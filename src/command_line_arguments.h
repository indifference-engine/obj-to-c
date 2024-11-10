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
 * The name of a macro which declares data for an opaque pass (e.g.
 * OPAQUE_PASS_DATA_MACRO_NAME(object_name, RED_LIST_MACRO_NAME(...),
 * GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...))).
 */
extern const char *opaque_pass_data_macro_name;

/**
 * The name of a macro which declares data for an opaque draw call (e.g.
 * OPAQUE_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name,
 * V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...),
 * LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).
 */
extern const char *opaque_draw_call_data_macro_name;

/**
 * The name of a macro which declares data for a cutout pass (e.g.
 * CUTOUT_PASS_DATA_MACRO_NAME(object_name, RED_LIST_MACRO_NAME(...),
 * GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...),
 * OPACITY_LIST_MACRO_NAME(...))).
 */
extern const char *cutout_pass_data_macro_name;

/**
 * The name of a macro which declares data for a cutout draw call (e.g.
 * CUTOUT_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name,
 * V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...),
 * LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).
 */
extern const char *cutout_draw_call_data_macro_name;

/**
 * The name of a macro which declares an opaque/cutout pass
 * (e.g. OPAQUE_CUTOUT_PASS_MACRO_NAME(object_name,
 * OPAQUE_DRAW_CALL_MACRO_NAME(...), CUTOUT_DRAW_CALL_MACRO_NAME(...), ...)).
 */
extern const char *opaque_cutout_pass_macro_name;

/**
 * The name of a macro which declares an opaque draw call (e.g.
 * OPAQUE_DRAW_CALL_MACRO_NAME(object_name, material_name)).
 */
extern const char *opaque_draw_call_macro_name;

/**
 * The name of a macro which declares a cutout draw call (e.g.
 * CUTOUT_DRAW_CALL_MACRO_NAME(object_name, material_name)).
 */
extern const char *cutout_draw_call_macro_name;

/**
 * The name of a macro which declares data for an additive/blended pass (XYZ)
 * (e.g. ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME(object_name,
 * LOCATION_LIST_MACRO_NAME(...))).
 */
extern const char *additive_blended_pass_data_macro_name;

/**
 * The name of a macro which declares data for an additive pass (e.g.
 * ADDITIVE_PASS_DATA_MACRO_NAME(object_name, RED_LIST_MACRO_NAME(...),
 * GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...))).
 */
extern const char *additive_pass_data_macro_name;

/**
 * The name of a macro which declares data for an additive draw call (e.g.
 * ADDITIVE_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name,
 * V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...),
 * LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).
 */
extern const char *additive_draw_call_data_macro_name;

/**
 * The name of a macro which declares data for an blended pass (e.g.
 * BLENDED_PASS_DATA_MACRO_NAME(object_name, RED_LIST_MACRO_NAME(...),
 * GREEN_LIST_MACRO_NAME(...), BLUE_LIST_MACRO_NAME(...),
 * OPACITY_LIST_MACRO_NAME(...))).
 */
extern const char *blended_pass_data_macro_name;

/**
 * The name of a macro which declares data for an blended draw call (e.g.
 * BLENDED_DRAW_CALL_DATA_MACRO_NAME(object_name, material_name,
 * V_LIST_MACRO_NAME(...), U_LIST_MACRO_NAME(...),
 * LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(...),
 * VU_INDEX_TRIANGLE_LIST_MACRO_NAME(...)).
 */
extern const char *blended_draw_call_data_macro_name;

/**
 * The name of a macro which declares an additive/blended pass
 * (e.g. ADDITIVE_BLENDED_PASS_MACRO_NAME(object_name,
 * ADDITIVE_DRAW_CALL_MACRO_NAME(...), BLENDED_DRAW_CALL_MACRO_NAME(...), ...)).
 */
extern const char *additive_blended_pass_macro_name;

