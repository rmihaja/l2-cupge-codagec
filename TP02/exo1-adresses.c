#include <stdio.h>

int main(int argc, char *argv[] __attribute__((unused)))
{
    int x0;
    int x1;
    printf("(a) Adresse de x0 : %p\n    Adresse de x1 : %p\n", &x0, &x1);
    printf("(b) Différence entre les adresses de x0 et x1 : %ld\n", &x1 - &x0);

    /

        int x2;
    printf("(c) Différence des adresses de x2 et x1 : %ld\n    Différence des adresses de x2 et x0 : %ld\n", &x2 - &x1, &x2 - &x0);

    // *(&x0 - 2) = 101;
    // *(&x0 - 4) = 202;
    printf("%d", argc);

    // printf("(g) Affichage de la taille de :\n
    //        char
    //        : % ld\n short int
    //        : % ld\n int
    //        : % ld\n long int
    //        : % ld\n float
    //        : % ld\n double
    //        : % ld\n int *
    //        : % ld\n char *
    //        : % ld\n ",
    //              sizeof(char),
    //          sizeof(short int), sizeof(int), sizeof(long int), sizeof(float), sizeof(double), sizeof(int *), sizeof(char *));

    return 0;
}