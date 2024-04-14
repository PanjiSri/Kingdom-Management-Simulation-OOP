#include <iostream>
#include <string>
#include <vector>
using namespace std;

void insert_lexicographical_order(string v, vector<string> &v2)
{
    bool is_in = false;
    for (int i = 0; i < v2.size(); i++)
    {
        // Jika elemen sudah ada di dalam vektor, berhenti loop
        if (v == v2[i]) {
            is_in = true;
            break;
        }
        if (v < v2[i])
        {
            v2.insert(v2.begin() + i, v);
            is_in = true;
            break;
        }
    }

    // Hanya tambahkan elemen jika belum ada di dalam vektor
    if(!is_in) {v2.push_back(v);}
}

int main()
{
    vector<string> v = {"x", "y", "z"};

    insert_lexicographical_order("y", v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}