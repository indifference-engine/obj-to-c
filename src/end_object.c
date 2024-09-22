#include <stdlib.h>
#include "end_object.h"
#include "object_name.h"
#include "write_pass.h"
#include "materials.h"
#include "indices.h"
#include "faces.h"
#include "command_line_arguments.h"

void end_object()
{
  if (object_name != NULL)
  {
    write_pass(
        opaque_cutout_pass_data_macro_name,
        MATERIAL_TYPE_OPAQUE, opaque_pass_data_macro_name, opaque_draw_call_data_macro_name,
        MATERIAL_TYPE_CUTOUT, cutout_pass_data_macro_name, cutout_draw_call_data_macro_name,
        opaque_cutout_pass_macro_name, opaque_draw_call_macro_name, cutout_draw_call_macro_name);

    write_pass(
        additive_blended_pass_data_macro_name,
        MATERIAL_TYPE_ADDITIVE, additive_pass_data_macro_name, additive_draw_call_data_macro_name,
        MATERIAL_TYPE_BLENDED, blended_pass_data_macro_name, blended_draw_call_data_macro_name,
        additive_blended_pass_macro_name, additive_draw_call_macro_name, blended_draw_call_macro_name);

    if (number_of_indices)
    {
      free(index_v);
      index_v = NULL;
      free(index_vt);
      index_vt = NULL;
      number_of_indices = 0;
    }

    if (number_of_faces)
    {
      free(face_lengths);
      face_lengths = NULL;
      free(face_materials);
      face_materials = NULL;
      number_of_faces = 0;
    }

    free(object_name);
    object_name = NULL;
    object_name_length = 0;
  }
}
