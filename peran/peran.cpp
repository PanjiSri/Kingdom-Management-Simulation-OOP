#include "peran.hpp"
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#include "../Item/Hewan/Carnivore.hpp"
#include "../Item/Hewan/Omnivore.hpp"
#include "../Item/Hewan/Herbivore.hpp"
#include "../Item/Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Item/Produk/Produk.hpp"
#include "../Item/Tanaman/Tanaman.hpp"
#include "../Item/Bangunan/Bangunan.hpp"
#include "../Pcolor/pcolor.h"
#include "MatriksPenyimpanan.hpp"

/*
 *  Class Peran
 *   
 */ 
Peran::Peran() {
    this->username = " ";
    this->gulden = 50;
    this->berat = 40;
} 

Peran::Peran(string username, int row, int col) {
    this->username = username;
    this->gulden = 50;
    this->berat = 40;
    penyimpanan.setUkuran(row, col);
}

Peran::Peran(string username, int berat, int gulden, int row, int col) {
    this->username = username;
    this->gulden = gulden;
    this->berat = berat;
    penyimpanan.setUkuran(row, col);
}

Peran::~Peran() {}

Peran& Peran::operator= (const Peran& other) {
    gulden = other.gulden;
    berat = other.berat;
    penyimpanan = other.penyimpanan;
    username = other.username;
    return *this;
}

int Peran::getGulden() {
    return this->gulden;
}

int Peran::getBerat() {
    return this->berat;
}

string Peran::getUname() {
    return this->username;
}

void Peran::printPenyimpanan() {
    cout << "=================== PENYIMPANAN ===================" << endl;
    penyimpanan.print();
}

void Peran::playerMakan() {
    printPenyimpanan();
    if (penyimpanan.isEmpety()) {
        cout << "Tidak ada yang bisa kamu makan disini" << endl;
    } else {
        Item* x;
        string kode;
        cout << "Ambil makanan dalam inventory mu: ";
        cin >> kode;
        vector<int> index = parse(kode);
        x = penyimpanan[index[1]][index[0]];
        
        if (x == NULL) {
            cout << "Tidak ada apa-apa di di sana" << endl;
        } else if ((x->getTipe() == "PRODUCT_ANIMAL") || (x->getTipe() == "PRODUCT_FRUIT_PLANT")) {
            tambahBerat(x->getTambahan());
            penyimpanan[index[1]][index[0]] = NULL;
            cout << "Berat badanmu naik jadi " << berat << endl;
        } else {
            cout << "Hei, yakin kamu mau makan itu???" << endl;
        }
    }
}

void Peran::tambahBerat(int berat_tambahan) {
    berat += berat_tambahan;
}

void Peran::addPenyimpanan(Item* item) {
    printPenyimpanan();
    string idx;
    cout << "Masukkan lokasi yang diinginkan: ";
    cin >> idx;
    vector<int> lokasi = parse(idx);
    if (penyimpanan[lokasi[1]][lokasi[0]] != NULL) {
        cout << "Cari tempat yang kosong" << endl;
    }
    else {
        penyimpanan[lokasi[1]][lokasi[0]] = item;
    }
}

void Peran::addPenyimpananFile(string name, vector<Item*> listItem) {
    Item* item;
    for(int i = 0; i < listItem.size(); i++) {
        if(listItem[i]->getNama() == name) {
            item = listItem[i];
        }
    }
    penyimpanan += item;
}

vector<string> Peran::getSemuaItem(){
    vector<string> temp;

    for(int i = 0; i < penyimpanan.getBaris(); i++) {
        for(int j = 0; j < penyimpanan.getKolom(); j++) {
            if(penyimpanan[j][i] != NULL) {
                temp.push_back(penyimpanan[j][i]->getNama());
            }
        }
    }
    return temp;
}



vector<int> Peran::parse(string idx) {
    vector<int> indeks;
    indeks.push_back(((int)idx[0])-65);
    indeks.push_back((int)(idx[2]-'0')-1);
    return indeks;
}
// belum handle error
void Peran::menjual(Toko* toko){
    cout << "Berikut merupakan penyimpanan Anda\n";
    printPenyimpanan();
    cout << "Silahkan pilih petak yang ingin Anda jual!\nPetak : ";
    string indeksinvent;
    cin >> indeksinvent;
    vector<int> idx = parse(indeksinvent);
    Item* barang;
    barang = penyimpanan[idx[1]][idx[0]];
    // ketika peran menjual berarti toko membeli kan,
    // make sense ga penamaannya atau malah bikin bingung
    toko->beli(barang);
    gulden = gulden + barang->getHarga();
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah "<< barang->getHarga() << " gulden!\n";
    penyimpanan[idx[1]][idx[0]] = NULL;
}

