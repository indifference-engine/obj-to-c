#include "test/include/a.h"
#include "test/include/b.h"
#include "test/include/c.h"
TEST_OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME({ -1.000000f, -1.000000f, 1.534695f, 1.000000f, -1.000000f, 1.534695f, 1.000000f, 1.000000f, 1.534695f, -1.000000f, 1.000000f, 1.534695f, -1.935218f, 0.000000f, 1.534695f, 1.000000f, 1.000000f, 0.767347f, -1.935218f, 0.000000f, 0.000000f, -1.000000f, -1.000000f, 0.000000f, -1.000000f, 1.000000f, 1.084368f, -1.000000f, 1.000000f, 0.000000f, -1.000000f, 2.170819f, 1.084368f, -1.000000f, 2.170819f, 0.000000f, 1.000000f, -1.000000f, 0.000000f, 1.000000f, 1.000000f, 0.000000f, 1.000000f, 2.170819f, 0.000000f, 1.000000f, 2.170819f, 0.767347f, 1.855214f, 1.000000f, 0.767347f, 1.855214f, 1.000000f, 0.000000f, 1.855214f, 2.170819f, 0.000000f, 1.855214f, 2.170819f, 0.767347f, 1.855214f, 2.764472f, 0.213226f, 1.855214f, 2.764472f, 0.571406f, 1.000000f, 2.764472f, 0.213226f, 1.000000f, 2.764472f, 0.571406f })
TEST_OPAQUE_PASS_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  { 1.000000f, 1.000000f, 0.000000f, 0.000000f },
  { 1.000000f, 0.000000f, 0.145098f, 1.000000f },
  { 1.000000f, 0.035294f, 1.000000f, 0.121569f }
)
TEST_OPAQUE_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  test_material_prefix_opaque_b,
  { 0.267882f, 0.528240f, 0.528240f, 0.267882f, 0.146137f },
  { 0.397042f, 0.397042f, 0.136684f, 0.136684f, 0.266863f },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4 }
)
TEST_OPAQUE_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  test_material_prefix_opaque_a,
  { 0.628132f, 0.528240f, 0.528240f, 0.000220f, 0.121966f, 0.267882f, 0.146137f, 0.528240f, 0.267882f, 0.267882f, 0.225066f, 0.880881f, 0.880881f, 0.728465f, 0.728465f, 0.728025f, 0.728025f, 0.121966f, 0.000220f, 0.601830f, 0.862188f, 0.862188f, 0.601830f, 0.958162f, 0.958162f, 0.805746f, 0.805746f, 0.728465f, 0.728465f, 0.839796f, 0.839796f, 0.728465f, 0.728465f, 0.839796f, 0.839796f, 0.728465f, 0.728465f, 0.728465f, 0.828357f, 0.802850f, 0.756222f },
  { 0.136684f, 0.136684f, 0.397042f, 0.403326f, 0.533505f, 0.397042f, 0.266863f, 0.036791f, 0.078061f, 0.136684f, 0.096641f, 0.241715f, 0.100553f, 0.100553f, 0.241715f, 0.397042f, 0.136684f, 0.000220f, 0.130399f, 0.972666f, 0.972666f, 0.831505f, 0.872774f, 0.100113f, 0.000220f, 0.000220f, 0.100113f, 0.027978f, 0.074605f, 0.342048f, 0.242155f, 0.242155f, 0.342048f, 0.389116f, 0.342488f, 0.342488f, 0.389116f, 0.466837f, 0.466837f, 0.389556f, 0.389556f },
  { 5, 2, 1, 6, 7, 0, 6, 0, 4, 5, 8, 3, 5, 3, 2, 4, 3, 8, 9, 8, 10, 9, 10, 11, 1, 12, 5, 12, 13, 5, 8, 9, 6, 6, 4, 8, 14, 11, 10, 14, 10, 15, 16, 17, 18, 16, 18, 19, 19, 18, 20, 19, 20, 21, 5, 13, 17, 5, 17, 16, 22, 23, 21, 22, 21, 20, 14, 15, 23, 14, 23, 22 },
  { 0, 0, 1, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0 },
  { 0, 1, 2, 3, 4, 5, 3, 5, 6, 7, 8, 9, 7, 9, 1, 6, 9, 10, 11, 12, 13, 11, 13, 14, 2, 15, 0, 15, 16, 0, 10, 17, 18, 18, 6, 10, 19, 20, 21, 19, 21, 22, 23, 24, 25, 23, 25, 26, 26, 25, 27, 26, 27, 28, 29, 30, 31, 29, 31, 32, 33, 34, 35, 33, 35, 36, 37, 38, 39, 37, 39, 40 }
)
TEST_CUTOUT_PASS_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  { 1.000000f, 0.000000f },
  { 1.000000f, 1.000000f },
  { 1.000000f, 0.121569f },
  { 1.000000f, 1.000000f }
)
TEST_CUTOUT_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  test_material_prefix_cutout_a,
  { 0.976769f, 0.713161f, 0.713161f, 0.976769f, 0.601830f, 0.601830f, 0.601830f, 0.713161f },
  { 0.597267f, 0.597267f, 0.749682f, 0.749682f, 0.597267f, 0.749682f, 0.831064f, 0.831064f },
  { 8, 5, 15, 8, 15, 10, 15, 5, 16, 15, 16, 19, 15, 19, 21, 15, 21, 23 },
  { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 2, 0, 2, 3, 2, 1, 4, 2, 4, 5, 2, 5, 6, 2, 6, 7 }
)
TEST_OPAQUE_CUTOUT_PASS_MACRO_NAME
(
  test_object_prefix_first_object,
  {
    TEST_OPAQUE_DRAW_CALL_MACRO_NAME(test_object_prefix_first_object, test_material_prefix_opaque_b)
    TEST_OPAQUE_DRAW_CALL_MACRO_NAME(test_object_prefix_first_object, test_material_prefix_opaque_a)
    TEST_CUTOUT_DRAW_CALL_MACRO_NAME(test_object_prefix_first_object, test_material_prefix_cutout_a)
  }
)
TEST_ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME({ -1.000000f, -1.000000f, 0.000000f, -1.935218f, 0.000000f, 0.000000f, -1.000000f, 1.000000f, 0.000000f, 1.000000f, 1.000000f, 0.000000f, 1.000000f, -1.000000f, 0.000000f, -1.000000f, 2.170819f, 0.000000f, 1.000000f, 2.170819f, 0.000000f, 1.855214f, 2.170819f, 0.000000f, 1.855214f, 1.000000f, 0.000000f, 1.000000f, 2.764472f, 0.213226f, 1.855214f, 2.764472f, 0.213226f, 1.000000f, -1.000000f, 1.534695f, -1.000000f, -1.000000f, 1.534695f })
TEST_ADDITIVE_PASS_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  { 1.000000f, 1.000000f },
  { 1.000000f, 0.000000f },
  { 1.000000f, 0.035294f }
)
TEST_ADDITIVE_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  test_material_prefix_additive_a,
  { 0.267882f, 0.528240f, 0.528240f, 0.267882f },
  { 0.596826f, 0.596826f, 0.397042f, 0.397042f },
  { 0, 4, 11, 0, 11, 12 },
  { 0, 0, 1, 0, 1, 0 },
  { 0, 1, 2, 0, 2, 3 }
)
TEST_BLENDED_PASS_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  { 1.000000f, 0.000000f },
  { 1.000000f, 0.145098f },
  { 1.000000f, 1.000000f },
  { 1.000000f, 1.000000f }
)
TEST_BLENDED_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_first_object,
  test_material_prefix_blended_a,
  { 0.601390f, 0.529562f, 0.362000f, 0.259635f, 0.499025f, 0.221859f, 0.119494f, 0.075722f, 0.215863f, 0.043992f, 0.000220f },
  { 0.760390f, 0.597267f, 0.658025f, 0.897415f, 0.999780f, 0.598100f, 0.837489f, 0.939854f, 0.999780f, 0.805204f, 0.907569f },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4, 3, 2, 5, 3, 5, 6, 3, 6, 7, 3, 7, 8, 7, 6, 9, 7, 9, 10 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4, 3, 2, 5, 3, 5, 6, 3, 6, 7, 3, 7, 8, 7, 6, 9, 7, 9, 10 }
)
TEST_ADDITIVE_BLENDED_PASS_MACRO_NAME
(
  test_object_prefix_first_object,
  {
    TEST_ADDITIVE_DRAW_CALL_MACRO_NAME(test_object_prefix_first_object, test_material_prefix_additive_a)
    TEST_BLENDED_DRAW_CALL_MACRO_NAME(test_object_prefix_first_object, test_material_prefix_blended_a)
  }
)
TEST_ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME({ -1.000000f, -1.000000f, 0.000000f, 1.000000f, -1.000000f, 0.000000f, 1.000000f, 1.000000f, 0.000000f, -1.000000f, 1.000000f, 0.000000f })
TEST_ADDITIVE_PASS_DATA_MACRO_NAME
(
  test_object_prefix_second_object,
  { 1.000000f, 0.000000f },
  { 1.000000f, 0.145098f },
  { 1.000000f, 1.000000f }
)
TEST_ADDITIVE_DRAW_CALL_DATA_MACRO_NAME
(
  test_object_prefix_second_object,
  test_material_prefix_additive_a,
  { 0.999900f, 0.999900f, 0.000100f, 0.000100f },
  { 0.999900f, 0.000100f, 0.000100f, 0.999900f },
  { 0, 1, 2, 0, 2, 3 },
  { 0, 0, 1, 0, 1, 0 },
  { 0, 1, 2, 0, 2, 3 }
)
TEST_ADDITIVE_BLENDED_PASS_MACRO_NAME
(
  test_object_prefix_second_object,
  {
    TEST_ADDITIVE_DRAW_CALL_MACRO_NAME(test_object_prefix_second_object, test_material_prefix_additive_a)
  }
)
