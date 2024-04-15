#ifndef __PETANI_HPP__
#define __PETANI_HPP__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Peran.hpp"

using namespace std;

class Petani : public Peran {
    private:
        string type = "Petani";
        MatriksPenyimpanan<Tanaman*> lahanPertanian;   // Vector pakai tipe data tanaman

    public:
        // Constructor & Destructor
        Petani();
        Petani(string username, int row_inv, int col_inv, int row_lahan, int col_lahan);
        Petani(string username, int berat, int gulden, int row_inv, int col_inv, int row_lahan, int col_lahan);
        ~Petani();
        Petani& operator= (const Petani &other);

        // Getter
        string getType();

        // Setter
        
        // Other Method
        void beternakBertani();
        void beternakBertaniFile(string location, string name, int umur, vector<Item*> listitem);
        void cetakLahan();
        void panen(vector<Produk*>);
        void beriMakan();
        void addUmurTanaman();
        void ambilPajak(vector<Peran*>);
        void buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet);
        int calculateTax();
        // void bangun();
        // void bangunBangunan(vector<Bangunan*>);
        // void menjual(Toko* toko);
        // void membeli(Toko* toko);
};

#endif