#include <stdio.h>
#define TAILLE 10

int imin(int *T, int length)
{
    int imin = 0;
    for (int i = 1; i < length; i++)
    {
        if (T[i] < T[imin])
        {
            imin = i;
        }
    }
    return imin;
}

void arrayf(int *T, int length)
{
    printf("\nValeurs du tableau :");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", T[i]);
    }
}

void tri(int *T, int length)
{
    int min = T[imin(T, length)];
    T[imin(T, length)] = T[0];
    T[0] = min;
    tri(T + 1, length - 1);
}

int main()
{
    int T[TAILLE] = {15, 1, 85, 3, 7, 24, 32, 7, 54, 5};
    printf("flddfl");

    arrayf(T, TAILLE);
    printf("fll");
    tri(T, TAILLE);
    arrayf(T, TAILLE);

    return 0;
}