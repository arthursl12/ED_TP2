#include "QI.h"
#include "QM3.h"
#include <iostream>

void QI::Insertion(int* A, int Esq, int Dir, int& n_comp, int& n_mov){
    for(int i = Esq+1; i <= Dir; i++){
        for(int j = Esq; j < i; j++){
            n_comp++;
            if (A[j] > A[i]){
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
                n_mov++;        
            }
        }
    }
}

void QI::Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov, int n, double perc){
    int i; 
    int j;
    int tam_min = perc * n;
    if (Dir - Esq > tam_min){
        QM3::Particao(Esq, Dir, i, j, A, n_comp, n_mov);
        if (Esq < j) QI::Ordena(Esq, j, A, n_comp, n_mov, n, perc);
        if (i < Dir) QI::Ordena(i, Dir, A, n_comp, n_mov, n, perc);
    }else{
        Insertion(A, Esq, Dir, n_comp, n_mov);
    }   
    
}


void qi(int* A, int n, int& n_comp, int& n_mov, double perc){
    n_comp = 0;
    n_mov = 0;
    QI::Ordena(0, n-1, A, n_comp, n_mov, n, perc);
}