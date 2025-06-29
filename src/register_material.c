#include "register_material.h"
#include "current_material.h"
#include "malloc_or_throw.h"
#include "material_name.h"
#include "materials.h"
#include "realloc_or_throw.h"
#include "throw.h"
#include <string.h>

void register_material(void) {
  for (size_t index = 0; index < number_of_materials; index++) {
    if (material_name_lengths[index] == material_name_length) {
      if (strcmp(material_name, material_names[index]) == 0) {
        current_material = index;
        return;
      }
    }
  }

  int material_type;

  if (material_name_length > 7 && strncmp("opaque_", material_name, 7) == 0) {
    material_type = MATERIAL_TYPE_OPAQUE;
  } else if (material_name_length > 7 &&
             strncmp("cutout_", material_name, 7) == 0) {
    material_type = MATERIAL_TYPE_CUTOUT;
  } else if (material_name_length > 9 &&
             strncmp("additive_", material_name, 9) == 0) {
    material_type = MATERIAL_TYPE_ADDITIVE;
  } else if (material_name_length > 8 &&
             strncmp("blended_", material_name, 8) == 0) {
    material_type = MATERIAL_TYPE_BLENDED;
  } else if (material_name_length > 11 &&
             strncmp("navigation_", material_name, 11) == 0) {
    material_type = MATERIAL_TYPE_NAVIGATION;
  } else {
    throw("Unable to determine type of material \"%s\".", material_name);
  }

  current_material = number_of_materials;

  if (number_of_materials) {
    material_types = realloc_or_throw(material_types,
                                      sizeof(int) * (number_of_materials + 1));
    material_types[number_of_materials] = material_type;
    material_names = realloc_or_throw(
        material_names, sizeof(const char *) * (number_of_materials + 1));
    material_names[number_of_materials] = material_name;
    material_name_lengths = realloc_or_throw(
        material_name_lengths, sizeof(size_t) * (number_of_materials + 1));
    material_name_lengths[number_of_materials] = material_name_length;
    number_of_materials++;
  } else {
    material_types = malloc_or_throw(sizeof(int));
    material_types[0] = material_type;
    material_names = malloc_or_throw(sizeof(const char *));
    material_names[0] = material_name;
    material_name_lengths = malloc_or_throw(sizeof(size_t));
    material_name_lengths[0] = material_name_length;
    number_of_materials = 1;
  }

  material_name = NULL;
  material_name_length = 0;
}
