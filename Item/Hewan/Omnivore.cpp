#include "Omnivore.hpp"

Omnivore::Omnivore() : Hewan() {}

Omnivore::Omnivore(int _ID, string _kode, string _nama, int _berat, int _harga) : 
    Hewan(_ID, _kode, _nama, _berat, _harga) 
    {}

Omnivore::Omnivore(const Omnivore& other) : 
    Hewan(other) 
    {}

Omnivore::~Omnivore() {}

string Omnivore::getTipe() {
    return tipe;
}

vector<string> Omnivore::getProduk() {
    vector<string> produk;
    produk.push_back(this->nama + "_MEAT");
    produk.push_back(this->nama + "_EGG");
    return produk;
}

void Omnivore::makan(Item* item) {
    if (item->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    } 
    else if (item->getTipe() == "PRODUCT_FRUIT_PLANT" ||
             item->getTipe() == "PRODUCT_ANIMAL") {
        this->berat_saat_ini += item->getTambahan();
    } 
    else {
        throw BukanMakananException();
    }
}