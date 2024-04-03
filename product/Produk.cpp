#include "Produk.hpp"

/*
    User-defined constructor produk
*/
Produk::Produk(int id, string &kode, string &nama, string &tipe, string &asal, int tambahan_berat, int harga)
    : id(id), kode(kode), nama(nama), tipe(tipe), asal(asal), tambahan_berat(tambahan_berat), harga(harga) {}

/*
    Mengembalikan id produk
*/
int Produk::get_id()
{
    return id;
}

/*
    Mengembalikan kode huruf produk
*/
string Produk::get_kode()
{
    return kode;
}

/*
    Mengembalikan nama produk
*/
string Produk::get_nama()
{
    return nama;
}

/*
    Mengembalikan tipe produk
*/
string Produk::get_tipe()
{
    return tipe;
}

/*
    Mengembalikan asal produk
*/
string Produk::get_asal()
{
    return asal;
}

/*
    Mengembalikan tambahan berat jika produk dikonsumsi
*/
int Produk::get_tambahan_berat()
{
    return tambahan_berat;
}

/*
    Mengembalikan harga produk
*/
int Produk::get_harga()
{
    return harga;
}
