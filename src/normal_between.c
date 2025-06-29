#include "normal_between.h"
#include "normalize.h"
#include "subtract.h"

void normal_between(const float from[3], const float to[3], float result[3]) {
  subtract(to, from, result);
  normalize(result, result);
}
