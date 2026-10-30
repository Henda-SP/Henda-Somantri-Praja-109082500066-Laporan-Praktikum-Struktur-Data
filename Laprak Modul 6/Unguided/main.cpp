#include <iostream>
#include "Buku.h"

using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "\n";
    cout << "masukkan kode buku: "; cin >> data.kodeBuku;
    cout << "masukkan judul buku: "; cin >> data.judul;
    cout << "masukkan tahun terbit: "; cin >> data.thnTerbit;
    
    // Pengecekan duplikasi kode buku sebelum dimasukkan
    if (findElm(L, data.kodeBuku) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "kode buku sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1: Masukkan data sesuai urutan di soal latihan
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    cout << "\n";
    printInfo(L); 

    // Latihan 2: Pencarian Elemen
    string cariKode;
    cout << "\nMasukkan Kode Buku yang dicari: "; 
    cin >> cariKode; 
    cout << "\n";

    P = findElm(L, cariKode); 
    if (P != Nil) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl; 
        cout << "Judul        : " << P->info.judul << endl; 
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl; 
    } else {
        cout << "Data dengan kode buku " << cariKode << " tidak ditemukan." << endl;
    }

    // Latihan 3: Penghapusan Elemen
    string hapusKode;
    bool statusHapus;
    cout << "\nMasukkan Kode Buku yang akan dihapus: ";
    cin >> hapusKode;

    deleteElm(L, hapusKode, statusHapus); 

    if (statusHapus) {
        cout << "Data dengan kode buku " << hapusKode << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan kode buku " << hapusKode << " tidak ditemukan." << endl;
    }
    cout << "\n";

    cout << "\nDATA LIST 1" << endl;
    cout << "\n";
    printInfo(L); 
    return 0;
}