#include "QPE.h"

void QPE::Particao(int Esq, int Dir, int& i, int& j, int* A, int& n_comp, int& n_mov){
    i = Esq;
    j = Dir;
    int Pivot = A[Esq];
    
    do{
        while (A[i] < Pivot){
            n_comp++;
            i++;
        }
        n_comp++;
        while (A[j] > Pivot){
            n_comp++;
            j--;
        }
        n_comp++;
        if (i <= j){
            int temp = A[i]; A[i] = A[j]; A[j] = temp;
            n_mov++;
            i++;
            j--;
        }

    }while (i <= j); 
}

void QPE::Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov){
    int i; 
    int j;
    
    QPE::Particao(Esq, Dir, i, j, A, n_comp, n_mov);
    if (Esq < j) QPE::Ordena(Esq, j, A, n_comp, n_mov);
    if (i < Dir) QPE::Ordena(i, Dir, A, n_comp, n_mov);
}

void qpe(int* A, int n, int& n_comp, int& n_mov){
    n_comp = 0;
    n_mov = 0;
    QPE::Ordena(0, n-1, A, n_comp, n_mov);
}