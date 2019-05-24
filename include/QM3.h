#ifndef QUICKSORT_MEDIANA_TRES_H
#define QUICKSORT_MEDIANA_TRES_H

#include "QC.h"

namespace QM3{
    int mediana_tres(int a, int b, int c);
    int Pivot(int Esq, int Dir, int* A);
    void Particao(int Esq, int Dir, int& i, int& j, int* A, int& n_comp, int& n_mov);
    void Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov);
}
void qm3(int* A, int n, int& n_comp, int& n_mov);

#endif /* QUICKSORT_MEDIANA_TRES_H */