#include <stdio.h>   /* printf (). */
#include <stdlib.h>  /* exit (). */
#include <stdbool.h> /* bool. */
#include <string.h>  /* memset (), sprintf (). */
#include <unistd.h>  /* sleep (). */

/* fizzbuzz is 8 characters in length, plus one for null terminator. */
#define STRING_LENGTH_WITH_NULL_AT_END 9
#define FIZZ_NUMBER 3
#define BUZZ_NUMBER 5
/* minimum number to see fizzbuzz. */
#define DEFAULT_FIZZBUZZ_UNTIL 15

#ifdef SLEEP
#define DELAY 75 /* delay in milliseconds. */

void
u_sleep ( int microseconds )
{
  usleep ( microseconds * 1000 );
}
#endif

bool
is_first_divisible_by_second ( int first, int second )
{
  return ( first % second == 0 );
}

bool
nor ( bool expr_A, bool expr_B )
{
  return !( expr_A || expr_B );
}

int
main ( int argc, char ** argv )
{
  int fizzbuzz_until = 0;
  if ( argc < 2 )
    fizzbuzz_until = DEFAULT_FIZZBUZZ_UNTIL;
  else
    fizzbuzz_until = atoi ( argv[1] );
  char buffer[STRING_LENGTH_WITH_NULL_AT_END] = { 0 };
  bool is_fizz = false;
  bool is_buzz = false;

  int i;
  for ( i = 1 ; i <= fizzbuzz_until ; i++ )
    {
      is_fizz = is_first_divisible_by_second ( i, FIZZ_NUMBER );
      is_buzz = is_first_divisible_by_second ( i, BUZZ_NUMBER );

      if ( is_fizz )
        sprintf ( buffer, "fizz" );
      if ( is_buzz )
        sprintf ( buffer, "%s%s", buffer, "buzz" );
      if ( nor ( is_fizz, is_buzz ) )
        sprintf ( buffer, "%d", i );

      #ifdef NUMBER
      printf ( "%03d - ", i );
      #endif
      printf ( "%s\n", buffer );
      memset ( buffer, 0, STRING_LENGTH_WITH_NULL_AT_END );
      #ifdef SLEEP
      u_sleep ( DELAY );
      #endif
    }
  exit ( EXIT_SUCCESS );
}
