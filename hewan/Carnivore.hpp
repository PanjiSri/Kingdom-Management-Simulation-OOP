#ifndef CARNIVORE_HPP
#define CARNIVORE_HPP

#include "Hewan.hpp"

class Carnivore : public Hewan
{
    private:
        string kode; 
        string nama;
    public:
        Carnivore();
        Carnivore(string kode, string nama, int berat, int harga);
        ~Carnivore();
        string getType();
        string getKode();
        string getNama();
        int getBeratPanen();
        int getHarga();
        int getberat_saat_ini();
        void makan(Produk produk);
        bool isSiapPanen();
};

#endif