/**
 * The name of a macro which declares an additive draw call
 * (e.g. ADDITIVE_DRAW_CALL_MACRO_NAME(object_name, material_name)).
 */
extern const char *additive_draw_call_macro_name;

/**
 * The name of a macro which declares a blended draw call
 * (e.g. BLENDED_DRAW_CALL_MACRO_NAME(object_name, material_name)).
 */
extern const char *blended_draw_call_macro_name;

/**
 * The name of a macro which declares a navigation mesh (e.g.
 * NAVIGATION_MACRO_NAME(object_name, MATERIAL_LIST_MACRO_NAME(...),
 * FACE_VERTEX_COUNT_LIST_MACRO_NAME(...),
 * FACE_VERTEX_OFFSET_LIST_MACRO_NAME(...),
 * FACE_VERTEX_LOCATION_LIST_NAME(...),
 * NORMAL_LIST_MACRO_NAME(...),
 * FACE_EDGE_EXIT_NORMAL_LIST_MACRO_NAME(...),
 * FACE_VERTEX_UP_NORMAL_LIST_MACRO_NAME(...),
 * NEIGHBOR_COUNT_LIST_MACRO_NAME(...),
 * FACE_EDGE_OFFSET_LIST_MACRO_NAME(...),
 * FACE_EDGE_NEIGHBOR_OFFSET_LIST_MACRO_NAME(...),
 * FACE_EDGE_NEIGHBOUR_FACE_INDEX_LIST_MACRO_NAME(...)).
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
 * location (e.g. LOCATION_MACRO_NAME(1.23f, -3.25f, 94.24f)).
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
 * The name of a macro which declares a list of location index triangles (e.g.
 * LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(
 * LOCATION_INDEX_TRIANGLE_MACRO_NAME(...),
 * LOCATION_INDEX_TRIANGLE_MACRO_NAME(...), ...)).
 */
extern const char *location_index_triangle_list_macro_name;

/**
 * The name of a macro which declares a triangle of location indices (e.g.
 * LOCATION_INDEX_TRIANGLE_MACRO_NAME(LOCATION_INDEX_MACRO_NAME(123),
 * LOCATION_INDEX_MACRO_NAME(123), LOCATION_INDEX_MACRO_NAME(123))).
 */
extern const char *location_index_triangle_macro_name;

/**
 * The name of a macro which declares a location index (e.g.
 * LOCATION_INDEX_MACRO_NAME(123)).
 */
extern const char *location_index_macro_name;

/**
 * The name of a macro which declares a list of color index triangles (e.g.
 * COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(COLOR_INDEX_TRIANGLE_MACRO_NAME(...),
 * COLOR_INDEX_TRIANGLE_MACRO_NAME(...), ...)).
 */
extern const char *color_index_triangle_list_macro_name;

/**
 * The name of a macro which declares a triangle of color indices (e.g.
 * COLOR_INDEX_TRIANGLE_MACRO_NAME(COLOR_INDEX_MACRO_NAME(123),
 * COLOR_INDEX_MACRO_NAME(123), COLOR_INDEX_MACRO_NAME(123))).
 */
extern const char *color_index_triangle_macro_name;

/**
 * The name of a macro which declares a color index (e.g.
 * COLOR_INDEX_MACRO_NAME(123)).
 */
extern const char *color_index_macro_name;

/**
 * The name of a macro which declares a list of VU index triangles (e.g.
 * VU_INDEX_TRIANGLE_LIST_MACRO_NAME(VU_INDEX_TRIANGLE_MACRO_NAME(...),
 * VU_INDEX_TRIANGLE_MACRO_NAME(...), ...)).
 */
extern const char *vu_index_triangle_list_macro_name;

/**
 * The name of a macro which declares a triangle of VU indices (e.g.
 * VU_INDEX_TRIANGLE_MACRO_NAME(VU_INDEX_MACRO_NAME(123),
 * VU_INDEX_MACRO_NAME(123), VU_INDEX_MACRO_NAME(123))).
 */
