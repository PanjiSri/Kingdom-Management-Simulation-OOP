#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "Hewan.hpp"

class Herbivore : public Hewan
{
    private:
        string kode;
        string nama;
    public:
        Herbivore(string kode, string nama, int berat, int harga);
        ~Herbivore();
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