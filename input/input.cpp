#include "header/input.hpp"

Line_Handler::Line_Handler(const string &id, const string &kode_huruf, const string &name, const string &type, int duration, int price)
    : id(id), kode_huruf(kode_huruf), name(name), type(type), duration(duration), price(price) {}

string Line_Handler::getId() const
{
    return id;
}

string Line_Handler::getKodeHuruf() const
{
    return kode_huruf;
}

string Line_Handler::getName() const
{
    return name;
}

string Line_Handler::getType() const
{
    return type;
}

int Line_Handler::getDurationToHarvest() const
{
    return duration;
}

int Line_Handler::getPrice() const
{
    return price;
}

Line_Handler_Produk::Line_Handler_Produk(const string &id, const string &kode_huruf, const string &name, const string &type, int duration, int price, const string &origin)
    : Line_Handler(id, kode_huruf, name, type, duration, price), origin(origin) {}

string Line_Handler_Produk::getOrigin() const
{
    return origin;
}
