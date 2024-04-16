#include "Peran.hpp"

Peran::Peran() {
    this->username = " ";
    this->gulden = 50;
    this->berat = 40;
}

Peran::Peran(string username, int row_inv, int col_inv) {
    this->username = username;
    this->gulden = 50;
    this->berat = 40;
    penyimpanan.setUkuran(row_inv, col_inv);
}

Peran::Peran(string username, int berat, int gulden, int row_inv, int col_inv) {
    this->username = username;
    this->gulden = gulden;
    this->berat = berat;
    penyimpanan.setUkuran(row_inv, col_inv);
}

Peran::~Peran() {}

Peran& Peran::operator= (const Peran& other) {
    username = other.username;
    gulden = other.gulden;
    berat = other.berat;
    penyimpanan = other.penyimpanan;
    return *this;
}

string Peran::getUname() {
    return this->username;
}

int Peran::getGulden() {
    return this->gulden;
}

int Peran::getBerat() {
    return this->berat;
}

vector<string> Peran::getSemuaItem() {
    vector<string> temp;

    for (int i = 0; i < penyimpanan.getBaris(); i++) {
        for (int j = 0; j < penyimpanan.getKolom(); j++) {
            if (penyimpanan[j][i] != NULL) {
                temp.push_back(penyimpanan[j][i]->getNama());
            }
        }
    }
    return temp;
}

MatriksPenyimpanan<Item *> Peran::getPenyimpanan() {
    return this->penyimpanan;
}

void Peran::tambahBerat(int berat) {
    this->berat += berat;
}

void Peran::tambahGulden(int gulden) {
    this->gulden += gulden;
}

vector<int> Peran::parse(string idx) {
    if (idx.length() != 3) {
        throw LokasiTidakValidException();
    } 
    else {
        if ((idx[0] < 'A' || idx[0] > 'Z') ||
            (idx[1] < '0' || idx[1] > '9') ||
            (idx[2] < '0' || idx[2] > '9')) 
            {
            throw LokasiTidakValidException();
            }
    }

    vector<int> indeks;
    indeks.push_back(((int)idx[0])-65);         // KOLOM
    indeks.push_back((int)(idx[1]-'0')*10);     // BARIS
    indeks[1] += (int)(idx[2]-'0');
    indeks[1] -= 1;

    if (indeks[0] < 0 || indeks[1] < 0) 
    {
        throw LokasiTidakValidException();
    }
    return indeks;
}

void Peran::centerAlign(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}

void Peran::printPenyimpanan() {
    int lebar = this->penyimpanan.getKolom()*5 + this->penyimpanan.getKolom() + 1;
    cout << "      ";
    centerAlign("[ PENYIMPANAN ]", lebar);
    this->penyimpanan.print();

    map<string, string> listItemDiPenyimpanan = penyimpanan.listProdukInMatriks();
    for (auto i = listItemDiPenyimpanan.begin(); i != listItemDiPenyimpanan.end(); i++) {
        cout << "      - ";
        cout << i->first << " : " << i->second << endl;
    }
    cout << endl;
}

void Peran::addPenyimpananInFirstEmpty(Item* item) {
    penyimpanan += item;
}

void Peran::addPenyimpananSpesifikLocation(Item* item) {
    printPenyimpanan();
    
    string idx;
    cout << "Masukkan lokasi yang diinginkan: ";
    cin >> idx;
    cout << endl;
    
    vector<int> lokasi = parse(idx);

    if (penyimpanan[lokasi[1]][lokasi[0]] != NULL) {
        cout << "Cari tempat yang kosong." << endl << endl;
    }
    else {
        penyimpanan.setElement(lokasi[1], lokasi[0], item);
    }
}

void Peran::addPenyimpananFile(string name, vector<Item*> listItem) {
// memasukkan item yang ada dalam file txt ke dalam penyimpanan
    Item* item;
    for (int i = 0; i < int(listItem.size()); i++) {
        if (listItem[i]->getNama() == name) {
            item = listItem[i];
        }
    }
    penyimpanan += item;
}

void Peran::playerMakan() {
    printPenyimpanan();
    if (penyimpanan.isEmpety() || !penyimpanan.isAdaMakanan("OMNIVORE")) {
        cout << "Tidak ada yang bisa kamu makan disini." << endl << endl;
    } else {
        Item* x;
        string lokasi;

        cout << "Ambil makanan dalam inventory mu: ";
        cin >> lokasi;
        cout << endl;
        vector<int> index = parse(lokasi);
        
        if (index[0] >= penyimpanan.getKolom() || index[1] >= penyimpanan.getBaris()) {
            cout << "Lokasi yang anda masukkan salah." << endl << endl;
        } else {
            x = penyimpanan[index[1]][index[0]];
            
            if (x == NULL) {
                cout << "Tidak ada apa-apa di di sana" << endl << endl;
            } else if ((x->getTipe() == "PRODUCT_ANIMAL") || (x->getTipe() == "PRODUCT_FRUIT_PLANT")) {
                tambahBerat(x->getTambahan());
                penyimpanan[index[1]][index[0]] = NULL;
                cout << "Berat badanmu naik jadi " << this->berat << endl << endl;
            } else {
                cout << "Hei, yakin kamu mau makan itu???" << endl << endl;
            }
        }
    }
}
