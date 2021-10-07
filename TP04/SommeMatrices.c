#include <stdlib.h>
#include "./include/matrices.h"

float **SommeMatrices(float **A, float **B, int n, int m)
{
    float **somme = CreerMatrice(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            somme[i][j] = A[i][j] + B[i][j];
        }
    }
    return somme;
}

// #ifdef TESTS

int main(int argc, char const *argv[])
{
    float **matrice = CreerMatrice(3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrice[i][j] = i * j;
        }
    }
    AfficheMatrice(SommeMatrices(matrice, matrice, 3, 3));
    return 0;
}

// #endif