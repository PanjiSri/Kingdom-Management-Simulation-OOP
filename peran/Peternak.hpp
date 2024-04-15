#ifndef __PETERNAK_HPP__
#define __PETERNAK_HPP__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Peran.hpp"

using namespace std;

class Peternak : public Peran {
    private:
        string type = "Peternak";
        MatriksPenyimpanan<Hewan*> peternakan;      // Vector pakai tipe data animal

    public:
        // Constructor & Destructor
        Peternak();
        Peternak(string username, int row_inv, int col_inv, int row_lahan, int col_lahan);
        Peternak(string username, int berat, int gulden, int row_inv, int col_inv, int row_lahan, int col_lahan);
        ~Peternak();
        Peternak& operator= (const Peternak &other);

        // Getter
        string getType();

        // Setter
        
        // Other Method
        void beternakBertani();
        void beternakBertaniFile(string location, string name, int berat, vector<Item*> listitem);
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