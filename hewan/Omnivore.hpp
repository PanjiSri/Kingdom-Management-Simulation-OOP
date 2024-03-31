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
        void makan(string product_type);
};

#endif