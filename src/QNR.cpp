#include "QNR.h"
#include "QC.h"
#include "Pilha.h"

void qnr(int* A, int n, int& n_comp, int& n_mov){
    Pilha P;
    int dir = n-1;
    int esq = 0;
    int i, j;
    n_comp = 0;
    n_mov = 0;

    P.Empilha(esq, dir);
    do{
        if (dir > esq){ /* i e j ainda não se cruzaram */
            QC::Particao(esq, dir, i, j, A, n_comp, n_mov);
            if (j-esq > dir-i){ /* subvetor da esquerda é maior que o da direita */
                P.Empilha(esq, j);
                esq = i;
                /* Resolve o subvetor da direita */
            }else{
                P.Empilha(i, dir);
                dir = j;
                /* Resolve o subvetor da esquerda */
            }
        }else{
            int x, y;
            P.Desempilha(x, y);
            esq = x;
            dir = y;
        }
    }while(!P.Vazia());
}