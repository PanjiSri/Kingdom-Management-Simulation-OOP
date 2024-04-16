#include "Peran.hpp"
#include <iostream>
#include <ostream>
#include "vector"
#include "../penyimpanan/MatriksPenyimpanan.hpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "Peternak.hpp"
#include "Petani.hpp"
#include "Walikota.hpp"
#include <string>
#include "../Pcolor/pcolor.h"
using namespace std;

// compile
// g++ -o main main.cpp peran.cpp ../Item/Hewan/Carnivore.cpp ../Item/Hewan/Omnivore.cpp ../Item/Hewan/Herbivore.cpp ../Item/Hewan/Hewan.cpp ../Item/Item.cpp ../Item/Produk/Produk.cpp ../Item/Tanaman/Tanaman.cpp ../Item/Bangunan/Bangunan.cpp
// g++ -o a peran/main.cpp Item/Bangunan/Bangunan.cpp peran/Peternak.cpp peran/Petani.cpp peran/Walikota.cpp peran/peran.cpp Item/Hewan/Omnivore.cpp Item/Hewan/Carnivore.cpp Item/Hewan/Hewan.cpp Item/Hewan/Herbivore.cpp Item/Tanaman/Tanaman.cpp Item/Item.cpp Item/Produk/Produk.cpp Pcolor/pcolor.c Toko/toko.cpp

