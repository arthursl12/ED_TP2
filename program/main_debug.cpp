#include <iostream>
#include "Pilha.h"


int main(){
    Pilha P = Pilha();
    int* C = new int[20];
    for (int i = 0; i < 20; i++) C[i] = i;
    int* D = new int[2];
    for (int i = 6; i > 4; i--) D[i] = i;
    P.Adiciona(&C);
    P.Adiciona(&D);

    int* E = P.Retira();

    int* F = P.Retira();

    delete[] C;
    delete[] D;

    return 0;
}