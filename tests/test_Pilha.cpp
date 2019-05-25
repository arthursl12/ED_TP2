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

TEST_CASE("Pilha: Adiciona e Retira"){
    int* A = new int[5];
    for (int i = 0; i < 5; i++) A[i] = i;
    Pilha P = Pilha();
    P.Adiciona(A);
    CHECK(P.Vazia() == false);

    int* B = P.Retira();
    CHECK(B[0] == A[0]);
    CHECK(B[1] == A[1]);
    CHECK(B[2] == A[2]);
    CHECK(B[3] == A[3]);
    CHECK(B[4] == A[4]);
    CHECK(P.Vazia() == true);

    delete[] A;

    A = new int[6];
    for (int i = 0; i < 6; i++) A[i] = i;
    B = new int[2];
    for (int i = 6; i > 4; i--) B[i] = i;
    P.Adiciona(A);
    P.Adiciona(B);
    CHECK(P.Vazia() == false);

    int* C = P.Retira();
    CHECK(B[0] == C[0]);
    CHECK(B[1] == C[1]);
    CHECK(P.Vazia() == false);

    int* D = P.Retira();
    CHECK(D[0] == A[0]);
    CHECK(D[1] == A[1]);
    CHECK(D[2] == A[2]);
    CHECK(D[3] == A[3]);
    CHECK(D[4] == A[4]);
    CHECK(D[4] == A[4]);
    CHECK(P.Vazia() == false);

    delete[] A;
    delete[] B;
}