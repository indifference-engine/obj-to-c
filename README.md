# OBJ to C

Command-line utility to convert OBJ files to C files.

## Usage

`obj_to_c object_prefix_ material_prefix_ NAVIGATION_MATERIAL_PREFIX_ OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME OPAQUE_PASS_DATA_MACRO_NAME OPAQUE_DRAW_CALL_DATA_MACRO_NAME CUTOUT_PASS_DATA_MACRO_NAME CUTOUT_DRAW_CALL_DATA_MACRO_NAME OPAQUE_CUTOUT_PASS_MACRO_NAME OPAQUE_DRAW_CALL_MACRO_NAME CUTOUT_DRAW_CALL_MACRO_NAME ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME ADDITIVE_PASS_DATA_MACRO_NAME ADDITIVE_DRAW_CALL_DATA_MACRO_NAME BLENDED_PASS_DATA_MACRO_NAME BLENDED_DRAW_CALL_DATA_MACRO_NAME ADDITIVE_BLENDED_PASS_MACRO_NAME ADDITIVE_DRAW_CALL_MACRO_NAME BLENDED_DRAW_CALL_MACRO_NAME NAVIGATION_MACRO_NAME LOCATION_LIST_MACRO_NAME LOCATION_MACRO_NAME RED_LIST_MACRO_NAME RED_MACRO_NAME GREEN_LIST_MACRO_NAME GREEN_MACRO_NAME BLUE_LIST_MACRO_NAME BLUE_MACRO_NAME OPACITY_LIST_MACRO_NAME OPACITY_MACRO_NAME path/to/first/include.h path/to/second/include.h < path/to/input.obj > path/to/output.c`

This will output a file similar to the following:

