#include "Grandmaster.hpp"
/*
PS D:\A Perkuliahan ITB\Mata Kuliah\Semester 4\OOP\tubes_1\Tubes-1-OOP-SCP> g++ -o testing grandTesting.cpp toko/Toko.cpp peran/peran.cpp peran/Petani.cpp peran/Peternak.cpp peran/Walikota.cpp Pcolor/pcolor.c Item/item.cpp Item/Bangunan/Bangunan.cpp Item/Hewan/Carnivore.cpp Item/Hewan/Herbivore.cpp Item/Hewan/Omnivore.cpp Item/Hewan/Hewan.cpp Item/Produk/Produk.cpp Item/Tanaman/Tanaman.cpp input/input.cpp grandmaster/Grandmaster.cpp
PS D:\A Perkuliahan ITB\Mata Kuliah\Semester 4\OOP\tubes_1\Tubes-1-OOP-SCP> ./testing
*/
Grandmaster::Grandmaster()
{
    config_hewan = "folder/animal.txt";
    config_produk = "folder/product.txt";
    config_tanaman = "folder/plant.txt";
    config_misc = "folder/misc.txt";
    config_recipe = "folder/recipe.txt";

    idx_giliran_pemain = 0;
    banyak_pemain = 0;
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
        list_jenis_hewan.push_back(Konfigurasi_Animal(id, kode_huruf, name, type, weight, price));
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
        list_jenis_tanaman.push_back(Konfigurasi_Tanaman(id2, kode_huruf2, name2, type2, duration2, price2));
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
        list_jenis_produk.push_back(Konfigurasi_Produk(id, kode_huruf, name, type, origin, add_weight, price));
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

// void Grandmaster::loadConfigRecipe(){

// }

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
        string kode = list_jenis_tanaman[i].getKode();
        string nama = list_jenis_tanaman[i].getName();
        string tipe = list_jenis_tanaman[i].getTipe();
        int durasi = list_jenis_tanaman[i].getDurationToHarvest();
        int harga = list_jenis_tanaman[i].getHarga();

        list_tanaman.push_back(new Tanaman(id, kode, nama, tipe, durasi, harga));
        list_item.push_back(new Tanaman(id, kode, nama, tipe, durasi, harga));
        list_tanaman.push_back(new Tanaman(id, kode, nama, tipe, durasi, harga));
        list_item.push_back(new Tanaman(id, kode, nama, tipe, durasi, harga));
    }
}

