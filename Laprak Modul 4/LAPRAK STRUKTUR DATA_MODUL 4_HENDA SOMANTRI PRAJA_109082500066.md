# <h1 align="center">LAPORAN PRAKTIKUM MODUL 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
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


## Guided (Contoh Soal)

### 1. Guided 1

### 1.1 list.h

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct LinkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(LinkedList List);
void createList(LinkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList List);
void insertFirst(LinkedList &List, address nodeBaru);
void insertAfter(LinkedList &List, address nodeBaru, address Prev);
void insertLast(LinkedList &List, address nodeBaru);

void delFirst(LinkedList &List);
void delLast(LinkedList &List);
void delAfter(LinkedList &List, address nodeHapus, address nodePrev);
int nbList(LinkedList List);
void deleteList(LinkedList &List);

#endif
```

### 1.2 list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(LinkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(LinkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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
void delFirst(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {//jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(LinkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(LinkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(LinkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

### 1.3 main.cpp

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main(){
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

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
Program ini dirancang untuk mengimplementasikan struktur data Singly Linked List berbasis bahasa C++ untuk mengelola data akademik mahasiswa secara dinamis. Berikut adalah penjelasan singkat mengenai masing-masing komponen kodenya:

File header list.h berfungsi sebagai kerangka dasar untuk mendefinisikan struktur data Singly Linked List khusus untuk menyimpan informasi data mahasiswa yang meliputi nama, NIM, dan umur. Di dalamnya didefinisikan tipe data bentukan seperti struct mahasiswa, struct node, dan struct LinkedList, serta deklarasi struktur fungsi dan prosedur untuk manajemen memori, penyisipan (insert), penghapusan (delete), dan pencetakan data.

File list.cpp berisi implementasi dari seluruh struktur fungsi dan prosedur yang telah dideklarasikan sebelumnya. File ini mengatur manajemen alokasi dan dealokasi memori secara dinamis, serta mengeksekusi logika pemrograman untuk berbagai operasi list seperti penyisipan di awal, tengah, atau akhir, penghapusan elemen secara fleksibel, penelusuran dan pencetakan isi list, penghitungan total node melalui fungsi nbList, hingga pembersihan seluruh elemen list lewat deleteList.

File main.cpp bertindak sebagai program utama untuk menjalankan dan menguji keseluruhan program Linked List mahasiswa. Di dalam fungsi utama ini, program menginisialisasi list kosong, mengalokasikan data lima mahasiswa (Dhimas, Arvin, Rizal, Satrio, dan Joshua), menguji berbagai metode penambahan dan penghapusan node, menampilkan kondisi list beserta jumlah node aktif pada setiap tahapan, hingga melakukan penghapusan total list di akhir program.


## Unguided (Soal Latihan)

### 1. Unguided 1

### 1.1 singlyList.h
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
// FUNGSI & PROSEDUR SOAL 1
// ==========================================
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

### 1.2 singlyList.cpp
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file 
“Singlylist.cpp”

```C++
#include "Singlylist.h"

// ==========================================
// IMPLEMENTASI SOAL 1
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

### 1.3 main.cpp
Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai 
berikut : 

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    // ==========================================
    // SOAL NOMOR 1
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

    return 0;
}
```

### Output Unguided 1 :
![Output Unguided 1.png](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%204/Output%20Unguided%201.png)

### Penjelasan Unguided 1 :
Program ini diawali dengan file header singlyList.h yang berfungsi sebagai kerangka dari struktur data Singly Linked List. Di dalam file ini didefinisikan tipe data bentukan untuk node (ElmList) yang menyimpan informasi nilai serta penunjuk (pointer) ke elemen berikutnya, struct List untuk penanda awal list, serta deklarasi berbagai struktur fungsi dan prosedur penting seperti createList, alokasi, dealokasi, printInfo, dan insertFirst.

Selanjutnya, file singlyList.cpp berisi implementasi dari seluruh fungsi dan prosedur yang telah dideklarasikan sebelumnya. Pada file ini, fungsi createList digunakan untuk menginisialisasi list agar bernilai kosong, alokasi dan dealokasi mengatur pengelolaan memori dinamis untuk setiap node, printInfo mencetak seluruh isi elemen list ke layar secara berurutan, serta prosedur insertFirst bertugas menyisipkan node baru di posisi paling depan.

Sebagai penutup, file main.cpp bertindak sebagai program utama untuk menjalankan dan menguji keseluruhan fungsi Singly Linked List yang telah dibuat. Di sini, program menginisialisasi list kosong, melakukan alokasi nilai berupa angka 2, 0, 8, 12, dan 9 yang kemudian dimasukkan ke bagian depan list secara berurutan menggunakan prosedur insertFirst, dan terakhir menampilkan hasil akhir susunan data tersebut ke terminal melalui fungsi printInfo.
 

### 2. Unguided 2
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan 
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh 
node menggunakan deleteList().

### 2.1 singlyList.h

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
// FUNGSI & PROSEDUR SOAL 1
// ==========================================
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// ==========================================
// FUNGSI & PROSEDUR SOAL 2
// ==========================================
bool isEmpty(List L);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prev, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

### 2.2 singlyList.cpp

```C++
#include "Singlylist.h"

