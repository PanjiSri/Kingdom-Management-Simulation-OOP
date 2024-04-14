
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
#include "../toko/Toko.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

class Peran
{
protected:
    int gulden;
    int berat;
    string username;
    MatriksPenyimpanan<Item *> penyimpanan;

public:
    // Constructor & Destructor
    Peran();
    Peran(string username, int row, int col);
    Peran(string username, int berat, int gulden, int row, int col);
    ~Peran();
    Peran &operator=(const Peran &other);

    // Getter
    int getGulden();
    int getBerat();
    string getUname();

    // Setter
    void tambahBerat(int berat);

    // Other Method
    void printPenyimpanan();
    void playerMakan();
    void addPenyimpanan(Item *);
    void addPenyimpananFile(string, vector<Item *>);
    vector<string> getSemuaItem();
    vector<int> parse(string);

    virtual string getType() = 0;
    virtual void tanam() = 0;
    virtual void tanamFile(string, string, int, vector<Item *>) = 0;
    virtual void panen(vector<Produk *>) = 0;
    virtual void cetakLahan() = 0;
    virtual void beriMakan() = 0;
    virtual void addumur() = 0;
    virtual void ambilPajak(vector<Peran *>) = 0;
    virtual void bangunBangunan(vector<Bangunan *>) = 0;
    virtual void buatuser(vector<Peran *> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) = 0;
    virtual int calculateTax() = 0;
    // virtual void bangun() = 0;

    void menjual(Toko *toko);
    void membeli(Toko *toko);
};

class Walikota : public Peran
{
private:
    string peran_pemain;

public:
    // Constructor & Destructor
    Walikota(string, int, int, int, int);
    Walikota(string username, int row, int col);
    ~Walikota();
    // Walikota(int gulden, int berat, string);

    // Getter
    string getType();

    // Setter
    void addGulden(int);
    void ambilPajak(vector<Peran *>);
    void buatuser(vector<Peran *> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet);
    void tanam();
    void panen(vector<Produk *>);
    void beriMakan();
    void cetakLahan();
    void addumur();
    void bangunBangunan(vector<Bangunan *>);
    void buatuser();
    void tanamFile(string, string, int, vector<Item *>);
    // void changelahan();
    int calculateTax();
    // void bangun();
};

class Petani : public Peran
{
public:
    string peran_pemain;
    MatriksPenyimpanan<Tanaman *> lahanPertanian; // Vector plant tipe data asli

public:
    // Constructor & Destructor
    Petani();
    Petani(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
    Petani(string username, int, int, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
    ~Petani();

    // Getter
    string getType();

    // Other Method
    void tanam();
    void beriMakan();
    void cetakLahan();
    void addumur();
    void panen(vector<Produk *>);
    void ambilPajak(vector<Peran *>);
    void buatuser(vector<Peran *> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet);
    void tanamFile(string, string, int, vector<Item *>);
    void bangunBangunan(vector<Bangunan *>);
    // void changelahan();
    int calculateTax();
    // void bangun();
};

class Peternak : public Peran
{
public:
    string peran_pemain;
    MatriksPenyimpanan<Hewan *> peternakan; // Vector pakai tipe data animal

public:
    // Constructor & Destructor
    Peternak();
    Peternak(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
    Peternak(string username, int, int, int row_inventory, int col_inventory, int row_lahan, int col_lahan);
    ~Peternak();

    // Getter
    string getType();

    // Other Method
    void tanam();
    void beriMakan();
    void cetakLahan();
    void addumur();
    void panen(vector<Produk *>);
    void ambilPajak(vector<Peran *>);
    void buatuser(vector<Peran *> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet);
    void tanamFile(string, string, int, vector<Item *>);
    void bangunBangunan(vector<Bangunan *>);
    int calculateTax();
    // void bangun();
};

#endif
