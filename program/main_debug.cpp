#include <iostream>
#include "Pilha.h"


int main(){
    int* a = new int(5);
    int* b = new int(0);
    Pilha P = Pilha();
    P.Empilha(a, b);

    int* c = new int(2);
    int* d = new int(3);
    P.Empilha(c, d);

    int* x;
    int* y;
    P.Desempilha(x, y);

    P.Desempilha(x, y);

    delete a;
    delete b;
    delete c;
    delete d;
    return 0;
}