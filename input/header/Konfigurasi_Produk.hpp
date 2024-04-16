#ifndef __PRODUK_CONFIG_HPP__
#define __PRODUK_CONFIG_HPP__
#include <iostream>
using namespace std;

#include "Konfigurasi_Item.hpp"

class Konfigurasi_Produk : public Konfigurasi_Item{
    private:
        string tipe;
        string origin;
        int berat_tambahan;
    
    public:
        // Konstruktor dan destruktor
        Konfigurasi_Produk();
        Konfigurasi_Produk(int _id, string _kode, string _nama, string _tipe, string origin, int _berat_tambahan, int _harga);
        ~Konfigurasi_Produk();

        // Getter
        string getTipe();
        string getOrigin();
        int getBeratTambahan();
};


#endif