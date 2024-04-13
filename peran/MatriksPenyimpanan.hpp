#ifndef __MATRIKS_PENYIMPANAN_HPP__
#define __MATRIKS_PENYIMPANAN_HPP__

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
using namespace std;

template <class T>
class MatriksPenyimpanan {
    private:
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
            for(int i = 0; i < baris; i++) {
                matriks[i].resize(kolom);
            }

            for(int i = 0; i < baris; i++) {
                for(int j = 0; j < kolom; j++) {
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

        vector<T>& operator[] (int idx) {
            return matriks[idx];
        }

        // Setter
        void setElement(int i, int j, T elem) {
            matriks[i][j] = elem;
        }

        void operator+= (T elem) {
            for(int i = 0; i < baris; i++) {
                for(int j = 0; j < kolom; j++) {
                    if(matriks[i][j] == NULL) {
                        matriks[i][j] = elem;
                        return;
                    }
                }
            }
        }

        // Other method
        void printKolomBorder() {
            cout << "      +";
            for(int i = 0; i < kolom; i++) {
                cout << "-----+";
            }
            cout << endl;
        }
        
        void print() {
            int asciinum = 65;

            cout << "       ";
            for(int i = 0; i < kolom; i++) {
                cout << "  " << (char)(asciinum+i) << "   ";
            }
            cout << endl;
            
            printKolomBorder();
            for (int i = 0; i < baris; i++) {
                if (i < 9) {
                    cout << "  0" << i+1 << "  |"; 
                } else {
                    cout << "  " << i+1 << "  |";
                }

                for (int j = 0; j < kolom; j++) {
                    if (matriks[i][j] == NULL) {
                        cout << "     |";
                    }
                    else {
                        cout << " "<< matriks[i][j]->getKode() << " |";
                    }
                }
                cout << endl;
                printKolomBorder();
            }
        }

        int getValue() {
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

        bool isEmpety() {
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
            for (int i = 0; i < baris; i++) {
                for (int j = 0; j < kolom; j++) {
                    if (matriks[i][j] == NULL) {
                        return false;
                    }
                }
            }
            return true;
        }
};

#endif