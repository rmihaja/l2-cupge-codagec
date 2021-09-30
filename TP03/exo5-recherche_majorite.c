#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAILLE 10

void arrayf(int *T, int length)
{
    printf("\nValeurs du tableau :");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", T[i]);
    }
}

int main()
{
    srand(time(NULL));
    int n;
    int T[TAILLE];

    printf("Veuillez entrer un nombre : ");
    scanf("%d", &n);

    for (int i = 0; i < TAILLE; i++)
    {
        T[i] = int(n * ((float)rand()) / RAND_MAX);
    }

    return 0;
}
