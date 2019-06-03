#ifndef PILHA_H
#define PILHA_H

typedef struct Celula_str *Apontador;

typedef struct TipoItem{
    int Esq;
    int Dir;
} Item;

typedef struct Celula_str{
    Item* item;
    Apontador prox;

    Celula_str(int esq, int dir){
        item = new TipoItem();
        item->Esq = esq; 
        item->Dir = dir;
        prox = nullptr;
    }
    ~Celula_str(){
        if (item != nullptr) delete item;
        prox = nullptr;
    }
} Celula;

class Pilha{
public:
    Pilha();
    ~Pilha();
    void Empilha(int Esq, int Dir);
    void Desempilha(int& x, int& y);
    bool Vazia();
private:
    Apontador Topo;
    Apontador Fundo;
    int n_elementos;
};

#endif /* PILHA_H */