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
class MatriksPenyimpanan {
protected:
    vector<vector<T>> matriks;
    int baris;
    int kolom;

    void printKolomBorder() {
        cout << "      +";
        for (int i = 0; i < kolom; i++) {
            cout << "-----+";
        }
        cout << endl;
    }

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

    int getPetakKosong() {
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

    int getPetakTerisi() {
        return baris * kolom - getPetakKosong();
    }

    int getCountItem(string kode) {
    // mendapatkan jumlah item berdasarkan kode
        int count = 0;
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (matriks[i][j]->getKode() == kode) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    map<string, string> listProdukInMatriks() {
    // mendapatkan jenis-jenis produk yang ada di dalam matriks
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

    void deleteElement(string kode, int jumlah) {
    // menghapus elemen dari matriks berdasarkan kode dan jumlah
        int count = 0;
        for (int i = 0; i < this->baris; i++) {
            for (int j = 0; j < this->kolom; j++) {
                if (count >= jumlah) {
                    break;
                }
                
                if (matriks[i][j] != NULL && matriks[i][j]->getKode() == kode) {
                    delete matriks[i][j];
                    matriks[i][j] = NULL;
                    count++;
                }
            }
        }
    }

    // Other method
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

    void printWithColour() {
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

    bool isAdaMakanan(string tipe) {
    // cek apakah di dalam matriks ada item yang bisa dimakan
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (tipe == "HERBIVORE" || tipe == "OMNIVORE") {
                        if (matriks[i][j]->getTipe() == "PRODUCT_FRUIT_PLANT") {
                            return true;
                        }
                    }
                    else if (tipe == "CARNIVORE" || tipe == "OMNIVORE") {
                        if (matriks[i][j]->getTipe() == "PRODUCT_ANIMAL") {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool isAdaTanaman() {
    // cek apakah ada tanaman di di dalam matriks
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (matriks[i][j]->getTipe() == "MATERIAL_PLANT" || matriks[i][j]->getTipe() == "FRUIT_PLANT") {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isAdaHewan() {
    // cek apakah ada hewan di dalam matriks
        for (int i = 0; i < baris; i++) {
            for (int j = 0; j < kolom; j++) {
                if (matriks[i][j] != NULL) {
                    if (matriks[i][j]->getTipe() == "CARNIVORE" || matriks[i][j]->getTipe() == "OMNIVORE" || matriks[i][j]->getTipe() == "HERBIVORE") {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif