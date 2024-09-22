#include <stdio.h>
#include "accumulate_float.h"
#include "accumulated_float.h"
#include "throw.h"

float accumulate_float(void)
{
  if (accumulated_float_length)
  {
    float output;

    if (sscanf(accumulated_float, "%f", &output))
    {
      free(accumulated_float);
      accumulated_float = NULL;
      accumulated_float_length = 0;
      return output;
    }
    else
    {
      throw("Failed to parse float \"%s\".", accumulated_float);
    }
  }
  else
  {
    throw("No float accumulated.");
  }
}
