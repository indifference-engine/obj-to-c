#include "space.h"
#include "accumulate_float.h"
#include "accumulate_integer.h"
#include "command_line_arguments.h"
#include "current_material.h"
#include "determine_object_type.h"
#include "end_object.h"
#include "faces.h"
#include "imported_materials.h"
#include "indices.h"
#include "malloc_or_throw.h"
#include "materials.h"
#include "object_type.h"
#include "realloc_or_throw.h"
#include "register_material.h"
#include "state.h"
#include "texture_coordinates.h"
#include "throw.h"
#include "vertices.h"
#include "write_or_throw.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void space(void) {
  switch (state) {
  case STATE_MTLLIB:
    state = STATE_MTLLIB_SPACE;
    return;

  case STATE_MTLLIB_SPACE:
    return;

  case STATE_MTLLIB_NAME:
    state = STATE_MTLLIB_NAME_SPACE;
    return;

  case STATE_O:
    end_object();
    state = STATE_O_SPACE;
    return;

  case STATE_O_SPACE:
    return;

  case STATE_O_NAME:
    determine_object_type();
    state = STATE_O_NAME_SPACE;
    return;

  case STATE_O_NAME_SPACE:
    return;

  case STATE_USEMTL:
    state = STATE_USEMTL_SPACE;
    return;

  case STATE_USEMTL_SPACE:
    return;

  case STATE_USEMTL_NAME:
    register_material();
    state = STATE_USEMTL_NAME_SPACE;
    return;

  case STATE_USEMTL_NAME_SPACE:
    return;

  case STATE_V:
    state = STATE_V_SPACE;

    if (number_of_vertices) {
      vertex_x =
          realloc_or_throw(vertex_x, sizeof(float) * (number_of_vertices + 1));
      vertex_x[number_of_vertices] = 0.0f;
      vertex_y =
          realloc_or_throw(vertex_y, sizeof(float) * (number_of_vertices + 1));
      vertex_y[number_of_vertices] = 0.0f;
      vertex_z =
          realloc_or_throw(vertex_z, sizeof(float) * (number_of_vertices + 1));
      vertex_z[number_of_vertices] = 0.0f;
      vertex_red = realloc_or_throw(vertex_red,
                                    sizeof(float) * (number_of_vertices + 1));
      vertex_red[number_of_vertices] = 1.0f;
      vertex_green = realloc_or_throw(vertex_green,
                                      sizeof(float) * (number_of_vertices + 1));
      vertex_green[number_of_vertices] = 1.0f;
      vertex_blue = realloc_or_throw(vertex_blue,
                                     sizeof(float) * (number_of_vertices + 1));
      vertex_blue[number_of_vertices] = 1.0f;
      vertex_opacity = realloc_or_throw(
          vertex_opacity, sizeof(float) * (number_of_vertices + 1));
      vertex_opacity[number_of_vertices] = 1.0f;
      number_of_vertices++;
    } else {
      vertex_x = malloc_or_throw(sizeof(float));
      vertex_x[0] = 0.0f;
      vertex_y = malloc_or_throw(sizeof(float));
      vertex_y[0] = 0.0f;
      vertex_z = malloc_or_throw(sizeof(float));
      vertex_z[0] = 0.0f;
      vertex_red = malloc_or_throw(sizeof(float));
      vertex_red[0] = 1.0f;
      vertex_green = malloc_or_throw(sizeof(float));
      vertex_green[0] = 1.0f;
      vertex_blue = malloc_or_throw(sizeof(float));
      vertex_blue[0] = 1.0f;
      vertex_opacity = malloc_or_throw(sizeof(float));
      vertex_opacity[0] = 1.0f;
      number_of_vertices = 1;
    }

    return;

  case STATE_V_SPACE:
    return;

  case STATE_V_X:
    vertex_x[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_X_SPACE;
    return;

  case STATE_V_X_SPACE:
    return;

  case STATE_V_Y:
    vertex_y[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_Y_SPACE;
    return;

  case STATE_V_Y_SPACE:
    return;

  case STATE_V_Z:
    vertex_z[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_Z_SPACE;
    return;

  case STATE_V_Z_SPACE:
    return;

  case STATE_V_R:
    vertex_red[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_R_SPACE;
    return;

  case STATE_V_R_SPACE:
    return;

  case STATE_V_G:
    vertex_green[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_G_SPACE;
    return;

  case STATE_V_G_SPACE:
    return;

  case STATE_V_B:
    vertex_blue[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_B_SPACE;
    return;

  case STATE_V_B_SPACE:
    return;

  case STATE_V_O:
    vertex_blue[number_of_vertices - 1] = accumulate_float();
    state = STATE_V_O_SPACE;
    return;

  case STATE_V_O_SPACE:
    return;

  case STATE_VT:
    if (number_of_texture_coordinates) {
      texture_coordinate_u =
          realloc_or_throw(texture_coordinate_u,
                           sizeof(float) * (number_of_texture_coordinates + 1));
      texture_coordinate_u[number_of_texture_coordinates] = 0.0f;
      texture_coordinate_v =
          realloc_or_throw(texture_coordinate_v,
                           sizeof(float) * (number_of_texture_coordinates + 1));
      texture_coordinate_v[number_of_texture_coordinates] = 0.0f;
      number_of_texture_coordinates++;
    } else {
      texture_coordinate_u = malloc_or_throw(sizeof(float));
      texture_coordinate_u[0] = 0.0f;
      texture_coordinate_v = malloc_or_throw(sizeof(float));
      texture_coordinate_v[0] = 0.0f;
      number_of_texture_coordinates = 1;
    }

    state = STATE_VT_SPACE;
    return;

  case STATE_VT_U:
    texture_coordinate_u[number_of_texture_coordinates - 1] =
        accumulate_float();
    state = STATE_VT_U_SPACE;
    return;

  case STATE_VT_U_SPACE:
    return;

  case STATE_VT_V:
    texture_coordinate_v[number_of_texture_coordinates - 1] =
        accumulate_float();
    state = STATE_VT_V_SPACE;
    return;

  case STATE_VT_V_SPACE:
    return;

  case STATE_F:
    if (number_of_materials) {
      switch (object_type) {
      case OBJECT_TYPE_NONE:
        throw("No object for face.");

      case OBJECT_TYPE_GRAPHICAL:
        if (material_types[current_material] == MATERIAL_TYPE_NAVIGATION) {
          throw("Cannot apply navigation materials to non-navigation objects.");
        }

        const char *const skipped_material_name =
            material_names[current_material] +
            material_type_name_offsets[material_types[current_material]];
        const size_t skipped_material_name_length =
            material_name_lengths[current_material] -
            material_type_name_offsets[material_types[current_material]];

        bool imported = false;

        for (size_t index = 0; index < number_of_imported_materials; index++) {
          if (imported_material_name_lengths[index] ==
              skipped_material_name_length) {
            if (strcmp(skipped_material_name, imported_material_names[index]) ==
                0) {
              imported = true;
              break;
            }
          }
        }

        if (!imported) {
          write_or_throw(stdout, "%s(%s%s)\n", material_import_macro_name,
                         material_prefix, skipped_material_name);

          if (number_of_imported_materials) {
            imported_material_names = realloc_or_throw(
                imported_material_names,
                sizeof(const char *) * (number_of_imported_materials + 1));
            imported_material_names[number_of_imported_materials] =
                skipped_material_name;
            imported_material_name_lengths = realloc_or_throw(
                imported_material_name_lengths,
                sizeof(size_t) * (number_of_imported_materials + 1));
            imported_material_name_lengths[number_of_imported_materials] =
                skipped_material_name_length;
            number_of_imported_materials++;
          } else {
            imported_material_names = malloc_or_throw(sizeof(const char *));
            imported_material_names[0] = skipped_material_name;
            imported_material_name_lengths = malloc_or_throw(sizeof(size_t));
            imported_material_name_lengths[0] = skipped_material_name_length;
            number_of_imported_materials = 1;
          }
        }

        break;

      case OBJECT_TYPE_NAVIGATION:
        if (material_types[current_material] != MATERIAL_TYPE_NAVIGATION) {
          throw("Cannot apply navigation materials to non-navigation objects.");
        }
        break;
      }

      if (number_of_faces) {
        face_materials =
            realloc(face_materials, sizeof(size_t) * (number_of_faces + 1));
        face_materials[number_of_faces] = current_material;
        face_lengths =
            realloc(face_lengths, sizeof(size_t) * (number_of_faces + 1));
        face_lengths[number_of_faces] = 0;
        number_of_faces++;
      } else {
        face_materials = malloc(sizeof(size_t));
        face_materials[0] = current_material;
        face_lengths = malloc(sizeof(size_t));
        face_lengths[0] = 0;
        number_of_faces = 1;
      }

      state = STATE_F_SPACE;
      return;
    } else {
      throw("No material set for face.");
    }

  case STATE_F_SPACE:
    return;

  case STATE_F_V:
    if (object_type == OBJECT_TYPE_NAVIGATION) {
      int v = accumulate_integer();

      if (!v) {
        throw("Vertex indices cannot be zero.");
      } else if (v < 0) {
        v += number_of_vertices;

        if (v < 0) {
          throw("Face references nonexistent vertex.");
        }
      } else {
        v--;
      }

      if ((size_t)v >= number_of_vertices) {
        throw("Face references nonexistent vertex.");
      }

      index_v[number_of_indices - 1] = v;
      state = STATE_F_SPACE;
      return;
    }
    break;

  case STATE_F_VT: {
    int vt = accumulate_integer();

    if (!vt) {
      throw("Texture coordinate indices cannot be zero.");
    } else if (vt < 0) {
      vt += number_of_texture_coordinates;

      if (vt < 0) {
        throw("Face references nonexistent texture coordinate.");
      }
    } else {
      vt--;
    }

    if ((size_t)vt >= number_of_texture_coordinates) {
      throw("Face references nonexistent texture coordinate.");
    }

    if (object_type == OBJECT_TYPE_GRAPHICAL) {
      index_vt[number_of_indices - 1] = vt;
    }

    state = STATE_F_SPACE;
    return;
  }
  }

  throw("Unexpected space in state %d.", state);
}
