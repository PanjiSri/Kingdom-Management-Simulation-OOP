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

    public:
        Peran();
        Peran(string);
        Peran(int gulden, int berat, string username);
        int getgulden();
        int getberat();
        void printpenyimpanan();
        Peran& operator=(const Peran&);
};

// class Walikota: public Peran {
//     public:
//         Walikota();
//         Walikota(int gulden, int berat);
//         void ambilpajak();
// };

class Petani: public Peran {
    private: 
        vector<vector<string>> lahanpertanian;

    public:
        Petani();
        Petani(string);
        Petani(int gulden, int berat, string);
        void tanam();
        void cetaklahan();
        void pernyataanperan();
        void panen();
        int getlahankosong();
};

#endif