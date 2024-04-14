#ifndef __BANGUNAN_HPP__
#define __BANGUNAN_HPP__

#include <iostream>
#include <string>
#include <map>
#include "../Item.hpp"
using namespace std;

class Bangunan : public Item {
    public:
        // Constructor & Destructor
        Bangunan();
        Bangunan(int, string, string, int);
        Bangunan(const Bangunan&);
        ~Bangunan();

        // map<string, int> getMaterial();
        string getTipe();
        int getTambahan();
};

#endif