#include "digit.h"
#include "accumulate_float_digit.h"
#include "accumulate_integer_digit.h"
#include "faces.h"
#include "indices.h"
#include "object_type.h"
#include "state.h"
#include "throw.h"

void digit(const int digit) {
  switch (state) {
  case STATE_V_SPACE:
    state = STATE_V_X;
    accumulate_float_digit(digit);
    return;

  case STATE_V_X:
    accumulate_float_digit(digit);
    return;

  case STATE_V_X_SPACE:
    state = STATE_V_Y;
    accumulate_float_digit(digit);
    return;

  case STATE_V_Y:
    accumulate_float_digit(digit);
    return;

  case STATE_V_Y_SPACE:
    state = STATE_V_Z;
    accumulate_float_digit(digit);
    return;

  case STATE_V_Z:
    accumulate_float_digit(digit);
    return;

  case STATE_V_Z_SPACE:
    state = STATE_V_R;
    accumulate_float_digit(digit);
    return;

  case STATE_V_R:
    accumulate_float_digit(digit);
    return;

  case STATE_V_R_SPACE:
    state = STATE_V_G;
    accumulate_float_digit(digit);
    return;

  case STATE_V_G:
    accumulate_float_digit(digit);
    return;

  case STATE_V_G_SPACE:
    state = STATE_V_B;
    accumulate_float_digit(digit);
    return;

  case STATE_V_B:
    accumulate_float_digit(digit);
    return;

  case STATE_V_B_SPACE:
    state = STATE_V_O;
    accumulate_float_digit(digit);
    return;

  case STATE_V_O:
    accumulate_float_digit(digit);
    return;

  case STATE_VT_SPACE:
    state = STATE_VT_U;
    accumulate_float_digit(digit);
    return;

  case STATE_VT_U:
    accumulate_float_digit(digit);
    return;

  case STATE_VT_U_SPACE:
    state = STATE_VT_V;
    accumulate_float_digit(digit);
    return;

  case STATE_VT_V:
    accumulate_float_digit(digit);
    return;

  case STATE_F_SPACE:
    if (number_of_indices) {
      index_v = realloc(index_v, sizeof(size_t) * (number_of_indices + 1));

      if (object_type == OBJECT_TYPE_GRAPHICAL) {
        index_vt = realloc(index_vt, sizeof(size_t) * (number_of_indices + 1));
      }

      number_of_indices++;
    } else {
      index_v = malloc(sizeof(size_t));

      if (object_type == OBJECT_TYPE_GRAPHICAL) {
        index_vt = malloc(sizeof(size_t));
      }

      number_of_indices = 1;
    }

    face_lengths[number_of_faces - 1]++;

    accumulate_integer_digit(digit);
    state = STATE_F_V;
    return;

  case STATE_F_V:
    accumulate_integer_digit(digit);
    return;

  case STATE_F_V_SLASH:
    state = STATE_F_VT;
    accumulate_integer_digit(digit);
    return;

  case STATE_F_VT:
    accumulate_integer_digit(digit);
    return;
  }

  throw("Unexpected %c in state %d.", '0' + digit, state);
}
