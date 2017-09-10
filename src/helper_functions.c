#include "helper_functions.h"

#define FIZZ_NUMBER 3
#define BUZZ_NUMBER 5

#ifdef SLEEP
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

void
append_fizz_to_char_buffer ( char * buffer )
{
  sprintf ( buffer, "fizz" );
}

void
append_buzz_to_buffer ( char * buffer )
{
  sprintf ( buffer, "%s%s", buffer, "buzz" );
}

void
set_buffer_to_number ( char * buffer, int * number_ptr )
{
  sprintf ( buffer, "%d", *number_ptr );
}

void
set_fizzbuzz ( int * number_ptr, char * message_buffer )
{
  bool is_fizz = is_first_divisible_by_second ( *number_ptr, FIZZ_NUMBER );
  bool is_buzz = is_first_divisible_by_second ( *number_ptr, BUZZ_NUMBER );

  if ( is_fizz )
    append_fizz_to_char_buffer ( message_buffer );
  if ( is_buzz )
    append_buzz_to_buffer ( message_buffer );
  if ( nor ( is_fizz, is_buzz ) )
    set_buffer_to_number ( message_buffer, number_ptr );
}