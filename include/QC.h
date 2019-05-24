#ifndef QUICKSORT_CLASSICO_H
#define QUICKSORT_CLASSICO_H

int IndicePivot(int Esq, int Dir, int* A);
void Particao(int Esq, int Dir, int& i, int& j, int* A, int& n_comp, int& n_mov);
void Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov);
void QC(int* A, int n, int& n_comp, int& n_mov);


#endif /* QUICKSORT_CLASSICO_H */