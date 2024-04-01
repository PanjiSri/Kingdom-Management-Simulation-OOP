#ifndef __Material_Plant_HPP__
#define __Material_Plant_HPP__

#include <string>
#include <iostream>
#include "Plant.hpp"
using namespace std;

class Material_Plant : public Plant {
    protected:
        string tipe = "MATERIAL_PLANT";
        string kode;
        string nama;
        string product_name;

    public:
        // Constructor
        Material_Plant(int _ID);

        // Getter
        string get_tipe();
        string get_kode();
        string get_nama();
        string get_product_name();
};

#endif