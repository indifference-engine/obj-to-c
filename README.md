# OBJ to C

Command-line utility to convert OBJ files to C files.

## Usage

`obj_to_c MESH_MACRO_NAME MATERIAL_PREFIX_ path/to/first/include.h path/to/second/include.h < path/to/input.obj > path/to/output.c`

This will output a file similar to the following:

```c
#include "path/to/first/include.h"
#include "path/to/second/include.h"

MESH_MACRO_NAME
(
  object_name,

  // Number of vertices for opaque and cutout geometry.
  4,

  // Location of each vertex for opaque and cutout geometry on the X axis.
  { -2.4f, 8.2f, 1.3f, 4.5f },

  // Location of each vertex for opaque and cutout geometry on the Y axis.
  { 3.1f, -2.9f, 8.5f, 6.4f },

  // Location of each vertex for opaque and cutout geometry on the Z axis.
  { 2.6f, 3.1f, -1.1f, 0.5f },

  // Number of opaque render passes.
  2,

  // Materials of opaque render passes.
  { MATERIAL_PREFIX_a, MATERIAL_PREFIX_b },

  // Number of triangles per opaque render pass.
  { 2, 3 },

  // A vertex index for each vertex of each triangle of each opaque render pass.
  {
    0, 1, 2,
    2, 3, 0,

    2, 1, 0,
    3, 1, 0,
    2, 0, 1,
  },

  // The number of texture widths between the left of the texture and the point
  // to sample for each vertex of each triangle of each opaque render pass.
  {
    0.2f, 1.4f, 0.3f,
    -0.4f, 10.0f, 4.2f,

    4.1f, 6.2f, 3.0f,
    -4.8f, -5.5f, 7.9f,
    12.3f, -4.1f, 0.1f,
  },

  // The number of texture heights between the top of the texture and the point
  // to sample for each vertex of each triangle of each opaque render pass.
  {
    6.3f, -1.1f, 0.9f,
    12.4f, 8.3f, 2.1f,

    6.8f, -5.6f, -3.0f,
    0.0f, -7.3f, 12.7f,
    -14.8f, 12.3f, 18.4f,
  },

  // The intensity of the red channel for each vertex of each triangle of each
  // opaque render pass, as a non-linearized unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the green channel for each vertex of each triangle of each
  // opaque render pass, as a non-linearized unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the blue channel for each vertex of each triangle of each
  // opaque render pass, as a non-linearized unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // Number of cutout render passes.
  2,

  // Materials of cutout render passes.
  { MATERIAL_PREFIX_a, MATERIAL_PREFIX_b },

  // Number of triangles per cutout render pass.
  { 2, 3 },

  // A vertex index for each vertex of each triangle of each cutout render pass.
  {
    0, 1, 2,
    2, 3, 0,

    2, 1, 0,
    3, 1, 0,
    2, 0, 1,
  },

  // The number of texture widths between the left of the texture and the point
  // to sample for each vertex of each triangle of each cutout render pass.
  {
    0.2f, 1.4f, 0.3f,
    -0.4f, 10.0f, 4.2f,

    4.1f, 6.2f, 3.0f,
    -4.8f, -5.5f, 7.9f,
    12.3f, -4.1f, 0.1f,
  },

  // The number of texture heights between the top of the texture and the point
  // to sample for each vertex of each triangle of each cutout render pass.
  {
    6.3f, -1.1f, 0.9f,
    12.4f, 8.3f, 2.1f,

    6.8f, -5.6f, -3.0f,
    0.0f, -7.3f, 12.7f,
    -14.8f, 12.3f, 18.4f,
  },

  // The intensity of the red channel for each vertex of each triangle of each
  // cutout render pass, as a non-linearized unit interval, not pre-multiplied
  // by opacity.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the green channel for each vertex of each triangle of each
  // cutout render pass, as a non-linearized unit interval, not pre-multiplied
  // by opacity.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the blue channel for each vertex of each triangle of each
  // cutout render pass, as a non-linearized unit interval, not pre-multiplied
  // by opacity.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The opacity of each vertex of each triangle of each cutout render pass, as
  // a unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // Number of vertices for additive and blended geometry.
  4,

  // Location of each vertex for additive and blended geometry on the X axis.
  { -2.4f, 8.2f, 1.3f, 4.5f },

  // Location of each vertex for additive and blended geometry on the Y axis.
  { 3.1f, -2.9f, 8.5f, 6.4f },

  // Location of each vertex for additive and blended geometry on the Z axis.
  { 2.6f, 3.1f, -1.1f, 0.5f },

  // Number of additive render passes.
  2,

  // Materials of additive render passes.
  { MATERIAL_PREFIX_a, MATERIAL_PREFIX_b },

  // Number of triangles per additive render pass.
  { 2, 3 },

  // A vertex index for each vertex of each triangle of each additive render
  // pass.
  {
    0, 1, 2,
    2, 3, 0,

    2, 1, 0,
    3, 1, 0,
    2, 0, 1,
  },

  // The number of texture widths between the left of the texture and the point
  // to sample for each vertex of each triangle of each additive render pass.
  {
    0.2f, 1.4f, 0.3f,
    -0.4f, 10.0f, 4.2f,

    4.1f, 6.2f, 3.0f,
    -4.8f, -5.5f, 7.9f,
    12.3f, -4.1f, 0.1f,
  },

  // The number of texture heights between the top of the texture and the point
  // to sample for each vertex of each triangle of each additive render pass.
  {
    6.3f, -1.1f, 0.9f,
    12.4f, 8.3f, 2.1f,

    6.8f, -5.6f, -3.0f,
    0.0f, -7.3f, 12.7f,
    -14.8f, 12.3f, 18.4f,
  },

  // The intensity of the red channel for each vertex of each triangle of each
  // additive render pass, as a non-linearized unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the green channel for each vertex of each triangle of each
  // additive render pass, as a non-linearized unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the blue channel for each vertex of each triangle of each
  // additive render pass, as a non-linearized unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // Number of blended render passes.
  2,

  // Materials of blended render passes.
  { MATERIAL_PREFIX_a, MATERIAL_PREFIX_b },

  // Number of triangles per blended render pass.
  { 2, 3 },

  // A vertex index for each vertex of each triangle of each blended render pass.
  {
    0, 1, 2,
    2, 3, 0,

    2, 1, 0,
    3, 1, 0,
    2, 0, 1,
  },

  // The number of texture widths between the left of the texture and the point
  // to sample for each vertex of each triangle of each blended render pass.
  {
    0.2f, 1.4f, 0.3f,
    -0.4f, 10.0f, 4.2f,

    4.1f, 6.2f, 3.0f,
    -4.8f, -5.5f, 7.9f,
    12.3f, -4.1f, 0.1f,
  },

  // The number of texture heights between the top of the texture and the point
  // to sample for each vertex of each triangle of each blended render pass.
  {
    6.3f, -1.1f, 0.9f,
    12.4f, 8.3f, 2.1f,

    6.8f, -5.6f, -3.0f,
    0.0f, -7.3f, 12.7f,
    -14.8f, 12.3f, 18.4f,
  },

  // The intensity of the red channel for each vertex of each triangle of each
  // blended render pass, as a non-linearized unit interval, not pre-multiplied
  // by opacity.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the green channel for each vertex of each triangle of each
  // blended render pass, as a non-linearized unit interval, not pre-multiplied
  // by opacity.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The intensity of the blue channel for each vertex of each triangle of each
  // blended render pass, as a non-linearized unit interval, not pre-multiplied
  // by opacity.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },

  // The opacity of each vertex of each triangle of each blended render pass, as
  // a unit interval.
  {
    0.3f, 0.1f, 0.9f,
    0.4f, 0.3f, 0.1f,

    0.8f, 0.6f, 0.0f,
    0.0f, 0.3f, 0.7f,
    0.8f, 0.3f, 1.0f,
  },
);
```

### Material Mapping

All faces of all meshes must have a material.

All materials must have one of the following prefixes, which will be excluded
from the generated code:

| Prefix      | Description                                                                                                                                                                                      |
| ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `opaque_`   | Geometry which is fully solid.                                                                                                                                                                   |
| `cutout_`   | Geometry which is fully solid except where the opacity falls below 0.5, where it is instead fully transparent.                                                                                   |
| `additive_` | Geometry which is drawn by adding its color to the previously drawn geometry covering the same pixels.  Equivalent to a "linear dodge" layer in some graphics applications.                      |
| `blended_`  | Geometry which is drawn by mixing its color with the previously drawn geometry covering the same pixels.  May draw in the wrong order when mixed with `additive_` or other `blended_` materials. |

## Building

Execute `make` to build the executable, which will be placed at
[dist/obj_to_c](./dist/obj_to_c).

### Dependencies

- Make.
- MinGW-GCC for Windows, Clang for all other platforms.
- Bash.

## Tests

Execute `make test` to run the test suite.
