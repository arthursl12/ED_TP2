#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "generator.h"

#include <stdexcept>

TEST_CASE("Generator: TamanhoValido"){
    CHECK(TamanhoValido(50000) == true);
    CHECK(TamanhoValido(500000) == true);
    CHECK(TamanhoValido(350000) == true);
    CHECK(TamanhoValido(352000) == true);
    CHECK(TamanhoValido(0) == false);
    CHECK(TamanhoValido(12000) == true);
    CHECK(TamanhoValido(504000) == true);
}

TEST_CASE("Generator: VetorAleatorio"){
    CHECK_THROWS_AS(VetorAleatorio(0), std::invalid_argument);

    int* random = VetorAleatorio(50000);
    delete[] random;

    random = VetorAleatorio(500000);
    delete[] random;
}

TEST_CASE("Generator: VetorCrescente"){
    CHECK_THROWS_AS(VetorCrescente(0), std::invalid_argument);

    int* A = VetorCrescente(50000);
    CHECK(A[0] <= A[1]);
    for (int i = 1; i < 50000; i++){
        CHECK(A[i-1] <= A[i]);
    }
    delete[] A;

    A = VetorCrescente(250000);
    CHECK(A[0] <= A[1]);
    for (int i = 1; i < 250000; i++){
        CHECK(A[i-1] <= A[i]);
    }
    delete[] A;
}

TEST_CASE("Generator: VetorDecrescente"){
    CHECK_THROWS_AS(VetorDecrescente(0), std::invalid_argument);

    int* A = VetorDecrescente(50000);
    CHECK(A[0] >= A[1]);
    for (int i = 1; i < 50000; i++){
        CHECK(A[i-1] >= A[i]);
    }
    delete[] A;

    A = VetorDecrescente(250000);
    CHECK(A[0] >= A[1]);
    for (int i = 1; i < 250000; i++){
        CHECK(A[i-1] >= A[i]);
    }
    delete[] A;
}