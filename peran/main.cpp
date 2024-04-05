#include "peran.hpp"
#include <iostream>
#include <ostream>
#include "vector"
#include "vector.hpp"
#include "../hewan/Hewan.hpp"
#include "../hewan/Carnivore.hpp"
using namespace std;

int main() {
    vector<Peran*> listpemain;
    Peran* a = new Petani("haikal");
    a->cetaklahan();
};