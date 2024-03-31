#ifndef DUMMY_HPP
#define DUMMY_HPP
#include <iostream>
using namespace std;

class Peran
{
    public: 
        int gulden;
        int berat;
        string username;
        vector<vector<string>> penyimpanan;

    public:
        Peran();
        Peran(string);
        Peran(int gulden, int berat, string username);
        int getgulden();
        int getberat();
        void printpenyimpanan();
        Peran& operator=(const Peran&);
};

class Walikota : public Peran
{
};

class Peternak : public Peran
{
};

class Petani : public Peran
{
};

#endif