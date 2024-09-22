#include "magnitude.h"
#include "throw.h"

void normalize(const float vector[3], float normal[3])
{
  const float vector_magnitude = magnitude(vector);

  if (vector_magnitude < 0.01f)
  {
    throw("Failed to normalize a vector as its magnitude is too small.");
  }

  normal[0] = vector[0] / vector_magnitude;
  normal[1] = vector[1] / vector_magnitude;
  normal[2] = vector[2] / vector_magnitude;
}
