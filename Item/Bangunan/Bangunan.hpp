#ifndef __BANGUNAN_HPP__
#define __BANGUNAN_HPP__

#include <iostream>
#include <string>
#include <map>
#include "../Item.hpp"
using namespace std;

class Bangunan : public Item {
    protected: 
        map<string, int> material;
    public:
        // Constructor & Destructor
        Bangunan();
        Bangunan(int, string, string, int, map<string,int>);
        Bangunan(const Bangunan&);
        ~Bangunan();
};

#endif