#ifndef INPUT_PLANT_HPP
#define INPUT_PLANT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../exception/header/exception.hpp"
using namespace std;


class plant_file
{
private:
    int id;
    string kode;
    string nama;
    string tipe;
    int value1;
    int value2;

public:
    int get_id();
    string get_kode();
    string get_nama();
    string get_tipe();
    int get_value1();
    int get_value2();
    void set_id(int id);
    void set_kode(string kode);
    void set_nama(string nama);
    void set_tipe(string tipe);
    void set_value1(int value1);
    void set_value2(int value2);
    void read_file(string path);
};

#endif