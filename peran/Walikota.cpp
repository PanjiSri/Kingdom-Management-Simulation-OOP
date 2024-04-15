#include "Walikota.hpp"

Walikota::Walikota() : Peran() {}

Walikota::Walikota(string username, int row_inv, int col_inv) : 
    Peran(username, row_inv, col_inv) 
    {}

Walikota::Walikota(string username, int berat, int gulden, int row_inv, int col_inv) :
    Peran(username, berat, gulden, row_inv, col_inv)
    {}

Walikota::~Walikota() {}

Walikota& Walikota::operator= (const Walikota &other) {
    Peran::operator=(other);
    return *this;
}

string Walikota::getType() {
    return type;
}

void Walikota::beternakBertani() {
    cout << "Kamu walikota, pekerjaanmu bukan ini!!!" << endl << endl;
}

void Walikota::beternakBertaniFile(string, string, int, vector<Item*>) {}

void Walikota::panen(vector<Produk*>) {
    cout << "Kamu walikota, pekerjaanmu bukan ini!!!" << endl << endl;
}

void Walikota::cetakLahan() {
    cout << "Emangnya kamu punya lahan!!!" << endl << endl;
}

void Walikota::beriMakan() {
    cout << "Emangnya kamu punya hewan???" << endl << endl;
}

void Walikota::addUmurTanaman() {}

int Walikota::calculateTax() {
    return 0;
}

// SEMENTARA
void Walikota::ambilPajak(vector<Peran*> listPeran) {
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah di pungut" << endl << endl;
    
    int gulden_pajak = 0;
    int pajak_pemain = 0;
    
    struct detailPajak {
        int pajak;
        string uname;
        string peran;
    };

    vector<detailPajak> detailPajak;
    // mendapatkan semua detail pajak dari pemain
    for (int i = 0; i < listPeran.size(); i++) {
        pajak_pemain = listPeran[i]->calculateTax();
        gulden_pajak += pajak_pemain;
        listPeran[i]->tambahGulden(-pajak_pemain);
        detailPajak.push_back({pajak_pemain, listPeran[i]->getUname(), listPeran[i]->getType()});
    }

    // urutkan pajak dari yang terbesar
    for (int i = 0; i < detailPajak.size(); i++) {
        int max = i;
        for (int j = i+1; j < detailPajak.size(); j++) {
            if (detailPajak[j].pajak > detailPajak[max].pajak) {
                max = j;
            } else if (detailPajak[j].pajak == detailPajak[max].pajak) {
                // bandingkan username
                // username terkecil akan diurutkan terlebih dahulu
                if (detailPajak[j].uname < detailPajak[max].uname) {
                    max = j;
                }
            }
        }
        swap(detailPajak[i], detailPajak[max]);
    }

    // cetak pajak
    cout << "Berikut adalah detail dari pemungutan pajak:" << endl;
    for (int i = 0; i < detailPajak.size(); i++) {
        cout << "   " << i+1 << ". ";
        cout << detailPajak[i].uname << " - " << detailPajak[i].peran << " : " << detailPajak[i].pajak << endl;
    }
    // tambahkan pajak ke walikota
    this->tambahGulden(gulden_pajak);
    cout << "Negara mendapatkan pemasukan sebesar " << gulden_pajak << "gulde" << endl;
    cout << "Jangan dikorupsi ya!!!"<< endl << endl;
}

void Walikota::buatUser(vector<Peran*> listPlayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    if (gulden >= 50) {
        string role, uname;
        cout << "Pilih role yang ingin dibuat: ";
        cin >> role;

        if (role == "Petani" || role == "Peternak") {
            cout << endl << "Masukkan username: ";
            gulden -= 50;

            if (role == "Petani") {
                Peran* a = new Petani(uname, row_inv, col_inv, row_farm, col_farm);
                listPlayer.push_back(a);
            }
            else {
                Peran* a = new Peternak(uname, row_inv, col_inv, row_pet, col_pet);
                listPlayer.push_back(a);
            }
            cout << endl;
        }
        else {
            cout << "Role ini tidak bisa dibuat." << endl << endl;
        }
    }
    else {
        cout << "Uang anda tidak cukup Pak Walikota." << endl << endl;
    }
}