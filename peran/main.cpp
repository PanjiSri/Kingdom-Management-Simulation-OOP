#include "peran.hpp"
#include <iostream>
#include <ostream>
#include "vector"
#include "MatriksPenyimpanan.hpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include <string>
using namespace std;

// compile
// g++ -o main main.cpp peran.cpp ../Item/Hewan/Carnivore.cpp ../Item/Hewan/Omnivore.cpp ../Item/Hewan/Herbivore.cpp ../Item/Hewan/Hewan.cpp ../Item/Item.cpp ../Item/Produk/Produk.cpp ../Item/Tanaman/Tanaman.cpp ../Item/Bangunan/Bangunan.cpp

int main() {
    static int nhewan = 0;
    string name, code, tipe, harga, berat, id, origin;
    int beratint, hargaint;
    vector<Hewan*> listhewan;
    vector<Item*> listitem;
    vector<vector<string>> parse;
    string datahewan;
    bool end = false;
    for(int i = 0; i < 7; i++) {
        int step = 0;
        string data;
        getline(cin,datahewan);
        for(int j = 0; j < datahewan.size(); j++) {
            if(datahewan[j] == ' ' or datahewan == "\n") {
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
                    harga = data;
                    data = "";
                }
                step += 1;   
            }
            else {
                data += datahewan[j];
            }
        }
        berat = data;
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

    for(int i = 0; i < 17; i++) {
        int step = 0;
        string data;
        getline(cin,datahewan);
        for(int j = 0; j < datahewan.size(); j++) {
            if(datahewan[j] == ' ' or datahewan == "\n") {
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
        Item* x = new Produk(stoi(id),code,name,tipe,origin, stoi(berat), stoi(harga));
        listitem.push_back(x);
    }

    vector<Peran*> listpemain;
    Peran* a = new Peternak("haikal");
    cout <<  a->getberat() << endl;
    cout << "Test1" << endl;
    a->cetaklahan();
    a->addpenyimpanan("COW", listitem);
    a->addpenyimpanan("COM", listitem);
    a->tanam();
    a->berimakan();
    a->printpenyimpanan();
    cout << "TEST2" << endl;
};