#include <stdlib.h>
#include <math.h>
#include "validate_face.h"
#include "vertices.h"
#include "faces.h"
#include "indices.h"
#include "cross_product.h"
#include "dot_product.h"
#include "throw.h"
#include "normal_between.h"
#include "normalize.h"
#include "subtract.h"

void validate_face(void)
{
  const size_t face_vertex_count = face_lengths[number_of_faces - 1];

  if (face_vertex_count < 3)
  {
    throw("Face does not have at least three vertices.");
  }

  const size_t *const face_vertices = index_v + number_of_indices - face_vertex_count;

  for (size_t first_index = 0; first_index < face_vertex_count; first_index++)
  {
    const size_t first_vertex = face_vertices[first_index];
    const float first_x = vertex_x[first_vertex];
    const float first_y = vertex_y[first_vertex];
    const float first_z = vertex_z[first_vertex];

    for (size_t second_index = first_index + 1; second_index < face_vertex_count; second_index++)
    {
      const size_t second_vertex = face_vertices[second_index];

      if (first_x == vertex_x[second_vertex] && first_y == vertex_y[second_vertex] && first_z == vertex_z[second_vertex])
      {
        throw("Face is degenerate.");
      }
    }
  }

  const size_t first_vertex = face_vertices[0];
  float first_xyz[3] = {vertex_x[first_vertex], vertex_y[first_vertex], vertex_z[first_vertex]};

  const size_t second_vertex = face_vertices[1];
  float second_xyz[3] = {vertex_x[second_vertex], vertex_y[second_vertex], vertex_z[second_vertex]};

  const size_t third_vertex = face_vertices[2];
  float third_xyz[3] = {vertex_x[third_vertex], vertex_y[third_vertex], vertex_z[third_vertex]};

  float temp_a[3], temp_b[3];
  normal_between(first_xyz, second_xyz, temp_a);
  normal_between(first_xyz, third_xyz, temp_b);
  cross_product(temp_a, temp_b, temp_a);
  normalize(temp_a, temp_a);

  for (size_t index = 3; index < face_vertex_count; index++)
  {
    const size_t vertex = face_vertices[index];
    const float xyz[3] = {vertex_x[vertex], vertex_y[vertex], vertex_z[vertex]};
    subtract(xyz, first_xyz, temp_b);

    if (fabs(dot_product(temp_a, temp_b)) > 0.001f)
    {
      throw("Face is not planar.");
    }
  }

  for (size_t first_index = 0; first_index < face_vertex_count; first_index++)
  {
    const size_t first_vertex = face_vertices[first_index];
    float first_xyz[3] = {vertex_x[first_vertex], vertex_y[first_vertex], vertex_z[first_vertex]};
    const size_t second_vertex = face_vertices[(first_index + 1) % face_vertex_count];
    float second_xyz[3] = {vertex_x[second_vertex], vertex_y[second_vertex], vertex_z[second_vertex]};
    normal_between(first_xyz, second_xyz, temp_b);
    cross_product(temp_a, temp_b, temp_b);
    normalize(temp_b, temp_b);

    for (size_t second_index = first_index == face_vertex_count - 1 ? 1 : 0; second_index < first_index; second_index++)
    {
      const size_t third_vertex = face_vertices[second_index];
      float third_xyz[3] = {vertex_x[third_vertex], vertex_y[third_vertex], vertex_z[third_vertex]};
      float temp_c[3];
      subtract(third_xyz, first_xyz, temp_c);

      if (dot_product(temp_b, temp_c) <= 0.0f)
      {
        throw("Face is not convex.");
      }
    }

    for (size_t second_index = first_index + 2; second_index < face_vertex_count; second_index++)
    {
      const size_t third_vertex = face_vertices[second_index];
      float third_xyz[3] = {vertex_x[third_vertex], vertex_y[third_vertex], vertex_z[third_vertex]};
      float temp_c[3];
      subtract(third_xyz, first_xyz, temp_c);

      if (dot_product(temp_b, temp_c) <= 0.0f)
      {
        throw("Face is not convex.");
      }
    }
  }
}
