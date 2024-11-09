#ifndef COMMAND_LINE_ARGUMENTS_H

#define COMMAND_LINE_ARGUMENTS_H

#include <stdlib.h>

/**
 * A prefix applied to any object names.
 */
extern const char *object_prefix;

/**
 * A prefix applied to any non-navigation material names.
 */
extern const char *material_prefix;

/**
 * A prefix applied to any navigation material names.
 */
extern const char *navigation_material_prefix;

/**
 * The name of a macro which declares data for an opaque/cutout pass (e.g.
 * OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME(object_name,
 * LOCATION_LIST_MACRO_NAME(...))).
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
 * (e.g. ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME(object_name,
 * LOCATION_LIST_MACRO_NAME(...))).
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
 * The name of a macro which declares a navigation mesh (a material type per
 * face, a vertex count per face, an index offset per face, a location per
 * vertex per face, a surface normal per face, an exit normal per edge per face,
 * an up normal per vertex per face, a number of neighbors per edge per face, an
 * edge index offset per face, a neighbor index offset per edge per face,
 * a face index per neighbor per edge per face) (e.g. MACRO(object_name,
 * { MATERIAL_NAME }, { 3 }, { 0 }, { 1.0f, 2.0f, 3.0f }, { 0.0f, 1.0f, 0.0 },
 * { -1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 2 }, { 0 }, { 0 }, { 1, 2 })).
 */
extern const char *navigation_macro_name;

/**
 * The name of a macro which declares a list of locations (e.g.
 * LOCATION_LIST_MACRO_NAME(LOCATION_MACRO_NAME(...), LOCATION_MACRO_NAME(...),
 * ...)).
 */
extern const char *location_list_macro_name;

/**
 * The name of a macro which declares the X, Y and Z coordinates of a single
 * location (e.g. MACRO_NAME(1.23f, -3.25f, 94.24f)).
 */
extern const char *location_macro_name;

/**
 * The name of a macro which declares a list of red intensities (e.g.
 * RED_LIST_MACRO_NAME(RED_MACRO_NAME(...), RED_MACRO_NAME(...), ...)).
 */
extern const char *red_list_macro_name;

/**
 * The name of a macro which declares a red intensity as a unit interval (e.g.
 * RED_MACRO_NAME(0.92f)).
 */
extern const char *red_macro_name;

/**
 * The name of a macro which declares a list of green intensities (e.g.
 * GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(...), GREEN_MACRO_NAME(...), ...)).
 */
extern const char *green_list_macro_name;

/**
 * The name of a macro which declares a green intensity as a unit interval (e.g.
 * GREEN_MACRO_NAME(0.92f)).
 */
extern const char *green_macro_name;

/**
 * The name of a macro which declares a list of blue intensities (e.g.
 * BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(...), BLUE_MACRO_NAME(...), ...)).
 */
extern const char *blue_list_macro_name;

/**
 * The name of a macro which declares a blue intensity as a unit interval (e.g.
 * BLUE_MACRO_NAME(0.92f)).
 */
extern const char *blue_macro_name;

/**
 * The name of a macro which declares a list of opacities (e.g.
 * OPACITY_LIST_MACRO_NAME(OPACITY_MACRO_NAME(...), OPACITY_MACRO_NAME(...),
 * ...)).
 */
extern const char *opacity_list_macro_name;

/**
 * The name of a macro which declares an opacity as a unit interval (e.g.
 * OPACITY_MACRO_NAME(0.92f)).
 */
extern const char *opacity_macro_name;

/**
 * The name of a macro which declares a list of V coordinates (e.g.
 * V_LIST_MACRO_NAME(V_MACRO_NAME(...), V_MACRO_NAME(...), ...)).
 */
extern const char *v_list_macro_name;

/**
 * The name of a macro which declares a V coordinate (e.g. V_MACRO_NAME(0.92f)).
 */
extern const char *v_macro_name;

/**
 * The name of a macro which declares a list of U coordinates (e.g.
 * U_LIST_MACRO_NAME(U_MACRO_NAME(...), U_MACRO_NAME(...), ...)).
 */
extern const char *u_list_macro_name;

/**
 * The name of a macro which declares a U coordinate (e.g. U_MACRO_NAME(0.92f)).
 */
extern const char *u_macro_name;

/**
 * The include paths to emit.
 */
extern const char *const *include_paths;

/**
 * The number of include paths to emit.
 */
extern size_t number_of_include_paths;

#endif
