#include "Pilha.h"

Pilha::Pilha(){
    this->n_elementos = 0;
    this->Topo = nullptr;
    this->Fundo = nullptr;
}

Pilha::~Pilha(){
    while(!Vazia()){
        int x;
        int y;
        Desempilha(x, y);
    }
}

void Pilha::Empilha(int* Esq, int* Dir){
    Apontador novo = new Celula(Esq, Dir);

    if (Vazia()){
        Fundo = novo;
        Topo = novo;
    }else{
        Topo->prox = novo;
        Topo = novo;
    }
    n_elementos++;
}

void Pilha::Desempilha(int& x, int& y){
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

    x = *retira->item->Esq;
    y = *retira->item->Dir;
    retira->item = nullptr;
    retira->prox = nullptr;
    delete(retira);
}
bool Pilha::Vazia(){
    return (n_elementos == 0 && Topo == nullptr && Fundo == nullptr);
}