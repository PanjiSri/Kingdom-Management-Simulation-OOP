#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include <vector>
#include <iostream>
#include <string>
#include "../hewan/Carnivore.hpp"
#include "../hewan/Omnivore.hpp"
using namespace std;

template <class T, int row, int col, int type>
class Matriks {
    private:
        T** matriks;
        int baris;
        int kolom;
        int tipe;
    public:
        Matriks() {
            baris = row;
            kolom = col;
            
            matriks = new T*[row];
            for (int i = 0; i < row; i++) {
                matriks[i] = new T[col];
            }
            if(tipe == 0) {
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        matriks[i][j] = new Carnivore(); 
                    }
                }
            }
            else {
                for(int i = 0; i < row; i++) {
                    for(int j = 0; j < col; j++) {
                        matriks[i][j] = new Omnivore(); 
                    }
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
                    cout << " "<< matriks[i][j]->getType() << " ";
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