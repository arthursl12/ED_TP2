#include <iostream>
#include "QC.h"

int IndicePivot(int Esq, int Dir, int* A){
    return (Esq + Dir)/2;
}

void Particao(int Esq, int Dir, int& i, int& j, int* A){
    i = Esq;
    j = Dir;
    int i_pivot = IndicePivot(Esq, Dir, A);
    int Pivot = A[i_pivot];
    
    do{
        while (A[i] < Pivot) i++;
        while (A[j] > Pivot) j--;

        if (i <= j){
            int temp = A[i]; A[i] = A[j]; A[j] = temp;
            i++;
            j--;
        }

    }while (i <= j);
}

void Ordena(int Esq, int Dir, int* A){
    int i; 
    int j;
    
    Particao(Esq, Dir, i, j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

void QC(int* A, int n){
    Ordena(0, n-1, A);
}