#include <string>
#include <iostream>
using namespace std;

int main() {
    string a = "teak_wood";
    cout << a << endl;
    a.erase(a.length()-5);
    cout << a << endl;
    a += "_plank";
    cout << a << endl;

    return 0;
}