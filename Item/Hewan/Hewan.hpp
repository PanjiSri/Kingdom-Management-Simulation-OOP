#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>
#include "../../exception/header/exception.hpp"
#include "../Produk/Produk.hpp"
#include "../Item.hpp"
#include <string>
#include <vector>

using namespace std;

class Hewan : public Item {
    protected:
        const int standar_berat_panen;
        int berat_saat_ini;

    public:
        // Constructor & Destructor
        Hewan();
        Hewan(int, string, string, int, int);
        Hewan(const Hewan&);
        virtual ~Hewan();
        
        // Getter
        int getBeratPanen();
        int getBeratSaatIni();
        int getTambahan();
        virtual string getTipe() = 0;
        virtual vector<string> getProduk() = 0;

        // Setter
        void tambahBerat(int);
        void setBerat(int);
        
        // Other Method
        virtual void makan(Item* item) = 0;
        bool isSiapPanen();
};

#endif