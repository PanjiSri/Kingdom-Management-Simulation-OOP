#include "grandmaster/Grandmaster.hpp"
#include "grandmaster/Grandmaster.cpp"
#include "input/header/input.hpp"
#include "input/input.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    Grandmaster g;

    g.loadallconfig();
    // ifstream file("folder/animal.txt");

    // if (!file.is_open())
    // {
    //     cout << "gak kebaca" << endl;
    // }
    // else{cout << "aman" << endl;
    // }
    // g.loadallconfig("../folder/animal.txt", "../folder/plant.txt", "../folder/product.txt");

    cout << "config tanaman" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << g.getJenisTanaman(i).getId() << " ";
        cout << g.getJenisTanaman(i).getKodeHuruf() << " ";
        cout << g.getJenisTanaman(i).getName() << " ";
        cout << g.getJenisTanaman(i).getType() << " ";
        cout << g.getJenisTanaman(i).getDurationToHarvest() << " ";
        cout << g.getJenisTanaman(i).getPrice() << " ";
        cout << endl;
    }

    cout << "config hewan" << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << g.getJenisHewan(i).getId() << " ";
        cout << g.getJenisHewan(i).getKodeHuruf() << " ";
        cout << g.getJenisHewan(i).getName() << " ";
        cout << g.getJenisHewan(i).getType() << " ";
        cout << g.getJenisHewan(i).getDurationToHarvest() << " ";
        cout << g.getJenisHewan(i).getPrice() << " ";
        cout << endl;
    }

    cout << "config produk" << endl;

    for (int i = 0; i < 17; i++)
    {
        cout << g.getJenisProduk(i).getId() << " ";
        cout << g.getJenisProduk(i).getKodeHuruf() << " ";
        cout << g.getJenisProduk(i).getName() << " ";
        cout << g.getJenisProduk(i).getType() << " ";
        cout << g.getJenisProduk(i).getOrigin() << " ";
        cout << g.getJenisProduk(i).getDurationToHarvest() << " ";
        cout << g.getJenisProduk(i).getPrice() << " ";
        cout << endl;
    }

    cout << "config misc" << endl;
    cout << g.getUangMenang() << endl;;
    cout << g.getBeratMenang() << endl;
    cout << g.getBesarPenyimpanan(0) << " " << g.getBesarPenyimpanan(1) << endl;
    cout << g.getBesarLahan(0) << " " << g.getBesarLahan(1) << endl;
    cout << g.getBesarPeternakan(0) << " " << g.getBesarPeternakan(1) << endl;
}