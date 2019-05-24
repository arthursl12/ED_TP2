#include <iostream>
#include <cstring>
#include <cstdio>
#include <chrono>

#include "QC.h"
#include "generator.h"

#define N_TESTES 25

bool stringIgual(char* str1, char* str2){
    int res = strcmp(str1, str2);
    if (res == 0)
        return true;
    else
        return false;
}

int* geraVetor(char* tipo, int tamanho){
    int* vetor;

    if (stringIgual(tipo,(char*)"Ale")){
        vetor = VetorAleatorio(tamanho);
    }else if(stringIgual(tipo,(char*)"OrdC")){
        vetor = VetorCrescente(tamanho);
    }else{ /* OrdD */
        vetor = VetorDecrescente(tamanho);
    }
    return vetor;
}

void fazOrdenacao(char* variacao, int* vetor, int tamanho, int& n_comp, int& n_mov){
    if (stringIgual(variacao, (char*)"QC"))
        qc(vetor, tamanho, n_comp, n_mov);
    /*
    else if (stringIgual(variacao,"QM3")){}
    else if (stringIgual(variacao,"QPE")){}
    else if (stringIgual(variacao,"QI1")){}
    else if (stringIgual(variacao,"QI5")){}
    else if (stringIgual(variacao,"QI10")){}
    else if (stringIgual(variacao,"QM3")){}*/
    else{};
    
}

int mediana(int* A, int n){
    int n_comp = 0;
    int n_mov = 0;
    int med;
    qc(A, n, n_comp, n_mov);

    if (n % 2 == 0){
        med = A[n/2] + A[n/2 - 1];
        med = med/2;
    }else{
        med = A[n/2];
    }

    return med;
}

int main(int argc, char* argv[]){
    /* Coleta os argumentos */
    char* variacao = argv[1];
    char* tipo = argv[2];
    char* str_tamanho = argv[3];
    int tamanho = atoi(str_tamanho);
    bool imprimir = false;
    if (argc == 5) imprimir = true;

    /* Bases da análise estatística */
    int* conj_vectors[N_TESTES];
    std::chrono::duration<double> tempos[N_TESTES];
    int n_comp_vec[N_TESTES];
    int n_mov_vec[N_TESTES];

    /* Executa os testes */
    for (int i = 0; i < N_TESTES; i++){
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        int n_comp, n_mov;

        int* vetor = geraVetor(tipo, tamanho);
        fazOrdenacao(variacao, vetor, tamanho, n_comp, n_mov);
        

        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        
        n_comp_vec[i] = n_comp;
        n_mov_vec[i] = n_mov;
        tempos[i] = elapsed_time;
        conj_vectors[i] = vetor;
    }

    /* Imprime os resultados */
    
    printf("%s %s %i",variacao, tipo, tamanho);
    printf(" %i",mediana(n_comp_vec, N_TESTES));
    printf(" %i",mediana(n_mov_vec, N_TESTES));
        
    if (imprimir == true){
        for (int j = 0; j < N_TESTES; j++){
            for (int i = 0; i < tamanho; i++)
                printf("%i ",conj_vectors[j][i]);
            printf("\n");
        }
    }


    for (int j = 0; j < N_TESTES; j++){
        delete[] conj_vectors[j];
    }

    

    return 0;
}