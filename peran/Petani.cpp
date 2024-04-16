#include "Petani.hpp"
#include <string>

Petani::Petani() : Peran() {}

Petani::Petani(string username, int row_inv, int col_inv, int row_lahan, int col_lahan) : 
    Peran(username, row_inv, col_inv)
{
    lahanPertanian.setUkuran(row_lahan, col_lahan);
}

Petani::Petani(string username, int berat, int gulden, int row_inv, int col_inv, int row_lahan, int col_lahan) : 
    Peran(username, berat, gulden, row_inv, col_inv)
{
    lahanPertanian.setUkuran(row_lahan, col_lahan);
}

Petani::~Petani() {}

Petani &Petani::operator=(const Petani &other) {
    Peran::operator=(other);
    lahanPertanian = other.lahanPertanian;
    return *this;
}

string Petani::getType() {
    return type;
}

int Petani::getKekayaan() {
    return this->gulden + this->penyimpanan.getValue() + this->lahanPertanian.getValue();
}

int Petani::getRowLahan() {
    return lahanPertanian.getBaris();
}

int Petani::getKolLahan() {
    return lahanPertanian.getKolom();
}

int Petani::getBanyakItemLahan() {
    int luas = lahanPertanian.getBaris() * lahanPertanian.getKolom();
    return luas - lahanPertanian.getPetakKosong();
}

vector<vector<string>> Petani::getDataLahan() {
// mendapatkan semua item yang ada di lahan
    int asciinum = 65;
    vector<string> temp_row;
    vector<vector<string>> temp;
    int num;

    for (int i = 0; i < lahanPertanian.getBaris(); i++) {
        for (int j = 0; j < lahanPertanian.getKolom(); j++) {
            string location;
            vector<string> temp_row;
            if (lahanPertanian[i][j] != NULL) {
                num = i + 1;
                if (num < 10) {
                    location = (char)(asciinum + j) + to_string(0) + to_string(num);
                }
                else {
                    location = (char)(asciinum + j) + to_string(num);
                }
                temp_row.push_back(location);
                temp_row.push_back(lahanPertanian[i][j]->getNama());
                temp_row.push_back(to_string(lahanPertanian[i][j]->getUmur()));
                temp.push_back(temp_row);
            }
        }
    }
    return temp;
}

void Petani::beternakBertani() {
    if (lahanPertanian.getPetakKosong() == 0) {
        cout << "Lahan Anda penuh." << endl << endl;
    } else if (!penyimpanan.isAdaTanaman()) {
        cout << "Tidak ada tanaman yang bisa ditanam." << endl << endl;
    }
    else {
        cout << "Pilih tanaman dari penyimpanan" << endl;
        printPenyimpanan();
        string indeksInvent;
        Tanaman *tanaman;

        cout << "Slot: ";
        cin >> indeksInvent;
        vector<int> lokasiInvent = parse(indeksInvent);
        if (penyimpanan[lokasiInvent[1]][lokasiInvent[0]] == NULL) {
            throw SlotKosongException();
        }
        
        string tipe = penyimpanan[lokasiInvent[1]][lokasiInvent[0]]->getTipe();

        if (tipe == "MATERIAL_PLANT" || tipe == "FRUIT_PLANT") {
            tanaman = dynamic_cast<Tanaman *>(penyimpanan[lokasiInvent[1]][lokasiInvent[0]]);
            cout << "Tumbuhan " << tanaman->getNama() << " diambil." << endl
                 << endl;

            cout << "Pilih petak lahan yang ingin ditanami" << endl;
            cetakLahan();

            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi = parse(idx);

            if (lokasi[0] >= lahanPertanian.getKolom() || lokasi[1] >= lahanPertanian.getBaris()) {
                cout << "Lokasi tidak valid." << endl << endl;
            } 
            else if (lahanPertanian[lokasi[1]][lokasi[0]] != NULL) {
                cout << "Petak sudah terisi." << endl << endl;
            } 
            else {
                lahanPertanian.setElement(lokasi[1], lokasi[0], tanaman);
                penyimpanan.setElement(lokasiInvent[1], lokasiInvent[0], NULL);

                cout << endl << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
                cout << tanaman->getNama() << " berhasil ditanam!" << endl << endl;
            }
        }
        else {
            cout << "Hei, itu bukan tanaman!!!" << endl << endl;
        }
    }
}

