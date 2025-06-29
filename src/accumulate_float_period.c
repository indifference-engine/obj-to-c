#include "accumulate_float_period.h"
#include "accumulated_float.h"
#include "malloc_or_throw.h"
#include "realloc_or_throw.h"
#include "throw.h"

void accumulate_float_period(void) {
  if (accumulated_float_length) {
    for (size_t index = 0; index < accumulated_float_length; index++) {
      if (accumulated_float[index] == '.') {
        throw("Multiple decimal points in float.");
      }
    }

    accumulated_float = realloc_or_throw(
        accumulated_float, sizeof(char) * (accumulated_float_length + 2));
    accumulated_float[accumulated_float_length] = '.';
    accumulated_float[accumulated_float_length + 1] = '\0';
    accumulated_float_length++;
  } else {
    accumulated_float = malloc_or_throw(sizeof(char) * 2);
    accumulated_float[0] = '.';
    accumulated_float[1] = '\0';
    accumulated_float_length = 1;
  }
}
