#include <stdio.h>

int main()
{
    int pgcd(int *resultat, int a, int b)
    {
        if (a <= 0 || b <= 0)
            return 1;
        if (a == b)
            *resultat = a;
        else if (a > b)
            pgcd(resultat, a - b, b);
        else
            pgcd(resultat, a, b - a);
        return 0;
    }

    int resultat;
    int a;
    int b;

    printf("Veuillez donner une valeur de a :\n");
    scanf("%d", &a);
    printf("Veuillez donner une valeur de b :\n");
    scanf("%d", &b);
    if (pgcd(&resultat, a, b) == 0)
        printf("Le pgcd de %d et %d est : %d", a, b, resultat);
    else
        printf("Erreur : il faut deux entiers strictement positifs pour calculer leur pgcd");
    return 0;
}