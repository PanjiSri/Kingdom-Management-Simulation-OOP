#include "header/list_pemain.hpp"


ListPemain::ListPemain(){
    banyak_pemain = 0;
}

ListPemain::ListPemain(const ListPemain& other){
    banyak_pemain = other.banyak_pemain;
    for(int i = 0; i < this->banyak_pemain; i++){
        list_of_pemain[i] = other.list_of_pemain[i];    
    }
}

ListPemain::~ListPemain(){}


void ListPemain::tambah_pemain(Peran pemain){
    banyak_pemain += 1;
    list_of_pemain.push_back(pemain);
}

Peran ListPemain::get_pemain(int index){
    return list_of_pemain[index];
}
