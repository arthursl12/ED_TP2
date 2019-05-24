#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "QC.h"

TEST_CASE("QC: IndicePivot"){
    int A[4] = {0, 1 ,2 ,3};
    CHECK(QC::IndicePivot(0, 3, A) == 1);
    
    int B[1] = {4};
    CHECK(QC::IndicePivot(0, 0, B) == 0);

    int C[3] = {5, 6, 7};
    CHECK(QC::IndicePivot(0, 2, C) == 1);
}

TEST_CASE("QC: Particao"){
    SUBCASE("Pivô maior de todos"){
        int A[5] = {2, 1, 4, 3, 0};
        int i, j;
        int n_comp, n_mov;
        QC::Particao(0, 4, i, j, A, n_comp, n_mov);

        /* Resultados:
        Pivô = 4
        i = 4
        j = 3

        2 1 4 3 0
        2 1 0 3 4
        */
        CHECK(i == 4);
        CHECK(j == 3);
        CHECK(A[0] == 2);
        CHECK(A[1] == 1);
        CHECK(A[2] == 0);
        CHECK(A[3] == 3);
        CHECK(A[4] == 4);
    }
    SUBCASE("Pivô menor de todos"){
        int B[7] = {3, 6, 4, 1, 5, 7, 2};
        int i, j;
        int n_comp, n_mov;
        QC::Particao(0, 6, i, j, B, n_comp, n_mov);

        /* Resultados:
        Pivô = 1
        i = 1
        j = 0

        3 6 4 1 5 7 2
        1 6 4 3 5 7 2 */

        CHECK(i == 1);
        CHECK(j == 0);
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
        QC::Particao(0, 8, i, j, C, n_comp, n_mov);
        /* Resultados:
        Pivô: 6
        i = 6
        j = 5

        5 7 3 1 6 8 4 2 0
        5 0 3 1 6 8 4 2 7
        5 0 3 1 2 8 4 6 7
        5 0 3 1 2 4 8 6 7 */

        CHECK(i == 6);
        CHECK(j == 5);
        CHECK(C[0] == 5);
        CHECK(C[1] == 0);
        CHECK(C[2] == 3);
        CHECK(C[3] == 1);
        CHECK(C[4] == 2);
        CHECK(C[5] == 4);
        CHECK(C[6] == 8);
        CHECK(C[7] == 6);
        CHECK(C[8] == 7);
    }
    SUBCASE("Pivô na posição correta"){
        int D[7] = {3, 6, 1, 4, 5, 7, 2};
        int i, j;
        int n_comp, n_mov;
        QC::Particao(0, 6, i, j, D, n_comp, n_mov);
        /* Resultados:
        Pivô: 4
        i = 4
        j = 2

        3 6 1 4 5 7 2
        3 2 1 4 5 7 6 */
        
        CHECK(i == 4);
        CHECK(j == 2);
        CHECK(D[0] == 3);
        CHECK(D[1] == 2);
        CHECK(D[2] == 1);
        CHECK(D[3] == 4);
        CHECK(D[4] == 5);
        CHECK(D[5] == 7);
        CHECK(D[6] == 6);
    }
    SUBCASE("Caso genérico"){
        int E[7] = {3, 6, 4, 5, 1, 7, 2};
        int i, j;
        int n_comp, n_mov;
        QC::Particao(0, 6, i, j, E, n_comp, n_mov);
        /* Resultados:
        Pivô: 5
        i = 4
        j = 3

        3 6 4 5 1 7 2
        3 2 4 5 1 7 6
        3 2 4 1 5 7 6 */

        CHECK(i == 4);
        CHECK(j == 3);
        CHECK(E[0] == 3);
        CHECK(E[1] == 2);
        CHECK(E[2] == 4);
        CHECK(E[3] == 1);
        CHECK(E[4] == 5);
        CHECK(E[5] == 7);
        CHECK(E[6] == 6);
    }
}

TEST_CASE("QC: Quicksort"){
    SUBCASE("Caso com várias especialidades"){
        int F[9] = {65, 77, 51, 25, 03, 84, 48, 21, 05};
        int n_mov, n_comp;
        qc(F, 9, n_comp, n_mov);
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
        qc(G, 7, n_comp, n_mov);
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
        qc(G, 7, n_comp, n_mov);
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
        qc(G, 6, n_comp, n_mov);
        CHECK(G[0] == 1);
        CHECK(G[1] == 2);
        CHECK(G[2] == 3);
        CHECK(G[3] == 4);
        CHECK(G[4] == 5);
        CHECK(G[5] == 6);
    }
}
    
    

    