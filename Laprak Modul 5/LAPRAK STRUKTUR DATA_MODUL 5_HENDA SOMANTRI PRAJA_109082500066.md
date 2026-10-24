# <h1 align="center">LAPORAN PRAKTIKUM MODUL 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<h3 align="center">HENDA SOMANTRI PRAJA - 109082500066</h3>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai merupakan salah satu bentuk struktur data linier yang berisi kumpulan elemen data yang tersusun secara sekuensial, saling bersambungan, dan bersifat dinamis [1]. Berbeda dengan struktur data statis, alokasi memori pada linked list dapat diatur saat program berjalan (runtime), sehingga ukuran senarai dapat bertambah atau berkurang secara fleksibel sesuai dengan kebutuhan sistem [2].

### A. Konsep Dasar Struktur Data Singly Linked List dan Manajemen Memori Dinamis<br/>

#### 1. Pengertian dan Karakteristik Singly Linked List
Singly linked list adalah jenis senarai berantai di mana setiap elemen atau node hanya memiliki satu arah pointer penunjuk yang mengarah ke simpul berikutnya [1]. Elemen terdepan dari senarai diakses melalui sebuah penanda utama (First atau Head), sementara elemen terakhir akan menunjuk ke nilai kosong (Null) sebagai penanda akhir dari rantai data [2].
#### 2. Struktur Node dan Pointer (address, next)
Secara struktur, setiap node di dalam singly linked list terbagi menjadi komponen informasi (field info) untuk menampung data serta komponen penunjuk (field next) yang menyimpan alamat memori dari simpul berikutnya [1]. Penggunaan alias tipe data pointer atau address sering diterapkan untuk mempermudah perujukan antar-simpul di dalam bahasa pemrograman seperti C++ [2].
#### 3. Manajemen Memori Dinamis (alokasi dan dealokasi)
Pengelolaan memori pada struktur data ini dilakukan secara dinamis menggunakan fungsi alokasi untuk memesan ruang memori baru di heap bagi pembentukan node, serta prosedur dealokasi untuk mengembalikan memori simpul yang sudah tidak terpakai ke sistem operasi guna mencegah terjadinya kebocoran memori (memory leak) [1, 2].

### B. Operasi Dasar Manipulasi Data pada Singly Linked List (Insert, Delete, dan Traversal)<br/>

#### 1. Operasi Penyisipan (Insertion)
Operasi penyisipan data dapat dilakukan melalui beberapa titik posisi strategis di dalam senarai, meliputi penambahan elemen baru di bagian awal (insertFirst), penyisipan di antara simpul tertentu (insertAfter), hingga penambahan elemen di posisi paling akhir (insertLast) dengan melakukan penelusuran dari simpul awal [1, 2].
#### 2. Operasi Penghapusan (Deletion)
Penghapusan elemen bertujuan untuk membuang simpul tertentu dari rantai senarai serta membebaskan kembali memori yang digunakannya [1]. Operasi ini mencakup penghapusan simpul pertama (delFirst), penghapusan simpul terakhir (delLast), penghapusan elemen setelah simpul tertentu (delAfter), serta pembersihan total seluruh elemen senarai (deleteList) [2].
#### 3. Traversal dan Fungsi Utilitas
Traversal adalah proses menelusuri setiap simpul di dalam linked list secara berurutan mulai dari simpul awal hingga akhir untuk menjalankan berbagai fungsi utilitas, seperti menampilkan seluruh isi data di terminal maupun menghitung jumlah total simpul aktif yang ada di dalam senarai [1, 2].
#### 4. Operasi Pencarian dan Agregasi Data (Searching dan Total Info)
Selain penambahan dan penghapusan, linked list juga mendukung operasi pencarian data (findElm) untuk melacak keberadaan nilai informasi tertentu di dalam senarai melalui penelusuran sekuensial, serta fungsi utilitas matematis seperti penjumlahan total nilai seluruh elemen (totalInfo) guna mengakumulasikan seluruh data integer yang tersimpan di setiap simpul aktif [1, 2].


## Guided (Contoh Soal)

### 1. Guided 1

