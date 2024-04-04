#include "Toko.hpp"

Toko::Toko()
{
    // Kode Tanaman
    jenisBarang.push_back("TEK");
    jenisBarang.push_back("SDT");
    jenisBarang.push_back("ALT");
    jenisBarang.push_back("IRN");
    jenisBarang.push_back("APL");
    jenisBarang.push_back("ORG");
    jenisBarang.push_back("BNT");
    jenisBarang.push_back("GAV");

    // Kode Hewan
    jenisBarang.push_back("COW");
    jenisBarang.push_back("SHP");
    jenisBarang.push_back("HRS");
    jenisBarang.push_back("RBT");
    jenisBarang.push_back("SNK");
    jenisBarang.push_back("CHK");
    jenisBarang.push_back("DCK");

    // Kode Produk
    jenisBarang.push_back("TAW");
    jenisBarang.push_back("SAW");
    jenisBarang.push_back("ALW");
    jenisBarang.push_back("IRW");
    jenisBarang.push_back("APP");
    jenisBarang.push_back("ORP");
    jenisBarang.push_back("BNP");
    jenisBarang.push_back("GAP");
    jenisBarang.push_back("COM");
    jenisBarang.push_back("SHM");
    jenisBarang.push_back("HRM");
    jenisBarang.push_back("RBM");
    jenisBarang.push_back("SNM");
    jenisBarang.push_back("CHM");
    jenisBarang.push_back("DCM");
    jenisBarang.push_back("CHE");
    jenisBarang.push_back("DCE");

    // Kode Bangunan
    jenisBarang.push_back("SMH");
    jenisBarang.push_back("MDH");
    jenisBarang.push_back("LRH");
    jenisBarang.push_back("HTL");

    // Kode Tanaman
    listBarang["TEK"] = -1;
    listBarang["SDT"] = -1;
    listBarang["ALT"] = -1;
    listBarang["IRN"] = -1;
    listBarang["APL"] = -1;
    listBarang["ORG"] = -1;
    listBarang["BNT"] = -1;
    listBarang["GAV"] = -1;

    // Kode Hewan
    listBarang["COW"] = -1;
    listBarang["SHP"] = -1;
    listBarang["HRS"] = -1;
    listBarang["RBT"] = -1;
    listBarang["SNK"] = -1;
    listBarang["CHK"] = -1;
    listBarang["DCK"] = -1;

    // Kode Produk
    listBarang["TAW"] = 0;
    listBarang["SAW"] = 0;
    listBarang["ALW"] = 0;
    listBarang["IRW"] = 0;
    listBarang["APP"] = 0;
    listBarang["ORP"] = 0;
    listBarang["BNP"] = 0;
    listBarang["GAP"] = 0;
    listBarang["COM"] = 0;
    listBarang["SHM"] = 0;
    listBarang["HRM"] = 0;
    listBarang["RBM"] = 0;
    listBarang["SNM"] = 0;
    listBarang["CHM"] = 0;
    listBarang["DCM"] = 0;
    listBarang["CHE"] = 0;
    listBarang["DCE"] = 0;

    // Kode Bangunan
    listBarang["SMH"] = 0;
    listBarang["MDH"] = 0;
    listBarang["LRH"] = 0;
    listBarang["HTL"] = 0;  
}

Toko::~Toko()
{
}

void Toko::jual(string kode){
    // if (listBarang[kode] == 0)
    // {
    //     throw StokHabisException();
    // }
    
    if (listBarang[kode] > 0)
    {
        listBarang[kode] -= 1;    
    }
    
}

void Toko::beli(string kode){
    if (listBarang[kode] != -1)
    {
        listBarang[kode] += 1;
    }
    
}

// harga masih dummy
void Toko::cetakListBarang(){
    int no = 1;
    cout << "Selamat datang di toko!!\nBerikut merupakan hal yang dapat Anda Beli\n";
    for (int i = 0; i < jenisBarang.size(); i++)
    {   
        if (listBarang[jenisBarang[i]] == -1)
        {
            cout << no << ". "<< jenisBarang[i] << " - " << 10 <<endl;
            no++;
        } else if (listBarang[jenisBarang[i]] != 0)
        {
            cout << no << ". "<< jenisBarang[i] << " - " << 10 << " (" << listBarang[jenisBarang[i]] << ")" <<endl;
            no++;
        }
    }
    
}

// int main(){
//     Toko a;
//     a.beli("COW");
//     a.beli("COM");
//     a.beli("COM");
//     a.beli("COM");
//     a.beli("COM");
//     a.jual("COM");
//     a.cetakListBarang();
// }