#include "Herbivore.hpp"
#include <iostream>
using namespace std;

Herbivore::Herbivore() : Hewan() {}

Herbivore::Herbivore(int _ID, string _kode, string _nama, int _berat, int _harga) : 
    Hewan(_ID, _kode, _nama, _berat, _harga) 
    {}

Herbivore::Herbivore(const Herbivore& other) : 
    Hewan(other) 
    {}

Herbivore::~Herbivore() {}

string Herbivore::getTipe() {
    return tipe;
}

vector<string> Herbivore::getProduk() {
    vector<string> produk;
    produk.push_back(this->nama + "_MEAT");
    return produk;
}

void Herbivore::makan(Item* item) {
    if (item->getTipe() == "PRODUCT_ANIMAL") {
        throw HerbivoraTidakMakanDagingException();
    } else if(item->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    } else if (item->getTipe() == "PRODUCT_FRUIT_PLANT") {
        this->berat_saat_ini += item->getTambahan();
    } else {
        throw BukanMakananException();
    }
}