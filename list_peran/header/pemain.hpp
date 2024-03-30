#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "dummy.hpp"
#include <iostream>
using namespace std;

class Pemain{
    private:
        string nama_pemain;
        Peran peran_pemain;

    public:
        Pemain();
        Pemain(string nama_pemain, Peran peran_pemain);
        ~Pemain();
        string getNama();
        Peran getPeran();
};

#endif