#include <stdlib.h>

float **CreerMatrice(int n, int m)
{
    float **matrice = malloc(sizeof(float *) * n);
    for (int i = 0; i < n; i++)
    {
        matrice[i] = malloc(sizeof(float) * m);
    }
    return matrice;
}

#ifdef TESTS

#include <stdio.h>

int main()
{
    float **M = CreerMatrice(2, 2);
    M[0][0] = 1;
    M[0][1] = 2;
    M[1][0] = 3;
    M[1][1] = 4;
    for (int i = 0; i < 2; i++)
    {
        printf("( ");
        for (int j = 0; j < 2; j++)
        {
            printf(" %5.2f ", M[i][j]);
        }
        printf(" )\n");
    }
    return 0;
}

#endif