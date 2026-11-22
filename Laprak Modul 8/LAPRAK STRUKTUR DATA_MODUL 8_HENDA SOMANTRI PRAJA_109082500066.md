# <h1 align="center">LAPORAN PRAKTIKUM MODUL 8 - QUEUE</h1>
<h3 align="center">HENDA SOMANTRI PRAJA - 109082500066</h3>

## Dasar Teori
Queue atau yang biasa disebut antrean merupakan struktur data linier yang bekerja dengan prinsip First In, First Out (FIFO). Artinya, elemen yang pertama kali masuk ke dalam antrean akan menjadi elemen pertama yang keluar atau dilayani terlebih dahulu [1]. Berbeda dengan stack yang hanya menggunakan satu ujung, proses pada queue berlangsung pada dua ujung yang berbeda, yaitu penambahan data di bagian belakang (tail/rear) dan pengambilan atau penghapusan data di bagian depan (head/front) [1, 2].

### A. Konsep Dasar Queue dan Variasi Indeks<br/>
#### 1. Karakteristik, Prinsip FIFO, dan Kondisi Antrean
Cara kerja queue menyerupai antrean di loket atau kasir, di mana yang datang lebih awal akan diproses lebih dulu. Dalam implementasi berbasis array, antrean kosong umumnya ditandai dengan head = -1 dan tail = -1, sedangkan kondisi penuh (isFull) bergantung pada skema indeks dan kapasitas maksimum yang ditetapkan [1, 2].
#### 2. Representasi Pointer (Linked List) dan Tabel (Array)
Dalam pemrograman C++, queue dapat direalisasikan menggunakan pointer (linked list) dengan alokasi dan dealokasi memori secara dinamis melalui simpul (info dan next), maupun menggunakan tabel (array) berukuran tetap [1, 2]. Pada pendekatan array, pergerakan indeks head dan tail dapat dibedakan menjadi antrean linear statis (head diam, tail bergerak dengan pergeseran elemen saat dequeue), antrean linear dinamis (head dan tail sama-sama bergerak maju), serta circular queue (head dan tail bergerak melingkar menggunakan operasi modulo %) [1, 2].

### B. Operasi Dasar pada Queue<br/>
#### 1. Operasi Penyisipan (Enqueue)
Enqueue adalah operasi untuk memasukkan elemen baru ke posisi belakang (tail) antrean [1]. Jika antrean masih kosong, head dan tail diatur ke posisi awal yang sama sebelum mengisi data, sedangkan jika sudah berisi, tail digerakkan (maju atau melingkar sesuai alternatif) lalu data ditempatkan pada indeks atau simpul baru tersebut [1, 2].
#### 2. Operasi Pengambilan (Dequeue)
Dequeue berfungsi untuk mengambil sekaligus menghapus elemen yang berada di posisi paling depan (head) antrean [1, 2]. Sebelum dijalankan, perlu dipastikan antrean tidak kosong agar tidak terjadi underflow, dan jika elemen terakhir telah dihapus, posisi head serta tail dikembalikan ke kondisi kosong (-1 pada array atau Nil pada linked list) [1, 2].
#### 3. Fungsi Pendukung (CreateQueue, IsEmpty, IsFull, PrintInfo / ViewQueue)
Selain operasi utama, queue dilengkapi fungsi pendukung seperti createQueue untuk menginisialisasi antrean awal, isEmpty dan isFull untuk memeriksa status antrean, serta printInfo atau viewQueue untuk menampilkan isi antrean beserta posisi indeks atau simpulnya [1, 2].

## Guided (Contoh Soal)

### 1. Guided 1

### 1.1 queue.h

```C++
#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>
using namespace std;

#define Nil NULL

typedef bool boolean;
typedef int infotype;
typedef struct elmQ *address;

struct elmQ {
    infotype info;
    address next;
};

struct queue {
    address head, tail;
};

boolean isEmpty(queue Q);
void CreateQueue(queue &Q);
address alokasi(infotype X);
void dealokasi(address P);
address findElm(queue Q, infotype X);
boolean fFindElm(queue Q, address P);
void insert(queue &Q, address P);
void deleteQueue(queue &Q, address &P);
void printInfo(queue Q);
int nbList(queue Q);
void delAll(queue &Q);

#endif
```

### 1.2 queue.cpp

