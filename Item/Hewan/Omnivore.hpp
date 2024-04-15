#ifndef OMNIVORE_HPP
#define OMNIVORE_HPP

#include "Hewan.hpp"
#include <vector>

class Omnivore : public Hewan
{
    private:
        string tipe = "OMNIVORE";

    public:
        // Constructor & Destructor
        Omnivore();
        Omnivore(int, string, string, int, int);
        Omnivore(const Omnivore&);
        ~Omnivore();

        // Getter
        string getTipe();
        vector<string> getProduk();
        
        // Other Method
        void makan(Item* item);
};

#endif