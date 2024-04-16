#include "header/Konfigurasi_Item.hpp"


Konfigurasi_Item::Konfigurasi_Item() {}

Konfigurasi_Item::Konfigurasi_Item(int _id, string _kode, string _nama, int _harga) {
    id = _id;
    kode = _kode;
    nama = _nama;
    harga = _harga;
}

Konfigurasi_Item::~Konfigurasi_Item() {}

int Konfigurasi_Item::getId() {
    return id;
}

int Konfigurasi_Item::getHarga() {
    return harga;
}

string Konfigurasi_Item::getKode() {
    return kode;
}

string Konfigurasi_Item::getName() {     
    return nama;
}