#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <string>

using std::string;

class Produk
{
private:
    const int id;
    const string kode;
    const string nama;
    const string tipe;
    const string asal;
    const int tambahan_berat;
    const int harga;

public:
    /*
        User-defined constructor produk
    */
    Produk(int id, const string &kode, const string &nama, const string &tipe, const string &asal, int tambahan_berat, int harga);

    /*
        Mengembalikan id produk
    */
    int get_id();

    /*
        Mengembalikan kode huruf produk
    */
    string get_kode();

    /*
        Mengembalikan nama produk
    */
    string get_nama();

    /*
        Mengembalikan tipe produk
    */
    string get_tipe();

    /*
        Mengembalikan asal produk
    */
    string get_asal();

    /*
        Mengembalikan tambahan berat jika produk dikonsumsi
    */
    int get_tambahan_berat();

    /*
        Mengembalikan harga produk
    */
    int get_harga();
};

#endif
