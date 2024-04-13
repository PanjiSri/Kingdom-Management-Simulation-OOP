#include "peran.hpp"
#include "vector"
#include <iostream>
using namespace std;
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "MatriksPenyimpanan.hpp"

/*
 *  Class Peran
 *   
 */ 
Peran::Peran() {
    this->username = " ";
    this->gulden = 50;
    this->berat = 40;
} 

Peran::Peran(string username, int row, int col) {
    this->username = username;
    this->gulden = 50;
    this->berat = 40;
    penyimpanan.setUkuran(row, col);
}

Peran::Peran(int gulden, int berat, string username, int row, int col) {
    this->username = username;
    this->gulden = gulden;
    this->berat = berat;
    penyimpanan.setUkuran(row, col);
}

Peran::~Peran() {}

Peran& Peran::operator= (const Peran& other) {
    gulden = other.gulden;
    berat = other.berat;
    penyimpanan = other.penyimpanan;
    username = other.username;
    return *this;
}

int Peran::getGulden() {
    return this->gulden;
}

int Peran::getBerat() {
    return this->berat;
}

void Peran::printPenyimpanan() {
    cout << "=================== PENYIMPANAN ===================" << endl;
    penyimpanan.print();
}

void Peran::playerMakan() {
    printPenyimpanan();
    if (penyimpanan.isEmpety()) {
        cout << "Tidak ada yang bisa kamu makan disini" << endl;
    } else {
        Item* x;
        string kode;
        cout << "Ambil makanan dalam inventory mu: ";
        cin >> kode;
        vector<int> index = parse(kode);
        x = penyimpanan[index[1]][index[0]];
        
        if (x == NULL) {
            cout << "Tidak ada apa-apa di di sana" << endl;
        } else if ((x->getTipe() == "PRODUCT_ANIMAL") or (x->getTipe() == "PRODUCT_FRUIT_PLANT")) {
            tambahBerat(x->getTambahan());
            penyimpanan[index[1]][index[0]] = NULL;
            cout << "Berat badanmu naik jadi " << berat << endl;
        } else {
            cout << "Hei, yakin kamu mau makan itu???" << endl;
        }
    }
}

void Peran::tambahBerat(int berat_tambahan) {
    berat += berat_tambahan;
}

void Peran::addPenyimpanan(string benda, vector<Item*> listItem) {
    Item* x;
    for (int i = 0; i < listItem.size(); i++) {
        if(listItem[i]->getKode() == benda) {
            x = listItem[i];
        }
    }
    printPenyimpanan();
    string idx;
    cout << "Masukkan lokasi yang diinginkan: ";
    cin >> idx;
    vector<int> lokasi = parse(idx);
    
    cout << lokasi[1] << endl;
    cout << lokasi[0] << endl;
    penyimpanan[lokasi[1]][lokasi[0]] = x;
}

vector<int> Peran::parse(string idx) {
    vector<int> indeks;
    indeks.push_back(((int)idx[0])-65);
    indeks.push_back((int)(idx[2]-'0')-1);
    return indeks;
}



/*
 *  Class Walikota
 *   
 */
Walikota::Walikota (string username, int row, int col): Peran(username, row, col) {
    peran_pemain = "walikota";
    gulden = 50;
    berat = 40;
}

Walikota::~Walikota() {}

string Walikota::getType() {
    return peran_pemain;
}

void Walikota::addGulden(int guldentambahan) {
    this->gulden += guldentambahan;
}

void Walikota::ambilPajak(vector<Peran*> listpemain) {
    int guldenpajak = 0;
    for(int i = 0; i < listpemain.size(); i++) {
        guldenpajak += listpemain[i]->calculateTax()*0.35;
    }
    addGulden(guldenpajak);
}

void Walikota::tanam() {
    cout << "Hanya bisa dilakukan oleh petani." << endl;
}

void Walikota::panen() {
    cout << "Hanya bisa dilakukan oleh petani." << endl;
}

void Walikota::beriMakan() {
    cout << "Hanya bisa dilakukan oleh petani." << endl;
}

void Walikota::cetakLahan() {
    cout << "Anda tidak punya lahan." << endl;
}

int Walikota::getlahankosong() {
    cout << "Hanya bisa dilakukan oleh petani" << endl;
    return -1;
}

int Walikota::calculateTax() {
    return 0;
}



/*
 *  Class Petani
 *   
 */
Petani::Petani(): Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
} 

