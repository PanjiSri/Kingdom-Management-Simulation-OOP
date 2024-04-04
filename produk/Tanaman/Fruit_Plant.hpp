#ifndef __Fruit_Plant_HPP__
#define __Fruit_Plant_HPP__

#include <string>
#include <iostream>
#include "Plant.hpp"
using namespace std;

class Fruit_Plant : public Plant {
    private:
        string tipe = "FRUIT_PLANT";
        string kode;
        string nama;
        string product_name;

    public:
        // Constructor
        Fruit_Plant(int _ID);

        // Getter
        string get_tipe();
        string get_kode();
        string get_nama();
        string get_product_name();
};

#endif