#include "Toko.hpp"
// kalo mau coba run yang di bawah uncoment dulu
// #include "../Item/Item.cpp"
// #include "../Item/Hewan/Carnivore.cpp"
// #include "../Item/Hewan/Herbivore.cpp"
// #include "../Item/Hewan/Omnivore.cpp"
// #include "../Item/Hewan/Hewan.cpp"
// #include "../Item/Tanaman/Tanaman.cpp"
// #include "../Item/Produk/Produk.cpp"


Toko::Toko()
{
    // DUMMY DULU, GATAU FORMAT NYAMBUNGIN ITEM SAMA BACA CONFIG
    jenisBarang.push_back(new Tanaman(1, "TEK", "TEAK_TREE", "MATERIAL_PLANT", 15, 5));
    jenisBarang.push_back(new Tanaman(2, "SDT", "SANDALWOOD_TREE", "MATERIAL_PLANT", 10, 4));
    jenisBarang.push_back(new Tanaman(3, "ALT", "ALOE_TREE", "MATERIAL_PLANT", 9, 6));
    jenisBarang.push_back(new Tanaman(4, "IRN", "IRONWOOD_TREE", "MATERIAL_PLANT", 11, 5));
    jenisBarang.push_back(new Tanaman(5, "APL", "APPLE_TREE", "FRUIT_PLANT", 13, 4));
    jenisBarang.push_back(new Tanaman(6, "ORG", "ORANGE_TREE", "FRUIT_PLANT", 12, 4));
    jenisBarang.push_back(new Tanaman(7, "BNT", "BANANA_TREE", "FRUIT_PLANT", 16, 3));
    jenisBarang.push_back(new Tanaman(8, "GAV", "GUAVA_TREE", "FRUIT_PLANT", 14, 3));

    jenisBarang.push_back(new Herbivore(1, "COW", "COW", 20, 6));
    jenisBarang.push_back(new Herbivore(2, "SHP", "SHEEP", 15, 5));
    jenisBarang.push_back(new Herbivore(3, "HRS", "HORSE", 18, 5));
    jenisBarang.push_back(new Herbivore(4, "RBT", "RABBIT", 10, 4));
    jenisBarang.push_back(new Carnivore(5, "SNK", "SNAKE", 13, 4));
    jenisBarang.push_back(new Omnivore(6, "CHK", "CHICKEN", 12, 3));
    jenisBarang.push_back(new Omnivore(7, "DCK", "DUCK", 11, 3));

    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());
    // jenisBarang.push_back(new Produk());

    // jenisBarang.push_back(new Bangunan());
    // jenisBarang.push_back(new Bangunan());
    // jenisBarang.push_back(new Bangunan());
    // jenisBarang.push_back(new Bangunan());

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

Item* Toko::jual(int no, int kuantitas){
    if (no > jenisBarang.size())
    {
        throw NoBarangTidakValidException();
    }

    string barang = jenisBarang[no-1]->getKode();
    if (listBarang[barang] != -1)
    {
        if (listBarang[barang]-kuantitas >= 0)
        {
            listBarang[barang] = listBarang[barang] - kuantitas;    
        } else
        {
            throw StokTidakTersediaException();
        }
    }

    Item* jualan = jenisBarang[no-1];
    if (listBarang[barang] == 0)
    {
        jenisBarang.erase(jenisBarang.begin()+no-1);
    }
    return jualan;
}

void Toko::beli(Item* barang){
    if (listBarang[barang->getKode()] == 0)
    {
        jenisBarang.push_back(barang);
    }    
    if (listBarang[barang->getKode()] != -1)
    {
        listBarang[barang->getKode()] += 1;
    }    
}

void Toko::cetakListBarang(){
    cout << "Selamat datang di toko!!\nBerikut merupakan hal yang dapat Anda Beli\n";
    for (int i = 0; i < jenisBarang.size(); i++)
    {   
        if (listBarang[jenisBarang[i]->getKode()] == -1)
        {
            cout << (i+1) << ". "<< jenisBarang[i]->getNama() << " - " << jenisBarang[i]->getHarga() <<endl;
        } else 
        {
            cout << (i+1) << ". "<< jenisBarang[i]->getNama() << " - " << jenisBarang[i]->getHarga() << " (" << listBarang[jenisBarang[i]->getKode()] << ")" <<endl;
        }
    }  
}

// int main(){
//     Toko a;
//     Item* barang = new Produk(1, "TAW", "TEAK_WOOD", "PRODUCT_MATERIAL_PLANT", "TEAK_TREE", 0, 9);
//     a.beli(barang);
//     a.beli(barang);
//     a.beli(barang);
//     a.beli(barang);
//     a.beli(barang);
//     a.cetakListBarang();
//     a.jual(1,3);
//     a.cetakListBarang();
// }