#include "Hewan.hpp"

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