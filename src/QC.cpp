#include <iostream>
#include "QC.h"

int IndicePivot(int Esq, int Dir, int* A){
    return (Esq + Dir)/2;
}

void Particao(int Esq, int Dir, int& i, int& j, int* A, int& n_comp, int& n_mov){
    i = Esq;
    j = Dir;
    int i_pivot = IndicePivot(Esq, Dir, A);
    int Pivot = A[i_pivot];
    
    do{
        while (A[i] < Pivot){
            n_comp++;
            i++;
        }
        while (A[j] > Pivot){
            n_comp++;
            j--;
        }
        if (i <= j){
            int temp = A[i]; A[i] = A[j]; A[j] = temp;
            n_mov++;
            i++;
            j--;
        }

    }while (i <= j); 
}

void Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov){
    int i; 
    int j;
    
    Particao(Esq, Dir, i, j, A, n_comp, n_mov);
    if (Esq < j) Ordena(Esq, j, A, n_comp, n_mov);
    if (i < Dir) Ordena(i, Dir, A, n_comp, n_mov);
}

void QC(int* A, int n, int& n_comp, int& n_mov){
    n_comp = 0;
    n_mov = 0;
    Ordena(0, n-1, A, n_comp, n_mov);
}