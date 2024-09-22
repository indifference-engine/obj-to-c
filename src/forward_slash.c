#include "forward_slash.h"
#include "state.h"
#include "throw.h"
#include "vertices.h"
#include "indices.h"
#include "accumulate_integer.h"

void forward_slash()
{
  switch (state)
  {
  case STATE_F_V:
  {
    int v = accumulate_integer();

    if (v < 0)
    {
      v += number_of_vertices;

      if (v < 0)
      {
        throw("Face references nonexistent vertex.");
      }
    }

    if ((size_t)v >= number_of_vertices)
    {
      throw("Face references nonexistent vertex.");
    }

    index_v[number_of_indices - 1] = v;
    state = STATE_F_V_SLASH;
    return;
  }
  }

  throw("Unexpected forward slash in state %d.", state);
}