### 1.1 listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist { //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### 1.2 listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "--------------------------------------------------" << endl;
        while(nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "--------------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 1.3 main.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### Penjelasan
Program ini secara keseluruhan dirancang untuk mengelola data inventaris buah menggunakan struktur data Singly Linked List dalam bahasa C++. Pada bagian 1.1 (listBuah.h), didefinisikan struktur data utama yang meliputi struct buah untuk menyimpan informasi nama, jumlah, dan harga buah, struct node sebagai elemen pembentuk list, serta kumpulan prototipe fungsi dan prosedur untuk operasi manajemen data seperti insert, delete, update, dan searching.

Pada bagian 1.2 (listBuah.cpp), terdapat implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan pada file header. File ini mengatur manajemen memori secara dinamis melalui proses alokasi dan dealokasi, serta mengeksekusi algoritma manipulasi data seperti penambahan node (insert), penghapusan node (delete), pembaruan data (update), hingga fitur pencarian lanjutan berdasarkan nama buah, alamat memori node, maupun rentang harga tertentu.

Terakhir, pada bagian 1.3 (main.cpp), file ini berfungsi sebagai program utama untuk menjalankan dan menguji seluruh program linked list. Di dalam fungsi main, program menginisialisasi list kosong, mengalokasikan beberapa data buah (seperti Jeruk, Apel, Pir, Semangka, dan Durian), lalu mendemonstrasikan tahapan operasi mulai dari penambahan, pembaruan data, pencarian, penghapusan bertahap, hingga pembersihan total seluruh isi list di akhir program.


## Unguided (Soal Latihan)

### 1. Unguided 2

### 2.1 singlyList.h
Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// ==========================================
// SOAL 2
// ==========================================
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

### 2.2 singlyList.cpp
Kemudian buatlah implementasi ADT Singly  linked List pada file “Singlylist.cpp”

```C++
#include "Singlylist.h"

// ==========================================
// IMPLEMENTASI SOAL 2
// ==========================================
void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

### 2.3 main.cpp
Cobalah hasil implementasi ADT pada file "main.cpp"

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    // ==========================================
    // SOAL NOMOR 2
    // ==========================================
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "OUTPUT SOAL 1" << endl;
    printInfo(L);
    
    cout << endl;

}
```

### Output Unguided 2 :
![Output Unguided 2](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%205/Output%20Unguided%202.png)

### Penjelasan Unguided 2 :
Program ini diawali dengan file header singlyList.h yang berfungsi sebagai kerangka dari struktur data Singly Linked List. Di dalam file ini didefinisikan tipe data bentukan untuk node (ElmList) yang menyimpan informasi nilai serta penunjuk (pointer) ke elemen berikutnya, struct List untuk penanda awal list, serta deklarasi berbagai struktur fungsi dan prosedur penting seperti createList, alokasi, dealokasi, printInfo, dan insertFirst.

Selanjutnya, file singlyList.cpp berisi implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan sebelumnya. Pada file ini, fungsi createList digunakan untuk menginisialisasi list agar bernilai kosong, alokasi dan dealokasi mengatur pengelolaan memori dinamis untuk setiap node, printInfo mencetak seluruh isi elemen list ke layar secara berurutan, serta prosedur insertFirst bertugas menyisipkan node baru di posisi paling depan.

Sebagai penutup, file main.cpp bertindak sebagai program utama untuk menjalankan dan menguji keseluruhan fungsi Singly Linked List yang telah dibuat. Di sini, program menginisialisasi list kosong, melakukan alokasi nilai berupa angka 2, 0, 8, 12, dan 9 yang kemudian dimasukkan ke bagian depan list secara berurutan menggunakan prosedur insertFirst, dan terakhir menampilkan hasil akhir susunan data tersebut ke terminal melalui fungsi printInfo.
 

### 2. Unguided 3
Carilah elemen dengan info 8 dengan membuat fungsi baru.
fungsi findElm(L : List, x : infotype) : address

### 3.1 singlyList.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// ==========================================
// SOAL 2
// ==========================================
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// ==========================================
// SOAL 3
// ==========================================
address findElm(List L, infotype x);

#endif
```

### 3.2 singlyList.cpp

```C++
#include "Singlylist.h"

// ==========================================
// IMPLEMENTASI SOAL 2
// ==========================================
void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// ==========================================
// IMPLEMENTASI SOAL 3
// ==========================================
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

### 3.3 main.cpp

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    // ==========================================
    // SOAL NOMOR 2
    // ==========================================
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "OUTPUT SOAL 2" << endl;
    printInfo(L);
    
    cout << endl;

    // ==========================================
    // SOAL NOMOR 3
    // ==========================================
    address pCari = findElm(L, 8);
    if (pCari != Nil) {
        cout << "OUTPUT SOAL 3" << endl;
        cout << "8 ditemukan dalam list\n" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list\n" << endl;
    }

}
```

### Output Unguided 3 :
![Output Unguided 3](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%205/Output%20Unguided%203.png)

### Penjelasan Unguided 3 :
Program ini diawali dengan file header singlyList.h yang berfungsi sebagai kerangka dari struktur data Singly Linked List. Di dalam file ini didefinisikan tipe data bentukan untuk node (ElmList) yang menyimpan informasi nilai serta penunjuk (pointer) ke elemen berikutnya, struct List untuk penanda awal list, serta deklarasi berbagai struktur fungsi dan prosedur penting seperti createList, alokasi, dealokasi, printInfo, insertFirst, hingga penambahan deklarasi fungsi baru findElm untuk keperluan pencarian data.

Selanjutnya, file singlyList.cpp berisi implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan sebelumnya. Pada file ini, fungsi createList digunakan untuk menginisialisasi list agar bernilai kosong, alokasi dan dealokasi mengatur pengelolaan memori dinamis untuk setiap node, printInfo mencetak seluruh isi elemen list ke layar secara berurutan, prosedur insertFirst menyisipkan node baru di posisi paling depan, serta ditambahkan fungsi findElm yang bertugas menelusuri (traversal) elemen list satu per satu guna menemukan simpul yang memiliki nilai info tertentu.

Sebagai penutup, file main.cpp bertindak sebagai program utama untuk menjalankan dan menguji keseluruhan fungsi Singly Linked List yang telah dibuat. Di sini, program menginisialisasi list kosong, melakukan alokasi nilai berupa angka 2, 0, 8, 12, dan 9 yang kemudian dimasukkan ke bagian depan list secara berurutan menggunakan prosedur insertFirst, menampilkan hasil susunan data awal ke terminal melalui fungsi printInfo, serta menguji fungsi findElm untuk mendeteksi keberadaan nilai 8 di dalam list dan mencetak status hasil pencariannya.


### 3. Unguided 4
Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31)

### 4.1 singlyList.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// ==========================================
// SOAL 2
// ==========================================
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// ==========================================
// SOAL 3
// ==========================================
address findElm(List L, infotype x);

// ==========================================
// SOAL 4
// ==========================================
int totalInfo(List L);

#endif
```

