#include <string.h>
#include "object_name.h"
#include "object_type.h"
#include "determine_object_type.h"

void determine_object_type(void)
{
  if (object_name_length > 11 && strncmp("navigation_", object_name, 11) == 0)
  {
    object_type = OBJECT_TYPE_NAVIGATION;
  }
  else
  {
    object_type = OBJECT_TYPE_GRAPHICAL;
  }
}
