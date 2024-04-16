#include "Grandmaster.hpp"

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

Grandmaster::~Grandmaster()
{

    for (int i = 0; i < int(list_pemain.size()); i++)
    {
        delete list_pemain[i];
    }

    for (int i = 0; i < int(list_tanaman.size()); i++)
    {
        delete list_tanaman[i];
    }

    for (int i = 0; i < int(list_hewan.size()); i++)
    {
        delete list_hewan[i];
    }

    for (int i = 0; i < int(list_item.size()); i++)
    {
        delete list_item[i];
    }

    for (int i = 0; i < int(list_produk.size()); i++)
    {
        delete list_produk[i];
    }

    delete toko;
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

int Grandmaster::getIndexGiliran() const
{
    return idx_giliran_pemain;
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

void Grandmaster::loadConfigRecipe()
{
    ifstream file(config_recipe);
    if (!file.is_open())
    {
        throw FilePathTidakValid();
    }

    string kode_huruf, nama, nama_material;
    int id, jumlah_material, harga;
    
    string line;
    while (getline(file, line))
    {
        map<string, int> material;
        stringstream ss(line);
        ss >> id >> kode_huruf >> nama >> harga;
        while (ss >> nama_material >> jumlah_material)
        {
            if (material.size() == 0) {
                material.insert({nama_material, jumlah_material});
            }
            else {
                if (material.count(nama_material)) {
                    material[nama_material] = jumlah_material;
                }
                else {
                    material.insert({nama_material, jumlah_material});
                }
            }
        }
        list_jenis_bangunan.push_back(Konfigurasi_Recipe(id, kode_huruf, nama, harga, material));
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
    loadConfigRecipe();
}

void Grandmaster::inisiatorTanaman()
{
    for (int i = 0; i < int(list_jenis_tanaman.size()); i++)
    {
        int id = list_jenis_tanaman[i].getId();
        string kode = list_jenis_tanaman[i].getKode();
        string nama = list_jenis_tanaman[i].getName();
        string tipe = list_jenis_tanaman[i].getTipe();
        int durasi = list_jenis_tanaman[i].getDurationToHarvest();
        int harga = list_jenis_tanaman[i].getHarga();

        list_tanaman.push_back(new Tanaman(id, kode, nama, tipe, durasi, harga));
        list_item.push_back(new Tanaman(id, kode, nama, tipe, durasi, harga));
    }
}

void Grandmaster::inisiatorHewan()
{
    for (int i = 0; i < int(list_jenis_hewan.size()); i++)
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
    for (int i = 0; i < int(list_jenis_produk.size()); i++)
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

void Grandmaster::inisiatorBangunan() {
    for (int i = 0; i < int(list_jenis_bangunan.size()); i++)
    {
        int id = list_jenis_bangunan[i].getId();
        string kode = list_jenis_bangunan[i].getKode();
        string nama = list_jenis_bangunan[i].getName();
        int harga = list_jenis_bangunan[i].getHarga();
        map<string, int> bahan_baku = list_jenis_bangunan[i].getBahanBaku();

        list_bangunan.push_back(new Bangunan(id, kode, nama, harga, bahan_baku));
        list_item.push_back(new Bangunan(id, kode, nama, harga, bahan_baku));
    }
}

void Grandmaster::mulaiTanpaBerkas()
{
    loadallconfig();
    inisiatorHewan();
    inisiatorTanaman();
    inisiatorProduk();
    inisiatorBangunan();

    toko = new Toko(list_tanaman, list_hewan, list_produk, list_bangunan);

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

    inisiatorHewan();
    inisiatorTanaman();
    inisiatorProduk();
    inisiatorBangunan();

    toko = new Toko(list_tanaman, list_hewan, list_produk, list_bangunan);

    muatState(data_path);
    banyak_pemain = list_pemain.size();

    // inisiasi giliran pemain
    idx_giliran_pemain = 0;
}

void Grandmaster::muatPemain(Peran *pemain_baru)
{
    if (list_pemain.empty())
    {
        list_pemain.push_back(pemain_baru);
        banyak_pemain++;
        return;
    }

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

    int banyak_pemain_file;

    ss >> banyak_pemain_file;

    // muat state tiap pemain
    for (int i = 0; i < banyak_pemain_file; i++)
    {
        getline(file, line);
        stringstream ss_pemain(line); // Ubah nama variabel ss menjadi ss_pemain

        string username, jenis_peran;
        int berat_badan, uang;

        ss_pemain >> username >> jenis_peran >> berat_badan >> uang; // Gunakan ss_pemain di sini

        // Asumsinya List Pemain sudah kosong
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
        stringstream ss_item(line); // Ubah nama variabel ss menjadi ss_item

        int banyak_item;
        ss_item >> banyak_item; // Gunakan ss_item di sini

        for (int j = 0; j < banyak_item; j++)
        {
            getline(file, line);
            stringstream ss_nama_item(line); // Ubah nama variabel ss menjadi ss_nama_item

            string nama_item;

            ss_nama_item >> nama_item; // Gunakan ss_nama_item di sini

            int index_pemain_untuk_tambah_item = cariPemain(username);

            list_pemain[index_pemain_untuk_tambah_item]->addPenyimpananFile(nama_item, list_item);   
        }

        if (jenis_peran != "Walikota")
        {
            int banyak_di_lahan;
            getline(file, line);
            stringstream ss_di_lahan(line); // Ubah nama variabel ss menjadi ss_di_lahan

            ss_di_lahan >> banyak_di_lahan; // Gunakan ss_di_lahan di sini

            int index_pemain_untuk_tambah_item = cariPemain(username);

            for (int k = 0; k < banyak_di_lahan; k++)
            {

                string lokasi, nama;
                int umur;

                getline(file, line);
                stringstream ss_lahan(line); // Ubah nama variabel ss menjadi ss_lahan

                ss_lahan >> lokasi >> nama >> umur; // Gunakan ss_lahan di sini

                list_pemain[index_pemain_untuk_tambah_item]->beternakBertaniFile(lokasi, nama, umur, list_item);
            }
        }
    }

    int banyak_barang_toko;

    getline(file, line);
    stringstream ss_barang_toko(line); 

    ss_barang_toko >> banyak_barang_toko;

    for (int i = 0; i < banyak_barang_toko; i++)
    {
        string namaBarang;
        int banyakBarang;
        getline(file, line);
        stringstream ss_toko(line);

        ss_toko >> namaBarang >> banyakBarang;

        string kode = cariKodeBarang(namaBarang);

        toko->setJenisBarang(kode, banyakBarang);
    }
}

int Grandmaster::cariJenis(string nama)
{
    for (int i = 0; i < int(list_jenis_tanaman.size()); i++)
    {
        if (list_jenis_tanaman[i].getName() == nama)
        {
            return 1;
        }
    }

    for (int i = 0; i < int(list_jenis_hewan.size()); i++)
    {
        if (list_jenis_hewan[i].getName() == nama)
        {
            return 2;
        }
    }

    for (int i = 0; i < int(list_jenis_produk.size()); i++)
    {
        if (list_jenis_produk[i].getName() == nama)
        {
            return 3;
        }
    }

    for (int i = 0; i < int(list_jenis_bangunan.size()); i++)
    {
        if (list_jenis_bangunan[i].getName() == nama)
        {
            return 4;
        }
    }

    return -1;
}

int Grandmaster::cariPemain(string username)
{
    for (int i = 0; i < int(list_pemain.size()); i++)
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
    if (idx_giliran_pemain + 1 >= int(list_pemain.size()))
    {
        idx_giliran_pemain = 0;
    }
    else
    {
        idx_giliran_pemain++;
    }
}

void Grandmaster::operasi_perintah(string command)
{
    if (command == "NEXT")
    {
        next();
        for (int i = 0; i < int(list_pemain.size()); i++)
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
    }
    else if (command == "CETAK_LADANG")
    {   
        if(list_pemain[idx_giliran_pemain]->getType() == "Petani"){
            list_pemain[idx_giliran_pemain]->cetakLahan();
        }else{
            throw AndaBukanPetaniException();        
        }
    }
    else if(command == "CETAK_PETERNAKAN"){
        if(list_pemain[idx_giliran_pemain]->getType() == "Peternak"){
            list_pemain[idx_giliran_pemain]->cetakLahan();
        }else{
            throw AndaBukanPeternakException();
        }
    }
    else if (command == "TANAM")
    {   
        if (list_pemain[idx_giliran_pemain]->getType() == "Petani"){

            list_pemain[idx_giliran_pemain]->beternakBertani();
        }
        else{
            throw AndaBukanPetaniException();  
        }
    }
    else if (command == "TERNAK")
    {
        if(list_pemain[idx_giliran_pemain]->getType() == "Peternak"){
            list_pemain[idx_giliran_pemain]->beternakBertani();
        }
        else{
            throw AndaBukanPeternakException();
        }
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
        list_pemain[idx_giliran_pemain]->simpan(list_pemain, toko);
    }
    else if (command == "BANGUN")
    {
        list_pemain[idx_giliran_pemain]->bangun(list_bangunan);
    }
    else if (command == "BELI")
    {
        list_pemain[idx_giliran_pemain]->membeli(toko);
    }
    else if (command == "JUAL")
    {
        list_pemain[idx_giliran_pemain]->menjual(toko);
    }
    else if (command == "TAMBAH_PEMAIN")
    {
        int row_inv = besar_penyimpanan[0] ;
        int col_inv = besar_penyimpanan[1];

        int row_lahan = besar_lahan[0];
        int col_lahan = besar_lahan[1];

        int row_ternak = besar_peternakan[0];
        int col_ternak = besar_peternakan[1];
    
        Peran * anak_baru = list_pemain[idx_giliran_pemain]->buatUser(list_pemain, row_inv, col_inv, row_lahan, col_lahan, row_ternak, col_ternak);

        if (anak_baru != NULL) {
            muatPemain(anak_baru);  
        }
    }
    else
    {
        throw CommandTidakValidException();
    }
}

string Grandmaster::cariKodeBarang(string nama){
    for (int i = 0; i < int(list_item.size()); i++) {
        if (list_item[i]->getNama() == nama) {
            return list_item[i]->getKode();
        }
    }
    return "";
}

void Grandmaster::runner(){
    cout << "**********************************************" << endl;
    cout << "*                                            *" << endl;
    cout << "*          Selamat Datang Di Kelola          *" << endl;
    cout << "*                 Kerajaan                   *" << endl;
    cout << "*                SCP-040-JP                  *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;

    string pilihan_mulai;

    cout << "Apakah anda ingin memulai menggunakan berkas? (y/n)" << endl;

    cin >> pilihan_mulai;

    bool isMuat = true;

    if (pilihan_mulai == "y" || pilihan_mulai == "Y") {

            string path_file;

            while(isMuat){
                try {
                    cout << "Masukkan path menuju berkas beserta ekstensinya terhadap path TUBES-1-OOP-SCP> : ";   

                    cin >> path_file;

                    mulaiDenganBerkas(path_file);

                    isMuat = false;
                }
                catch (exception &e) {
                    cout << e.what() << endl;
                    list_pemain.clear();
                    list_hewan.clear();
                    list_bangunan.clear();
                    list_item.clear();
                    list_jenis_bangunan.clear();
                    list_jenis_hewan.clear();
                    list_jenis_produk.clear();
                    list_jenis_tanaman.clear();
                    list_produk.clear();
                    list_tanaman.clear();
                } 
            }

            string command;
            bool isRunning = true;

            while (isRunning) {
            
                cout << "===========================================================" << endl;
                try {
                    cout << "Sekarang giliran " << list_pemain[idx_giliran_pemain]->getUname() << endl;

                    cout << "Tulis operasi atau perintah yang anda inginkan: ";

                    cin >> command;

                    operasi_perintah(command);

                    for(int i = 0; i < int(list_pemain.size()); i++){

                        if(list_pemain[i]->getBerat() == berat_menang && list_pemain[i]->getGulden() == uang_menang){
                            isRunning = false;

                            cout << "**************************************" << endl;
                            cout << "*                                    *" << endl;
                            cout << "*       PERMAINAN DIMENANGKAN        *" << endl;
                            cout << "*     " << list_pemain[i]->getUname()   << "    *" << endl;
                            cout << "*                                    *" << endl;
                            cout << "**************************************" << endl;

                            break;   
                        }                    
                    }

                } 
                catch (exception &e) {
                    cout << e.what() << endl << endl; 
                }

            }
    } else if (pilihan_mulai == "n" || pilihan_mulai == "N") {
        mulaiTanpaBerkas();

        string command;
        bool isRunning = true;

        while(isRunning){
            
                cout << "===========================================================" << endl;
                try {
                    cout << "Sekarang giliran " << list_pemain[idx_giliran_pemain]->getUname() << endl;

                    cout << "Tulis operasi atau perintah yang anda inginkan: ";

                    cin >> command;

                    operasi_perintah(command);

                    for(int i = 0; i < int(list_pemain.size()); i++){

                        if(list_pemain[i]->getBerat() == berat_menang && list_pemain[i]->getGulden() == uang_menang){
                            isRunning = false;

                            cout << "**************************************" << endl;
                            cout << "*                                    *" << endl;
                            cout << "*       PERMAINAN DIMENANGKAN        *" << endl;
                            cout << "*     " << list_pemain[i]->getUname()   << "    *" << endl;
                            cout << "*                                    *" << endl;
                            cout << "**************************************" << endl;

                            break;   
                        }                    
                    }

                } 
                catch (exception &e) {
                    cout <<  e.what() << endl << endl;
                }
        }
    }
}
