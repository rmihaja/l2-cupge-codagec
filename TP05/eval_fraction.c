#include "fraction.h"

double eval_fraction(struct fraction_s *f) {
    return ((double)*numerateur(f)) / ((double)*denominateur(f));

}

#ifdef TESTS
// si nécessaire

#include "tests.h"

int main() {
    struct fraction_s *f;
    f = nouvelle_fraction(1, 3);
    VAL_FLOAT(eval_fraction(f));
    f = nouvelle_fraction(48, 47);
    VAL_FLOAT(eval_fraction(f));
    return 0;
}

#endif