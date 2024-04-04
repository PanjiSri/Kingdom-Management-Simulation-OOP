#ifndef __Plant_HPP__
#define __Plant_HPP__

#include <iostream>
#include <string>
using namespace std;

class Plant {
    protected:
        int ID;
        int harga;
        int umur;
        int waktu_panen;

    public:
        // Constructor
        Plant(int _ID);

        // Getter
        int get_ID();
        int get_harga();
        int get_umur();
        int get_waktu_panen();
        
        // Setter
        void tambah_umur();

        // Method virtual
        virtual string get_kode() = 0;
        virtual string get_nama() = 0;
        virtual string get_tipe() = 0;
        virtual string get_product_name() = 0;
};

#endif