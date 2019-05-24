#ifndef QUICKSORT_CLASSICO_H
#define QUICKSORT_CLASSICO_H

int IndicePivot(int Esq, int Dir, int* A);
void Particao(int Esq, int Dir, int& i, int& j, int* A);
void Ordena(int Esq, int Dir, int* A);
void QC(int* A, int n);


#endif /* QUICKSORT_CLASSICO_H */