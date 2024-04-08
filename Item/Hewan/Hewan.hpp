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
        const int harga;
        int berat_saat_ini;

    public:
        // Constructor & Destructor
        Hewan();
        Hewan(int _ID, string, string, int, int);
        Hewan(const Hewan& other);
        ~Hewan();
        Hewan& operator=(Hewan& other);
        
        // Getter
        int getBeratPanen();
        int getHarga();
        int getBeratSaatIni();
        static int getJumlahHewan();
        virtual string getTipe() = 0;
        int getTambahan();
        
        // Setter
        void setBeratSaatIni(int tambahan_berat);
        
        // Other Method
        virtual void makan(Produk* produk) = 0;
        bool isSiapPanen();
};

#endif