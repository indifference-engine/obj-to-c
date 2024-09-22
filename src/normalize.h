#ifndef NORMALIZE_H

#define NORMALIZE_H

/**
 * Normalizes a given 3D vector to unit length.
 * @param vector The 3D vector to normalize.
 * @param normal Overwritten with the resulting 3D vector.  May be the input 3D
 *               vector.
 */
void normalize(const float vector[3], float normal[3]);

#endif
