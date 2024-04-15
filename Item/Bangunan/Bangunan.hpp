#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <string>
#include "../Item.hpp"
using namespace std;

class Bangunan : public Item {
    private:
        const int teak_wood_cost;
        const int sandalwood_wood_cost;
        const int aloe_wood_cost;
        const int ironwood_wood_cost;

    public:
        // Constructor & Destructor
        Bangunan();
        Bangunan(int id, 
                 string kode, 
                 string nama, 
                 int harga, 
                 int teak_wood_cost, 
                 int sandalwood_wood_cost, 
                 int aloe_wood_cost, 
                 int ironwood_wood_cost);
        Bangunan(const Bangunan& other);
        ~Bangunan();
        
        // Getter
        int getTeakWoodCost();
        int getSandalwoodWoodCost();
        int getAloeWoodCost();
        int getIronwoodWoodCost();

        string getTipe();
        int getTambahan();
};

#endif
