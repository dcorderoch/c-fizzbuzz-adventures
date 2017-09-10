#include <stdio.h>   /* printf (). */
#include <stdlib.h>  /* exit (). */
#include <stdbool.h> /* bool. */
#include <string.h>  /* memset (), sprintf (). */

#include "fizzbuzz_execution.h"

/* fizzbuzz is 8 characters in length, plus one for null terminator. */
#define STRING_LENGTH_WITH_NULL_AT_END 9
/* minimum number to see fizzbuzz. */
#define DEFAULT_FIZZBUZZ_UNTIL 15

int
main ( int argc, char ** argv )
{
  int fizzbuzz_until = 0;
  if ( argc < 2 )
    fizzbuzz_until = DEFAULT_FIZZBUZZ_UNTIL;
  else
    fizzbuzz_until = atoi ( argv[1] );
  char * buffer = calloc ( 1, STRING_LENGTH_WITH_NULL_AT_END );

  run_fizzbuzz_until_with_buffer ( fizzbuzz_until, buffer );

  free ( buffer );
  exit ( EXIT_SUCCESS );
}
