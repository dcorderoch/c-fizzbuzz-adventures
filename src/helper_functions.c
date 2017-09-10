#include "helper_functions.h"

#define FIZZ_NUMBER 3
#define BUZZ_NUMBER 5

#ifdef SLEEP
#define DELAY_IN_MILLISECONDS 75
#endif

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

  int buf_len = strlen ( message_buffer );
  memset ( message_buffer, 0, buf_len );

  if ( is_fizz )
    append_fizz_to_char_buffer ( message_buffer );
  if ( is_buzz )
    append_buzz_to_buffer ( message_buffer );
  if ( nor ( is_fizz, is_buzz ) )
    set_buffer_to_number ( message_buffer, number_ptr );
}

void
#ifdef NUMBER
print_fizzbuzz ( int * number, char * message_buffer )
#else
print_fizzbuzz ( char * message_buffer )
#endif
{
  #ifdef NUMBER
  printf ( "%03d - ", *number );
  #endif
  printf ( "%s\n", message_buffer );
  #ifdef SLEEP
  u_sleep ( DELAY_IN_MILLISECONDS );
  #endif
}
