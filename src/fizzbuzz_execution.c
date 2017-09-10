#include "fizzbuzz_execution.h"

void
run_fizzbuzz_until_with_buffer ( int number, char * buffer )
{
  int i;
  for ( i = 1 ; i <= number ; i++ )
    {
      set_fizzbuzz ( &i, buffer );

      #ifdef NUMBER
      print_fizzbuzz ( &i, buffer );
      #else
      print_fizzbuzz ( buffer );
      #endif
    }
}
