#include "dot_product.h"

float dot_product(const float multiplier[3], const float multiplicand[3]) {
  return multiplier[0] * multiplicand[0] + multiplier[1] * multiplicand[1] +
         multiplier[2] * multiplicand[2];
}
