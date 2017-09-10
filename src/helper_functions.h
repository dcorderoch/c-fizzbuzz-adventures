#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef SLEEP
#include <unistd.h>  /* sleep (). */

void
u_sleep ( int microseconds );
#endif /* SLEEP */

bool
is_first_divisible_by_second ( int first, int second );

bool
nor ( bool expr_A, bool expr_B );

void
append_fizz_to_char_buffer ( char * buffer );

void
append_buzz_to_buffer ( char * buffer );

void
set_buffer_to_number ( char * buffer, int * number_ptr );

void
set_fizzbuzz ( int * number_ptr, char * message_buffer );

void
print_fizzbuzz ( int * number, char * message_buffer );

#endif /* HELPER_FUNCTIONS_H */
