#ifndef INPUT_PLANT_HPP
#define INPUT_PLANT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../../exception/header/exception.hpp"
using namespace std;

class Line_Handler
{
protected:
    string id;
    string kode_huruf;
    string name;
    string type;
    int duration;
    int price;

public:
    Line_Handler(const string &id, const string &kode_huruf, const string &name, const string &type, int duration, int price);

    string getId() const;

    string getKodeHuruf() const;

    string getName() const;

    string getType() const;

    int getDurationToHarvest() const;

    int getPrice() const;
};

class Line_Handler_Produk : public Line_Handler
{
private:
    string origin;

public:
    Line_Handler_Produk(const string &id, const string &kode_huruf, const string &name, const string &type, int duration, int price, const string &origin);

    string getOrigin() const;
};

#endif
