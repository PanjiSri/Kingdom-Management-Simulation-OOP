#include "Petani.hpp"

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

Petani& Petani::operator= (const Petani &other) {
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

void Petani::beternakBertani() {
    if (lahanPertanian.getLahanKosong() == 0) {
        cout << "Lahan Anda penuh." << endl << endl;
    } else {
        cout << "Pilih tanaman dari penyimpanan" << endl;
        printPenyimpanan();
        string indeksInvent;
        Tanaman* tanaman;

        cout << "Slot: ";
        cin >> indeksInvent;
        vector<int> lokasiInvent;
        try {
            lokasiInvent = parse(indeksInvent);
        } catch (LokasiTidakValidException e) {
            cout << e.what() << endl << endl;
            return;
        }

        string tipe = penyimpanan[lokasiInvent[1]][lokasiInvent[0]]->getTipe();
        
        if (tipe == "MATERIAL_PLANT" || tipe == "FRUIT_PLANT") {
            tanaman = dynamic_cast<Tanaman*> (penyimpanan[lokasiInvent[1]][lokasiInvent[0]]);
            cout << "Tumbuhan " << tanaman->getNama() << " diambil." << endl << endl;
            
            cout << "Pilih petak lahan yang ingin ditanami" << endl;
            cetakLahan();
            
            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi;
            try {
                lokasi = parse(idx);
            } catch (LokasiTidakValidException e) {
                cout << e.what() << endl << endl;
                return;
            }

            lahanPertanian.setElement(lokasi[1], lokasi[0], tanaman);
            penyimpanan.setElement(lokasiInvent[1], lokasiInvent[0], NULL);

            cout << endl << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
            cout << tanaman->getNama() << " berhasil ditanam!" << endl << endl;
        } else {
            cout << "Hei, itu bukan tanaman!!!" << endl << endl;
        }
    }
// cetakLahan();
}

void Petani::beternakBertaniFile(string location, string name, int umur, vector<Item*> listItem) {
    Tanaman* plant;
    for (int i = 0; i < listItem.size(); i++) {
        if (listItem[i]->getNama() == name) {
            plant = dynamic_cast<Tanaman*>(listItem[i]);
        }
        plant->setUmur(umur);
    }

    vector<int> lokasi;
    try {
        lokasi = parse(location);
    } catch (LokasiTidakValidException e) {
        cout << e.what() << endl << endl;
        return;
    }
    lahanPertanian.setElement(lokasi[1], lokasi[0], plant);
}

void Petani::cetakLahan() {
    int lebar = this->lahanPertanian.getKolom()*5 + this->lahanPertanian.getKolom() + 1;
    cout << "      ";
    centerAlign("[ LADANG ]", lebar);
    lahanPertanian.printlahan();
}

void Petani::panen(vector<Produk*> listProduk) {
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
    for (int i = 0; i < listTanamanMatang.size(); i++) {
        cout << i+1 << ") " << listTanamanMatang[i] << " (" << jumlahTanamanMatang[i] << " buah)" << endl;
    }

    if (listTanamanMatang.size() == 0) { // jika tidak ada yang bisa dipanen
        cout << "Tidak ada tanaman yang bisa dipanen." << endl << endl;
    } else {
        // memilih jenis tanaman yang ingin dipanen
        int angka;
        cout << endl << "Pilih tanaman yang ingin dipananen: ";
        cin >> angka;
        angka--;

        if (angka >= listTanamanMatang.size() || angka < 0) { // jika masukan tidak valid
            cout << "Hei, apakah kamu tidak bisa membaca!!!." << endl << endl;
        } 
        else {
            // memilih berapa banyak tanaman dari jenis tsb yang ingin dipanen
            cout << "Tanaman " << listTanamanMatang[angka] << " dipilih" << endl << endl;
            cout << "Berapa petak yang ingin dipanen: ";
            int jumlah;
            cin >> jumlah;

            if (jumlah > jumlahTanamanMatang[angka]) { // jika input lebih dari yang ada
                cout << "Tanaman yang bisa dipanen tidak sebanyak itu tahu." << endl << endl;
            }
            else {
                for (int x = 0; x < jumlah; x++) {
                    bool get = false;

                    while (get == false) {
                        // memilih petak yang ingin dipanen
                        string kode;
                        cout << "Pilih petak ke-" << x + 1 << " : ";
                        cin >> kode;
                        vector<int> index;
                        try {
                            index = parse(kode);
                        } catch (LokasiTidakValidException e) {
                            cout << e.what() << endl << endl;
                            continue;
                        }

                        Tanaman* tanaman;
                        // cek apakah masukan benar
                        if (this->lahanPertanian[index[1]][index[0]]->getNama() == listTanamanMatang[angka]) {
                            tanaman = this->lahanPertanian[index[1]][index[0]];
                            this->lahanPertanian[index[1]][index[0]] = NULL;
                            vector<string> hasilPanen = tanaman->getProduk();

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
                            // }
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

void Petani::beriMakan() {
    cout << "Emangnya kamu punya hewan???" << endl << endl;
}

void Petani::addUmurTanaman() {
    for (int i = 0 ; i < lahanPertanian.getBaris(); i++) {
        for (int j = 0; j < lahanPertanian.getKolom(); j++) {
            if (lahanPertanian[i][j] != NULL) {
                lahanPertanian[i][j]->tambahUmur();
            }
        }
    }
}

void Petani::ambilPajak(vector<Peran*> list) {
    cout << "Hei, ini bukan wewenangmu!!!" << endl << endl;
}

void Petani::buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    cout << "Hanya walikota yang bisa melakukannya." << endl << endl;
}

int Petani::calculateTax() {
    int KKP, pajak;
    KKP = this->getKekayaan() - 13;
    
    if (KKP <= 6) {
        pajak = KKP * 0.05;
    } else if (KKP > 6 && KKP <= 25) {
        pajak = KKP * 0.15;
    } else if (KKP > 25 && KKP <= 50) {
        pajak = KKP * 0.25;
    } else if (KKP > 50 && KKP <= 500) {
        pajak = KKP * 0.30;
    } else {
        pajak = KKP * 0.35;
    }

    // jika gulden yang dimiliki lebih kecil dari pajak yang dikeluarkan
    if (gulden < pajak) {
        pajak = gulden;
    }

    return pajak;
}

void Petani::bangun() {
    cout << "Kamu tidak punya wewenang untuk membangun." << endl << endl;
}