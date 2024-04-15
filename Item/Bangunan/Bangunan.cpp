#include "Bangunan.hpp"

// Constructor & Destructor

Bangunan::Bangunan()
    : Item(), 
      teak_wood_cost(0),
      sandalwood_wood_cost(0), 
      aloe_wood_cost(0), 
      ironwood_wood_cost(0) 
    {}

Bangunan::Bangunan(int id, string kode, string nama, int harga, map<string, int> bahanBaku) 
    : Item(id, kode, nama, harga),
      teak_wood_cost(bahanBaku["TEAK_WOOD"]),
      sandalwood_wood_cost(bahanBaku["SANDALWOOD_WOOD"]),
      aloe_wood_cost(bahanBaku["ALOE_WOOD"]),
      ironwood_wood_cost(bahanBaku["IRONWOOD_WOOD"])
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

string Bangunan::getTipe() {
    return "BANGUNAN";
}

int Bangunan::getTambahan() {
    return 0;
}

void Bangunan::printDetail() {
    cout << "Nama\t: " << nama << endl;
    cout << "Harga\t: " << harga << endl;
    cout << "Bahan Baku:\n";
    cout << "1. Teak Wood\t\t: " << teak_wood_cost << endl;
    cout << "2. Sandalwood Wood\t: " << sandalwood_wood_cost << endl;
    cout << "3. Aloe Wood\t\t: " << aloe_wood_cost << endl;
    cout << "4. Ironwood Wood\t: " << ironwood_wood_cost << endl;
}