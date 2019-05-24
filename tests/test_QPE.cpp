#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "QPE.h"

using namespace QPE;
TEST_CASE("QPE: Particao"){
    SUBCASE("Pivô maior de todos"){
        int A[5] = {4, 0, 2, 3, 1};
        int i, j;
        int n_comp, n_mov;
        QPE::Particao(0, 4, i, j, A, n_comp, n_mov);

        /* Resultados:
        Pivô = 4
        i = 4
        j = 3

        4 0 2 3 1
        1 0 2 3 4 */
        CHECK(i == 4);
        CHECK(j == 3);
        CHECK(A[0] == 1);
        CHECK(A[1] == 0);
        CHECK(A[2] == 2);
        CHECK(A[3] == 3);
        CHECK(A[4] == 4);
    }
    SUBCASE("Pivô menor de todos"){
        int B[7] = {1, 6, 4, 3, 5, 7, 2};
        int i, j;
        int n_comp, n_mov;
        QPE::Particao(0, 6, i, j, B, n_comp, n_mov);

        /* Resultados:
        Pivô = 1
        i = 1
        j = -1

        1 6 4 3 5 7 2 */

        CHECK(i == 1);
        CHECK(j == -1);
        CHECK(B[0] == 1);
        CHECK(B[1] == 6);
        CHECK(B[2] == 4);
        CHECK(B[3] == 3);
        CHECK(B[4] == 5);
        CHECK(B[5] == 7);
        CHECK(B[6] == 2);
    }
    SUBCASE("Pivô não está nas bordas"){
        int C[9] = {5, 7, 3, 1, 6, 8, 4, 2, 0};
        int i, j;
        int n_comp, n_mov;
        QPE::Particao(0, 8, i, j, C, n_comp, n_mov);
        /* Resultados:
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
    SUBCASE("Caso genérico"){
        int E[7] = {3, 6, 4, 5, 1, 7, 2};
        int i, j;
        int n_comp, n_mov;
        QPE::Particao(0, 6, i, j, E, n_comp, n_mov);
        /* Resultados:
        Pivô: 3
        i = 2
        j = 1

        3 6 4 5 1 7 2
        2 6 4 5 1 7 3
        2 1 4 5 6 7 3
        */

        CHECK(i == 2);
        CHECK(j == 1);
        CHECK(E[0] == 2);
        CHECK(E[1] == 1);
        CHECK(E[2] == 4);
        CHECK(E[3] == 5);
        CHECK(E[4] == 6);
        CHECK(E[5] == 7);
        CHECK(E[6] == 3);
    }
}

TEST_CASE("QPE: Quicksort"){
    SUBCASE("Caso com várias especialidades"){
        int F[9] = {65, 77, 51, 25, 03, 84, 48, 21, 05};
        int n_mov, n_comp;
        qpe(F, 9, n_comp, n_mov);
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
        qpe(G, 7, n_comp, n_mov);
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
        qpe(G, 7, n_comp, n_mov);
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
        qpe(G, 6, n_comp, n_mov);
        CHECK(G[0] == 1);
        CHECK(G[1] == 2);
        CHECK(G[2] == 3);
        CHECK(G[3] == 4);
        CHECK(G[4] == 5);
        CHECK(G[5] == 6);
    }
}