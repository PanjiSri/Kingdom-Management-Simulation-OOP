#ifndef __CONFIG_RECIPE_HPP__
#define __CONFIG_RECIPE_HPP__
#include "Konfigurasi_Item.hpp"
#include <iostream>
#include <map>
using namespace std;

class Konfigurasi_Recipe : public Konfigurasi_Item
{
private:
    map<string, int> bahan_baku;

public:
    // Konstruktor dan destruktor
    Konfigurasi_Recipe();
    Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, map<string, int> bahan_baku);
    ~Konfigurasi_Recipe();

    // Getter
    map<string, int> getBahanBaku(); 
};

#endif