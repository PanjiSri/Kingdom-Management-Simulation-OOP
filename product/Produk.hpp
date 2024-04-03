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
    Produk(int, string &, string &, string &, string &, int, int);

    int get_id();
    string get_kode();
    string get_nama();
    string get_tipe();
    string get_asal();
    int get_tambahan_berat();
    int get_harga();
};

#endif
