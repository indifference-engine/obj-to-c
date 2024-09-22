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

### Vertex Color

OBJ exporters may include vertex color as part of their vertex definitions:

```obj
v x y z red green blue opacity
```

For example:

```obj
v 18.3, -17.9, 22.1, 0.3, 0.9, 1, 0.24
```

Where these are not supplied, red, green, blue and opacity are assumed to be 1.

## Building

Execute `make` to build the executable, which will be placed at
[dist/obj_to_c](./dist/obj_to_c).

### Dependencies

- Make.
- MinGW-GCC for Windows, Clang for all other platforms.
- Bash.

## Tests

Execute `make test` to run the test suite.

## Blender OBJ Add-On

This add-on can be used in place of Blender's built-in OBJ import/export to add
support for vertex colors and material types.

### Installation

- Download and install [Blender](https://www.blender.org/download/).  The plugin
  was developed using version 3.6.5.  Other versions will likely work.
- Open Blender.
- From the menu bar, select "Edit" > "Preferences".
- A "Blender Preferences" window will open.
- Select the "Add-ons" tab from the left.
- Click the "Install..." button in the top right corner.
- Select the [indifference-engine-obj.py](./indifference-engine-obj.py) file.
- Tick the checkbox left of the "Import-Export: Indifference Engine OBJ" which
  appears.

### Usage

#### Importing OBJ files into Blender

Select `File` > `Import` > `Indifference Engine OBJ (*.obj)`.  This will prompt
for an OBJ file (and corresponding MTLLIB file) to import.

This will add to the content of the current scene and configure Blender to
display assets similarly to Indifference Engine.

#### Creating navigation meshes

Select `Add` > `Indifference Engine` > `Navigation Mesh` from the menu bar.

A new plane with an appropriate name will be added to the scene, selected, and
the camera will focus upon it.

This will also configure Blender to display assets similarly to Indifference
Engine.

#### Creating new materials

Select `Add` > `Indifference Engine` > `Material` from the menu bar and select
the appropriate material type:

| Type     | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Opaque   | Solid geometry.  Should be used for all surfaces not matching any of the below.                                                                                                                                                                                                                                                                                                                                                                                                         |
| Cutout   | Similar to "Opaque", but where any opacity values below 50% are fully transparent, with a hard edge.  Useful for grates, fences, foliage, etc.  Prefer over "Blended" where possible.                                                                                                                                                                                                                                                                                                   |
| Blended  | Blends between the surface and those behind it (similar to the "Normal" layer blend mode in Adobe Photoshop).  May draw in the wrong order if layered with "Blended" or "Additive" materials.  Useful for smoke, glass, etc.                                                                                                                                                                                                                                                            |
| Additive | Brightens the background (similar to the "Linear Dodge (Add)" layer blend mode in Adobe Photoshop).  May draw in the wrong order if layered together with "Blended" materials, but _will_ combine correctly with "Opaque", "Cutout" and/or "Additive" materials.  Useful for lasers, lens flares, flames, explosions, muzzle flashes, etc.  Note that if your game has a transparent background, additive blending on top of areas of partial or complete transparency is not possible. |

You will then be prompted for a TGA file.  If no material of the specified type
exists for the TGA file, one is created using the name of the TGA file excluding
its file extension and the selected TGA file as a base color.  It will be
prefixed with the material type.

If an object other than a navigation mesh is selected and no material slot
uses that TGA file, the material found or created above is added to a new slot.

These materials must not be applied to navigation meshes.

This will also configure Blender to display assets similarly to Indifference
Engine.

##### Creating new materials for navigation meshes

Select `Add` > `Indifference Engine` > `Material` > `Navigation Mesh` from the
menu bar.

This will create a new red navigation material.

If a navigation mesh is selected, the material created is added to a new slot.

The color can be changed from the material properties pane (`Emission` shader
> `Color`).

#### Exporting OBJ files from Blender

Select `File` > `Export` > `Indifference Engine OBJ (*.obj)`.  This will prompt
for the file path to export to, overwriting if it already exists.  A MTLLIB file
will also be exported at the same time.

### Limitations

- This plugin will export all objects from the current scene, even if they are
  hidden.
- It will NOT apply any transformations; any moving, rotating,
  scaling etc. of objects will NOT be applied.
- Modifiers will NOT be applied (e.g. mirror modifiers).
- Shape keys are NOT supported.
- Non-mesh objects will NOT be exported.
- All object and material names must start with a lower case letter, and all
  following characters must be lower case letters, digits or underscores.
- All texture names must start with a lower case letter, and all following
  characters must be lower case letters, digits or underscores, until the ending
  `.tga`.
- All textures must be in the same directory as the OBJ file or a subdirectory.
- Detached vertices and edges are not permitted.
- All mesh objects must have at least one face.

#### Meshes

- Each face must have a non-navigation material applied.
- Only exactly one UV map is supported.
- Only exactly one color attribute is supported.

#### Navigation Meshes

- Each face must have a navigation material applied.
- UV maps are NOT supported.
- Color attributes are NOT supported.
- All faces must be convex.
- All faces must be planar.
