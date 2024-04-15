#ifndef __WALIKOTA_HPP__
#define __WALIKOTA_HPP__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Peran.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"

using namespace std;

class Walikota : public Peran {
    private:
        string type = "Walikota";
        
    public:
        // Constructor & Destructor
        Walikota();
        Walikota(string username, int row_inv, int col_inv);
        Walikota(string username, int berat, int gulden, int row_inv, int col_inv);
        ~Walikota();
        Walikota &operator= (const Walikota &other);

        // Getter
        string getType();
        int getKekayaan();

        // Setter
        
        // Other Method
        void beternakBertani();
        void beternakBertaniFile(string, string, int, vector<Item*>);
        void panen(vector<Produk*>);
        void cetakLahan();
        void beriMakan();
        void addUmurTanaman();
        int calculateTax();
        void ambilPajak(vector<Peran*>);    //nanti dulu
        void buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet);
        // void bangun();
        // void bangunBangunan(vector<Bangunan*>);
        // void menjual(Toko* toko);
        // void membeli(Toko* toko);
};

#endif