#ifndef PILHA_H
#define PILHA_H

#include <memory>

typedef struct Celula_str *Apontador;

typedef struct Celula_str{
    int** item;
    Apontador prox;
} Celula;

class Pilha{
public:
    Pilha();
    void Adiciona(int** A);
    int* Retira();
    bool Vazia();
private:
    Apontador Topo;
    Apontador Fundo;
    int n_elementos;
};

#endif /* PILHA_H */