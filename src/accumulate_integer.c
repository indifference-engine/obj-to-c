#include <stdio.h>
#include "accumulate_integer.h"
#include "accumulated_integer.h"
#include "throw.h"

int accumulate_integer(void)
{
  if (accumulated_integer_length)
  {
    int output;

    if (sscanf(accumulated_integer, "%d", &output))
    {
      free(accumulated_integer);
      accumulated_integer = NULL;
      accumulated_integer_length = 0;
      return output;
    }
    else
    {
      throw("Failed to parse integer \"%s\".", accumulated_integer);
    }
  }
  else
  {
    throw("No integer accumulated.");
  }
}
