#ifndef CARNIVORE_HPP
#define CARNIVORE_HPP

#include "Hewan.hpp"
#include <vector>

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
        vector<string> getProduk();

        // Other Method
        void makan(Item* item);
};

#endif