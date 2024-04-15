#include "header/konfig_recipe.hpp"


Konfigurasi_Recipe::Konfigurasi_Recipe()
{
    banyak_material_1 = 0;
    material_1 = "";
    banyak_material_2 = 0;
    material_2 = "";
    banyak_material_3 = 0;
    material_3 = "";
    banyak_material_4 = 0;
    material_4 = "";
}

Konfigurasi_Recipe::Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, string mrl_1, int banyak_1, string mrl_2, int banyak_2)
{
    this->id = _id;
    this->kode = _kode;
    this->nama = _nama;
    this->harga = harga;
    this->material_1 = mrl_1;
    this->banyak_material_1 = banyak_1;
    this->material_2 = mrl_2;
    this->banyak_material_2 = banyak_2;
}

Konfigurasi_Recipe::Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, string mrl_1, int banyak_1, string mrl_2, int banyak_2, string mrl_3, int banyak_3)
{
    this->id = _id;
    this->kode = _kode;
    this->nama = _nama;
    this->harga = harga;
    this->material_1 = mrl_1;
    this->banyak_material_1 = banyak_1;
    this->material_2 = mrl_2;
    this->banyak_material_2 = banyak_2;
    this->material_3 = mrl_3;
    this->banyak_material_3 = banyak_3;
}

Konfigurasi_Recipe::Konfigurasi_Recipe(int _id, string _kode, string _nama, int harga, string mrl_1, int banyak_1, string mrl_2, int banyak_2, string mrl_3, int banyak_3, string mrl_4, int banyak_4)
{
    this->id = _id;
    this->kode = _kode;
    this->nama = _nama;
    this->harga = harga;
    this->material_1 = mrl_1;
    this->banyak_material_1 = banyak_1;
    this->material_2 = mrl_2;
    this->banyak_material_2 = banyak_2;
    this->material_3 = mrl_3;
    this->banyak_material_3 = banyak_3;
    this->material_4 = mrl_4;
    this->banyak_material_4 = banyak_4;
}

Konfigurasi_Recipe::~Konfigurasi_Recipe() {}

int Konfigurasi_Recipe::getBanMrl1() { return this->banyak_material_1; }
int Konfigurasi_Recipe::getBanMrl2() { return this->banyak_material_2; }
int Konfigurasi_Recipe::getBanMrl3() { return this->banyak_material_3; }
int Konfigurasi_Recipe::getBanMrl4() { return this->banyak_material_4; }

string Konfigurasi_Recipe::getMrl1() { return this->material_1; }
string Konfigurasi_Recipe::getMrl2() { return this->material_2; }
string Konfigurasi_Recipe::getMrl3() { return this->material_3; }
string Konfigurasi_Recipe::getMrl4() { return this->material_4; }   
