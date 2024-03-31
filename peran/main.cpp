#include "peran.hpp"
#include "../helper/helper.hpp"
#include <iostream>
#include <ostream>
#include "vector"
using namespace std;

int main() {
    // <haikal,petani>, <ronaldo,walikota>
    Petani a("haikal");
    cout << a.gulden << endl;
    a.addpenyimpanan("BOM");
    a.printpenyimpanan();
}