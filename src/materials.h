#ifndef MATERIALS_H

#define MATERIALS_H

#include <stdlib.h>

/**
 * The material entirely replaces the background when rendered.
 */
#define MATERIAL_TYPE_OPAQUE 0

/**
 * The material entirely replaces the background where opaque when rendered.
 */
#define MATERIAL_TYPE_CUTOUT 1

/**
 * The material is added to the background when rendered.
 */
#define MATERIAL_TYPE_ADDITIVE 2

/**
 * The material is blended with the background when rendered.
 */
#define MATERIAL_TYPE_BLENDED 3

/**
 * The material is a navigation mesh surface type and cannot be rendered.
 */
#define MATERIAL_TYPE_NAVIGATION 4

/**
 * The number of characters to skip in a name of a material of each material
 * type to skip the type prefix.
 */
extern const int material_type_name_offsets[5];

/**
 * The types of the materials found.
 */
extern int *material_types;

/**
 * The names of the materials found.
 */
extern const char **material_names;

/**
 * The lengths of the names of the materials found.
 */
extern size_t *material_name_lengths;

/**
 * The number of materials found.
 */
extern size_t number_of_materials;

#endif
