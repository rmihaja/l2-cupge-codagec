#include <stdio.h>
#include "matrices.h"

struct matrice_s *lire_matrice(struct matrice_s *matrice) {
    for (int i = 0; i < matrice->nb_lignes; i++)
    {
        for (int j = 0; j < matrice->nb_colonnes; j++) {
            // TODO : ask why it doesn't work
            // scanf("%f", (&*matrice->m[0]) + (i * matrice->nb_colonnes + j) * sizeof(float));
            scanf("%f", &matrice->m[i][j]);
        }
    }
    return matrice;
}

#ifdef TESTS

typedef struct matrice_s *matrice;

int main()
{
    matrice m = creer_matrice(2, 3);
    m = lire_matrice(m);
    afficher_matrice(m);
    return 0;
}

#endif