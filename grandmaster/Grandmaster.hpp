#ifndef GRANDMASTER_HPP
#define GRANDMASTER_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../input/header/input.hpp"
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

    // path ke file konfigurasi
    string config_hewan;
    string config_tanaman;
    string config_produk;
    string config_misc;

public:
    Grandmaster();
    // method load animal.txt, plant.txt, product.txt
    void loadConfigHewanTanaman();
    void loadConfigProduk();
    void loadallconfig();

    // method load misc.txt
    void loadConfigMisc();

    //memulai game
    void mulaiTanpaBerkas();

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