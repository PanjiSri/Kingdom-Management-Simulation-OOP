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
        int umur;

    public:
        // Constructor & Destructor
        Tanaman();
        Tanaman(int, string, string, string, int, int);
        Tanaman(const Tanaman&);
        ~Tanaman();

        // Getter
        string getTipe();
        int getWaktuPanen();
        int getUmur();
        int getTambahan();

        // Setter
        void tambahUmur();
        void setUmur(int);

        // Other Method
        bool isSiapPanen();
};

#endif