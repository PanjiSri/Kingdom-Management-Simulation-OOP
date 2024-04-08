#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
#include <string>
using namespace std;

class Item {
    protected:
        const int ID;
        const string kode;
        const string nama;
    
    public:
        // Constructor & Destructor
        Item();
        Item(int _ID, string, string);
        Item(const Item& other);
        ~Item();

        // Getter
        int getID();
        string getKode();
        string getNama();
        virtual int getHarga() = 0;
};

#endif