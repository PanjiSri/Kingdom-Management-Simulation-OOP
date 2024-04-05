#include "Carnivore.hpp"

Carnivore::Carnivore(): Hewan() { 
}

Carnivore::Carnivore(string kode, string nama, int berat, int harga) : Hewan(kode, nama, berat, harga){
}

Carnivore::~Carnivore(){
}

void Carnivore::makan(Produk produk) {
    if (produk.get_tipe() == "PRODUCT_FRUIT_PLANT") {
        throw CarnivoraTidakMakanSayurException();
    } else if(produk.get_tipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setberat_saat_ini(produk.get_tambahan_berat());
    }
}

string Carnivore::getType(){
    return "CARNIVORE";
}
string Carnivore::getKode(){
    return Hewan::getKode();
}
string Carnivore::getNama(){
    return Hewan::getNama();
}
int Carnivore::getBeratPanen(){
    return Hewan::getBeratPanen();
}
int Carnivore::getHarga(){
    return Hewan::getHarga();
}
int Carnivore::getberat_saat_ini(){
    return Hewan::getberat_saat_ini();
}
bool Carnivore::isSiapPanen(){
    return Hewan::isSiapPanen();
}