#include "Herbivore.hpp"

Herbivore::Herbivore(string kode, string nama, int berat, int harga) : Hewan(kode, nama, berat, harga)
{
}

Herbivore::~Herbivore()
{
}

// masih dummy
void Herbivore::makan(string product_type) {
    if (product_type != "Tumbuhan")
    {
        throw exception();
    } else {
         
    }
    
}