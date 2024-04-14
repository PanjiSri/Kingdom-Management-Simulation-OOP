// #include "exception/header/exception.hpp"
// #include "../Item/Item.cpp"
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Produk/Produk.hpp"
// bangungan belum terelealisasi
// #include "../Item/Bangunan/Bangunan.cpp"

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Toko
{
private:
    vector<Item*> jenisBarang;
    map<string,int> listBarang;
public:
    Toko();
    ~Toko();
    void jual(int no);
    void beli(Item* barang);
    void cetakListBarang();
};