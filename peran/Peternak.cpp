#include "Peternak.hpp"

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

void Peternak::beternakBertani() {
    if (peternakan.getLahanKosong() == 0) {
        cout << "Peternakan Anda penuh." << endl << endl;
    } else {
        cout << "Pilih hewan dari penyimpanan" << endl;
        printPenyimpanan();
        string indeksInvent;
        Hewan* hewan;

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

        if (tipe == "HERBIVORE" || tipe == "CARNIVORE" || tipe == "OMNIVORE") {
                hewan = dynamic_cast<Hewan*> (penyimpanan[lokasiInvent[1]][lokasiInvent[0]]);
                cout << "Hewan " << hewan->getNama() << " diambil." << endl << endl;
                
                cout << "Pilih petak tanah untuk hewan Anda" << endl;
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
        }
        hewan->setBerat(berat);
    }

    vector<int> lokasi;
    try {
        lokasi = parse(location);
    } catch (LokasiTidakValidException e) {
        cout << e.what() << endl << endl;
        return;
    }
    peternakan.setElement(lokasi[1], lokasi[0], hewan);
}

void Peternak::cetakLahan() {
    int lebar = this->peternakan.getKolom()*5 + this->peternakan.getKolom() + 1;
    cout << "      ";
    centerAlign("[ PETERNAKAN ]", lebar);
    peternakan.printlahan();
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
                        vector<int> index;
                        try {
                            index = parse(kode);;
                        } catch (LokasiTidakValidException e) {
                            cout << e.what() << endl << endl;
                            continue;
                        }

                        Hewan* hewan;
                        // cek apakah masukan benar
                        if (this->peternakan[index[1]][index[0]]->getNama() == listHewanPanen[angka]) {
                            hewan = this->peternakan[index[1]][index[0]];
                            this->peternakan[index[1]][index[0]] = NULL;
                            vector<string> hasilPanen = hewan->getProduk();

                            if (hasilPanen.size() > penyimpanan.getLahanKosong()) {
                                // ada hewan yang menghasilkan 2 produk
                                cout << "Inventory Anda tidak cukup untuk produk hewan tersebut." << endl << endl;
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

    bool kondisi;
    string slot;
    Hewan* hewan;

    cout << "Pilih hewan yang akan diberi makan: ";
    cin >> slot;
    cout << endl;
    vector<int> index;
    try {
        index = parse(slot);
    } catch (LokasiTidakValidException e) {
        cout << e.what() << endl << endl;
        return;
    }

    hewan = peternakan[index[1]][index[0]];

    if (hewan == NULL) {
        cout << "Tidak ada hewan di sana." << endl << endl;
    }
    else {
        printPenyimpanan();
        Produk* produk;
        cout << "Ambil makanan: ";
        cin >> slot;
        index;
        try {
            index = parse(slot);
        } catch (LokasiTidakValidException e) {
            cout << e.what() << endl << endl;
            return;
        }
        produk = dynamic_cast<Produk*> (penyimpanan[index[1]][index[0]]);

        if (produk == NULL) {
            cout << "Tidak ada apa-apa di di sana." << endl << endl;
        } 
        else {
            try {
                hewan->makan(produk);
                hewan->tambahBerat(produk->getTambahan());
                cout << "Makanan berhasil diberikan" << endl;
                cout << "Berat "<< hewan->getNama() <<" menjadi " << hewan->getBeratSaatIni() << endl << endl;
                penyimpanan.setElement(index[1], index[0], NULL);
            } catch (CarnivoraTidakMakanSayurException e) {
                cout << e.what() << endl << endl;
            } catch (MaterialPlantTidakDimakanException e) {
                cout << e.what() << endl << endl;
            } catch (HerbivoraTidakMakanDagingException e) {
                cout << e.what() << endl << endl;
            }
        }
    }
}

void Peternak::addUmurTanaman() {}

void Peternak::ambilPajak(vector<Peran*> list) {
    cout << "Hei, ini bukan wewenangmu!!!" << endl << endl;
}

void Peternak::buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    cout << "Hanya walikota yang bisa melakukannya." << endl << endl;
}

int Peternak::calculateTax() {
    int KKP, pajak;
    KKP = this->getKekayaan() - 11;
    
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

void Peternak::bangun() {
    cout << "Kamu tidak punya wewenang untuk membangun." << endl << endl;
}