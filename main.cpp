#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << i;
        int x;
        cin >> x;
        if (x < 0) {
            i--;
        }
    }
    return 0;
}