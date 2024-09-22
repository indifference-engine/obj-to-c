#include <stdio.h>
#include <limits.h>
#include "write_pass.h"
#include "faces.h"
#include "indices.h"
#include "materials.h"
#include "vertices.h"
#include "texture_coordinates.h"
#include "malloc_or_throw.h"
#include "realloc_or_throw.h"
#include "write_or_throw.h"
#include "command_line_arguments.h"
#include "object_name.h"
#include "material_name.h"

void write_pass(
    const char *const pass_macro_data_name,
    const int first_material_type,
    const char *const first_material_type_pass_data_macro_name,
    const char *const first_material_type_draw_call_data_macro_name,
    const int second_material_type,
    const char *const second_material_type_pass_data_macro_name,
    const char *const second_material_type_draw_call_data_macro_name,
    const char *const pass_macro_name,
    const char *const first_material_type_draw_call_macro_name,
    const char *const second_material_type_draw_call_macro_name)
{
  float *unique_x = NULL;
  float *unique_y = NULL;
  float *unique_z = NULL;
  size_t number_of_unique_xyz = 0;
  float *first_unique_r = NULL;
  float *first_unique_g = NULL;
  float *first_unique_b = NULL;
  size_t number_of_first_unique_rgb = 0;
  float *second_unique_r = NULL;
  float *second_unique_g = NULL;
  float *second_unique_b = NULL;
  float *second_unique_o = NULL;
  size_t number_of_second_unique_rgbo = 0;
  size_t *first_matched_materials = NULL;
  float **first_matched_material_unique_u = NULL;
  float **first_matched_material_unique_v = NULL;
  size_t *first_matched_material_number_of_unique_uv = NULL;
  size_t **first_matched_material_xyz_indices = NULL;
  size_t **first_matched_material_rgb_indices = NULL;
  size_t **first_matched_material_uv_indices = NULL;
  size_t *first_matched_material_number_of_indices = NULL;
  size_t number_of_first_matched_materials = 0;
  size_t *second_matched_materials = NULL;
  float **second_matched_material_unique_u = NULL;
  float **second_matched_material_unique_v = NULL;
  size_t *second_matched_material_number_of_unique_uv = NULL;
  size_t **second_matched_material_xyz_indices = NULL;
  size_t **second_matched_material_rgbo_indices = NULL;
  size_t **second_matched_material_uv_indices = NULL;
  size_t *second_matched_material_number_of_indices = NULL;
  size_t number_of_second_matched_materials = 0;

  for (size_t material = 0; material < number_of_materials; material++)
  {
    const int material_type = material_types[material];

    if (material_type == first_material_type)
    {
      size_t index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++)
      {
        const size_t face_length = face_lengths[face_index];

        if (face_materials[face_index] == material)
        {
          if (number_of_first_matched_materials)
          {
            if (first_matched_materials[number_of_first_matched_materials - 1] != material)
            {
              first_matched_materials = realloc_or_throw(first_matched_materials, sizeof(size_t) * (number_of_first_matched_materials + 1));
              first_matched_materials[number_of_first_matched_materials] = material;
              first_matched_material_unique_u = realloc_or_throw(first_matched_material_unique_u, sizeof(float *) * (number_of_first_matched_materials + 1));
              first_matched_material_unique_u[number_of_first_matched_materials] = NULL;
              first_matched_material_unique_v = realloc_or_throw(first_matched_material_unique_v, sizeof(float *) * (number_of_first_matched_materials + 1));
              first_matched_material_unique_v[number_of_first_matched_materials] = NULL;
              first_matched_material_number_of_unique_uv = realloc_or_throw(first_matched_material_number_of_unique_uv, sizeof(size_t) * (number_of_first_matched_materials + 1));
              first_matched_material_number_of_unique_uv[number_of_first_matched_materials] = 0;
              first_matched_material_xyz_indices = realloc_or_throw(first_matched_material_xyz_indices, sizeof(size_t *) * (number_of_first_matched_materials + 1));
              first_matched_material_xyz_indices[number_of_first_matched_materials] = NULL;
              first_matched_material_rgb_indices = realloc_or_throw(first_matched_material_rgb_indices, sizeof(size_t *) * (number_of_first_matched_materials + 1));
              first_matched_material_rgb_indices[number_of_first_matched_materials] = NULL;
              first_matched_material_uv_indices = realloc_or_throw(first_matched_material_uv_indices, sizeof(size_t *) * (number_of_first_matched_materials + 1));
              first_matched_material_uv_indices[number_of_first_matched_materials] = NULL;
              first_matched_material_number_of_indices = realloc_or_throw(first_matched_material_number_of_indices, sizeof(size_t) * (number_of_first_matched_materials + 1));
              first_matched_material_number_of_indices[number_of_first_matched_materials] = 0;
              number_of_first_matched_materials++;
            }
          }
          else
          {
            first_matched_materials = malloc_or_throw(sizeof(size_t));
            first_matched_materials[0] = material;
            first_matched_material_unique_u = malloc_or_throw(sizeof(float *));
            first_matched_material_unique_u[0] = NULL;
            first_matched_material_unique_v = malloc_or_throw(sizeof(float *));
            first_matched_material_unique_v[0] = NULL;
            first_matched_material_number_of_unique_uv = malloc_or_throw(sizeof(size_t));
            first_matched_material_number_of_unique_uv[0] = 0;
            first_matched_material_xyz_indices = malloc_or_throw(sizeof(size_t *) * (number_of_first_matched_materials + 1));
            first_matched_material_xyz_indices[number_of_first_matched_materials] = NULL;
            first_matched_material_rgb_indices = malloc_or_throw(sizeof(size_t *) * (number_of_first_matched_materials + 1));
            first_matched_material_rgb_indices[number_of_first_matched_materials] = NULL;
            first_matched_material_uv_indices = malloc_or_throw(sizeof(size_t *) * (number_of_first_matched_materials + 1));
            first_matched_material_uv_indices[number_of_first_matched_materials] = NULL;
            first_matched_material_number_of_indices = malloc_or_throw(sizeof(size_t) * (number_of_first_matched_materials + 1));
            first_matched_material_number_of_indices[number_of_first_matched_materials] = 0;
            number_of_first_matched_materials = 1;
          }

          size_t first_unique_xyz = SIZE_MAX;
          size_t first_unique_rgb = SIZE_MAX;
          size_t first_unique_uv = SIZE_MAX;
          size_t previous_unique_xyz = SIZE_MAX;
          size_t previous_unique_rgb = SIZE_MAX;
          size_t previous_unique_uv = SIZE_MAX;
          const size_t end = index + face_length;

          for (; index < end; index++)
          {
            const size_t vertex = index_v[index];
            const float x = vertex_x[vertex];
            const float y = vertex_y[vertex];
            const float z = vertex_z[vertex];

            size_t unique_xyz = 0;

            for (; unique_xyz < number_of_unique_xyz; unique_xyz++)
            {
              if (x == unique_x[unique_xyz] && y == unique_y[unique_xyz] && z == unique_z[unique_xyz])
              {
                break;
              }
            }

            if (unique_xyz == number_of_unique_xyz)
            {
              if (number_of_unique_xyz)
              {
                unique_x = realloc_or_throw(unique_x, sizeof(float) * (number_of_unique_xyz + 1));
                unique_x[number_of_unique_xyz] = x;
                unique_y = realloc_or_throw(unique_y, sizeof(float) * (number_of_unique_xyz + 1));
                unique_y[number_of_unique_xyz] = y;
                unique_z = realloc_or_throw(unique_z, sizeof(float) * (number_of_unique_xyz + 1));
                unique_z[number_of_unique_xyz] = z;
                number_of_unique_xyz++;
              }
              else
              {
                unique_x = malloc_or_throw(sizeof(float));
                unique_x[0] = x;
                unique_y = malloc_or_throw(sizeof(float));
                unique_y[0] = y;
                unique_z = malloc_or_throw(sizeof(float));
                unique_z[0] = z;
                number_of_unique_xyz = 1;
              }
            }

            const float r = vertex_red[vertex];
            const float g = vertex_green[vertex];
            const float b = vertex_blue[vertex];

            size_t unique_rgb = 0;

            for (; unique_rgb < number_of_first_unique_rgb; unique_rgb++)
            {
              if (r == first_unique_r[unique_rgb] && g == first_unique_g[unique_rgb] && b == first_unique_b[unique_rgb])
              {
                break;
              }
            }

            if (unique_rgb == number_of_first_unique_rgb)
            {
              if (number_of_first_unique_rgb)
              {
                first_unique_r = realloc_or_throw(first_unique_r, sizeof(float) * (number_of_first_unique_rgb + 1));
                first_unique_r[number_of_first_unique_rgb] = r;
                first_unique_g = realloc_or_throw(first_unique_g, sizeof(float) * (number_of_first_unique_rgb + 1));
                first_unique_g[number_of_first_unique_rgb] = g;
                first_unique_b = realloc_or_throw(first_unique_b, sizeof(float) * (number_of_first_unique_rgb + 1));
                first_unique_b[number_of_first_unique_rgb] = b;
                number_of_first_unique_rgb++;
              }
              else
              {
                first_unique_r = malloc_or_throw(sizeof(float));
                first_unique_r[0] = r;
                first_unique_g = malloc_or_throw(sizeof(float));
                first_unique_g[0] = g;
                first_unique_b = malloc_or_throw(sizeof(float));
                first_unique_b[0] = b;
                number_of_first_unique_rgb = 1;
              }
            }

            const size_t texture_coordinate = index_vt[index];
            const float u = texture_coordinate_u[texture_coordinate];
            const float v = texture_coordinate_v[texture_coordinate];

            size_t unique_uv = 0;
            const size_t number_of_unique_uv = first_matched_material_number_of_unique_uv[number_of_first_matched_materials - 1];

            for (; unique_uv < number_of_unique_uv; unique_uv++)
            {
              if (u == first_matched_material_unique_u[number_of_first_matched_materials - 1][unique_uv] && v == first_matched_material_unique_v[number_of_first_matched_materials - 1][unique_uv])
              {
                break;
              }
            }

            if (unique_uv == number_of_unique_uv)
            {
              if (number_of_unique_uv)
              {
                first_matched_material_unique_u[number_of_first_matched_materials - 1] = realloc_or_throw(first_matched_material_unique_u[number_of_first_matched_materials - 1], sizeof(float) * (number_of_unique_uv + 1));
                first_matched_material_unique_u[number_of_first_matched_materials - 1][number_of_unique_uv] = u;
                first_matched_material_unique_v[number_of_first_matched_materials - 1] = realloc_or_throw(first_matched_material_unique_v[number_of_first_matched_materials - 1], sizeof(float) * (number_of_unique_uv + 1));
                first_matched_material_unique_v[number_of_first_matched_materials - 1][number_of_unique_uv] = v;
                first_matched_material_number_of_unique_uv[number_of_first_matched_materials - 1] = number_of_unique_uv + 1;
              }
              else
              {
                first_matched_material_unique_u[number_of_first_matched_materials - 1] = malloc_or_throw(sizeof(float));
                first_matched_material_unique_u[number_of_first_matched_materials - 1][0] = u;
                first_matched_material_unique_v[number_of_first_matched_materials - 1] = malloc_or_throw(sizeof(float));
                first_matched_material_unique_v[number_of_first_matched_materials - 1][0] = v;
                first_matched_material_number_of_unique_uv[number_of_first_matched_materials - 1] = 1;
              }
            }

            if (first_unique_xyz == SIZE_MAX)
            {
              first_unique_xyz = unique_xyz;
              first_unique_rgb = unique_rgb;
              first_unique_uv = unique_uv;
            }
            else
            {
              if (previous_unique_xyz != SIZE_MAX)
              {
                const size_t number_of_indices = first_matched_material_number_of_indices[number_of_first_matched_materials - 1];

                if (number_of_indices)
                {
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1] = realloc_or_throw(first_matched_material_xyz_indices[number_of_first_matched_materials - 1], sizeof(size_t) * (number_of_indices + 3));
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1][number_of_indices] = first_unique_xyz;
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1][number_of_indices + 1] = previous_unique_xyz;
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1][number_of_indices + 2] = unique_xyz;
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1] = realloc_or_throw(first_matched_material_rgb_indices[number_of_first_matched_materials - 1], sizeof(size_t) * (number_of_indices + 3));
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1][number_of_indices] = first_unique_rgb;
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1][number_of_indices + 1] = previous_unique_rgb;
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1][number_of_indices + 2] = unique_rgb;
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1] = realloc_or_throw(first_matched_material_uv_indices[number_of_first_matched_materials - 1], sizeof(size_t) * (number_of_indices + 3));
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1][number_of_indices] = first_unique_uv;
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1][number_of_indices + 1] = previous_unique_uv;
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1][number_of_indices + 2] = unique_uv;
                  first_matched_material_number_of_indices[number_of_first_matched_materials - 1] = number_of_indices + 3;
                }
                else
                {
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1] = malloc_or_throw(sizeof(size_t) * 3);
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1][0] = first_unique_xyz;
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1][1] = previous_unique_xyz;
                  first_matched_material_xyz_indices[number_of_first_matched_materials - 1][2] = unique_xyz;
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1] = malloc_or_throw(sizeof(size_t) * 3);
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1][0] = first_unique_rgb;
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1][1] = previous_unique_rgb;
                  first_matched_material_rgb_indices[number_of_first_matched_materials - 1][2] = unique_rgb;
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1] = malloc_or_throw(sizeof(size_t) * 3);
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1][0] = first_unique_uv;
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1][1] = previous_unique_uv;
                  first_matched_material_uv_indices[number_of_first_matched_materials - 1][2] = unique_uv;
                  first_matched_material_number_of_indices[number_of_first_matched_materials - 1] = 3;
                }
              }

              previous_unique_xyz = unique_xyz;
              previous_unique_rgb = unique_rgb;
              previous_unique_uv = unique_uv;
            }
          }
        }
        else
        {
          index += face_length;
        }
      }
    }
    else if (material_type == second_material_type)
    {
      size_t index = 0;

      for (size_t face_index = 0; face_index < number_of_faces; face_index++)
      {
        const size_t face_length = face_lengths[face_index];

        if (face_materials[face_index] == material)
        {
          if (number_of_second_matched_materials)
          {
            if (second_matched_materials[number_of_second_matched_materials - 1] != material)
            {
              second_matched_materials = realloc_or_throw(second_matched_materials, sizeof(size_t) * (number_of_second_matched_materials + 1));
              second_matched_materials[number_of_second_matched_materials] = material;
              second_matched_material_unique_u = realloc_or_throw(second_matched_material_unique_u, sizeof(float *) * (number_of_second_matched_materials + 1));
              second_matched_material_unique_u[number_of_second_matched_materials] = NULL;
              second_matched_material_unique_v = realloc_or_throw(second_matched_material_unique_v, sizeof(float *) * (number_of_second_matched_materials + 1));
              second_matched_material_unique_v[number_of_second_matched_materials] = NULL;
              second_matched_material_number_of_unique_uv = realloc_or_throw(second_matched_material_number_of_unique_uv, sizeof(size_t) * (number_of_second_matched_materials + 1));
              second_matched_material_number_of_unique_uv[number_of_second_matched_materials] = 0;
              second_matched_material_xyz_indices = realloc_or_throw(second_matched_material_xyz_indices, sizeof(size_t *) * (number_of_second_matched_materials + 1));
              second_matched_material_xyz_indices[number_of_second_matched_materials] = NULL;
              second_matched_material_rgbo_indices = realloc_or_throw(second_matched_material_rgbo_indices, sizeof(size_t *) * (number_of_second_matched_materials + 1));
              second_matched_material_rgbo_indices[number_of_second_matched_materials] = NULL;
              second_matched_material_uv_indices = realloc_or_throw(second_matched_material_uv_indices, sizeof(size_t *) * (number_of_second_matched_materials + 1));
              second_matched_material_uv_indices[number_of_second_matched_materials] = NULL;
              second_matched_material_number_of_indices = realloc_or_throw(second_matched_material_number_of_indices, sizeof(size_t) * (number_of_second_matched_materials + 1));
              second_matched_material_number_of_indices[number_of_second_matched_materials] = 0;
              number_of_second_matched_materials++;
            }
          }
          else
          {
            second_matched_materials = malloc_or_throw(sizeof(size_t));
            second_matched_materials[0] = material;
            second_matched_material_unique_u = malloc_or_throw(sizeof(float *));
            second_matched_material_unique_u[0] = NULL;
            second_matched_material_unique_v = malloc_or_throw(sizeof(float *));
            second_matched_material_unique_v[0] = NULL;
            second_matched_material_number_of_unique_uv = malloc_or_throw(sizeof(size_t));
            second_matched_material_number_of_unique_uv[0] = 0;
            second_matched_material_xyz_indices = malloc_or_throw(sizeof(size_t *) * (number_of_second_matched_materials + 1));
            second_matched_material_xyz_indices[number_of_second_matched_materials] = NULL;
            second_matched_material_rgbo_indices = malloc_or_throw(sizeof(size_t *) * (number_of_second_matched_materials + 1));
            second_matched_material_rgbo_indices[number_of_second_matched_materials] = NULL;
            second_matched_material_uv_indices = malloc_or_throw(sizeof(size_t *) * (number_of_second_matched_materials + 1));
            second_matched_material_uv_indices[number_of_second_matched_materials] = NULL;
            second_matched_material_number_of_indices = malloc_or_throw(sizeof(size_t) * (number_of_second_matched_materials + 1));
            second_matched_material_number_of_indices[number_of_second_matched_materials] = 0;
            number_of_second_matched_materials = 1;
          }

          size_t first_unique_xyz = SIZE_MAX;
          size_t first_unique_rgbo = SIZE_MAX;
          size_t first_unique_uv = SIZE_MAX;
          size_t previous_unique_xyz = SIZE_MAX;
          size_t previous_unique_rgbo = SIZE_MAX;
          size_t previous_unique_uv = SIZE_MAX;
          const size_t end = index + face_length;

          for (; index < end; index++)
          {
            const size_t vertex = index_v[index];
            const float x = vertex_x[vertex];
            const float y = vertex_y[vertex];
            const float z = vertex_z[vertex];

            size_t unique_xyz = 0;

            for (; unique_xyz < number_of_unique_xyz; unique_xyz++)
            {
              if (x == unique_x[unique_xyz] && y == unique_y[unique_xyz] && z == unique_z[unique_xyz])
              {
                break;
              }
            }

            if (unique_xyz == number_of_unique_xyz)
            {
              if (number_of_unique_xyz)
              {
                unique_x = realloc_or_throw(unique_x, sizeof(float) * (number_of_unique_xyz + 1));
                unique_x[number_of_unique_xyz] = x;
                unique_y = realloc_or_throw(unique_y, sizeof(float) * (number_of_unique_xyz + 1));
                unique_y[number_of_unique_xyz] = y;
                unique_z = realloc_or_throw(unique_z, sizeof(float) * (number_of_unique_xyz + 1));
                unique_z[number_of_unique_xyz] = z;
                number_of_unique_xyz++;
              }
              else
              {
                unique_x = malloc_or_throw(sizeof(float));
                unique_x[0] = x;
                unique_y = malloc_or_throw(sizeof(float));
                unique_y[0] = y;
                unique_z = malloc_or_throw(sizeof(float));
                unique_z[0] = z;
                number_of_unique_xyz = 1;
              }
            }

            const float r = vertex_red[vertex];
            const float g = vertex_green[vertex];
            const float b = vertex_blue[vertex];
            const float o = vertex_opacity[vertex];

            size_t unique_rgbo = 0;

            for (; unique_rgbo < number_of_second_unique_rgbo; unique_rgbo++)
            {
              if (r == second_unique_r[unique_rgbo] && g == second_unique_g[unique_rgbo] && b == second_unique_b[unique_rgbo] && o == second_unique_o[unique_rgbo])
              {
                break;
              }
            }

            if (unique_rgbo == number_of_second_unique_rgbo)
            {
              if (number_of_second_unique_rgbo)
              {
                second_unique_r = realloc_or_throw(second_unique_r, sizeof(float) * (number_of_second_unique_rgbo + 1));
                second_unique_r[number_of_second_unique_rgbo] = r;
                second_unique_g = realloc_or_throw(second_unique_g, sizeof(float) * (number_of_second_unique_rgbo + 1));
                second_unique_g[number_of_second_unique_rgbo] = g;
                second_unique_b = realloc_or_throw(second_unique_b, sizeof(float) * (number_of_second_unique_rgbo + 1));
                second_unique_b[number_of_second_unique_rgbo] = b;
                second_unique_o = realloc_or_throw(second_unique_o, sizeof(float) * (number_of_second_unique_rgbo + 1));
                second_unique_o[number_of_second_unique_rgbo] = o;
                number_of_second_unique_rgbo++;
              }
              else
              {
                second_unique_r = malloc_or_throw(sizeof(float));
                second_unique_r[0] = r;
                second_unique_g = malloc_or_throw(sizeof(float));
                second_unique_g[0] = g;
                second_unique_b = malloc_or_throw(sizeof(float));
                second_unique_b[0] = b;
                second_unique_o = malloc_or_throw(sizeof(float));
                second_unique_o[0] = o;
                number_of_second_unique_rgbo = 1;
              }
            }

            const size_t texture_coordinate = index_vt[index];
            const float u = texture_coordinate_u[texture_coordinate];
            const float v = texture_coordinate_v[texture_coordinate];

            size_t unique_uv = 0;
            const size_t number_of_unique_uv = second_matched_material_number_of_unique_uv[number_of_second_matched_materials - 1];

            for (; unique_uv < number_of_unique_uv; unique_uv++)
            {
              if (u == second_matched_material_unique_u[number_of_second_matched_materials - 1][unique_uv] && v == second_matched_material_unique_v[number_of_second_matched_materials - 1][unique_uv])
              {
                break;
              }
            }

            if (unique_uv == number_of_unique_uv)
            {
              if (number_of_unique_uv)
              {
                second_matched_material_unique_u[number_of_second_matched_materials - 1] = realloc_or_throw(second_matched_material_unique_u[number_of_second_matched_materials - 1], sizeof(float) * (number_of_unique_uv + 1));
                second_matched_material_unique_u[number_of_second_matched_materials - 1][number_of_unique_uv] = u;
                second_matched_material_unique_v[number_of_second_matched_materials - 1] = realloc_or_throw(second_matched_material_unique_v[number_of_second_matched_materials - 1], sizeof(float) * (number_of_unique_uv + 1));
                second_matched_material_unique_v[number_of_second_matched_materials - 1][number_of_unique_uv] = v;
                second_matched_material_number_of_unique_uv[number_of_second_matched_materials - 1] = number_of_unique_uv + 1;
              }
              else
              {
                second_matched_material_unique_u[number_of_second_matched_materials - 1] = malloc_or_throw(sizeof(float));
                second_matched_material_unique_u[number_of_second_matched_materials - 1][0] = u;
                second_matched_material_unique_v[number_of_second_matched_materials - 1] = malloc_or_throw(sizeof(float));
                second_matched_material_unique_v[number_of_second_matched_materials - 1][0] = v;
                second_matched_material_number_of_unique_uv[number_of_second_matched_materials - 1] = 1;
              }
            }

            if (first_unique_xyz == SIZE_MAX)
            {
              first_unique_xyz = unique_xyz;
              first_unique_rgbo = unique_rgbo;
              first_unique_uv = unique_uv;
            }
            else
            {
              if (previous_unique_xyz != SIZE_MAX)
              {
                const size_t number_of_indices = second_matched_material_number_of_indices[number_of_second_matched_materials - 1];

                if (number_of_indices)
                {
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1] = realloc_or_throw(second_matched_material_xyz_indices[number_of_second_matched_materials - 1], sizeof(size_t) * (number_of_indices + 3));
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1][number_of_indices] = first_unique_xyz;
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1][number_of_indices + 1] = previous_unique_xyz;
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1][number_of_indices + 2] = unique_xyz;
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1] = realloc_or_throw(second_matched_material_rgbo_indices[number_of_second_matched_materials - 1], sizeof(size_t) * (number_of_indices + 3));
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1][number_of_indices] = first_unique_rgbo;
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1][number_of_indices + 1] = previous_unique_rgbo;
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1][number_of_indices + 2] = unique_rgbo;
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1] = realloc_or_throw(second_matched_material_uv_indices[number_of_second_matched_materials - 1], sizeof(size_t) * (number_of_indices + 3));
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1][number_of_indices] = first_unique_uv;
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1][number_of_indices + 1] = previous_unique_uv;
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1][number_of_indices + 2] = unique_uv;
                  second_matched_material_number_of_indices[number_of_second_matched_materials - 1] = number_of_indices + 3;
                }
                else
                {
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1] = malloc_or_throw(sizeof(size_t) * 3);
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1][0] = first_unique_xyz;
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1][1] = previous_unique_xyz;
                  second_matched_material_xyz_indices[number_of_second_matched_materials - 1][2] = unique_xyz;
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1] = malloc_or_throw(sizeof(size_t) * 3);
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1][0] = first_unique_rgbo;
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1][1] = previous_unique_rgbo;
                  second_matched_material_rgbo_indices[number_of_second_matched_materials - 1][2] = unique_rgbo;
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1] = malloc_or_throw(sizeof(size_t) * 3);
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1][0] = first_unique_uv;
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1][1] = previous_unique_uv;
                  second_matched_material_uv_indices[number_of_second_matched_materials - 1][2] = unique_uv;
                  second_matched_material_number_of_indices[number_of_second_matched_materials - 1] = 3;
                }
              }

              previous_unique_xyz = unique_xyz;
              previous_unique_rgbo = unique_rgbo;
              previous_unique_uv = unique_uv;
            }
          }
        }
        else
        {
          index += face_length;
        }
      }
    }
  }

  if (number_of_unique_xyz)
  {
    write_or_throw(stdout, "%s({ ", pass_macro_data_name);

    for (size_t unique_xyz = 0; unique_xyz < number_of_unique_xyz; unique_xyz++)
    {
      if (unique_xyz)
      {
        write_or_throw(stdout, ", ");
      }

      write_or_throw(stdout, "%ff, %ff, %ff", unique_x[unique_xyz], unique_y[unique_xyz], unique_z[unique_xyz]);
    }

    write_or_throw(stdout, " })\n", pass_macro_data_name);

    if (number_of_first_matched_materials)
    {
      write_or_throw(stdout, "%s\n(\n  %s%s,\n  { ", first_material_type_pass_data_macro_name, object_prefix, object_name);

      for (size_t unique_r = 0; unique_r < number_of_first_unique_rgb; unique_r++)
      {
        if (unique_r)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", first_unique_r[unique_r]);
      }

      write_or_throw(stdout, " },\n  { ");

      for (size_t unique_g = 0; unique_g < number_of_first_unique_rgb; unique_g++)
      {
        if (unique_g)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", first_unique_g[unique_g]);
      }

      write_or_throw(stdout, " },\n  { ");

      for (size_t unique_b = 0; unique_b < number_of_first_unique_rgb; unique_b++)
      {
        if (unique_b)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", first_unique_b[unique_b]);
      }

      write_or_throw(stdout, " }\n)\n");

      for (size_t material = 0; material < number_of_first_matched_materials; material++)
      {
        write_or_throw(stdout, "%s\n(\n  %s%s,\n  %s%s,\n  { ", first_material_type_draw_call_data_macro_name, object_prefix, object_name, material_prefix, material_names[first_matched_materials[material]]);

        for (size_t unique_v = 0; unique_v < first_matched_material_number_of_unique_uv[material]; unique_v++)
        {
          if (unique_v)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%ff", first_matched_material_unique_v[material][unique_v]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_u = 0; unique_u < first_matched_material_number_of_unique_uv[material]; unique_u++)
        {
          if (unique_u)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%ff", first_matched_material_unique_u[material][unique_u]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_xyz = 0; unique_xyz < first_matched_material_number_of_indices[material]; unique_xyz++)
        {
          if (unique_xyz)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%u", first_matched_material_xyz_indices[material][unique_xyz]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_rgb = 0; unique_rgb < first_matched_material_number_of_indices[material]; unique_rgb++)
        {
          if (unique_rgb)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%u", first_matched_material_rgb_indices[material][unique_rgb]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_uv = 0; unique_uv < first_matched_material_number_of_indices[material]; unique_uv++)
        {
          if (unique_uv)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%u", first_matched_material_uv_indices[material][unique_uv]);
        }

        write_or_throw(stdout, " }\n)\n");
      }
    }

    if (number_of_second_matched_materials)
    {
      write_or_throw(stdout, "%s\n(\n  %s%s,\n  { ", second_material_type_pass_data_macro_name, object_prefix, object_name);

      for (size_t unique_r = 0; unique_r < number_of_second_unique_rgbo; unique_r++)
      {
        if (unique_r)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", second_unique_r[unique_r]);
      }

      write_or_throw(stdout, " },\n  { ");

      for (size_t unique_g = 0; unique_g < number_of_second_unique_rgbo; unique_g++)
      {
        if (unique_g)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", second_unique_g[unique_g]);
      }

      write_or_throw(stdout, " },\n  { ");

      for (size_t unique_b = 0; unique_b < number_of_second_unique_rgbo; unique_b++)
      {
        if (unique_b)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", second_unique_b[unique_b]);
      }

      write_or_throw(stdout, " },\n  { ");

      for (size_t unique_o = 0; unique_o < number_of_second_unique_rgbo; unique_o++)
      {
        if (unique_o)
        {
          write_or_throw(stdout, ", ");
        }

        write_or_throw(stdout, "%ff", second_unique_o[unique_o]);
      }

      write_or_throw(stdout, " }\n)\n");

      for (size_t material = 0; material < number_of_second_matched_materials; material++)
      {
        write_or_throw(stdout, "%s\n(\n  %s%s,\n  %s%s,\n  { ", second_material_type_draw_call_data_macro_name, object_prefix, object_name, material_prefix, material_names[second_matched_materials[material]]);

        for (size_t unique_v = 0; unique_v < second_matched_material_number_of_unique_uv[material]; unique_v++)
        {
          if (unique_v)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%ff", second_matched_material_unique_v[material][unique_v]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_u = 0; unique_u < second_matched_material_number_of_unique_uv[material]; unique_u++)
        {
          if (unique_u)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%ff", second_matched_material_unique_u[material][unique_u]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_xyz = 0; unique_xyz < second_matched_material_number_of_indices[material]; unique_xyz++)
        {
          if (unique_xyz)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%u", second_matched_material_xyz_indices[material][unique_xyz]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_rgbo = 0; unique_rgbo < second_matched_material_number_of_indices[material]; unique_rgbo++)
        {
          if (unique_rgbo)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%u", second_matched_material_rgbo_indices[material][unique_rgbo]);
        }

        write_or_throw(stdout, " },\n  { ");

        for (size_t unique_uv = 0; unique_uv < second_matched_material_number_of_indices[material]; unique_uv++)
        {
          if (unique_uv)
          {
            write_or_throw(stdout, ", ");
          }

          write_or_throw(stdout, "%u", second_matched_material_uv_indices[material][unique_uv]);
        }

        write_or_throw(stdout, " }\n)\n");
      }
    }

    write_or_throw(stdout, "%s\n(\n  %s%s,\n  {\n", pass_macro_name, object_prefix, object_name);

    for (size_t material = 0; material < number_of_first_matched_materials; material++)
    {
      write_or_throw(stdout, "    %s(%s%s, %s%s)\n", first_material_type_draw_call_macro_name, object_prefix, object_name, material_prefix, material_names[first_matched_materials[material]]);
    }

    for (size_t material = 0; material < number_of_second_matched_materials; material++)
    {
      write_or_throw(stdout, "    %s(%s%s, %s%s)\n", second_material_type_draw_call_macro_name, object_prefix, object_name, material_prefix, material_names[second_matched_materials[material]]);
    }

    write_or_throw(stdout, "  }\n)\n");

    free(unique_x);
    free(unique_y);
    free(unique_z);

    if (number_of_first_matched_materials)
    {
      free(first_unique_r);
      free(first_unique_g);
      free(first_unique_b);
      free(first_matched_materials);

      for (size_t matched_material = 0; matched_material < number_of_first_matched_materials; matched_material++)
      {
        free(first_matched_material_unique_u[matched_material]);
        free(first_matched_material_unique_v[matched_material]);
        free(first_matched_material_xyz_indices[matched_material]);
        free(first_matched_material_rgb_indices[matched_material]);
        free(first_matched_material_uv_indices[matched_material]);
      }

      free(first_matched_material_unique_u);
      free(first_matched_material_unique_v);
      free(first_matched_material_number_of_unique_uv);
      free(first_matched_material_xyz_indices);
      free(first_matched_material_rgb_indices);
      free(first_matched_material_uv_indices);
      free(first_matched_material_number_of_indices);
    }

    if (number_of_second_matched_materials)
    {
      free(second_unique_r);
      free(second_unique_g);
      free(second_unique_b);
      free(second_unique_o);
      free(second_matched_materials);

      for (size_t matched_material = 0; matched_material < number_of_second_matched_materials; matched_material++)
      {
        free(second_matched_material_unique_u[matched_material]);
        free(second_matched_material_unique_v[matched_material]);
        free(second_matched_material_xyz_indices[matched_material]);
        free(second_matched_material_rgbo_indices[matched_material]);
        free(second_matched_material_uv_indices[matched_material]);
      }

      free(second_matched_material_unique_u);
      free(second_matched_material_unique_v);
      free(second_matched_material_number_of_unique_uv);
      free(second_matched_material_xyz_indices);
      free(second_matched_material_rgbo_indices);
      free(second_matched_material_uv_indices);
      free(second_matched_material_number_of_indices);
    }
  }
}
