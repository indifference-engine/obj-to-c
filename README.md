# OBJ to C

Command-line utility to convert OBJ files to C files.

## Usage

`obj_to_c object_prefix_ material_prefix_ NAVIGATION_MATERIAL_PREFIX_ OPAQUE_CUTOUT_PASS_DATA_MACRO_NAME OPAQUE_PASS_DATA_MACRO_NAME OPAQUE_DRAW_CALL_DATA_MACRO_NAME CUTOUT_PASS_DATA_MACRO_NAME CUTOUT_DRAW_CALL_DATA_MACRO_NAME OPAQUE_CUTOUT_PASS_MACRO_NAME OPAQUE_PREPARATION_MACRO_NAME CUTOUT_PREPARATION_MACRO_NAME OPAQUE_DRAW_CALL_MACRO_NAME CUTOUT_DRAW_CALL_MACRO_NAME ADDITIVE_BLENDED_PASS_DATA_MACRO_NAME ADDITIVE_PASS_DATA_MACRO_NAME ADDITIVE_DRAW_CALL_DATA_MACRO_NAME BLENDED_PASS_DATA_MACRO_NAME BLENDED_DRAW_CALL_DATA_MACRO_NAME ADDITIVE_BLENDED_PASS_MACRO_NAME ADDITIVE_PREPARATION_MACRO_NAME BLENDED_PREPARATION_MACRO_NAME ADDITIVE_DRAW_CALL_MACRO_NAME BLENDED_DRAW_CALL_MACRO_NAME NAVIGATION_MACRO_NAME LOCATION_LIST_MACRO_NAME LOCATION_MACRO_NAME OPACITY_LIST_MACRO_NAME OPACITY_MACRO_NAME RED_LIST_MACRO_NAME RED_MACRO_NAME GREEN_LIST_MACRO_NAME GREEN_MACRO_NAME BLUE_LIST_MACRO_NAME BLUE_MACRO_NAME V_LIST_MACRO_NAME V_MACRO_NAME U_LIST_MACRO_NAME U_MACRO_NAME LOCATION_INDEX_TRIANGLE_LIST_MACRO_NAME LOCATION_INDEX_TRIANGLE_MACRO_NAME LOCATION_INDEX_MACRO_NAME COLOR_INDEX_TRIANGLE_LIST_MACRO_NAME COLOR_INDEX_TRIANGLE_MACRO_NAME COLOR_INDEX_MACRO_NAME VU_INDEX_TRIANGLE_LIST_MACRO_NAME VU_INDEX_TRIANGLE_MACRO_NAME VU_INDEX_MACRO_NAME FACE_VERTEX_COUNT_LIST_MACRO_NAME FACE_VERTEX_COUNT_MACRO_NAME FACE_VERTEX_OFFSET_LIST_MACRO_NAME FACE_VERTEX_OFFSET_MACRO_NAME FACE_VERTEX_LOCATION_LIST_NAME LOCATION_FACE_MACRO_NAME NORMAL_LIST_MACRO_NAME FACE_EDGE_EXIT_NORMAL_LIST_MACRO_NAME FACE_EDGE_NORMAL_LIST_MACRO_NAME FACE_VERTEX_UP_NORMAL_LIST_MACRO_NAME NORMAL_MACRO_NAME NEIGHBOR_COUNT_LIST_LIST_MACRO_NAME NEIGHBOR_COUNT_LIST_MACRO_NAME NEIGHBOR_COUNT_MACRO_NAME FACE_EDGE_OFFSET_LIST_MACRO_NAME FACE_EDGE_NEIGHBOR_OFFSET_LIST_MACRO_NAME OFFSET_LIST_LIST_MACRO_NAME OFFSET_LIST_MACRO_NAME OFFSET_MACRO_NAME FACE_INDEX_LIST_LIST_LIST_MACRO_NAME FACE_INDEX_LIST_LIST_MACRO_NAME FACE_EDGE_NEIGHBOR_FACE_INDEX_LIST_MACRO_NAME FACE_INDEX_MACRO_NAME MATERIAL_LIST_MACRO_NAME MATERIAL_IMPORT_MACRO_NAME path/to/first/include.h path/to/second/include.h < path/to/input.obj > path/to/output.c`

