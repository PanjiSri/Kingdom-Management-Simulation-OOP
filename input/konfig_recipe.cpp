#include "header/konfig_recipe.hpp"


Konfigurasi_Recipe::Konfigurasi_Recipe() {}

Konfigurasi_Recipe::Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, map<string, int> bahan_baku) {
    this->id = _id;
    this->kode = _kode;
    this->nama = _nama;
    this->harga = harga;
    this->bahan_baku = bahan_baku;
}

Konfigurasi_Recipe::~Konfigurasi_Recipe() {}

map<string, int> Konfigurasi_Recipe::getBahanBaku() {
    return this->bahan_baku;
}