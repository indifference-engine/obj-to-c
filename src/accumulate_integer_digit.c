#include "accumulate_integer_digit.h"
#include "accumulated_integer.h"
#include "malloc_or_throw.h"
#include "realloc_or_throw.h"

void accumulate_integer_digit(const int digit) {
  if (accumulated_integer_length) {
    accumulated_integer = realloc_or_throw(
        accumulated_integer, sizeof(char) * (accumulated_integer_length + 2));
    accumulated_integer[accumulated_integer_length] = '0' + digit;
    accumulated_integer[accumulated_integer_length + 1] = '\0';
    accumulated_integer_length++;
  } else {
    accumulated_integer = malloc_or_throw(sizeof(char) * 2);
    accumulated_integer[0] = '0' + digit;
    accumulated_integer[1] = '\0';
    accumulated_integer_length = 1;
  }
}
