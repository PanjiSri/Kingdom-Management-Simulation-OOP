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
        int getKekayaan();
        int getRowLahan();
        int getKolLahan();
        int getBanyakItemLahan();
        vector<vector<string>> getDataLahan();

        // Setter
        
        // Other Method
        void beternakBertani();
        void beternakBertaniFile(string location, string name, int umur, vector<Item*> listitem);
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