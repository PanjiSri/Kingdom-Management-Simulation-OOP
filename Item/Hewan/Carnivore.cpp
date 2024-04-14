#include "Carnivore.hpp"

Carnivore::Carnivore() : Hewan() {}

Carnivore::Carnivore(int _ID, string _kode, string _nama, int _berat, int _harga) : 
    Hewan(_ID, _kode, _nama, _berat, _harga) 
    {}


Carnivore::Carnivore(const Carnivore& other) : 
    Hewan(other) 
    {}

Carnivore::~Carnivore() {}

string Carnivore::getTipe() {
    return tipe;
}

vector<string> Carnivore::getProduk() {
    vector<string> produk;
    produk.push_back(this->nama + "_MEAT");
    return produk;
}

bool Carnivore::makan(Produk* produk) {
    if (produk->getTipe() == "PRODUCT_FRUIT_PLANT") {
        throw CarnivoraTidakMakanSayurException();
    } else if(produk->getTipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        cout << "Berat hewan bertambah sebanyak " << produk->getTambahan() << endl;
        return true;
    }
}