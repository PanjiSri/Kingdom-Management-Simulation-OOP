#include "Herbivore.hpp"
#include <iostream>
using namespace std;

Herbivore::Herbivore() : Hewan() {}

Herbivore::Herbivore(int _ID, string _kode, string _nama, int _berat, int _harga) : 
    Hewan(_ID, _kode, _nama, _berat, _harga) 
    {}

Herbivore::Herbivore(const Herbivore& other) : 
    Hewan(other) 
    {}

Herbivore::~Herbivore() {}

string Herbivore::getTipe() {
    return tipe;
}

bool Herbivore::makan(Produk* produk) {
    if (produk->getTipe() == "PRODUCT_ANIMAL") {
        cout << "Herbivora tidak makan tumbuhan" << endl;
        return false;
    }
    else {
        setBeratSaatIni(produk->getTambahan());
        return true;
    }
}