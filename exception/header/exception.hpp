#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
#include <exception>
using namespace std;

class FilePathTidakValid : public exception
{
public:
    const char *what() const throw()
    {
        return "Path File Tidak Valid.";
    }
};

class ConfigTidakValid : public exception
{
public:
    const char *what() const throw()
    {
        return "Config Tidak Valid.";
    }
};

class NamaPemainTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "Nama tidak valid, sudah ada pemain dengan nama yang sama.";
    }
};

class BukanMakananException : public exception
{
public:
    const char *what() const throw()
    {
        return "Itu bukan makanan.";
    }
};

class CarnivoraTidakMakanSayurException : public exception
{
public:
    const char *what() const throw()
    {
        return "Carnivore hanya memakan produk hewan.";
    }
};

class HerbivoraTidakMakanDagingException : public exception
{
public:
    const char *what() const throw()
    {
        return "Herbivore hanya memakan produk tanaman.";
    }
};

class MaterialPlantTidakDimakanException : public exception
{
public:
    const char *what() const throw()
    {
        return "Produk tanaman material tidak bisa dimakan.";
    }
};

class StokTidakTersediaException : public exception
{
public:
    const char *what() const throw()
    {
        return "Stok barang tidak mencukupi.";
    }
};

class NoBarangTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "No barang tidak valid.";
    }
};

class LokasiTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "Lokasi tidak valid.";
    }
};
class HanyaWalikotaException : public exception
{
public:
    const char *what() const throw()
    {
        return "Sayang sekali operasi ini hanya bisa dilakukan oleh walikota";
    }
};

class CommandTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "Command tidak valid";
    }
};

class PetaniPeternakTidakBisaJualBangunanException : public exception
{
public:
    const char *what() const throw()
    {
        return "Anda tidak bisa menjual bangunan";
    }
};

class WalikotaTidakBisaBeliBangunanException : public exception
{
public:
    const char *what() const throw()
    {
        return "Anda tidak bisa membeli bangunan";
    }
};

class FolderTidakAdaException : public exception {
    const char *what() const throw()
    {
        return "Lokasi berkas tidak valid";
    }
};

class BangunTidakAdaResepBangunan : public exception {
    const char *what() const throw()
    {
        return "Kamu tidak punya resep bangunan tersebut!";
    }
};

class BangunSumberDayaTidakCukup : public exception {
    const char *what() const throw()
    {
        return "Kamu tidak punya sumber daya yang cukup!";
    }
};

class TidakAdaBarangException : public exception{
    const char *what() const throw()
    {
        return "Tidak ada barang di toko";
    }
};

#endif
