#include "Herbivore.hpp"

Herbivore::Herbivore() : Hewan() {}

Herbivore::Herbivore(int _ID) : Hewan(_ID) {}

Herbivore::Herbivore(const Herbivore& other) : Hewan(other) {}

Herbivore::~Herbivore() {}

string Herbivore::getTipe() {
    return tipe;
}

void Herbivore::makan(Produk* produk) {
    if (produk->getTipe() == "PRODUCT_ANIMAL") {
        throw HerbivoraTidakMakanDagingException();
    } else if(produk->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setBeratSaatIni(produk->getTambahanBerat());
    }
}