#include <stdlib.h>

float **CreerMatrice(int n, int m)
{
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
        print(" )\n");
    }
    return 0;
}

#endif