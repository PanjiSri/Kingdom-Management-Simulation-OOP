#include "Item.hpp"
#include "Tanaman/Tanaman.hpp"

Item::Item() :
    ID(0), kode("XXX"), nama("XXX") {}

Item::Item(int _ID, string code, string name) 
   : ID(_ID) , kode(code), nama(name) {}

Item::Item(const Item& other) 
    : ID(other.ID) , kode(other.kode), nama(other.nama) {}

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
