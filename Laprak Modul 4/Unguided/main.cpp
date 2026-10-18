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