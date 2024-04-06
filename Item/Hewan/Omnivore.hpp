#ifndef OMNIVORE_HPP
#define OMNIVORE_HPP

#include "Hewan.hpp"

class Omnivore : public Hewan
{
    private:
        string tipe = "OMNIVORE";

    public:
        // Constructor & Destructor
        Omnivore();
        Omnivore(int _ID);
        Omnivore(const Omnivore& other);
        ~Omnivore();

        string getTipe();
        void makan(Produk* produk);
};

#endif