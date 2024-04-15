#include "Bangunan.hpp"

// Constructor & Destructor

Bangunan::Bangunan()
    : Item(), 
      teak_wood_cost(0),
      sandalwood_wood_cost(0), 
      aloe_wood_cost(0), 
      ironwood_wood_cost(0) 
    {}

Bangunan::Bangunan(int id, 
                   string kode, 
                   string nama, 
                   int harga, 
                   int teak_wood_cost, 
                   int sandalwood_wood_cost, 
                   int aloe_wood_cost, 
                   int ironwood_wood_cost)
    : Item(id, kode, nama, harga), 
      teak_wood_cost(teak_wood_cost), 
      sandalwood_wood_cost(sandalwood_wood_cost), 
      aloe_wood_cost(aloe_wood_cost), 
      ironwood_wood_cost(ironwood_wood_cost) 
    {}

Bangunan::Bangunan(const Bangunan& other)
    : Item(other),
      teak_wood_cost(other.teak_wood_cost),
      sandalwood_wood_cost(other.sandalwood_wood_cost),
      aloe_wood_cost(other.aloe_wood_cost),
      ironwood_wood_cost(other.ironwood_wood_cost)
    {}

Bangunan::~Bangunan() {}

// Getter

int Bangunan::getTeakWoodCost() {
    return teak_wood_cost;
}
int Bangunan::getSandalwoodWoodCost() {
    return sandalwood_wood_cost;
}
int Bangunan::getAloeWoodCost() {
    return aloe_wood_cost;
}
int Bangunan::getIronwoodWoodCost() {
    return ironwood_wood_cost;
}
