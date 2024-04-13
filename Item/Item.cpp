#include "Item.hpp"
#include "Tanaman/Tanaman.hpp"

Item::Item() :
    ID(0), 
    kode("   "), 
    nama("   "), 
    harga(0)
    {}

Item::Item(int _ID, string _kode, string _nama, int _harga) : 
    ID(_ID), 
    kode(_kode), 
    nama(_nama),
    harga(_harga)
    {}

Item::Item(const Item& other) : 
    ID(other.ID), 
    kode(other.kode), 
    nama(other.nama),
    harga(other.harga)
    {}

Item::~Item() {}

int Item::getID() {
    return ID;
}

string Item::getKode() {
    return kode;
}

string Item::getNama() {
    return nama;
}

int Item::getHarga() {
    return harga;
}