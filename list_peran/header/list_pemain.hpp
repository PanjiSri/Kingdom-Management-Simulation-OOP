#ifndef LIST_PERAN_HPP
#define LIST_PERAN_HPP

// #include "dummy.hpp"
#include "../../peran/peran.hpp"
#include <vector>
using namespace std;

class ListPemain
{
private:
    // Asumsi sementara list_of_pemain udah sesuai urutak leksikografis
    // Method untuk mengurutkan akan dibuat nanti
    vector<Peran*> list_of_pemain;
    int banyak_pemain;

public:
    ListPemain();
    ListPemain(const ListPemain& other); 
    ~ListPemain();
    void tambah_pemain();//aku tidak tahu parameter yang cocok untuk method ini

};


#endif