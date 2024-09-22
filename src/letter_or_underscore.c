#include "state.h"
#include "throw.h"
#include "object_name.h"
#include "material_name.h"
#include "malloc_or_throw.h"
#include "realloc_or_throw.h"

void letter_or_underscore(const char letter_or_underscore)
{
  switch (state)
  {
  case STATE_INITIAL:
    switch (letter_or_underscore)
    {
    case 'u':
      state = STATE_U;
      return;

    case 'm':
      state = STATE_M;
      return;

    case 'o':
      state = STATE_O;
      return;

    case 'v':
      state = STATE_V;
      return;

    case 'f':
      state = STATE_F;
      return;
    }
    break;

  case STATE_M:
    switch (letter_or_underscore)
    {
    case 't':
      state = STATE_MT;
      return;
    }
    break;

  case STATE_MT:
    switch (letter_or_underscore)
    {
    case 'l':
      state = STATE_MTL;
      return;
    }
    break;

  case STATE_MTL:
    switch (letter_or_underscore)
    {
    case 'l':
      state = STATE_MTLL;
      return;
    }
    break;

  case STATE_MTLL:
    switch (letter_or_underscore)
    {
    case 'i':
      state = STATE_MTLLI;
      return;
    }
    break;

  case STATE_MTLLI:
    switch (letter_or_underscore)
    {
    case 'b':
      state = STATE_MTLLIB;
      return;
    }
    break;

  case STATE_MTLLIB_SPACE:
    state = STATE_MTLLIB_NAME;
    return;

  case STATE_MTLLIB_NAME:
    return;

  case STATE_U:
    state = STATE_US;
    return;

  case STATE_US:
    state = STATE_USE;
    return;

  case STATE_USE:
    state = STATE_USEM;
    return;

  case STATE_USEM:
    state = STATE_USEMT;
    return;

  case STATE_USEMT:
    state = STATE_USEMTL;
    return;

  case STATE_O_SPACE:
    state = STATE_O_NAME;
    object_name = malloc_or_throw(sizeof(char) * 2);
    object_name[0] = letter_or_underscore;
    object_name[1] = '\0';
    object_name_length = 1;
    return;

  case STATE_O_NAME:
    object_name = realloc_or_throw(object_name, sizeof(char) * (object_name_length + 2));
    object_name[object_name_length] = letter_or_underscore;
    object_name[object_name_length + 1] = '\0';
    object_name_length++;
    return;

  case STATE_USEMTL_SPACE:
    state = STATE_USEMTL_NAME;
    material_name = malloc_or_throw(sizeof(char) * 2);
    material_name[0] = letter_or_underscore;
    material_name[1] = '\0';
    material_name_length = 1;
    return;

  case STATE_USEMTL_NAME:
    material_name = realloc_or_throw(material_name, sizeof(char) * (material_name_length + 2));
    material_name[material_name_length] = letter_or_underscore;
    material_name[material_name_length + 1] = '\0';
    material_name_length++;
    return;

  case STATE_V:
    switch (letter_or_underscore)
    {
    case 't':
      state = STATE_VT;
      return;
    }
    return;
  }

  throw("Unexpected %c in state %d.", letter_or_underscore, state);
}
