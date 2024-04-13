
#ifndef _PERAN_HPP_
#define _PERAN_HPP_
#include "vector"
#include "MatriksPenyimpanan.hpp"
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
        MatriksPenyimpanan<Item*> penyimpanan;
        
    public:
        // Constructor & Destructor
        Peran();
        Peran(string username, int row, int col);
        Peran(int gulden, int berat, string username, int row, int col);
        ~Peran();
        Peran& operator= (const Peran& other);

        // Getter
        int getGulden();
        int getBerat();

        // Setter
        void tambahBerat(int berat);

        // Other Method
        void printPenyimpanan();
        void playerMakan();
        void addPenyimpanan(string, vector<Item*>);
        vector<int> parse(string);
        
        virtual string getType() = 0;
        virtual void tanam() = 0;
        virtual void panen() = 0;
        virtual void cetakLahan() = 0;
        virtual void beriMakan() = 0;
        virtual int getLahanKosong() = 0;
        virtual int calculateTax() = 0;
};

class Walikota: public Peran {
    private:
        string peran_pemain;

    public:
        // Constructor & Destructor
        Walikota(string username, int row, int col);
        ~Walikota();
        // Walikota(int gulden, int berat, string);

        // Getter
        string getType();

        // Setter
        void addGulden(int);
        void ambilPajak(vector<Peran*>);
        void tanam();
        void panen();
        void beriMakan();
        void cetakLahan();
        int getlahankosong();
        int calculateTax();
};

class Petani: public Peran {
    public:
        string peran_pemain; 
        MatriksPenyimpanan<Tanaman*> lahanPertanian; // Vector plant tipe data asli

    public:
        // Constructor & Destructor
        Petani();
        Petani(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
        Petani(int gulden, int berat, string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
        ~Petani();

        // Getter
        string getType();

        // Other Method
        void tanam();
        void beriMakan();
        void cetakLahan();
        void panen();
        int calculateTax();
        int getLahanKosong();
};

class Peternak: public Peran {
    public: 
        string peran_pemain;
        MatriksPenyimpanan<Hewan*> peternakan; // Vector pakai tipe data animal

    public:
        // Constructor & Destructor
        Peternak();
        Peternak(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
        Peternak(int gulden, int berat, string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
        ~Peternak();

        // Getter
        string getType();

        // Other Method
        void tanam();
        void beriMakan();
        void cetakLahan();
        void panen();
        int calculateTax();
        int getLahanKosong();
};

#endif
