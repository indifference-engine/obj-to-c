#ifndef NORMAL_BETWEEN_H

#define NORMAL_BETWEEN_H

/**
 * Calculates the normal between two 3D vectors.
 * @param from The first 3D vector to measure.
 * @param to The second 3D vector to measure.
 * @param result Overwritten with the resulting 3D vector.  May be either or
 *               both of the input 3D vectors.
 */
void normal_between(const float from[3], const float to[3], float result[3]);

#endif
