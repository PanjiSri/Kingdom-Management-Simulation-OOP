#ifndef LIST_PERAN_HPP
#define LIST_PERAN_HPP

#include "pemain.hpp"
#include <vector>
using namespace std;

class ListPemain
{
private:
    // Asumsi sementara list_of_pemain udah sesuai urutak leksikografis
    // Method untuk mengurutkan akan dibuat nanti
    vector<Pemain> list_of_Pemain;
    int banyak_pemain;

public:
    ListPemain();
    ListPemain(int banyak_pemain);
    ListPemain(const ListPemain& list_of_pemain); 
    ~ListPemain();
    void getPemain(int index);
    void setPemain(int index);
};

#endif