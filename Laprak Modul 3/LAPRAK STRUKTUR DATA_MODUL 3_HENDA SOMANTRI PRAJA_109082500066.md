# <h1 align="center">LAPORAN PRAKTIKUM MODUL 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">HENDA SOMANTRI PRAJA - 109082500066</p>

## Dasar Teori
Struct atau struktur data bentukan adalah salah satu bentuk tipe data kustom yang memungkinkan pengelompokan beberapa variabel dengan tipe data yang berbeda ke dalam satu kesatuan nama untuk merepresentasikan objek data yang kompleks[1]. Penggunaan struct berkaitan erat dengan konsep Abstract Data Type (ADT) atau Tipe Data Abstrak, yaitu model konseptual yang memisahkan antara spesifikasi fungsional dari detail implementasi teknisnya, yang dalam praktiknya diwujudkan melalui pemisahan file header dan file implementasi kode[1].

Pointer adalah variabel khusus yang berfungsi untuk menyimpan alamat memori dari variabel lain alih-alih nilai datanya secara langsung[2]. Pemanfaatan pointer serta mekanisme pass by reference (&) pada parameter fungsi memungkinkan program untuk mengakses, memanipulasi, dan mengubah nilai variabel asli secara langsung di dalam memori tanpa perlu menduplikasi data tersebut[2].

## Guided (Contoh Soal)

### 1. mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif //MAHASISWA_H_INCLUDED
```
### Penjelasan
File mahasiswa.h merupakan file header, file ini berfungsi sebagai kerangka dari ADT mahasiswa. Di dalamnya terdapat definisi struktur (struct) bernama mahasiswa yang menampung data berupa NIM dan dua buah nilai ujian. Selain itu, file ini juga mendeklarasikan prototipe fungsi inputMhs dan rata2 yang akan diimplementasikan pada file terpisah.

### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}
float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;
}
```
### Penjelasan
File mahasiswa.cpp merupakan file implementasi, file ini berisi isi fungsi-fungsi yang sebelumnya sudah dideklarasikan di file header. Fungsi inputMhs bertugas untuk meminta pengguna memasukkan data NIM dan nilai ke dalam objek mahasiswa menggunakan mekanisme pass by reference (&), sehingga data asli dapat langsung terisi. Sementara itu, fungsi rata2 digunakan untuk menghitung dan mengembalikan hasil rata-rata dari kedua nilai ujian dalam bentuk bilangan desimal (float).

### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
### Penjelasan
File main.cpp merupakan file program utama ,file ini digunakan untuk  menjalankan program, program memanggil file header mahasiswa.h untuk mengenali struktur dan fungsi yang telah dibuat. Di dalamnya, program mendeklarasikan sebuah variabel bertipe mahasiswa bernama mhs, lalu secara berurutan memanggil fungsi inputMhs untuk mengisi datanya dan fungsi rata2 untuk menghitung serta menampilkan hasil rata-rata nilai ke layar.

## Unguided (Soal Latihan)

### 1. Unguided 1
 Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>

using namespace std;

struct mahasiswa {
    char nama[50];
    char nim[10];
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> n;

    if (n > 10) {
        n = 10;
    }

