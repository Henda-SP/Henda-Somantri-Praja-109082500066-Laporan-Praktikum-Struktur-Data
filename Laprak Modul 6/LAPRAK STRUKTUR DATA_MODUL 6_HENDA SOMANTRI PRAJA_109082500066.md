# <h1 align="center">LAPORAN PRAKTIKUM MODUL 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<h3 align="center">HENDA SOMANTRI PRAJA - 109082500066</h3>

## Dasar Teori
Doubly linked list atau senarai berantai ganda merupakan salah satu bentuk struktur data linier dinamis yang terdiri dari kumpulan elemen data (node) yang saling terhubung melalui dua arah pointer, yaitu penunjuk simpul berikutnya (next) dan penunjuk simpul sebelumnya (prev) [1]. Berbeda dengan senarai tunggal, keberadaan pointer ganda pada doubly linked list memungkinkan penelusuran data dilakukan secara fleksibel dari dua arah berlawanan, baik dari simpul awal ke akhir maupun sebaliknya [2].

### A. Konsep Dasar Doubly Linked List dan Manajemen Memori Dinamis<br/>

#### 1. Pengertian dan Karakteristik Doubly Linked List
Doubly linked list adalah senarai berantai di mana setiap node dilengkapi dengan dua jalur pointer, yakni field next untuk mengakses simpul sesudahnya dan field prev untuk mengakses simpul sebelumnya [1]. Keberadaan penanda batas awal (First atau Head) dan batas akhir (Last atau Tail) pada struktur list ini mempermudah pengelolaan akses data secara dua arah [2].
#### 2. Struktur Node dan Pointer (address, next, prev)
Secara struktur, setiap simpul dalam doubly linked list terdiri atas komponen informasi (field info) untuk menyimpan data, serta dua buah komponen pointer (next dan prev) yang masing-masing merujuk ke alamat memori [1]. Penggunaan alias tipe data pointer (address) sangat esensial dalam bahasa pemrograman seperti C++ untuk mengatur keterhubungan antar-simpul secara akurat [2].
#### 3. Manajemen Memori Dinamis (Alokasi dan Dealokasi)
Alokasi memori pada doubly linked list dilakukan secara dinamis pada saat runtime melalui fungsi alokasi untuk memesan ruang simpul baru di area heap, serta prosedur dealokasi untuk menghapus dan mengembalikan memori simpul yang sudah tidak digunakan ke sistem operasi guna mencegah terjadinya kebocoran memori (memory leak) [1,2].

### B. Operasi Dasar Penambahan, Penampilan, Pencarian, dan Penghapusan Data pada Doubly Linked List<br/>

#### 1. Operasi Penambahan Data (Insertion)
Operasi penambahan data bertujuan untuk menyisipkan simpul baru ke dalam senarai, di mana proses ini seringkali disertai mekanisme validasi pencarian terlebih dahulu untuk mencegah terjadinya duplikasi data, serta penyisipan elemen di akhir list (insertLast) dengan memperbarui pointer next dan prev secara presisi [1,2].
#### 2. Operasi Penampilan Data (Traversal / PrintInfo)
Traversal adalah prosedur penelusuran seluruh elemen di dalam doubly linked list secara berurutan untuk menampilkan informasi data ke layar konsol, yang pada implementasi tertentu dapat dilakukan dari simpul akhir (Last) menuju simpul awal (First) menggunakan penunjuk prev [1,2].
#### 3. Operasi Pencarian Data (Searching / findElm)
Pencarian data merupakan proses melacak keberadaan suatu elemen tertentu di dalam senarai berdasarkan kunci atau atribut unik (seperti kode buku) menggunakan fungsi findElm, yang bekerja dengan menelusuri simpul demi simpul hingga data ditemukan atau mencapai batas akhir list [1,2].
#### 4. Operasi Penghapusan Data (Deletion)
Penghapusan data bertujuan untuk membuang simpul tertentu dari senarai serta membebaskan memorinya, yang mencakup penghapusan simpul pertama (deleteFirst), penghapusan simpul terakhir (deleteLast), penghapusan simpul setelah simpul tertentu (deleteAfter), hingga prosedur pembungkus utama (deleteElm) yang menjaga integritas pointer dua arah agar tidak terputus [1,2].


