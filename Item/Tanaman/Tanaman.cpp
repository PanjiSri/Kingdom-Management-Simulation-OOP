#include "Tanaman.hpp"

Tanaman::Tanaman() : 
    Item(), 
    tipe("Tanaman"), 
    waktu_panen(0)
{
    this->umur = 0;
}

Tanaman::Tanaman(int _ID, string _kode, string _tipe, string _nama, int _waktu_panen, int _harga) : 
    Item(_ID, _kode, _nama, _harga), 
    tipe(_tipe), 
    waktu_panen(_waktu_panen) 
{
    this->umur = 0;
}

Tanaman::Tanaman(const Tanaman& other) :
    Item(other), 
    tipe(other.tipe), 
    waktu_panen(other.waktu_panen)
{
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

int Tanaman::getTambahan() {
    return 0;
}

void Tanaman::tambahUmur() {
    umur++;
}

void Tanaman::setUmur(int num) {
    umur = num;
}

bool Tanaman::isSiapPanen() {
    return umur >= waktu_panen;
}
