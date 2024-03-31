#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "Hewan.hpp"

class Herbivore : public Hewan
{
    private:
    public:
        Herbivore(string kode, string nama, int berat, int harga);
        ~Herbivore();
        void makan(string product_type);
};


#endif