#ifndef __CONFIG_RECIPE_HPP__
#define __CONFIG_RECIPE_HPP__
#include "konfig_file.hpp"
#include <iostream>
#include <map>
using namespace std;

class Konfigurasi_Recipe : public Konfigurasi_Item
{
private:
    map<string, int> bahan_baku;

public:
    Konfigurasi_Recipe();
    Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, map<string, int> bahan_baku);
    
    ~Konfigurasi_Recipe();

    map<string, int> getBahanBaku(); 
};

#endif