#include "Omnivore.hpp"

Omnivore::Omnivore() : Hewan() {}

Omnivore::Omnivore(int _ID) : Hewan(_ID) {}

Omnivore::Omnivore(const Omnivore& other) : Hewan(other) {}

Omnivore::~Omnivore() {}

string Omnivore::getTipe() {
    return tipe;
}

void Omnivore::makan(Produk* produk) {
    if(produk->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setBeratSaatIni(produk->getTambahanBerat());
    }
}