#include "write_or_throw.h"
#include "throw.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void write_or_throw(FILE *const file, const char *const fmt, ...) {
  va_list args;
  va_start(args, fmt);

  if (vfprintf(file, fmt, args) < 0) {
    throw("Failed to write.");
  }

  va_end(args);
}
