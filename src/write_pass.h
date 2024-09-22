#ifndef WRITE_PASS_H

#define WRITE_PASS_H

/**
 * Writes a pass of the current object to the output.
 * @param pass_macro_data_name The name of a macro which declares data for a
 *                             pass (XYZ) (e.g. MACRO(object_name, { 1.0f, 2.0f,
 *                             3.0f })).
 * @param first_material_type The first material type to include in the pass.
 * @param first_material_type_pass_data_macro_name The name of a macro which
 *                                                 declares data for a pass of
 *                                                 the first material type (R,
 *                                                 G, B, O) (e.g. MACRO(
 *                                                 object_name, { 1.0f },
 *                                                 { 1.0f }, { 1.0f },
 *                                                 { 1.0f })).
 * @param first_material_type_draw_call_data_macro_name The name of a macro
 *                                                      which declares data for
 *                                                      a draw call of the first
 *                                                      material type (V, U, XYZ
 *                                                      indices, RGB indices, VU
 *                                                      indices) (e.g. MACRO(
 *                                                      object_name,
 *                                                      material_name, { 1.0f },
 *                                                      { 1.0f }, { 0, 1, 2 },
 *                                                      { 0, 1, 2 },
 *                                                      { 0, 1, 2 })).
 * @param second_material_type The second material type to include in the pass.
 * @param second_material_type_pass_data_macro_name The name of a macro which
 *                                                 declares data for a pass of
 *                                                 the second material type (R,
 *                                                 G, B, O) (e.g. MACRO(
 *                                                 object_name, { 1.0f },
 *                                                 { 1.0f }, { 1.0f },
 *                                                 { 1.0f })).
 * @param second_material_type_draw_call_data_macro_name The name of a macro
 *                                                       which declares data for
 *                                                       a draw call of the
 *                                                       second material type
 *                                                       (V, U, XYZ indices, RGB
 *                                                       indices, VU indices)
 *                                                       (e.g. MACRO(
 *                                                       object_name,
 *                                                       material_name,
 *                                                       { 1.0f }, { 1.0f },
 *                                                       { 0, 1, 2 },
 *                                                       { 0, 1, 2 },
 *                                                       { 0, 1, 2 })).
 * @param pass_macro_name The name of a macro which declares a pass (e.g. MACRO(
 *                        object_name, { (draw calls) })).
 * @param first_material_type_draw_call_macro_name The name of a macro which
 *                                                 declares a draw call of the
 *                                                 first material type (e.g.
 *                                                 MACRO(object_name,
 *                                                 material_name)).
 * @param second_material_type_draw_call_macro_name The name of a macro which
 *                                                  declares a draw call of the
 *                                                  second material type (e.g.
 *                                                  MACRO(object_name,
 *                                                  material_name)).
 */
void write_pass(
    const char *const pass_macro_data_name,
    const int first_material_type,
    const char *const first_material_type_pass_data_macro_name,
    const char *const first_material_type_draw_call_data_macro_name,
    const int second_material_type,
    const char *const second_material_type_pass_data_macro_name,
    const char *const second_material_type_draw_call_data_macro_name,
    const char *const pass_macro_name,
    const char *const first_material_type_draw_call_macro_name,
    const char *const second_material_type_draw_call_macro_name);

#endif
