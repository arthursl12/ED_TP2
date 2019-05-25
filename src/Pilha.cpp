#include "Pilha.h"

Pilha::Pilha(){
    this->n_elementos = 0;
    this->Topo = nullptr;
    this->Fundo = nullptr;
}

void Pilha::Adiciona(int** A){
    Apontador novo = new Celula;
    novo->item = A;
    novo->prox = nullptr;

    if (Vazia()){
        Fundo = novo;
        Topo = novo;
    }else{
        Topo->prox = novo;
        Topo = novo;
    }
    n_elementos++;
}

int* Pilha::Retira(){
    Apontador retira = Topo;
    Apontador atual = Fundo;
    for (int i = 1; i < n_elementos-1; i++){
        atual = Fundo->prox;
    }
    Topo = atual;
    Topo->prox = nullptr;
    n_elementos--;

    if (n_elementos == 0){
        Topo = nullptr;
        Fundo = nullptr;
    }

    int** item = retira->item;
    retira->item = nullptr;
    retira->prox = nullptr;
    free(retira);
    return *item;
}
bool Pilha::Vazia(){
    return (n_elementos == 0 && Topo == nullptr && Fundo == nullptr);
}