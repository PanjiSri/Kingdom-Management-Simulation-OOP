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
    Produk(int _id);
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
    int getTambahanBerat();

    /*
        Mengembalikan harga produk
    */
    int getHarga();
};

#endif
