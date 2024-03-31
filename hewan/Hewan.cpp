#include "Hewan.hpp"

Hewan::Hewan(string kode, string nama, int berat_panen, int harga){
    this->id = nhewan;
    this->kode = kode;
    this->nama = nama;
    this->standar_berat_panen = berat_panen;
    this->berat_saat_ini = 0;
    this->harga = harga;
    nhewan++;
}

Hewan::~Hewan(){
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

void Hewan::setberat_saat_ini(int added_weight){
    berat_saat_ini = berat_saat_ini + added_weight;
}