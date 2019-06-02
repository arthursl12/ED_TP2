#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "QI.h"
#include "generator.h"

using namespace QI;
TEST_CASE("QI: Insertion"){
    int A[5] = {1,2,3,4,5};
    int n_comp, n_mov;
    Insertion(A, 0, 4, n_comp, n_mov);
    CHECK(A[0] == 1);
    CHECK(A[1] == 2);
    CHECK(A[2] == 3);
    CHECK(A[3] == 4);
    CHECK(A[4] == 5);

    int B[6] = {1, 3, 2, 4, 5, 6};
    Insertion(B, 1, 3, n_comp, n_mov);
    CHECK(B[0] == 1);
    CHECK(B[1] == 2);
    CHECK(B[2] == 3);
    CHECK(B[3] == 4);
    CHECK(B[4] == 5);
    CHECK(B[5] == 6);

    int C[6] = {6, 5, 4, 3, 2, 1};
    Insertion(C, 0, 5, n_comp, n_mov);
    CHECK(C[0] == 1);
    CHECK(C[1] == 2);
    CHECK(C[2] == 3);
    CHECK(C[3] == 4);
    CHECK(C[4] == 5);
    CHECK(C[5] == 6);

    int D[7] = {2, 3 ,6, 1, 0, 4, 4};
    Insertion(D, 0, 6, n_comp, n_mov);
    CHECK(D[0] == 0);
    CHECK(D[1] == 1);
    CHECK(D[2] == 2);
    CHECK(D[3] == 3);
    CHECK(D[4] == 4);
    CHECK(D[5] == 4);
    CHECK(D[6] == 6);
}

TEST_CASE("QI: Quicksort com inserção"){
    int A[5] = {1, 2, 3, 4, 5};
    int n_comp, n_mov;
    qi(A, 5, n_comp, n_mov, 0);
    CHECK(A[0] == 1);
    CHECK(A[1] == 2);
    CHECK(A[2] == 3);
    CHECK(A[3] == 4);
    CHECK(A[4] == 5);

    int B[10] = {3, 2, 4, 5, 7, 1, 0, 8, 9, 6};
    qi(B, 10, n_comp, n_mov, 0.1);    
    CHECK(B[0] == 0);
    CHECK(B[1] == 1);
    CHECK(B[2] == 2);
    CHECK(B[3] == 3);
    CHECK(B[4] == 4);
    CHECK(B[5] == 5);
    CHECK(B[6] == 6);
    CHECK(B[7] == 7);
    CHECK(B[8] == 8);
    CHECK(B[9] == 9);

    int* C = VetorAleatorio(3000,12);
    qi(C, 3000, n_comp, n_mov, 0.1);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 3000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorAleatorio(40000,13);
    qi(C, 40000, n_comp, n_mov, 0.01);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 40000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorAleatorio(40000,15);
    qi(C, 40000, n_comp, n_mov, 0.05);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 40000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorCrescente(3000);
    qi(C, 3000, n_comp, n_mov, 0.1);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 3000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorCrescente(40000);
    qi(C, 40000, n_comp, n_mov, 0.01);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 40000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorCrescente(40000);
    qi(C, 40000, n_comp, n_mov, 0.05);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 40000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorDecrescente(3000);
    qi(C, 3000, n_comp, n_mov, 0.1);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 3000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorDecrescente(40000);
    qi(C, 40000, n_comp, n_mov, 0.01);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 40000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;

    C = VetorDecrescente(40000);
    qi(C, 40000, n_comp, n_mov, 0.05);
    CHECK(C[0] <= C[1]);
    for (int i = 0; i < 40000; i++){
        CHECK(C[i-1] <= C[i]);
    }
    delete[] C;
}
