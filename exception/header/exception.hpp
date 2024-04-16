#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
#include <exception>
using namespace std;

// Berhubungan dengan file eksternal
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

class FolderTidakAdaException : public exception 
{
    const char *what() const throw()
    {
        return "Lokasi berkas tidak valid";
    }
};

// Berhubungan dengan peran
class NamaPemainTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "Nama tidak valid, sudah ada pemain dengan nama yang sama.";
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

// Berhubungan dengan item
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

class BangunTidakAdaResepBangunanException : public exception 
{
    const char *what() const throw()
    {
        return "Kamu tidak punya resep bangunan tersebut!";
    }
};

class BangunSumberDayaTidakCukupException : public exception 
{
    const char *what() const throw()
    {
        return "Kamu tidak punya sumber daya yang cukup!";
    }
};

// Berhubungan dengan toko
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

class TidakAdaBarangException : public exception
{
    const char *what() const throw()
    {
        return "Tidak ada barang di toko";
    }
};

// DLL
class LokasiTidakValidException : public exception
{
public:
    const char *what() const throw()
    {
        return "Lokasi tidak valid.";
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

#endif