#include "Hewan.hpp"

int Hewan::nhewan = 0;

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
    nhewan++;
}

Hewan::Hewan(const Hewan& other) :
    Item(other), 
    standar_berat_panen(other.standar_berat_panen) 
{
    this->berat_saat_ini = other.berat_saat_ini;
    nhewan++;
}

Hewan::~Hewan() {}

int Hewan::getBeratPanen() {
    return standar_berat_panen;
}

int Hewan::getBeratSaatIni() {
    return berat_saat_ini;
}

int Hewan::getJumlahHewan() {
    return nhewan;
}

string Hewan::getKode() {
    return kode;
}

int Hewan::getTambahan() {
    return 0;
}

void Hewan::setBeratSaatIni(int tambahan_berat) {
    berat_saat_ini += tambahan_berat;
}

bool Hewan::isSiapPanen() {
    return berat_saat_ini >= standar_berat_panen;
}