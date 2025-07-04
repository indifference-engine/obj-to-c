#include "command_line_arguments.h"
#include <stdlib.h>

const char *object_prefix = NULL;
const char *material_prefix = NULL;
const char *navigation_material_prefix = NULL;
const char *opaque_cutout_pass_data_macro_name = NULL;
const char *opaque_preparation_macro_name = NULL;
const char *cutout_preparation_macro_name = NULL;
const char *opaque_pass_data_macro_name = NULL;
const char *opaque_draw_call_data_macro_name = NULL;
const char *cutout_pass_data_macro_name = NULL;
const char *cutout_draw_call_data_macro_name = NULL;
const char *opaque_cutout_pass_macro_name = NULL;
const char *opaque_draw_call_macro_name = NULL;
const char *cutout_draw_call_macro_name = NULL;
const char *additive_blended_pass_data_macro_name = NULL;
const char *additive_pass_data_macro_name = NULL;
const char *additive_draw_call_data_macro_name = NULL;
const char *blended_pass_data_macro_name = NULL;
const char *blended_draw_call_data_macro_name = NULL;
const char *additive_blended_pass_macro_name = NULL;
const char *additive_preparation_macro_name = NULL;
const char *blended_preparation_macro_name = NULL;
const char *additive_draw_call_macro_name = NULL;
const char *blended_draw_call_macro_name = NULL;
const char *navigation_macro_name = NULL;
const char *location_list_macro_name = NULL;
const char *location_macro_name = NULL;
const char *opacity_list_macro_name = NULL;
const char *opacity_macro_name = NULL;
const char *red_list_macro_name = NULL;
const char *red_macro_name = NULL;
const char *green_list_macro_name = NULL;
const char *green_macro_name = NULL;
const char *blue_list_macro_name = NULL;
const char *blue_macro_name = NULL;
const char *v_list_macro_name = NULL;
const char *v_macro_name = NULL;
const char *u_list_macro_name = NULL;
const char *u_macro_name = NULL;
const char *location_index_triangle_list_macro_name = NULL;
const char *location_index_triangle_macro_name = NULL;
const char *location_index_macro_name = NULL;
const char *color_index_triangle_list_macro_name = NULL;
const char *color_index_triangle_macro_name = NULL;
const char *color_index_macro_name = NULL;
const char *vu_index_triangle_list_macro_name = NULL;
const char *vu_index_triangle_macro_name = NULL;
const char *vu_index_macro_name = NULL;
const char *face_vertex_count_list_macro_name = NULL;
const char *face_vertex_count_macro_name = NULL;
const char *face_vertex_offset_list_macro_name = NULL;
const char *face_vertex_offset_macro_name = NULL;
const char *face_vertex_location_list_name = NULL;
const char *location_face_macro_name = NULL;
const char *normal_list_macro_name = NULL;
const char *face_edge_exit_normal_list_macro_name = NULL;
const char *face_edge_normal_list_macro_name = NULL;
const char *face_edge_coefficient_list_macro_name = NULL;
const char *face_vertex_up_normal_list_macro_name = NULL;
const char *normal_macro_name = NULL;
const char *neighbor_count_list_list_macro_name = NULL;
const char *neighbor_count_list_macro_name = NULL;
const char *neighbor_count_macro_name = NULL;
const char *face_edge_offset_list_macro_name = NULL;
const char *face_edge_neighbor_offset_list_macro_name = NULL;
const char *offset_list_list_macro_name = NULL;
const char *offset_list_macro_name = NULL;
const char *offset_macro_name = NULL;
const char *face_index_list_list_list_macro_name = NULL;
const char *face_index_list_list_macro_name = NULL;
const char *face_edge_neighbor_face_index_list_macro_name = NULL;
const char *face_index_macro_name = NULL;
const char *material_list_macro_name = NULL;
const char *material_import_macro_name = NULL;
const char *coefficient_list_macro_name = NULL;
const char *coefficient_macro_name = NULL;
const char *const *include_paths = NULL;
size_t number_of_include_paths = 0;
