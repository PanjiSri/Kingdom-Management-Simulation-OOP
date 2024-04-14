#ifndef CARNIVORE_HPP
#define CARNIVORE_HPP

#include "Hewan.hpp"

class Carnivore : public Hewan
{
    private:
        const string tipe = "CARNIVORE";

    public:
        // Constructor & Destructor
        Carnivore();
        Carnivore(int, string, string, int, int);
        Carnivore(const Carnivore&);
        ~Carnivore();

        // Getter
        string getTipe();

        // Other Method
        bool makan(Produk* produk);
};

#endif