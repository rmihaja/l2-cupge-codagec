#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <limits.h>

#define TAB_SIZE 1000
#define NB_TABS 10
#define SLEEP_TIME 0
#define MERGE_MIN_SIZE 2
typedef void ( * memcpy_t ) ( void * , const void * , size_t ) ;
typedef int ( * cmp_function ) ( const void * , const void * ) ;

int
alignment ( void * v ) ;

void memcpy_8 ( void * dest_orig , const void * src_orig , size_t size ) ;
void
procedure_fusion (
		  char * tmp ,
		  char * t ,
		  int debut_tableaux ,
		  int milieu_tableaux ,
		  int fin_tableaux ,
		  size_t elt_size ,
		  cmp_function f ,
		  memcpy_t copie ) ;
void recopie_si_necessaire ( void * t1 , void * t2 , size_t taille_totale , int b , memcpy_t copie ) ;

void passe_fusion_avec_taille_fixee (  char * dest , char * src , size_t taille_courante_tableaux , size_t elt_size , size_t taille_totale , int nombre_d_iterations , cmp_function f , memcpy_t copie ) ;
void memcpy_2 ( void * dest_orig , const void * src_orig , size_t size ) ;
void tri_fusion_court (
				     char ** t_dest ,
				      char ** t_orig ,
				     size_t elt_size ,
				     size_t nb_elts ,
				     size_t taille_courante_tableaux ,
				     cmp_function f ,
				     memcpy_t copie ,
				     int * odd ,
				     int * nb ) ;
void indice_min ( void * t_orig , size_t elt_size , size_t taille_totale , cmp_function f , int * i_min ) ;
void swap_array ( char ** t1 , char ** t2 , int * b , int * nb ) ; 
void memcpy_1 ( void * dest_orig , const void * src_orig , size_t size ) ;
void adaptative_fusion ( void * t_orig , size_t elt_size , size_t nb_elts , cmp_function f ) ;
void tri_court ( char * dest , char * src , size_t elt_size , size_t taille_totale , cmp_function f , memcpy_t copie ) ;
void memcpy_4 ( void * dest_orig , const void * src_orig , size_t size ) ;

int
choose_best_type_size ( void * v , size_t elt_size ) ;
memcpy_t memcpy_builder ( void * t , size_t elt ) ;
const memcpy_t fonctions_de_copie[] = { memcpy_1 , memcpy_2 , memcpy_4 , memcpy_8 } ;

memcpy_t memcpy_builder ( void * t , size_t elt )
{
	return fonctions_de_copie[choose_best_type_size ( t , elt )] ;
}


void tri_court ( char * dest , char * src , size_t elt_size , size_t taille_totale , cmp_function f , memcpy_t copie )
{
  int i , i_min ;
  for ( i = 0 ; i < taille_totale - elt_size ; i+=elt_size , src += elt_size , dest += elt_size)
    {
      indice_min ( src , elt_size , taille_totale - i , f , & i_min ) ;
      copie ( dest , src + i_min , elt_size ) ;
      copie ( src  + i_min, src  , elt_size ) ;
    }
  return ;
}

void swap_array ( char ** t1 , char ** t2 , int * b , int * nb )
{
  char * exch ;
  exch = *t1 ;
  *t1 = *t2 ;
  *t2 = exch ;
  *b = ! *b ;
 *nb = *nb + 1 ;
}

