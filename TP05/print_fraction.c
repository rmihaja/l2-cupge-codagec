#include <stdio.h>
#include "fraction.h"

void print_fraction(struct fraction_s f) {
    printf("%d/%d", *numerateur(f), *denominateur(f));
}

#ifdef TESTS
// si nécessaire

#include "tests.h"

int main() {
    // tests de la fonction
    return 0;
}

#endif