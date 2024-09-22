#include <math.h>
#include "magnitude.h"

float magnitude(const float vector[3])
{
  return sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
}
