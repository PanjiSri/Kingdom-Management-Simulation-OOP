#include "Produk.hpp"

Produk::Produk() :
    Item(),
    tipe("XXX"),
    asal("XXX"),
    tambahan_berat(0)
    {}

Produk::Produk(int _ID, string _kode, string _name, string _tipe, string _asal, int _tambahan, int _harga) : 
    Item(_ID, _kode, _name, _harga),
    tipe(_tipe), asal(_asal), 
    tambahan_berat(_tambahan)
    {}

Produk::Produk(const Produk &other) :
    Item(other),
    tipe(other.tipe), 
    asal(other.asal), 
    tambahan_berat(other.tambahan_berat)
    {}

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