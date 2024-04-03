#ifndef CARNIVORE_HPP
#define CARNIVORE_HPP

#include "Hewan.hpp"

class Carnivore : public Hewan
{
    private:

    public:
        Carnivore(string kode, string nama, int berat, int harga);
        ~Carnivore();
    virtual void makan(string product_type);
    void panen();
};

Carnivore::Carnivore(string kode, string nama, int berat, int harga) : Hewan(kode, nama, berat, harga)
{
}

Carnivore::~Carnivore()
{
}

//masih dummy
void Carnivore::makan(string product_type) {
    if (product_type != "Hewan")
    {
        throw exception();
    } else {
         
    }
    
}

#endif