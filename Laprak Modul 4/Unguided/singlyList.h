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