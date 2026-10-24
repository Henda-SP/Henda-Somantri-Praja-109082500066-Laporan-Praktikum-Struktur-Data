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