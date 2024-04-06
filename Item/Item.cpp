#include "Item.hpp"

Item::Item() :
    ID(0), kode("XXX"), nama("XXX") {}

// Item::Item(int _ID) 
//    : ID(_ID) , kode(dummy[_ID][1]), nama(dummy[_ID][2]) {}

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