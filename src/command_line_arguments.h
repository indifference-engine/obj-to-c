#ifndef COMMAND_LINE_ARGUMENTS_H

#define COMMAND_LINE_ARGUMENTS_H

#include <stdlib.h>

/**
 * A prefix applied to any object names.
 */
extern const char *object_prefix;

/**
 * A prefix applied to any material names.
 */
extern const char *material_prefix;

/**
 * The name of a macro which declares data for an opaque/cutout pass (XYZ) (e.g.
 * MACRO(object_name, { 1.0f, 2.0f, 3.0f })).
 */
extern const char *opaque_cutout_pass_data_macro_name;

/**
 * The name of a macro which declares data for an opaque pass (R, G, B) (e.g.
 * MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f })).
 */
extern const char *opaque_pass_data_macro_name;

/**
 * The name of a macro which declares data for an opaque draw call (V, U, XYZ
 * indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name,
 * { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).
 */
extern const char *opaque_draw_call_data_macro_name;

/**
 * The name of a macro which declares data for an cutout pass (R, G, B, O) (e.g.
 * MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f }, { 1.0f })).
 */
extern const char *cutout_pass_data_macro_name;

/**
 * The name of a macro which declares data for a cutout draw call (V, U, XYZ
 * indices, RGBO indices, VU indices) (e.g. MACRO(object_name, material_name,
 * { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).
 */
extern const char *cutout_draw_call_data_macro_name;

/**
 * The name of a macro which declares an opaque/cutout pass
 * (e.g. MACRO(object_name, { draw calls })).
 */
extern const char *opaque_cutout_pass_macro_name;

/**
 * The name of a macro which declares an opaque draw call (e.g.
 * MACRO(object_name, material_name)).
 */
extern const char *opaque_draw_call_macro_name;

/**
 * The name of a macro which declares a cutout draw call (e.g.
 * MACRO(object_name, material_name)).
 */
extern const char *cutout_draw_call_macro_name;

/**
 * The name of a macro which declares data for an additive/blended pass (XYZ)
 * (e.g. MACRO(object_name, { 1.0f, 2.0f, 3.0f })).
 */
extern const char *additive_blended_pass_data_macro_name;

/**
 * The name of a macro which declares data for an additive pass (R, G, B) (e.g.
 * MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f })).
 */
extern const char *additive_pass_data_macro_name;

/**
 * The name of a macro which declares data for an additive draw call (V, U, XYZ
 * indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name,
 * { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).
 */
extern const char *additive_draw_call_data_macro_name;

/**
 * The name of a macro which declares data for an blended pass (R, G, B) (e.g.
 * MACRO(object_name, { 1.0f }, { 1.0f }, { 1.0f })).
 */
extern const char *blended_pass_data_macro_name;

/**
 * The name of a macro which declares data for an blended draw call (V, U, XYZ
 * indices, RGB indices, VU indices) (e.g. MACRO(object_name, material_name,
 * { 1.0f }, { 1.0f }, { 0, 1, 2 }, { 0, 1, 2 }, { 0, 1, 2 })).
 */
extern const char *blended_draw_call_data_macro_name;

/**
 * The name of a macro which declares an additive/blended pass (e.g. MACRO(
 * object_name, { (draw calls) })).
 */
extern const char *additive_blended_pass_macro_name;

/**
 * The name of a macro which declares an additive draw call (e.g. MACRO(
 * object_name, material_name)).
 */
extern const char *additive_draw_call_macro_name;

/**
 * The name of a macro which declares a blended draw call (e.g. MACRO(
 * object_name, material_name)).
 */
extern const char *blended_draw_call_macro_name;

/**
 * The include paths to emit.
 */
extern const char *const *include_paths;

/**
 * The number of include paths to emit.
 */
extern size_t number_of_include_paths;

#endif
