#ifndef __BANGUNAN_HPP__
#define __BANGUNAN_HPP__

#include <iostream>
#include <string>
#include <map>
#include "../Item.hpp"
using namespace std;

class Bangunan : public Item {
    private:
        // map<string, int> resep;
        const int harga;
    
    public:
        // Constructor & Destructor
        Bangunan();
        Bangunan(int _ID);
        Bangunan(const Bangunan& other);
        ~Bangunan();
        Bangunan& operator=(const Bangunan& other);

        // Getter
        int getHarga();
};

#endif