// belum selesai
void Peran::membeli(Toko* toko){
    toko->cetakListBarang();
    int noBarang;
    int kuantitas;
    cout << "\nUang Anda : " << gulden << endl;
    cout << "Slot Penyimpanan tersedia : " << penyimpanan.getLahanKosong() << endl;
    cout << "Barang ingin dibeli : "; 
    cin >> noBarang;
    cout << "\nKuantitas : ";
    cin >> kuantitas;
    // belum divalidasi
    try {
        Item* item = toko->jual(noBarang, kuantitas);
        for(int i = 0; i < kuantitas; i++) {
            penyimpanan += item;
        }
        gulden -= item->getHarga()*kuantitas;
    }
    catch (StokTidakTersediaException e) {
        cout << e.what() << endl;
    }
    // addpenyimpanan(item);
    // harusnya gini sih
}


/*
 *  Class Walikota
 *   
 */
Walikota::Walikota (string username, int row, int col): Peran(username, row, col) {
    peran_pemain = "walikota";
    gulden = 50;
    berat = 40;
}

Walikota::Walikota(string username, int berat, int gulden, int row, int col): Peran(username, berat, gulden, row, col) {
    peran_pemain = "walikota";
}

Walikota::~Walikota() {}

string Walikota::getType() {
    return peran_pemain;
}

void Walikota::addGulden(int guldentambahan) {
    this->gulden += guldentambahan;
}

void Walikota::ambilPajak(vector<Peran*> listpemain) {
    int guldenpajak = 0;
    for(int i = 0; i < listpemain.size(); i++) {
        guldenpajak += listpemain[i]->calculateTax()*0.35;
    }
    addGulden(guldenpajak);
}

void Walikota::tanam() {
    cout << "Hanya bisa dilakukan oleh petani." << endl;
}

void Walikota::panen(vector<Produk*> listproduk) {
    cout << "Hanya bisa dilakukan oleh petani dan peternak." << endl;
}

void Walikota::beriMakan() {
    cout << "Hanya bisa dilakukan oleh petani." << endl;
}

void Walikota::cetakLahan() {
    cout << "Anda tidak punya lahan." << endl;
}

int Walikota::calculateTax() {
    return 0;
}

void Walikota::addumur() {

}

void Walikota::tanamFile(string a, string b, int c, vector<Item*> x) {}

void Walikota::buatuser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    if(gulden >= 50) {
        string role, uname;
        cout << "Pilih role yang ingin dibuat: ";
        cin >> role;
        if (role == "Petani" || role == "Peternak") {
            cout << "Masukkan username: ";
            gulden -= 50;
            if(role == "Petani") {
                Peran* a = new Petani(uname, row_inv, col_inv, row_farm, col_farm);
                listplayer.push_back(a);
            }
            else {
                Peran* a = new Peternak(uname, row_inv, col_inv, row_pet, col_pet);
                listplayer.push_back(a);
            }
        }
        else {
            cout << "Role ini tidak bisa dibuat" << endl;
        }
    }
    else {
        cout << "Tidak ada uang" << endl;
    }
}

void Walikota::bangunBangunan(vector<Bangunan*> listbangunan) {
    cout << "" << endl; //Ditambah Agil
    string name;
    cout << "Bangunan yang ingin dibangun: ";
    cin >> name;
    for(int i = 0 ; i < listbangunan.size(); i++) {
        if(listbangunan[i]->getNama() == name) {
            if(listbangunan[i]->getHarga() <= gulden) {
                bool item_complete = penyimpanan.check_item_building(listbangunan[i]->getMaterial());
                if(item_complete == true) {
                    penyimpanan += listbangunan[i];
                }
            }
            else {
                cout << "Uang tidak cukup" << endl;
            }
        }
    }
}

/*
 *  Class Petani
 *   
 */
Petani::Petani(): Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
} 