```c
#include "path/to/first/include.h"
#include "path/to/second/include.h"
OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME(
  object_prefix_first_object,
  LOCATION_LIST_MACRO_NAME(LOCATION_MACRO_NAME(1.23f, -8.24f, 12.123f), LOCATION_MACRO_NAME(6.2f, 8.12f, -1.2f))
)
OPAQUE_PASS_DATA_MACRO_NAME
(
  object_prefix_first_object,
  RED_LIST_MACRO_NAME(RED_MACRO_NAME(0.63f), RED_MACRO_NAME(0.215f), RED_MACRO_NAME(0.923f) ),
  GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(0.63f), GREEN_MACRO_NAME(0.215f), GREEN_MACRO_NAME(0.923f) ),
  BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(0.63f), BLUE_MACRO_NAME(0.215f), BLUE_MACRO_NAME(0.923f) )
)
OPAQUE_DRAW_CALL_DATA_MACRO_NAME
(
  object_prefix_first_object,
  material_prefix_opaque_b,
  { 0.267882f, 0.528240f, 0.528240f, 0.267882f, 0.146137f },
  { 0.397042f, 0.397042f, 0.136684f, 0.136684f, 0.266863f },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4 }
)
OPAQUE_DRAW_CALL_DATA_MACRO_NAME
(
  object_prefix_first_object,
  material_prefix_opaque_a,
  { 0.628132f, 0.528240f, 0.528240f, 0.000220f, 0.121966f, 0.267882f, 0.146137f, 0.528240f, 0.267882f, 0.267882f, 0.225066f, 0.880881f, 0.880881f, 0.728465f, 0.728465f, 0.728025f, 0.728025f, 0.121966f, 0.000220f, 0.601830f, 0.862188f, 0.862188f, 0.601830f, 0.958162f, 0.958162f, 0.805746f, 0.805746f, 0.728465f, 0.728465f, 0.839796f, 0.839796f, 0.728465f, 0.728465f, 0.839796f, 0.839796f, 0.728465f, 0.728465f, 0.728465f, 0.828357f, 0.802850f, 0.756222f },
  { 0.136684f, 0.136684f, 0.397042f, 0.403326f, 0.533505f, 0.397042f, 0.266863f, 0.036791f, 0.078061f, 0.136684f, 0.096641f, 0.241715f, 0.100553f, 0.100553f, 0.241715f, 0.397042f, 0.136684f, 0.000220f, 0.130399f, 0.972666f, 0.972666f, 0.831505f, 0.872774f, 0.100113f, 0.000220f, 0.000220f, 0.100113f, 0.027978f, 0.074605f, 0.342048f, 0.242155f, 0.242155f, 0.342048f, 0.389116f, 0.342488f, 0.342488f, 0.389116f, 0.466837f, 0.466837f, 0.389556f, 0.389556f },
  { 5, 2, 1, 6, 7, 0, 6, 0, 4, 5, 8, 3, 5, 3, 2, 4, 3, 8, 9, 8, 10, 9, 10, 11, 1, 12, 5, 12, 13, 5, 8, 9, 6, 6, 4, 8, 14, 11, 10, 14, 10, 15, 16, 17, 18, 16, 18, 19, 19, 18, 20, 19, 20, 21, 5, 13, 17, 5, 17, 16, 22, 23, 21, 22, 21, 20, 14, 15, 23, 14, 23, 22 },
  { 0, 0, 1, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0 },
  { 0, 1, 2, 3, 4, 5, 3, 5, 6, 7, 8, 9, 7, 9, 1, 6, 9, 10, 11, 12, 13, 11, 13, 14, 2, 15, 0, 15, 16, 0, 10, 17, 18, 18, 6, 10, 19, 20, 21, 19, 21, 22, 23, 24, 25, 23, 25, 26, 26, 25, 27, 26, 27, 28, 29, 30, 31, 29, 31, 32, 33, 34, 35, 33, 35, 36, 37, 38, 39, 37, 39, 40 }
)
CUTOUT_PASS_DATA_MACRO_NAME
(
  object_prefix_first_object,
  RED_LIST_MACRO_NAME(RED_MACRO_NAME(0.63f), RED_MACRO_NAME(0.215f), RED_MACRO_NAME(0.923f) ),
  GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(0.63f), GREEN_MACRO_NAME(0.215f), GREEN_MACRO_NAME(0.923f) ),
  BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(0.63f), BLUE_MACRO_NAME(0.215f), BLUE_MACRO_NAME(0.923f) ),
  OPACITY_LIST_MACRO_NAME(OPACITY_MACRO_NAME(0.63f), OPACITY_MACRO_NAME(0.215f), OPACITY_MACRO_NAME(0.923f) )
)
CUTOUT_DRAW_CALL_DATA_MACRO_NAME
(
  object_prefix_first_object,
  material_prefix_cutout_a,
  { 0.976769f, 0.713161f, 0.713161f, 0.976769f, 0.601830f, 0.601830f, 0.601830f, 0.713161f },
  { 0.597267f, 0.597267f, 0.749682f, 0.749682f, 0.597267f, 0.749682f, 0.831064f, 0.831064f },
  { 8, 5, 15, 8, 15, 10, 15, 5, 16, 15, 16, 19, 15, 19, 21, 15, 21, 23 },
  { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 2, 0, 2, 3, 2, 1, 4, 2, 4, 5, 2, 5, 6, 2, 6, 7 }
)
OPAQUE_CUTOUT_PASS_MACRO_NAME
(
  object_prefix_first_object,
  {
    OPAQUE_DRAW_CALL_MACRO_NAME(object_prefix_first_object, material_prefix_opaque_b)
    OPAQUE_DRAW_CALL_MACRO_NAME(object_prefix_first_object, material_prefix_opaque_a)
    CUTOUT_DRAW_CALL_MACRO_NAME(object_prefix_first_object, material_prefix_cutout_a)
  }
)
ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME(
  object_prefix_first_object,
  LOCATION_LIST_MACRO_NAME(LOCATION_MACRO_NAME(1.23f, -8.24f, 12.123f), LOCATION_MACRO_NAME(6.2f, 8.12f, -1.2f))
)
ADDITIVE_PASS_DATA_MACRO_NAME
(
  object_prefix_first_object,
  RED_LIST_MACRO_NAME(RED_MACRO_NAME(0.63f), RED_MACRO_NAME(0.215f), RED_MACRO_NAME(0.923f) ),
  GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(0.63f), GREEN_MACRO_NAME(0.215f), GREEN_MACRO_NAME(0.923f) ),
  BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(0.63f), BLUE_MACRO_NAME(0.215f), BLUE_MACRO_NAME(0.923f) )
)
ADDITIVE_DRAW_CALL_DATA_MACRO_NAME
(
  object_prefix_first_object,
  material_prefix_additive_a,
  { 0.267882f, 0.528240f, 0.528240f, 0.267882f },
  { 0.596826f, 0.596826f, 0.397042f, 0.397042f },
  { 0, 4, 11, 0, 11, 12 },
  { 0, 0, 1, 0, 1, 0 },
  { 0, 1, 2, 0, 2, 3 }
)
BLENDED_PASS_DATA_MACRO_NAME
(
  object_prefix_first_object,
  RED_LIST_MACRO_NAME(RED_MACRO_NAME(0.63f), RED_MACRO_NAME(0.215f), RED_MACRO_NAME(0.923f) ),
  GREEN_LIST_MACRO_NAME(GREEN_MACRO_NAME(0.63f), GREEN_MACRO_NAME(0.215f), GREEN_MACRO_NAME(0.923f) ),
  BLUE_LIST_MACRO_NAME(BLUE_MACRO_NAME(0.63f), BLUE_MACRO_NAME(0.215f), BLUE_MACRO_NAME(0.923f) ),
  OPACITY_LIST_MACRO_NAME(OPACITY_MACRO_NAME(0.63f), OPACITY_MACRO_NAME(0.215f), OPACITY_MACRO_NAME(0.923f) )
)
BLENDED_DRAW_CALL_DATA_MACRO_NAME
(
  object_prefix_first_object,
  material_prefix_blended_a,
  { 0.601390f, 0.529562f, 0.362000f, 0.259635f, 0.499025f, 0.221859f, 0.119494f, 0.075722f, 0.215863f, 0.043992f, 0.000220f },
  { 0.760390f, 0.597267f, 0.658025f, 0.897415f, 0.999780f, 0.598100f, 0.837489f, 0.939854f, 0.999780f, 0.805204f, 0.907569f },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4, 3, 2, 5, 3, 5, 6, 3, 6, 7, 3, 7, 8, 7, 6, 9, 7, 9, 10 },
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 2, 0, 2, 3, 0, 3, 4, 3, 2, 5, 3, 5, 6, 3, 6, 7, 3, 7, 8, 7, 6, 9, 7, 9, 10 }
)
ADDITIVE_BLENDED_PASS_MACRO_NAME
(
  object_prefix_first_object,
  {
    ADDITIVE_DRAW_CALL_MACRO_NAME(object_prefix_first_object, material_prefix_additive_a)
    BLENDED_DRAW_CALL_MACRO_NAME(object_prefix_first_object, material_prefix_blended_a)
  }
)
NAVIGATION_MACRO_NAME
(
  object_prefix_navigation,
  { NAVIGATION_MATERIAL_PREFIX_GRASS },
  { 3 },
  { 0 },
  { 1.0f, 2.0f, 3.0f },
  { 0.0f, 1.0f, 0.0 },
  { -1.0f, 0.0f, 0.0f },
  { 0.0f, 1.0f, 0.0f },
  { 2 },
  { 0 },
  { 0 },
  { 1, 2 }
)
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

Execute `make test` to run the test suite.  Note that this only covers the
command-line executable, NOT any bundled add-ons.

## Blender OBJ Add-On

This add-on can be used in place of Blender's built-in OBJ import/export to add
support for vertex colors and material types.

### Installation

- Download and install [Blender](https://www.blender.org/download/).  The plugin
  was developed using version 4.2.3.  Other versions will likely work.
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
