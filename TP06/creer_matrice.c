#include "matrices.h"
#include <stdlib.h>

struct matrice_s *creer_matrice(int nb_lignes, int nb_colonnes) 
{
    struct matrice_s *matrice = malloc(sizeof(struct matrice_s));
    matrice->nb_lignes = nb_lignes;
    matrice->nb_colonnes = nb_colonnes;

    matrice->m = malloc(nb_lignes * sizeof(float *));
    for (int i = 0; i < nb_colonnes; i++) {
        matrice->m[i] = malloc(sizeof(float));
    }

    return matrice;
}

#ifdef TESTS

#include <stdio.h>
typedef struct matrice_s *matrice;

int main()
{
    matrice m = creer_matrice(2, 3);
    for (int i = 0; i < m->nb_lignes; i++) {
        for (int j = 0; j < m->nb_colonnes; j++) {
            m->m[i][j] = i + j;
        }
    }
    for (int i = 0; i < m->nb_lignes; i++) {
        printf("( ");
        for (int j = 0; j < m->nb_colonnes; j++)
        {
            printf("%5.2f ", m->m[i][j]);
        }
        printf(" )\n");
    }
    return 0;
}

/* ? devrait afficher :
( 0.00 1.00 2.00 )
( 1.00 2.00 3.00 )
*/

#endif