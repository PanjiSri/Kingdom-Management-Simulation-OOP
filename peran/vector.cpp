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

template <class T, int row, int col>
class Matriks {
    public:
        T** matriks;
        int baris;
        int kolom;
    public:
        Matriks() {
            baris = row;
            kolom = col;
            matriks = new T*[baris];
            for (int i = 0; i < baris; i++) {
                matriks[i] = new T[kolom];
            }
                for(int i = 0; i < baris; i++) {
                    for(int j = 0; j < kolom; j++) {
                        matriks[i][j] = NULL; 
                    }
                }
        }

        T* operator[](int idx) {
            return matriks[idx];
        }

        ~Matriks() {
            delete [] matriks;
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
                for(int j = 0;j < kolom; j++) {
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

        Matriks<T,row,col> operator= (const Matriks<T,row,col>& other) {
            this->matriks = other.matriks;
            this->baris = other.baris;
            this->kolom = other.kolom;
            return *this;
        }
        
        Matriks<T,row,col> operator+(T produk) {
            int isi = 0;
            for(int i = 0; i < this->baris; i++) {
                for(int j = 0; j < this->kolom; j++) {
                    if ((this->matriks[i][j]->getKode() == "XXX") && (isi == 0)) {
                        this->matriks[i][j] = produk;
                        isi += 1;
                        cout << "SEMPAT" <<endl;
                    }
                }
            }
            this->print();
            return *this;
        }
};

int main() {
    Matriks<Tanaman*, 8, 8> a;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            a[i][j] = new Tanaman();
        }
    }
    Tanaman* x = new Tanaman(1, "HAI", "HAI", "HAI", 2,3);
    a = a + x;
    cout << a.getbaris() << endl;
    cout << a.matriks[0][0]->getKode() << endl;
}
// class MatriksHewan: public Matriks<Tanaman*  {
//     // public:
//     //     Matriks
// }

#endif