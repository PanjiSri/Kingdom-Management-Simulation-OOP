#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>
#include "../../exception/header/exception.hpp"
#include "../produk/Produk.hpp"
#include "../Item.hpp"
#include <string>

using namespace std;

class Hewan : public Item
{
    protected:
        static int nhewan;
        const int standar_berat_panen;
        int berat_saat_ini;

    public:
        // Constructor & Destructor
        Hewan();
        Hewan(int, string, string, int, int);
        Hewan(const Hewan&);
        ~Hewan();
        
        // Getter
        int getBeratPanen();
        int getBeratSaatIni();
        string getKode();
        int getTambahan();
        static int getJumlahHewan();
        virtual string getTipe() = 0;

        
        // Setter
        void setBeratSaatIni(int);
        
        // Other Method
        virtual void makan(Produk* produk) = 0;
        bool isSiapPanen();
};

#endif