#include "matrices.h" 
#include <stdio.h>

int produit_matrices(struct matrice_s *resultat, struct matrice_s *matrice1, struct matrice_s *matrice2) {
    if (matrice1->nb_colonnes != matrice2->nb_lignes 
        || resultat->nb_lignes != matrice1->nb_lignes 
        || resultat->nb_colonnes != matrice2->nb_colonnes) {
        return 1;
    }
    for (int i = 0; i < resultat->nb_lignes; i++) {
        for (int j = 0; j < resultat->nb_colonnes; j++)
            for (int k = 0; k < resultat->nb_lignes; k++)
            {
                resultat->m[i][j] += matrice1->m[i][k] + matrice2->m[k][j];
            }
    }
    afficher_matrice(resultat);
    return 0;
}

#ifdef TESTS

#include "tests.h"
typedef struct matrice_s *matrice;

int main()
{
    matrice m1, m2, m3, m4, mresult;
    m1 = creer_matrice(2, 4);
    m2 = creer_matrice(2, 3);
    m3 = creer_matrice(3, 4);
    m4 = creer_matrice(2, 3);
    mresult = creer_matrice(2, 4);
    lire_matrice(m2);
    lire_matrice(m3);
    lire_matrice(mresult);
    // afficher_matrice(m2);
    // afficher_matrice(m3);
    // afficher_matrice(mresult);
    test(produit_matrices(m1, m2, m3) == 0);
    for (int i = 0; i < m1->nb_lignes; i++)
    {
        for (int j = 0; j < m1->nb_colonnes; j++)
        {
            test(m1->m[i][j] == mresult->m[i][j]);
        }
    }
    test(produit_matrices(m4, m2, m3) == 1);
    test(produit_matrices(m1, m3, m4) == 1);
    test(produit_matrices(m1, m2, m4) == 1);
    return 0;
}

#endif