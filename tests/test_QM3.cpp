#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "QM3.h"

using namespace QM3;

TEST_CASE("QM3: Mediana de Três"){
    CHECK(mediana_tres(2,3,4) == 3);
    CHECK(mediana_tres(2,4,3) == 3);
    CHECK(mediana_tres(3,2,4) == 3);
    CHECK(mediana_tres(3,4,2) == 3);
    CHECK(mediana_tres(4,3,2) == 3);
    CHECK(mediana_tres(4,2,3) == 3);

    CHECK(mediana_tres(2,2,4) == 2);
    CHECK(mediana_tres(2,4,2) == 2);
    CHECK(mediana_tres(4,2,2) == 2);

    CHECK(mediana_tres(2,2,2) == 2);
    CHECK(mediana_tres(0,0,0) == 0);
}

TEST_CASE("QM3: Mediana de Três"){
    /* O vetor sempre tem pelo menos três elementos */
    int A[3] = {0,1,2};
    CHECK(Pivot(0,2,A) == 1);
    int B[8] = {22,43,55,76,87,90,0,4};
    CHECK(Pivot(0,7,B) == 22);
    int C[9] = {22,43,55,55,76,87,90,0,4};
    CHECK(Pivot(0,8,C) == 22);
}

TEST_CASE("QM3: Partição"){
    /* Pivô nunca é o maior ou o menor de todos */
    SUBCASE("Pivô segundo maior"){
        int A[5] = {3, 2, 5, 1, 4};
        /* Resultado:
        Pivô: 4
        i = 4
        j = 3

        3 2 5 1 4
        3 2 4 1 5 */
        int i, j, n_comp, n_mov;
        Particao(0, 4, i, j, A, n_comp, n_mov);
        CHECK(i == 4);
        CHECK(j == 3);
        CHECK(A[0] == 3);
        CHECK(A[1] == 2);
        CHECK(A[2] == 4);
        CHECK(A[3] == 1);
        CHECK(A[4] == 5);
    }
    SUBCASE("Pivô segundo menor"){
        int A[5] = {3, 5, 2, 4, 1};
        /* Resultado:
        Pivô: 2
        i = 2
        j = 1

        3 5 2 4 1
        1 5 2 4 3
        1 2 5 4 3
        */
        int i, j, n_comp, n_mov;
        Particao(0, 4, i, j, A, n_comp, n_mov);
        CHECK(i == 2);
        CHECK(j == 1);
        CHECK(A[0] == 1);
        CHECK(A[1] == 2);
        CHECK(A[2] == 5);
        CHECK(A[3] == 4);
        CHECK(A[4] == 3);
    }
    SUBCASE("Caso genérico"){
        int C[9] = {5, 7, 3, 1, 6, 8, 4, 2, 0};
        int i, j, n_comp, n_mov;
        Particao(0, 8, i, j, C, n_comp, n_mov);
        /* Resultado:
        Pivô: 5
        i = 5
        j = 4

        5 7 3 1 6 8 4 2 0
        0 7 3 1 6 8 4 2 5
        0 2 3 1 6 8 4 7 5
        0 2 3 1 4 8 6 7 5 */
        CHECK(i == 5);
        CHECK(j == 4);
        CHECK(C[0] == 0);
        CHECK(C[1] == 2);
        CHECK(C[2] == 3);
        CHECK(C[3] == 1);
        CHECK(C[4] == 4);
        CHECK(C[5] == 8);
        CHECK(C[6] == 6);
        CHECK(C[7] == 7);
        CHECK(C[8] == 5);
    }
    SUBCASE("Pivô na posição correta"){
        int A[5] = {1, 2, 3, 5, 4};
        /* Resultado:
        Pivô: 3
        i = 3
        j = 1

        1 2 3 5 4 */
        int i, j, n_comp, n_mov;
        Particao(0, 4, i, j, A, n_comp, n_mov);
        CHECK(i == 3);
        CHECK(j == 1);
        CHECK(A[0] == 1);
        CHECK(A[1] == 2);
        CHECK(A[2] == 3);
        CHECK(A[3] == 5);
        CHECK(A[4] == 4);
    }
}

TEST_CASE("QM3: Quicksort"){
    SUBCASE("Caso com várias especialidades"){
        int F[9] = {65, 77, 51, 25, 03, 84, 48, 21, 05};
        int n_mov, n_comp;
        qm3(F, 9, n_comp, n_mov);
        CHECK(F[0] == 3);
        CHECK(F[1] == 5);
        CHECK(F[2] == 21);
        CHECK(F[3] == 25);
        CHECK(F[4] == 48);
        CHECK(F[5] == 51);
        CHECK(F[6] == 65);
        CHECK(F[7] == 77);
        CHECK(F[8] == 84);
    }
    SUBCASE("Caso simples"){
        int G[7] = {3, 6, 4, 5, 1, 7, 2};
        int n_mov, n_comp;
        qm3(G, 7, n_comp, n_mov);
        CHECK(G[0] == 1);
        CHECK(G[1] == 2);
        CHECK(G[2] == 3);
        CHECK(G[3] == 4);
        CHECK(G[4] == 5);
        CHECK(G[5] == 6);
        CHECK(G[6] == 7);
    }
    SUBCASE("Vetor já ordenado"){
        int G[7] = {0, 1, 2, 3, 4, 5, 6};
        int n_mov, n_comp;
        qm3(G, 7, n_comp, n_mov);
        CHECK(G[0] == 0);
        CHECK(G[1] == 1);
        CHECK(G[2] == 2);
        CHECK(G[3] == 3);
        CHECK(G[4] == 4);
        CHECK(G[5] == 5);
        CHECK(G[6] == 6);
    }
    SUBCASE("Vetor em ordem decrescente"){
        int G[6] = {6, 5, 4, 3, 2, 1};
        int n_mov, n_comp;
        qm3(G, 6, n_comp, n_mov);
        CHECK(G[0] == 1);
        CHECK(G[1] == 2);
        CHECK(G[2] == 3);
        CHECK(G[3] == 4);
        CHECK(G[4] == 5);
        CHECK(G[5] == 6);
    }
}