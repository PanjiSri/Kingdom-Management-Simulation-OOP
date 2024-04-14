#include "Grandmaster.hpp"

Grandmaster::Grandmaster()
{
    config_hewan = "folder/animal.txt";
    config_produk = "folder/product.txt";
    config_tanaman = "folder/plant.txt";
    config_misc = "folder/misc.txt";
}

void Grandmaster::loadConfigHewanTanaman()
{
    ifstream file(config_hewan);

    if (!file.is_open())
    {
        throw FilePathTidakValid();
    }

    string kode_huruf, name, type;
    int id, weight, price;
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        ss >> id >> kode_huruf >> name >> type >> weight >> price;
        list_jenis_hewan.push_back(Line_Handler(id, kode_huruf, name, type, weight, price));
    }

    file.close();

    ifstream file2(config_tanaman);

    if (!file2.is_open())
    {
        throw FilePathTidakValid();
    }

    string kode_huruf2, name2, type2;
    int id2, duration2, price2;
    string line2;

    while (getline(file2, line2))
    {
        stringstream ss(line2);
        ss >> id2 >> kode_huruf2 >> name2 >> type2 >> duration2 >> price2;
        list_jenis_tanaman.push_back(Line_Handler(id2, kode_huruf2, name2, type2, duration2, price2));
    }

    file2.close();
}

void Grandmaster::loadConfigProduk()
{
    ifstream file(config_produk);
    if (!file.is_open())
    {
        throw FilePathTidakValid();
    }

    string kode_huruf, name, type, origin;
    int id, add_weight, price;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        ss >> id >> kode_huruf >> name >> type >> origin >> add_weight >> price;
        list_jenis_produk.push_back(Line_Handler_Produk(id, kode_huruf, name, type, add_weight, price, origin));
    }
    file.close();
}

void Grandmaster::loadConfigMisc()
{
    ifstream file(config_misc);

    if (!file.is_open())
    {
        throw FilePathTidakValid();
    }
    string line;

    for (int i = 0; i < 5; i++)
    {
        getline(file, line);
        stringstream ss(line);
        if (i == 0)
        {
            ss >> uang_menang;
        }
        else if (i == 1)
        {
            ss >> berat_menang;
        }
        else if (i == 2)
        {
            ss >> besar_penyimpanan[0] >> besar_penyimpanan[1];
        }
        else if (i == 3)
        {
            ss >> besar_lahan[0] >> besar_lahan[1];
        }
        else if (i == 4)
        {
            ss >> besar_peternakan[0] >> besar_peternakan[1];
        }
    }
}

void Grandmaster::loadallconfig()
{
    loadConfigHewanTanaman();
    loadConfigProduk();
    loadConfigMisc();
    // cout << "aman" << endl;
}

void Grandmaster::inisiatorTanaman()
{
    for (int i = 0; i < list_jenis_tanaman.size(); i++)
    {
        int id = list_jenis_tanaman[i].getId();
        string kode = list_jenis_tanaman[i].getKodeHuruf();
        string nama = list_jenis_tanaman[i].getName();
        string tipe = list_jenis_tanaman[i].getType();
        int durasi = list_jenis_tanaman[i].getDurationToHarvest();
        int harga = list_jenis_tanaman[i].getPrice();

        list_tanaman.push_back(new Tanaman(id, kode, tipe, nama, durasi, harga));
        list_item.push_back(new Tanaman(id, kode, tipe, nama, durasi, harga));
    }
}

void Grandmaster::inisiatorHewan()
{
    for (int i = 0; i < list_jenis_hewan.size(); i++)
    {

        int id = list_jenis_hewan[i].getId();
        string kode = list_jenis_hewan[i].getKodeHuruf();
        string nama = list_jenis_hewan[i].getName();
        string tipe = list_jenis_hewan[i].getType();
        int berat = list_jenis_hewan[i].getDurationToHarvest();
        int harga = list_jenis_hewan[i].getPrice();

        if (tipe == "HERBIVORE")
        {
            list_hewan.push_back(new Herbivore(id, kode, nama, berat, harga));
            list_item.push_back(new Herbivore(id, kode, nama, berat, harga));
        }
        else if (tipe == "OMNIVORE")
        {
            list_hewan.push_back(new Omnivore(id, kode, nama, berat, harga));
            list_item.push_back(new Omnivore(id, kode, nama, berat, harga));
        }
        else if (tipe == "CARNIVORE")
        {
            list_hewan.push_back(new Carnivore(id, kode, nama, berat, harga));
            list_item.push_back(new Carnivore(id, kode, nama, berat, harga));
        }
        else
        {
            throw ConfigTidakValid();
        }
    }
}

void Grandmaster::inisiatorProduk()
{
    for (int i = 0; i < list_jenis_produk.size(); i++)
    {
        int id = list_jenis_produk[i].getId();
        string kode = list_jenis_produk[i].getKodeHuruf();
        string nama = list_jenis_produk[i].getName();
        string tipe = list_jenis_produk[i].getType();
        int berat = list_jenis_produk[i].getDurationToHarvest();
        int harga = list_jenis_produk[i].getPrice();
        string origin = list_jenis_produk[i].getOrigin();

        list_produk.push_back(new Produk(id, kode, nama, tipe, origin, berat, harga));
        list_item.push_back(new Produk(id, kode, nama, tipe, origin, berat, harga));
    }
}

