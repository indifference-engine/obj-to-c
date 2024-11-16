#include <stdlib.h>
#include "materials.h"

const int material_type_name_offsets[] = {
    7,
    7,
    9,
    8,
    11};

int *material_types = NULL;
const char **material_names = NULL;
size_t *material_name_lengths = NULL;
size_t number_of_materials = 0;
