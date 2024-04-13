#include "Omnivore.hpp"

Omnivore::Omnivore() : Hewan() {}

Omnivore::Omnivore(int _ID, string _kode, string _nama, int _berat, int _harga) : 
    Hewan(_ID, _kode, _nama, _berat, _harga) 
    {}

Omnivore::Omnivore(const Omnivore& other) : 
    Hewan(other) 
    {}

Omnivore::~Omnivore() {}

string Omnivore::getTipe() {
    return tipe;
}

void Omnivore::makan(Produk* produk) {
    if(produk->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setBeratSaatIni(produk->getTambahan());
    }
}