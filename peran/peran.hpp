
#ifndef _PERAN_HPP_
#define _PERAN_HPP_
#include "vector"
#include "vector.hpp"
#include "vector2.hpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "../toko/Toko.hpp"
#include <iostream>
using namespace std;


class Peran {
    public: 
        int gulden;
        int berat;
        string username;
        MatriksHewan<Item*> penyimpanan; // Vector item
        string peran_pemain;
    public:
        Peran();
        Peran(string);
        Peran(int gulden, int berat, string username);
        int getgulden();
        int getberat();
        virtual int calculateTax() = 0;
        string get_type();
        void printpenyimpanan();
        void addpenyimpanan(string, vector<Item*>);
        void setberat(int berat);
        void player_makan();
        virtual void tanam() = 0;
        virtual void cetaklahan() = 0;
        virtual void panen() = 0;
        virtual void berimakan() = 0;
        virtual int getlahankosong() = 0;
        virtual void menjual(Toko* toko) = 0;
        virtual void membeli(Toko* toko) = 0;
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
        int calculateTax();
};

class Petani: public Peran {
    public: 
        MatriksTumbuhan<Tanaman*, 8, 8> lahanpertanian; // Vector plant tipe data asli

    public:
        Petani();
        Petani(string);
        Petani(int gulden, int berat, string);
        void tanam();
        void berimakan();
        void cetaklahan();
        void panen();
        int calculateTax();
        int getlahankosong();
};

class Peternak: public Peran {
    public: 
        MatriksHewan<Hewan*> peternakan; // Vector pakai tipe data animal

    public:
        Peternak(string);
        // Peternak(int, int, string);
        void tanam();
        void panen();
        int calculateTax();
        int getlahankosong();
        void cetaklahan();
        void berimakan();
};

#endif
