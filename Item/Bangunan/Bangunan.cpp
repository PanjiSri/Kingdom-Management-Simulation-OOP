#include "Bangunan.hpp"
#include <map>

Bangunan::Bangunan() : 
    Item()
    {}

Bangunan::Bangunan(int _ID, string _kode, string _nama, int _harga, map<string, int> material) : 
    Item(_ID, _kode, _nama, _harga)
    {
        this->material = material;
    }

Bangunan::Bangunan(const Bangunan& other) :
    Item(other)
    {}

Bangunan::~Bangunan() {}

map<string, int> Bangunan::getMaterial() {
    return this->material;
}