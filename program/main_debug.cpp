#include <iostream>
#include "QNR.h"


int main(){
    int G[7] = {3, 6, 4, 5, 1, 7, 2};
    int n_mov, n_comp;
    qnr(G, 7, n_comp, n_mov);
    
    return 0;
}