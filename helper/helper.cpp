#include "helper.hpp"
#include "iostream"
#include "vector"
using namespace std;

vector<int> outside_function::parse(string idx) {
    for(int i = 0; i < idx.length(); i++) {
        cout << idx[1] << endl;
    }
}