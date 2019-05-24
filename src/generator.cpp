#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "generator.h"

bool TamanhoValido(int tamanho){
    if (tamanho % 50000 != 0)
        return false;
    if (tamanho < 50000)
        return false;
    if (tamanho > 500000)
        return false;
    return true;
}

int* VetorAleatorio(int tamanho){
    if(!TamanhoValido(tamanho))
        throw std::invalid_argument("Tamanho inválido");

    int tam = tamanho;
    srand(time(NULL));
    int* vec = new int[tam];
    for (int i = 0; i < tam; i++){
        vec[i] = rand();
    }
    return vec;
}
int* VetorCrescente(int tamanho){
    if(!TamanhoValido(tamanho))
        throw std::invalid_argument("Tamanho inválido");

    int tam = tamanho;
    int* vec = new int[tam];
    for (int i = 0; i < tam; i++){
        vec[i] = i;
    }
    return vec;
}
int* VetorDecrescente(int tamanho){
    if(!TamanhoValido(tamanho))
        throw std::invalid_argument("Tamanho inválido");

    int tam = tamanho;
    int* vec = new int[tam];
    for (int i = 0; i < tam; i++){
        vec[i] = tam - i - 1;
    }
    return vec;
}

