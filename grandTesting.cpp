// #include "grandmaster/Grandmaster.hpp"
// #include "grandmaster/Grandmaster.cpp"
#include "grandmaster/Grandmaster.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{


    Grandmaster g;

    cout << "something" << endl;
    // g.mulaiTanpaBerkas();

    g.mulaiDenganBerkas("data/state.txt");

    // g.getAllPemainInfo();

    g.getAllPemainInfo();

    g.next();

    g.next();

    g.next();

    cout << "sekarang giliran pemain indeks ke ";
    g.next();

    cout << "sekarang giliran pemain indeks ke ";
    g.operasi_perintah("NEXT");
    g.printAllPemain();
    g.operasi_perintah("CETAK_PENYIMPANAN");
}