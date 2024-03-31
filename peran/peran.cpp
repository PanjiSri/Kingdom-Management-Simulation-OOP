#include "peran.hpp"
#include "vector"
#include <iostream>
using namespace std;

// Parent Peran

Peran::Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
    for(int i = 0; i < 10; i++) {
        vector<string> rowpenyimpanan;
        for(int j = 0; j < 10; j++) {
            rowpenyimpanan.push_back("   ");
        }
        penyimpanan.push_back(rowpenyimpanan);
    }
} 

Peran::Peran(string username) {
    this->username = username;
    gulden = 50;
    berat = 40;
    for(int i = 0; i < 10; i++) {
        vector<string> rowpenyimpanan;
        for(int j = 0; j < 10; j++) {
            rowpenyimpanan.push_back("   ");
        }
        penyimpanan.push_back(rowpenyimpanan);
    }
}

Peran::Peran(int gulden, int berat, string username) {
    this->username = username;
    this->gulden = gulden;
    this->berat = berat;
    for(int i = 0; i < 10; i++) {
        vector<string> rowpenyimpanan;
        for(int j = 0; j < 10; j++) {
            rowpenyimpanan.push_back("   ");
        }
        penyimpanan.push_back(rowpenyimpanan);
    }
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

void Peran::printpenyimpanan() {
    int asciinum = 65;
    cout << "   ";
    for(int i = 0; i < 10; i++) {
        cout << "  " << (char)(i+asciinum) << "  ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        if(i < 9) {
            cout << "0" << i+1 << " ";
        }
        else {
            cout << i+1 << " ";
        }
        for(int j = 0; j < 10; j++) {
            cout << " " << penyimpanan[i][j] << " ";
        }
        cout << endl;
    }
}

Peran& Peran::operator=(const Peran& other) {
    gulden = other.gulden;
    berat = other.berat;
    penyimpanan = other.penyimpanan;
    username = other.username;
    return *this;
}

void Peran::addpenyimpanan(string benda) {
    printpenyimpanan();
    string idx;
    cout << "Masukkan lokasi yang diinginkan: ";
    cin >> idx;
    vector<int> lokasi = parse(idx);
    cout << lokasi[1] << endl;
    cout << lokasi[0] << endl;
    penyimpanan[lokasi[1]][lokasi[0]] = benda;
}

// Child Petani

Petani::Petani(string username): Peran(username) {
    peran_pemain = "petani";
    for(int i = 0; i < 8; i++) {
        vector<string> rowlahan;
        for(int j = 0; j < 8; j++) {
            rowlahan.push_back("   ");
        }
        lahanpertanian.push_back(rowlahan);
    }
}

Petani::Petani(): Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
    for(int i = 0; i < 10; i++) {
        vector<string> rowpenyimpanan;
        for(int j = 0; j < 10; j++) {
            rowpenyimpanan.push_back("   ");
        }
        penyimpanan.push_back(rowpenyimpanan);
    }
} 

Petani::Petani(int gulden, int berat, string username): Peran(gulden, berat, username) {
    for(int i = 0; i < 8; i++) {
        vector<string> rowlahan;
        for(int j = 0; j < 8; j++) {
            rowlahan.push_back("   ");
        }
        lahanpertanian.push_back(rowlahan);
    }
}

void Petani::cetaklahan() {
    int asciinum = 65;
    cout << "_____________________LADANG___________________" << endl;
    cout << "   ";
    for(int i = 0; i < 8; i++) {
        cout << "  " << (char)(i+asciinum) << "  ";
    }
    cout << endl;
    for(int i = 0; i < 8; i++) {
        if(i < 9) {
            cout << "0" << i+1 << " ";
        }
        else {
            cout << i+1 << " ";
        }
        for(int j = 0; j < 8; j++) {
            cout << " "<< lahanpertanian[i][j] << " ";
        }
        cout << endl;
    }
}

int Petani::getlahankosong() {
    int lahankosong = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (lahanpertanian[i][j] == "   ") {
                lahankosong += 1;
            }
        }
    }
    return lahankosong;
}

void Petani::tanam() {
    printpenyimpanan();
    string indeksinvent, tumbuhan;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    tumbuhan = penyimpanan[lokasiinvent[1]][lokasiinvent[0]];
    cout << "Tumbuhan " << tumbuhan << " diambil" << endl;
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