#include "header/konfig_produk.hpp"


Konfigurasi_Produk::Konfigurasi_Produk() {}

Konfigurasi_Produk::Konfigurasi_Produk(int _id, string _kode, string _nama, string _tipe, string origin, int _berat_tambahan, int _harga) : Konfigurasi_Item(_id, _kode, _nama, _harga) {
    this->tipe = _tipe;
    this->origin = origin;
    this->berat_tambahan = _berat_tambahan;
}

Konfigurasi_Produk::~Konfigurasi_Produk() {}

string Konfigurasi_Produk::getTipe() {
    return this->tipe;  
}

string Konfigurasi_Produk::getOrigin() {
    return this->origin;
}

int Konfigurasi_Produk::getBeratTambahan() {
    return this->berat_tambahan;
}

