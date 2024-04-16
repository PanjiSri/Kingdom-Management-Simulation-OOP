#include "header/Konfigurasi_Tanaman.hpp"


Konfigurasi_Tanaman::Konfigurasi_Tanaman() {}


Konfigurasi_Tanaman::Konfigurasi_Tanaman(int _id, string _kode, string _nama, string _tipe, int _duration_to_harvest, int harga) : 
    Konfigurasi_Item(_id, _kode, _nama, harga)
{
    this->duration_to_harvest = _duration_to_harvest;
    this->tipe = _tipe;
}


Konfigurasi_Tanaman::~Konfigurasi_Tanaman() {}


string Konfigurasi_Tanaman::getTipe() {
    return tipe;
}

int Konfigurasi_Tanaman::getDurationToHarvest() {
    return duration_to_harvest;
}