```C++
#include "queue.h"

boolean isEmpty(queue Q) {
    return (Q.head == Nil);
}

void CreateQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

address alokasi(infotype X) {
    address P = new (nothrow) elmQ;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

address findElm(queue Q, infotype X) {
    address P = Q.head;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

boolean fFindElm(queue Q, address P) {
    address R = Q.head;
    while (R != Nil) {
        if (R == P) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void insert(queue &Q, address P) {
    if (isEmpty(Q)) {
        Q.head = P;
        Q.tail = P;
    } else {
        (Q.tail)->next = P;
        Q.tail = P;
    }
}

void deleteQueue(queue &Q, address &P) {
    P = Q.head;
    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = P->next;
    }
    P->next = Nil;
}

void printInfo(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        address P = Q.head;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

int nbList(queue Q) {
    int jumlah = 0;
    address P = Q.head;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void delAll(queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        deleteQueue(Q, P);
        dealokasi(P);
    }
}
```

### 1.3 main.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue Q;
    address P;

    CreateQueue(Q);
    cout << "isEmpty : " << isEmpty(Q) << endl;
    printInfo(Q);

    insert(Q, alokasi(5));
    insert(Q, alokasi(2));
    insert(Q, alokasi(7));
    cout << "Setelah insert 5, 2, 7" << endl;
    printInfo(Q);
    cout << "nbList  : " << nbList(Q) << endl;

    P = findElm(Q, 2);
    if (P != Nil) {
        cout << "findElm(2) ketemu, info : " << P->info << endl;
        cout << "fFindElm : " << fFindElm(Q, P) << endl;
    }
    if (findElm(Q, 9) == Nil) {
        cout << "findElm(9) tidak ketemu" << endl;
    }

    deleteQueue(Q, P);
    cout << "Setelah delete, elemen yang dihapus : " << P->info << endl;
    dealokasi(P);
    printInfo(Q);

    delAll(Q);
    cout << "Setelah delAll" << endl;
    printInfo(Q);
    cout << "isEmpty : " << isEmpty(Q) << endl;

    return 0;
}
```

### Penjelasan
Pada bagian file queue.h, didefinisikan struktur data queue berbasis pointer (linked list) beserta prototype primitifnya. Struktur elmQ merepresentasikan tiap simpul antrean dengan data info (int) dan penunjuk next (address), sedangkan struktur queue menyimpan penunjuk head (elemen terdepan) dan tail (elemen terakhir), di mana Nil (NULL) menandakan pointer kosong serta terdapat include guard (#ifndef QUEUE_H_INCLUDE) agar header tidak dimuat ganda.

Pada bagian file queue.cpp, seluruh fungsi dan prosedur primitif diimplementasikan untuk menjalankan prinsip FIFO (First In First Out). Operasi CreateQueue dan isEmpty mengatur serta memeriksa kondisi kosong (head == Nil), alokasi dan dealokasi mengelola memori dinamis secara manual, insert menambahkan elemen baru di bagian tail, dan deleteQueue mengambil/menghapus elemen dari bagian head, dilengkapi fungsi pencarian (findElm, fFindElm), pencetakan (printInfo), penghitungan jumlah elemen (nbList), serta pembersihan total (delAll).

Pada bagian file main.cpp, program utama menguji alur kerja queue secara berurutan mulai dari inisialisasi antrean kosong dengan CreateQueue, penyisipan nilai 5, 2, dan 7 melalui insert dan alokasi, pengecekan jumlah elemen serta pencarian nilai 2 dan 9, penghapusan elemen terdepan dengan deleteQueue diikuti dealokasi, hingga mengosongkan kembali seluruh isi antrean menggunakan delAll.


### 2. Guided 2

### 2.1 queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

### 2.2 queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

//dequeue implementasi 2
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        Q.head++;
        if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}
```

### 2.3 main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

