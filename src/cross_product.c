#include "cross_product.h"

void cross_product(const float a[3], const float b[3], float result[3])
{
  const float x = a[1] * b[2] - b[1] * a[2];
  const float y = a[2] * b[0] - b[2] * a[0];
  const float z = a[0] * b[1] - b[0] * a[1];
  result[0] = x;
  result[1] = y;
  result[2] = z;
}
