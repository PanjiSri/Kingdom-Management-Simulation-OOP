#include <iostream>
#include <string>
#include <vector>
#include "Carnivore.hpp"
#include "Herbivore.hpp"
#include "Omnivore.hpp"
#include "Hewan.hpp"
#include "../Item.hpp"

using namespace std;

int main() {
    Carnivore c (1, "SIN", "SINGA", 20, 100);
    Herbivore h (2, "KMB", "KAMBING", 10, 50);
    Omnivore o (3, "MNY", "MONYET", 15, 75);

    cout << c.getHarga() << endl;
    cout << h.getHarga() << endl;
    cout << o.getHarga() << endl;

    cout << c.getBeratPanen() << endl;
    cout << h.getBeratPanen() << endl;
    cout << o.getBeratPanen() << endl;

    cout << c.getKode() << endl;
    cout << h.getKode() << endl;
    cout << o.getKode() << endl;

    cout << c.getKode() << endl;
    cout << h.getKode() << endl;
    cout << o.getKode() << endl;

    cout << c.getKode() << endl;
    cout << h.getKode() << endl;
    cout << o.getKode() << endl;

    cout << c.getTipe() << endl;
    cout << h.getTipe() << endl;
    cout << o.getTipe() << endl;

    cout << c.getID() << endl;
    cout << h.getID() << endl;
    cout << o.getID() << endl;

    return 0;
}

// compile
// g++ -o tes tes.cpp Carnivore.cpp Herbivore.cpp Omnivore.cpp Hewan.cpp ../Item.cpp