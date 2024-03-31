#ifndef INPUT_PLANT_HPP
#define INPUT_PLANT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../../exception/header/exception.hpp"
using namespace std;

class line_handler
{
private:
    string id;
    string kode_huruf;
    string name;
    string type;
    int duration;
    int price;

public:
    line_handler(const string &id, const string &kode_huruf, const string &name, const string &type, int duration, int price)
        : id(id), kode_huruf(kode_huruf), name(name), type(type), duration(duration), price(price) {}

    string getId() const
    {
        return id;
    }

    string getKodeHuruf() const
    {
        return kode_huruf;
    }

    string getName() const
    {
        return name;
    }

    string getType() const
    {
        return type;
    }

    int getDurationToHarvest() const
    {
        return duration;
    }

    int getPrice() const
    {
        return price;
    }
};


class list_hasil_baca
{
private:
    vector<line_handler> list_objek;

public:
    void readPlanFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw FilePathTidakValid();
        }

        string id, kode_huruf, name, type;
        int duration_to_harvest, price;
        string line; 
        
        while (getline(file, line)) {
            stringstream ss(line);
            ss >> id >> kode_huruf >> name >> type >> duration_to_harvest >> price;
            list_objek.push_back(line_handler(id, kode_huruf, name, type, duration_to_harvest, price));
        }

        file.close();
    }

    line_handler getObjek(int index) const
    {
        return list_objek[index];
    }

    int getUkuran() const
    {
        return list_objek.size();
    }
};

#endif
