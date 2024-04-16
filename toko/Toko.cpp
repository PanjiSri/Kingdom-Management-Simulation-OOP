#include "Toko.hpp"
// kalo mau coba run yang di bawah uncoment dulu
// #include "../Item/Item.cpp"
// #include "../Item/Hewan/Carnivore.cpp"
// #include "../Item/Hewan/Herbivore.cpp"
// #include "../Item/Hewan/Omnivore.cpp"
// #include "../Item/Hewan/Hewan.cpp"
// #include "../Item/Tanaman/Tanaman.cpp"
// #include "../Item/Produk/Produk.cpp"

Toko::Toko() {}

Toko::Toko(vector<Tanaman *> list_jenis_tanaman, vector<Hewan *> list_jenis_hewan, vector<Produk *> list_jenis_produk, vector<Bangunan *> list_jenis_bangunan)
{
    for (int i = 0; i < int(list_jenis_tanaman.size()); i++)
    {
        jenisBarang.push_back(list_jenis_tanaman[i]);
        jumlahTiapJenis.insert({list_jenis_tanaman[i]->getKode(), -1});
    }
    for (int i = 0; i < int(list_jenis_hewan.size()); i++)
    {
        jenisBarang.push_back(list_jenis_hewan[i]);
        jumlahTiapJenis.insert({list_jenis_hewan[i]->getKode(), -1});
    }
    for (int i = 0; i < int(list_jenis_produk.size()); i++)
    {
        jenisBarang.push_back(list_jenis_produk[i]);
        jumlahTiapJenis.insert({list_jenis_produk[i]->getKode(), 0});
    }
    for (int i = 0; i < int(list_jenis_bangunan.size()); i++)
    {
        jenisBarang.push_back(list_jenis_bangunan[i]);
        jumlahTiapJenis.insert({list_jenis_bangunan[i]->getKode(), 0});
    }
}

Toko::~Toko() {}

vector<Item *> Toko::getListBarang()
{
    return jenisBarang;
}

vector<vector<string>> Toko::getBarangJumlah()
{
    vector<vector<string>> list;
    for (int i = 0; i < int(jenisBarang.size()); i++)
    {
        vector<string> temp;
        temp.push_back(jenisBarang[i]->getNama());
        temp.push_back(to_string(jumlahTiapJenis[jenisBarang[i]->getKode()]));
        list.push_back(temp);
    }
    return list;
}

void Toko::setJenisBarang(string kode, int value)
{
    this->jumlahTiapJenis[kode] = value;
}

Item *Toko::jual(int no, int kuantitas)
{
    if (no > int(jenisBarang.size()))
    {
        throw NoBarangTidakValidException();
    }

    string barang = jenisBarang[no - 1]->getKode();
    if (jumlahTiapJenis[barang] != -1)
    {
        if (jumlahTiapJenis[barang] - kuantitas >= 0)
        {
            jumlahTiapJenis[barang] = jumlahTiapJenis[barang] - kuantitas;
        }
        else
        {
            throw StokTidakTersediaException();
        }
    }

    Item *jualan = jenisBarang[no - 1];
    if (jumlahTiapJenis[barang] == 0)
    {
        jenisBarang.erase(jenisBarang.begin() + no - 1);
    }
    return jualan;
}

void Toko::beli(Item *barang)
{
    if (jumlahTiapJenis[barang->getKode()] == 0)
    {
        jenisBarang.push_back(barang);
        jumlahTiapJenis[barang->getKode()] = 0;
    }
    if (jumlahTiapJenis[barang->getKode()] != -1)
    {
        jumlahTiapJenis[barang->getKode()] += 1;
    }
}

void Toko::cetakListBarang()
{
    cout << "Selamat datang di toko!!\nBerikut merupakan hal yang dapat Anda Beli\n";
    bool adaBarang = false;
    int number = 1;
    for (int i = 0; i < int(jenisBarang.size()); i++)
    {
        if (jumlahTiapJenis[jenisBarang[i]->getKode()] == -1)
        {
            cout << number << ". " << jenisBarang[i]->getNama() << " - " << jenisBarang[i]->getHarga();
            adaBarang = true;
            ++number;
            cout << endl;
        } else {
            if (jumlahTiapJenis[jenisBarang[i]->getKode()] != 0) {
                cout << number << ". " << jenisBarang[i]->getNama() << " - " << jenisBarang[i]->getHarga();
                cout << " (" << jumlahTiapJenis[jenisBarang[i]->getKode()] << ")";
                adaBarang = true;
                ++number;
                cout << endl;
            }
        }
    }

    if (!adaBarang)
    {
        throw TidakAdaBarangException();
    }
}