int main() {
    string name, code, tipe, harga, berat, id, origin;
    int beratint, hargaint;
    vector<Tanaman*> listtanaman;
    vector<Hewan*> listhewan;
    vector<Item*> listitem;
    vector<Produk*> listproduct;
    vector<vector<string>> parse;
    string datahewan;
    string datatanaman;

    bool end = false;
    for(int i = 0; i < 7; i++) {
        int step = 0;
        string data;
        getline(cin,datahewan);
        for(int j = 0; j < datahewan.size(); j++) {
            if(datahewan[j] == ' ' || datahewan == "\n") {
                if(step == 0) {
                    id = data;
                    data = "";
                }
                else if(step == 1) {
                    code = data;
                    data = "";
                }
                else if(step == 2) {
                    name = data;
                    data = "";
                }
                else if(step == 3) {
                    tipe = data;
                    data = "";
                }
                else if(step == 4) {
                    berat = data;
                    data = "";
                }
                step += 1;   
            }
            else {
                data += datahewan[j];
            }
        }
        harga = data;
        if (tipe == "CARNIVORE") {
            Hewan* x = new Carnivore(stoi(id),code,name,stoi(berat), stoi(harga));
            listhewan.push_back(x);
            listitem.push_back(x);
        }
        else if (tipe == "OMNIVORE") {
            Hewan* x = new Omnivore(stoi(id), code, name, stoi(berat), stoi(harga));
            listhewan.push_back(x);
            listitem.push_back(x);

        }
        else if(tipe == "HERBIVORE"){
            Hewan* x = new Herbivore(stoi(id), code, name, stoi(berat), stoi(harga));
            listhewan.push_back(x);
            listitem.push_back(x);

        }
    }

    for(int i = 0; i < 8; i++) {
        int step = 0;
        string data;
        getline(cin,datatanaman);
        for(int j = 0; j < datatanaman.size(); j++) {
            if(datatanaman[j] == ' ' || datatanaman == "\n") {
                if(step == 0) {
                    id = data;
                    data = "";
                }
                else if(step == 1) {
                    code = data;
                    data = "";
                }
                else if(step == 2) {
                    name = data;
                    data = "";
                }
                else if(step == 3) {
                    tipe = data;
                    data = "";
                }
                else if(step == 4) {
                    berat = data;
                    data = "";
                }
                step += 1;   
            }
            else {
                data += datatanaman[j];
            }
        }
        harga = data;
        Tanaman* y = new Tanaman(stoi(id),code,name, tipe, stoi(berat), stoi(harga));
        listtanaman.push_back(y);
        listitem.push_back(y);
    }

    for(int i = 0; i < 17; i++) {
        int step = 0;
        string data;
        getline(cin,datahewan);
        for(int j = 0; j < datahewan.size(); j++) {
            if(datahewan[j] == ' ' || datahewan == "\n") {
                if(step == 0) {
                    id = data;
                    data = "";
                }
                else if(step == 1) {
                    code = data;
                    data = "";
                }
                else if(step == 2) {
                    name = data;
                    data = "";
                }
                else if(step == 3) {
                    tipe = data;
                    data = "";
                }
                else if(step == 4) {
                    origin = data;
                    data = "";
                }
                else if(step == 5) {
                    berat = data;
                    data = "";
                }
                step += 1;   
            }
            else {
                data += datahewan[j];
            }
        }
        harga = data;
        Produk* z = new Produk(stoi(id),code,name,tipe,origin, stoi(berat), stoi(harga));
        listproduct.push_back(z);
        listitem.push_back(z);
    }

    vector<Peran*> listpemain;
    // Toko* store = new Toko();
    Peran* a = new Peternak("haikal", 100, 100, 8, 8, 8, 8);
    listpemain.push_back(a);  
    Item* COM = new Produk(1, "COM", "COW_MEAT", "PRODUCT_ANIMAL", "COW", 7, 10);
    Item* SAW = new Produk(2, "SAW", "SANDALWOOD_WOOD", "PRODUCT_MATERIAL_PLANT", "SANDALWOOD_TREE", 0, 8);
    Item* BNP = new Produk(7, "BNP", "BANANA", "PRODUCT_FRUIT_PLANT", "BANANA_TREE", 3, 7);

    a->addPenyimpananSpesifikLocation(COM);
    a->addPenyimpananSpesifikLocation(COM);
    a->addPenyimpananSpesifikLocation(SAW);
    // a->menjual(store);
    // a->addPenyimpananSpesifikLocation(BNP);
    Item* snake = new Carnivore(1, "SNK", "SNAKE", 13, 4);
    
    a->addPenyimpananSpesifikLocation(snake);
    a->beternakBertani();
    a->beriMakan();
    a->beriMakan();
    
    // try {
    //     cout << "MASUK SINI GAK";
    //     a->beriMakan();
    //     cout << "MASUK SINI GAK";
    // } catch (CarnivoraTidakMakanSayurException e) {
    //     cout << e.what() << endl;        
    // }

    // try {
    //     a->beriMakan();
    // } catch (MaterialPlantTidakDimakanException e) {
    //     cout << e.what() << endl;        
    // }

    a->panen(listproduct);
    a->printPenyimpanan();

    Peran* b = new Petani("budi", 100, 100, 8, 8, 8, 8);
    listpemain.push_back(b);
    Item* apel = new Tanaman(5, "APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4);
    Item *aloe = new Tanaman(3, "ALT", "ALOE_TREE", "MATERIAL_PLANT", 9, 6);
    b->addPenyimpananSpesifikLocation(apel);
    b->addPenyimpananSpesifikLocation(aloe);
    b->beternakBertani();
    b->beternakBertani();
    b->panen(listproduct);

    for (int i = 0; i < 10; i++) {
        b->addUmurTanaman();
    }
    b->panen(listproduct);
    for (int i = 0; i < 5; i++) {
        b->addUmurTanaman();
    }
    b->panen(listproduct);

    Peran* d = new Peternak("Ijat", 108, 108, 8, 8, 8, 8);
    listpemain.push_back(d);
    // a->cetakLahan();
    // b->cetakLahan();

    // a->printPenyimpanan();
    // b->printPenyimpanan();

    Peran* c = new Walikota("caca", 100, 100, 8, 8);
    listpemain.push_back(c);
    cout << "Kekayaan a: " << a->getKekayaan() << endl;
    cout << "Kekayaan b: " << b->getKekayaan() << endl;
    cout << "Kekayaan c: " << c->getKekayaan() << endl;
    cout << "Pajak a: " << a->calculateTax() << endl;
    cout << "Pajak b: " << b->calculateTax() << endl;
    cout << "Pajak c: " << c->calculateTax() << endl;
    c->ambilPajak(listpemain);
    cout << "Kekayaan a: " << a->getKekayaan() << endl;
    cout << "Kekayaan b: " << b->getKekayaan() << endl;
    cout << "Kekayaan c: " << c->getKekayaan() << endl;


    return 0;
};