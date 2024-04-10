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
#include "vector.hpp"

// Parent Peran

Peran::Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
} 

Peran::Peran(string username) {
    this->username = username;
    gulden = 50;
    berat = 40;
}

Peran::Peran(int gulden, int berat, string username) {
    this->username = username;
    this->gulden = gulden;
    this->berat = berat;
}

int Peran::getgulden() {
    return this->gulden;
}

int Peran::getberat() {
    return this->berat;
}

vector<int> Peran::parse(string idx) {
    vector<int> indeks;
    indeks.push_back(((int)idx[0])-65);
    indeks.push_back((int)(idx[2]-'0')-1);
    return indeks;
}

string Peran::get_type() {
    return this->peran_pemain;
}

void Peran::printpenyimpanan() {
    cout << "===================PENYIMPANAN====================" << endl;
    penyimpanan.print();
}

Peran& Peran::operator=(const Peran& other) {
    gulden = other.gulden;
    berat = other.berat;
    penyimpanan = other.penyimpanan;
    username = other.username;
    return *this;
}

void Peran::addpenyimpanan(string benda, vector<Item*> listitem) {
    Item* x;
    for(int i = 0; i < listitem.size(); i++) {
        if(listitem[i]->getKode() == benda) {
            x = listitem[i];
        }
    }
    printpenyimpanan();
    string idx;
    cout << "Masukkan lokasi yang diinginkan: ";
    cin >> idx;
    vector<int> lokasi = parse(idx);
    cout << lokasi[1] << endl;
    cout << lokasi[0] << endl;
    penyimpanan[lokasi[1]][lokasi[0]] = x;
}

void Peran::player_makan() {
    printpenyimpanan();
    Item* x;
    string kode;
    cout << "Ambil makanan dalam inventory mu: ";
    cin >> kode;
    vector<int> index = parse(kode);
    x = penyimpanan[index[1]][index[0]];
    if((x->getTipe() == "PRODUCT_ANIMAL") or (x->getTipe() == "PRODUCT_FRUIT_PLANT")) {
        setberat(x->getTambahan());
    }
    else {
        cout << "Jangan makan barang mentah atau kosong" << endl;
    }
}

void Peran::setberat(int berat_tambahan) {
    berat += berat_tambahan;
}

// Child Walikota
Walikota::Walikota (string username): Peran(username) {
    peran_pemain = "walikota";
    gulden = 50;
    berat = 40;
}

void Walikota::addgulden(int guldentambahan) {
    this->gulden += guldentambahan;
}

void Walikota::ambilpajak(vector<Peran*> listpemain) {
    int guldenpajak = 0;
    for(int i = 0; i < listpemain.size(); i++) {
        guldenpajak += listpemain[i]->calculateTax()*0.35;
    }
    addgulden(guldenpajak);
}

void Walikota::tanam() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Walikota::panen() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Walikota::cetaklahan() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Walikota::berimakan() {
}

int Walikota::getlahankosong() {
    cout << "Hanya bisa dilakukan petani" << endl;
    return -1;
}

int Walikota::calculateTax() {
    return 0;
}


// Child Petani

Petani::Petani(string username): Peran(username) {
    peran_pemain = "petani";
}

Petani::Petani(): Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
} 

Petani::Petani(int gulden, int berat, string username): Peran(gulden, berat, username) {
}

void Petani::cetaklahan() {
    int asciinum = 65;
    lahanpertanian.print();
}

int Petani::getlahankosong() {
    int empty = 0;
    for(int i = 0; i < lahanpertanian.getbaris(); i++) {
        for(int j = 0; j < lahanpertanian.getkolom(); j++) {
            if(lahanpertanian[i][j]->getKode() == "XXX" ) {
                empty += 1;
            }
        }
    }
    return empty;
}

void Petani::tanam() {
    printpenyimpanan();
    string indeksinvent;
    Tanaman* tanaman;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    if (penyimpanan[lokasiinvent[1]][lokasiinvent[0]]->getTipe() == "HERBIVORE") {
        tanaman = dynamic_cast<Tanaman*>(penyimpanan[lokasiinvent[1]][lokasiinvent[0]]);
        cout << "Tumbuhan " << tanaman->getNama() << " diambil" << endl;
        cetaklahan();
        cout <<"Lahan kosong: " << this->getlahankosong() << endl;
        if (getlahankosong() == 0) {
            cout << "Lahan penuh" << endl;
        }
        else {
            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi = parse(idx);
            lahanpertanian[lokasi[1]][lokasi[0]] = tanaman;
            penyimpanan[lokasiinvent[1]][lokasiinvent[0]] = new Carnivore();
        }
    }
    cetaklahan();
}

void Petani::panen() {
    vector<string> listtanamanmatang;
    vector<int> jumlahtanamanmatang;
    // Menghitung tanaman yang siap panen
    for(int i = 0; i < listtanamanmatang.size(); i++) {
        cout << listtanamanmatang[i] << " (" << jumlahtanamanmatang[i] << " buah)" << endl;
    }
}

void Petani::berimakan() {}

int Petani::calculateTax() {
    int uang = this->gulden;
    uang += penyimpanan.getValue();
    uang += lahanpertanian.getValue();
    return uang;
}

// Child Peternak
Peternak::Peternak(string username): Peran(username) {
    peran_pemain = "peternak";
}

void Peternak::cetaklahan() {
    peternakan.print();
}

void Peternak::tanam() {
    printpenyimpanan();
    string indeksinvent;
    Hewan* hewan;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    if (penyimpanan[lokasiinvent[1]][lokasiinvent[0]]->getTipe() == "HERBIVORE") {
        hewan = dynamic_cast<Hewan*>(penyimpanan[lokasiinvent[1]][lokasiinvent[0]]);
        cout << "Hewan " << hewan->getNama() << " diambil" << endl;
        cetaklahan();
        cout <<"Lahan kosong: " << this->getlahankosong() << endl;
        if (getlahankosong() == 0) {
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
    cetaklahan();
}

void Peternak::panen() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Peternak::berimakan() {
    cetaklahan();
    string slot;
    Hewan* hewan;
    cout << "Hewan yang akan diberi makan: ";
    cin >> slot;
    vector<int> index = parse(slot);
    hewan = peternakan[index[1]][index[0]];
    printpenyimpanan();
    Produk* produk;
    cout << "Ambil makanan: ";
    cin >> slot;
    index = parse(slot);
    produk = dynamic_cast<Produk*>(penyimpanan[index[1]][index[0]]);
    hewan->makan(produk);
}

int Peternak::getlahankosong() {
    int empty = 0;
    for(int i = 0; i < peternakan.getbaris(); i++) {
        for(int j = 0; j < peternakan.getkolom(); j++) {
            if(peternakan[i][j]->getKode() == "XXX" ) {
                empty += 1;
            }
        }
    }
    return empty;
}

int Petani::calculateTax() {
    int uang = this->gulden;
    uang += penyimpanan.getValue();
    uang += lahanpertanian.getValue();
    return uang;
}