#include <iostream>
#include "QC.h"

int main(int argc, char* argv[]){
    int A[5] = {2, 1, 4, 3, 0};
    int i, j;
    Particao(0, 4, i, j, A);
    std::cout << "i = " << i << " j = " << j << std::endl;
    
    int B[7] = {3, 6, 4, 1, 5, 7, 2};
    Particao(0, 6, i, j, B);
    std::cout << "i = " << i << " j = " << j << std::endl;

    return 0;
}