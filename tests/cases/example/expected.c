#include "test/include/a.h"
#include "test/include/b.h"
#include "test/include/c.h"
TEST_MATERIAL_IMPORT_MACRO_NAME(test_material_prefix_a)
TEST_MATERIAL_IMPORT_MACRO_NAME(test_material_prefix_b)
TEST_MATERIAL_IMPORT_MACRO_NAME(test_material_prefix_c)
TEST_MATERIAL_IMPORT_MACRO_NAME(test_material_prefix_d)
TEST_OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME(
  test_object_prefix_object_name,
  TEST_LOCATION_LIST_MACRO_NAME(TEST_LOCATION_MACRO_NAME(14.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(21.000000, 12.000000, 13.000000), TEST_LOCATION_MACRO_NAME(20.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(27.000000, 12.000000, 13.000000))
)
TEST_OPAQUE_PASS_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  TEST_RED_LIST_MACRO_NAME(TEST_RED_MACRO_NAME(0.200000), TEST_RED_MACRO_NAME(0.300000), TEST_RED_MACRO_NAME(0.650000), TEST_RED_MACRO_NAME(0.250000)),
  TEST_GREEN_LIST_MACRO_NAME(TEST_GREEN_MACRO_NAME(0.700000), TEST_GREEN_MACRO_NAME(0.400000), TEST_GREEN_MACRO_NAME(0.400000), TEST_GREEN_MACRO_NAME(0.750000)),
  TEST_BLUE_LIST_MACRO_NAME(TEST_BLUE_MACRO_NAME(0.800000), TEST_BLUE_MACRO_NAME(0.500000), TEST_BLUE_MACRO_NAME(0.225000), TEST_BLUE_MACRO_NAME(0.450000))
)
TEST_OPAQUE_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  test_material_prefix_a,
  TEST_V_LIST_MACRO_NAME(TEST_V_MACRO_NAME(0.840000), TEST_V_MACRO_NAME(0.110000), TEST_V_MACRO_NAME(0.380000)),
  TEST_U_LIST_MACRO_NAME(TEST_U_MACRO_NAME(0.110000), TEST_U_MACRO_NAME(0.920000), TEST_U_MACRO_NAME(0.630000)),
  TEST_LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_LOCATION_INDEX_TRIANGLE_MACRO_NAME(TEST_LOCATION_INDEX_MACRO_NAME(0), TEST_LOCATION_INDEX_MACRO_NAME(1), TEST_LOCATION_INDEX_MACRO_NAME(2)), TEST_LOCATION_INDEX_TRIANGLE_MACRO_NAME(TEST_LOCATION_INDEX_MACRO_NAME(1), TEST_LOCATION_INDEX_MACRO_NAME(0), TEST_LOCATION_INDEX_MACRO_NAME(2)), TEST_LOCATION_INDEX_TRIANGLE_MACRO_NAME(TEST_LOCATION_INDEX_MACRO_NAME(1), TEST_LOCATION_INDEX_MACRO_NAME(2), TEST_LOCATION_INDEX_MACRO_NAME(3))),
  TEST_COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_COLOR_INDEX_TRIANGLE_MACRO_NAME(TEST_COLOR_INDEX_MACRO_NAME(0), TEST_COLOR_INDEX_MACRO_NAME(1), TEST_COLOR_INDEX_MACRO_NAME(2)), TEST_COLOR_INDEX_TRIANGLE_MACRO_NAME(TEST_COLOR_INDEX_MACRO_NAME(1), TEST_COLOR_INDEX_MACRO_NAME(0), TEST_COLOR_INDEX_MACRO_NAME(2)), TEST_COLOR_INDEX_TRIANGLE_MACRO_NAME(TEST_COLOR_INDEX_MACRO_NAME(1), TEST_COLOR_INDEX_MACRO_NAME(2), TEST_COLOR_INDEX_MACRO_NAME(3))),
  TEST_VU_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_VU_INDEX_TRIANGLE_MACRO_NAME(TEST_VU_INDEX_MACRO_NAME(0), TEST_VU_INDEX_MACRO_NAME(1), TEST_VU_INDEX_MACRO_NAME(2)), TEST_VU_INDEX_TRIANGLE_MACRO_NAME(TEST_VU_INDEX_MACRO_NAME(0), TEST_VU_INDEX_MACRO_NAME(1), TEST_VU_INDEX_MACRO_NAME(2)), TEST_VU_INDEX_TRIANGLE_MACRO_NAME(TEST_VU_INDEX_MACRO_NAME(0), TEST_VU_INDEX_MACRO_NAME(2), TEST_VU_INDEX_MACRO_NAME(0)))
)
TEST_CUTOUT_PASS_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  TEST_OPACITY_LIST_MACRO_NAME(TEST_OPACITY_MACRO_NAME(0.900000), TEST_OPACITY_MACRO_NAME(0.600000), TEST_OPACITY_MACRO_NAME(0.850000)),
  TEST_RED_LIST_MACRO_NAME(TEST_RED_MACRO_NAME(0.200000), TEST_RED_MACRO_NAME(0.300000), TEST_RED_MACRO_NAME(0.650000)),
  TEST_GREEN_LIST_MACRO_NAME(TEST_GREEN_MACRO_NAME(0.700000), TEST_GREEN_MACRO_NAME(0.400000), TEST_GREEN_MACRO_NAME(0.400000)),
  TEST_BLUE_LIST_MACRO_NAME(TEST_BLUE_MACRO_NAME(0.800000), TEST_BLUE_MACRO_NAME(0.500000), TEST_BLUE_MACRO_NAME(0.225000))
)
TEST_CUTOUT_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  test_material_prefix_b,
  TEST_V_LIST_MACRO_NAME(TEST_V_MACRO_NAME(0.840000), TEST_V_MACRO_NAME(0.110000), TEST_V_MACRO_NAME(0.380000)),
  TEST_U_LIST_MACRO_NAME(TEST_U_MACRO_NAME(0.110000), TEST_U_MACRO_NAME(0.920000), TEST_U_MACRO_NAME(0.630000)),
  TEST_LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_LOCATION_INDEX_TRIANGLE_MACRO_NAME(TEST_LOCATION_INDEX_MACRO_NAME(0), TEST_LOCATION_INDEX_MACRO_NAME(1), TEST_LOCATION_INDEX_MACRO_NAME(2))),
  TEST_COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_COLOR_INDEX_TRIANGLE_MACRO_NAME(TEST_COLOR_INDEX_MACRO_NAME(0), TEST_COLOR_INDEX_MACRO_NAME(1), TEST_COLOR_INDEX_MACRO_NAME(2))),
  TEST_VU_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_VU_INDEX_TRIANGLE_MACRO_NAME(TEST_VU_INDEX_MACRO_NAME(0), TEST_VU_INDEX_MACRO_NAME(1), TEST_VU_INDEX_MACRO_NAME(2)))
)
TEST_OPAQUE_CUTOUT_PASS_MACRO_NAME
(
  test_object_prefix_object_name,
  TEST_OPAQUE_PREPARATION_MACRO_NAME(test_object_prefix_object_name)
  TEST_CUTOUT_PREPARATION_MACRO_NAME(test_object_prefix_object_name)
  TEST_OPAQUE_DRAW_CALL_MACRO_NAME(test_object_prefix_object_name, test_material_prefix_a)
  TEST_CUTOUT_DRAW_CALL_MACRO_NAME(test_object_prefix_object_name, test_material_prefix_b)
)
TEST_ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME(
  test_object_prefix_object_name,
  TEST_LOCATION_LIST_MACRO_NAME(TEST_LOCATION_MACRO_NAME(14.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(21.000000, 12.000000, 13.000000), TEST_LOCATION_MACRO_NAME(20.000000, 35.000000, 46.000000))
)
TEST_ADDITIVE_PASS_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  TEST_RED_LIST_MACRO_NAME(TEST_RED_MACRO_NAME(0.200000), TEST_RED_MACRO_NAME(0.300000), TEST_RED_MACRO_NAME(0.650000)),
  TEST_GREEN_LIST_MACRO_NAME(TEST_GREEN_MACRO_NAME(0.700000), TEST_GREEN_MACRO_NAME(0.400000), TEST_GREEN_MACRO_NAME(0.400000)),
  TEST_BLUE_LIST_MACRO_NAME(TEST_BLUE_MACRO_NAME(0.800000), TEST_BLUE_MACRO_NAME(0.500000), TEST_BLUE_MACRO_NAME(0.225000))
)
TEST_ADDITIVE_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  test_material_prefix_c,
  TEST_V_LIST_MACRO_NAME(TEST_V_MACRO_NAME(0.840000), TEST_V_MACRO_NAME(0.110000), TEST_V_MACRO_NAME(0.380000)),
  TEST_U_LIST_MACRO_NAME(TEST_U_MACRO_NAME(0.110000), TEST_U_MACRO_NAME(0.920000), TEST_U_MACRO_NAME(0.630000)),
  TEST_LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_LOCATION_INDEX_TRIANGLE_MACRO_NAME(TEST_LOCATION_INDEX_MACRO_NAME(0), TEST_LOCATION_INDEX_MACRO_NAME(1), TEST_LOCATION_INDEX_MACRO_NAME(2))),
  TEST_COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_COLOR_INDEX_TRIANGLE_MACRO_NAME(TEST_COLOR_INDEX_MACRO_NAME(0), TEST_COLOR_INDEX_MACRO_NAME(1), TEST_COLOR_INDEX_MACRO_NAME(2))),
  TEST_VU_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_VU_INDEX_TRIANGLE_MACRO_NAME(TEST_VU_INDEX_MACRO_NAME(0), TEST_VU_INDEX_MACRO_NAME(1), TEST_VU_INDEX_MACRO_NAME(2)))
)
TEST_BLENDED_PASS_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  TEST_OPACITY_LIST_MACRO_NAME(TEST_OPACITY_MACRO_NAME(0.900000), TEST_OPACITY_MACRO_NAME(0.600000), TEST_OPACITY_MACRO_NAME(0.850000)),
  TEST_RED_LIST_MACRO_NAME(TEST_RED_MACRO_NAME(0.200000), TEST_RED_MACRO_NAME(0.300000), TEST_RED_MACRO_NAME(0.650000)),
  TEST_GREEN_LIST_MACRO_NAME(TEST_GREEN_MACRO_NAME(0.700000), TEST_GREEN_MACRO_NAME(0.400000), TEST_GREEN_MACRO_NAME(0.400000)),
  TEST_BLUE_LIST_MACRO_NAME(TEST_BLUE_MACRO_NAME(0.800000), TEST_BLUE_MACRO_NAME(0.500000), TEST_BLUE_MACRO_NAME(0.225000))
)
TEST_BLENDED_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_object_name,
  test_material_prefix_d,
  TEST_V_LIST_MACRO_NAME(TEST_V_MACRO_NAME(0.840000), TEST_V_MACRO_NAME(0.110000), TEST_V_MACRO_NAME(0.380000)),
  TEST_U_LIST_MACRO_NAME(TEST_U_MACRO_NAME(0.110000), TEST_U_MACRO_NAME(0.920000), TEST_U_MACRO_NAME(0.630000)),
  TEST_LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_LOCATION_INDEX_TRIANGLE_MACRO_NAME(TEST_LOCATION_INDEX_MACRO_NAME(0), TEST_LOCATION_INDEX_MACRO_NAME(1), TEST_LOCATION_INDEX_MACRO_NAME(2))),
  TEST_COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_COLOR_INDEX_TRIANGLE_MACRO_NAME(TEST_COLOR_INDEX_MACRO_NAME(0), TEST_COLOR_INDEX_MACRO_NAME(1), TEST_COLOR_INDEX_MACRO_NAME(2))),
  TEST_VU_INDEX_TRIANGLE_LIST_MACRO_NAME(TEST_VU_INDEX_TRIANGLE_MACRO_NAME(TEST_VU_INDEX_MACRO_NAME(0), TEST_VU_INDEX_MACRO_NAME(1), TEST_VU_INDEX_MACRO_NAME(2)))
)
TEST_ADDITIVE_BLENDED_PASS_MACRO_NAME
(
  test_object_prefix_object_name,
  TEST_ADDITIVE_PREPARATION_MACRO_NAME(test_object_prefix_object_name)
  TEST_BLENDED_PREPARATION_MACRO_NAME(test_object_prefix_object_name)
  TEST_ADDITIVE_DRAW_CALL_MACRO_NAME(test_object_prefix_object_name, test_material_prefix_c)
  TEST_BLENDED_DRAW_CALL_MACRO_NAME(test_object_prefix_object_name, test_material_prefix_d)
)
TEST_NAVIGATION_MACRO_NAME(
  test_object_prefix_navigation_mesh,
  TEST_MATERIAL_LIST_MACRO_NAME(TEST_NAVIGATION_MATERIAL_PREFIX_A, TEST_NAVIGATION_MATERIAL_PREFIX_B, TEST_NAVIGATION_MATERIAL_PREFIX_B),
  TEST_FACE_VERTEX_COUNT_LIST_MACRO_NAME(TEST_FACE_VERTEX_COUNT_MACRO_NAME(4), TEST_FACE_VERTEX_COUNT_MACRO_NAME(3), TEST_FACE_VERTEX_COUNT_MACRO_NAME(3)),
  TEST_FACE_VERTEX_OFFSET_LIST_MACRO_NAME(TEST_FACE_VERTEX_OFFSET_MACRO_NAME(0), TEST_FACE_VERTEX_OFFSET_MACRO_NAME(4), TEST_FACE_VERTEX_OFFSET_MACRO_NAME(7)),
  TEST_FACE_VERTEX_LOCATION_LIST_NAME(TEST_LOCATION_LIST_MACRO_NAME(TEST_LOCATION_MACRO_NAME(21.000000, 12.000000, 13.000000), TEST_LOCATION_MACRO_NAME(14.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(20.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(27.000000, 12.000000, 13.000000)), TEST_LOCATION_LIST_MACRO_NAME(TEST_LOCATION_MACRO_NAME(20.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(14.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(18.000000, 19.000000, 20.000000)), TEST_LOCATION_LIST_MACRO_NAME(TEST_LOCATION_MACRO_NAME(20.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(14.000000, 35.000000, 46.000000), TEST_LOCATION_MACRO_NAME(5.000000, 2.000000, 7.000000))),
  TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.000000, 0.820398, -0.571793), TEST_NORMAL_MACRO_NAME(0.000000, -0.851658, 0.524097), TEST_NORMAL_MACRO_NAME(0.000000, -0.763386, 0.645942)),
  TEST_FACE_EDGE_EXIT_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(-0.985193, -0.098032, -0.140655), TEST_NORMAL_MACRO_NAME(0.000000, -0.601455, -0.798907), TEST_NORMAL_MACRO_NAME(0.985193, 0.098032, 0.140655), TEST_NORMAL_MACRO_NAME(-0.000000, -0.571793, -0.820398)), TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.000000, 0.601455, 0.798907), TEST_NORMAL_MACRO_NAME(-0.991525, -0.068088, -0.110642), TEST_NORMAL_MACRO_NAME(0.997861, -0.034261, -0.055675)), TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.000000, 0.601455, 0.798907), TEST_NORMAL_MACRO_NAME(-0.984835, 0.112067, 0.132443), TEST_NORMAL_MACRO_NAME(0.959497, -0.181974, -0.215060))),
  TEST_FACE_EDGE_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(-0.985193, -0.098032, -0.140655), TEST_NORMAL_MACRO_NAME(-0.000000, 0.571793, 0.820398), TEST_NORMAL_MACRO_NAME(0.985193, 0.098032, 0.140655), TEST_NORMAL_MACRO_NAME(-0.000000, -0.571793, -0.820398)), TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.000000, 0.524097, 0.851658), TEST_NORMAL_MACRO_NAME(-0.991525, -0.068088, -0.110642), TEST_NORMAL_MACRO_NAME(0.997861, -0.034261, -0.055675)), TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.000000, 0.645942, 0.763386), TEST_NORMAL_MACRO_NAME(-0.984835, 0.112067, 0.132443), TEST_NORMAL_MACRO_NAME(0.959497, -0.181974, -0.215060))),
  FACE_EDGE_COEFFICIENT_LIST_MACRO_NAME(TEST_COEFFICIENT_LIST_MACRO_NAME(TEST_COEFFICIENT_LIST_MACRO_NAME(-0.004199, 0.013797, 0.019796), TEST_COEFFICIENT_LIST_MACRO_NAME(0.166667, 0.000000, 0.000000), TEST_COEFFICIENT_LIST_MACRO_NAME(0.004199, -0.013797, -0.019796), TEST_COEFFICIENT_LIST_MACRO_NAME(-0.166667, 0.000000, 0.000000)), TEST_COEFFICIENT_LIST_MACRO_NAME(TEST_COEFFICIENT_LIST_MACRO_NAME(-0.166667, 0.000000, 0.000000), TEST_COEFFICIENT_LIST_MACRO_NAME(0.004219, -0.016878, -0.027426), TEST_COEFFICIENT_LIST_MACRO_NAME(0.002137, 0.017094, 0.027778)), TEST_COEFFICIENT_LIST_MACRO_NAME(TEST_COEFFICIENT_LIST_MACRO_NAME(-0.166667, 0.000000, 0.000000), TEST_COEFFICIENT_LIST_MACRO_NAME(-0.003344, -0.012263, -0.014493), TEST_COEFFICIENT_LIST_MACRO_NAME(0.005291, 0.011640, 0.013757))),
  TEST_FACE_VERTEX_UP_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.000000, 0.820398, -0.571793), TEST_NORMAL_MACRO_NAME(-0.006373, -0.798891, 0.601442), TEST_NORMAL_MACRO_NAME(-0.006373, -0.798891, 0.601442), TEST_NORMAL_MACRO_NAME(0.000000, 0.820398, -0.571793)), TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(0.006127, -0.798892, 0.601443), TEST_NORMAL_MACRO_NAME(-0.012254, -0.798847, 0.601409), TEST_NORMAL_MACRO_NAME(-0.000000, -0.851658, 0.524097)), TEST_NORMAL_LIST_MACRO_NAME(TEST_NORMAL_MACRO_NAME(-0.016706, -0.798796, 0.601371), TEST_NORMAL_MACRO_NAME(-0.010024, -0.798867, 0.601424), TEST_NORMAL_MACRO_NAME(0.000000, -0.763386, 0.645942))),
  TEST_NEIGHBOR_COUNT_LIST_LIST_MACRO_NAME(TEST_NEIGHBOR_COUNT_LIST_MACRO_NAME(TEST_NEIGHBOR_COUNT_MACRO_NAME(0), TEST_NEIGHBOR_COUNT_MACRO_NAME(2), TEST_NEIGHBOR_COUNT_MACRO_NAME(0), TEST_NEIGHBOR_COUNT_MACRO_NAME(0)), TEST_NEIGHBOR_COUNT_LIST_MACRO_NAME(TEST_NEIGHBOR_COUNT_MACRO_NAME(2), TEST_NEIGHBOR_COUNT_MACRO_NAME(0), TEST_NEIGHBOR_COUNT_MACRO_NAME(0)), TEST_NEIGHBOR_COUNT_LIST_MACRO_NAME(TEST_NEIGHBOR_COUNT_MACRO_NAME(2), TEST_NEIGHBOR_COUNT_MACRO_NAME(0), TEST_NEIGHBOR_COUNT_MACRO_NAME(0))),
  TEST_FACE_EDGE_OFFSET_LIST_MACRO_NAME(TEST_OFFSET_MACRO_NAME(0), TEST_OFFSET_MACRO_NAME(4), TEST_OFFSET_MACRO_NAME(7)),
  TEST_FACE_EDGE_NEIGHBOR_OFFSET_LIST_MACRO_NAME(TEST_OFFSET_LIST_MACRO_NAME(TEST_OFFSET_MACRO_NAME(0), TEST_OFFSET_MACRO_NAME(0), TEST_OFFSET_MACRO_NAME(2), TEST_OFFSET_MACRO_NAME(2)), TEST_OFFSET_LIST_MACRO_NAME(TEST_OFFSET_MACRO_NAME(2), TEST_OFFSET_MACRO_NAME(4), TEST_OFFSET_MACRO_NAME(4)), TEST_OFFSET_LIST_MACRO_NAME(TEST_OFFSET_MACRO_NAME(4), TEST_OFFSET_MACRO_NAME(6), TEST_OFFSET_MACRO_NAME(6))),
  TEST_FACE_EDGE_NEIGHBOR_FACE_INDEX_LIST_MACRO_NAME(TEST_FACE_INDEX_MACRO_NAME(1), TEST_FACE_INDEX_MACRO_NAME(2), TEST_FACE_INDEX_MACRO_NAME(0), TEST_FACE_INDEX_MACRO_NAME(2), TEST_FACE_INDEX_MACRO_NAME(0), TEST_FACE_INDEX_MACRO_NAME(1))
)
