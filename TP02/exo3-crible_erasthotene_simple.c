#include <stdio.h>
#define TAILLE 100000

int crible(int *t)
{
    t[0] = 0;
    t[1] = 0;

    for (int i = 2; i < TAILLE; i++)
    {
        t[i] = 1;
    }

    for (int i = 0; i < TAILLE; i++)
    {
        if (t[i] == 0)
            continue;
        else if (t[i] == 1)
        {
            for (int j = 2; j * i < TAILLE; j++)
            {
                t[i * j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    int t[TAILLE];
    if (crible(t) != 0)
        return 404;

    while (1) // ? il n'y a pas de keyword 'true' en C
    {
        int entier;
        printf("Veuillez entrer un entier : ");
        scanf("%d", &entier);
        if (entier < 0)
            break;
        else if (entier >= TAILLE)
            continue;
        else
            printf("L'entier est-il premier ? %d\n", t[entier]);
    }

    return 0;
}
