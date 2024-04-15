#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Item {
    protected:
        const int ID;
        const string kode;
        const string nama;
        const int harga;
    
    public:
        // Constructor & Destructor
        Item();
        Item(int, string, string, int);
        Item(const Item&);
        ~Item();
        
        // Getter
        int getID();
        string getKode();
        string getNama();
        int getHarga();
        virtual string getTipe() = 0;
        virtual int getTambahan() = 0;
        // virtual map<string, int> getMaterial() = 0;

        // Other Method
        bool operator==(string nama) const;
};

#endif