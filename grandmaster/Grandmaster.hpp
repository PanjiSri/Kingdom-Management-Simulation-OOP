#ifndef GRANDMASTER_HPP
#define GRANDMASTER_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../input/header/input.hpp"
#include "../peran/peran.hpp"
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
    vector<Line_Handler> list_jenis_tanaman;
    vector<Line_Handler> list_jenis_hewan;
    vector<Line_Handler_Produk> list_jenis_produk;

    // inisiasi configurasi
    vector<Tanaman *> list_tanaman;
    vector<Hewan *> list_hewan;
    vector<Produk *> list_produk;
    vector<Item *> list_item;


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

    // manipulasi list
    void muatPemain(Peran *pemain_baru);

    // muatState
    void muatState(string data_path);

    //cari jenis
    int cariJenis(string nama);

    // //cari index
    // int cariIndex(string nama);

    //................... ini buat testing aja......................//
    Line_Handler getJenisTanaman(int index) const;

    Line_Handler getJenisHewan(int index) const;

    Line_Handler_Produk getJenisProduk(int index) const;

    //..............................................................//

    int getUangMenang() const;

    int getBeratMenang() const;

    int getBesarPenyimpanan(int index) const;

    int getBesarLahan(int index) const;

    int getBesarPeternakan(int index) const;

    // ~Grandmaster();
};

#endif