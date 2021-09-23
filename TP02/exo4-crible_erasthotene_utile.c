#include <stdio.h>
#define TAILLE 100000

int crible(int *t, int n)
{
    t[0] = 1;
    t[1] = 1;

    for (int i = 2; i < n; i++)
    {
        t[i] = i;
    }

    for (int i = 2; i < n; i++)
    {
        if (t[i] == i)
        {
            // i est un nombre premier
            for (int j = 2; i * j < n; j++)
            {
                // nous avons les multiples de i : i * j
                t[i * j] = i;
            }
        }
    }
    return 0;
}

int criblef(int entier)
{
    int t[TAILLE];
    if (crible(t, TAILLE) != 0)
        return 307;
    printf("Décomposition de %d en facteurs premiers :\n", entier);
    int i = entier;
    while (i != t[i])
    {
        printf("%d * ", t[i]);
        i = i / t[i];
    }
    printf("%d\n", t[i]);
    return 0;
}

int main()
{
    while (1) // ? il n'y a pas de keyword true en C
    {
        int entier;
        printf("Veuillez entrer un entier : ");
        scanf("%d", &entier);
        if (entier < 0)
            break;
        else if (entier >= TAILLE)
            continue;
        else
            criblef(entier);
    }

    return 0;
}
