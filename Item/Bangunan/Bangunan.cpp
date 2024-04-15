#include "Bangunan.hpp"
#include <map>

Bangunan::Bangunan() : 
    Item()
    {}

Bangunan::Bangunan(int _ID, string _kode, string _nama, int _harga) : 
    Item(_ID, _kode, _nama, _harga)
    {
    }

Bangunan::Bangunan(const Bangunan& other) :
    Item(other)
    {}

Bangunan::~Bangunan() {}

// map<string, int> Bangunan::getMaterial() {
//     return this->material;
// }

string Bangunan::getTipe() {}

int Bangunan::getTambahan() {
    return 0;
}