#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

int main(int argc, char const *argv[])
{
    if (argc == 1) {
        printf("\nVeuillez entrer un nombre à chercher et une précision\n");
        double f, epsilon;
        scanf("%lf\n", &f);
        scanf("%lf\n", &epsilon);
        print_fraction(ftofraction(f, epsilon));
    }
    if (argc == 2) {
        printf("\nParamètre utilisé: %s\n", argv[1]);
        print_fraction(ftofraction(atof(argv[1]), 0.000001));
    }
    else if (argc == 4) {
        printf("\nParamètre utilisé: %s %s %lf\n", argv[1], argv[2], atof(argv[3]));
        print_fraction(ftofraction(atof(argv[3]), atof(argv[2])));
    }
    return 0;
}

