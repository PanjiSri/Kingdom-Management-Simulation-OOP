#ifndef __CONFIG_RECIPE_HPP__
#define __CONFIG_RECIPE_HPP__
#include "konfig_file.hpp"
#include <iostream>
using namespace std;

class Konfigurasi_Recipe : public Konfigurasi_Item
{
private:
    int banyak_material_1;
    string material_1;
    int banyak_material_2;
    string material_2;
    int banyak_material_3;
    string material_3;
    int banyak_material_4;
    string material_4;

public:
    Konfigurasi_Recipe();
    Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, string mrl_1, int banyak_1, string mrl_2, int banyak_2);
    Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, string mrl_1, int banyak_1, string mrl_2, int banyak_2, string mrl_3, int banyak_3);
    Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, string mrl_1, int banyak_1, string mrl_2, int banyak_2, string mrl_3, int banyak_3, string mrl_4, int banyak_4);

    ~Konfigurasi_Recipe();

    int getBanMrl1();
    int getBanMrl2();
    int getBanMrl3();
    int getBanMrl4();

    string getMrl1();
    string getMrl2();
    string getMrl3();
    string getMrl4();   
};

#endif