Petani::Petani(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(username, row_inventory, col_inventory) {
    peran_pemain = "petani";
    gulden = 50;
    berat = 40;
    lahanPertanian.setUkuran(row_lahan, col_lahan);
}

Petani::Petani(int gulden, int berat, string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(gulden, berat, username, row_inventory, col_inventory) {
    peran_pemain = "petani";
    this->gulden = gulden;
    this->berat = berat;
    lahanPertanian.setUkuran(row_lahan, col_lahan);
}

Petani::~Petani() {}

string Petani::getType() {
    return peran_pemain;
}

void Petani::tanam() {
    printPenyimpanan();
    string indeksinvent;
    Tanaman* tanaman;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    if (penyimpanan[lokasiinvent[1]][lokasiinvent[0]]->getTipe() == "HERBIVORE") {
        tanaman = dynamic_cast<Tanaman*>(penyimpanan[lokasiinvent[1]][lokasiinvent[0]]);
        cout << "Tumbuhan " << tanaman->getNama() << " diambil" << endl;
        cetakLahan();
        cout <<"Lahan kosong: " << this->getLahanKosong() << endl;
        if (getLahanKosong() == 0) {
            cout << "Lahan penuh" << endl;
        }
        else {
            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi = parse(idx);
            lahanPertanian[lokasi[1]][lokasi[0]] = tanaman;
            penyimpanan[lokasiinvent[1]][lokasiinvent[0]] = NULL;
        }
    }
    cetakLahan();
}

void Petani::cetakLahan() {
    int asciinum = 65;
    lahanPertanian.print();
}

int Petani::getLahanKosong() {
    int empty = 0;
    for(int i = 0; i < lahanPertanian.getBaris(); i++) {
        for(int j = 0; j < lahanPertanian.getKolom(); j++) {
            if(lahanPertanian[i][j] == NULL) {
                empty += 1;
            }
        }
    }
    return empty;
}

void Petani::panen() {
    vector<string> listtanamanmatang;
    vector<int> jumlahtanamanmatang;
    // Menghitung tanaman yang siap panen
    for(int i = 0; i < listtanamanmatang.size(); i++) {
        cout << listtanamanmatang[i] << " (" << jumlahtanamanmatang[i] << " buah)" << endl;
    }
}

void Petani::beriMakan() {
    cout << "Hanya bisa dilakukan oleh peternak" << endl;
}

int Petani::calculateTax() {
    int uang = this->gulden;
    uang += penyimpanan.getValue();
    uang += lahanPertanian.getValue();
    return uang;
}

// Child Peternak
Peternak::Peternak(): Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
}

Peternak::Peternak(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(username, row_inventory, col_inventory) {
    peran_pemain = "peternak";
    gulden = 50;
    berat = 40;
    peternakan.setUkuran(row_lahan, col_lahan);
}

Peternak::Peternak(int gulden, int berat, string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(gulden, berat, username, row_inventory, col_inventory) {
    peran_pemain = "peternak";
    this->gulden = gulden;
    this->berat = berat;
    peternakan.setUkuran(row_lahan, col_lahan);
}

Peternak::~Peternak() {}


void Peternak::cetakLahan() {
    peternakan.print();
}

void Peternak::tanam() {
    printPenyimpanan();
    string indeksinvent;
    Hewan* hewan;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    if (penyimpanan[lokasiinvent[1]][lokasiinvent[0]]->getTipe() == "HERBIVORE") {
        hewan = dynamic_cast<Hewan*>(penyimpanan[lokasiinvent[1]][lokasiinvent[0]]);
        cout << "Hewan " << hewan->getNama() << " diambil" << endl;
        cetakLahan();
        cout <<"Lahan kosong: " << this->getLahanKosong() << endl;
        if (getLahanKosong() == 0) {
            cout << "Lahan penuh" << endl;
        }
        else {
            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi = parse(idx);
            peternakan[lokasi[1]][lokasi[0]] = hewan;
            penyimpanan[lokasiinvent[1]][lokasiinvent[0]] = new Carnivore();
        }
    }
    cetakLahan();
}

void Peternak::panen() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Peternak::beriMakan() {
    cetakLahan();
    string slot;
    Hewan* hewan;
    cout << "Hewan yang akan diberi makan: ";
    cin >> slot;
    vector<int> index = parse(slot);
    hewan = peternakan[index[1]][index[0]];
    printPenyimpanan();
    Produk* produk;
    cout << "Ambil makanan: ";
    cin >> slot;
    index = parse(slot);
    produk = dynamic_cast<Produk*>(penyimpanan[index[1]][index[0]]);
    hewan->makan(produk);
}

int Peternak::getLahanKosong() {
    int empty = 0;
    for(int i = 0; i < peternakan.getBaris(); i++) {
        for(int j = 0; j < peternakan.getKolom(); j++) {
            if(peternakan[i][j] == NULL) {
                empty += 1;
            }
        }
    }
    return empty;
}

int Peternak::calculateTax() {
    int uang = this->gulden;
    uang += penyimpanan.getValue();
    uang += peternakan.getValue();
    return uang;
}