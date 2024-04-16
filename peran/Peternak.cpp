#include "Peternak.hpp"
#include <string>

Peternak::Peternak() : Peran() {}

Peternak::Peternak(string username, int row_inv, int col_inv, int row_pet, int col_pet) : 
    Peran(username, row_inv, col_inv) 
    {
        peternakan.setUkuran(row_pet, col_pet);
    }

Peternak::Peternak(string username, int berat, int gulden, int row_inv, int col_inv, int row_pet, int col_pet) :
    Peran(username, berat, gulden, row_inv, col_inv)
    {
        peternakan.setUkuran(row_pet, col_pet);
    }

Peternak::~Peternak() {}

Peternak& Peternak::operator= (const Peternak &other) {
    Peran::operator=(other);
    peternakan = other.peternakan;
    return *this;
}

string Peternak::getType() {
    return type;
}

int Peternak::getKekayaan() {
    return this->gulden + this->penyimpanan.getValue() + this->peternakan.getValue();
}

int Peternak::getRowLahan() {
    return peternakan.getBaris();
}

int Peternak::getKolLahan() {
    return peternakan.getKolom();
}

int Peternak::getBanyakItemLahan() {
    int luas = peternakan.getBaris() * peternakan.getKolom();
    return luas - peternakan.getPetakKosong();
}

vector<vector<string>> Peternak::getDataLahan() {
// mendapatkan semua item yang ada di lahan
    int asciinum = 65;
    vector<string> temp_row;
    vector<vector<string>> temp;
    int num;
    for(int i = 0; i < peternakan.getBaris(); i++) {
        for(int j = 0; j < peternakan.getKolom(); j++) {
            string location;
            vector<string> temp_row;
            if(peternakan[i][j] != NULL) {
                num = i + 1;
                if(num < 10) {
                    location = (char)(asciinum+j) + to_string(0) + to_string(num);
                }
                else {
                    location = (char)(asciinum+j) + to_string(num);
                }
                temp_row.push_back(location);
                temp_row.push_back(peternakan[i][j]->getNama());
                temp_row.push_back(to_string(peternakan[i][j]->getBeratSaatIni()));
                temp.push_back(temp_row);
            }
        }
    }
    return temp;
}

void Peternak::beternakBertani() {
    if (peternakan.getPetakKosong() == 0) {
        cout << "Peternakan Anda penuh." << endl << endl;
    } else if (!penyimpanan.isAdaHewan()) {
        cout << "Anda tidak memiliki hewan." << endl << endl;
    } else {
        cout << "Pilih hewan dari penyimpanan" << endl;
        printPenyimpanan();
        string indeksInvent;
        Hewan* hewan;

        cout << "Slot: ";
        cin >> indeksInvent;
        vector<int> lokasiInvent = parse(indeksInvent);
        string tipe = penyimpanan[lokasiInvent[1]][lokasiInvent[0]]->getTipe();

        if (tipe == "HERBIVORE" || tipe == "CARNIVORE" || tipe == "OMNIVORE") {
                hewan = dynamic_cast<Hewan*> (penyimpanan[lokasiInvent[1]][lokasiInvent[0]]);
                cout << "Hewan " << hewan->getNama() << " diambil." << endl << endl;
                
                cout << "Pilih petak tanah untuk hewan Anda" << endl;
                cetakLahan();
                
                string idx;
                cout << "Masukkan lokasi yang diinginkan: ";
                cin >> idx;
                vector<int> lokasi = parse(idx);

                peternakan.setElement(lokasi[1], lokasi[0], hewan);
                penyimpanan.setElement(lokasiInvent[1], lokasiInvent[0], NULL);

                cout << endl << "Dengan hati-hati, kamu meletakkan seekor " << hewan->getNama() <<  " di kandang" << endl;
                cout << hewan->getNama() << " telah menjadi peliharaanmu sekarang!!" << endl << endl;
        } else {
            cout << "Hei, itu bukan hewan!!!" << endl << endl;
        }
    }
// cetakLahan();
}

void Peternak::beternakBertaniFile(string location, string name, int berat, vector<Item*> listItem) {
    Hewan* hewan;
    for (int i = 0; i < listItem.size(); i++) {
        if (listItem[i]->getNama() == name) {
            hewan = dynamic_cast<Hewan*>(listItem[i]);
            hewan->setBerat(berat);
        }
    }

    vector<int> lokasi = parse(location);
    peternakan.setElement(lokasi[1], lokasi[0], hewan);
}

