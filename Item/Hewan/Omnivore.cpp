#include "Omnivore.hpp"

Omnivore::Omnivore() : Hewan() {}

Omnivore::Omnivore(int _ID, string code, string name, int berat, int harga) : Hewan(_ID, code, name, berat, harga) {}

Omnivore::Omnivore(const Omnivore& other) : Hewan(other) {}

Omnivore::~Omnivore() {}

string Omnivore::getType() {
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

int Omnivore::getHarga() {
    return this->harga;
}