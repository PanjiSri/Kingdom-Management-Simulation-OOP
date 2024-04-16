#include "Hewan.hpp"

Hewan::Hewan() :
    Item(), 
    standar_berat_panen(0)
{
    this->berat_saat_ini = 0;
}

Hewan::Hewan(int _ID, string _kode, string _nama, int _berat_panen, int _harga) :
    Item(_ID, _kode, _nama, _harga),
    standar_berat_panen(_berat_panen)
{
    this->berat_saat_ini = 0;
}

Hewan::Hewan(const Hewan& other) :
    Item(other), 
    standar_berat_panen(other.standar_berat_panen) 
{
    this->berat_saat_ini = other.berat_saat_ini;
}

Hewan::~Hewan() {}

int Hewan::getBeratPanen() {
    return standar_berat_panen;
}

int Hewan::getBeratSaatIni() {
    return berat_saat_ini;
}

int Hewan::getTambahan() {
    return 0;
}

void Hewan::tambahBerat(int tambahan_berat) {
    berat_saat_ini += tambahan_berat;
}

void Hewan::setBerat(int num) {
    berat_saat_ini = num;
}

bool Hewan::isSiapPanen() {
    return berat_saat_ini >= standar_berat_panen;
}