void Peternak::cetakLahan() {
    int lebar = this->peternakan.getKolom()*5 + this->peternakan.getKolom() + 1;
    cout << "      ";
    centerAlign("[ PETERNAKAN ]", lebar);
    peternakan.printlahan();

    map<string, string> listHewanDiPeternakan = peternakan.listProdukInMatriks();
    for (auto i = listHewanDiPeternakan.begin(); i != listHewanDiPeternakan.end(); i++) {
        cout << "      - ";
        cout << i->first << " : " << i->second << endl;
    }
    cout << endl;
}

void Peternak::panen(vector<Produk*> listProduk) {
    cetakLahan();
    
    vector<string> listHewanPanen;
    vector<int> jumlahHewanPanen;
    map<string, int> hewanSiapPanen = peternakan.listSiapPanen();
    
    // Menghitung hewan yang siap panen
    for (auto i = hewanSiapPanen.begin(); i != hewanSiapPanen.end(); i++) {
        listHewanPanen.push_back(i->first);
        jumlahHewanPanen.push_back(i->second);
    }
    // Menampilkan hewan yang siap panen
    cout << "Daftar hewan yang siap panen: " << endl;
    for (int i = 0; i < listHewanPanen.size(); i++) {
        cout << i+1 << ") " << listHewanPanen[i] << " (" << jumlahHewanPanen[i] << " ekor)" << endl;
    }

    if (listHewanPanen.size() == 0) { // jika tidak ada yang bisa dipanen
        cout << "Tidak ada hewan yang bisa dipanen." << endl << endl;
    } else {
        // memilih jenis hewan yang ingin dipanen
        int angka;
        cout << endl << "Pilih hewan yang ingin dipananen: ";
        cin >> angka;
        angka--;

        if (angka >= listHewanPanen.size() || angka < 0) { // jika masukan tidak valid
            cout << "Hei, apakah kamu tidak bisa membaca!!!." << endl << endl;
        } 
        else {
            // memilih berapa banyak hewan dari jenis tsb yang ingin dipanen
            cout << "Hewan " << listHewanPanen[angka] << " dipilih" << endl << endl;
            cout << "Berapa petak yang ingin dipanen: ";
            int jumlah;
            cin >> jumlah;

            if (jumlah > jumlahHewanPanen[angka]) { // jika input lebih dari yang ada
                cout << "Hewan yang bisa dipanen tidak sebanyak itu tahu." << endl << endl;
            }
            else {
                for (int x = 0; x < jumlah; x++) {
                    bool get = false;

                    while (get == false) {
                        // memilih petak yang ingin dipanen
                        string kode;
                        cout << "Pilih petak ke-" << x + 1 << " : ";
                        cin >> kode;
                        vector<int> index = parse(kode);;

                        Hewan* hewan;
                        // cek apakah masukan benar
                        if (this->peternakan[index[1]][index[0]]->getNama() == listHewanPanen[angka]) {
                            hewan = this->peternakan[index[1]][index[0]];
                            this->peternakan[index[1]][index[0]] = NULL;
                            vector<string> hasilPanen = hewan->getProduk();

                            if (hasilPanen.size() > penyimpanan.getPetakKosong()) {
                                // ada hewan yang menghasilkan 2 produk
                                cout << "Inventory Anda tidak cukup untuk produk hewan tersebut." << endl << endl;
                                this->peternakan[index[1]][index[0]] = hewan;
                                get = true;
                            } else if (penyimpanan.getPetakKosong() == 0) {
                                cout << "Inventory Anda sudah penuh." << endl << endl;
                                this->peternakan[index[1]][index[0]] = hewan;
                                return;
                            }
                            else {
                                for (int banyak_produk = 0; banyak_produk < hasilPanen.size(); banyak_produk++) {
                                    Produk* produk;
                                    for (int q = 0; q < listProduk.size(); q++) {
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

void Peternak::beriMakan() {
    cetakLahan();
    if (peternakan.isEmpety()) {
        cout << "Anda belum memiliki hewan." << endl << endl;
    }
    else {
        bool kondisi;
        string slot;
        Hewan* hewan;

        cout << "Pilih hewan yang akan diberi makan: ";
        cin >> slot;
        cout << endl;
        vector<int> index = parse(slot);

        hewan = peternakan[index[1]][index[0]];
        if (hewan == NULL) {
            cout << "Tidak ada hewan di sana." << endl << endl;
        }
        else {
            if (penyimpanan.isAdaMakanan(hewan->getTipe())) {
                printPenyimpanan();
                Item* item;
                cout << "Ambil makanan: ";
                cin >> slot;
                index = parse(slot);
                item = dynamic_cast<Item*> (penyimpanan[index[1]][index[0]]);

                if (item == NULL) {
                    cout << "Tidak ada apa-apa di di sana." << endl << endl;
                } 
                else {
                        hewan->makan(item);
                        cout << "Makanan berhasil diberikan" << endl;
                        cout << "Berat "<< hewan->getNama() <<" menjadi " << hewan->getBeratSaatIni() << endl << endl;
                        penyimpanan.setElement(index[1], index[0], NULL);
                }
            }
            else {
                cout << "Tidak ada makanan yang cocok untuk hewan ini." << endl << endl;
            }
        }
    }
}

void Peternak::addUmurTanaman() {}

void Peternak::ambilPajak(vector<Peran*> list) {
    cout << "Hei, ini bukan wewenangmu!!!" << endl << endl;
}

Peran* Peternak::buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_lahan, int col_lahan, int row_ternak, int col_ternak) {
    cout << "Hanya walikota yang bisa melakukannya." << endl << endl;
    return NULL;
}

int Peternak::calculateTax() {
    int KKP, pajak;
    KKP = this->getKekayaan() - 11;
    
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

void Peternak::bangun(vector<Bangunan *> listbangunan) {
    cout << "Kamu tidak punya wewenang untuk membangun." << endl << endl;
}

void Peternak::membeli(Toko* toko) {
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
            if (penyimpanan[index[1]][index[0]] != NULL) {
                cout << "Slot sudah terisi." << endl;
                i--;
            } else {
                penyimpanan.setElement(index[1], index[0], item);
                this->gulden -= item->getHarga();
            }
        }
    }
}

void Peternak::menjual(Toko* toko) {
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
                Item* barang;
                barang = penyimpanan[idx[1]][idx[0]];

                if (barang == NULL) {
                    cout << "Petak kosong." << endl;
                    i--;
                } else {
                    // handle error kalo bangunan
                    if (barang->getTipe() == "BANGUNAN") {
                        throw PetaniPeternakTidakBisaJualBangunanException();
                    }

                    toko->beli(barang);
                    gulden = gulden + barang->getHarga();
                    total_uang += barang->getHarga();
                    penyimpanan.setElement(idx[1], idx[0], NULL);
                }
            }
            cout << "Barang Anda berhasil dijual! Uang Anda bertambah "<< total_uang << " gulden!" << endl << endl;
            this->gulden += total_uang;
        }
    }
}

void Peternak::simpan(vector<Peran *> list_pemain, Toko *toko) {
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

        outfile << to_string(banyak_di_penyimpanan) << endl;

        for (int j = 0; j < list_pemain[i]->getPenyimpanan().getBaris(); j++) {
            for (int k = 0; k < list_pemain[i]->getPenyimpanan().getKolom(); k++) {
                if (list_pemain[i]->getPenyimpanan()[j][k] != NULL) {
                    outfile << list_pemain[i]->getPenyimpanan()[j][k]->getNama() << endl;
                }
            }
        }

        if (list_pemain[i]->getType() == "Peternak") {
            cout << "tes tes" << endl;
            int banyak_ternak = list_pemain[i]->getBanyakItemLahan();

            cout << banyak_ternak << endl;

            outfile << banyak_ternak << endl;

            vector<vector<string>> temp = list_pemain[i]->getDataLahan();
            for (int j = 0; j < temp.size(); j++) {
                outfile << temp[j][0] << " " << temp[j][1] << " " << temp[j][2] << endl;
            }
        }

        if (list_pemain[i]->getType() == "Petani"){
            int banyak_tandur = list_pemain[i]->getBanyakItemLahan();

            outfile << banyak_tandur << endl;

            vector<vector<string>> temp = list_pemain[i]->getDataLahan();
            for (int j = 0; j < temp.size(); j++) {
                outfile << temp[j][0] << " " << temp[j][1] << " " << temp[j][2] << endl;
            }
        }
    }
    
    vector<vector<string>> data_toko = toko->getBarangJumlah();
    int sum = 0;
    for(int i = 0; i < data_toko.size(); i++) {
        if (data_toko[i][1] != "0" || data_toko[i][1] != "-1") {
            sum += 1;
        }
    }

    outfile << sum << endl;

    for(int i = 0; i < data_toko.size(); i++) {
        if (data_toko[i][1] != "0" || data_toko[i][1] != "-1") {
            outfile << data_toko[i][0] << " " << data_toko[i][1] << endl;
        }
    }

    outfile.close();
    cout << "Data pemain berhasil disimpan!" << endl << endl;
}
