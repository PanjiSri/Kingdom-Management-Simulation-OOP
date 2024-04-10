#ifndef VECTOR_HPP_
#define VECTOR_HPP_

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
class MatriksHewan {
    private:
        T** matriks;
        int baris;
        int kolom;
        int tipe;
    public:
        MatriksHewan() {
            baris = 8;
            kolom = 8;
            
            matriks = new T*[baris];
            for (int i = 0; i < baris; i++) {
                matriks[i] = new T[kolom];
            }
                for(int i = 0; i < baris; i++) {
                    for(int j = 0; j < kolom; j++) {
                        matriks[i][j] = new Carnivore(); 
                    }
                }
        }

        T* operator[](int idx) {
            return matriks[idx];
        }

        ~MatriksHewan() {
            delete[] matriks;
        }

        void print() {
            int asciinum = 65;
            cout << "     ";
            for(int i = 0; i < baris; i++) {
                cout << "  " << (char)(asciinum+i) << "  ";
            }
            cout << endl;
            for (int i = 0; i < baris; i++) {
                if(i < 9) {
                    cout << "  0" << i+1 << " "; 
                }
                for (int j = 0; j < kolom; j++) {
                    cout << " "<< matriks[i][j]->getKode() << " ";
                }
                cout << endl;
            }
        }

        int getValue() {
            int uang = 0;
            for(int i = 0; i < baris; i++) {
                for(int j = 0; < kolom; j++) {
                    uang += matriks[i][j]->getHarga();
                }
            }
            return uang;
        }

        int getbaris() {
            return this->baris;
        }

        int getkolom() {
            return this->kolom;
        }
};

template <class T, int row, int col>
class MatriksTumbuhan {
    private:
        T** matriks;
        int baris;
        int kolom;
        int tipe;
    public:
        MatriksTumbuhan() {
            baris = 8;
            kolom = 8;
            
            matriks = new T*[baris];
            for (int i = 0; i < baris; i++) {
                matriks[i] = new T[kolom];
            }
                for(int i = 0; i < baris; i++) {
                    for(int j = 0; j < kolom; j++) {
                        matriks[i][j] = new Tanaman(); 
                    }
                }
        }

        T* operator[](int idx) {
            return matriks[idx];
        }

        ~MatriksTumbuhan() {
            delete[] matriks;
        }

        void print() {
            int asciinum = 65;
            cout << "     ";
            for(int i = 0; i < baris; i++) {
                cout << "  " << (char)(asciinum+i) << "  ";
            }
            cout << endl;
            for (int i = 0; i < baris; i++) {
                if(i < 9) {
                    cout << "  0" << i+1 << " "; 
                }
                for (int j = 0; j < kolom; j++) {
                    cout << " "<< matriks[i][j]->getKode() << " ";
                }
                cout << endl;
            }
        }

        int getValue() {
            int uang = 0;
            for(int i = 0; i < baris; i++) {
                for(int j = 0; < kolom; j++) {
                    uang += matriks[i][j]->getHarga();
                }
            }
            return uang;
        }

        int getbaris() {
            return this->baris;
        }

        int getkolom() {
            return this->kolom;
        }
};

// class MatriksHewan: public Matriks<Tanaman*  {
//     // public:
//     //     Matriks
// }

#endif