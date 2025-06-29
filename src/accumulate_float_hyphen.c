#include "accumulate_float_hyphen.h"
#include "accumulated_float.h"
#include "malloc_or_throw.h"
#include "throw.h"

void accumulate_float_hyphen(void) {
  if (accumulated_float_length) {
    throw("Unexpected hyphen inside a float.");
  } else {
    accumulated_float = malloc_or_throw(sizeof(char) * 2);
    accumulated_float[0] = '-';
    accumulated_float[1] = '\0';
    accumulated_float_length = 1;
  }
}