## Guided (Contoh Soal)

### 1. Guided 1

### 1.1 Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype
{
    std::string nopol;
    std::string warna;
    int thnBuat;
};
typedef struct elmlist *address;
struct elmlist
{
    infotype info;
    address next;
    address prev;
};
struct List
{
    address First;
    address Last;
};

// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2
address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

### 1.2 Doublylist.cpp

```C++
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```

### 1.3 main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```

### Penjelasan
File Doublylist.h berfungsi sebagai kerangka atau rancangan utama dari program Doubly Linked List yang dibuat. Di dalam file ini, didefinisikan struktur data infotype yang berisi atribut kendaraan (nopol, warna, thnBuat), serta struktur elemen list (elmlist) yang memiliki dua buah pointer penunjuk arah, yaitu next (menuju elemen sesudahnya) dan prev (menuju elemen sebelumnya). Selain itu, didefinisikan pula struktur List pointer First dan Last untuk mencatat batas awal dan akhir dari list. File ini juga memuat seluruh deklarasi fungsi dan prosedur (prototype) seperti alokasi, insert, searching, hingga penghapusan, agar dapat dikenali dan digunakan oleh file program DoublyList.cpp.

File Doublylist.cpp berisi penjabaran dari seluruh fungsi dan prosedur yang sebelumnya sudah dideklarasikan di file Doublylist.h. Di sinilah konsep dasar Doubly Linked List diterapkan menggunakan pointer, seperti prosedur insertLast yang mengatur keterhubungan dua arah (next dan prev) saat menambahkan data baru di akhir list, fungsi findElm untuk menelusuri elemen berdasarkan kriteria tertentu, serta kumpulan prosedur penghapusan (deleteFirst, deleteLast, deleteAfter, dan deleteElm) yang secara presisi memutus dan menyambungkan kembali pointer next serta prev agar struktur list tetap rapi tanpa mengalami memory leak (kebocoran memori).

File main.cpp bertindak sebagai pusat pengendali program tempat fungsi int main() berada. File main.cpp berfungsi untuk mengintegrasikan seluruh modul yang ada, program mengeksekusi tahapan program secara berurutan: mulai dari meminta masukan data kendaraan dengan validasi pencegahan duplikasi nomor polisi, mencetak seluruh isi list dari belakang ke depan (Last ke First), melakukan pencarian data tertentu, hingga mengeksekusi penghapusan data berdasarkan permintaan pengguna dan menampilkan kembali kondisi akhir dari Doubly Linked List tersebut.


## Unguided (Soal Latihan)

### 1. Unguided 1, 2, dan 3

### 1, 2, dan 3 (Buku.h)
Buatlah ADT Doubly Linked List sebagai berikut di dalam file "Buku.h":

```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>

#define Nil NULL

// Struktur infotype untuk Buku
struct infotype
{
    std::string kodeBuku;
    std::string judul;
    int thnTerbit;
};

typedef struct elmlist *address;

struct elmlist
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

// Latihan 1 : fungsi dan prosedur dasar
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2: Searching
address findElm(List L, std::string kodeBuku);

// Latihan 3: Delete
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string kodeBuku, bool &status);

#endif
```

### 1, 2, dan 3 (Buku.cpp)
Buatlah implementasi ADT Doubly Linked List pada file "Buku.cpp" dan cobalah hasil implementasi ADT tersebut pada file "main.cpp". Pastikan sistem melakukan pengecekan duplikasi kodeBuku sebelum memasukkan data baru ke dalam list.

```C++
#include "Buku.h"

// Latihan 1: Masukkan data
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "Kode Buku    : " << P->info.kodeBuku << std::endl;   
        std::cout << "Judul        : " << P->info.judul << std::endl;   
        std::cout << "Tahun Terbit : " << P->info.thnTerbit << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2: Pencarian elemen berdasarkan kode buku
address findElm(List L, std::string kodeBuku) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kodeBuku) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3: Pengahapusan elemen berdasarkan kode buku
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string kodeBuku, bool &status) {
    address P = findElm(L, kodeBuku);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```

