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
        Carnivore(int _ID, string, string, int, int);
        Carnivore(const Carnivore& other);
        ~Carnivore();

        // Getter
        string getTipe();
        void makan(Produk* produk);
        int getHarga();
};

#endif