#include "Toko.hpp"
// kalo mau coba run yang di bawah uncoment dulu
// #include "../Item/Item.cpp"
// #include "../Item/Hewan/Carnivore.cpp"
// #include "../Item/Hewan/Herbivore.cpp"
// #include "../Item/Hewan/Omnivore.cpp"
// #include "../Item/Hewan/Hewan.cpp"
// #include "../Item/Tanaman/Tanaman.cpp"
// #include "../Item/Produk/Produk.cpp"

Toko::Toko()
{
    // DUMMY DULU, GATAU FORMAT NYAMBUNGIN ITEM SAMA BACA CONFIG
    jenisBarang.push_back(new Tanaman(1, "TEK", "TEAK_TREE", "MATERIAL_PLANT", 15, 5));
    jenisBarang.push_back(new Tanaman(2, "SDT", "SANDALWOOD_TREE", "MATERIAL_PLANT", 10, 4));
    jenisBarang.push_back(new Tanaman(3, "ALT", "ALOE_TREE", "MATERIAL_PLANT", 9, 6));
    jenisBarang.push_back(new Tanaman(4, "IRN", "IRONWOOD_TREE", "MATERIAL_PLANT", 11, 5));
    jenisBarang.push_back(new Tanaman(5, "APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4));
    jenisBarang.push_back(new Tanaman(6, "ORG", "ORANGE_TREE", "FRUIT_PLANT", 12, 4));
    jenisBarang.push_back(new Tanaman(7, "BNT", "BANANA_TREE", "FRUIT_PLANT", 16, 3));
    jenisBarang.push_back(new Tanaman(8, "GAV", "GUAVA_TREE", "FRUIT_PLANT", 14, 3));

    jenisBarang.push_back(new Herbivore(1, "COW", "COW", 20, 6));
    jenisBarang.push_back(new Herbivore(2, "SHP", "SHEEP", 15, 5));
    jenisBarang.push_back(new Herbivore(3, "HRS", "HORSE", 18, 5));
    jenisBarang.push_back(new Herbivore(4, "RBT", "RABBIT", 10, 4));
    jenisBarang.push_back(new Carnivore(5, "SNK", "SNAKE", 13, 4));
    jenisBarang.push_back(new Omnivore(6, "CHK", "CHICKEN", 12, 3));
    jenisBarang.push_back(new Omnivore(7, "DCK", "DUCK", 11, 3));

    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());

    // jenisBarang.push_back(new Bangunan());
    // jenisBarang.push_back(new Bangunan());
    // jenisBarang.push_back(new Bangunan());
    // jenisBarang.push_back(new Bangunan());

    // Kode Tanaman
    jumlahTiapJenis["TEK"] = -1;
    jumlahTiapJenis["SDT"] = -1;
    jumlahTiapJenis["ALT"] = -1;
    jumlahTiapJenis["IRN"] = -1;
    jumlahTiapJenis["APL"] = -1;
    jumlahTiapJenis["ORG"] = -1;
    jumlahTiapJenis["BNT"] = -1;
    jumlahTiapJenis["GAV"] = -1;

    // Kode Hewan
    jumlahTiapJenis["COW"] = -1;
    jumlahTiapJenis["SHP"] = -1;
    jumlahTiapJenis["HRS"] = -1;
    jumlahTiapJenis["RBT"] = -1;
    jumlahTiapJenis["SNK"] = -1;
    jumlahTiapJenis["CHK"] = -1;
    jumlahTiapJenis["DCK"] = -1;

    // Kode Produk
    jumlahTiapJenis["TAW"] = 0;
    jumlahTiapJenis["SAW"] = 0;
    jumlahTiapJenis["ALW"] = 0;
    jumlahTiapJenis["IRW"] = 0;
    jumlahTiapJenis["APP"] = 0;
    jumlahTiapJenis["ORP"] = 0;
    jumlahTiapJenis["BNP"] = 0;
    jumlahTiapJenis["GAP"] = 0;
    jumlahTiapJenis["COM"] = 0;
    jumlahTiapJenis["SHM"] = 0;
    jumlahTiapJenis["HRM"] = 0;
    jumlahTiapJenis["RBM"] = 0;
    jumlahTiapJenis["SNM"] = 0;
    jumlahTiapJenis["CHM"] = 0;
    jumlahTiapJenis["DCM"] = 0;
    jumlahTiapJenis["CHE"] = 0;
    jumlahTiapJenis["DCE"] = 0;

    // Kode Bangunan
    jumlahTiapJenis["SMH"] = 0;
    jumlahTiapJenis["MDH"] = 0;
    jumlahTiapJenis["LRH"] = 0;
    jumlahTiapJenis["HTL"] = 0;
}

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

Toko::~Toko()
{
}

vector<Item *> Toko::getListBarang()
{
    return jenisBarang;
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
    for (int i = 0; i < int(jenisBarang.size()); i++)
    {
        cout << (i + 1) << ". " << jenisBarang[i]->getNama() << " - " << jenisBarang[i]->getHarga();
        if (jumlahTiapJenis[jenisBarang[i]->getKode()] != -1)
        {
            cout << " (" << jumlahTiapJenis[jenisBarang[i]->getKode()] << ")";
            adaBarang = true;
        }
        cout << endl;
    }

    if (!adaBarang)
    {
        throw TidakAdaBarangException();
        // cout << "gak ada barang" << endl;
    }
}

// int main(){
//     // dummy vector, tapi tipe dan nama tanaman kebalik karena kuikutin konfig bukan file tanaman.cpp
//     vector<Tanaman*> t;
//     t.push_back(new Tanaman(1, "TEK", "TEAK_TREE", "MATERIAL_PLANT", 15, 5));
//     t.push_back(new Tanaman(2, "SDT", "SANDALWOOD_TREE", "MATERIAL_PLANT", 10, 4));
//     t.push_back(new Tanaman(3, "ALT", "ALOE_TREE", "MATERIAL_PLANT", 9, 6));
//     t.push_back(new Tanaman(4, "IRN", "IRONWOOD_TREE", "MATERIAL_PLANT", 11, 5));
//     t.push_back(new Tanaman(5, "APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4));
//     t.push_back(new Tanaman(6, "ORG", "ORANGE_TREE", "FRUIT_PLANT", 12, 4));
//     t.push_back(new Tanaman(7, "BNT", "BANANA_TREE", "FRUIT_PLANT", 16, 3));
//     t.push_back(new Tanaman(8, "GAV", "GUAVA_TREE", "FRUIT_PLANT", 14, 3));

//     vector<Hewan*> h;
//     h.push_back(new Herbivore(1, "COW", "COW", 20, 6));
//     h.push_back(new Herbivore(2, "SHP", "SHEEP", 15, 5));
//     h.push_back(new Herbivore(3, "HRS", "HORSE", 18, 5));
//     h.push_back(new Herbivore(4, "RBT", "RABBIT", 10, 4));
//     h.push_back(new Carnivore(5, "SNK", "SNAKE", 13, 4));
//     h.push_back(new Omnivore(6, "CHK", "CHICKEN", 12, 3));
//     h.push_back(new Omnivore(7, "DCK", "DUCK", 11, 3));
//     vector<Produk*> p;
//     vector<Bangunan*> b;
//     Toko a(t,h,p,b);
//     Item* barang = new Produk(1, "TAW", "TEAK_WOOD", "PRODUCT_MATERIAL_PLANT", "TEAK_TREE", 0, 9);
//     a.beli(barang);
//     a.beli(barang);
//     a.beli(barang);
//     a.beli(barang);
//     a.beli(barang);
//     a.cetakListBarang();
//     a.jual(16,5);
//     a.cetakListBarang();
// }

void Toko::setJenisBarang(string kode, int value)
{
    this->jumlahTiapJenis[kode] = value;
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