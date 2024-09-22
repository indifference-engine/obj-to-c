#ifndef FACES_H

#define FACES_H

#include <stdlib.h>

/**
 * The material of each face.
 */
extern size_t *face_materials;

/**
 * The number of indices in each face.
 */
extern size_t *face_lengths;

/**
 * The number of faces in the current object.
 */
extern size_t number_of_faces;

#endif