extern const char *vu_index_triangle_macro_name;

/**
 * The name of a macro which declares a VU index (e.g.
 * VU_INDEX_MACRO_NAME(123)).
 */
extern const char *vu_index_macro_name;

/**
 * The name of a macro which declares a list of face vertex counts (e.g.
 * FACE_VERTEX_COUNT_LIST_MACRO_NAME(FACE_VERTEX_COUNT_MACRO_NAME(3),
 * FACE_VERTEX_COUNT_MACRO_NAME(5), ...)).
 */
extern const char *face_vertex_count_list_macro_name;

/**
 * The name of a macro which declares a face vertex count
 * (e.g. FACE_VERTEX_COUNT_MACRO_NAME(3)).
 */
extern const char *face_vertex_count_macro_name;

/**
 * The name of a macro which declares a list of face vertex offsets (e.g.
 * FACE_VERTEX_OFFSET_LIST_MACRO_NAME(FACE_VERTEX_OFFSET_MACRO_NAME(3),
 * FACE_VERTEX_OFFSET_MACRO_NAME(8), ...)).
 */
extern const char *face_vertex_offset_list_macro_name;

/**
 * The name of a macro which declares a face vertex offset
 * (e.g. FACE_VERTEX_OFFSET_MACRO_NAME(3)).
 */
extern const char *face_vertex_offset_macro_name;

/**
 * The name of a macro which declares a list of faces, each of which contains
 * a list of vertex locations (e.g. FACE_VERTEX_LOCATION_LIST_NAME(
 * LOCATION_FACE_MACRO_NAME(...), LOCATION_FACE_MACRO_NAME(...), ...)).
 */
extern const char *face_vertex_location_list_name;

/**
 * The name of a macro which declares a list of vertex locations (e.g.
 * LOCATION_FACE_MACRO_NAME(LOCATION_MACRO_NAME(1.23f, -3.25f, 94.24f),
 * LOCATION_MACRO_NAME(1.23f, -3.25f, 94.24f), ...)).
 */
extern const char *location_face_macro_name;

/**
 * The name of a macro which declares a list of normals (e.g.
 * NORMAL_LIST_MACRO_NAME(NORMAL_MACRO_NAME(0.337f, -0.7538f, -0.5641f),
 * NORMAL_MACRO_NAME(-0.6719f, 0.6248f, -0.3977f), ...)).
 */
extern const char *normal_list_macro_name;

/**
 * The name of a macro which declares a list of edge exit normals for each face
 * (e.g. FACE_EDGE_EXIT_NORMAL_LIST_MACRO_NAME(NORMAL_LIST_MACRO_NAME(...),
 * NORMAL_LIST_MACRO_NAME(...), ...).
 */
extern const char *face_edge_exit_normal_list_macro_name;

/**
 * The name of a macro which declares a list of vertex up normals for each face
 * (e.g. FACE_VERTEX_UP_NORMAL_LIST_MACRO_NAME(NORMAL_LIST_MACRO_NAME(...),
 * NORMAL_LIST_MACRO_NAME(...), ...).
 */
extern const char *face_vertex_up_normal_list_macro_name;

/**
 * The name of a macro which declares a normal
 * (e.g. NORMAL_MACRO_NAME(0.337f, -0.7538f, -0.5641f)).
 */
extern const char *normal_macro_name;

/**
 * The name of a macro which declares a list of faces, each of which contains a
 * list of how many neighbors each of its edges have (e.g.
 * NEIGHBOR_COUNT_LIST_LIST_MACRO_NAME(NEIGHBOR_COUNT_LIST_MACRO_NAME(...),
 * NEIGHBOR_COUNT_LIST_MACRO_NAME(...), ...)).
 */
extern const char *neighbor_count_list_list_macro_name;

