// #include "exception/header/exception.hpp"

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Toko
{
private:
    // harusnya objek item cuman belum dibuat
    vector<string> jenisBarang;
    map<string,int> listBarang;
public:
    Toko();
    ~Toko();
    void jual(string kode);
    void beli(string kode);
    void cetakListBarang();
};