#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include <vector>
#include <iostream>
#include <string>
#include "../hewan/Carnivore.hpp"
using namespace std;

template <class T, int row, int col>
class Matriks {
    private:
        T** matriks;
        int baris;
        int kolom;
    public:
        Matriks() {
            baris = row;
            kolom = col;
            
            matriks = new T*[row];
            for (int i = 0; i < row; i++) {
                matriks[i] = new T[col];
            }

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    matriks[i][j] = new Carnivore();
                }
            }
        }

        T* operator[](int idx) {
            return matriks[idx];
        }

        ~Matriks() {
            delete[] matriks;
        }

        void print() {
            for (int i = 0; i < baris; i++) {
                for (int j = 0; j < kolom; j++) {
                    cout << matriks[i][j]->getKode() << " ";
                }
                cout << endl;
            }
        }

        int getbaris() {
            return this->baris;
        }

        int getkolom() {
            return this->kolom;
        }
};

#endif