#include "Omnivore.hpp"

Omnivore::Omnivore(string kode, string nama, int berat, int harga) : Hewan(kode, nama, berat, harga)
{
}

Omnivore::~Omnivore()
{
}

// masih dummy
void Omnivore::makan(string product_type) {
    
}
