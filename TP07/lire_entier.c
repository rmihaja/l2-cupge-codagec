#include <stdio.h>
#include "entrees.h"

void lire_entier(int *entier) {
    do {
        printf("\nVeuillez entrer un entier :");
    } while (scanf("%d", entier) == 0 || lire_fin_ligne() > 0);
}

#ifdef TESTS

int main()
{
    int i;
    lire_entier(&i);
    printf("\n[TEST] Entier lu: %d\n", i);
    return 0;
}

#endif