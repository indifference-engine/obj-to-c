#include <stdlib.h>
#include "materials.h"

int *material_types = NULL;
const char **material_names = NULL;
bool *material_imports = NULL;
size_t *material_name_lengths = NULL;
size_t number_of_materials = 0;
