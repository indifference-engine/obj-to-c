#include "normal_between.h"
#include "subtract.h"
#include "normalize.h"

void normal_between(const float from[3], const float to[3], float result[3])
{
  subtract(to, from, result);
  normalize(result, result);
}
