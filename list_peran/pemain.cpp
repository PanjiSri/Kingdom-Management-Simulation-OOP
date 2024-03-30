#include "header/pemain.hpp"

Pemain::Pemain(string nama_pemain, Peran peran_pemain, int uang, int berat_badan)
{
    this->nama_pemain = nama_pemain;
    this->peran_pemain = peran_pemain;
    this->uang = uang;
    this->berat_badan = berat_badan;
}

Pemain::~Pemain() {}

string Pemain::getNama()
{
    return this->nama_pemain;
}

Peran Pemain::getPeran()
{
    return this->peran_pemain;
}
