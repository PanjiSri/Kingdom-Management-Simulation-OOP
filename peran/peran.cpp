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
    penyimpanan.print();
}

Peran& Peran::operator=(const Peran& other) {
    gulden = other.gulden;
    berat = other.berat;
    penyimpanan = other.penyimpanan;
    username = other.username;
    return *this;
}

void Peran::addpenyimpanan(string benda, vector<Produk*> listhewan) {
    Hewan* x;
    printpenyimpanan();
    string idx;
    cout << "Masukkan lokasi yang diinginkan: ";
    cin >> idx;
    vector<int> lokasi = parse(idx);
    cout << lokasi[1] << endl;
    cout << lokasi[0] << endl;
    penyimpanan[lokasi[1]][lokasi[0]] = x;
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
        guldenpajak += (int)(listpemain[i]->getgulden())*0.1;
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
            if(lahanpertanian[i][j]->getKode() == "   " ) {
                empty += 1;
            }
        }
    }
    return empty;
}

void Petani::tanam() {
    printpenyimpanan();
    string indeksinvent;
    Hewan* tumbuhan;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    // tumbuhan = penyimpanan[lokasiinvent[1]][lokasiinvent[0]];
    cout << "Tumbuhan " << tumbuhan->getNama() << " diambil" << endl;
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
        lahanpertanian[lokasi[1]][lokasi[0]] = tumbuhan;
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

// Child Peternak
Peternak::Peternak(string username): Peran(username) {
    peran_pemain = "peternak";
}

void Peternak::cetaklahan() {
    peternakan.print();
}

void Peternak::tanam() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Peternak::panen() {
    cout << "Hanya bisa dilakukan petani" << endl;
}

void Peternak::berimakan() {
    cetaklahan();
    string slot;
    Item* hewan;
    cout << "Hewan yang akan diberi makan: ";
    cin >> slot;
    vector<int> index = parse(slot);
    hewan = peternakan[index[1]][index[0]];
    printpenyimpanan();
    Produk* produk;
    cout << "Ambil makanan: ";
    cin >> slot;
    // hewan->makan(produk);
}

int Peternak::getlahankosong() {
    cout << "Hanya bisa dilakukan petani" << endl;
    return -1;
}

