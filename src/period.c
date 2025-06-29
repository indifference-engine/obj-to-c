#include "period.h"
#include "accumulate_float_period.h"
#include "state.h"
#include "throw.h"

void period(void) {
  switch (state) {
  case STATE_MTLLIB_NAME:
    return;

  case STATE_V_SPACE:
    state = STATE_V_X;
    accumulate_float_period();
    return;

  case STATE_V_X:
    accumulate_float_period();
    return;

  case STATE_V_X_SPACE:
    state = STATE_V_Y;
    accumulate_float_period();
    return;

  case STATE_V_Y:
    accumulate_float_period();
    return;

  case STATE_V_Y_SPACE:
    state = STATE_V_Z;
    accumulate_float_period();
    return;

  case STATE_V_Z:
    accumulate_float_period();
    return;

  case STATE_V_Z_SPACE:
    state = STATE_V_R;
    accumulate_float_period();
    return;

  case STATE_V_R:
    accumulate_float_period();
    return;

  case STATE_V_R_SPACE:
    state = STATE_V_G;
    accumulate_float_period();
    return;

  case STATE_V_G:
    accumulate_float_period();
    return;

  case STATE_V_G_SPACE:
    state = STATE_V_B;
    accumulate_float_period();
    return;

  case STATE_V_B:
    accumulate_float_period();
    return;

  case STATE_V_B_SPACE:
    state = STATE_V_O;
    accumulate_float_period();
    return;

  case STATE_V_O:
    accumulate_float_period();
    return;

  case STATE_VT_SPACE:
    state = STATE_VT_U;
    accumulate_float_period();
    return;

  case STATE_VT_U:
    accumulate_float_period();
    return;

  case STATE_VT_U_SPACE:
    state = STATE_VT_V;
    accumulate_float_period();
    return;

  case STATE_VT_V:
    accumulate_float_period();
    return;
  }

  throw("Unexpected period in state %d.", state);
}
