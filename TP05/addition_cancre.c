#include "fraction.h"
#include <stdlib.h>

struct fraction_s *addition_cancre(struct fraction_s *f1, struct fraction_s *f2) {
    struct fraction_s *f = malloc(sizeof(struct fraction_s));
    f->p = *numerateur(f1) + *numerateur(f1);
    f->q = *denominateur(f1) + *denominateur(f1);
    return f;
}

#ifdef TESTS
// si nécessaire

#include "tests.h"

int main() {
    // tests de la fonction
    struct fraction_s *f1;
    struct fraction_s *f2;
    struct fraction_s *fres;
    // test 1
    f1 = nouvelle_fraction(5, 8);
    f2 = nouvelle_fraction(8, 12);
    f_res = addition_cancre(f1, f2);
    f_valid = nouvelle_fraction(-1, -5);
    TEST_RES(*numerateur(f_res) == *numerateur(f_valid) && *denominateur(f_res) == *denominateur(f_valid));
    // test 2
    f1 = nouvelle_fraction(18, 42);
    f2 = nouvelle_fraction(-53, -27);
    f_res = addition_cancre(f1, f2);
    f_valid = nouvelle_fraction(-35, 15);
    TEST_RES(*numerateur(f_res) == *numerateur(f_valid) && *denominateur(f_res) == *denominateur(f_valid));
    return 0;
}

#endif