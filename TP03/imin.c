#include <stdio.h>
#define TAILLE 10

int imin(int *T)
{
    for (int i = 0; i < TAILLE; i++)
    {
        printf("%d\n", T[i]);
    }
    return 0;
}

int main()
{
    int T[TAILLE];

    for (int i = 0; i < TAILLE; i++)
    {
        T[i] = i;
    }
    imin(T);

    return 0;
}