#ifndef __PERAN_HPP__
#define __PERAN_HPP__

#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip> // For std::setw

#include "MatriksPenyimpanan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "../toko/Toko.hpp"
#include "../Pcolor/pcolor.h"

using namespace std;

class Peran
{
protected:
    string username;
    int gulden;
    int berat;
    MatriksPenyimpanan<Item *> penyimpanan;

public:
    // Constructor & Destructor
    Peran();
    Peran(string username, int row_inv, int col_inv);
    Peran(string username, int berat, int gulden, int row_inv, int col_inv);
    ~Peran();
    Peran &operator= (const Peran &other);

    // Getter
    string getUname();
    int getGulden();
    int getBerat();
    vector<string> getSemuaItem();
    virtual int getKekayaan() = 0;
    virtual string getType() = 0;

    // Setter
    void tambahBerat(int berat);
    void tambahGulden(int gulden);

    // Other Method
    vector<int> parse(string);
    void centerAlign(const string& text, int width);
    void printPenyimpanan();
    void addPenyimpananInFirstEmpty(Item*);
    void addPenyimpananSpesifikLocation(Item*);
    void addPenyimpananFile(string, vector<Item*>);
    void playerMakan();


    virtual void beternakBertani() = 0;
    virtual void beternakBertaniFile(string, string, int, vector<Item*>) = 0;
    virtual void panen(vector<Produk*>) = 0;
    virtual void cetakLahan() = 0;
    virtual void beriMakan() = 0;
    virtual void addUmurTanaman() = 0;
    virtual void ambilPajak(vector<Peran*>) = 0;
    virtual void buatUser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) = 0;
    virtual int calculateTax() = 0;
    // virtual void bangun() = 0;
    virtual vector<vector<string>> getDataLahan() = 0;
    // virtual void menjual(Toko* toko) = 0;
    virtual void membeli(Toko* toko) = 0;
};

#endif
