#ifndef CROSS_PRODUCT_H

#define CROSS_PRODUCT_H

/**
 * Calculates the cross product of two 3D vectors.
 * @param a The first 3D vector to multiply.
 * @param b The second 3D vector to multiply.
 * @param result Overwritten with the resulting 3D vector.  May be either or
 *               both of the input 3D vectors.
 */
void cross_product(const float a[3], const float b[3], float result[3]);

#endif
