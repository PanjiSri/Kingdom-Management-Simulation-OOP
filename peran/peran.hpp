
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
#include <iostream>
using namespace std;




class Peran {
    protected: 
        int gulden;
        int berat;
        string username;
        Matriks<Item*, 8, 8> penyimpanan; // Vector item
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
        void changepernyimpanan();
        void player_makan();
        virtual void tanam() = 0;
        virtual void cetaklahan() = 0;
        virtual void panen() = 0;
        virtual void berimakan() = 0;
        virtual int getlahankosong() = 0;
        virtual void changelahan() = 0;
        vector<int> parse(string);
        // Peran& operator=(const Peran&);
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
        void changelahan();
        int calculateTax();
};

class Petani: public Peran {
    protected: 
        Matriks<Tanaman*, 8, 8> lahanpertanian; // Vector plant tipe data asli

    public:
        Petani();
        Petani(string);
        Petani(int gulden, int berat, string);
        void tanam();
        void berimakan();
        void cetaklahan();
        void panen();
        void changelahan();
        int calculateTax();
        int getlahankosong();
};

class Peternak: public Peran {
    protected: 
        Matriks<Hewan*, 8, 8> peternakan; // Vector pakai tipe data animal

    public:
        Peternak(string);
        // Peternak(int, int, string);
        void tanam();
        void panen();
        int calculateTax();
        int getlahankosong();
        void cetaklahan();
        void berimakan();
        void changelahan();
};

#endif
