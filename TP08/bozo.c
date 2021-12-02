#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <limits.h>

#include "memoire.h"
#include "tri.h"

#define TAB_SIZE 1000
#define NB_TABS 10
#define SLEEP_TIME 0

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
