#include <math.h>
#include "fraction.h"

struct fraction *ftofraction(double f, double epsilon) {
    struct fraction *min = nouvelle_fraction(0, 1);
    struct fraction *max = nouvelle_fraction(1, 0);

    // ! correction 
    while (1) {
        somme = addition_cancre(min, max);
        double s = eval(somme);
        if (fabs(s - x) < epsilon) {
            return somme;
        } 
        if (s < x) {
            min = somme;
        } else {
            max = somme;
        }
    }
    return somme;
}




#ifdef TESTS
// si nécessaire

#include "tests.h"

int main() {
    // tests de la fonction
    return 0;
}

#endif