#include "fizzbuzz_execution.h"

void
run_fizzbuzz_until_with_buffer ( int number, char * buffer )
{
  int i;
  for ( i = 1 ; i <= number ; i++ )
    {
      set_fizzbuzz ( &i, buffer );

      print_fizzbuzz ( &i, buffer );
    }
}
