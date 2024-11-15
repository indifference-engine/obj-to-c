#ifndef VERTICES_H

#define VERTICES_H

#include <stdlib.h>

/**
 * The location of each vertex on the X axis.
 */
extern float *vertex_x;

/**
 * The location of each vertex on the Y axis.
 */
extern float *vertex_y;

/**
 * The location of each vertex on the Z axis.
 */
extern float *vertex_z;

/**
 * The opacity of each vertex.
 */
extern float *vertex_opacity;

/**
 * The intensity of each vertex in the red channel.
 */
extern float *vertex_red;

/**
 * The intensity of each vertex in the green channel.
 */
extern float *vertex_green;

/**
 * The intensity of each vertex in the blue channel.
 */
extern float *vertex_blue;

/**
 * The number of vertices.
 */
extern size_t number_of_vertices;

#endif
