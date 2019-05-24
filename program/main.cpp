#include <iostream>
#include <cstring>
#include <cstdio>

#include "QC.h"
#include "generator.h"

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
        printf("Aleatorio\n");
        vetor = VetorAleatorio(tamanho);
    }else if(stringIgual(tipo,(char*)"OrdC")){
        printf("Crescente\n");
        vetor = VetorCrescente(tamanho);
    }else{
        printf("Decrescente\n");
        vetor = VetorDecrescente(tamanho);
    }
    return vetor;
}

void fazOrdenacao(char* variacao, int* vetor, int tamanho){
    if (stringIgual(variacao, (char*)"QC"))
        QC(vetor, tamanho);
    /*
    else if (stringIgual(variacao,"QM3")){}
    else if (stringIgual(variacao,"QPE")){}
    else if (stringIgual(variacao,"QI1")){}
    else if (stringIgual(variacao,"QI5")){}
    else if (stringIgual(variacao,"QI10")){}
    else if (stringIgual(variacao,"QM3")){}*/
    else{};
    
}

int main(int argc, char* argv[]){
    /* Coleta os argumentos */
    char* variacao = argv[1];
    char* tipo = argv[2];
    char* str_tamanho = argv[3];
    int tamanho = atoi(str_tamanho);
    bool imprimir = false;
    if (argc == 5) imprimir = true;

    int* vetor = geraVetor(tipo, tamanho);
    fazOrdenacao(variacao, vetor, tamanho);

    printf("%s %s %i\n",variacao, tipo, tamanho);
    if (imprimir == true){
        for (int i = 0; i < tamanho; i++)
            printf("%i ",vetor[i]);
    }

    delete[] vetor;
    

    return 0;
}