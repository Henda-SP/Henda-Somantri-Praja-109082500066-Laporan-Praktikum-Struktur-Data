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