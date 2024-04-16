#include "header/Konfigurasi_Animal.hpp"


Konfigurasi_Animal::Konfigurasi_Animal() {}


Konfigurasi_Animal::Konfigurasi_Animal(int _id, string _kode, string _nama, string _tipe, int _weight_to_harvest, int _harga) : 
    Konfigurasi_Item(_id, _kode, _nama, _harga) 
{
    this->weight_to_harvest = _weight_to_harvest;
    this->tipe = _tipe;
}


Konfigurasi_Animal::~Konfigurasi_Animal() {}


string Konfigurasi_Animal::getTipe() {
    return tipe;
}

int Konfigurasi_Animal::getWeightToHarvest() {
    return weight_to_harvest;
}
