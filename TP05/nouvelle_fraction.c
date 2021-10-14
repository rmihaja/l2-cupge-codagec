#include <stdlib.h> // pour avoir malloc
#include <math.h>
#include "fraction.h"

struct fraction_s *nouvelle_fraction(int p, int q) {
    struct fraction_s *f = malloc(sizeof(struct fraction_s));
    
    // ? vérification fonction valide
    if (q < 0) {
        p = -p;
        q = -q;
    }
    if (q == 0) {
        if (p < 0) {
            p = -1;
        }
        if (p > 0) {
            p = 1;
        }
    }
    if (p == 0) {
        q = 1;
    }

    f->p = p;
    f->q = q;

    return f;
}

int *numerateur(struct fraction_s *f) {
    return &((*f).p);
}

int *denominateur(struct fraction_s *f) {
    return &((*f).q);
}

#ifdef TESTS

#include <tests.h>

int main()
{
    struct fraction_s *f;
    // test 1
    f = nouvelle_fraction(2, 3);
    VAL_INT(*numerateur(f));
    TEST_RES(*numerateur(f) == 2);
    VAL_INT(*denominateur(f));
    TEST_RES(*denominateur(f) == 3);
    // test 2
    f = nouvelle_fraction(2, -3);
    TEST_RES(*numerateur(f) == -2);
    TEST_RES(*denominateur(f) == 3);
    // test 3
    f = nouvelle_fraction(2, 0);
    TEST_RES(*numerateur(f) == 1);
    TEST_RES(*denominateur(f) == 0);
    // test 4
    f = nouvelle_fraction(-3, 0);
    TEST_RES(*numerateur(f) == -1);
    TEST_RES(*denominateur(f) == 0);
    // test 5
    f = nouvelle_fraction(0, -4);
    TEST_RES(*numerateur(f) == 0);
    TEST_RES(*denominateur(f) == 1);
    return 0;
}

#endif