### 1, 2, dan 3 (main.cpp)
Cobalah hasil implementasi ADT tersebut pada file "main.cpp". Pastikan sistem melakukan pengecekan duplikasi kodeBuku sebelum memasukkan data baru ke dalam list.

```C++
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
```

### Output Unguided 1 (Menampilkan hasil masukkan data dan list data) :
![Output Unguided 1](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%206/Output%20Unguided%201.png)

### Penjelasan Unguided 1 (Menampilkan hasil masukkan data dan list data) :
File Buku.h pada unguided ini dirancang untuk mendefinisikan kerangka struktur data dasar Doubly Linked List khusus untuk entitas buku. Di dalam file ini, dideklarasikan tipe bentukan infotype yang menyimpan atribut buku (kodeBuku, judul, thnTerbit), struktur elemen list (elmlist) yang dilengkapi dua buah pointer penunjuk arah yaitu next dan prev, serta struktur List yang memegang pointer batas awal (First) dan akhir (Last). Selain itu, dideklarasikan juga prototipe fungsi dasar seperti CreateList, alokasi, dealokasi, printInfo, dan insertLast.

File Buku.cpp mengimplementasikan struktur Doubly Linked List, seperti prosedur insertLast bekerja dengan cara mengaitkan pointer next dan prev secara dua arah setiap kali sebuah simpul baru ditambahkan ke bagian akhir list. Sementara itu, prosedur printInfo menelusuri list mulai dari pointer Last menuju First menggunakan penunjuk prev, sehingga data buku yang terakhir dimasukkan dapat ditampilkan lebih dulu.

File main.cpp bertindak sebagai pusat kendali utama untuk menguji proses input data. Melalui fungsi inputData, program meminta masukan informasi buku dari pengguna dan memanfaatkan fungsi findElm sebagai mekanisme validasi untuk memeriksa duplikasi kodeBuku sebelum data baru dialokasikan serta dimasukkan ke dalam list. Jika kode buku terdeteksi sudah terdaftar, sistem akan menolak penyisipan dan mencetak pesan peringatan, dan setelah seluruh data valid masuk, program memanggil prosedur printInfo untuk menampilkan keseluruhan isi Doubly Linked List.


### Output Unguided 2 (Menampilkan hasil pencarian data tertentu) :
![Output Unguided 2](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%206/Output%20Unguided%202.png)

### Penjelasan Unguided 2 (Menampilkan hasil pencarian data tertentu):
File Buku.h pada bagian pencarian memuat deklarasi fungsi findElm yang berfungsi sebagai antarmuka pencarian elemen. Dengan memanfaatkan struktur data Doubly Linked List yang telah terhubung melalui pointer next dan prev, file header ini memastikan bahwa fungsi pencarian dikenali oleh program lainnya untuk mendeteksi keberadaan suatu data berdasarkan kodeBuku.

File Buku.cpp berisi implementasi dari fungsi findElm. Fungsi ini bekerja dengan cara menginisialisasi sebuah pointer penelusuran mulai dari simpul First hingga akhir list (Nil), lalu mencocokkan atribut kodeBuku pada setiap elemen yang dikunjungi. Jika data yang dicari ditemukan, fungsi akan mengembalikan alamat (address) dari simpul tersebut, namun jika penelusuran selesai tanpa hasil, fungsi akan mengembalikan nilai Nil.

File main.cpp mengintegrasikan hasil fungsi pencarian. Bagian ini meminta masukan berupa kode buku yang ingin dicari, lalu memanggil fungsi findElm. Jika alamat yang dikembalikan bukan Nil, program akan mencetak secara terperinci atribut buku tersebut (kode buku, judul, dan tahun terbit), dan menampilkan pesan pemberitahuan jika data tidak ditemukan.


