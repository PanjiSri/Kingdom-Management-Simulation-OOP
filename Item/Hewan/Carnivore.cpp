#include "Carnivore.hpp"

Carnivore::Carnivore() : Hewan() {}

Carnivore::Carnivore(int _ID, string code, string name, int berat, int harga) : Hewan(_ID, code, name, berat, harga) {}


Carnivore::Carnivore(const Carnivore& other) : Hewan(other) {}

Carnivore::~Carnivore() {}

string Carnivore::getType() {
    return tipe;
}

void Carnivore::makan(Produk* produk) {
    if (produk->getTipe() == "PRODUCT_FRUIT_PLANT") {
        throw CarnivoraTidakMakanSayurException();
    } else if(produk->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setBeratSaatIni(produk->getTambahanBerat());
    }
}

int Carnivore::getHarga() {
    return harga;
}