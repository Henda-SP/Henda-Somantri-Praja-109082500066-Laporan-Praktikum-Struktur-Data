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