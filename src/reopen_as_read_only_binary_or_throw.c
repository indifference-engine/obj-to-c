#include <stdio.h>
#ifdef __MINGW32__
#include <fcntl.h>
#endif
#include "reopen_as_read_only_binary_or_throw.h"
#include "throw.h"

void reopen_as_read_only_binary_or_throw(FILE *const file)
{
#ifdef __MINGW32__
  if (_setmode(_fileno(file), O_BINARY) == -1)
#else
  if (freopen(NULL, "rb", file) == NULL)
#endif
  {
#ifdef errno
    throw("Failed to re-open a file as read-only binary (errno %d).", errno);
#else
    throw("Failed to re-open a file as read-only binary.");
#endif
  }
}