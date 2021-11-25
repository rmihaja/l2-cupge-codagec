#include <stdio.h>
#include "entrees.h"

void lire_entier_positif(int *entier) {
    do {
        lire_entier(entier);
    } while (entier < 0);

}

#ifdef TESTS

int main()
{
    // tests
    return 0;
}

#endif