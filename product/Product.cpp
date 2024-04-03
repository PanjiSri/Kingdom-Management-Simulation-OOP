#include "Product.hpp"

/*
    Default Constructor
*/
Product::Product()
    : code(""), name(""), type(""), origin(""), added_weight(0), price(0) {}

/*
    User-defined Constructor
*/
Product::Product(string code, string name, string type, string origin, int added_weight, int price)
    : code(code), name(name), type(type), origin(origin), added_weight(added_weight), price(price) {}

/*
    getter
*/
string Product::get_code()
{
    return code;
}

string Product::get_name()
{
    return name;
}

string Product::get_type()
{
    return type;
}

string Product::get_origin()
{
    return origin;
}

int Product::get_added_weight()
{
    return added_weight;
}

int Product::get_price()
{
    return price;
}

/*
    setter
*/
void Product::set_code(string &code)
{
    this->code = code;
}

void Product::set_name(string &name)
{
    this->name = name;
}

void Product::set_type(string &type)
{
    this->type = type;
}

void Product::set_origin(string &origin)
{
    this->origin = origin;
}

void Product::set_added_weight(int added_weight)
{
    this->added_weight = added_weight;
}

void Product::set_price(int price)
{
    this->price = price;
}
