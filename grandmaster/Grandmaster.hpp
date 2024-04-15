#ifndef GRANDMASTER_HPP
#define GRANDMASTER_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "../input/header/konfig_file.hpp"
#include "../input/header/konfig_animal.hpp"
#include "../input/header/konfig_tanaman.hpp"
#include "../input/header/konfig_produk.hpp"
#include "../input/header/konfig_recipe.hpp"
#include "../peran/Peran.hpp"
#include "../peran/Walikota.hpp"
#include "../peran/Petani.hpp"
#include "../peran/Peternak.hpp"
#include "../exception/header/exception.hpp"
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
    vector<Tanaman *> list_tanaman;
    vector<Hewan *> list_hewan;
    vector<Produk *> list_produk;
    vector<Item *> list_item;
    // vector<Bangunan *> list_bangunan;


        // path ke file konfigurasi
    string config_hewan;
    string config_tanaman;
    string config_produk;
    string config_misc;

    // list pemain
    vector<Peran *> list_pemain;
    int banyak_pemain;

    // logic permainan
    int idx_giliran_pemain;

public:
    Grandmaster();
    // method load animal.txt, plant.txt, product.txt
    void loadConfigHewanTanaman();
    void loadConfigProduk();

    // method load misc.txt
    void loadConfigMisc();

    // load semua config
    void loadallconfig();

    //inisiasi tanaman
    void inisiatorTanaman();

    //inisiasi hewan
    void inisiatorHewan();

    //inisiasi produk
    void inisiatorProduk();

    // memulai game //ragu apakah perlu loadallconfig() disini?
    void mulaiTanpaBerkas();

    //memulai game dengan berkas
    void mulaiDenganBerkas(string data_path);

    // manipulasi list
    void muatPemain(Peran *pemain_baru);

    // muatState
    void muatState(string data_path);

    //cari jenis
    int cariJenis(string nama);

    // //cari index
    // int cariIndex(string nama);

    // cari index pemain berdasarkan username
    int cariPemain(string username);


    //command program
    void next();


    //alur program
    void operasi_perintah(string command);

    //................... ini buat testing aja......................//
    // Line_Handler getJenisTanaman(int index) const;

    // Line_Handler getJenisHewan(int index) const;

    // Line_Handler_Produk getJenisProduk(int index) const;

    //..............................................................//

    int getUangMenang() const;

    int getBeratMenang() const;

    int getBesarPenyimpanan(int index) const;

    int getBesarLahan(int index) const;

    int getBesarPeternakan(int index) const;

    int getIndexGiliran() const;

    void getAllPemainInfo();

    void printAllPemain();

    void printWalikota();

    ~Grandmaster();
};

#endif