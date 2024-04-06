#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>
#include "../exception/header/exception.hpp"
#include "../produk/Produk.hpp"
using namespace std;

class Hewan
{
    private:
        string kode;
        string nama; 
        static int nhewan;
        int standar_berat_panen;
        int harga;
        int berat_saat_ini;
    public:
        Hewan();
        Hewan(string kode, string nama, int standar_berat_panen, int harga);
        ~Hewan();
        string getKode();
        string getNama();
        Hewan& operator=(Hewan& other);
        virtual string getType() = 0;
        int getBeratPanen();
        int getHarga();
        int getberat_saat_ini();
        static int getJumlahHewan();
        void setberat_saat_ini(int tambahan_berat);
        virtual void makan(Produk* produk) = 0;
        bool isSiapPanen();
};





#endif