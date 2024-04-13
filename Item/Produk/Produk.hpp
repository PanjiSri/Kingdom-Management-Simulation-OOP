#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <string>
#include "../Item.hpp"
using std::string;

class Produk : public Item
{
private:
    const string tipe;
    const string asal;
    const int tambahan_berat;

public:
    // Constructor & Destructor
    Produk();
    Produk(int, string, string, string, string, int, int);
    Produk(const Produk&);
    ~Produk();

    /*
        Mengembalikan tipe produk
    */
    string getTipe();

    /*
        Mengembalikan asal produk
    */
    string getAsal();

    /*
        Mengembalikan tambahan berat jika produk dikonsumsi
    */
    int getTambahan();
};

#endif
