#include <vector>

#include <iostream>
#include <string>
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "MatriksPenyimpanan.hpp"
using namespace std;

// compile
// g++ -o test test.cpp ../Pcolorpcolor.c ../Item/Hewan/Carnivore.cpp ../Item/Hewan/Omnivore.cpp ../Item/Hewan/Herbivore.cpp ../Item/Hewan/Hewan.cpp ../Item/Item.cpp ../Item/Produk/Produk.cpp ../Item/Tanaman/Tanaman.cpp ../Item/Bangunan/Bangunan.cpp

int main() {
    MatriksPenyimpanan<Tanaman*> lahanpertanian;
    lahanpertanian.print();
    lahanpertanian.setUkuran(8,8);
    lahanpertanian.print();
    MatriksPenyimpanan<Hewan*> peternakan;
    peternakan.print();
    peternakan.setUkuran(8,8);
    peternakan.print();
    
    lahanpertanian.setElement(0,1,new Tanaman(1,"T01","Tanaman1","HERBIVORE",1,100));
    lahanpertanian.setElement(7,2,new Tanaman(2,"T02","Tanaaman2","HERBIVORE",2,200));
    lahanpertanian.print();
    
    lahanpertanian+=new Tanaman(3,"T03","Tanaman3","HERBIVORE",3,300);
    
    lahanpertanian.print();

    lahanpertanian+=new Tanaman(4,"T04","Tanaman4","HERBIVORE",4,400);
    lahanpertanian.print();

    cout << "                              harga: " << lahanpertanian.getValue() << endl;

    
    lahanpertanian+=new Tanaman(4,"T05","Tanaman4","HERBIVORE",4,400);
    lahanpertanian.printlahan();
    cout << "                              harga: " << lahanpertanian.getValue() << endl;
    
    return 0;
}