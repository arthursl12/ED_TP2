#include <iostream>
#include "QI.h"

int main(){
    int C[6] = {6, 5, 4, 3, 2, 1};
    int n_comp, n_mov;
    QI::Insertion(C, 0, 5, n_comp, n_mov);

    return 0;
}