### Penjelasan
Pada bagian file queue.h, didefinisikan struktur data queue berbasis array berukuran tetap (MAKSIMAL = 5) dengan elemen bertipe string (nama[MAKSIMAL]) serta penunjuk indeks head dan tail bertipe int. File header ini juga menyertakan include guard (#ifndef QUEUE_H) dan mendeklarasikan prototype fungsi maupun prosedur primitif utama seperti isFull, isEmpty, CreateQueue, enQueue, deQueue, dan viewQueue.

Pada bagian file queue.cpp, diimplementasikan operasi queue berprinsip FIFO (First In First Out) menggunakan array dengan inisialisasi head = -1 dan tail = -1 pada CreateQueue serta pengecekan kondisi kosong melalui isEmpty. File ini juga memuat variasi logika isFull, enQueue, deQueue, dan viewQueue untuk Implementasi 1 (head diam, tail bergerak dengan pergeseran elemen saat dequeue), Implementasi 2 (head dan tail bergerak maju), serta Implementasi 3 (head dan tail bergerak melingkar dengan modulo % MAKSIMAL). (Catatan: karena versi fungsi untuk Implementasi 2 dan 3 tidak diberi komentar pada kode yang diberikan, bagian yang tidak dipakai perlu dikomentari atau dipisah saat kompilasi agar tidak terjadi duplikasi definisi).

Pada bagian file main.cpp, program utama menjalankan skenario pengujian antrean dengan membuat variabel Q, menginisialisasinya lewat CreateQueue(Q), lalu menambahkan enam nama (Dimas, Arvin, Rizal, Hafizh, Fathur, dan Daffa) menggunakan enQueue. Setelah menampilkan isi antrean dengan viewQueue(Q), program melakukan empat kali penghapusan elemen terdepan menggunakan deQueue(Q) (sementara dua panggilan deQueue(Q) berikutnya masih dikomentari) sebelum akhirnya menampilkan kembali sisa isi antrean melalui viewQueue(Q).


## Unguided (Soal Latihan)

### 1. Unguided 1, 2, 3
1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file "queue.h". Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
2. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).
3. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 2 (head dan tail berputar).

### 1, 2, 3 queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAKSIMAL = 5;

typedef int infotype;

struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### 1, 2, 3 queue.cpp

```C++
#include "queue.h"

// NOTE :
// Alternatif 1 = head diam, tail bergerak
// Alternatif 2 = head bergerak, tail bergerak
// Alternatif 3 = head dan tail berputar (circular)

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    if (Q.head == -1 && Q.tail == -1) {
        return true;
    } else {
        return false;
    }
}

// ==========================================
// ALTERNATIF 1 (head diam, tail bergerak)
// ==========================================

bool isFullQueue(Queue Q) {
    if (Q.tail == MAKSIMAL - 1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        for (int i = 0; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    string ht = to_string(Q.head) + " - " + to_string(Q.tail);
    cout << " " << left << setw(7) << ht << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}


// ==============================================
// ALTERNATIF 2 (head bergerak, tail bergerak)
// ==============================================

bool isFullQueue(Queue Q) {
    if (Q.tail == MAKSIMAL - 1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        Q.head++;
        if (Q.head > Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    string ht = to_string(Q.head) + " - " + to_string(Q.tail);
    cout << " " << left << setw(7) << ht << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}


// ========================================
// ALTERNATIF 3 (head dan tail berputar)
// ========================================

bool isFullQueue(Queue Q) {
    if ((Q.tail + 1) % MAKSIMAL == Q.head) {
        return true;
    } else {
        return false;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    string ht = to_string(Q.head) + " - " + to_string(Q.tail);
    cout << " " << left << setw(7) << ht << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) {
                break;
            }
            i = (i + 1) % MAKSIMAL;
        }
    }
    cout << endl;
}
```

### 1, 2, 3 main.cpp