This will produce a file similar to
[the example](./tests/cases/example/expected.c).

### Material mapping

All materials must have one of the following prefixes, which will be excluded
from the generated code:

| Prefix      | Description                                                                                                                                                                                      |
| ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `opaque_`   | Geometry which is fully solid.                                                                                                                                                                   |
| `cutout_`   | Geometry which is fully solid except where the opacity falls below 0.5, where it is instead fully transparent.                                                                                   |
| `additive_` | Geometry which is drawn by adding its color to the previously drawn geometry covering the same pixels.  Equivalent to a "linear dodge" layer in some graphics applications.                      |
| `blended_`  | Geometry which is drawn by mixing its color with the previously drawn geometry covering the same pixels.  May draw in the wrong order when mixed with `additive_` or other `blended_` materials. |

Note that navigation objects use materials prefixed `navigation_` instead of the
above list (see below).

### Vertex color

OBJ exporters may include vertex color as part of their vertex definitions:

```obj
v x y z red green blue opacity
```

For example:

```obj
v 18.3, -17.9, 22.1, 0.3, 0.9, 1, 0.24
```

Where these are not supplied, red, green, blue and opacity are assumed to be 1.

### Draw Calls

Faces within an object are split into two groups of draw calls:

- Depth-writing (opaque and cutout materials).
- Non-depth-writing (additive and blended materials).

They are additionally grouped by material within those groups to minimize
unnecessary state switches.

### Navigation objects

While every object featuring a name __not__ prefixed with `navigation_` is
considered a "graphical" object, those featuring names prefixed with
`navigation_` are considered to be navigation objects, which instead describe
surfaces on which agents are able to roam.

#### Neighbors

The exported data includes a list of which edges of which faces neighbor which
faces.  A face may have more than one neighbor on the same edge, to account for
cases in which agents may have a choice of faces to cross onto (for example,
ramps with a high and low exit route depending upon agent behavior).

#### Normals

While each face has a self-explanatory surface normal, there are two other types
of exported normal which are more complex in nature.

##### Edge exit normals

Each edge of each face features a normal pointing outwards and (mostly)
perpendicular to the surface normal which defines the "plane" of that edge.

Where the edge does not feature any neighboring faces, this can be used as a
"wall" for collision purposes.

Where the edge features one or more neighboring faces, on the other hand, this
should be used as the boundary to cross to reach them.  The exit normal may not
be perpendicular to the face's surface normal in this scenario as it must be
coplanar with those of all neighboring faces.

##### Edge normals

Similar to edge exit normals, but calculated in ignorance of any neighboring
faces.

##### Vertex up normals

Each vertex of each face features a normal pointing perpendicularly to the edge
exit normals either side of it.  It will generally be similar to the face's
surface normal.

This is intended to be used for cases where agents collide with corners and an
iteration cap on crossing face boundaries has been met (to ensure that the agent
cannot escape the "volume" implied by the face).

#### Navigation materials

Each face of a navigation object must feature a material, named with a
`navigation_` prefix.  These are intended to convey some kind of meaning to the
consuming application, e.g. surface types for physics, sound and particle
effects.

#### Look-up indices

As the data structure in the consuming application is assumed to be flat, fast
look-up indices are provided.  These include:

- The number of edges preceding each face (e.g. for 3, 5 and 4 vertex faces,
  these would be 0, 3 and 8).
