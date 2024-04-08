#include "Produk.hpp"

Produk::Produk() :
    Item(),
    tipe("XXX"), asal("XXX"), tambahan_berat(0), harga(0) {}

Produk::Produk(int _ID, string code, string name, string type, string origin, int tambahan, int harga) : 
   Item(_ID, code, name),
   tipe(type), asal(origin), tambahan_berat(tambahan), harga(harga) {}

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

int Produk::getTambahan() {
    return tambahan_berat;
}

int Produk::getHarga() {
    return harga;
}