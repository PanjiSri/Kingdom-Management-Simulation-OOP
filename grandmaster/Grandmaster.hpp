#ifndef GRANDMASTER_HPP
#define GRANDMASTER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "../input/header/Konfigurasi_Item.hpp"
#include "../input/header/Konfigurasi_Animal.hpp"
#include "../input/header/Konfigurasi_Tanaman.hpp"
#include "../input/header/Konfigurasi_Produk.hpp"
#include "../input/header/Konfigurasi_Recipe.hpp"
#include "../peran/Peran.hpp"
#include "../peran/Walikota.hpp"
#include "../peran/Petani.hpp"
#include "../peran/Peternak.hpp"
#include "../exception/header/exception.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
using namespace std;

class Grandmaster
{
private:
    // variabel konstan
    int uang_menang;
    int berat_menang;
    int besar_penyimpanan[2];
    int besar_lahan[2];
    int besar_peternakan[2];

    // list jenis tanaman, hewan, produk
    vector<Konfigurasi_Tanaman> list_jenis_tanaman;
    vector<Konfigurasi_Animal> list_jenis_hewan;
    vector<Konfigurasi_Produk> list_jenis_produk;
    vector<Konfigurasi_Recipe> list_jenis_bangunan;

    // inisiasi configurasi
    vector<Item *> list_item;
    vector<Tanaman *> list_tanaman;
    vector<Hewan *> list_hewan;
    vector<Produk *> list_produk;
    vector<Bangunan *> list_bangunan;

    //toko kang
    Toko* toko;

    // path ke file konfigurasi
    string config_hewan;
    string config_tanaman;
    string config_produk;
    string config_misc;
    string config_recipe;

    // list pemain
    vector<Peran *> list_pemain;
    int banyak_pemain;

    // logic permainan
    int idx_giliran_pemain;

public:
    // Constructor & Destructor
    Grandmaster();
    ~Grandmaster();

    // Getter
    int getBesarPenyimpanan(int index) const;
    int getBesarLahan(int index) const;
    int getBesarPeternakan(int index) const;
    int getIndexGiliran() const;
    string cariKodeBarang(string nama);

    // method load animal.txt, plant.txt, product.txt, recipe.txt
    void loadConfigHewanTanaman();
    void loadConfigProduk();
    void loadConfigRecipe();
    void loadConfigMisc();
    void loadallconfig();

    //inisiasi
    void inisiatorTanaman();
    void inisiatorHewan();
    void inisiatorProduk();
    void inisiatorBangunan();

    // memulai game
    void mulaiTanpaBerkas();

    //memulai game dengan berkas
    void mulaiDenganBerkas(string data_path);

    // manipulasi list
    void muatPemain(Peran *pemain_baru);

    // muatState
    void muatState(string data_path);

    // cari jenis
    int cariJenis(string nama);

    // cari index pemain berdasarkan username
    int cariPemain(string username);

    // command program
    void next();

    //alur program
    void operasi_perintah(string command);

    void runner();
};

#endif