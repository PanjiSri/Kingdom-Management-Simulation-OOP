#ifndef OMNIVORE_HPP
#define OMNIVORE_HPP

#include "Hewan.hpp"

class Omnivore : public Hewan
{
    private:
    public:
        Omnivore(string kode, string nama, int berat, int harga);
        ~Omnivore();
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