/**
 * The name of a macro which declares a list of edge neighbor counts (e.g.
 * NEIGHBOR_COUNT_LIST_MACRO_NAME(NEIGHBOR_COUNT_MACRO_NAME(2),
 * NEIGHBOR_COUNT_MACRO_NAME(0), ...)).
 */
extern const char *neighbor_count_list_macro_name;

/**
 * The name of a macro which declares an edge neighbor count (e.g.
 * NEIGHBOR_COUNT_MACRO_NAME(0)).
 */
extern const char *neighbor_count_macro_name;

/**
 * The name of a macro which declares a list of faces, each of which contains a
 * list of edges, each of which contains a list of vertex offsets (e.g.
 * FACE_EDGE_OFFSET_LIST_MACRO_NAME(OFFSET_MACRO_NAME(3), OFFSET_MACRO_NAME(8),
 * ...).
 */
extern const char *face_edge_offset_list_macro_name;

/**
 * The name of a macro which declares a list of faces, each of which contains a
 * list of edges, each of which contains a list of neighbor vertex offsets (e.g.
 * FACE_EDGE_NEIGHBOR_OFFSET_LIST_MACRO_NAME(OFFSET_LIST_LIST_MACRO_NAME(...),
 * OFFSET_LIST_LIST_MACRO_NAME(...), ...).
 */
extern const char *face_edge_neighbor_offset_list_macro_name;

/**
 * The name of a macro which declares a list of a list of offsets into an array
 * (e.g. OFFSET_LIST_LIST_MACRO_NAME(OFFSET_LIST_MACRO_NAME(...),
 * OFFSET_LIST_MACRO_NAME(...), ...)).
 */
extern const char *offset_list_list_macro_name;

/**
 * The name of a macro which declares a list of offsets into an array (e.g.
 * OFFSET_LIST_MACRO_NAME(OFFSET_MACRO_NAME(3), OFFSET_MACRO_NAME(8), ...)).
 */
extern const char *offset_list_macro_name;

/**
 * The name of a macro which declares an offset into an array (e.g.
 * OFFSET_MACRO_NAME(3)).
 */
extern const char *offset_macro_name;

/**
 * The name of a macro which declares a list of faces, each of which contains a
 * list of edges, each of which contains a list of neighbors, each of which
 * contains a face index (e.g. FACE_INDEX_LIST_LIST_LIST_MACRO_NAME(
 * FACE_INDEX_LIST_LIST_MACRO_NAME(...), FACE_INDEX_LIST_LIST_MACRO_NAME(...),
 * ...)).
 */
extern const char *face_index_list_list_list_macro_name;

/**
 * The name of a macro which declares a list of edges, each of which contains a
 * list of neighbors, each of which contains a face index (e.g.
 * FACE_INDEX_LIST_LIST_MACRO_NAME(FACE_INDEX_LIST_MACRO_NAME(...),
 * FACE_INDEX_LIST_MACRO_NAME(...), ...)).
 */
extern const char *face_index_list_list_macro_name;

/**
 * The name of a macro which declares a list of faces, each of which contains a
 * list of edges, each of which contains a list of neighbors, each of which
 * contains a face index (e.g. FACE_EDGE_NEIGHBOUR_FACE_INDEX_LIST_MACRO_NAME(
 * FACE_INDEX_MACRO_NAME(3), FACE_INDEX_MACRO_NAME(8), ...)).
 */
extern const char *face_edge_neighbour_face_index_list_macro_name;

/**
 * The name of a macro which declares a face index (e.g.
 * FACE_INDEX_MACRO_NAME(3)).
 */
extern const char *face_index_macro_name;

/**
 * The name of a macro which declares a material name (e.g.
 * MATERIAL_LIST_MACRO_NAME(MATERIAL_PREFIX_A, MATERIAL_PREFIX_B, ...)).
 */
extern const char *material_list_macro_name;

/**
 * The include paths to emit.
 */
extern const char *const *include_paths;

/**
 * The number of include paths to emit.
 */
extern size_t number_of_include_paths;

#endif
