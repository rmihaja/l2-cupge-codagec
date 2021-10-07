#include <stdlib.h>
#include "matrices.h"

float **ProduitMatrice(float **A, float **B, int n, int m, int p)
{
    float **produit = CreerMatrice(n, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            produit[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                produit[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return produit;
}

#ifdef TESTS

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int length = 2;
    float **matriceA = CreerMatrice(length, length);
    matriceA[0][0] = 1;
    matriceA[0][1] = 5;
    matriceA[1][0] = 8;
    matriceA[1][1] = 7;
    float **matriceB = CreerMatrice(length, length);
    matriceB[0][0] = 2;
    matriceB[0][1] = 7;
    matriceB[1][0] = 1;
    matriceB[1][1] = 8;
    printf("Matrice utilisée A :\n");
    AfficheMatrice(matriceA, length, length);
    printf("Matrice utilisée B :\n");
    AfficheMatrice(matriceB, length, length);
    printf("Résultat :\n");
    AfficheMatrice(ProduitMatrice(matriceA, matriceB, length, length, length), length, length);

    return 0;
}

#endif