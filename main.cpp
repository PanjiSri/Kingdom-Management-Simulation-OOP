#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Matriks {
    private:
        T** matriks;
        int baris;
        int kolom;
    public:
        Matriks(int baris, int kolom) {
            
            matriks = new T*[row];
            for (int i = 0; i < row; i++) {
                matriks[i] = new T[col];
            }

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    matriks[i][j] = "a ";
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
                    cout << matriks[i][j] << " ";
                }
                cout << endl;
            }
        }
};


int main() {
    Matriks<string> m(3,3);
    m.print();
    cout << m[1][1] << endl;
    return 0;

}