// #include "../exception/header/exception.hpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Bangunan/Bangunan.hpp"

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Toko {
private:
    vector<Item*> jenisBarang;
    map<string,int> jumlahTiapJenis;
public:
    // Konstruktor dan destruktor
    Toko();
    Toko(vector<Tanaman*>, vector<Hewan*>, vector<Produk*>, vector<Bangunan*>); 
    ~Toko();

    // Getter
    vector<vector<string>> getBarangJumlah();
    vector<Item*> getListBarang();

    // Setter
    void setJenisBarang(string, int);
    
    // Other Method
    Item* jual(int no, int kuantitas);
    void beli(Item* barang);
    void cetakListBarang();
};