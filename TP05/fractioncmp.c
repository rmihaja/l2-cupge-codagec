#include "fraction.h"

int fractioncmp(struct fraction_s *f1, struct fraction_s *f2) {
    return (*numerateur(f1) * *denominateur(f2) - *numerateur(f2) * *denominateur(f1));
}

#ifdef TESTS

#include "tests.h"

int main()
{
    struct fraction_s *f1;
    struct fraction_s *f2;
    // test 1
    f1 = nouvelle_fraction(-5, 3);
    f2 = nouvelle_fraction(4, -8);
    TEST_RES(fractioncmp(f1, f2) < 0);
    // test 2
    f1 = nouvelle_fraction(18, 42);
    f2 = nouvelle_fraction(-53, -27);
    TEST_RES(fractioncmp(f1, f2) < 0);
    return 0;
}

#endif