// #include "grandmaster/Grandmaster.hpp"
// #include "grandmaster/Grandmaster.cpp"
#include "grandmaster/Grandmaster.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <sys/stat.h>
using namespace std;

int main()
{


    Grandmaster g;

    cout << "something" << endl;
    // g.mulaiTanpaBerkas();

    g.mulaiDenganBerkas("data/state.txt");

    // g.getAllPemainInfo();

    // g.getAllPemainInfo();

    // g.printAllPemain();
    g.list_bangunan[0]->printDetail();
    g.list_bangunan[1]->printDetail();
    g.list_bangunan[2]->printDetail();
    g.list_bangunan[3]->printDetail();



    // g.next();

    // g.next();

    // g.next();


    // g.operasi_perintah("PUNGUT_PAJAK");
    // g.printAllPemain();

        // cout << "sekarang giliran pemain indeks ke ";
        // g.next();

        // while(true){
        //     string command;
        //     cin >> command;
        //     if(command == "BREAK"){
        //         break;
        //     }
        //     g.operasi_perintah(command);
        // }
    // cout << "sekarang giliran pemain indeks ke ";
    // g.operasi_perintah("NEXT");
    // g.printAllPemain();
    // g.operasi_perintah("CETAK_PENYIMPANAN");
    // g.operasi_perintah("PUNGUT_PAJAK");
    // cout << "sekarang giliran pemain indeks ke ";
    // g.operasi_perintah("NEXT");
    // g.printAllPemain();
    // cout << "walikota sekarang adalah ";
    // g.printWalikota();
    // g.operasi_perintah("PUNGUT_PAJAK");
}