#include "end_object.h"
#include "command_line_arguments.h"
#include "cross_product.h"
#include "faces.h"
#include "indices.h"
#include "magnitude.h"
#include "malloc_or_throw.h"
#include "materials.h"
#include "normal_between.h"
#include "normalize.h"
#include "object_name.h"
#include "object_type.h"
#include "realloc_or_throw.h"
#include "subtract.h"
#include "throw.h"
#include "vertices.h"
#include "write_or_throw.h"
#include "write_pass.h"
#include <stdio.h>
#include <stdlib.h>

void end_object(void) {
  switch (object_type) {
  case OBJECT_TYPE_NONE:
    break;

  case OBJECT_TYPE_GRAPHICAL:
    write_pass(opaque_cutout_pass_data_macro_name, MATERIAL_TYPE_OPAQUE,
               opaque_pass_data_macro_name, opaque_draw_call_data_macro_name,
               MATERIAL_TYPE_CUTOUT, cutout_pass_data_macro_name,
               cutout_draw_call_data_macro_name, opaque_cutout_pass_macro_name,
               opaque_preparation_macro_name, cutout_preparation_macro_name,
               opaque_draw_call_macro_name, cutout_draw_call_macro_name);

    write_pass(additive_blended_pass_data_macro_name, MATERIAL_TYPE_ADDITIVE,
               additive_pass_data_macro_name,
               additive_draw_call_data_macro_name, MATERIAL_TYPE_BLENDED,
               blended_pass_data_macro_name, blended_draw_call_data_macro_name,
               additive_blended_pass_macro_name,
               additive_preparation_macro_name, blended_preparation_macro_name,
               additive_draw_call_macro_name, blended_draw_call_macro_name);

    if (number_of_indices) {
      free(index_v);
      index_v = NULL;
      free(index_vt);
      index_vt = NULL;
      number_of_indices = 0;
    }

    if (number_of_faces) {
      free(face_lengths);
      face_lengths = NULL;
      free(face_materials);
      face_materials = NULL;
      number_of_faces = 0;
    }

    free(object_name);
    object_name = NULL;
    object_name_length = 0;
    break;

  case OBJECT_TYPE_NAVIGATION:
    if (number_of_faces) {
      float *const normals =
          malloc_or_throw(sizeof(float) * number_of_faces * 3);
      size_t *neighboring_face_indices = NULL;
      size_t total_neighbors = 0;
      size_t *const numbers_of_neighboring_edges =
          malloc_or_throw(sizeof(size_t) * number_of_indices);
      float *const edge_exit_normals =
          malloc_or_throw(sizeof(float) * number_of_indices * 3);
      float *const edge_normals =
          malloc_or_throw(sizeof(float) * number_of_indices * 3);
      float *const edge_coefficients =
          malloc_or_throw(sizeof(float) * number_of_indices * 3);
      float *const vertex_up_normals =
          malloc_or_throw(sizeof(float) * number_of_indices * 3);

      size_t first_index = 0;

      for (size_t first_face_index = 0; first_face_index < number_of_faces;
           first_face_index++) {
        const size_t first_face_length = face_lengths[first_face_index];

        const size_t index_v_a = index_v[first_index];
        const float xyz_a[] = {vertex_x[index_v_a], vertex_y[index_v_a],
                               vertex_z[index_v_a]};

        const size_t index_v_b = index_v[first_index + 1];
        const float xyz_b[] = {vertex_x[index_v_b], vertex_y[index_v_b],
                               vertex_z[index_v_b]};

        const size_t index_v_c = index_v[first_index + 2];
        const float xyz_c[] = {vertex_x[index_v_c], vertex_y[index_v_c],
                               vertex_z[index_v_c]};

        float xyz_ab[3];
        float xyz_ac[3];

        normal_between(xyz_a, xyz_b, xyz_ab);
        normal_between(xyz_a, xyz_c, xyz_ac);

        cross_product(xyz_ab, xyz_ac, normals + first_face_index * 3);
        normalize(normals + first_face_index * 3,
                  normals + first_face_index * 3);

        first_index += first_face_length;
      }

      first_index = 0;

      for (size_t first_face_index = 0; first_face_index < number_of_faces;
           first_face_index++) {
        const size_t first_face_length = face_lengths[first_face_index];

        size_t first_previous_index = index_v[first_index];

        for (size_t first_edge_index = 0; first_edge_index < first_face_length;
             first_edge_index++) {
          numbers_of_neighboring_edges[first_index + first_edge_index] = 0;

          const size_t first_next_index =
              index_v[first_index +
                      ((first_edge_index + 1) % first_face_length)];

          float accumulated_normal[] = {normals[first_face_index * 3],
                                        normals[first_face_index * 3 + 1],
                                        normals[first_face_index * 3 + 2]};

          size_t second_index = 0;

          for (size_t second_face_index = 0;
               second_face_index < number_of_faces; second_face_index++) {
            const size_t second_face_length = face_lengths[second_face_index];

            if (first_face_index != second_face_index) {
              size_t second_previous_index =
                  index_v[second_index + second_face_length - 1];

              for (size_t second_edge_index = 0;
                   second_edge_index < second_face_length;
                   second_edge_index++) {
                const size_t second_next_index =
                    index_v[second_index + second_edge_index];

                if ((first_previous_index == second_previous_index &&
                     first_next_index == second_next_index) ||
                    (first_previous_index == second_next_index &&
                     first_next_index == second_previous_index)) {
                  if (total_neighbors) {
                    neighboring_face_indices = realloc_or_throw(
                        neighboring_face_indices,
                        sizeof(size_t) * (total_neighbors + 1));
                    neighboring_face_indices[total_neighbors] =
                        second_face_index;
                    total_neighbors++;
                  } else {
                    neighboring_face_indices = malloc_or_throw(sizeof(size_t));
                    neighboring_face_indices[0] = second_face_index;
                    total_neighbors = 1;
                  }

                  accumulated_normal[0] += normals[second_face_index * 3];
                  accumulated_normal[1] += normals[second_face_index * 3 + 1];
                  accumulated_normal[2] += normals[second_face_index * 3 + 2];

                  numbers_of_neighboring_edges[first_index +
                                               first_edge_index]++;
                }

                second_previous_index = second_next_index;
              }
            }

            second_index += second_face_length;
          }

          normalize(accumulated_normal, accumulated_normal);

          const float previous_xyz[] = {vertex_x[first_previous_index],
                                        vertex_y[first_previous_index],
                                        vertex_z[first_previous_index]};
          const float next_xyz[] = {vertex_x[first_next_index],
                                    vertex_y[first_next_index],
                                    vertex_z[first_next_index]};

          float edge_delta[3];
          subtract(next_xyz, previous_xyz, edge_delta);

          const float edge_length = magnitude(edge_delta);

          if (edge_length < 0.001f) {
            throw(
                "Failed to normalize a vector as its magnitude is too small.");
          }

          const float edge_length_reciprocal = 1.0f / edge_length;

          float edge_normal[3] = {
              edge_delta[0] * edge_length_reciprocal,
              edge_delta[1] * edge_length_reciprocal,
              edge_delta[2] * edge_length_reciprocal,
          };

          cross_product(edge_normal, accumulated_normal,
                        edge_exit_normals +
                            (first_index + first_edge_index) * 3);
          normalize(edge_exit_normals + (first_index + first_edge_index) * 3,
                    edge_exit_normals + (first_index + first_edge_index) * 3);

          cross_product(edge_normal, normals + first_face_index * 3,
                        edge_normals + (first_index + first_edge_index) * 3);
          normalize(edge_normals + (first_index + first_edge_index) * 3,
                    edge_normals + (first_index + first_edge_index) * 3);

          edge_coefficients[(first_index + first_edge_index) * 3] =
              edge_normal[0] * edge_length_reciprocal;

          edge_coefficients[(first_index + first_edge_index) * 3 + 1] =
              edge_normal[1] * edge_length_reciprocal;

          edge_coefficients[(first_index + first_edge_index) * 3 + 2] =
              edge_normal[2] * edge_length_reciprocal;

          first_previous_index = first_next_index;
        }

        for (size_t first_edge_index = 0; first_edge_index < first_face_length;
             first_edge_index++) {

          const int next_offset =
              3 * (first_index + ((first_edge_index + 1) % first_face_length));

          cross_product(
              edge_exit_normals + 3 * (first_index + first_edge_index),
              edge_exit_normals + next_offset, vertex_up_normals + next_offset);
          normalize(vertex_up_normals + next_offset,
                    vertex_up_normals + next_offset);
        }

        first_index += first_face_length;
      }

      write_or_throw(stdout, "%s(\n  %s%s,\n  %s(", navigation_macro_name,
                     object_prefix, object_name, material_list_macro_name);

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s", navigation_material_prefix);

        const size_t material_index = face_materials[face_index];
        const char *const material_name = material_names[material_index];
        const size_t material_name_length =
            material_name_lengths[material_index];

        for (size_t character_index = 11;
             character_index < material_name_length; character_index++) {
          char character = material_name[character_index];

          if (character >= 'a' && character <= 'z') {
            character += 'A' - 'a';
          }

          write_or_throw(stdout, "%c", character);
        }
      }

      write_or_throw(stdout, "),\n  %s(", face_vertex_count_list_macro_name);

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(%u)", face_vertex_count_macro_name,
                       face_lengths[face_index]);
      }

      write_or_throw(stdout, "),\n  %s(", face_vertex_offset_list_macro_name);

      size_t index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(%u)", face_vertex_offset_macro_name, index);

        index += face_lengths[face_index];
      }

      write_or_throw(stdout, "),\n  %s(", face_vertex_location_list_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", location_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t vertex_index = 0; vertex_index < face_length;
             vertex_index++) {
          if (vertex_index) {
            write_or_throw(stdout, ", ");
          }

          const size_t xyz_index = index_v[index];

          write_or_throw(stdout, "%s(%f, %f, %f)", location_macro_name,
                         vertex_x[xyz_index], vertex_y[xyz_index],
                         vertex_z[xyz_index]);

          index++;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(", normal_list_macro_name);

      for (size_t axis = 0; axis < number_of_faces * 3; axis += 3) {
        if (axis) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(%f, %f, %f)", normal_macro_name,
                       normals[axis], normals[axis + 1], normals[axis + 2]);
      }

      write_or_throw(stdout, "),\n  %s(",
                     face_edge_exit_normal_list_macro_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", normal_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t edge_index = 0; edge_index < face_length; edge_index++) {
          if (edge_index) {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%s(%f, %f, %f)", normal_macro_name,
                         edge_exit_normals[index], edge_exit_normals[index + 1],
                         edge_exit_normals[index + 2]);

          index += 3;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(", face_edge_normal_list_macro_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", normal_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t edge_index = 0; edge_index < face_length; edge_index++) {
          if (edge_index) {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%s(%f, %f, %f)", normal_macro_name,
                         edge_normals[index], edge_normals[index + 1],
                         edge_normals[index + 2]);

          index += 3;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(",
                     face_edge_coefficient_list_macro_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", coefficient_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t edge_index = 0; edge_index < face_length; edge_index++) {
          if (edge_index) {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%s(%f, %f, %f)", coefficient_list_macro_name,
                         edge_coefficients[index], edge_coefficients[index + 1],
                         edge_coefficients[index + 2]);

          index += 3;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(",
                     face_vertex_up_normal_list_macro_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", normal_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t vertex_index = 0; vertex_index < face_length;
             vertex_index++) {
          if (vertex_index) {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%s(%f, %f, %f)", normal_macro_name,
                         vertex_up_normals[index], vertex_up_normals[index + 1],
                         vertex_up_normals[index + 2]);

          index += 3;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(", neighbor_count_list_list_macro_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", neighbor_count_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t edge_index = 0; edge_index < face_length; edge_index++) {
          if (edge_index) {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%s(%u)", neighbor_count_macro_name,
                         numbers_of_neighboring_edges[index]);

          index++;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(", face_edge_offset_list_macro_name);

      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(%u)", offset_macro_name, index);

        index += face_lengths[face_index];
      }

      write_or_throw(stdout, "),\n  %s(",
                     face_edge_neighbor_offset_list_macro_name);

      size_t total_edges = 0;
      index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        if (face_index) {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%s(", offset_list_macro_name);

        const size_t face_length = face_lengths[face_index];

        for (size_t edge_index = 0; edge_index < face_length; edge_index++) {
          if (edge_index) {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%s(%u)", offset_macro_name, index);

          index += numbers_of_neighboring_edges[total_edges];
          total_edges++;
        }

        write_or_throw(stdout, ")");
      }

      write_or_throw(stdout, "),\n  %s(",
                     face_edge_neighbor_face_index_list_macro_name);

      index = 0;
      total_edges = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++) {
        const size_t face_length = face_lengths[face_index];

        for (size_t edge_index = 0; edge_index < face_length; edge_index++) {
          const size_t edge_length = numbers_of_neighboring_edges[total_edges];

          for (size_t neighbor_index = 0; neighbor_index < edge_length;
               neighbor_index++) {
            if (index) {
              write_or_throw(stdout, ", ");
            }

            write_or_throw(stdout, "%s(%u)", face_index_macro_name,
                           neighboring_face_indices[index]);
            index++;
          }

          total_edges++;
        }
      }

      write_or_throw(stdout, ")\n)\n");

      if (neighboring_face_indices) {
        free(neighboring_face_indices);
      }

      free(vertex_up_normals);
      free(edge_exit_normals);
      free(edge_normals);
      free(edge_coefficients);
      free(numbers_of_neighboring_edges);

      free(normals);
    }

    if (number_of_indices) {
      free(index_v);
      index_v = NULL;
      number_of_indices = 0;
    }

    if (number_of_faces) {
      free(face_lengths);
      face_lengths = NULL;
      free(face_materials);
      face_materials = NULL;
      number_of_faces = 0;
    }

    free(object_name);
    object_name = NULL;
    object_name_length = 0;
    break;
  }
}
