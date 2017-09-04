#include <stdio.h>   /* printf () */
#include <stdlib.h>  /* exit () */
#include <stdbool.h> /* bool */
#include <string.h>  /* memset () */

/* fizzbuzz is 8 characters in length, plus one for null terminator */
#define STRING_LENGTH_WITH_NULL_AT_END 9
#define FIZZ_NUMBER 3
#define BUZZ_NUMBER 5

int
main ( void )
{
  char buffer[STRING_LENGTH_WITH_NULL_AT_END] = { 0 };
  bool fizz = false;
  bool buzz = false;

  int i;
  for ( i = 1 ; i < 16 ; i++ )
    {
      fizz = i % FIZZ_NUMBER == 0;
      buzz = i % BUZZ_NUMBER == 0;

      if ( fizz )
        sprintf ( buffer, "fizz" );
      if ( buzz )
        sprintf ( buffer, "%s%s", buffer, "buzz" );
      if ( !(fizz || buzz) )
        sprintf ( buffer, "%d", i );

      printf ( "%s\n", buffer );

      memset ( buffer, 0, STRING_LENGTH_WITH_NULL_AT_END );
    }
  exit ( EXIT_SUCCESS );
}
