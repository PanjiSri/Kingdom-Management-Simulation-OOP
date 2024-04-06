#include "peran.hpp"
#include <iostream>
#include <ostream>
#include "vector"
#include "vector.hpp"
#include "../hewan/Hewan.hpp"
#include "../hewan/Carnivore.hpp"
#include "../hewan/Omnivore.hpp"
#include "../hewan/Herbivore.hpp"
#include "../produk/Produk.hpp"
#include <string>
using namespace std;

int main() {
    string name, code, tipe, harga, berat;
    int beratint, hargaint;
    vector<Hewan*> listhewan;
    vector<vector<string>> parse;
    string datahewan;
    bool end = false;
    // for(int i = 0; i < 7; i++) {
    //     int step = 0;
    //     string data;
    //     getline(cin,datahewan);
    //     for(int j = 0; j < datahewan.size(); j++) {
    //         if(datahewan[j] == ' ' or datahewan == "\n") {
    //             if(step == 0) {
    //                 code = data;
    //                 data = "";
    //             }
    //             else if(step == 1) {
    //                 name = data;
    //                 data = "";
    //             }
    //             else if(step == 2) {
    //                 tipe = data;
    //                 data = "";
    //             }
    //             else if(step == 3) {
    //                 harga = data;
    //                 data = "";
    //             }
    //             step += 1;   
    //         }
    //         else {
    //             data += datahewan[j];
    //         }
    //     }
    //     berat = data;
    //     if (tipe == "CARNIVORE") {
    //         Hewan* x = new Carnivore(code, name, stoi(berat), stoi(harga));
    //         listhewan.push_back(x);
    //     }
    //     else if (tipe == "OMNIVORE") {
    //         Hewan* x = new Omnivore(code, name, stoi(berat), stoi(harga));
    //         listhewan.push_back(x);
    //     }
    //     else {
    //         Hewan* x = new Herbivore(code, name, stoi(berat), stoi(harga));
    //         listhewan.push_back(x);
    //     }
    // }

    // for(int i = 0; i < listhewan.size(); i++) {
    //     cout << listhewan[i]->getType() << endl;
    // }
    vector<Peran*> listpemain;
    Peran* a = new Peternak("haikal");
    a->printpenyimpanan();
    a->cetaklahan();
};