// ==========================================
// IMPLEMENTASI SOAL 1
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
// IMPLEMENTASI SOAL 2
// ==========================================
bool isEmpty(List L) {
    return (L.First == Nil);
}

void deleteFirst(List &L, address &P) {
    if (!isEmpty(L)) {
        P = L.First;
        L.First = L.First->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (!isEmpty(L)) {
        if (L.First->next == Nil) {
            P = L.First;
            L.First = Nil;
        } else {
            address Prev = L.First;
            while (Prev->next->next != Nil) {
                Prev = Prev->next;
            }
            P = Prev->next;
            Prev->next = Nil;
        }
    }
}

void deleteAfter(address Prev, address &P) {
    if (Prev != Nil && Prev->next != Nil) {
        P = Prev->next;
        Prev->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (!isEmpty(L)) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "\n- List Berhasil Terhapus -" << endl;
}
```

### 2.3 main.cpp

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    // ==========================================
    // SOAL NOMOR 1
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

    // ==========================================
    // SOAL NOMOR 2
    // ==========================================
    address pHapus;

    // Hapus node 9 (deleteFirst)
    deleteFirst(L, pHapus);
    dealokasi(pHapus);

    // Hapus node 2 (deleteLast)
    deleteLast(L, pHapus);
    dealokasi(pHapus);

    // Hapus node 8 (deleteAfter, setelah node 12 / L.First)
    deleteAfter(L.First, pHapus);
    dealokasi(pHapus);

    cout << "OUTPUT SOAL 2" << endl;
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :
![Output Unguided 2.png](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%204/Output%20Unguided%202.png)

### Penjelasan Unguided 2 :
Program ini merupakan lanjutan dari program unguided 1, file header singlyList.h berfungsi sebagai kerangka dasar untuk memperluas struktur data Singly Linked List dengan menyediakan tambahan struktur fungsi penghapusan. Di dalam file ini didefinisikan kembali struktur node (ElmList) dan list, serta deklarasi prosedur pendukung seperti isEmpty, deleteFirst, deleteLast, deleteAfter, fungsi penghitung total node nbList, dan prosedur penghapusan seluruh elemen deleteList.

File singlyList.cpp berisi implementasi dari seluruh program untuk mengelola dan memanipulasi memori saat penghapusan data dilakukan. Di sini dituliskan kode untuk memeriksa apakah list kosong, mengatur pemutusan dan pergeseran pointer saat menghapus elemen di posisi awal, akhir, maupun setelah node tertentu, menghitung sisa elemen secara berurutan, serta membersihkan seluruh node dari memori secara aman.

File main.cpp bertindak sebagai program utama untuk menjalankan dan menguji seluruh operasi penghapusan tersebut secara berurutan. Program membentuk list awal, menghapus node 9 menggunakan deleteFirst, node 2 menggunakan deleteLast, dan node 8 menggunakan deleteAfter, lalu menampilkan hasil akhir susunan list, menghitung sisa elemen menggunakan nbList(), dan terakhir menghapus seluruh isi list lewat deleteList().


## Kesimpulan
Singly Linked List merupakan struktur data linier yang bersifat dinamis, di mana alokasi memorinya diatur pada saat runtime melalui penggunaan pointer. Setiap simpul (node) di dalamnya terbagi menjadi komponen informasi untuk menampung data dan komponen penunjuk (next) yang mengarah ke simpul berikutnya, dengan elemen pertama diakses melalui penanda utama (First) dan elemen terakhir menunjuk ke nilai kosong (Nil).

Dari proses implementasi pemrogramannya, penerapan struktur data ini menggunakan konsep pemrograman modular yang memisahkan file header (.h), file implementasi (.cpp), dan file utama (main.cpp). Pengelolaan memori dilakukan secara manual dan sistematis menggunakan fungsi alokasi dan dealokasi (new dan delete) guna mengoptimalkan penggunaan memori komputer serta mencegah terjadinya kebocoran memori (memory leak).

Secara keseluruhan, rangkaian Soal Guided dan Soal Unguided membuktikan bahwa Singly Linked List sangat fleksibel dalam mendukung berbagai operasi manipulasi data, mulai dari penyisipan (insert), penghapusan selektif (delete), hingga fungsi penelusuran (traversal) dan utilitas untuk menghitung jumlah node aktif. Hal ini memberikan pemahaman yang lebih jauh mengenai penerapan Abstract Data Type (ADT) dan logika pointer secara mendalam dalam bahasa C++.


## Referensi
<br> [1] ResearchGate. (2025). *Linked List in C++*. ResearchGate Technical Publication. https://www.researchgate.net/publication/387794369_Linked_List_in_C
<br> [2] Scribd. (2025). *C++ Singly Linked List Implementation and Operations.* Practical Laboratory Manual of Data Structures and Algorithms. https://www.scribd.com/document/822604030/DSA-LAB-05-SINGLY-LINKED-LIST