void Grandmaster::inisiatorHewan()
{
    for (int i = 0; i < list_jenis_hewan.size(); i++)
    {

        int id = list_jenis_hewan[i].getId();
        string kode = list_jenis_hewan[i].getKode();
        string nama = list_jenis_hewan[i].getName();
        string tipe = list_jenis_hewan[i].getTipe();
        int berat = list_jenis_hewan[i].getWeightToHarvest();
        int harga = list_jenis_hewan[i].getHarga();

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
        string kode = list_jenis_produk[i].getKode();
        string nama = list_jenis_produk[i].getName();
        string tipe = list_jenis_produk[i].getTipe();
        int berat = list_jenis_produk[i].getBeratTambahan();
        int harga = list_jenis_produk[i].getHarga();
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

void Grandmaster::mulaiDenganBerkas(string data_path)
{
    loadallconfig();

    cout << "flag 1" << endl;

    inisiatorHewan();
    inisiatorTanaman();
    inisiatorProduk();

    cout << "banyak_pemain awal " << banyak_pemain << endl;
    muatState(data_path);

    banyak_pemain = list_pemain.size();

    // inisiasi giliran pemain
    idx_giliran_pemain = 0;
}

void Grandmaster::muatPemain(Peran *pemain_baru)
{
    cout << "flag 0" << endl;
    if (list_pemain.empty())
    {
        list_pemain.push_back(pemain_baru);
        cout << "username " << pemain_baru->getUname() << endl;
        cout << "banyak_pemain " << banyak_pemain << endl;
        banyak_pemain++;
        return;
    }
    // leksikografis
    string username_baru = pemain_baru->getUname();
    bool cek = false;
    cout << "username: " << username_baru << endl;
    cout << "banyak_pemain " << banyak_pemain << endl;
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

    cout << "flag 2" << endl;

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

    int banyak_pemain_file;

    ss >> banyak_pemain_file;

    cout << "banyak pemain file: " << banyak_pemain_file << endl;

    for (int i = 0; i < banyak_pemain_file; i++)
    {
        getline(file, line);
        stringstream ss_pemain(line); // Ubah nama variabel ss menjadi ss_pemain

        string username, jenis_peran;
        int berat_badan, uang;

        ss_pemain >> username >> jenis_peran >> berat_badan >> uang; // Gunakan ss_pemain di sini

        cout << "username: " << username << endl;
        cout << "jenis peran: " << jenis_peran << endl;
        cout << "berat badan: " << berat_badan << endl;
        cout << "uang: " << uang << endl;

        // int banyak_jenis;

        // // Asumsinya List Pemain sudah kosong
        if (jenis_peran == "Peternak")
        {
            muatPemain(new Peternak(username, berat_badan, uang, row_penyimpanan, col_penyimpanan, row_lahan, col_lahan));
            cout << "muat pemain peternak" << endl;
        }
        else if (jenis_peran == "Petani")
        {
            muatPemain(new Petani(username, berat_badan, uang, row_penyimpanan, col_penyimpanan, row_lahan, col_lahan));
            cout << "muat pemain petani" << endl;
        }
        else if (jenis_peran == "Walikota")
        {
            muatPemain(new Walikota(username, berat_badan, uang, row_penyimpanan, col_penyimpanan));
            cout << "muat pemain walikota" << endl;
        }
        else
        {
            throw ConfigTidakValid();
        }

        // Debugging
        if (i == 0)
        {
            cout << "debug 1" << endl;
            cout << list_pemain[0]->getUname() << endl;
        }
        else if (i == 1)
        {
            cout << "debug 2" << endl;
            cout << list_pemain[0]->getUname() << endl;
            cout << list_pemain[1]->getUname() << endl;
        }
        else
        {
            cout << "debug 3" << endl;
            // cout << list_pemain[0]->getUname() << endl;
            // cout << list_pemain[1]->getUname() << endl;
            // cout << list_pemain[2]->getUname() << endl;
            printAllPemain();
        }

        // Debugging

        getline(file, line);
        stringstream ss_item(line); // Ubah nama variabel ss menjadi ss_item

        int banyak_item;
        ss_item >> banyak_item; // Gunakan ss_item di sini

        cout << "banyak item: " << banyak_item << endl;

        for (int j = 0; j < banyak_item; j++)
        {

            getline(file, line);
            stringstream ss_nama_item(line); // Ubah nama variabel ss menjadi ss_nama_item

            string nama_item;

            ss_nama_item >> nama_item; // Gunakan ss_nama_item di sini

            // pastiin ini jenis item apa, terus tambahin ke peran
            // cari peran berdasarkan index'
            cout << "nama item: " << nama_item << endl;

            int index_pemain_untuk_tambah_item = cariPemain(username);

            list_pemain[index_pemain_untuk_tambah_item]->addPenyimpananFile(nama_item, list_item);
        }

        cout << "debug walikota i: " << i << endl;
        if (i == 2)
        {
            cout << "debug 4" << endl;
            list_pemain[0]->printPenyimpanan();
        }

        if (jenis_peran != "Walikota")
        {
            int banyak_di_lahan;
            getline(file, line);
            stringstream ss_di_lahan(line); // Ubah nama variabel ss menjadi ss_di_lahan

            ss_di_lahan >> banyak_di_lahan; // Gunakan ss_di_lahan di sini

            cout << "banyak di lahan: " << banyak_di_lahan << endl;

            int index_pemain_untuk_tambah_item = cariPemain(username);

            printAllPemain();

            cout << "index pemain: " << index_pemain_untuk_tambah_item << endl;

            for (int k = 0; k < banyak_di_lahan; k++)
            {

                string lokasi, nama;
                int umur;

                getline(file, line);
                stringstream ss_lahan(line); // Ubah nama variabel ss menjadi ss_lahan

                ss_lahan >> lokasi >> nama >> umur; // Gunakan ss_lahan di sini

                cout << "lokasi: " << lokasi << endl;
                cout << "nama: " << nama << endl;
                cout << "umur: " << umur << endl;

                list_pemain[index_pemain_untuk_tambah_item]->beternakBertaniFile(lokasi, nama, umur, list_item);
                // list_pemain[index_pemain_untuk_tambah_item]->cetakLahan();
            }
            if (i == 2)
            {

                cout << "debug 5" << endl;
                // list_pemain[1]->cetakLahan();
                printAllPemain();
            }
        }
        // if(i == 2){
        //         return;
        // }
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

void Grandmaster::next()
{

    if (idx_giliran_pemain + 1 >= list_pemain.size())
    {
        idx_giliran_pemain = 0;
    }
    else
    {
        idx_giliran_pemain++;
    }

    cout << idx_giliran_pemain << endl;
}

void Grandmaster::operasi_perintah(string command)
{
    if (command == "NEXT")
    {
        next();
        for (int i = 0; i < list_pemain.size(); i++)
        {
            if (list_pemain[i]->getType() == "Petani")
            {
                list_pemain[i]->addUmurTanaman();
            }
        }
    }
    else if (command == "CETAK_PENYIMPANAN")
    {
        list_pemain[idx_giliran_pemain]->printPenyimpanan();
    }
    else if (command == "PUNGUT_PAJAK")
    {
        list_pemain[idx_giliran_pemain]->ambilPajak(list_pemain);
        // cout << list_pemain[cariPemain("Budi")]->getType() << endl;
        // cout << "Peternak" << endl;
    }
    else if (command == "CETAK_LADANG")
    {
        list_pemain[idx_giliran_pemain]->cetakLahan();
    }
    else if (command == "TANAM")
    {

        list_pemain[idx_giliran_pemain]->beternakBertani();
    }
    else if (command == "TERNAK")
    {
        list_pemain[idx_giliran_pemain]->beternakBertani();
    }
    else if (command == "MAKAN")
    {
        list_pemain[idx_giliran_pemain]->playerMakan();
    }
    else if (command == "KASIH_MAKAN")
    {
        list_pemain[idx_giliran_pemain]->beriMakan();
    }
    else if (command == "PANEN")
    {
        list_pemain[idx_giliran_pemain]->panen(list_produk);
    }
    else if (command == "SIMPAN")
    {
        list_pemain[idx_giliran_pemain]->simpan(list_pemain);
    }
    else
    {
        throw CommandTidakValidException();
    }
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

// // testing
// Line_Handler Grandmaster::getJenisHewan(int index) const
// {
//     return list_jenis_hewan[index];
// }

// Line_Handler Grandmaster::getJenisTanaman(int index) const
// {
//     return list_jenis_tanaman[index];
// }

// Line_Handler_Produk Grandmaster::getJenisProduk(int index) const
// {
//     return list_jenis_produk[index];
// }

int Grandmaster::getIndexGiliran() const
{
    return idx_giliran_pemain;
}

void Grandmaster::getAllPemainInfo()
{
    printAllPemain();
    cout << "=========INFORMASI PEMAIN PETERNAK=========" << endl;
    list_pemain[1]->cetakLahan();
    cout << "=========INFORMASI PEMAIN PETANI=========" << endl;
    cout << list_pemain[2]->getGulden() << endl;
    cout << list_pemain[2]->getBerat() << endl;
    list_pemain[2]->printPenyimpanan();
    list_pemain[2]->cetakLahan();

    return;

    for (int i = 0; i < list_pemain.size(); i++)
    {
        cout << "Nama: " << list_pemain[i]->getUname() << endl;
        cout << "Berat: " << list_pemain[i]->getBerat() << endl;
        cout << "Gulden: " << list_pemain[i]->getGulden() << endl;
        list_pemain[i]->printPenyimpanan();
        if (list_pemain[i]->getType() != "walikota")
        {
            list_pemain[i]->cetakLahan();
        }
    }
}

Grandmaster::~Grandmaster()
{

    for (int i = 0; i < list_pemain.size(); i++)
    {
        delete list_pemain[i];
    }

    for (int i = 0; i < list_tanaman.size(); i++)
    {
        delete list_tanaman[i];
    }

    for (int i = 0; i < list_hewan.size(); i++)
    {
        delete list_hewan[i];
    }

    for (int i = 0; i < list_item.size(); i++)
    {
        delete list_item[i];
    }

    for (int i = 0; i < list_produk.size(); i++)
    {
        delete list_produk[i];
    }
}

void Grandmaster::printAllPemain()
{

    cout << "[";
    for (int i = 0; i < list_pemain.size(); i++)
    {
        cout << "(";
        cout << list_pemain[i]->getUname() << ", ";
        cout << list_pemain[i]->getBerat() << ", ";
        cout << list_pemain[i]->getGulden();
        cout << ")";
        if (i != list_pemain.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void Grandmaster::printWalikota()
{
    for (int i = 0; i < list_pemain.size(); i++)
    {
        if (list_pemain[i]->getType() == "walikota")
        {
            cout << list_pemain[i]->getUname() << endl;
        }
    }
}
