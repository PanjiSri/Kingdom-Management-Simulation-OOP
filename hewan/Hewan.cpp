#include "Hewan.hpp"

int Hewan::nhewan = 0;

Hewan::Hewan() {
    kode = "BOM";
    nama = "   ";
    standar_berat_panen = 0;
    berat_saat_ini = 0;
    harga = 0;
    nhewan += 0;
}

Hewan::Hewan(string kode, string nama, int berat_panen, int harga){
    this->kode = kode;
    this->nama = nama;
    this->standar_berat_panen = berat_panen;
    this->berat_saat_ini = 0;
    this->harga = harga;
    nhewan++;
}

Hewan::~Hewan(){
}

Hewan& Hewan::operator=(Hewan& other) {
    this->kode = other.kode;
    this->nama = other.nama;
    this->standar_berat_panen = other.standar_berat_panen;
    this->berat_saat_ini = other.berat_saat_ini;
    this->harga = other.harga;
    return *this;
}

string Hewan::getKode(){
    return kode;
}
string Hewan::getNama(){
    return nama;
}

int Hewan::getBeratPanen(){
    return standar_berat_panen;
}

int Hewan::getHarga(){
    return harga;
}

int Hewan::getberat_saat_ini(){
    return berat_saat_ini;
}

void Hewan::setberat_saat_ini(int tambahan_berat){
    berat_saat_ini = berat_saat_ini + tambahan_berat;
}

int Hewan::getJumlahHewan(){
    return nhewan;
}

bool Hewan::isSiapPanen(){
    return berat_saat_ini == standar_berat_panen;
}