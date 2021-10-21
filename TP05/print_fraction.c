#include <stdio.h>
#include "fraction.h"

void print_fraction(struct fraction_s *f) {
    printf("%d/%d\n", *numerateur(f), *denominateur(f));
}

#ifdef TESTS

#include "tests.h"

int main() {
    struct fraction_s *f;
    f = nouvelle_fraction(2, 3);
    print_fraction(f);
    f = nouvelle_fraction(-47, 8);
    print_fraction(f);
    f = nouvelle_fraction(6, 15);
    print_fraction(f);
    return 0;   
}

#endif