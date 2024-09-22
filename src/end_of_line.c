#include <stdint.h>
#include "state.h"
#include "throw.h"
#include "validate_face.h"
#include "vertices.h"
#include "texture_coordinates.h"
#include "indices.h"
#include "register_material.h"
#include "accumulate_float.h"
#include "accumulate_integer.h"

void end_of_line(void)
{
  switch (state)
  {
  case STATE_INITIAL:
    return;

  case STATE_MTLLIB_NAME:
    state = STATE_INITIAL;
    return;

  case STATE_O_NAME:
    state = STATE_INITIAL;
    return;

  case STATE_O_NAME_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_USEMTL_NAME:
    register_material();
    state = STATE_INITIAL;
    return;

  case STATE_USEMTL_NAME_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V:
    state = STATE_INITIAL;
    return;

  case STATE_V_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_X:
    vertex_x[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_X_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_Y:
    vertex_y[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_Y_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_Z:
    vertex_z[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_Z_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_R:
    vertex_red[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_R_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_G:
    vertex_green[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_G_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_B:
    vertex_blue[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_B_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_V_O:
    vertex_opacity[number_of_vertices - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_V_O_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_VT_U:
    texture_coordinate_u[number_of_texture_coordinates - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_VT_U_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_VT_V:
    texture_coordinate_v[number_of_texture_coordinates - 1] = accumulate_float();
    state = STATE_INITIAL;
    return;

  case STATE_VT_V_SPACE:
    state = STATE_INITIAL;
    return;

  case STATE_F_SPACE:
    validate_face();
    state = STATE_INITIAL;
    return;

  case STATE_F_VT:
  {
    int vt = accumulate_integer();

    if (vt < 0)
    {
      vt += number_of_texture_coordinates;

      if (vt < 0)
      {
        throw("Face references nonexistent texture coordinate.");
      }
    }

    if ((size_t)vt >= number_of_texture_coordinates)
    {
      throw("Face references nonexistent texture coordinate.");
    }

    index_vt[number_of_indices - 1] = vt;

    validate_face();
    state = STATE_INITIAL;
    return;
  }
  }

  throw("Unexpected end-of-line in state %d.", state);
}
