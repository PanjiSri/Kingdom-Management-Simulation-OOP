#include "header/pemain.hpp"

Pemain::Pemain(){}

Pemain::Pemain(string nama_pemain, Peran peran_pemain){
    this->nama_pemain = nama_pemain;
    this->peran_pemain = peran_pemain;
}

Pemain::~Pemain(){}

string Pemain::getNama(){
    return this->nama_pemain;
}

Peran Pemain::getPeran(){
    return this->peran_pemain;
}