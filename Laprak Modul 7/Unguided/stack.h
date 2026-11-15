/* file : stack.h
   ADT Stack dengan representasi array */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

/* Prototipe Soal 1 */
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

/* Prototipe Soal 2 */
void pushAscending(Stack &S, int x);

/* Prototipe Soal 3 */
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED