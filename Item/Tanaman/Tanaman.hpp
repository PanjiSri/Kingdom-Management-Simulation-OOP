#ifndef __TANAMAN_HPP__
#define __TANAMAN_HPP__

#include <iostream>
#include <string>
#include "../Item.hpp"
using namespace std;

class Tanaman : public Item {
    private:
        const string tipe;
        const int waktu_panen;
        const int harga;
        int umur;

    public:
        // Constructor & Destructor
        Tanaman();
        Tanaman(int _ID, string, string, string, int, int);
        Tanaman(const Tanaman& other);
        ~Tanaman();

        // Getter
        string getTipe();
        int getWaktuPanen();
        int getUmur();
        int getHarga();
        int getTambahan();

        // Setter
        void tambahUmur();

        // Other Method
        bool isSiapPanen();
        // void makan(Produk* produk) {}
};

#endif