    mahasiswa mhs[10];
    
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << " Nama : ";
        cin >> mhs[i].nama;
        cout << " NIM : ";
        cin >> mhs[i].nim;
        cout << " Nilai UTS : ";
        cin >> mhs[i].uts;
        cout << " Nilai UAS : ";
        cin >> mhs[i].uas;
        cout << " Nilai Tugas : ";
        cin >> mhs[i].tugas;
    
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    cout << "\n--- Daftar Nilai Akhir Mahasiswa ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}
```
### Output Unguided 1 :
![Output Unguided Soal-1.png](https://github.com/Henda-SP/Laporan-Praktikum-Struktur-Data/blob/main/Output%20Unguided%20Soal-1.png)

### Penjelasan
Program ini menggunakan struktur data (struct) mahasiswa untuk menampung data nama, NIM, nilai UTS, UAS, tugas, serta nilai akhir, dan dilengkapi fungsi hitungNilaiAkhir untuk menjumlahkan bobot nilai secara otomatis. Di dalam fungsi main, program meminta pengguna memasukkan jumlah data (maksimal 10), lalu melakukan perulangan untuk menginput data ke dalam array sekaligus memanggil fungsi perhitungan nilai akhir. Terakhir, program mencetak hasil nilai akhir yang terlah di jumlahkan sesuai dengan jumlah data yang dimasukkan, dimana data yang berisi nama, NIM, dan nilai akhir seluruh mahasiswa dan menampilkannya ke layar. 

### 2. Unguided 2

#### 2.1 pelajaran.h
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h"
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>

using namespace std;

struct pelajaran {
    string namapel;
    string kodepel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif //PELAJARAN_H_INCLUDED
```

#### 2.2 pelajaran.cpp
Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
```C++
#include "pelajaran.h"
#include <iostream>

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel){
    pelajaran pel;
    pel.namapel = namapel;
    pel.kodepel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namapel << endl;
    cout << "Nilai : " << pel.kodepel << endl;
}
```
#### 2.3 main.cpp
Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "SDT";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

### Output Unguided 2 :
![Output Unguided Soal-2.png](https://github.com/Henda-SP/Laporan-Praktikum-Struktur-Data/blob/main/Output%20Unguided%20Soal-2.png)

### Penjelasan
Program ini terdiri dari tiga bagian utama yang menerapkan konsep ADT (Abstract Data Type):
- File pelajaran.h berfungsi sebagai header untuk mendefinisikan struktur pelajaran yang berisi variabel namapel dan kodepel, sekaligus mendeklarasikan fungsi create_pelajaran dan tampil_pelajaran. 
- File pelajaran.cpp berisi implementasi dari fungsi-fungsi tersebut, di mana create_pelajaran bertugas menginisialisasi dan mengembalikan objek pelajaran, sedangkan tampil_pelajaran digunakan untuk mencetak informasi nama dan kode pelajaran. 
- File main.cpp menjalankan program utama dengan mendefinisikan variabel nama dan kode pelajaran, lalu memanggil fungsi pembuatan data dan menampilkannya sebagai output.

### Unguided 3
Buatlah program dengan ketentuan :
  - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
  - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
  - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
  - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer
```C++
#include <iostream>

using namespace std;

// Fungsi/prosedur untuk menampilkan array 2D
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
    }
}

// Fungsi/prosedur untuk menukar isi 2 array 2D pada posisi tertentu
void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi/prosedur untuk menukar nilai dari variabel oleh 2 pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    // 2 buah array 2D ukuran 3x3
    int A[3][3] = {
        {7, 2, 9},
        {4, 1, 6},
        {8, 3, 5}
    };

    int B[3][3] = {
        {3, 8, 1},
        {5, 9, 2},
        {6, 7, 4}
    };

    // 2 buah pointer integer
    int x = 42;
    int y = 17;
    int *ptr1 = &x;
    int *ptr2 = &y;

    // Menampilkan isi array sebelum ditukar
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    // Menukar isi array pada posisi baris 1, kolom 1 indeks [1][1]
    tukarArray(A, B, 1, 1);

    cout << "\nSetelah array ditukar pada posisi [1][1]:\n";
    cout << "Array A;\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    // Menukar nilai variabel dengan pointer
    cout << "\nSebelum pointer ditukar: *pointer1 = " << *ptr1 << ", *pointer2 = " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    cout << "setelah pointer ditukar: *pointer1 = " << *ptr1 << ", *pointer2 = " << *ptr2 << endl;

    return 0;
}
```
### Output Unguided 3 :
![Output Unguided Soal-3.png](https://github.com/Henda-SP/Laporan-Praktikum-Struktur-Data/blob/main/Output%20Unguided%20Soal-3.png)

### Penjelasan
Program ini terdiri dari tiga fungsi utama, fungsi tampilArray digunakan untuk mencetak isi array 2D berukuran 3x3, sedangkan tukarArray berfungsi untuk menukar nilai elemen tertentu pada posisi baris dan kolom tertentu di antara dua array menggunakan variabel sementara (temp). Selain itu, terdapat fungsi tukarPointer yang memanfaatkan pointer untuk menukar nilai dari dua variabel. Di dalam fungsi main, program mendeklarasikan dua buah array 2D (A dan B) serta dua variabel integer yang ditunjuk oleh ptr1 dan ptr2, lalu menampilkan kondisi awal, mengeksekusi fungsi penukaran elemen array pada posisi [1][1] serta penukaran nilai melalui pointer, dan terakhir mencetak hasil akhir perubahannya ke layar.

## Kesimpulan
Berdasarkan materi dan latihan kode C++ modul 3 ini berfokus pada penerapan konsep pemrograman terstruktur, mulai dari penggunaan struktur data bentukan (struct), pengolahan Abstract Data Type (ADT), manipulasi array, hingga pemahaman dasar mengenai pointer. Melalui modul guided dan unguided, telah dipelajari cara memisahkan kode program ke dalam file header (.h) dan file implementasi (.cpp) agar program lebih terstruktur, mudah dibaca, serta dapat dijalankan dengan baik. Selain itu, pembelajaran mencakup pembuatan tipe data kustom menggunakan struct untuk menggabungkan berbagai jenis tipe data seperti pada data mahasiswa dan pelajaran, serta penerapan pola ADT untuk penerapan fungsi pembentukan dan penampilan objek. Dalam hal pengolahan data, telah digunakan penggunaan array 2D berukuran 3x3 untuk menukar elemen matriks pada posisi tertentu. Dengan demikian materi ini memperkuat pemahaman mengenai mekanisme parameter fungsi, penggunaan pass by reference agar data asli langsung berubah, serta pemanfaatan pointer untuk menukar nilai antarvariabel secara langsung melalui alamat memorinya.

## Referensi
<br> [1] Sindar, A. (2019). Struktur Data dan Algoritma dengan C++. ResearchGate. https://www.researchgate.net/profile/Anita-Sindar/publication/337657500_STRUKTUR_DATA_DAN_ALGORITMA_DENGAN_C/links/5de3c560299bf10bc33628a2/STRUKTUR-DATA-DAN-ALGORITMA-DENGAN-C.pdf
<br> [2] Stroustrup, B. (1993). A History of C++: 1979−1991. ResearchGate. https://www.researchgate.net/publication/269031890_A_history_of_C