void Petani::beternakBertaniFile(string location, string name, int umur, vector<Item *> listItem) {
    Tanaman* plant;
    for (int i = 0; i < int(listItem.size()); i++) {
        if (listItem[i]->getNama() == name) {
            plant = dynamic_cast<Tanaman*>(listItem[i]);
            plant->setUmur(umur);
        }
    }

    vector<int> lokasi = parse(location);
    lahanPertanian.setElement(lokasi[1], lokasi[0], plant);
}

void Petani::cetakLahan() {
    int lebar = this->lahanPertanian.getKolom() * 5 + this->lahanPertanian.getKolom() + 1;
    cout << "      ";
    centerAlign("[ LADANG ]", lebar);
    lahanPertanian.printWithColour();
    
    map<string, string> listTanamanDiLadang = lahanPertanian.listProdukInMatriks();
    for (auto i = listTanamanDiLadang.begin(); i != listTanamanDiLadang.end(); i++) {
        cout << "      - ";
        cout << i->first << " : " << i->second << endl;
    }
    cout << endl;
}

void Petani::panen(vector<Produk *> listProduk) {
    cetakLahan();

    vector<string> listTanamanMatang;
    vector<int> jumlahTanamanMatang;
    map<string, int> tanamanSiapPanen = lahanPertanian.listSiapPanen();

    // Menghitung tanaman yang siap panen
    for (auto i = tanamanSiapPanen.begin(); i != tanamanSiapPanen.end(); i++) {
        listTanamanMatang.push_back(i->first);
        jumlahTanamanMatang.push_back(i->second);
    }
    // Menampilkan tanaman yang siap panen
    cout << "Daftar tanaman yang siap panen: " << endl;
    for (int i = 0; i < int(listTanamanMatang.size()); i++) {
        cout << i+1 << ") " << listTanamanMatang[i] << " (" << jumlahTanamanMatang[i] << " buah)" << endl;
    }

    if (listTanamanMatang.size() == 0) { // jika tidak ada yang bisa dipanen
        cout << "Tidak ada tanaman yang bisa dipanen." << endl << endl;
    }
    else {
        // memilih jenis tanaman yang ingin dipanen
        int angka;
        cout << endl
             << "Pilih tanaman yang ingin dipananen: ";
        cin >> angka;
        angka--;

        if (angka >= int(listTanamanMatang.size()) || angka < 0) { // jika masukan tidak valid
            cout << "Hei, apakah kamu tidak bisa membaca!!!." << endl
                 << endl;
        }
        else {
            // memilih berapa banyak tanaman dari jenis tsb yang ingin dipanen
            cout << "Tanaman " << listTanamanMatang[angka] << " dipilih" << endl
                 << endl;
            cout << "Berapa petak yang ingin dipanen: ";
            int jumlah;
            cin >> jumlah;

            if (jumlah > jumlahTanamanMatang[angka]) { // jika input lebih dari yang ada
                cout << "Tanaman yang bisa dipanen tidak sebanyak itu tahu." << endl
                     << endl;
            }
            else {
                for (int x = 0; x < jumlah; x++) {
                    bool get = false;

                    while (get == false) {
                        // memilih petak yang ingin dipanen
                        string kode;
                        cout << "Pilih petak ke-" << x + 1 << " : ";
                        cin >> kode;
                        vector<int> index = parse(kode);

                        if (index[0] >= lahanPertanian.getKolom() || index[1] >= lahanPertanian.getBaris()) {
                            cout << "Lokasi yang anda masukkan salah." << endl << endl;
                        }
                        else if (lahanPertanian[index[1]][index[0]] == NULL) {
                            cout << "Tidak ada tanaman di sana." << endl << endl;
                        }
                        else {
                            Tanaman *tanaman;
                            // cek apakah masukan benar
                            if (this->lahanPertanian[index[1]][index[0]]->getNama() == listTanamanMatang[angka]) {
                                tanaman = this->lahanPertanian[index[1]][index[0]];
                                this->lahanPertanian[index[1]][index[0]] = NULL;
                                vector<string> hasilPanen = tanaman->getProduk();

                                if (penyimpanan.getPetakKosong() == 0) {
                                    cout << "Inventory Anda sudah penuh." << endl << endl;
                                    this->lahanPertanian[index[1]][index[0]] = tanaman;
                                    return;
                                }
                                else {
                                    for (int banyak_produk = 0; banyak_produk < int(hasilPanen.size()); banyak_produk++) {
                                        Produk *produk;
                                        for (int q = 0; q < int(listProduk.size()); q++) {
                                            // membuat objek produk dari string nama pada hasilPanen
                                            if (hasilPanen[banyak_produk] == listProduk[q]->getNama()) {
                                                produk = listProduk[q];
                                            }
                                        }
                                        penyimpanan += produk;
                                    }
                                    get = true;
                                }
                            }
                            else { // jika masukan salah
                                cout << "Lokasi yang anda masukkan salah." << endl << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Petani::beriMakan() {
    cout << "Emangnya kamu punya hewan???" << endl << endl;
}

void Petani::addUmurTanaman() {
    for (int i = 0; i < lahanPertanian.getBaris(); i++) {
        for (int j = 0; j < lahanPertanian.getKolom(); j++) {
            if (lahanPertanian[i][j] != NULL) {
                lahanPertanian[i][j]->tambahUmur();
            }
        }
    }
}

void Petani::ambilPajak(vector<Peran *> list) {
    cout << "Hei, ini bukan wewenangmu!!!" << endl
         << endl;
}

Peran* Petani::buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_lahan, int col_lahan, int row_ternak, int col_ternak) {
    cout << "Hanya walikota yang bisa melakukannya." << endl << endl;
    return NULL;
}

int Petani::calculateTax() {
    int KKP, pajak;
    KKP = this->getKekayaan() - 13;

    if (KKP <= 6) {
        pajak = KKP * 0.05;
    }
    else if (KKP > 6 && KKP <= 25) {
        pajak = KKP * 0.15;
    }
    else if (KKP > 25 && KKP <= 50) {
        pajak = KKP * 0.25;
    }
    else if (KKP > 50 && KKP <= 500) {
        pajak = KKP * 0.30;
    }
    else {
        pajak = KKP * 0.35;
    }

    // jika gulden yang dimiliki lebih kecil dari pajak yang dikeluarkan
    if (gulden < pajak) {
        pajak = gulden;
    }

    return pajak;
}

void Petani::bangun(vector<Bangunan *> listbangunan) {
    cout << "Kamu tidak punya wewenang untuk membangun." << endl << endl;
}

void Petani::membeli(Toko* toko) {
// Membeli item dari toko
    toko->cetakListBarang();
    int noBarang;
    int kuantitas;

    cout << endl << "Uang Anda : " << gulden << endl;
    cout << "Slot Penyimpanan tersedia : " << penyimpanan.getPetakKosong() << endl << endl;
    cout << "Barang ingin dibeli : "; 
    cin >> noBarang;
    cout << endl << "Kuantitas : ";
    cin >> kuantitas;

    Item* item = toko->jual(noBarang, kuantitas);
    if (this->getGulden() < item->getHarga()*kuantitas) {
        cout << "Uang yang Anda miliki tidak cukup." << endl << endl;
    } else if (kuantitas > penyimpanan.getPetakKosong()) {
        cout << "Slot penyimpanan tidak cukup." << endl << endl;
    } else {
        penyimpanan.print();
        for (int i = 0; i < kuantitas; i++) {
            string location;
            cout << "Masukkan lokasi untuk item ke-" << i << " : ";
            cin >> location;
            vector<int> index = parse(location);
            if (index[0] >= penyimpanan.getKolom() || index[1] >= penyimpanan.getBaris()) {
                cout << "Lokasi yang anda masukkan salah." << endl << endl;
                i--;
            }
            else if (penyimpanan[index[1]][index[0]] != NULL) {
                cout << "Slot sudah terisi." << endl;
                i--;
            } else {
                penyimpanan.setElement(index[1], index[0], item);
                this->gulden -= item->getHarga();
            }
        }
    }
}

void Petani::menjual(Toko* toko) {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    printPenyimpanan();
    
    if (penyimpanan.isEmpety()) {
        cout << "Penyimpanan Anda kosong!" << endl << endl;
    } else {
        int total_barang;
        int total_uang = 0;
        cout << "Berapa benda yang ingin Anda jual: ";
        cin >> total_barang;

        if (total_barang > penyimpanan.getPetakTerisi()) {
            cout << "Barang yang ingin Anda jual lebih dari yang Anda punya!" << endl << endl;
        } else {
            cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
            for (int i = 0; i < total_barang; i++) {
                cout << "Petak ke-" << i+1 << " : ";
                string indeksInvent;
                cin >> indeksInvent;
                vector<int> idx = parse(indeksInvent);

                if (idx[0] >= penyimpanan.getKolom() || idx[1] >= penyimpanan.getBaris()) {
                    cout << "Lokasi yang anda masukkan salah." << endl << endl;
                    i--;
                }
                else if (penyimpanan[idx[1]][idx[0]] == NULL) {
                    cout << "Petak kosong." << endl;
                    i--;
                } else {
                    Item* barang;
                    barang = penyimpanan[idx[1]][idx[0]];
                    // handle error kalo bangunan
                    if (barang->getTipe() == "BANGUNAN") {
                        throw PetaniPeternakTidakBisaJualBangunanException();
                    }

                    toko->beli(barang);
                    total_uang += barang->getHarga();
                    penyimpanan.setElement(idx[1], idx[0], NULL);
                }
            }
            cout << "Barang Anda berhasil dijual! Uang Anda bertambah "<< total_uang << " gulden!" << endl << endl;
            this->gulden += total_uang;
        }
    }
}

void Petani::simpan(vector<Peran*> list_pemain, Toko *toko) {
// menyimpan data pemain ke dalam file
    string file_path;
    cout << "Masukkan lokasi berkas state : ";
    cin >> file_path;
    size_t pos = file_path.find_last_of("/");
    string namaFolder = file_path.substr(0, pos);

    struct stat info;
    if (stat(namaFolder.c_str(), &info) != 0 || !(info.st_mode & S_IFDIR)) {
        throw FolderTidakAdaException();
    }

    ofstream outfile(file_path);

    if (!outfile.is_open()) {
        throw FilePathTidakValid();
    }

    int banyak_pemain = list_pemain.size();

    outfile << banyak_pemain << endl;

    for (int i = 0; i < banyak_pemain; i++) {
        outfile << list_pemain[i]->getUname() << " " << list_pemain[i]->getType() << " " << to_string(list_pemain[i]->getBerat()) << " " << to_string(list_pemain[i]->getGulden()) << endl;

        int banyak_di_penyimpanan = (list_pemain[i]->getPenyimpanan().getBaris() * list_pemain[i]->getPenyimpanan().getKolom()) - list_pemain[i]->getPenyimpanan().getPetakKosong();

        outfile << banyak_di_penyimpanan << endl;

        for (int j = 0; j < list_pemain[i]->getPenyimpanan().getBaris(); j++) {
            for (int k = 0; k < list_pemain[i]->getPenyimpanan().getKolom(); k++) {
                if (list_pemain[i]->getPenyimpanan()[j][k] != NULL) {
                    outfile << list_pemain[i]->getPenyimpanan()[j][k]->getNama() << endl;
                }
            }
        }

        if (list_pemain[i]->getType() == "Peternak") {
            int banyak_ternak = list_pemain[i]->getBanyakItemLahan();

            outfile << banyak_ternak << endl;

            vector<vector<string>> temp = list_pemain[i]->getDataLahan();
            for (int m = 0; m < int(temp.size()); m++) {
                outfile << temp[m][0] << " " << temp[m][1] << " " << temp[m][2] << endl;
            }
        }

        if (list_pemain[i]->getType() == "Petani") {
            int banyak_tandur = list_pemain[i]->getBanyakItemLahan();

            outfile << banyak_tandur << endl;

            vector<vector<string>> temp = list_pemain[i]->getDataLahan();
            for (int n = 0; n < int(temp.size()); n++) {
                outfile << temp[n][0] << " " << temp[n][1] << " " << temp[n][2] << endl;
            }
        }
    }

    vector<vector<string>> data_toko = toko->getBarangJumlah();
    int sum = 0;
    for(int i = 0; i < int(data_toko.size()); i++) {
        if (!(data_toko[i][1] == "0" || data_toko[i][1] == "-1")) {
            sum += 1;
        }
    }

    outfile << sum << endl;

    for(int i = 0; i < int(data_toko.size()); i++) {
        if (!(data_toko[i][1] == "0" || data_toko[i][1] == "-1")) {
            outfile << data_toko[i][0] << " " << data_toko[i][1] << endl;
        }
    }

    outfile.close();
    cout << "Data pemain berhasil disimpan!" << endl << endl;
}
