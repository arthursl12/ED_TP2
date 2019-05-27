#include<QM3.h>

int QM3::mediana_tres(int a, int b, int c){
    if (a > b && a > c){
        if (b > c)
            return b;
        else /* c >= b */
            return c;
    }else if (b > a && b > c){
        if (a > c)
            return a;
        else /* c >= a */
            return c;
    }else{  /* c > a && c > b */
        if (a > b)
            return a;
        else /* b >= a */
            return b;
    }
}

int QM3::Pivot(int Esq, int Dir, int* A){
    int A_0 = A[Dir];
    int A_n = A[Esq];
    int A_m = A[(Esq + Dir)/2];
    
    return mediana_tres(A_0, A_n, A_m);
}

void QM3::Particao(int Esq, int Dir, int& i, int& j, int* A, int& n_comp, int& n_mov){
    i = Esq;
    j = Dir;
    int Pivot = QM3::Pivot(Esq, Dir, A);
    n_comp = n_comp+3;
    
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

void QM3::Ordena(int Esq, int Dir, int* A, int& n_comp, int& n_mov){
    int i; 
    int j;
    
    QM3::Particao(Esq, Dir, i, j, A, n_comp, n_mov);
    if (Esq < j) QM3::Ordena(Esq, j, A, n_comp, n_mov);
    if (i < Dir) QM3::Ordena(i, Dir, A, n_comp, n_mov);
}

void qm3(int* A, int n, int& n_comp, int& n_mov){
    n_comp = 0;
    n_mov = 0;
    QM3::Ordena(0, n-1, A, n_comp, n_mov);
}