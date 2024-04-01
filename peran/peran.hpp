#ifndef _PERAN_HPP_
#define _PERAN_HPP_
#include "vector"
#include <iostream>
using namespace std;
class Peran {
    public: 
        int gulden;
        int berat;
        string username;
        vector<vector<string>> penyimpanan;
        string peran_pemain;
    public:
        Peran();
        Peran(string);
        Peran(int gulden, int berat, string username);
        int getgulden();
        int getberat();
        void printpenyimpanan();
        void addpenyimpanan(string);
        vector<int> parse(string);
        Peran& operator=(const Peran&);
};

class Walikota: public Peran {
    public:
        Walikota(string);
        Walikota(int gulden, int berat, string);
        void ambilpajak();
};

class Petani: public Peran {
    private: 
        vector<vector<string>> lahanpertanian; // Vector plant tipe data asli

    public:
        Petani();
        Petani(string);
        Petani(int gulden, int berat, string);
        void tanam();
        void cetaklahan();
        void panen();
        int getlahankosong();
};

class Peternak: public Peran {
    private: 
        vector<vector<string>> peternakan; // Vector pakai tipe data animal

    public:
        Peternak(string);
        Peternak(int, int, string);
};

#endif