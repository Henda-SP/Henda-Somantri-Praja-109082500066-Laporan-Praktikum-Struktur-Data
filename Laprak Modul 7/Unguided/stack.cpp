#include "stack.h"

/* Implementasi Soal 1: Menampilkan daftar stack */
void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top = S.top + 1;
        S.info[S.top - 1] = x;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (S.top > 0) {
        x = S.info[S.top - 1];
        S.top = S.top - 1;
    } else {
        cout << "Stack kosong" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 1; i--) {
        cout << S.info[i - 1] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top > 0) {
        push(temp, pop(S));
    }
    S = temp;
}

/* Implementasi Soal 2: Push secara terurut membesar dari bawah ke TOP */
void pushAscending(Stack &S, int x) {
    Stack temp;
    createStack(temp);
    
    // Pindahkan elemen yang lebih besar dari x ke stack sementara
    while (S.top > 0 && S.info[S.top - 1] > x) {
        push(temp, pop(S));
    }
    
    // Masukkan x di posisi yang tepat
    push(S, x);
    
    // Kembalikan elemen dari stack sementara ke stack utama
    while (temp.top > 0) {
        push(S, pop(temp));
    }
}

/* Implementasi Soal 3: Membaca karakter satu per satu hingga tombol Enter ditekan */
void getInputStream(Stack &S) {
    char ch;
    while (cin.get(ch) && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0');
        }
    }
}