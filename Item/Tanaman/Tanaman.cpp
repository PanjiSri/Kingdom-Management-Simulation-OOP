#include "Tanaman.hpp"

Tanaman::Tanaman() : 
    Item(), 
    tipe("Tanaman"), waktu_panen(0), harga(0) {
    this->umur = 0;
}

Tanaman::Tanaman(int _ID, string code, string tipe, string name, int panen, int harga) : 
   Item(_ID, code, name), 
   tipe(tipe), waktu_panen(panen), harga(harga) {
    this->umur = 0;
}

Tanaman::Tanaman(const Tanaman& other) :
    Item(other), 
    tipe(other.tipe), waktu_panen(other.waktu_panen), harga(other.harga) {
    this->umur = other.umur;
}

Tanaman::~Tanaman() {}

string Tanaman::getTipe() {
    return tipe;
}

int Tanaman::getWaktuPanen() {
    return waktu_panen;
}

int Tanaman::getUmur() {
    return umur;
}

int Tanaman::getHarga() {
    return harga;
}

void Tanaman::tambahUmur() {
    umur++;
}

bool Tanaman::isSiapPanen() {
    return umur >= waktu_panen;
}