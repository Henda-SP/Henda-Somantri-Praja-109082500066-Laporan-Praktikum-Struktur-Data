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