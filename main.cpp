#include <vector>
#include <iostream>
#include <string>
using namespace std;
// 
// template <class T>
// class Matriks {
//     private:
//         T** matriks;
//         int baris;
//         int kolom;
//     public:
//         Matriks(int baris, int kolom) {
//             
//             matriks = new T*[row];
//             for (int i = 0; i < row; i++) {
//                 matriks[i] = new T[col];
//             }
// 
//             for (int i = 0; i < row; i++) {
//                 for (int j = 0; j < col; j++) {
//                     matriks[i][j] = "a ";
//                 }
//             }
//         }
// 
//         T* operator[](int idx) {
//             return matriks[idx];
//         }
// 
//         ~Matriks() {
//             delete[] matriks;
//         }
// 
//         void print() {
//             for (int i = 0; i < baris; i++) {
//                 for (int j = 0; j < kolom; j++) {
//                     cout << matriks[i][j] << " ";
//                 }
//                 cout << endl;
//             }
//         }
// };
// 
// 
// int main() {
//     Matriks<string> m(3,3);
//     m.print();
//     cout << m[1][1] << endl;
//     return 0;
// 
// }

// #include <vector>
// #include <iostream>
// #include <string>
// using namespace std;
// 
// class item {
//     protected:
//         int data;
//     public:
//         item() {
//             data = 0;
//         }
// 
//         item(int data) {
//             this->data = data;
//         }
// 
//         int get_data() {
//             return data;
//         }
// 
//         virtual void tampilkan_data() = 0;
// };
// 
// class tanaman : public item {
//     private:
//         float data_tanaman;
//     public:
//         tanaman() : item() {}
//         tanaman(float data_tanaman, int data) : item(data) {
//             this->data_tanaman = data_tanaman;
//         }
// 
//         void tampilkan_data() {
//             cout << "Data parent: " << get_data() << endl; // "Data parent: 1
//             cout << "Data child 1: " << data_tanaman << endl;
//         }
// };
// 
// class hewan : public item {
//     private:
//         string data_hewan;
//     public:
//         hewan() : item() {}
//         hewan(string data_hewan, int data) : item(data) {
//             this->data_hewan = data_hewan;
//         }
// 
//         void tampilkan_data() {
//             cout << "Data parent: " << get_data() << endl; // "Data parent: 2
//             cout << "Data child 2: " << data_hewan << endl;
//         }
// };

template <class T, int row, int col>
class Matriks {
    private:
        vector<vector<T>> matriks;
        int baris;
        int kolom;
    public:
        Matriks() {
            this->baris = row;
            this->kolom = col;
            matriks.resize(baris);
            for (int i = 0; i < baris; i++) {
                matriks[i].resize(kolom);
            }

            for (int i = 0; i < baris; i++) {
                for (int j = 0; j < kolom; j++) {
                    matriks[i][j] = (i + j) * 0.5;
                }
            }
        }

        vector<T>& operator[](int idx) {
            return matriks[idx];
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
//     vector<vector<int>> m(3, vector<int>(3, 0));
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             cout << m[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << m[1][1] << endl;
//     return 0;
    const int a = 3;
    const int b = 5;
    Matriks<float, a, b> m;
    m.print();
}