#include "Produk.hpp"

Produk::Produk() :
    Item(),
    tipe("XXX"), asal("XXX"), tambahan_berat(0), harga(0) {}

// Produk::Produk(int _ID) : 
//    Item(_ID),
//    tipe(dummy[_ID][3]), asal(dummy[_ID][4]), tambahan_berat(dummy[_ID][5]), harga(dummy[_ID][6]) {}

Produk::Produk(const Produk &other) :
        Item(other),
        tipe(other.tipe), asal(other.asal), tambahan_berat(other.tambahan_berat), harga(other.harga) {}

Produk::~Produk() {}

string Produk::getTipe() {
    return tipe;
}

string Produk::getAsal() {
    return asal;
}

int Produk::getTambahanBerat() {
    return tambahan_berat;
}

int Produk::getHarga() {
    return harga;
}