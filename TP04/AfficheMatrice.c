#include <stdlib.h>

void AfficheMatrice(float **M, int n, int m)
{
}

#ifdef TESTS

#include <stdio.h>
#include "matrices.h"

int main()
{
    float **M = CreerMatrice(2, 2);
    M[0][0] = 1;
    M[0][1] = 2;
    M[1][0] = 3;
    M[1][1] = 4;
    AfficheMatrice(M, 2, 2);

    return 0;
}

#endif