Petani::Petani(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(username, row_inventory, col_inventory) {
    peran_pemain = "petani";
    gulden = 50;
    berat = 40;
    lahanPertanian.setUkuran(row_lahan, col_lahan);
}

Petani::Petani(string username, int berat, int gulden, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(username, berat, gulden, row_inventory, col_inventory) {
    peran_pemain = "petani";
    this->gulden = gulden;
    this->berat = berat;
    lahanPertanian.setUkuran(row_lahan, col_lahan);
}

Petani::~Petani() {}

string Petani::getType() {
    return peran_pemain;
}

void Petani::tanam() {
    printPenyimpanan();
    string indeksinvent;
    Tanaman* tanaman;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent); 
    if (penyimpanan[lokasiinvent[1]][lokasiinvent[0]]->getTipe() == "HERBIVORE") {
        tanaman = dynamic_cast<Tanaman*>(penyimpanan[lokasiinvent[1]][lokasiinvent[0]]);
        cout << "Tumbuhan " << tanaman->getNama() << " diambil" << endl;
        cetakLahan();
        cout <<"Lahan kosong: " << lahanPertanian.getLahanKosong() << endl;
        if (lahanPertanian.getLahanKosong() == 0) {
            cout << "Lahan penuh" << endl;
        }
        else {
            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi = parse(idx);
            lahanPertanian[lokasi[1]][lokasi[0]] = tanaman;
            penyimpanan[lokasiinvent[1]][lokasiinvent[0]] = NULL;
        }
    }
    cetakLahan();
}

void Petani::bangunBangunan(vector<Bangunan*> a) {
    cout << "Hanya bisa dilakukan walikota" << endl;
} 

void Petani::cetakLahan() {
    int asciinum = 65;
    lahanPertanian.printlahan();
}
void Petani::panen(vector<Produk*> listproduk) {
    cout << "=====================LAHAN PETERNAKAN===================" << endl;
    lahanPertanian.printlahan();
    vector<string> listtanamanmatang;
    vector<int> jumlahtanamanmatang;
    map<string, int> hewansiappanen = lahanPertanian.listSiapPanen();
    map<string, int>::iterator it = hewansiappanen.begin();
    // Menghitung tanaman yang siap panen
    for(int i = 0; i < listtanamanmatang.size(); i++) {
        cout << i+1 << " " << listtanamanmatang[i] << " (" << jumlahtanamanmatang[i] << " buah)" << endl;
    }
    if(listtanamanmatang.size() == 0) {
        cout << "Tidak ada yang bisa dipanen" << endl;
    }
    else {
        int angka;
        cout << "Pilih hewan yang akan dipananen: ";
        cin >> angka;
        angka--;
        if(angka >= listtanamanmatang.size() || angka < 0) {
            cout << "Jenis hewan yang dipanen tidak sebanyak itu" << endl;
        } 
        else {
            cout << "Hewan " << listtanamanmatang[angka] << " dipilih" << endl;
            cout << "Masukkan jumlah: ";
            int jumlah;
            cin >> jumlah;
            if (jumlah > jumlahtanamanmatang[angka]) {
                cout << "Hewan yang ingin anda panen terlalu banyak" << endl;
            }
            // else if(jumlah > penyimpanan.getLahanKosong()) {
            //     cout << "Inventory tidak cukup" << endl;
            // }
            else {
                for(int x = 0; x < jumlah; x++) {
                    bool get = false;
                    while (get == false) {
                        string kode;
                        cin >> kode;
                        Tanaman* a;
                        vector<int> index = parse(kode);
                        if(lahanPertanian[index[1]][index[0]]->getKode() == listtanamanmatang[angka]) {
                            a = lahanPertanian[index[1]][index[0]];
                            lahanPertanian[index[1]][index[0]] = NULL;
                            vector<string> hasilpanen = a->getProduk();
                            if(hasilpanen.size()*(jumlah-x) > penyimpanan.getLahanKosong()) {
                                cout << "Inventory anda tidak cukup" << endl;
                            }
                            else {
                                for(int banyak_produk = 0; banyak_produk < hasilpanen.size(); banyak_produk++) {
                                    Produk* produk;
                                    for(int q = 0; q < listproduk.size(); q++) {
                                        if(hasilpanen[banyak_produk] == listproduk[q]->getNama()) {
                                            produk = listproduk[q];
                                        }
                                    }
                                    penyimpanan += produk;
                                }
                                get = true;    
                            }
                        }
                        else {
                            cout << "Lokasi yang anda masukkan salah" << endl;
                        }
                    }
                    
                }
            }
        }
    }
}

void Petani::beriMakan() {
    cout << "Hanya bisa dilakukan oleh peternak" << endl;
}

int Petani::calculateTax() {
    int uang = this->gulden;
    uang += penyimpanan.getValue();
    uang += lahanPertanian.getValue();
    uang -= 13;
    return uang;
}

void Petani::addumur() {
    for(int i = 0 ; i < lahanPertanian.getBaris(); i++) {
        for(int j = 0; j < lahanPertanian.getKolom(); j++) {
            if(lahanPertanian[i][j] != NULL) {
                lahanPertanian[i][j]->tambahUmur();
            }
        }
    }
}

void Petani::ambilPajak(vector<Peran*> list) {
    cout << "Hanya bisa dilakukan oleh walikota" << endl;
}

void Petani::buatuser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    cout << "Hanya bisa dilakukan oleh walikota" << endl;
}

