#include "Omnivore.hpp"

Omnivore::Omnivore(): Hewan() {

}

Omnivore::Omnivore(string kode, string nama, int berat, int harga) : Hewan(kode, nama, berat, harga){
}

Omnivore::~Omnivore(){}

void Omnivore::makan(Produk* produk) {
    if(produk->get_tipe() == "PRODUCT_MATERIAL_PLANT") {
        throw MaterialPlantTidakDimakanException();
    }
    else {
        setberat_saat_ini(produk->get_tambahan_berat());
    }
}

string Omnivore::getType(){
    return "OMNIVORE";
}
string Omnivore::getKode(){
    return Hewan::getKode();
}
string Omnivore::getNama(){
    return Hewan::getNama();
}
int Omnivore::getBeratPanen(){
    return Hewan::getBeratPanen();
}
int Omnivore::getHarga(){
    return Hewan::getHarga();
}
int Omnivore::getberat_saat_ini(){
    return Hewan::getberat_saat_ini();
}
bool Omnivore::isSiapPanen(){
    return Hewan::isSiapPanen();
}
