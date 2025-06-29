#include "accumulate_integer_hyphen.h"
#include "accumulated_integer.h"
#include "malloc_or_throw.h"
#include "throw.h"

void accumulate_integer_hyphen(void) {
  if (accumulated_integer_length) {
    throw("Unexpected hyphen inside an integer.");
  } else {
    accumulated_integer = malloc_or_throw(sizeof(char) * 2);
    accumulated_integer[0] = '-';
    accumulated_integer[1] = '\0';
    accumulated_integer_length = 1;
  }
}
