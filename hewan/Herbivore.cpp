#include "Herbivore.hpp"

Herbivore::Herbivore(string kode, string nama, int berat, int harga) : Hewan(kode, nama, berat, harga){
}

Herbivore::~Herbivore(){
}

void Herbivore::makan(Produk produk) {
    if (produk.get_tipe() == "PRODUCT_ANIMAL") {
        throw CarnivoraTidakMakanSayurException();
    } else if(produk.get_tipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setberat_saat_ini(produk.get_tambahan_berat());
    }
}

string Herbivore::getType(){
    return "HERBIVORE";
}
string Herbivore::getKode(){
    return Hewan::getKode();
}
string Herbivore::getNama(){
    return Hewan::getNama();
}
int Herbivore::getBeratPanen(){
    return Hewan::getBeratPanen();
}
int Herbivore::getHarga(){
    return Hewan::getHarga();
}
int Herbivore::getberat_saat_ini(){
    return Hewan::getberat_saat_ini();
}
bool Herbivore::isSiapPanen(){
    return Hewan::isSiapPanen();
}