#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "throw.h"
#include "end_of_line.h"
#include "period.h"
#include "forward_slash.h"
#include "digit.h"
#include "letter_or_underscore.h"
#include "space.h"
#include "hyphen.h"
#include "end_object.h"
#include "command_line_arguments.h"
#include "write_or_throw.h"
#include "reopen_as_read_only_binary_or_throw.h"
#include "reopen_as_write_only_binary_or_throw.h"

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  if (argc < 44)
  {
    throw(
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
        "At least 43 arguments are required:\n",
        "• A prefix applied to any object names.\n",
        "• A prefix applied to any non-navigation material names.\n",
        "• A prefix applied to any navigation material names.\n",
        "• The name of a macro which declares data for an opaque/cutout pass (XYZ) (e.g. MACRO(object_name, { 1.0f, 2.0f, 3.0f })).\n",
        "• The name of a macro which declares data for an opaque pass (R, G, B) (e.g. MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f })).\n",
        "• The name of a macro which declares data for an opaque draw call (V, U, XYZ indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name, { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).\n",
        "• The name of a macro which declares data for a cutout pass (R, G, B, O) (e.g. MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f }, { 1.0f })).\n",
        "• The name of a macro which declares data for a cutout draw call (V, U XYZ indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name, { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).\n",
        "• The name of a macro which declares an opaque/cutout pass (e.g. MACRO(object_name, { /* Draw calls. */ })).\n",
        "• The name of a macro which declares an opaque draw call (e.g. MACRO(object_name, material_name)).\n",
        "• The name of a macro which declares a cutout draw call (e.g. MACRO(object_name, material_name)).\n",
        "• The name of a macro which declares data for an additive/blended pass (XYZ) (e.g. MACRO(object_name, { 1.0f, 2.0f, 3.0f })).\n",
        "• The name of a macro which declares data for an additive pass (R, G, B) (e.g. MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f })).\n",
        "• The name of a macro which declares data for an additive draw call (V, U, XYZ indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name, { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).\n",
        "• The name of a macro which declares data for a blended pass (R, G, B, O) (e.g. MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f }, { 1.0f })).\n",
        "• The name of a macro which declares data for a blended draw call (V, U XYZ indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name, { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).\n",
        "• The name of a macro which declares an additive/blended pass (e.g. MACRO(object_name, { /* Draw calls. */ })).\n",
        "• The name of a macro which declares an additive draw call (e.g. MACRO(object_name, material_name)).\n",
        "• The name of a macro which declares a blended draw call (e.g. MACRO(object_name, material_name)).\n",
        "• The name of a macro which declares a navigation mesh (a material type per face, a vertex count per face, an index offset per face, a location per vertex per face, a surface normal per face, an exit normal per edge per face, an up normal per vertex per face, a number of neighbors per edge per face, a neighbor index offset per edge per face, a face index per neighbor per edge per face) (e.g. MACRO(object_name, { MATERIAL_NAME }, { 3 }, { 0 }, { 1.0f, 2.0f, 3.0f }, { 0.0f, 1.0f, 0.0 }, { -1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 2 }, { 0 }, { 1, 2 })).\n",
        "• The name of a macro which declares a list of locations (e.g. LOCATION_LIST_MACRO_NAME(LOCATION_MACRO_NAME(...), LOCATION_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares the X, Y and Z coordinates of a single location (e.g. MACRO_NAME(1.23f, -3.25f, 94.24f)).\n",
        "• The name of a macro which declares a list of red intensities (e.g. RED_LIST_MACRO_NAME(RED_MACRO_NAME(...), RED_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a red intensity as a unit interval (e.g. RED_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of green intensities (e.g. GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(...), GREEN_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a green intensity as a unit interval (e.g. GREEN_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of blue intensities (e.g. BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(...), BLUE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a blue intensity as a unit interval (e.g. BLUE_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of opacities (e.g. OPACITY_LIST_MACRO_NAME(OPACITY_MACRO_NAME(...), OPACITY_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares an opacity as a unit interval (e.g. OPACITY_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of V coordinates (e.g. V_LIST_MACRO_NAME(V_MACRO_NAME(...), V_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a V coordinate (e.g. V_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of U coordinates (e.g. U_LIST_MACRO_NAME(U_MACRO_NAME(...), U_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a U coordinate (e.g. U_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of location index triangles (e.g. LOCATION_INDEX_LIST_MACRO_NAME(LOCATION_INDEX_TRIANGLE_MACRO_NAME(...), LOCATION_INDEX_TRIANGLE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a triangle of location indices (e.g. LOCATION_INDEX_TRIANGLE_MACRO_NAME(LOCATION_INDEX_MACRO_NAME(123), LOCATION_INDEX_MACRO_NAME(123), LOCATION_INDEX_MACRO_NAME(123))).\n"
        "• The name of a macro which declares a location index (e.g. LOCATION_INDEX_MACRO_NAME(123)).\n",
        "• The name of a macro which declares a list of color index triangles (e.g. COLOR_INDEX_LIST_MACRO_NAME(COLOR_INDEX_TRIANGLE_MACRO_NAME(...), COLOR_INDEX_TRIANGLE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a triangle of color indices (e.g. COLOR_INDEX_TRIANGLE_MACRO_NAME(COLOR_INDEX_MACRO_NAME(123), COLOR_INDEX_MACRO_NAME(123), COLOR_INDEX_MACRO_NAME(123))).\n",
        "• The name of a macro which declares a color index (e.g. COLOR_INDEX_MACRO_NAME(123)).\n",
        "• The name of a macro which declares a list of VU index triangles (e.g. VU_INDEX_LIST_MACRO_NAME(VU_INDEX_TRIANGLE_MACRO_NAME(...), VU_INDEX_TRIANGLE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a triangle of VU indices (e.g. VU_INDEX_TRIANGLE_MACRO_NAME(VU_INDEX_MACRO_NAME(123), VU_INDEX_MACRO_NAME(123), VU_INDEX_MACRO_NAME(123))).\n",
        "• The name of a macro which declares a VU index (e.g. VU_INDEX_MACRO_NAME(123)).\n",
        "• Any number of include paths.\n");
  }

  object_prefix = argv[1];
  material_prefix = argv[2];
  navigation_material_prefix = argv[3];
  opaque_cutout_pass_data_macro_name = argv[4];
  opaque_pass_data_macro_name = argv[5];
  opaque_draw_call_data_macro_name = argv[6];
  cutout_pass_data_macro_name = argv[7];
  cutout_draw_call_data_macro_name = argv[8];
  opaque_cutout_pass_macro_name = argv[9];
  opaque_draw_call_macro_name = argv[10];
  cutout_draw_call_macro_name = argv[11];
  additive_blended_pass_data_macro_name = argv[12];
  additive_pass_data_macro_name = argv[13];
  additive_draw_call_data_macro_name = argv[14];
  blended_pass_data_macro_name = argv[15];
  blended_draw_call_data_macro_name = argv[16];
  additive_blended_pass_macro_name = argv[17];
  additive_draw_call_macro_name = argv[18];
  blended_draw_call_macro_name = argv[19];
  navigation_macro_name = argv[20];
  location_list_macro_name = argv[21];
  location_macro_name = argv[22];
  red_list_macro_name = argv[23];
  red_macro_name = argv[24];
  green_list_macro_name = argv[25];
  green_macro_name = argv[26];
  blue_list_macro_name = argv[27];
  blue_macro_name = argv[28];
  opacity_list_macro_name = argv[29];
  opacity_macro_name = argv[30];
  v_list_macro_name = argv[31];
  v_macro_name = argv[32];
  u_list_macro_name = argv[33];
  u_macro_name = argv[34];
  location_index_triangle_list_macro_name = argv[35];
  location_index_triangle_macro_name = argv[36];
  location_index_macro_name = argv[37];
  color_index_triangle_list_macro_name = argv[38];
  color_index_triangle_macro_name = argv[39];
  color_index_macro_name = argv[40];
  vu_index_triangle_list_macro_name = argv[41];
  vu_index_triangle_macro_name = argv[42];
  vu_index_macro_name = argv[43];
  include_paths = argv + 44;
  number_of_include_paths = argc - 44;

  reopen_as_read_only_binary_or_throw(stdin);
  reopen_as_write_only_binary_or_throw(stdout);

  for (size_t include_path = 0; include_path < number_of_include_paths; include_path++)
  {
    write_or_throw(stdout, "#include \"%s\"\n", include_paths[include_path]);
  }

  while (true)
  {
    const int character = fgetc(stdin);

    switch (character)
    {
    case EOF:
    {
      const int error = ferror(stdin);

      if (error != 0)
      {
        throw("Failed to read from standard input (error number %d).", error);
      }

      end_of_line();
      end_object();
      return 0;
    }

    case '\r':
    case '\n':
      end_of_line();
      break;

    case ' ':
    case '\t':
      space();
      break;

    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '_':
      letter_or_underscore(character);
      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      digit(character - '0');
      break;

    case '.':
      period();
      break;

    case '/':
      forward_slash();
      break;

    case '-':
      hyphen();
      break;

    default:
      throw("Unexpected character \"%c\".", character);
    }
  }
}
