#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main() {
    vector<string> kata;
    vector<int> sum;
    map<string, int> sign;
    for(int i = 0; i < 3; i++) {
        kata.push_back("Hai");
        sum.push_back(i);
        sign.insert({kata[i], sum[i]});
    }
    for(int i = 0; i < 3; i++) {
        
    }
}