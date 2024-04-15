#ifndef __INPUT_REV_HPP__
#define __INPUT_REV_HPP__
#include <iostream>
using namespace std;

class Konfigurasi_Item
{
protected:
    int id;
    string kode;
    string nama;
    int harga;

public:
    Konfigurasi_Item();
    Konfigurasi_Item(int _id, string _kode, string _nama, int _harga);
    ~Konfigurasi_Item();
    int getId();
    string getKode();
    string getName();
    int getHarga();
};

#endif