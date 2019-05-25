#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H


template<class T>
struct Celula{
    T* objeto;
    Celula* prox;
    Celula* ant;
    
    // Construtor inicializador para Celula_str
    Celula(){objeto = nullptr; prox = nullptr; ant = nullptr;}
    ~Celula(){
        if (objeto != nullptr)
            delete objeto; 
        objeto = nullptr;}
};

template<class T>
class ListaEncadeada{
private:
    Celula<T>* ultimo;
    Celula<T>* primeiro;
    Celula<T>* pos; //iterador
    int n_elementos;
    
    
public:
    ListaEncadeada();
    ~ListaEncadeada();
    
    T* _primeiro();
    T* proximo();

    void AdicionaInicio(T& novo);
    void Adiciona(T& novo, int i);
    void AdicionaFim(T& novo);
    
    T* RetiraUltimo();
    T* RetiraPrimeiro();
    T* Retira(int i);

    T Consulta(int i);
    bool Vazia();
    int get_n_elementos();
    int get_indice(Candidato* cand);
};




#endif /* LISTA_ENCADEADA_H */