#ifndef __TANAMAN_HPP__
#define __TANAMAN_HPP__

#include <iostream>
#include <string>
#include "../Item.hpp"
#include <vector>

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
        vector<string> getProduk();

        // Setter
        void tambahUmur();
        void setUmur(int);
        map<string, int> getMaterial();

        // Other Method
        bool isSiapPanen();
};

#endif