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

vector<string> Tanaman::getProduk() {
    string produk = this->nama;
    produk.erase(produk.length() - 5);

    vector<string> vec_produk;
    if (this->tipe == "MATERIAL_PLANT") {
        vec_produk.push_back(produk + "_WOOD");
    } else {
        vec_produk.push_back(produk);
    }

    return vec_produk;
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

map<string, int> Tanaman::getMaterial() {}