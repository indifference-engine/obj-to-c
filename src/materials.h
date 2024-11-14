#ifndef MATERIALS_H

#define MATERIALS_H

#include <stdlib.h>
#include <stdbool.h>

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
 * The types of the materials found.
 */
extern int *material_types;

/**
 * The names of the materials found.
 */
extern const char **material_names;

/**
 * Set when materials are imported.
 */
extern bool *material_imports;

/**
 * The lengths of the names of the materials found.
 */
extern size_t *material_name_lengths;

/**
 * The number of materials found.
 */
extern size_t number_of_materials;

#endif
