#ifndef SUBTRACT_H

#define SUBTRACT_H

/**
 * Calculates the difference between two 3D vectors.
 * @param minuend The 3D vector to subtract from.
 * @param subtrahend The 3D vector to subtract by.
 * @param difference Overwritten with the resulting 3D vector.  May be either or
 *                   both of the input 3D vectors.
 */
void subtract(const float minuend[3], const float subtrahend[3], float difference[3]);

#endif
