#include "fizzbuzz_execution.h"

#ifdef SLEEP
#define DELAY_IN_MILLISECONDS 75
#endif

void
run_fizzbuzz_until_with_buffer ( int number, char * buffer )
{
  int i;
  int buf_len = strlen ( buffer );
  for ( i = 1 ; i <= number ; i++ )
    {
      set_fizzbuzz ( &i, buffer );

      #ifdef NUMBER
      printf ( "%03d - ", i );
      #endif
      printf ( "%s\n", buffer );
      memset ( buffer, 0, buf_len );
      #ifdef SLEEP
      u_sleep ( DELAY_IN_MILLISECONDS );
      #endif
    }
}
