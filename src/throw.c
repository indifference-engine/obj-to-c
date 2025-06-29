#include "throw.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((noreturn)) void throw(const char *const fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fprintf(stderr, "\n");
  exit(1);
}
