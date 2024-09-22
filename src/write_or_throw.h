#ifndef WRITE_OR_THROW_H

#define WRITE_OR_THROW_H

/**
 * Writes a string to a file, halting execution with an error message should the
 * operation fail.
 * @param file The file to which to write.
 * @param fmt The format of the string.
 * @param ... Variables to be substituted into the string.
 */
void write_or_throw(FILE *const file, const char *const fmt, ...);

#endif
