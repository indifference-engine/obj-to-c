#ifndef REOPEN_AS_READ_ONLY_BINARY_OR_THROW_H

#define REOPEN_AS_READ_ONLY_BINARY_OR_THROW_H

#include <stdio.h>

/**
 * Re-opens a file as read-only binary, halting execution with an error message
 * should the operation fail.
 * @param file The file to re-open as binary.
 */
void reopen_as_read_only_binary_or_throw(FILE *const file);

#endif
