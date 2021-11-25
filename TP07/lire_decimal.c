#include <stdio.h>
#include "entrees.h"

void lire_decimal(float *decimal) {
    do
    {
        printf("\nVeuillez entrer un décimal :");
    } while (scanf("%f", decimal) == 0 || lire_fin_ligne() > 0);
}

#ifdef TESTS

int main()
{
    float f;
    lire_decimal(&f);
    printf("\n[TEST] Décimal lu: %f\n", f);
    return 0;
}

#endif