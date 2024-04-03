#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include "vector"
#include <iostream>
using namespace std;

template<class T, int baris, int kolom>
class vector2{
    public:
        T** matriks;
        int row;
        int column;
    public: 
        vector2() {
            matriks = new T*[baris];
            for(int i = 0; i < baris; i++) {
                matriks[baris] = new T[kolom];
            }
            for(int i = 0; i < baris; i++) {
                for(int j = 0; j < kolom; j++) {
                    matriks[i][j] = kolom;
                }
            }
            row = baris;
            column = kolom;
        }
        T* operator[](int idx) {
            return this->matriks[idx];
        }
};

#endif