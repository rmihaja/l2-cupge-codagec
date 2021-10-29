#include <stdio.h>

#define NB_LIGNES 2
#define NB_COLONNES 2

typedef float matrice[NB_LIGNES][NB_COLONNES];

void print_mat(matrice m) {
    for (int i= 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            printf("%f1 ", m[i][j]);
        }
        printf("\n");
    }
}

int scan_mat(matrice m) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            scanf("%f", &(m[i][j]));
        }
    }
    print_mat(m);
    return 0;
}

int somme_matrices(matrice resultat, matrice m1, matrice m2) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            resultat[i][j] = m1[i][j] + m2[i][j];
        }
    }
    print_mat(resultat);
    return 0;
}

int produit_matrices(matrice resultat, matrice m1, matrice m2) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            resultat[i][j] = 0;
        }
    }
    
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            for (int k = 0; k < NB_COLONNES; k++) {
                resultat[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    print_mat(resultat);
    return 0;
}

#ifdef TESTS

// #include "tests.h"

int main()
{
    matrice m1;
    matrice m2;

    scan_mat(m1);
    scan_mat(m2);

    printf("\nTEST #1: Sommes\n");
    matrice result_sum;
    somme_matrices(result_sum, m1, m2);

    printf("\nTEST #2: Produit\n");
    matrice result_prod;
    produit_matrices(result_prod, m1, m2);

    return 0;
}

#endif