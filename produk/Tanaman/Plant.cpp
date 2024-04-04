#include "Plant.hpp"

// Constructor
Plant::Plant(int _ID) {
    this->ID = _ID;
    //this->harga = dummy[_ID][];
    this->umur = 0;
    //this->waktu_panen = dummy[_ID][];
}

// Getter
int Plant::get_ID() {
    return this->ID;
}

int Plant::get_harga() {
    return this->harga;
}

int Plant::get_umur() {
    return this->umur;
}

int Plant::get_waktu_panen() {
    return this->waktu_panen;
}

// Setter
void Plant::tambah_umur() {
    umur++;
}
