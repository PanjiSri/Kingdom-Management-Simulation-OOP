#ifndef _PERAN_HPP_
#define _PERAN_HPP_
#include "vector"
#include "vector.hpp"
#include <iostream>
using namespace std;
class Peran {
    public: 
        int gulden;
        int berat;
        string username;
        vector2<string, 8, 8> penyimpanan; // Vector item
        string peran_pemain;
    public:
        Peran();
        Peran(string);
        Peran(int gulden, int berat, string username);
        int getgulden();
        int getberat();
        string get_type();
        void printpenyimpanan();
        void addpenyimpanan(string);
        virtual void tanam() = 0;
        virtual void cetaklahan() = 0;
        virtual void panen() = 0;
        virtual int getlahankosong() = 0;
        vector<int> parse(string);
        Peran& operator=(const Peran&);
};

class Walikota: public Peran {
    public:
        Walikota(string);
        // Walikota(int gulden, int berat, string);
        void addgulden(int);
        void ambilpajak(vector<Peran*>);
        void tanam();
        void cetaklahan();
        void panen();
        int getlahankosong();
};

class Petani: public Peran {
    public: 
        vector2<string, 8, 8> lahanpertanian; // Vector plant tipe data asli

    public:
        Petani();
        Petani(string);
        Petani(int gulden, int berat, string);
        void tanam();
        void cetaklahan();
        void panen();
        int getlahankosong();
};

// class Peternak: public Peran {
//     private: 
//         vector<vector<string>> peternakan; // Vector pakai tipe data animal

//     public:
//         Peternak(string);
//         Peternak(int, int, string);
// };

#endif