#ifndef __MATRIKS_PENYIMPANAN_HPP__
#define __MATRIKS_PENYIMPANAN_HPP__

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "../Pcolor/pcolor.h"
using namespace std;

template <class T>
class MatriksPenyimpanan
{
protected:
    vector<vector<T>> matriks;
    int baris;
    int kolom;

public:
    // Constructor
    MatriksPenyimpanan() {
        baris = 0;
        kolom = 0;
    }

    ~MatriksPenyimpanan() {}

    // Setter
    void setUkuran(int baris, int kolom) {
        this->baris = baris;
        this->kolom = kolom;

        matriks.resize(baris);
        for (int i = 0; i < baris; i++) {
            matriks[i].resize(kolom);
        }

        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                matriks[i][j] = NULL;
            }
        }
    }

    // Getter
    int getBaris() {
        return this->baris;
    }

    int getKolom() {
        return this->kolom;
    }

    vector<T> &operator[](int idx) {
        return matriks[idx];
    }

    // Setter
    void setElement(int i, int j, T elem) {
        matriks[i][j] = elem;
    }

    void operator+=(T elem) {
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] == NULL) {
                    matriks[i][j] = elem;
                    return;
                }
            }
        }
    }

    // Other method
    void printKolomBorder() {
        cout << "      +";
        for (int i = 0; i < kolom; i++) {
            cout << "-----+";
        }
        cout << endl;
    }

    void print() {
        // print matriks tanpa warna pada kode
        int ASCII_NUM = 65;

        // print koordinat kolom
        cout << "       ";
        for (int i = 0; i < kolom; i++) {
            cout << "  " << (char)(ASCII_NUM + i) << "   ";
        }
        cout << endl;

        printKolomBorder();
        for (int i = 0; i < baris; i++) {
            // print koordinat baris
            if (i < 9) {
                cout << "  0" << i + 1 << "  |";
            }
            else {
                cout << "  " << i + 1 << "  |";
            }

            // print isi matriks
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] == NULL) {
                    cout << "     |";
                }
                else {
                    cout << " " << matriks[i][j]->getKode() << " |";
                }
            }
            cout << endl;
            printKolomBorder();
        }
    }

    void printlahan() {
        // print matriks dengan warna
        int ASCII_NUM = 65;

        // print koordinat kolom
        cout << "       ";
        for (int i = 0; i < kolom; i++) {
            cout << "  " << (char)(ASCII_NUM + i) << "   ";
        }
        cout << endl;

        printKolomBorder();
        for (int i = 0; i < baris; i++) {
            // print koordinat baris
            if (i < 9) {
                cout << "  0" << i + 1 << "  |";
            }
            else {
                cout << "  " << i + 1 << "  |";
            }

            // print isi matriks
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] == NULL) {
                    cout << "     |";
                }
                else {
                    cout << " ";
                    string kata = matriks[i][j]->getKode();
                    cout << kata << endl;
                    if (matriks[i][j]->isSiapPanen() == true)
                    {
                        for (int k = 0; k < kata.size(); k++)
                        {
                            print_green(kata[k]);
                        }
                    }
                    else {
                        for (int k = 0; k < kata.size(); k++) {
                            print_red(kata[k]);
                        }
                    }
                    cout << " |";
                }
            }
            cout << endl;
            printKolomBorder();
        }
    }

    map<string, string> listProdukInMatriks() {
        // mendapatkan hewan/tanaman yang siap panen beserta jumlahnya
        map<string, string> listProduk;
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (listProduk.size() == 0) {
                        listProduk.insert({matriks[i][j]->getKode(), matriks[i][j]->getNama()});
                    }
                    else {
                        if (listProduk.count(matriks[i][j]->getNama())) {
                            listProduk[matriks[i][j]->getKode()] += " " + matriks[i][j]->getNama();
                        }
                        else {
                            listProduk.insert({matriks[i][j]->getKode(), matriks[i][j]->getNama()});
                        }
                    }
                }
            }
        }
        return listProduk;
    }
    

    map<string, int> listSiapPanen() {
        // mendapatkan hewan/tanaman yang siap panen beserta jumlahnya
        map<string, int> siappanen;
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (matriks[i][j]->isSiapPanen() == true) {
                        if (siappanen.size() == 0) {
                            siappanen.insert({matriks[i][j]->getNama(), 1});
                        }
                        else {
                            if (siappanen.count(matriks[i][j]->getKode())) {
                                siappanen[matriks[i][j]->getNama()] += 1;
                            }
                            else {
                                siappanen.insert({matriks[i][j]->getNama(), 1});
                            }
                        }
                    }
                }
            }
        }
        return siappanen;
    }

    // bool checkItemBuilding(map<string, int> material)
    // {
    //     // menentukan apakah jumlah inventory saat ini mencukupi untuk membangun sebuah bangunan
    //     map<string, int> material_di_invent;
    //     material_di_invent.insert({"TAW", 0});
    //     material_di_invent.insert({"SAW", 0});
    //     material_di_invent.insert({"ALW", 0});
    //     material_di_invent.insert({"IRW", 0});

    //     for (int i = 0; i < baris; i++)
    //     {
    //         for (int j = 0; j < kolom; j++)
    //         {
    //             if (matriks[i][j] != NULL)
    //             {
    //                 if (matriks[i][j]->getKode() == ("TAW" || "SAW" || "ALW" || "IRW"))
    //                 {
    //                     material_di_invent[matriks[i][j]->getKode()] += 1;
    //                 }
    //             }
    //         }
    //     }

    //     // cek apakah jumlah inventory mencukupi
    //     bool mencukupi = true;
    //     bool cetak_kalimat = true;
    //     for (auto i = material.begin(); i != material.end(); i++)
    //     {
    //         if (material_di_invent[i->first] < i->second)
    //         {
    //             if (cetak_kalimat)
    //             {
    //                 cout << "Kamu tidak memiliki cukup material untuk membangun bangunan" << endl;
    //                 cetak_kalimat = false;
    //             }
    //             cout << "Material " << i->first << " masih perlu " << i->second - material_di_invent[i->first] << " lagi" << endl;
    //             mencukupi = false;
    //         }
    //     }
    //     return mencukupi;
    // }

    int getValue() {
        // mendapatkan total uang dari seluruh item yang ada di dalam matriks
        int uang = 0;
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    uang += matriks[i][j]->getHarga();
                }
            }
        }
        return uang;
    }

    int getLahanKosong() {
        // mendapatkan jumlah petak matriks yang kosong
        int empty = 0;
        for (int i = 0; i < this->getBaris(); i++) {
            for (int j = 0; j < this->getKolom(); j++) {
                if (matriks[i][j] == NULL) {
                    empty += 1;
                }
            }
        }
        return empty;
    }

    bool isEmpety() {
        // cek apakah matriks kosong
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isFull() {
        // cek apakah matriks penuh
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] == NULL) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAdaMakanan() {
        // cek apakah di dalam matriks ada item yang bisa dimakan
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (matriks[i][j]->getTipe() == "PRODUCT_FRUIT_PLANT" || matriks[i][j]->getTipe() == "PRODUCT_ANIMAL") {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif