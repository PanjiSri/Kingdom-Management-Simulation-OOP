#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<vector<string>> matriks;
    vector<string> temp;
    temp.push_back("a");
    temp.push_back("b");
    temp.push_back("c");
    temp.push_back("d");
    matriks.push_back(temp);
    vector<string> temp2;
    temp2.push_back("d");
    temp2.push_back("e");
    matriks.push_back(temp2);
    vector<string> temp3;
    temp3.push_back("z");
    matriks.push_back(temp3);

    for (int i = 0; i < matriks.size(); i++) {
        for (int j = 0; j < matriks[i].size(); j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}