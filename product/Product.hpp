#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

using std::string;

class Product
{
private:
    string code;
    string name;
    string type;
    string origin;
    int added_weight;
    int price;

public:
    Product();
    Product(string, string, string, string, int, int);

    string get_code();
    string get_name();
    string get_type();
    string get_origin();
    int get_added_weight();
    int get_price();
    void set_code(string &);
    void set_name(string &);
    void set_type(string &);
    void set_origin(string &);
    void set_added_weight(int);
    void set_price(int);
};

#endif
