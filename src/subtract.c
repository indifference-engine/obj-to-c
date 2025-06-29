#include "subtract.h"

void subtract(const float minuend[3], const float subtrahend[3],
              float difference[3]) {
  difference[0] = minuend[0] - subtrahend[0];
  difference[1] = minuend[1] - subtrahend[1];
  difference[2] = minuend[2] - subtrahend[2];
}
