
#ifndef _PERAN_HPP_
#define _PERAN_HPP_
#include "vector"
#include "vector.hpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include <iostream>
using namespace std;
class Peran {
    public: 
        int gulden;
        int berat;
        string username;
        Matriks<Item*, 8, 8, 0> penyimpanan; // Vector item
        string peran_pemain;
    public:
        Peran();
        Peran(string);
        Peran(int gulden, int berat, string username);
        int getgulden();
        int getberat();
        string get_type();
        void printpenyimpanan();
        void addpenyimpanan(string, vector<Produk*>);
        virtual void tanam() = 0;
        virtual void cetaklahan() = 0;
        virtual void panen() = 0;
        virtual void berimakan() = 0;
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
        void berimakan();
        int getlahankosong();
};

class Petani: public Peran {
    public: 
        Matriks<Item*, 8, 8, 1> lahanpertanian; // Vector plant tipe data asli

    public:
        Petani();
        Petani(string);
        Petani(int gulden, int berat, string);
        void tanam();
        void berimakan();
        void cetaklahan();
        void panen();
        int getlahankosong();
};

class Peternak: public Peran {
    public: 
        Matriks<Item*,8,8,2> peternakan; // Vector pakai tipe data animal

    public:
        Peternak(string);
        // Peternak(int, int, string);
        void tanam();
        void panen();
        int getlahankosong();
        void cetaklahan();
        void berimakan();
};

#endif
