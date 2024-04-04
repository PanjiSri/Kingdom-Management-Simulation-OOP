#include "Fruit_Plant.hpp"

// Constructor
Fruit_Plant::Fruit_Plant(int _ID) : Plant(_ID) {
    //this->kode = dummy[_ID][];
    //this->nama = dummy[_ID][];
    //this->product_name = this->nama
    for (int i = 0; i < 5; i++) {
        this->product_name.pop_back();
    }
}

// Getter
string Fruit_Plant::get_tipe() {
    return this->tipe;
}

string Fruit_Plant::get_kode() {
    return this->kode;
}

string Fruit_Plant::get_nama() {
    return this->nama;
}

string Fruit_Plant::get_product_name() {
    return this->product_name;
}