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
        Herbivore(int _ID, string, string, int, int);
        Herbivore(const Herbivore& other);
        ~Herbivore();

        string getType();
        void makan(Produk* produk);
        int getHarga();
};


#endif