- The number of neighboring faces preceding each edge (e.g. for faces with
  neighbor counts (3, 5, 4) and (1, 0, 2), these would be (0, 3, 8) and (12, 13,
  13).

## Additional validation rules

### Non-planar faces

All faces must be planar (i.e. flat).  Triangulate your objects should they fall
afoul of this.

### Concave face perimeters

All faces must have convex perimeters (though they may have any number of
sides).  Most editors' triangulation features will automatically fix non-convex
faces.

### Degenerate faces

No faces may have more than one vertex in the same location.

### Overlapping faces

No two faces in the same object may share more than two vertices, even if they
face opposite directions.

### Non-navigation specific

The following validation rules apply to all non-navigation objects.

#### Texture coordinates

Every vertex of every face in every non-navigation object must feature a texture
coordinate.

### Navigation specific

#### Coplanar neighbors facing backwards

Faces which are coplanar with their neighbors but face the opposite direction
will fail to generate valid edge exit normals.  Most editors feature a
"recalculate normals" feature which will fix this should it occur.

## Limitations

### Ignored features

The following features are completely ignored by the command-line utility:

- MTLLib directives and files.
- Texture coordinates in navigation objects.
- Vertex colors in navigation objects.

### Compatibility

The command-line utility is unlikely to be able to read all valid OBJ files due
to several missing features.  Details on these missing test features can be
found in the
[issue tracker](https://github.com/indifference-engine/obj-to-c/issues).

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

Test coverage is currently implemented only for some simple scenarios; most
complex error handling is currently uncovered.  Details on these missing test
cases can be found in the
[issue tracker](https://github.com/indifference-engine/obj-to-c/issues).

## Blender add-on

This add-on can be used in place of Blender's built-in OBJ import/export to add
support for vertex colors and material types.

### Installation

- Download and install [Blender](https://www.blender.org/download/).  The add-on
  was developed using version 4.2.3.  Other versions will likely work.
- Open Blender.
- From the menu bar, select "Edit" > "Preferences".
- A "Blender Preferences" window will open.
- Select the "Add-ons" tab from the left.
- Click the `\/` in the top right corner.
- Click the "Install from Disk..." button in the top right corner.
- Select the [indifference-engine-obj.py](./indifference-engine-obj.py) file.

### Usage

#### Importing OBJ files into Blender

Select `File` > `Import` > `Indifference Engine OBJ (*.obj)`.  This will prompt
for an OBJ file to import.

This will add to the content of the current scene and configure Blender to
display assets similarly to Indifference Engine.

#### Creating navigation objects

Select `Add` > `Indifference Engine` > `Navigation Object` from the menu bar.

A new plane with an appropriate name will be added to the scene, selected, and
the camera will focus upon it.

This will also configure Blender to display assets similarly to Indifference
Engine.

#### Creating new materials

Select `Add` > `Indifference Engine` > `Material` from the menu bar and select
the appropriate material type.

You will then be prompted for a TGA file.  If no material of the specified type
exists for the TGA file, one is created using the name of the TGA file excluding
its file extension and the selected TGA file as a base color.  It will be
prefixed with the material type.

If an object other than a navigation object is selected and no material slot
uses that TGA file, the material found or created above is added to a new slot.

These materials must not be applied to navigation objects.

This will also configure Blender to display assets similarly to Indifference
Engine and create a color attribute if it is missing from the object.

##### Creating new materials for navigation objects

Select `Add` > `Indifference Engine` > `Material` > `Navigation Object` from the
menu bar.

This will create a new red navigation material.

If a navigation object is selected, the material created is added to a new slot.

The color can be changed from the material properties pane (`Emission` shader >
`Color`).

#### Exporting OBJ files from Blender

Select `File` > `Export` > `Indifference Engine OBJ (*.obj)`.  This will prompt
for the file path to export to, overwriting if it already exists.  A MTLLIB file
will also be exported at the same time.

#### Limitations

- This add-on will export all objects from the current scene, even if they are
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
- The add-on's import feature is currently intended only to be able to read OBJ
  files exported by the same add-on.  It may work for files written by hand or
  exported from other tools, but is unlikely to.
- Blender at the time of writing does not import opacity values from indexed TGA
  files.  Transparent areas will instead be rendered black.  This has been
  confirmed to be expected behavior by the developers and is unlikely to be
  changed as a consequence.

##### Non-navigation objects

- Only exactly one UV map is supported.
- Only exactly one color attribute is supported.
