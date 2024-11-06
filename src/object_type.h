#ifndef OBJECT_TYPE_H

#define OBJECT_TYPE_H

/**
 * No object has been started.
 */
#define OBJECT_TYPE_NONE 0

/**
 * The object can be rendered.
 */
#define OBJECT_TYPE_GRAPHICAL 1

/**
 * The object can be navigated.
 */
#define OBJECT_TYPE_NAVIGATION 2

/**
 * The type of the current object.
 */
extern int object_type;

#endif
