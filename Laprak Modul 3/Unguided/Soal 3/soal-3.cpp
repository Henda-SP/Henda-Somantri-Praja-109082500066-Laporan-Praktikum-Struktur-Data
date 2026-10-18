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