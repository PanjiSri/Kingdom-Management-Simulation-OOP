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
        Herbivore(int, string, string, int, int);
        Herbivore(const Herbivore&);
        ~Herbivore();

        // Getter
        string getTipe();

        // Other Method
        void makan(Produk* produk);
};


#endif