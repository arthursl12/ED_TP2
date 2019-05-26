#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "QNR.h"

TEST_CASE("QNR: Quicksort"){
    SUBCASE("Caso com várias especialidades"){
        int F[9] = {65, 77, 51, 25, 03, 84, 48, 21, 05};
        int n_mov, n_comp;
        qnr(F, 9, n_comp, n_mov);
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
        qnr(G, 7, n_comp, n_mov);
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
        qnr(G, 7, n_comp, n_mov);
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
        qnr(G, 6, n_comp, n_mov);
        CHECK(G[0] == 1);
        CHECK(G[1] == 2);
        CHECK(G[2] == 3);
        CHECK(G[3] == 4);
        CHECK(G[4] == 5);
        CHECK(G[5] == 6);
    }
}