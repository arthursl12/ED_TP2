#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Pilha.h"

TEST_CASE("Pilha: construtor"){
    CHECK_NOTHROW(Pilha());
}

TEST_CASE("Pilha: Vazia"){
    Pilha P;
    CHECK(P.Vazia() == true);
}

TEST_CASE("Pilha: Empilha e Retira"){
    int* a = new int(5);
    int* b = new int(0);
    Pilha P = Pilha();
    P.Empilha(a, b);
    CHECK(P.Vazia() == false);

    int* c = new int(2);
    int* d = new int(3);
    P.Empilha(c, d);
    CHECK(P.Vazia() == false);

    
    int x;
    int y;
    P.Desempilha(x, y);
    CHECK(x == 2);
    CHECK(y == 3);
    CHECK(P.Vazia() == false);
    
    P.Desempilha(x, y);
    CHECK(x == 5);
    CHECK(y == 0);
    CHECK(P.Vazia() == true);

    delete a;
    delete b;
    delete c;
    delete d;
    
}

TEST_CASE("Pilha: Desempilha maior e destrutor"){
    int* a = new int(5);
    int* b = new int(6);
    int* c = new int(7);
    int* d = new int(8);
    int* e = new int(0);
    int* f = new int(10);

    Pilha P = Pilha();
    P.Empilha(a, b);
    P.Empilha(c, d);
    P.Empilha(e, f);
}