void Petani::tanamFile(string location, string name, int umur, vector<Item*> listtanaman) {
    Tanaman* plant;
    for(int i = 0; i < listtanaman.size(); i++) {
        if(listtanaman[i]->getNama() == name) {
            plant = dynamic_cast<Tanaman*>(listtanaman[i]);
        }
        plant->setUmur(umur);
    }
}

// Child Peternak
Peternak::Peternak(): Peran() {
    this->username = " ";
    gulden = 50;
    berat = 40;
}

Peternak::Peternak(string username, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(username, row_inventory, col_inventory) {
    peran_pemain = "peternak";
    gulden = 50;
    berat = 40;
    peternakan.setUkuran(row_lahan, col_lahan);
}

Peternak::Peternak(string username, int berat, int gulden, int row_inventory, int col_inventory, int row_lahan, int col_lahan): Peran(username, berat, gulden, row_inventory, col_inventory) {
    peran_pemain = "peternak";
    this->gulden = gulden;
    this->berat = berat;
    peternakan.setUkuran(row_lahan, col_lahan);
}

Peternak::~Peternak() {}


void Peternak::cetakLahan() {
    peternakan.printlahan();
}

void Peternak::tanam() {
    printPenyimpanan();
    string indeksinvent;
    Hewan* hewan;
    cout << "Slot: ";
    cin >> indeksinvent;
    vector<int> lokasiinvent = parse(indeksinvent);
    string tipe = penyimpanan[lokasiinvent[1]][lokasiinvent[0]]->getTipe();
    if (tipe == "HERBIVORE" || tipe == "CARNIVORE" || tipe == "OMNIVORE") {
        hewan = dynamic_cast<Hewan*>(penyimpanan[lokasiinvent[1]][lokasiinvent[0]]);
        cout << "Hewan " << hewan->getNama() << " diambil" << endl;
        cetakLahan();
        cout <<"Lahan kosong: " << peternakan.getLahanKosong() << endl;
        if (peternakan.getLahanKosong() == 0) {
            cout << "Lahan penuh" << endl;
        }
        else {
            string idx;
            cout << "Masukkan lokasi yang diinginkan: ";
            cin >> idx;
            vector<int> lokasi = parse(idx);
            if(peternakan[lokasi[1]][lokasi[0]] != NULL) {
                cout << "Lahan ini telah diisi" << endl;
            }
            else {
                peternakan[lokasi[1]][lokasi[0]] = hewan;
                penyimpanan[lokasiinvent[1]][lokasiinvent[0]] = NULL;
                cout << "Hewan " << hewan->getNama() << " diletakkan di petak " << idx << endl; 
            }
        }
    }
    cetakLahan();
}

string Peternak::getType() {
    return this->peran_pemain;
}

void Peternak::panen(vector<Produk*> listproduk) {
    cout << "=====================LAHAN PETERNAKAN===================" << endl;
    peternakan.printlahan();
    vector<string> hewankurban;
    vector<int> jumlahhewan;
    map<string, int> hewansiappanen = peternakan.listSiapPanen();
    // Menghitung tanaman yang siap panen
    for (auto i = hewansiappanen.begin(); i != hewansiappanen.end(); i++) {
        hewankurban.push_back(i->first);
        jumlahhewan.push_back(i->second);
    }
    cout << "OK" << endl;
    for(int i = 0; i < hewankurban.size(); i++) {
        cout << hewankurban[i] << " (" << jumlahhewan[i] << " buah)" << endl;
    }
    if(hewankurban.size() == 0) {
        cout << "Tidak ada yang bisa dipanen" << endl;
    }
    else {
        int angka;
        cout << "Pilih hewan yang akan dipananen: ";
        cin >> angka;
        angka--;
        if(angka >= hewankurban.size() || angka < 0) {
            cout << "Jenis hewan yang dipanen tidak sebanyak itu" << endl;
        } 
        else {
            cout << "Hewan " << hewankurban[angka] << " dipilih" << endl;
            cout << "Masukkan jumlah: ";
            int jumlah;
            cin >> jumlah;
            if (jumlah > jumlahhewan[angka]) {
                cout << "Hewan yang ingin anda panen terlalu banyak" << endl;
            }
            // else if(jumlah > penyimpanan.getLahanKosong()) {
            //     cout << "Inventory tidak cukup" << endl;
            // }
            else {
                for(int x = 0; x < jumlah; x++) {
                    bool get = false;
                    while (get == false) {
                        string kode;
                        cout << "Pilih petak yang ingin dipanen: ";
                        cin >> kode;
                        Hewan* a;
                        vector<int> index = parse(kode);
                        cout << peternakan[index[1]][index[0]]->getNama() << endl;
                        cout << hewankurban[angka] << endl;
                        if(peternakan[index[1]][index[0]]->getNama() == hewankurban[angka]) {
                            a = peternakan[index[1]][index[0]];
                            peternakan[index[1]][index[0]] = NULL;
                            vector<string> hasilpanen = a->getProduk();
                            if(hasilpanen.size()*(jumlah-x) > penyimpanan.getLahanKosong()) {
                                cout << "Inventory anda tidak cukup" << endl;
                            }
                            else {
                                for(int banyak_produk = 0; banyak_produk < hasilpanen.size(); banyak_produk++) {
                                    Produk* produk;
                                    for(int q = 0; q < listproduk.size(); q++) {
                                        if(hasilpanen[banyak_produk] == listproduk[q]->getNama()) {
                                            produk = listproduk[q];
                                        }
                                    }
                                    penyimpanan += produk;
                                }
                                get = true;    
                            }
                        }
                        else {
                            cout << "Lokasi yang anda masukkan salah" << endl;
                        }
                    }
                    
                }
            }
        }
    }
}

void Peternak::bangunBangunan(vector<Bangunan*> a) {
    cout << "Hany bisa dilakukan walikota" << endl;
}

void Peternak::beriMakan() {
    cetakLahan();
    bool kondisi;
    string slot;
    Hewan* hewan;
    cout << "Hewan yang akan diberi makan: ";
    cin >> slot;
    vector<int> index = parse(slot);
    hewan = peternakan[index[1]][index[0]];
    if(hewan == NULL) {
        cout << "Tidak ada hewan di ladang" << endl;
    }
    else {
        printPenyimpanan();
        Produk* produk;
        cout << "Ambil makanan: ";
        cin >> slot;
        index = parse(slot);
        produk = dynamic_cast<Produk*>(penyimpanan[index[1]][index[0]]);
        if (produk == NULL) {
            cout << "Tidak ada apa-apa di di sana" << endl;
        } 
        else if ((produk->getTipe() == "PRODUCT_ANIMAL") || (produk->getTipe() == "PRODUCT_FRUIT_PLANT")) {
            kondisi = hewan->makan(produk);
            if(kondisi == true) {
                hewan->tambahBerat(produk->getTambahan());
                cout << "Berat " << hewan->getBeratSaatIni() << endl;
                penyimpanan[index[1]][index[0]] = NULL;
            }
        } 
        else {
            cout << "Hei, yakin kamu mau makan itu???" << endl;
        }
    }
}

int Peternak::calculateTax() {
    int uang = this->gulden;
    uang += penyimpanan.getValue();
    uang += peternakan.getValue();
    uang -= 11;
    return uang;
}

void Peternak::addumur() {

}

void Peternak::ambilPajak(vector<Peran*> list) {
    cout << "Hanya bisa dilakukan oleh walikota" << endl;
}

void Peternak::buatuser(vector<Peran*> listplayer, int row_inv, int col_inv, int row_farm, int col_farm, int row_pet, int col_pet) {
    cout << "Hanya bisa dilakukan walikota" << endl;
}

void Peternak::tanamFile(string location, string name, int berat, vector<Item*> listhewan) {
    Hewan* animal;
    for(int i = 0; i < listhewan.size(); i++) {
        if(listhewan[i]->getNama() == name) {
            animal = dynamic_cast<Hewan*>(listhewan[i]);
        }
        animal->setBerat(berat);
    }
}

// void Peternak::changelahan() {
//     for(int i = 0; i < 8; i++) {
//         for(int j = 0; j < 8; j++) {
//             peternakan[i][j] = new Carnivore();
//         }
//     }
// }