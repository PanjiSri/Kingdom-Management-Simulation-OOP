#ifndef INPUT_PLANT_HPP
#define INPUT_PLANT_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// struct Plant {
//     int id;
//     std::string name;
//     std::string type;
//     std::string material;
//     int value1;
//     int value2;
// };

class plant_file
{
private:
    int id;
    string name;
    string type;
    string material;
    int value1;
    int value2;
public: 
    void get_id();
    void get_name();
    void get_type();
    void get_material();
    void get_value1();
    void get_value2();
    void set_id(int id);
    void set_name(string name);
    void set_type(string type);
    void set_material(string material);
    void set_value1(int value1);
    void set_value2(int value2);
};

// main()
// {
//     std::ifstream file("plant.txt");
//     if (!file.is_open())
//     {
//         std::cerr << "Error opening file.\n";
//         return 1;
//     }

//     int sum = 0;
//     std::vector<Plant> plants;
//     Plant temp;
//     while (file >> temp.id >> temp.name >> temp.type >> temp.material >> temp.value1 >> temp.value2)
//     {
//         plants.push_back(temp);
//         sum += 1;
//         std::cout << sum << std::endl;
//     }

//     file.close();

//     // Print out the contents of the vector for verification
//     for (const auto &plant : plants)
//     {
//         std::cout << "ID: " << plant.id << ", Name: " << plant.name << ", Type: " << plant.type
//                   << ", Material: " << plant.material << ", Value1: " << plant.value1 << ", Value2: " << plant.value2 << std::endl;
//     }

//     return 0;
// }

#endif