```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :


### Penjelasan Unguided 1 
Pada bagian file queue.h, didefinisikan struktur Queue berbasis array berukuran MAKSIMAL = 5 dengan elemen bertipe infotype (int), indeks head dan tail, serta deklarasi primitif createQueue, isEmptyQueue, isFullQueue, enqueue, dequeue, dan printInfo lengkap dengan include guard dan pustaka <iomanip> serta <string>.

Pada bagian file queue.cpp, Alternatif 1 menginisialisasi head dan tail ke -1 lewat createQueue, mengecek kekosongan antrean dengan isEmptyQueue, mendeteksi penuh saat Q.tail == MAKSIMAL - 1 pada isFullQueue, menambahkan elemen di Q.tail pada enqueue, menghapus elemen terdepan (Q.head) sambil menggeser sisa elemen ke depan dan menurunkan Q.tail-- pada dequeue (mereset ke -1 jika Q.tail < 0), serta menampilkan status H - T dan isi antrean lewat printInfo.

Pada bagian file main.cpp, program membuat Queue Q, memanggil createQueue(Q), mencetak header H - T dan Queue Info, lalu menjalankan urutan enqueue (5, 2, 7, 4) dan dequeue empat kali dengan printInfo(Q) di tiap langkah untuk mengamati head yang tetap di 0 sementara tail naik-turun.

### Output Unguided 2 :


### Penjelasan Unguided 2 
Pada bagian file queue.h, struktur Queue berkapasitas MAKSIMAL = 5 (array info, indeks head dan tail) beserta prototype seluruh fungsi primitif (createQueue, isEmptyQueue, isFullQueue, enqueue, dequeue, printInfo) dan pustaka pendukungnya dideklarasikan dengan include guard #ifndef QUEUE_H.

Pada bagian file queue.cpp, Alternatif 2 memakai createQueue dan isEmptyQueue yang sama untuk kondisi kosong (-1), mengecek penuh pada isFullQueue saat Q.tail == MAKSIMAL - 1, menambah data ke Q.tail lewat enqueue, namun pada dequeue menghapus elemen di Q.head cukup dengan menggeser indeks Q.head++ tanpa menggeser elemen array (mereset head dan tail ke -1 jika Q.head > Q.tail), lalu mencetak antrean dari indeks Q.head sampai Q.tail di printInfo.

Pada bagian file main.cpp, program menginisialisasi Q dengan createQueue(Q), menampilkan header tabel, lalu menjalankan rangkaian enqueue (5, 2, 7, 4) dan dequeue empat kali sambil mencetak printInfo(Q) di setiap tahap agar pergeseran maju head dan tail dapat terlihat.

### Output Unguided 3 :


### Penjelasan Unguided 3 
Pada bagian file queue.h, didefinisikan struktur Queue berukuran MAKSIMAL = 5 dengan array info, indeks head dan tail, serta deklarasi primitif createQueue, isEmptyQueue, isFullQueue, enqueue, dequeue, dan printInfo bersama include guard dan header <iomanip> serta <string>.

Pada bagian file queue.cpp, Alternatif 3 menginisialisasi antrean kosong (-1) lewat createQueue dan isEmptyQueue, memeriksa kondisi penuh secara melingkar pada isFullQueue dengan (Q.tail + 1) % MAKSIMAL == Q.head, menggerakkan Q.tail secara melingkar (% MAKSIMAL) pada enqueue, menggerakkan Q.head secara melingkar (% MAKSIMAL) pada dequeue (mereset ke -1 saat Q.head == Q.tail), serta menelusuri elemen secara melingkar hingga Q.tail pada printInfo.

Pada bagian file main.cpp, program membuat Queue Q, memanggil createQueue(Q), menampilkan header H - T dan Queue Info, lalu menjalankan serangkaian operasi enqueue (5, 2, 7, 4) dan dequeue empat kali disertai printInfo(Q) di setiap langkah untuk menguji pergerakan melingkar indeks head dan tail pada Alternatif 3.

## Kesimpulan
Secara keseluruhan, queue (antrean) adalah struktur data berprinsip FIFO (First In, First Out), di mana data yang masuk pertama kali akan keluar atau dilayani paling awal, dengan proses penambahan elemen di bagian belakang (tail/rear) dan pengambilan atau penghapusan di bagian depan (head/front). Dalam pemrograman C++, queue dapat diterapkan menggunakan pointer (linked list) yang mengalokasikan serta mendealokasikan memori secara dinamis lewat simpul (info dan next) dengan penunjuk head dan tail, maupun menggunakan array berkapasitas tetap (MAKSIMAL) dengan indeks head dan tail yang ditandai -1 saat antrean kosong.

Pada implementasi berbasis array, pergerakan indeks head dan tail terbagi menjadi tiga mekanisme, yaitu Alternatif 1 (head diam, tail bergerak) yang mempertahankan posisi awal dan menggeser elemen ke depan saat dequeue, Alternatif 2 (head bergerak, tail bergerak) yang menggeser indeks head maju tanpa menggeser isi array, serta Alternatif 3 (head dan tail berputar / circular) yang menggerakkan head dan tail secara melingkar menggunakan operasi modulo (% MAKSIMAL) agar ruang yang kosong dapat dipakai kembali. Selain itu, penyusunan program secara modular ke dalam file queue.h, queue.cpp, dan main.cpp memisahkan deklarasi struktur serta fungsi, implementasi operasi utama maupun pendukung (createQueue/CreateQueue, isEmpty/isEmptyQueue, isFull/isFullQueue, enqueue/insert, dequeue/deleteQueue, serta printInfo/viewQueue), dan pengujian alur antrean sehingga lebih rapi dan mudah diamati perbedaannya.


## Referensi
<br> [1] SoftwareSeni. (2025). Queue Adalah: Pengertian, Tipe, dan Contoh Implementasi. SoftwareSeni Blog. https://www.softwareseni.co.id/blog/queue-adalah-pengertian-tipe-dan-contoh-implementasi
<br> [2] GeeksforGeeks. (2025). C++ Program to Implement Circular Queue. GeeksforGeeks. https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-circular-queue/