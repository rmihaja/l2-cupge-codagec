#include <math.h>
#include "fraction.h"

struct fraction_s *ftofraction(double f, double epsilon) {
    struct fraction_s *min = nouvelle_fraction(0, 1),
                      *max = nouvelle_fraction(1, 0),
                      *somme;
    // impossible de contracter *  
    

    // ! correction 
    // tous les entiers sauf 0 sont vraies
    while (1) {
        somme = addition_cancre(min, max);
        double s = eval_fraction(somme);
        if (fabsl(s - f) < epsilon) {
            break;
        } 
        if (s < f) {
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