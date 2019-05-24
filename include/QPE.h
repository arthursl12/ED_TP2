#ifndef QUICKSORT_PRIMEIRO_ELEMENTO_H
#define QUICKSORT_PRIMEIRO_ELEMENTO_H

#include "QC.h"

namespace QPE{
    void Particao(int Esq, int Dir, int& i, int& j, int* A, int& n_comp, int& n_mov);
    void Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov);
}
void qpe(int* A, int n, int& n_comp, int& n_mov);

#endif /* QUICKSORT_PRIMEIRO_ELEMENTO_H */