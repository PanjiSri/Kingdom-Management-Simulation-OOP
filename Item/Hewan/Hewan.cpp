#include "Hewan.hpp"

int Hewan::nhewan = 0;

Hewan::Hewan() :
    Item(), 
    standar_berat_panen(0), harga(0) {
    this->berat_saat_ini = 0;
}

Hewan::Hewan(int _ID, string code, string name, int berat, int price) :
    Item(_ID,code,name),
    standar_berat_panen(berat),
    harga(price){
    this->berat_saat_ini = 0;
    nhewan++;
}

Hewan::Hewan(const Hewan& other) :
    Item(other), 
    standar_berat_panen(other.standar_berat_panen), harga(other.harga) {
    this->berat_saat_ini = other.berat_saat_ini;
    nhewan++;
}

Hewan::~Hewan() {}

int Hewan::getBeratPanen() {
    return standar_berat_panen;
}

int Hewan::getHarga() {
    return harga;
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

void Hewan::setBeratSaatIni(int tambahan_berat) {
    berat_saat_ini += tambahan_berat;
}

bool Hewan::isSiapPanen() {
    return berat_saat_ini >= standar_berat_panen;
}

int Hewan::getTambahan() {
    return 0;
}