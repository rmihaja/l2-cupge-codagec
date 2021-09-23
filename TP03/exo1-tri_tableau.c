#include <stdio.h>
#define TAILLE 9999

int somme(int *T, int n, int N)
{
    int res = 0;
    for (int i = n; i < N; i++)
    {
        res += T[i];
    }
    return res;
}

int main()
{
    int T1[TAILLE];
    int s;
    for (int i = 0; i < TAILLE; i++)
    {
        T1[i] = i;
    }
    int A;
    int B;
    printf("Valeur de la borne inférieur (inclus) : ");
    scanf("%d", &A);
    printf("Valeur de la borne supérieur (exclus) : ");
    scanf("%d", &B);
    s = somme(T1, A, B);
    printf("la somme des nombres de %d jusqu'à %d est %d\n", A, B, s);
    return 0;
}