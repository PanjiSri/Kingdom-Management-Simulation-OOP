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
        int getKekayaan();
        vector<vector<string>> getDataLahan();
        int getRowLahan();
        int getKolLahan();
        int getBanyakItemLahan();

        // Setter
        
        // Other Method
        void beternakBertani();
        void beternakBertaniFile(string location, string name, int berat, vector<Item*> listitem);
        void cetakLahan();
        void panen(vector<Produk*>);
        void beriMakan();
        void addUmurTanaman();
        void ambilPajak(vector<Peran*>);
        Peran* buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_lahan, int col_lahan, int row_ternak, int col_ternak);
        int calculateTax();
        void bangun(vector<Bangunan *> listbangunan);
        void menjual(Toko* toko);
        void membeli(Toko* toko);
        void simpan(vector<Peran *> list_pemain, Toko *toko);
};

#endif