    // int get_id();
    // string get_name();
    // string get_type();
    // string get_material();
    // int get_value1();
    // int get_value2();
    // void set_id(int id);
    // void set_name(string name);
    // void set_type(string type);
    // void set_material(string material);
    // void set_value1(int value1);
    // void set_value2(int value2);
    // void read_file(string path);

#include "header/input.hpp"

int plant_file::get_id() {
    return id;
}

string plant_file::get_name() {
    return name;
}

string plant_file::get_type() {
    return type;
}

string plant_file::get_material() {
    return material;
}

int plant_file::get_value1() {
    return value1;
}

int plant_file::get_value2() {
    return value2;
}

void plant_file::set_id(int id) {
    this->id = id;
}

void plant_file::set_name(string name) {
    this->name = name;
}

void plant_file::set_type(string type) {
    this->type = type;
}

void plant_file::set_material(string material) {
    this->material = material;
}

void plant_file::set_value1(int value1) {
    this->value1 = value1;
}

void plant_file::set_value2(int value2) {
    this->value2 = value2;
}

void plant_file::read_file(string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return;
    }
}