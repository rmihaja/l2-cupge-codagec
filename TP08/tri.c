#include <stdio.h>
#include <stdlib.h>

#include "memoire.h"
#include "tri.h"

#define MERGE_MIN_SIZE 1

void adaptative_fusion(void *t_orig, size_t elt_size, size_t nb_elts, cmp_function f)
{
    int
        nombre_d_iterations,
        odd = 0,
        taille_totale = nb_elts * elt_size;
    char
        *t = (char *)t_orig,
        *tmp = (char *)malloc(taille_totale);
    int taille_courante_tableaux = MERGE_MIN_SIZE;
    int
#ifdef DEBUG
        nombre_theorique_de_phases = CHAR_BIT * sizeof(unsigned int) - __builtin_clz((unsigned int)nb_elts),
#endif
        nombre_reel_de_phases,
        nombre_de_swaps = 0;
    memcpy_t copie = memcpy_builder(t_orig, elt_size);

#ifdef DEBUG
    printf("nombre de phases calculées: %d\n", nombre_theorique_de_phases);
#endif
    /* 
     On commence par s'assurer que tous les sous-tableaux de taille <=
   taille_courante_tableaux sont tries. 
  */
    if (taille_courante_tableaux > 1)
    {
        tri_fusion_court(&tmp, &t, elt_size, nb_elts, taille_courante_tableaux, f, copie, &odd, &nombre_de_swaps);
        nombre_reel_de_phases = 1;
    }
    // Fusion de tableaux dont la taille double à chaque itération
    for (
        nombre_reel_de_phases = 0,
       nombre_d_iterations = nb_elts / (2 * taille_courante_tableaux);
        taille_courante_tableaux < nb_elts;
        nombre_d_iterations /= 2,
       taille_courante_tableaux *= 2,
       nombre_reel_de_phases++)
    { // Dans chaque itération, faire nombre_d_iterations avec des paires de tableaux
        passe_fusion_avec_taille_fixee(tmp, t,
                                       taille_courante_tableaux, elt_size, taille_totale,
                                       nombre_d_iterations,
                                       f, copie);
        // et on met tmp dans t, et inversement
        swap_array(&t, &tmp, &odd, &nombre_de_swaps);
    }
    recopie_si_necessaire(tmp, t, taille_totale, odd, copie);
#ifdef DEBUG
    printf("nombre de phases:\n\ttheorique: %d\n\tpratique: %d\nnombre de swaps: %d\n",
           nombre_theorique_de_phases,
           nombre_reel_de_phases,
           nombre_de_swaps);
#endif
}

void tri_fusion_court(char **t_dest, char **t_orig, size_t elt_size, size_t nb_elts, size_t taille_courante_tableaux, cmp_function f, memcpy_t copie, int *odd, int *nb)
{
    int i;
    for (i = 0;
         i < elt_size * (nb_elts - taille_courante_tableaux);
         i += taille_courante_tableaux * elt_size)
        tri_court((*t_dest) + i, (*t_orig) + i, elt_size, taille_courante_tableaux * elt_size, f, copie);
    tri_court((*t_dest) + i, (*t_orig) + i, elt_size, elt_size * nb_elts - i, f, copie);
    swap_array(t_dest, t_orig, odd, nb);
}

void passe_fusion_avec_taille_fixee(char *dest, char *src, size_t taille_courante_tableaux, size_t elt_size, size_t taille_totale, int nombre_d_iterations, cmp_function f, memcpy_t copie)
{
    size_t debut_tableaux, milieu_tableaux, fin_tableaux, nombre_de_fusions;
    for (
        debut_tableaux = 0,
       milieu_tableaux = taille_courante_tableaux * elt_size,
       fin_tableaux = 2 * taille_courante_tableaux * elt_size,
       nombre_de_fusions = 0;
        nombre_de_fusions < nombre_d_iterations;
        nombre_de_fusions++,
       debut_tableaux = fin_tableaux,
       milieu_tableaux += 2 * taille_courante_tableaux * elt_size,
       fin_tableaux += 2 * taille_courante_tableaux * elt_size)
        // Pour chaque paire de tableau, appliquer l'algorithme de fusion
        procedure_fusion(dest, src, debut_tableaux, milieu_tableaux, fin_tableaux, elt_size, f, copie);
    if (milieu_tableaux > taille_totale)
        milieu_tableaux = taille_totale;
    if (fin_tableaux > taille_totale)
        fin_tableaux = taille_totale;
    procedure_fusion(dest, src, debut_tableaux, milieu_tableaux, fin_tableaux, elt_size, f, copie);
}


void tri_court(char *dest, char *src, size_t elt_size, size_t taille_totale, cmp_function f, memcpy_t copie)
{
    int i, i_min;
    for (i = 0; i < taille_totale - elt_size; i += elt_size, src += elt_size, dest += elt_size)
    {
        indice_min(src, elt_size, taille_totale - i, f, &i_min);
        copie(dest, src + i_min, elt_size);
        copie(src + i_min, src, elt_size);
    }
    return;
}

void indice_min ( void * t_orig , size_t elt_size , size_t taille_totale , cmp_function f , int * i_min )
{
  char * t = ( char * ) t_orig ;
  int i , min  ;
  for ( min = 0 , i = elt_size ; i < taille_totale ; i += elt_size )
    {
      if ( f ( t + i , t + min ) < 0 )
	min = i ;
    }
  * i_min = min  ;
}


void procedure_fusion(char *tmp, char *t, int debut_tableaux, int milieu_tableaux, int fin_tableaux, size_t elt_size, cmp_function f, memcpy_t copie)
{
    int position_tableau_dest,
        position_tableau_1,
        position_tableau_2;
    for (
        position_tableau_dest = debut_tableaux,
       position_tableau_1 = debut_tableaux,
       position_tableau_2 = milieu_tableaux;
        (position_tableau_1 < milieu_tableaux) && (position_tableau_2 < fin_tableaux);
        position_tableau_dest += elt_size)
    {
        if (f(t + position_tableau_1, t + position_tableau_2) < 0)
        {
            copie(tmp + position_tableau_dest, t + position_tableau_1, elt_size);
            position_tableau_1 += elt_size;
        }
        else
        {
            copie(tmp + position_tableau_dest, t + position_tableau_2, elt_size);
            position_tableau_2 += elt_size;
        }
    }
    if (position_tableau_1 < milieu_tableaux)
        copie(tmp + position_tableau_dest, t + position_tableau_1, (milieu_tableaux - position_tableau_1));
    if (position_tableau_2 < fin_tableaux)
        copie(tmp + position_tableau_dest, t + position_tableau_2, fin_tableaux - position_tableau_2);
}
