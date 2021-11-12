#include "matrices.h" 

int somme_matrices(struct matrice_s *resultat, struct matrice_s *matrice1, struct matrice_s *matrice2) {
    if (matrice1->nb_lignes != matrice2->nb_lignes || matrice1->nb_lignes != resultat->nb_lignes 
        || matrice1->nb_colonnes != matrice2->nb_colonnes || matrice1->nb_colonnes != resultat->nb_colonnes) {
        return 1;
    }
    for (int i = 0; i < resultat->nb_lignes; i++) {
        for (int j = 0; j < resultat->nb_colonnes; j++)
        {
            resultat->m[i][j] = matrice1->m[i][j] + matrice2->m[i][j];
        }
    }
    return 0;
}

#ifdef TESTS

#include "tests.h"
typedef struct matrice_s *matrice;

int main()
{
    matrice m1, m2, m3, m4;
    m1 = creer_matrice(2, 3);
    m2 = creer_matrice(2, 3);
    m3 = creer_matrice(2, 3);
    m4 = creer_matrice(3, 3);
    test(somme_matrices(m1, m2, m3) == 0);
    for (int i = 0; i < m1->nb_lignes; i++)
    {
        for (int j = 0; j < m1->nb_colonnes; j++)
        {
            test(m1->m[i][j] == (m2->m[i][j] + m3->m[i][j]));
        }
    }
    test(somme_matrices(m4, m2, m3) == 1);
    test(somme_matrices(m1, m4, m3) == 1);
    test(somme_matrices(m1, m2, m4) == 1);
    return 0;
}

#endif