### Output Unguided 3 (Menampilkan hasil penghapusan data tertentu) :
![Output Unguided 3](https://github.com/Henda-SP/Henda-Somantri-Praja-109082500066-Laporan-Praktikum-Struktur-Data/blob/main/Laprak%20Modul%206/Output%20Unguided%203.png)

### Penjelasan Unguided 3 (Menampilkan hasil penghapusan data tertentu):
File Buku.h berisi deklarasi prosedur penghapusan yang lengkap untuk struktur Doubly Linked List. Prosedur-prosedur tersebut meliputi deleteFirst, deleteLast, deleteAfter, serta prosedur pembungkus utama deleteElm. Deklarasi ini dirancang agar sistem mampu menangani skenario penghapusan simpul di berbagai posisi (awal, tengah, maupun akhir list) secara aman dan terstruktur.

File Buku.cpp mengimplementasikan logika pemutusan dan penyambungan kembali pointer dua arah dalam Doubly Linked List saat sebuah elemen dihapus. Prosedur utama deleteElm terlebih dahulu mencari posisi data menggunakan findElm, lalu mengarahkan eksekusi ke prosedur deleteFirst, deleteLast, atau deleteAfter berdasarkan letak simpul tersebut. Setelah pointer next dan prev pada elemen di sekitarnya diperbarui untuk menutup celah, memori simpul yang dihapus akan langsung dikembalikan ke sistem melalui prosedur dealokasi guna mencegah terjadinya kebocoran memori (memory leak).

File main.cpp mengeksekusi tahapan akhir di mana pengguna dapat menghapus data buku tertentu berdasarkan kodeBuku yang diinputkan. Program memanggil prosedur deleteElm untuk memproses penghapusan, memberikan status kepada pengguna bahwa data berhasil dihapus, lalu mencetak kembali kondisi akhir dari Doubly Linked List menggunakan printInfo guna membuktikan bahwa elemen target telah berhasil dihilangkan dari struktur list.


## Kesimpulan
Berdasarkan landasan teori dan implementasi program yang telah dilakukan, Doubly Linked List terbukti sebagai struktur data linier dinamis yang efektif dalam mengelola koleksi data melalui pemanfaatan dua arah pointer, yaitu next dan prev. Struktur ini memungkinkan penelusuran data secara fleksibel dari dua arah berlawanan, didukung oleh manajemen memori dinamis di area heap melalui fungsi alokasi dan dealokasi yang menjaga efisiensi serta mencegah terjadinya memory leak.

Dalam praktiknya, implementasi struktur data buku pada modul ini mencakup berbagai operasi dasar yang komprehensif, mulai dari penambahan data di akhir list (insertLast) yang dilengkapi validasi pencegahan duplikasi menggunakan fungsi pencarian (findElm), penelusuran data secara terbalik dari simpul akhir ke awal (printInfo), hingga prosedur penghapusan elemen secara fleksibel (deleteFirst, deleteLast, deleteAfter, dan deleteElm). Seluruh operasi tersebut dikoordinasikan secara presisi untuk menjaga integritas hubungan antar-simpul tanpa memutus koneksi dua arah pointer.

Secara keseluruhan,  pemahaman mendalam mengenai manipulasi pointer tingkat lanjut dalam bahasa pemrograman C++. Penggabungan antara kajian literatur teoretis dan implementasi kode sumber secara langsung melatih kemampuan analisis logika pemrograman, pengelolaan struktur data berbasis simpul (node), serta penerapan algoritma penanganan data dinamis yang sesuai dengan standar akademis.


## Referensi
<br> [1] Indo Jurnal Press. (2024). Analisis Struktur Data Linier dan Kompleksitas Operasi Koleksi. Jejak Digital Jurnal Informatika. https://indojurnal.com/index.php/jejakdigital/article/download/3013/2614/8370
<br> [2] ResearchGate. (2025). Algorithm 2 Labs - Linked List. ResearchGate Academic Laboratory Publication. https://www.researchgate.net/publication/389392581_Algorithm_2_Labs_-Linked_List