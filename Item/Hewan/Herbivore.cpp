#include "Herbivore.hpp"

Herbivore::Herbivore() : Hewan() {}

Herbivore::Herbivore(int _ID, string code, string name, int berat, int harga) : Hewan(_ID, code, name, berat, harga) {}

Herbivore::Herbivore(const Herbivore& other) : Hewan(other) {}

Herbivore::~Herbivore() {}

string Herbivore::getType() {
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

int Herbivore::getHarga() {
    return harga;
}