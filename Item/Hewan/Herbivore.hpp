#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "Hewan.hpp"

class Herbivore : public Hewan
{
    private:
        string tipe = "HERBIVORE";

    public:
        // Constructor & Destructor
        Herbivore();
        Herbivore(int _ID);
        Herbivore(const Herbivore& other);
        ~Herbivore();

        string getTipe();
        void makan(Produk* produk);
};


#endif