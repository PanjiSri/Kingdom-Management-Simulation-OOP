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
    const int harga;

public:
    // Constructor & Destructor
    Produk();
    Produk(int _id, string, string, string, string, int, int);
    Produk(const Produk &other);
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

    /*
        Mengembalikan harga produk
    */
    int getHarga();
    void makan(Produk* produk){}
};

#endif