### 4.2 singlyList.cpp

```C++
#include "Singlylist.h"

// ==========================================
// IMPLEMENTASI SOAL 2
// ==========================================
void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// ==========================================
// IMPLEMENTASI SOAL 3
// ==========================================
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// ==========================================
// IMPLEMENTASI SOAL 4
// ==========================================
int totalInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```

### 4.3 main.cpp

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    // ==========================================
    // SOAL NOMOR 2
    // ==========================================
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "OUTPUT SOAL 2" << endl;
    printInfo(L);
    
    cout << endl;

    // ==========================================
    // SOAL NOMOR 3
    // ==========================================
    address pCari = findElm(L, 8);
    if (pCari != Nil) {
        cout << "OUTPUT SOAL 3" << endl;
        cout << "8 ditemukan dalam list\n" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list\n" << endl;
    }

    // ==========================================
    // SOAL NOMOR 4
    // ==========================================
    cout << "OUTPUT SOAL 4" << endl;
    int total = totalInfo(L);
    cout << "Total info dari kelima elemen adalah " << total << endl;
    
    return 0;
}
```

### Output Unguided 4 :
![Output Unguided 4](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%205/Output%20Unguided%204.png)

### Penjelasan Unguided 4 :
Program ini diawali dengan file header singlyList.h yang berfungsi sebagai kerangka dari struktur data Singly Linked List. Di dalam file ini didefinisikan tipe data bentukan untuk node (ElmList) yang menyimpan informasi nilai serta penunjuk (pointer) ke elemen berikutnya, struct List untuk penanda awal list, serta deklarasi berbagai struktur fungsi dan prosedur penting seperti createList, alokasi, dealokasi, printInfo, insertFirst, fungsi pencarian findElm, hingga penambahan deklarasi fungsi baru totalInfo untuk menghitung akumulasi seluruh nilai elemen.

Selanjutnya, file singlyList.cpp berisi implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan sebelumnya. Pada file ini, fungsi createList digunakan untuk menginisialisasi list agar bernilai kosong, alokasi dan dealokasi mengatur pengelolaan memori dinamis untuk setiap node, printInfo mencetak seluruh isi elemen list ke layar secara berurutan, prosedur insertFirst menyisipkan node baru di posisi paling depan, fungsi findElm bertugas menelusuri (traversal) elemen untuk mencari data tertentu, serta ditambahkan fungsi totalInfo yang melakukan iterasi ke seluruh simpul untuk menjumlahkan nilai info dari setiap elemen di dalam list.

Sebagai penutup, file main.cpp bertindak sebagai program utama untuk menjalankan dan menguji keseluruhan fungsi Singly Linked List yang telah dibuat. Di sini, program menginisialisasi list kosong, melakukan alokasi nilai berupa angka 2, 0, 8, 12, dan 9 yang kemudian dimasukkan ke bagian depan list secara berurutan menggunakan prosedur insertFirst, menampilkan hasil susunan data awal ke terminal melalui fungsi printInfo, menguji fungsi findElm untuk mendeteksi keberadaan nilai 8, serta mengeksekusi dan menampilkan hasil dari fungsi totalInfo untuk mencetak jumlah keseluruhan nilai elemen ke layar.


## Kesimpulan
Singly Linked List merupakan struktur data linier yang bersifat dinamis, di mana alokasi memorinya diatur pada saat runtime melalui penggunaan pointer. Setiap simpul (node) di dalamnya terbagi menjadi komponen informasi (info) untuk menampung data dan komponen penunjuk (next) yang mengarah ke simpul berikutnya, dengan elemen pertama diakses melalui penanda utama (First) dan elemen terakhir menunjuk ke nilai kosong (Nil).

Dari proses implementasi pemrogramannya, penerapan struktur data ini menggunakan konsep pemrograman modular yang memisahkan file header (.h), file implementasi (.cpp), dan file utama (main.cpp). Pengelolaan memori dilakukan secara manual dan sistematis menggunakan fungsi alokasi dan dealokasi (alokasi dan dealokasi) guna mengoptimalkan penggunaan memori komputer serta mencegah terjadinya kebocoran memori (memory leak).

Secara keseluruhan, rangkaian Soal Guided dan Soal Unguided membuktikan bahwa Singly Linked List sangat fleksibel dalam mendukung berbagai operasi manipulasi data. Mulai dari pembentukan list kosong (createList), penyisipan elemen di awal (insertFirst), pencetakan informasi (printInfo), pencarian elemen tertentu berdasarkan nilai (findElm), hingga fungsi untuk menghitung jumlah total nilai seluruh elemen (totalInfo). Hal ini memberikan pemahaman yang lebih detail mengenai penerapan Abstract Data Type (ADT) dan logika pointer secara mendalam dalam bahasa C++.


## Referensi
<br> [1] ResearchGate. (2025). *Linked List in C++*. ResearchGate Technical Publication. https://www.researchgate.net/publication/387794369_Linked_List_in_C
<br> [2] Scribd. (2025). *C++ Singly Linked List Implementation and Operations.* Practical Laboratory Manual of Data Structures and Algorithms. https://www.scribd.com/document/822604030/DSA-LAB-05-SINGLY-LINKED-LIST