void Grandmaster::mulaiTanpaBerkas()
{
    loadallconfig();
    inisiatorHewan();
    inisiatorTanaman();
    inisiatorProduk();

    // masih prototype
    // Membuat list pemain sesuai dengan informasi yang diberikan
    list_pemain.push_back(new Petani("Petani1", besar_penyimpanan[0], besar_penyimpanan[1], besar_lahan[0], besar_lahan[1]));
    list_pemain.push_back(new Peternak("Peternak1", besar_penyimpanan[0], besar_penyimpanan[1], besar_lahan[0], besar_lahan[1]));
    list_pemain.push_back(new Walikota("Walikota", besar_penyimpanan[0], besar_penyimpanan[1]));

    // inisiasi banyak_pemain
    banyak_pemain = 3;

    // inisiasi giliran pemain
    idx_giliran_pemain = 0;
}

void Grandmaster::mulaiDenganBerkas()
{
    
}

void Grandmaster::muatPemain(Peran *pemain_baru)
{
    // leksikografis
    string username_baru = pemain_baru->getUname();
    bool cek = false;

    for (int i = 0; i < banyak_pemain; ++i)
    {
        if (username_baru == list_pemain[i]->getUname())
        {

            throw NamaPemainTidakValidException();
        }
        if (username_baru < list_pemain[i]->getUname())
        {
            list_pemain.insert(list_pemain.begin() + i, pemain_baru);
            cek = true;
            break;
        }
    }

    if (!cek)
    {
        list_pemain.push_back(pemain_baru);
    }

    banyak_pemain++;
}

// data_path = data/state.txt
void Grandmaster::muatState(string data_path)
{
    ifstream file(data_path);

    if (!file.is_open())
    {
        throw FilePathTidakValid();
    }

    int row_penyimpanan = besar_penyimpanan[0];
    int col_penyimpanan = besar_penyimpanan[1];

    int row_lahan = besar_lahan[0];
    int col_lahan = besar_lahan[1];

    string line;
    getline(file, line);
    stringstream ss(line);

    ss >> banyak_pemain;

    for (int i = 0; i < banyak_pemain; i++)
    {
        getline(file, line);
        stringstream ss(line);

        string username, jenis_peran;
        int berat_badan, uang;

        ss >> username >> jenis_peran >> berat_badan >> uang;

        int banyak_jenis;

        // // Asumsinya List Pemain sudah kosong
        if (jenis_peran == "Peternak")
        {
            muatPemain(new Peternak(username, berat_badan, uang, row_penyimpanan, col_penyimpanan, row_lahan, col_lahan));
        }
        else if (jenis_peran == "Petani")
        {
            muatPemain(new Petani(username, berat_badan, uang, row_penyimpanan, col_penyimpanan, row_lahan, col_lahan));
        }
        else if (jenis_peran == "Walikota")
        {
            muatPemain(new Walikota(username, berat_badan, uang, row_penyimpanan, col_penyimpanan));
        }
        else
        {
            throw ConfigTidakValid();
        }

        getline(file, line);
        stringstream ss(line);

        int banyak_item;
        ss >> banyak_item;

        for (int j = 0; j < banyak_item; j++)
        {

            getline(file, line);
            stringstream ss(line);

            string nama_item;

            ss >> nama_item;

            // pastiin ini jenis item apa, terus tambahin ke peran
            // cari peran berdasarkan index'

            int index_pemain_untuk_tambah_item = cariPemain(username);

            list_pemain[index_pemain_untuk_tambah_item]->addPenyimpananFile(nama_item, list_item);
        }

        if (jenis_peran != "Walikota")
        {
            int banyak_di_lahan;
            getline(file, line);
            stringstream ss(line);

            ss >> banyak_di_lahan;
            for (int k = 0; k < banyak_di_lahan; k++)
            {

                string lokasi, nama;
                int umur;

                getline(file, line);
                stringstream ss(line);

                ss >> lokasi, nama, umur;

                int index_pemain_untuk_tambah_item = cariPemain(username);

                list_pemain[index_pemain_untuk_tambah_item]->tanamFile(lokasi, nama, umur, list_item);
            }
        }
    }
}

int Grandmaster::cariJenis(string nama)
{
    for (int i = 0; i < list_jenis_tanaman.size(); i++)
    {
        if (list_jenis_tanaman[i].getName() == nama)
        {
            return 1;
        }
    }

    for (int i = 0; i < list_jenis_hewan.size(); i++)
    {
        if (list_jenis_hewan[i].getName() == nama)
        {
            return 2;
        }
    }

    for (int i = 0; i < list_jenis_produk.size(); i++)
    {
        if (list_jenis_produk[i].getName() == nama)
        {
            return 3;
        }
    }

    return -1;
}

int Grandmaster::cariPemain(string username)
{

    for (int i = 0; i < list_pemain.size(); i++)
    {

        if (list_pemain[i]->getUname() == username)
        {
            return i;
        }
    }

    return -1;
}

// getter
int Grandmaster::getUangMenang() const
{
    return uang_menang;
}

int Grandmaster::getBeratMenang() const
{
    return berat_menang;
}

int Grandmaster::getBesarPenyimpanan(int index) const
{
    return besar_penyimpanan[index];
}

int Grandmaster::getBesarLahan(int index) const
{
    return besar_lahan[index];
}

int Grandmaster::getBesarPeternakan(int index) const
{
    return besar_peternakan[index];
}

// testing
Line_Handler Grandmaster::getJenisHewan(int index) const
{
    return list_jenis_hewan[index];
}

Line_Handler Grandmaster::getJenisTanaman(int index) const
{
    return list_jenis_tanaman[index];
}

Line_Handler_Produk Grandmaster::getJenisProduk(int index) const
{
    return list_jenis_produk[index];
}