void memcpy_8 ( void * dest_orig , const void * src_orig , size_t size )
{
  uint64_t * dest = ( uint64_t * ) dest_orig ;
  const uint64_t  * src = ( const uint64_t * ) src_orig ;
  int i ,
    max = size / sizeof ( uint64_t ) ;
  for ( i = 0 ; i < max ; i++ )
    *dest++ = *src++ ;
}
void
procedure_fusion (
		  char * tmp ,
		  char * t ,
		  int debut_tableaux ,
		  int milieu_tableaux ,
		  int fin_tableaux ,
		  size_t elt_size ,
		  cmp_function f ,
		  memcpy_t copie )
{
  int position_tableau_dest ,
    position_tableau_1 ,
    position_tableau_2 ; 
  for (
       position_tableau_dest = debut_tableaux ,
	 position_tableau_1 = debut_tableaux ,
	 position_tableau_2 = milieu_tableaux  ;
       ( position_tableau_1 < milieu_tableaux )
	 && ( position_tableau_2 < fin_tableaux ) ;
       position_tableau_dest += elt_size )
    {
      if ( f ( t + position_tableau_1  , t + position_tableau_2  ) < 0 )
	{
	  copie ( tmp + position_tableau_dest  , t + position_tableau_1  , elt_size ) ;
	  position_tableau_1 += elt_size ;
	}
      else
	{
	  copie ( tmp + position_tableau_dest  , t + position_tableau_2  , elt_size ) ;
	  position_tableau_2 += elt_size ;
	}
    }
  if ( position_tableau_1 < milieu_tableaux )
    copie ( tmp + position_tableau_dest  , t + position_tableau_1 , ( milieu_tableaux - position_tableau_1 )  ) ;
  if ( position_tableau_2 < fin_tableaux )
    copie ( tmp + position_tableau_dest  , t + position_tableau_2 , fin_tableaux - position_tableau_2  ) ;
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

void memcpy_4 ( void * dest_orig , const void * src_orig , size_t size )
{
  uint32_t * dest = ( uint32_t * ) dest_orig ;
  const uint32_t  * src = ( const uint32_t * ) src_orig ;
  int i ,
    max = size / sizeof ( uint32_t ) ;
  for ( i = 0 ; i < max ; i++ )
    *dest++ = *src++ ;
}

void adaptative_fusion ( void * t_orig , size_t elt_size , size_t nb_elts , cmp_function f )
{
  int
    nombre_d_iterations ,
    odd = 0  ,
    taille_totale = nb_elts * elt_size ;
  char
    * t = ( char * ) t_orig ,
    * tmp = ( char * ) malloc ( taille_totale ) ;
  int taille_courante_tableaux = MERGE_MIN_SIZE ;
  int
 #ifdef DEBUG
    nombre_theorique_de_phases = CHAR_BIT * sizeof ( unsigned int ) - __builtin_clz ( ( unsigned int ) nb_elts ) ,
#endif
    nombre_reel_de_phases ,
    nombre_de_swaps = 0 ;
  memcpy_t  copie = memcpy_builder ( t_orig , elt_size ) ;

  #ifdef DEBUG
  printf ( "nombre de phases calculées: %d\n" , nombre_theorique_de_phases ) ;
 #endif
  /* 
     On commence par s'assurer que tous les sous-tableaux de taille <=
   taille_courante_tableaux sont tries. 
  */
  if ( taille_courante_tableaux > 1 )
    {
      tri_fusion_court ( & tmp , & t , elt_size , nb_elts , taille_courante_tableaux , f , copie , & odd , & nombre_de_swaps ) ;
      nombre_reel_de_phases = 1 ;
    }
  // Fusion de tableaux dont la taille double à chaque itération
  for (
       nombre_reel_de_phases = 0 ,
       nombre_d_iterations = nb_elts / ( 2 * taille_courante_tableaux ) ;
       taille_courante_tableaux < nb_elts ;
       nombre_d_iterations /= 2 ,
	 taille_courante_tableaux *=  2 ,
       nombre_reel_de_phases++ )
    { // Dans chaque itération, faire nombre_d_iterations avec des paires de tableaux
      passe_fusion_avec_taille_fixee ( tmp , t ,
				       taille_courante_tableaux , elt_size , taille_totale ,
				       nombre_d_iterations ,
				       f , copie ) ;
      // et on met tmp dans t, et inversement
      swap_array ( & t , & tmp , & odd  , & nombre_de_swaps ) ;
    }
  recopie_si_necessaire ( tmp , t , taille_totale , odd , copie ) ;
  #ifdef DEBUG
  printf ( "nombre de phases:\n\ttheorique: %d\n\tpratique: %d\nnombre de swaps: %d\n" ,
	   nombre_theorique_de_phases ,
	   nombre_reel_de_phases ,
	   nombre_de_swaps ) ; 
#endif
    }

void memcpy_2 ( void * dest_orig , const void * src_orig , size_t size )
{
  uint16_t
    * dest = ( uint16_t * ) dest_orig ,
    * src = ( uint16_t * ) src_orig ;
  int i ,
    max = size / sizeof ( uint16_t ) ;
  for ( i = 0 ; i < max ; i++ )
    *dest++ = *src++ ;
}

void recopie_si_necessaire ( void * t1 , void * t2 , size_t taille_totale , int b , memcpy_t copie )
{
  if ( b )
    {
      printf (  "besoin de recopie\n" ) ;
      copie ( t1 , t2 , taille_totale ) ;
      free ( t2 ) ;
    }
  else
    {
      printf ( "recopie inutile\n" ) ;
      free ( t1 ) ;
    }
}

void memcpy_1 ( void * dest_orig , const void * src_orig , size_t size )
{
  uint8_t
    * dest = ( uint8_t * ) dest_orig ,
    * src = ( uint8_t * ) src_orig ;
  int i ,
    max = size / sizeof ( uint8_t ) ;
  for ( i = 0 ; i < max ; i++ )
    *dest++ = *src++ ;
}
void tri_fusion_court (
				     char ** t_dest ,
				      char ** t_orig ,
				     size_t elt_size ,
				     size_t nb_elts ,
				     size_t taille_courante_tableaux ,
				     cmp_function f ,
				     memcpy_t copie ,
				     int * odd ,
				     int * nb )
{
  int i ;
  for ( i = 0 ;
	i < elt_size * ( nb_elts - taille_courante_tableaux ) ;
	i +=  taille_courante_tableaux * elt_size )
    tri_court ( (*t_dest) + i , (*t_orig) + i  , elt_size , taille_courante_tableaux * elt_size , f , copie ) ;
  tri_court ( (*t_dest) + i , (*t_orig) +  i  , elt_size , elt_size * nb_elts  - i   , f , copie ) ;
  swap_array ( t_dest , t_orig , odd , nb ) ;
}


int
choose_best_type_size ( void * v , size_t elt_size )
{
  int pointer_alignment = alignment ( v ) ,
    size = elt_size ,
    res = 0 ;
  while ( ! ( pointer_alignment & 1 ) &&  ! ( size & 1 ) )
    {
      pointer_alignment /= 2 ;
      size /= 2 ;
      res += 1 ;
    }
  printf ( "taille choisie: %d\n" , 1 << res ) ;
  return res ;
}
void passe_fusion_avec_taille_fixee (  char * dest , char * src , size_t taille_courante_tableaux , size_t elt_size , size_t taille_totale , int nombre_d_iterations , cmp_function f , memcpy_t copie )
{
  size_t debut_tableaux , milieu_tableaux , fin_tableaux , nombre_de_fusions ;
  for (
	   debut_tableaux = 0 ,
	     milieu_tableaux = taille_courante_tableaux * elt_size ,
	     fin_tableaux = 2 * taille_courante_tableaux * elt_size ,
	     nombre_de_fusions = 0 ;
	   nombre_de_fusions < nombre_d_iterations ;
	   nombre_de_fusions++ ,
	     debut_tableaux = fin_tableaux  ,
	     milieu_tableaux += 2 * taille_courante_tableaux * elt_size ,
	     fin_tableaux += 2 * taille_courante_tableaux * elt_size
	   )
	// Pour chaque paire de tableau, appliquer l'algorithme de fusion
	procedure_fusion ( dest , src , debut_tableaux , milieu_tableaux , fin_tableaux , elt_size , f , copie ) ;
      if ( milieu_tableaux > taille_totale ) 	milieu_tableaux = taille_totale ; 
      if ( fin_tableaux > taille_totale ) fin_tableaux = taille_totale ;
      procedure_fusion ( dest , src , debut_tableaux , milieu_tableaux , fin_tableaux , elt_size , f , copie ) ;
}
int intcmp ( const void * a , const void * b )
{
  static int count = 0 ;
  if ( a == NULL )
    {
      printf ( "nombre de comparaisons: %d\n" , count ) ;
      * ( int * ) b += count ;
      count = 0 ;
      return 0 ;
    }
  count ++ ;
#ifdef DEBUG
  usleep ( SLEEP_TIME ) ;
  #endif
  return * ( const int * ) a - * ( const int * ) b ;
}
int
alignment ( void * v )
{
  if ( ( ( ( uintptr_t ) v ) % 8 ) == 0 ) return 8 ;
  if ( ( ( ( uintptr_t ) v ) % 4 ) == 0 ) return 4 ;
  if ( ( ( ( uintptr_t ) v ) % 2 ) == 0 ) return 2 ;
  return 1 ;
}
int
main ( int argc , char * argv[] )
{
  int t[TAB_SIZE] , elt_size , i , j , k , nb_ok = 0 , cmp_msort = 0 , cmp_qsort = 0 ;
  clock_t
    timings_qsort_end[NB_TABS] ,
    timings_qsort_begin[NB_TABS] ,
    timings_msort_end[NB_TABS] ,
    timings_msort_begin[NB_TABS] ;
  time_t debut  ;
  double average_msort , average_qsort ;
  srand48 ( time ( & debut  ) ) ;
  elt_size = sizeof ( int ) ;
  for ( i = 0 ; i < NB_TABS ; i++ )
    {
      for ( j = 0 ; j < TAB_SIZE ; j++ )
	t[j] = lrand48() ;
      timings_msort_begin[i] = clock ( ) ;
      adaptative_fusion ( t , elt_size , TAB_SIZE , intcmp ) ;
      timings_msort_end[i] = clock ( ) ;
      intcmp ( NULL , & cmp_msort ) ;
      for ( j = k = 0 ; j < TAB_SIZE - 1 ;  )
	if ( intcmp ( ( char * ) t + j++ * elt_size , ( char * ) t + ( ++k ) * elt_size  ) > 0 )
	  break ;
      nb_ok += ( j == ( TAB_SIZE - 1 ) ) ; 
      for ( j = 0 ; j < TAB_SIZE ; j++ )
	t[j] = lrand48() ;
      timings_qsort_begin[i]  =clock ( ) ;
      qsort ( t , TAB_SIZE , sizeof ( int ) , intcmp ) ;
      timings_qsort_end[i] = clock ( ) ;
      intcmp ( NULL , & cmp_qsort ) ;
    }
  for ( i = 0 , average_msort = average_qsort = 0 ; i < NB_TABS ; i++ )
    {
      average_msort += ( ( double ) timings_msort_end[i] - ( double ) timings_msort_begin[i] ) / CLOCKS_PER_SEC ;
      average_qsort += ( ( double ) timings_qsort_end[i] - ( double ) timings_qsort_begin[i] ) / CLOCKS_PER_SEC;
    }
  printf ( "Temps de calculs:\n\tfusion: %f\n\trapide: %f\n" ,
	   ( ( double ) average_msort ) / NB_TABS ,
	   ( ( double ) average_qsort ) / NB_TABS ) ;

  if ( nb_ok != NB_TABS )
    printf ( "erreur algo.\n" ) ;
  else
    printf ( "algo correct.\n" ) ;
  printf ( "Nombre total de comparaisons:\n\tfusion: %d\n\trapide: %d\n" ,
	   cmp_msort , cmp_qsort ) ;
  return 0 ;
}
