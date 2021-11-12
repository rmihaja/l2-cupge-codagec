#include "matrices.h" 
#include <stdio.h>

void afficher_matrice(struct matrice_s *matrice) {
    for (int i= 0; i < matrice->nb_lignes; i++) {
        printf("( ");
        for (int j = 0; j < matrice->nb_colonnes; j++) {
            printf("%5.2f ", matrice->m[i][j]);
        }
        printf(" )\n");
    }
}

#ifdef TESTS

typedef struct matrice_s *matrice;

int main()
{
    matrice m = creer_matrice(2, 3);
    for (int i = 0; i < m->nb_lignes; i++) {
        for (int j = 0; j < m->nb_colonnes; j++) {
            m->m[i][j] = i + j;
        }
    }
    afficher_matrice(m);
    return 0;
}

#endif