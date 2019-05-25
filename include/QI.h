#ifndef QUICKSORT_INSERCAO_H
#define QUICKSORT_INSERCAO_H

namespace QI{
    void Insertion(int* A, int Esq, int Dir, int& n_comp, int& n_mov);
    void Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov, int n, double perc);
}

void qi(int* A, int n, int& n_comp, int& n_mov, double perc);



#endif /* QUICKSORT_INSERCAO_H */