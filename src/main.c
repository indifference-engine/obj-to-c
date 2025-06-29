#include "command_line_arguments.h"
#include "digit.h"
#include "end_object.h"
#include "end_of_line.h"
#include "forward_slash.h"
#include "hyphen.h"
#include "letter_or_underscore.h"
#include "period.h"
#include "reopen_as_read_only_binary_or_throw.h"
#include "reopen_as_write_only_binary_or_throw.h"
#include "space.h"
#include "throw.h"
#include "write_or_throw.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  if (argc < 72) {
    throw(
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%"
        "s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%"
        "s%s%s%s",
        "At least 67 arguments are required:\n",
        "• A prefix applied to any object names.\n",
        "• A prefix applied to any non-navigation material names.\n",
        "• A prefix applied to any navigation material names.\n",
        "• The name of a macro which declares data for an opaque/cutout pass "
        "(e.g. OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME(object_name, "
        "LOCATION_LIST_MACRO_NAME(...))).\n",
        "• The name of a macro which declares data for an opaque pass (e.g. "
        "OPAQUE_PASS_DATA_MACRO_NAME(object_name, RED_LIST_MACRO_NAME(...), "
        "GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...))).\n",
        "• The name of a macro which declares data for an opaque draw call "
        "(e.g. OPAQUE_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name, "
        "V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...), "
        "LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).\n",
        "• The name of a macro which declares data for a cutout pass (e.g. "
        "CUTOUT_PASS_DATA_MACRO_NAME(object_name, "
        "OPACITY_LIST_MACRO_NAME(...), RED_LIST_MACRO_NAME(...), "
        "GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...))).\n",
        "• The name of a macro which declares data for a cutout draw call "
        "(e.g. CUTOUT_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name, "
        "V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...), "
        "LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).\n",
        "• The name of a macro which declares an opaque/cutout pass (e.g. "
        "OPAQUE_CUTOUT_PASS_MACRO_NAME(object_name, "
        "TEST_OPAQUE_PREPARATION_MACRO_NAME(...), "
        "TEST_CUTOUT_PREPARATION_MACRO_NAME(...), "
        "OPAQUE_DRAW_CALL_MACRO_NAME(...), CUTOUT_DRAW_CALL_MACRO_NAME(...), "
        "...)).\n",
        "• The name of a macro which declares preparation for an opaque/cutout "
        "pass including opaque draw calls (e.g. "
        "TEST_OPAQUE_PREPARATION_MACRO_NAME(object_name)).\n",
        "• The name of a macro which declares preparation for an opaque/cutout "
        "pass including cutout draw calls (e.g. "
        "TEST_CUTOUT_PREPARATION_MACRO_NAME(object_name)).\n",
        "• The name of a macro which declares an opaque draw call (e.g. "
        "OPAQUE_DRAW_CALL_MACRO_NAME(object_name, material_name)).\n",
        "• The name of a macro which declares a cutout draw call (e.g. "
        "CUTOUT_DRAW_CALL_MACRO_NAME(object_name, material_name)).\n",
        "• The name of a macro which declares data for an additive/blended "
        "pass (XYZ) (e.g. ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME(object_name, "
        "LOCATION_LIST_MACRO_NAME(...))).\n",
        "• The name of a macro which declares data for an additive pass (e.g. "
        "ADDITIVE_PASS_DATA_MACRO_NAME(object_name, RED_LIST_MACRO_NAME(...), "
        "GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...))).\n",
        "• The name of a macro which declares data for an additive draw call "
        "(e.g. ADDITIVE_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name, "
        "V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...), "
        "LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).\n",
        "• The name of a macro which declares data for a blended pass (e.g. "
        "BLENDED_PASS_DATA_MACRO_NAME(object_name, "
        "OPACITY_LIST_MACRO_NAME(...), RED_LIST_MACRO_NAME(...), "
        "GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...))).\n",
        "• The name of a macro which declares data for a blended draw call "
        "(e.g. BLENDED_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name, "
        "V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...), "
        "LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...), "
        "VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).\n",
        "• The name of a macro which declares an additive/blended pass (e.g. "
        "ADDITIVE_BLENDED_PASS_MACRO_NAME(object_name, "
        "TEST_ADDITIVE_PREPARATION_MACRO_NAME(...), "
        "TEST_BLENDED_PREPARATION_MACRO_NAME(...), "
        "ADDITIVE_DRAW_CALL_MACRO_NAME(...), "
        "BLENDED_DRAW_CALL_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares preparation for an "
        "additive/blended pass including additive draw calls (e.g. "
        "TEST_ADDITIVE_PREPARATION_MACRO_NAME(object_name)).\n",
        "• The name of a macro which declares preparation for an "
        "additive/blended pass including blended draw calls (e.g. "
        "TEST_BLENDED_PREPARATION_MACRO_NAME(object_name)).\n",
        "• The name of a macro which declares an additive draw call (e.g. "
        "ADDITIVE_DRAW_CALL_MACRO_NAME(object_name, material_name)).\n",
        "• The name of a macro which declares a blended draw call (e.g. "
        "BLENDED_DRAW_CALL_MACRO_NAME(object_name, material_name)).\n",
        "• The name of a macro which declares a navigation mesh (e.g. "
        "NAVIGATION_MACRO_NAME(object_name, MATERIAL_LIST_MACRO_NAME(...), "
        "FACE_VERTEX_COUNT_LIST_MACRO_NAME(...), "
        "FACE_VERTEX_OFFSET_LIST_MACRO_NAME(...), "
        "FACE_VERTEX_LOCATION_LIST_NAME(...), NORMAL_LIST_MACRO_NAME(...), "
        "FACE_EDGE_EXIT_NORMAL_LIST_MACRO_NAME(...), "
        "FACE_EDGE_NORMAL_LIST_MACRO_NAME(...), "
        "FACE_VERTEX_UP_NORMAL_LIST_MACRO_NAME(...), "
        "NEIGHBOR_COUNT_LIST_MACRO_NAME(...), "
        "FACE_EDGE_OFFSET_LIST_MACRO_NAME(...), "
        "FACE_EDGE_NEIGHBOR_OFFSET_LIST_MACRO_NAME(...), "
        "FACE_EDGE_NEIGHBOR_FACE_INDEX_LIST_MACRO_NAME(...)).\n",
        "• The name of a macro which declares a list of locations (e.g. "
        "LOCATION_LIST_MACRO_NAME(LOCATION_MACRO_NAME(...), "
        "LOCATION_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares the X, Y and Z coordinates of a "
        "single location (e.g. LOCATION_MACRO_NAME(1.23f, -3.25f, 94.24f)).\n",
        "• The name of a macro which declares a list of opacities (e.g. "
        "OPACITY_LIST_MACRO_NAME(OPACITY_MACRO_NAME(...), "
        "OPACITY_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares an opacity as a unit interval "
        "(e.g. OPACITY_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of red intensities (e.g. "
        "RED_LIST_MACRO_NAME(RED_MACRO_NAME(...), RED_MACRO_NAME(...), "
        "...)).\n",
        "• The name of a macro which declares a red intensity as a unit "
        "interval (e.g. RED_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of green intensities "
        "(e.g. GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(...), "
        "GREEN_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a green intensity as a unit "
        "interval (e.g. GREEN_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of blue intensities (e.g. "
        "BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(...), BLUE_MACRO_NAME(...), "
        "...)).\n",
        "• The name of a macro which declares a blue intensity as a unit "
        "interval (e.g. BLUE_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of V coordinates (e.g. "
        "V_LIST_MACRO_NAME(V_MACRO_NAME(...), V_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a V coordinate (e.g. "
        "V_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of U coordinates (e.g. "
        "U_LIST_MACRO_NAME(U_MACRO_NAME(...), U_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a U coordinate (e.g. "
        "U_MACRO_NAME(0.92f)).\n",
        "• The name of a macro which declares a list of location index "
        "triangles (e.g. "
        "LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(LOCATION_INDEX_TRIANGLE_MACRO_"
        "NAME(...), LOCATION_INDEX_TRIANGLE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a triangle of location indices "
        "(e.g. "
        "LOCATION_INDEX_TRIANGLE_MACRO_NAME(LOCATION_INDEX_MACRO_NAME(123), "
        "LOCATION_INDEX_MACRO_NAME(123), LOCATION_INDEX_MACRO_NAME(123))).\n",
        "• The name of a macro which declares a location index (e.g. "
        "LOCATION_INDEX_MACRO_NAME(123)).\n",
        "• The name of a macro which declares a list of color index triangles "
        "(e.g. "
        "COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(COLOR_INDEX_TRIANGLE_MACRO_NAME(."
        "..), COLOR_INDEX_TRIANGLE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a triangle of color indices "
        "(e.g. COLOR_INDEX_TRIANGLE_MACRO_NAME(COLOR_INDEX_MACRO_NAME(123), "
        "COLOR_INDEX_MACRO_NAME(123), COLOR_INDEX_MACRO_NAME(123))).\n",
        "• The name of a macro which declares a color index (e.g. "
        "COLOR_INDEX_MACRO_NAME(123)).\n",
        "• The name of a macro which declares a list of VU index triangles "
        "(e.g. "
        "VU_INDEX_TRIANGLE_LIST_MACRO_NAME(VU_INDEX_TRIANGLE_MACRO_NAME(...), "
        "VU_INDEX_TRIANGLE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a triangle of VU indices (e.g. "
        "VU_INDEX_TRIANGLE_MACRO_NAME(VU_INDEX_MACRO_NAME(123), "
        "VU_INDEX_MACRO_NAME(123), VU_INDEX_MACRO_NAME(123))).\n",
        "• The name of a macro which declares a VU index (e.g. "
        "VU_INDEX_MACRO_NAME(123)).\n",
        "• The name of a macro which declares a list of face vertex counts "
        "(e.g. "
        "FACE_VERTEX_COUNT_LIST_MACRO_NAME(FACE_VERTEX_COUNT_MACRO_NAME(3), "
        "FACE_VERTEX_COUNT_MACRO_NAME(5), ...)).\n",
        "• The name of a macro which declares a face vertex count (e.g. "
        "FACE_VERTEX_COUNT_MACRO_NAME(3)).\n",
        "• The name of a macro which declares a list of face vertex offsets "
        "(e.g. "
        "FACE_VERTEX_OFFSET_LIST_MACRO_NAME(FACE_VERTEX_OFFSET_MACRO_NAME(3), "
        "FACE_VERTEX_OFFSET_MACRO_NAME(8), ...)).\n",
        "• The name of a macro which declares a face vertex offset (e.g. "
        "FACE_VERTEX_OFFSET_MACRO_NAME(3)).\n",
        "• The name of a macro which declares a list of faces, each of which "
        "contains a list of vertex locations (e.g. "
        "FACE_VERTEX_LOCATION_LIST_NAME(LOCATION_FACE_MACRO_NAME(...), "
        "LOCATION_FACE_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a list of vertex locations (e.g. "
        "LOCATION_FACE_MACRO_NAME(LOCATION_MACRO_NAME(1.23f, -3.25f, 94.24f), "
        "LOCATION_MACRO_NAME(1.23f, -3.25f, 94.24f), ...)).\n",
        "• The name of a macro which declares a list of normals (e.g. "
        "NORMAL_LIST_MACRO_NAME(NORMAL_MACRO_NAME(0.337f, -0.7538f, -0.5641f), "
        "NORMAL_MACRO_NAME(-0.6719f, 0.6248f, -0.3977f), ...)).\n",
        "• The name of a macro which declares a list of edge exit normals for "
        "each face (e.g. "
        "FACE_EDGE_EXIT_NORMAL_LIST_MACRO_NAME(NORMAL_LIST_MACRO_NAME(...), "
        "NORMAL_LIST_MACRO_NAME(...), ...).\n",
        "• The name of a macro which declares a list of edge normals for each "
        "face (e.g. "
        "FACE_EDGE_NORMAL_LIST_MACRO_NAME(NORMAL_LIST_MACRO_NAME(...), "
        "NORMAL_LIST_MACRO_NAME(...), ...).\n",
        "• The name of a macro which declares a list of vertex up normals for "
        "each face (e.g. "
        "FACE_VERTEX_UP_NORMAL_LIST_MACRO_NAME(NORMAL_LIST_MACRO_NAME(...), "
        "NORMAL_LIST_MACRO_NAME(...), ...).\n",
        "• The name of a macro which declares a normal (e.g. "
        "NORMAL_MACRO_NAME(0.337f, -0.7538f, -0.5641f)).\n",
        "• The name of a macro which declares a list of faces, each of which "
        "contains a list of how many neighbors each of its edges have (e.g. "
        "NEIGHBOR_COUNT_LIST_LIST_MACRO_NAME(NEIGHBOR_COUNT_LIST_MACRO_NAME(..."
        "), NEIGHBOR_COUNT_LIST_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a list of edge neighbor counts "
        "(e.g. NEIGHBOR_COUNT_LIST_MACRO_NAME(NEIGHBOR_COUNT_MACRO_NAME(2), "
        "NEIGHBOR_COUNT_MACRO_NAME(0), ...)).\n",
        "• The name of a macro which declares an edge neighbor count (e.g. "
        "NEIGHBOR_COUNT_MACRO_NAME(0)).\n",
        "• The name of a macro which declares a list of faces, each of which "
        "contains a list of edges, each of which contains a list of vertex "
        "offsets (e.g. FACE_EDGE_OFFSET_LIST_MACRO_NAME(OFFSET_MACRO_NAME(3), "
        "OFFSET_MACRO_NAME(8), ...).\n",
        "• The name of a macro which declares a list of faces, each of which "
        "contains a list of edges, each of which contains a list of neighbor "
        "vertex offsets (e.g. "
        "FACE_EDGE_NEIGHBOR_OFFSET_LIST_MACRO_NAME(OFFSET_LIST_LIST_MACRO_NAME("
        "...), OFFSET_LIST_LIST_MACRO_NAME(...), ...).\n",
        "• The name of a macro which declares a list of a list of offsets into "
        "an array (e.g. "
        "OFFSET_LIST_LIST_MACRO_NAME(OFFSET_LIST_MACRO_NAME(...), "
        "OFFSET_LIST_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a list of offsets into an array "
        "(e.g. OFFSET_LIST_MACRO_NAME(OFFSET_MACRO_NAME(3), "
        "OFFSET_MACRO_NAME(8), ...)).\n",
        "• The name of a macro which declares an offset into an array (e.g. "
        "OFFSET_MACRO_NAME(3)).\n",
        "• The name of a macro which declares a list of faces, each of which "
        "contains a list of edges, each of which contains a list of neighbors, "
        "each of which contains a face index (e.g. "
        "FACE_INDEX_LIST_LIST_LIST_MACRO_NAME(FACE_INDEX_LIST_LIST_MACRO_NAME(."
        "..), FACE_INDEX_LIST_LIST_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a list of edges, each of which "
        "contains a list of neighbors, each of which contains a face index "
        "(e.g. "
        "FACE_INDEX_LIST_LIST_MACRO_NAME(FACE_INDEX_LIST_MACRO_NAME(...), "
        "FACE_INDEX_LIST_MACRO_NAME(...), ...)).\n",
        "• The name of a macro which declares a list of faces, each of which "
        "contains a list of edges, each of which contains a list of neighbors, "
        "each of which contains a face index (e.g. "
        "FACE_EDGE_NEIGHBOR_FACE_INDEX_LIST_MACRO_NAME(FACE_INDEX_MACRO_NAME(3)"
        ", FACE_INDEX_MACRO_NAME(8), ...)).\n",
        "• The name of a macro which declares a face index (e.g. "
        "FACE_INDEX_MACRO_NAME(3)).\n",
        "• The name of a macro which declares a material name (e.g. "
        "MATERIAL_LIST_MACRO_NAME(MATERIAL_PREFIX_A, MATERIAL_PREFIX_B, "
        "...)).\n",
        "• The name of a macro which declares a material import (e.g. "
        "MATERIAL_IMPORT_MACRO_NAME(material_name)).\n",
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
  opaque_preparation_macro_name = argv[10];
  cutout_preparation_macro_name = argv[11];
  opaque_draw_call_macro_name = argv[12];
  cutout_draw_call_macro_name = argv[13];
  additive_blended_pass_data_macro_name = argv[14];
  additive_pass_data_macro_name = argv[15];
  additive_draw_call_data_macro_name = argv[16];
  blended_pass_data_macro_name = argv[17];
  blended_draw_call_data_macro_name = argv[18];
  additive_blended_pass_macro_name = argv[19];
  additive_preparation_macro_name = argv[20];
  blended_preparation_macro_name = argv[21];
  additive_draw_call_macro_name = argv[22];
  blended_draw_call_macro_name = argv[23];
  navigation_macro_name = argv[24];
  location_list_macro_name = argv[25];
  location_macro_name = argv[26];
  opacity_list_macro_name = argv[27];
  opacity_macro_name = argv[28];
  red_list_macro_name = argv[29];
  red_macro_name = argv[30];
  green_list_macro_name = argv[31];
  green_macro_name = argv[32];
  blue_list_macro_name = argv[33];
  blue_macro_name = argv[34];
  v_list_macro_name = argv[35];
  v_macro_name = argv[36];
  u_list_macro_name = argv[37];
  u_macro_name = argv[38];
  location_index_triangle_list_macro_name = argv[39];
  location_index_triangle_macro_name = argv[40];
  location_index_macro_name = argv[41];
  color_index_triangle_list_macro_name = argv[42];
  color_index_triangle_macro_name = argv[43];
  color_index_macro_name = argv[44];
  vu_index_triangle_list_macro_name = argv[45];
  vu_index_triangle_macro_name = argv[46];
  vu_index_macro_name = argv[47];
  face_vertex_count_list_macro_name = argv[48];
  face_vertex_count_macro_name = argv[49];
  face_vertex_offset_list_macro_name = argv[50];
  face_vertex_offset_macro_name = argv[51];
  face_vertex_location_list_name = argv[52];
  location_face_macro_name = argv[53];
  normal_list_macro_name = argv[54];
  face_edge_exit_normal_list_macro_name = argv[55];
  face_edge_normal_list_macro_name = argv[56];
  face_vertex_up_normal_list_macro_name = argv[57];
  normal_macro_name = argv[58];
  neighbor_count_list_list_macro_name = argv[59];
  neighbor_count_list_macro_name = argv[60];
  neighbor_count_macro_name = argv[61];
  face_edge_offset_list_macro_name = argv[62];
  face_edge_neighbor_offset_list_macro_name = argv[63];
  offset_list_list_macro_name = argv[64];
  offset_list_macro_name = argv[65];
  offset_macro_name = argv[66];
  face_index_list_list_list_macro_name = argv[67];
  face_index_list_list_macro_name = argv[68];
  face_edge_neighbor_face_index_list_macro_name = argv[69];
  face_index_macro_name = argv[70];
  material_list_macro_name = argv[71];
  material_import_macro_name = argv[72];
  include_paths = argv + 73;
  number_of_include_paths = argc - 73;

  reopen_as_read_only_binary_or_throw(stdin);
  reopen_as_write_only_binary_or_throw(stdout);

  for (size_t include_path = 0; include_path < number_of_include_paths;
       include_path++) {
    write_or_throw(stdout, "#include \"%s\"\n", include_paths[include_path]);
  }

  while (true) {
    const int character = fgetc(stdin);

    switch (character) {
    case EOF: {
      const int error = ferror(stdin);

      if (error != 0) {
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
