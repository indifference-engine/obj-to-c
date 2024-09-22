bl_info = {
    "name": "Indifference Engine OBJ",
    "author": "siliconspecter",
    "version": (0, 0, 0),
    "blender": (3, 6, 5),
    "location": "File > Import-Export",
    "description": "Import-Export OBJ files from/to Indifference Engine",
    "category": "Import-Export",
}

import bpy
from re import match, sub
from os import path
from bpy.utils import register_class, unregister_class
from bpy.types import (
    Operator,
    VIEW3D_MT_add,
    TOPBAR_MT_file_import,
    TOPBAR_MT_file_export,
    Menu,
)
from bpy_extras.io_utils import ExportHelper, ImportHelper


def initialize_scene(context):
    context.scene.render.engine = "BLENDER_EEVEE"
    context.scene.eevee.taa_render_samples = 1
    context.scene.eevee.taa_samples = 1
    context.scene.view_settings.view_transform = "Standard"
    context.scene.render.resolution_x = 320
    context.scene.render.resolution_y = 240

    for window in context.window_manager.windows:
        for area in window.screen.areas:
            if area.type == "VIEW_3D":
                for space in area.spaces:
                    if space.type == "VIEW_3D":
                        space.shading.type = "MATERIAL"


def configure_as_navigation_mesh(obj):
    wireframe = obj.modifiers.new("Wireframe", "WIREFRAME")
    wireframe.thickness = 0.05
    wireframe.use_replace = False
    wireframe.show_in_editmode = True


def get_material_type_from_name(name):
    if name.startswith("cutout_"):
        return "cutout"
    elif name.startswith("blended_"):
        return "blended"
    elif name.startswith("additive_"):
        return "additive"
    else:
        return "opaque"


def create_material(name, texture_path):
    output = None
    type = get_material_type_from_name(name)

    for material_candidate in bpy.data.materials:
        if get_material_type_from_name(material_candidate.name) == type:
            if material_candidate.use_nodes:
                for node in material_candidate.node_tree.nodes:
                    if node.type == "TEX_IMAGE":
                        if (
                            node.image is not None
                            and node.image.filepath == texture_path
                        ):
                            output = material_candidate

    if output is None:
        if bpy.data.materials.get(name):
            index = 2

            while bpy.data.materials.get(name + "_" + str(index)):
                index += 1

            name = name + "_" + str(index)

        output = bpy.data.materials.new(name)

        output.use_nodes = True

        output_node = None

        for node in output.node_tree.nodes:
            if node.type == "OUTPUT_MATERIAL":
                output_node = node
            else:
                output.node_tree.nodes.remove(node)

        match type:
            case "opaque":
                vertex_color = output.node_tree.nodes.new("ShaderNodeVertexColor")
                vertex_color.layer_name = "Attribute"
                vertex_color.location = (-350, 50)

                tex_image = output.node_tree.nodes.new("ShaderNodeTexImage")
                tex_image.image = bpy.data.images.get(
                    texture_path
                ) or bpy.data.images.load(texture_path)
                tex_image.extension = "CLIP"
                tex_image.interpolation = "Closest"
                tex_image.location = (-450, -125)

                color_mix = output.node_tree.nodes.new("ShaderNodeMix")
                color_mix.data_type = "RGBA"
                color_mix.blend_type = "MULTIPLY"
                color_mix.inputs[0].default_value = 1
                color_mix.location = (-100, 50)

                emission = output.node_tree.nodes.new("ShaderNodeEmission")
                emission.location = (150, 50)

                output_node.location = (400, 50)

                output.node_tree.links.new(color_mix.inputs[6], vertex_color.outputs[0])
                output.node_tree.links.new(color_mix.inputs[7], tex_image.outputs[0])
                output.node_tree.links.new(emission.inputs[0], color_mix.outputs[2])
                output.node_tree.links.new(output_node.inputs[0], emission.outputs[0])

            case "cutout":
                vertex_color = output.node_tree.nodes.new("ShaderNodeVertexColor")
                vertex_color.layer_name = "Attribute"
                vertex_color.location = (-600, 50)

                tex_image = output.node_tree.nodes.new("ShaderNodeTexImage")
                tex_image.image = bpy.data.images.get(
                    texture_path
                ) or bpy.data.images.load(texture_path)
                tex_image.extension = "CLIP"
                tex_image.interpolation = "Closest"
                tex_image.location = (-700, -125)

                color_mix = output.node_tree.nodes.new("ShaderNodeMix")
                color_mix.data_type = "RGBA"
                color_mix.blend_type = "MULTIPLY"
                color_mix.inputs[0].default_value = 1
                color_mix.location = (-350, -150)

                multiply = output.node_tree.nodes.new("ShaderNodeMath")
                multiply.operation = "MULTIPLY"
                multiply.location = (-350, 50)

                emission = output.node_tree.nodes.new("ShaderNodeEmission")
                emission.location = (-100, -250)

                transparent = output.node_tree.nodes.new("ShaderNodeBsdfTransparent")
                transparent.location = (-100, -100)

                transparency_mix = output.node_tree.nodes.new("ShaderNodeMixShader")
                transparency_mix.location = (150, 50)

                output_node.location = (400, 50)

                output.node_tree.links.new(color_mix.inputs[6], vertex_color.outputs[0])
                output.node_tree.links.new(multiply.inputs[0], vertex_color.outputs[1])
                output.node_tree.links.new(color_mix.inputs[7], tex_image.outputs[0])
                output.node_tree.links.new(multiply.inputs[1], tex_image.outputs[1])
                output.node_tree.links.new(emission.inputs[0], color_mix.outputs[2])

                output.node_tree.links.new(
                    transparency_mix.inputs[0], multiply.outputs[0]
                )
                output.node_tree.links.new(
                    transparency_mix.inputs[1], transparent.outputs[0]
                )
                output.node_tree.links.new(
                    output_node.inputs[0], transparency_mix.outputs[0]
                )

                output.node_tree.links.new(
                    transparency_mix.inputs[2], emission.outputs[0]
                )

                output.blend_method = "CLIP"
                output.shadow_method = "CLIP"

            case "additive":
                vertex_color = output.node_tree.nodes.new("ShaderNodeVertexColor")
                vertex_color.layer_name = "Attribute"
                vertex_color.location = (-600, 50)

                tex_image = output.node_tree.nodes.new("ShaderNodeTexImage")
                tex_image.image = bpy.data.images.get(
                    texture_path
                ) or bpy.data.images.load(texture_path)
                tex_image.extension = "CLIP"
                tex_image.interpolation = "Closest"
                tex_image.location = (-700, -125)

                color_mix = output.node_tree.nodes.new("ShaderNodeMix")
                color_mix.data_type = "RGBA"
                color_mix.blend_type = "MULTIPLY"
                color_mix.inputs[0].default_value = 1
                color_mix.location = (-350, 50)

                emission = output.node_tree.nodes.new("ShaderNodeEmission")
                emission.location = (-100, -100)

                transparent = output.node_tree.nodes.new("ShaderNodeBsdfTransparent")
                transparent.location = (-100, 50)

                transparency_mix = output.node_tree.nodes.new("ShaderNodeAddShader")
                transparency_mix.location = (150, 50)

                output_node.location = (400, 50)

                output.node_tree.links.new(color_mix.inputs[6], vertex_color.outputs[0])
                output.node_tree.links.new(color_mix.inputs[7], tex_image.outputs[0])
                output.node_tree.links.new(emission.inputs[0], color_mix.outputs[2])

                output.node_tree.links.new(
                    transparency_mix.inputs[0], transparent.outputs[0]
                )
                output.node_tree.links.new(
                    output_node.inputs[0], transparency_mix.outputs[0]
                )

                output.node_tree.links.new(
                    transparency_mix.inputs[1], emission.outputs[0]
                )

                output.blend_method = "BLEND"
                output.shadow_method = "NONE"

            case "blended":
                vertex_color = output.node_tree.nodes.new("ShaderNodeVertexColor")
                vertex_color.layer_name = "Attribute"
                vertex_color.location = (-600, 50)

                tex_image = output.node_tree.nodes.new("ShaderNodeTexImage")
                tex_image.image = bpy.data.images.get(
                    texture_path
                ) or bpy.data.images.load(texture_path)
                tex_image.extension = "CLIP"
                tex_image.interpolation = "Closest"
                tex_image.location = (-700, -125)

                color_mix = output.node_tree.nodes.new("ShaderNodeMix")
                color_mix.data_type = "RGBA"
                color_mix.blend_type = "MULTIPLY"
                color_mix.inputs[0].default_value = 1
                color_mix.location = (-350, -150)

                multiply = output.node_tree.nodes.new("ShaderNodeMath")
                multiply.operation = "MULTIPLY"
                multiply.location = (-350, 50)

                emission = output.node_tree.nodes.new("ShaderNodeEmission")
                emission.location = (-100, -250)

                transparent = output.node_tree.nodes.new("ShaderNodeBsdfTransparent")
                transparent.location = (-100, -100)

                transparency_mix = output.node_tree.nodes.new("ShaderNodeMixShader")
                transparency_mix.location = (150, 50)

                output_node.location = (400, 50)

                output.node_tree.links.new(color_mix.inputs[6], vertex_color.outputs[0])
                output.node_tree.links.new(multiply.inputs[0], vertex_color.outputs[1])
                output.node_tree.links.new(color_mix.inputs[7], tex_image.outputs[0])
                output.node_tree.links.new(multiply.inputs[1], tex_image.outputs[1])
                output.node_tree.links.new(emission.inputs[0], color_mix.outputs[2])

                output.node_tree.links.new(
                    transparency_mix.inputs[0], multiply.outputs[0]
                )
                output.node_tree.links.new(
                    transparency_mix.inputs[1], transparent.outputs[0]
                )
                output.node_tree.links.new(
                    output_node.inputs[0], transparency_mix.outputs[0]
                )

                output.node_tree.links.new(
                    transparency_mix.inputs[2], emission.outputs[0]
                )

                output.blend_method = "BLEND"
                output.shadow_method = "HASHED"

    return output


def create_navigation_mesh_material(name, color):
    output = bpy.data.materials.get(name)

    if not output:
        output = bpy.data.materials.new(name)

        output.use_nodes = True

        output_node = None

        for node in output.node_tree.nodes:
            if node.type == "OUTPUT_MATERIAL":
                output_node = node
            else:
                output.node_tree.nodes.remove(node)

        emission = output.node_tree.nodes.new("ShaderNodeEmission")
        emission.location = (-400, 0)
        emission.inputs[0].default_value[0] = color[0]
        emission.inputs[0].default_value[1] = color[1]
        emission.inputs[0].default_value[2] = color[2]

        transparent = output.node_tree.nodes.new("ShaderNodeBsdfTransparent")
        transparent.location = (-400, -150)

        mix = output.node_tree.nodes.new("ShaderNodeMixShader")
        mix.location = (-200, 0)
        mix.inputs[0].default_value = 0.9

        output_node.location = (0, 0)

        output.node_tree.links.new(mix.inputs[1], emission.outputs[0])
        output.node_tree.links.new(mix.inputs[2], transparent.outputs[0])
        output.node_tree.links.new(output_node.inputs[0], mix.outputs[0])

        output.blend_method = "BLEND"
        output.shadow_method = "NONE"

    return output


def import_material(self, context, prefix):
    initialize_scene(context)

    name = prefix + path.basename(path.splitext(self.properties.filepath)[0])

    if not match("^[a-z_][a-z_0-9]*$", name):
        self.report(
            {"ERROR"},
            'Texture name file names should be lower case, start with a letter or underscore, followed by only letters, digits and/or underscores ("'
            + name
            + '").',
        )
        return {"FINISHED"}

    material = create_material(name, self.properties.filepath)

    for object in bpy.context.selected_objects:
        if object.type == "MESH" and not object.name.startswith("navigation_"):
            exists = False

            for existing_material in object.data.materials:
                if existing_material == material:
                    exists = True

            if not exists:
                object.data.materials.append(material)

    return {"FINISHED"}


class IndifferenceEngineOBJAddOpaqueMaterial(Operator, ImportHelper):
    bl_idname = "indifference_engine_obj.add_opaque_material"
    bl_label = "Add Indifference Engine OBJ Opaque Material"
    filename_ext = ".tga"

    def execute(self, context):
        return import_material(self, context, "opaque_")


class IndifferenceEngineOBJAddBlendMaterial(Operator, ImportHelper):
    bl_idname = "indifference_engine_obj.add_blended_material"
    bl_label = "Add Indifference Engine OBJ Blended Material"
    filename_ext = ".tga"

    def execute(self, context):
        return import_material(self, context, "blended_")


class IndifferenceEngineOBJAddCutoutMaterial(Operator, ImportHelper):
    bl_idname = "indifference_engine_obj.add_cutout_material"
    bl_label = "Add Indifference Engine OBJ Cutout Material"
    filename_ext = ".tga"

    def execute(self, context):
        return import_material(self, context, "cutout_")


class IndifferenceEngineOBJAddAdditiveMaterial(Operator, ImportHelper):
    bl_idname = "indifference_engine_obj.add_additive_material"
    bl_label = "Add Indifference Engine OBJ Additive Material"
    filename_ext = ".tga"

    def execute(self, context):
        return import_material(self, context, "additive_")


def create_new_navigation_mesh_material():
    name = "navigation_untitled"
    counter = 2

    while bpy.data.materials.get(name):
        name = "navigation_untitled_" + str(counter)
        counter = counter + 1

    return create_navigation_mesh_material(name, [1, 0, 0])


class IndifferenceEngineOBJAddNavigationMeshMaterial(Operator):
    bl_idname = "indifference_engine_obj.add_navigation_mesh_material"
    bl_label = "Add Indifference Engine OBJ Navigation Mesh Material"

    def execute(self, context):
        initialize_scene(context)

        output = create_new_navigation_mesh_material()

        for object in bpy.context.selected_objects:
            if object.type == "MESH" and object.name.startswith("navigation_"):
                object.data.materials.append(output)

        return {"FINISHED"}


class IndifferenceEngineOBJAddNavigationMesh(Operator):
    bl_idname = "indifference_engine_obj.add_navigation_mesh"
    bl_label = "Add Indifference Engine OBJ Navigation Mesh"

    def execute(self, context):
        initialize_scene(context)

        bpy.ops.mesh.primitive_plane_add(
            location=context.scene.cursor.location,
        )

        output = context.active_object

        name = "navigation_untitled"
        counter = 2

        while name in context.scene.objects:
            name = "navigation_untitled_" + str(counter)
            counter = counter + 1

        output.name = name

        configure_as_navigation_mesh(output)

        bpy.ops.view3d.view_selected()

        for material in bpy.data.materials:
            if material.name.startswith("navigation_"):
                output.data.materials.append(material)
                return {"FINISHED"}

        output.data.materials.append(create_new_navigation_mesh_material())

        return {"FINISHED"}


class IndifferenceEngineOBJAdd(Menu):
    bl_idname = "INDIFFERENCE_ENGINE_OBJ_MT_add"
    bl_label = "Indifference Engine"
    bl_options = {"SEARCH_ON_KEY_PRESS"}

    def draw(self, context):
        layout = self.layout
        layout.operator_context = "INVOKE_REGION_WIN"
        layout.menu(
            IndifferenceEngineOBJAddMaterial.bl_idname,
            text="Material",
            icon="MATERIAL",
        )
        layout.operator(
            IndifferenceEngineOBJAddNavigationMesh.bl_idname,
            text="Navigation Mesh",
            icon="MESH_DATA",
        )


class IndifferenceEngineOBJAddMaterial(Menu):
    bl_idname = "INDIFFERENCE_ENGINE_OBJ_MT_add_material"
    bl_label = "Material"
    bl_options = {"SEARCH_ON_KEY_PRESS"}

    def draw(self, context):
        layout = self.layout
        layout.operator_context = "INVOKE_REGION_WIN"
        layout.operator(
            IndifferenceEngineOBJAddOpaqueMaterial.bl_idname,
            text="Opaque",
            icon="MATERIAL",
        )
        layout.operator(
            IndifferenceEngineOBJAddBlendMaterial.bl_idname,
            text="Blended",
            icon="MATERIAL",
        )
        layout.operator(
            IndifferenceEngineOBJAddCutoutMaterial.bl_idname,
            text="Cutout",
            icon="MATERIAL",
        )
        layout.operator(
            IndifferenceEngineOBJAddAdditiveMaterial.bl_idname,
            text="Additive",
            icon="MATERIAL",
        )
        layout.operator(
            IndifferenceEngineOBJAddNavigationMeshMaterial.bl_idname,
            text="Navigation Mesh",
            icon="MATERIAL",
        )


def menu_add(self, context):
    layout = self.layout
    layout.operator_context = "INVOKE_REGION_WIN"
    layout.separator()
    layout.menu(
        IndifferenceEngineOBJAdd.bl_idname,
        text="Indifference Engine",
        icon="GHOST_ENABLED",
    )


class IndifferenceEngineOBJExport(Operator, ExportHelper):
    bl_idname = "export.indifference_engine_obj"
    bl_label = "Export Indifference Engine OBJ (*.obj)"
    filename_ext = ".obj"

    def execute(self, context):
        initialize_scene(context)

        if self.filepath.endswith(".obj"):
            mtllib = self.filepath[:-3] + "mtl"
        else:
            mtllib = self.filepath + ".mtl"

        file = None

        try:
            file = open(mtllib, "w")

            first = True

            for material in bpy.data.materials:
                found = False

                for obj in context.scene.objects:
                    if material.name in obj.data.materials:
                        found = True
                        break

                if found:
                    if first:
                        first = False
                    else:
                        file.write("\n")

                    if not match("^[a-z_][a-z_0-9]*$", material.name):
                        self.report(
                            {"ERROR"},
                            'Material names should be lower case, start with a letter or underscore, followed by only letters, digits and/or underscores ("'
                            + material.name
                            + '").',
                        )
                        return {"FINISHED"}

                    file.write("newmtl " + material.name + "\n")

                    if not material.use_nodes:
                        self.report(
                            {"ERROR"},
                            'Material "' + material.name + '" does not use nodes.',
                        )
                        return {"FINISHED"}

                    found = False
                    if material.name.startswith("navigation_"):
                        for node in material.node_tree.nodes:
                            if node.type == "EMISSION":
                                if found:
                                    self.report(
                                        {"ERROR"},
                                        'Multiple texture image nodes in material "'
                                        + material.name
                                        + '".',
                                    )
                                    return {"FINISHED"}

                                file.write(
                                    "Kd "
                                    + str(node.inputs[0].default_value[0])
                                    + " "
                                    + str(node.inputs[0].default_value[1])
                                    + " "
                                    + str(node.inputs[0].default_value[2])
                                    + "\n"
                                )

                                found = True

                        if not found:
                            self.report(
                                {"ERROR"},
                                'No texture image node in material "'
                                + material.name
                                + '".',
                            )
                            return {"FINISHED"}
                    else:
                        for node in material.node_tree.nodes:
                            if node.type == "TEX_IMAGE":
                                if found:
                                    self.report(
                                        {"ERROR"},
                                        'Multiple texture image nodes in material "'
                                        + material.name
                                        + '".',
                                    )
                                    return {"FINISHED"}

                                if node.image is None:
                                    self.report(
                                        {"ERROR"},
                                        'No image in texture image node of material "'
                                        + material.name
                                        + '".',
                                    )
                                    return {"FINISHED"}
                                else:
                                    if not node.image.filepath.endswith(".tga"):
                                        self.report(
                                            {"ERROR"},
                                            'Textures must be in TGA format ("'
                                            + node.image.filepath
                                            + '").',
                                        )
                                        return {"FINISHED"}

                                    file.write(
                                        "map_Kd "
                                        + sub(
                                            r"^[\\/]+",
                                            "",
                                            path.relpath(
                                                bpy.path.abspath(node.image.filepath),
                                                path.dirname(self.filepath),
                                            ),
                                        ).replace("\\", "/")
                                        + "\n"
                                    )

                                    found = True

                        if not found:
                            self.report(
                                {"ERROR"},
                                'No texture image node in material "'
                                + material.name
                                + '".',
                            )
                            return {"FINISHED"}

        finally:
            if file != None:
                file.close()

        file = None

        try:
            file = open(self.filepath, "w")

            file.write("mtllib " + path.basename(mtllib) + "\n")

            for obj in context.scene.objects:
                if not match("^[a-z_][a-z_0-9]*$", obj.name):
                    self.report(
                        {"ERROR"},
                        'Object names should be lower case, start with a letter or underscore, followed by only letters, digits and/or underscores ("'
                        + obj.name
                        + '").',
                    )
                    return {"FINISHED"}

                file.write("o " + obj.name + "\n")

                if obj.type != "MESH":
                    self.report(
                        {"ERROR"},
                        'Object "' + obj.name + '" is not a mesh.',
                    )
                    return {"FINISHED"}

                mesh = obj.data

                if obj.name.startswith("navigation_"):
                    for vertex in mesh.vertices:
                        location = vertex.co

                        file.write(
                            "v "
                            + f"{location[0]:f}"
                            + " "
                            + f"{location[1]:f}"
                            + " "
                            + f"{location[2]:f}"
                            + "\n"
                        )

                    materials = mesh.materials.values()

                    for polygon in mesh.polygons:
                        material = materials[polygon.material_index]

                        if material is None:
                            self.report(
                                {"ERROR"},
                                'Object "'
                                + obj.name
                                + '" contains faces without materials.',
                            )
                            return {"FINISHED"}

                        if not material.name.startswith("navigation_"):
                            self.report(
                                {"ERROR"},
                                'Object "'
                                + obj.name
                                + '" contains non-navigation materials but is a navigation mesh.',
                            )
                            return {"FINISHED"}

                        file.write("usemtl " + material.name + "\n")

                        file.write("f")

                        for key in polygon.vertices:
                            file.write(" " + str(key - len(mesh.vertices)))

                        file.write("\n")
                else:
                    match len(mesh.uv_layers):
                        case 0:
                            self.report(
                                {"ERROR"},
                                'Object "'
                                + obj.name
                                + '" does not have any UV layers.',
                            )
                            return {"FINISHED"}

                        case 1:
                            for uv_layer in mesh.uv_layers:
                                match len(mesh.vertex_colors):
                                    case 0:
                                        self.report(
                                            {"ERROR"},
                                            'Object "'
                                            + obj.name
                                            + '" does not have any color layers.',
                                        )
                                        return {"FINISHED"}

                                    case 1:
                                        materials = mesh.materials.values()

                                        for color_layer in mesh.vertex_colors:
                                            total_indices = 0

                                            for polygon in mesh.polygons:
                                                material = materials[
                                                    polygon.material_index
                                                ]

                                                if material is None:
                                                    self.report(
                                                        {"ERROR"},
                                                        'Object "'
                                                        + obj.name
                                                        + '" contains faces without materials.',
                                                    )
                                                    return {"FINISHED"}

                                                if material.name.startswith(
                                                    "navigation_"
                                                ):
                                                    self.report(
                                                        {"ERROR"},
                                                        'Object "'
                                                        + obj.name
                                                        + '" is not a navigation mesh but contains navigation materials.',
                                                    )
                                                    return {"FINISHED"}

                                                file.write(
                                                    "usemtl " + material.name + "\n"
                                                )

                                                for key in polygon.vertices:
                                                    vertex = mesh.vertices[key]
                                                    location = vertex.co
                                                    uv = uv_layer.data[total_indices].uv
                                                    color = color_layer.data[
                                                        total_indices
                                                    ].color

                                                    total_indices += 1

                                                    file.write(
                                                        "v "
                                                        + f"{location[0]:f}"
                                                        + " "
                                                        + f"{location[1]:f}"
                                                        + " "
                                                        + f"{location[2]:f}"
                                                        + " "
                                                        + f"{color[0]:f}"
                                                        + " "
                                                        + f"{color[1]:f}"
                                                        + " "
                                                        + f"{color[2]:f}"
                                                        + " "
                                                        + f"{color[3]:f}"
                                                        + "\n"
                                                    )

                                                    file.write(
                                                        "vt "
                                                        + f"{uv[0]:f}"
                                                        + " "
                                                        + f"{uv[1]:f}"
                                                        + "\n"
                                                    )

                                                file.write("f")

                                                index = -len(polygon.vertices)
                                                for key in polygon.vertices:
                                                    file.write(
                                                        " "
                                                        + str(index)
                                                        + "/"
                                                        + str(index)
                                                    )
                                                    index += 1

                                                file.write("\n")

                                    case _:
                                        self.report(
                                            {"ERROR"},
                                            'Object "'
                                            + obj.name
                                            + '" has multiple color layers.',
                                        )
                                        return {"FINISHED"}

                        case _:
                            self.report(
                                {"ERROR"},
                                'Object "' + obj.name + '" has multiple UV layers.',
                            )
                            return {"FINISHED"}

        finally:
            if file != None:
                file.close()

        return {"FINISHED"}


def menu_export(self, context):
    self.layout.operator(IndifferenceEngineOBJExport.bl_idname)


class IndifferenceEngineOBJImport(Operator, ImportHelper):
    bl_idname = "import.indifference_engine_obj"
    bl_label = "Import Indifference Engine OBJ (*.obj)"
    filename_ext = ".obj"

    def execute(self, context):
        initialize_scene(context)

        file = None

        try:
            file = open(self.properties.filepath, "r")

            object_name = None
            vertices = []
            texture_coordinates = []
            faces = []
            materials = {}
            current_material = None
            previous_object_names = []

            def end_object():
                if object_name != None:
                    if object_name.startswith("navigation_"):
                        object_vertex_order = []
                        object_vertices = []
                        indices = []

                        for face in faces:
                            face_indices = []

                            for face_vertex in face:
                                original_index = face_vertex[0]

                                if original_index not in object_vertex_order:
                                    object_vertex_order.append(original_index)
                                    vertex = vertices[face_vertex[0]]
                                    object_vertices.append(
                                        [vertex[0], vertex[1], vertex[2]]
                                    )

                                face_indices.append(
                                    object_vertex_order.index(original_index)
                                )

                            indices.append(face_indices)

                        mesh = bpy.data.meshes.new(object_name)

                        mesh.from_pydata(
                            object_vertices,
                            [],
                            indices,
                        )

                        material_order = []

                        for face_index, face in enumerate(faces):
                            for face_vertex in face:
                                vertex = vertices[face_vertex[0]]

                                material = face_vertex[1]

                                if material not in material_order:
                                    material_order.append(material)
                                    mesh.materials.append(material)

                                mesh.polygons[face_index].material_index = (
                                    material_order.index(material)
                                )

                        mesh.update()

                        obj = bpy.data.objects.new(object_name, mesh)
                        context.scene.collection.objects.link(obj)

                        faces.clear()

                        configure_as_navigation_mesh(obj)
                    else:
                        object_vertices = []
                        indices = []

                        for face in faces:
                            face_indices = []

                            for face_vertex in face:
                                vertex = vertices[face_vertex[0]]

                                index = None

                                for i, existing_vertex in enumerate(object_vertices):
                                    if (
                                        existing_vertex[0] == vertex[0]
                                        and existing_vertex[1] == vertex[1]
                                        and existing_vertex[2] == vertex[2]
                                    ):
                                        index = i
                                        break

                                if index == None:
                                    index = len(object_vertices)
                                    object_vertices.append(
                                        [vertex[0], vertex[1], vertex[2]]
                                    )

                                face_indices.append(index)

                            indices.append(face_indices)

                        mesh = bpy.data.meshes.new(object_name)

                        mesh.from_pydata(
                            object_vertices,
                            [],
                            indices,
                        )

                        color_layer = mesh.vertex_colors.new(name="Attribute")
                        uv_layer = mesh.uv_layers.new(name="UV")

                        total_indices = 0

                        material_order = []

                        for face_index, face in enumerate(faces):
                            for face_vertex in face:
                                vertex = vertices[face_vertex[0]]
                                color_layer.data[total_indices].color[0] = vertex[3]
                                color_layer.data[total_indices].color[1] = vertex[4]
                                color_layer.data[total_indices].color[2] = vertex[5]
                                color_layer.data[total_indices].color[3] = vertex[6]
                                texture_coordinate = texture_coordinates[face_vertex[1]]
                                uv_layer.data[total_indices].uv[0] = texture_coordinate[
                                    0
                                ]
                                uv_layer.data[total_indices].uv[1] = texture_coordinate[
                                    1
                                ]
                                total_indices += 1

                                material = face_vertex[2]

                                if material not in material_order:
                                    material_order.append(material)
                                    mesh.materials.append(material)

                                mesh.polygons[face_index].material_index = (
                                    material_order.index(material)
                                )

                        mesh.update()

                        obj = bpy.data.objects.new(object_name, mesh)
                        context.scene.collection.objects.link(obj)

                        faces.clear()

            for line in file.readlines():
                without_comments = match("^([^#]*)#.*$", line)

                if without_comments:
                    line = without_comments[1]

                if match("\S", line):
                    object_match = match("^\s*o\s+([a-z_][a-z_0-9]*)\s*$", line)

                    if object_match:
                        end_object()

                        object_name = object_match[1]

                        if object_name in previous_object_names:
                            self.report(
                                {"ERROR"},
                                'Object "'
                                + object_name
                                + '" is defined multiple times.',
                            )
                            return {"FINISHED"}

                        previous_object_names.append(object_name)
                        continue

                    mtllib_match = match(
                        "^\s*mtllib\s+([a-z_][a-z_0-9]*)\.mtl\s*$", line
                    )

                    if mtllib_match:
                        mtl_file = None

                        try:
                            mtl_file = open(
                                path.join(
                                    path.dirname(self.properties.filepath),
                                    mtllib_match[1] + ".mtl",
                                ),
                                "r",
                            )

                            material_name = None
                            waiting_for_color = False
                            waiting_for_texture = False

                            for mtl_line in mtl_file.readlines():
                                without_comments = match("^([^#]*)#.*$", mtl_line)

                                if without_comments:
                                    mtl_line = without_comments[1]

                                if match("\S", mtl_line):
                                    if match("^\s*Ns\s+.*$", mtl_line):
                                        continue

                                    if match("^\s*Ka\s+.*$", mtl_line):
                                        continue

                                    if match("^\s*Ks\s+.*$", mtl_line):
                                        continue

                                    if match("^\s*Ke\s+.*$", mtl_line):
                                        continue

                                    if match("^\s*Ni\s+.*$", mtl_line):
                                        continue

                                    if match("^\s*d\s+.*$", mtl_line):
                                        continue

                                    if match("^\s*illum\s+.*$", mtl_line):
                                        continue

                                    newmtl_match = match(
                                        "^\s*newmtl\s+([a-z_][a-z_0-9]*)\s*$", mtl_line
                                    )

                                    if newmtl_match:
                                        if waiting_for_texture:
                                            self.report(
                                                {"ERROR"},
                                                'Material "'
                                                + material_name
                                                + '" lacks a texture map.',
                                            )
                                            return {"FINISHED"}
                                        elif newmtl_match[1] in materials:
                                            self.report(
                                                {"ERROR"},
                                                'Material "'
                                                + material_name
                                                + '" is defined multiple times.',
                                            )
                                            return {"FINISHED"}
                                        else:
                                            material_name = newmtl_match[1]
                                            waiting_for_color = (
                                                material_name.startswith("navigation_")
                                            )
                                            waiting_for_texture = not waiting_for_color
                                            continue

                                    map_kd_match = match(
                                        "^\s*map_Kd\s+(.*)\.tga\s*$", mtl_line
                                    )

                                    if map_kd_match:
                                        if waiting_for_texture:
                                            waiting_for_texture = False

                                            materials[material_name] = create_material(
                                                material_name,
                                                path.join(
                                                    path.dirname(
                                                        self.properties.filepath
                                                    ),
                                                    path.dirname(mtllib_match[1]),
                                                    map_kd_match[1] + ".tga",
                                                ),
                                            )

                                            continue
                                        elif material_name == None:
                                            self.report(
                                                {"ERROR"},
                                                "Cannot specify a texture map outside of a material.",
                                            )
                                            return {"FINISHED"}
                                        elif material_name.startswith("navigation_"):
                                            self.report(
                                                {"ERROR"},
                                                "Unexpectedly specified a texture map for a navigation material.",
                                            )
                                            return {"FINISHED"}
                                        else:
                                            self.report(
                                                {"ERROR"},
                                                "Cannot specify multiple texture maps for the same material.",
                                            )
                                            return {"FINISHED"}

                                    kd_match = match(
                                        "^\s*Kd\s+((?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+((?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+((?:\d+\.\d+|\d+\.|\d+|\.\d+))\s*$",
                                        mtl_line,
                                    )

                                    if kd_match:
                                        if waiting_for_color:
                                            waiting_for_color = False

                                            materials[material_name] = (
                                                create_navigation_mesh_material(
                                                    material_name,
                                                    [
                                                        float(kd_match[1]),
                                                        float(kd_match[2]),
                                                        float(kd_match[3]),
                                                    ],
                                                )
                                            )

                                            continue
                                        elif material_name == None:
                                            self.report(
                                                {"ERROR"},
                                                "Cannot specify a color outside of a material.",
                                            )
                                            return {"FINISHED"}
                                        elif not material_name.startswith(
                                            "navigation_"
                                        ):
                                            self.report(
                                                {"ERROR"},
                                                "Unexpectedly specified a color for a non-navigation material.",
                                            )
                                            return {"FINISHED"}
                                        else:
                                            self.report(
                                                {"ERROR"},
                                                "Cannot specify multiple colors for the same material.",
                                            )
                                            return {"FINISHED"}

                                    self.report(
                                        {"ERROR"},
                                        'Failed to parse "'
                                        + mtl_line
                                        + '" as a MTL instruction.',
                                    )
                                    return {"FINISHED"}

                            if waiting_for_color:
                                self.report(
                                    {"ERROR"},
                                    'Material "' + material_name + '" lacks a color.',
                                )
                                return {"FINISHED"}

                            if waiting_for_texture:
                                self.report(
                                    {"ERROR"},
                                    'Material "'
                                    + material_name
                                    + '" lacks a texture map.',
                                )
                                return {"FINISHED"}

                        finally:
                            if mtl_file != None:
                                mtl_file.close()

                        continue

                    usemtl_match = match("^\s*usemtl\s+([a-z_][a-z_0-9]*)\s*$", line)

                    if usemtl_match:
                        if usemtl_match[1] in materials:
                            current_material = materials[usemtl_match[1]]
                            continue
                        else:
                            self.report(
                                {"ERROR"},
                                'Undefined material "' + usemtl_match[1] + '".',
                            )
                            return {"FINISHED"}

                    v_match = match(
                        "^\s*v\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))(?:\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))(?:\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+)))?)?\s*$",
                        line,
                    )

                    if v_match:
                        vertices.append(
                            [
                                float(v_match[1]),
                                float(v_match[2]),
                                float(v_match[3]),
                                float(v_match[4]) if v_match[4] is not None else 1,
                                float(v_match[5]) if v_match[5] is not None else 1,
                                float(v_match[6]) if v_match[6] is not None else 1,
                                float(v_match[7]) if v_match[7] is not None else 1,
                            ]
                        )
                        continue

                    vn_match = match("^\s*vn\s+.*$", line)

                    if vn_match:
                        continue

                    vt_match = match(
                        "^\s*vt\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))\s+(-?(?:\d+\.\d+|\d+\.|\d+|\.\d+))\s*$",
                        line,
                    )

                    if vt_match:
                        texture_coordinates.append(
                            [
                                float(vt_match[1]),
                                float(vt_match[2]),
                            ]
                        )
                        continue

                    s_match = match("^\s*s\s+.*$", line)

                    if s_match:
                        continue

                    f_match = match("^\s*f\s+((?:\s*-?\d+(?:\/*-?\d+)*)+)\s*$", line)

                    if f_match:
                        if current_material == None:
                            self.report(
                                {"ERROR"},
                                "All faces must have materials.",
                            )
                            return {"FINISHED"}
                        elif object_name == None:
                            self.report(
                                {"ERROR"},
                                "Face outside of object.",
                            )
                            return {"FINISHED"}
                        elif object_name.startswith(
                            "navigation_"
                        ) != current_material.name.startswith("navigation_"):
                            self.report(
                                {"ERROR"},
                                "Navigation materials cannot be used on non-navigation meshes nor vice versa.",
                            )
                            return {"FINISHED"}
                        else:
                            extracted = []

                            for fragment in f_match[1].strip().split():
                                indices = fragment.split("/")

                                if object_name.startswith("navigation_"):
                                    vertex = int(indices[0])

                                    if vertex == 0:
                                        self.report(
                                            {"ERROR"},
                                            "Vertex indices cannot be zero.",
                                        )
                                        return {"FINISHED"}
                                    elif vertex > 0 and vertex <= len(vertices):
                                        vertex = vertex - 1
                                    elif vertex < 0 and vertex >= -len(vertices):
                                        vertex = len(vertices) + vertex
                                    else:
                                        self.report(
                                            {"ERROR"},
                                            "Out-of-range vertex index.",
                                        )
                                        return {"FINISHED"}

                                    extracted.append([vertex, current_material])
                                else:
                                    if len(indices) < 2:
                                        self.report(
                                            {"ERROR"},
                                            "All vertices of all faces must have texture coordinates.",
                                        )
                                        return {"FINISHED"}
                                    else:
                                        vertex = int(indices[0])

                                        if vertex == 0:
                                            self.report(
                                                {"ERROR"},
                                                "Vertex indices cannot be zero.",
                                            )
                                            return {"FINISHED"}
                                        elif vertex > 0 and vertex <= len(vertices):
                                            vertex = vertex - 1
                                        elif vertex < 0 and vertex >= -len(vertices):
                                            vertex = len(vertices) + vertex
                                        else:
                                            self.report(
                                                {"ERROR"},
                                                "Out-of-range vertex index.",
                                            )
                                            return {"FINISHED"}

                                        texture_coordinate = int(indices[1])

                                        if texture_coordinate == 0:
                                            self.report(
                                                {"ERROR"},
                                                "Texture coordinate indices cannot be zero.",
                                            )
                                            return {"FINISHED"}
                                        elif (
                                            texture_coordinate > 0
                                            and texture_coordinate
                                            <= len(texture_coordinates)
                                        ):
                                            texture_coordinate = texture_coordinate - 1
                                        elif (
                                            texture_coordinate < 0
                                            and texture_coordinate
                                            >= -len(texture_coordinates)
                                        ):
                                            texture_coordinate = (
                                                len(texture_coordinates)
                                                + texture_coordinate
                                            )
                                        else:
                                            self.report(
                                                {"ERROR"},
                                                "Out-of-range texture coordinate index.",
                                            )
                                            return {"FINISHED"}

                                        extracted.append(
                                            [
                                                vertex,
                                                texture_coordinate,
                                                current_material,
                                            ]
                                        )

                            faces.append(extracted)
                            continue

                    self.report(
                        {"ERROR"},
                        'Failed to parse "' + line + '" as an OBJ instruction.',
                    )
                    return {"FINISHED"}

            end_object()

        finally:
            if file != None:
                file.close()

        return {"FINISHED"}


def menu_import(self, context):
    self.layout.operator(IndifferenceEngineOBJImport.bl_idname)


classes = (
    IndifferenceEngineOBJAddOpaqueMaterial,
    IndifferenceEngineOBJAddBlendMaterial,
    IndifferenceEngineOBJAddCutoutMaterial,
    IndifferenceEngineOBJAddAdditiveMaterial,
    IndifferenceEngineOBJAddNavigationMeshMaterial,
    IndifferenceEngineOBJAddNavigationMesh,
    IndifferenceEngineOBJAdd,
    IndifferenceEngineOBJAddMaterial,
    IndifferenceEngineOBJExport,
    IndifferenceEngineOBJImport,
)


def register():
    for cls in classes:
        register_class(cls)

    VIEW3D_MT_add.append(menu_add)
    TOPBAR_MT_file_import.append(menu_import)
    TOPBAR_MT_file_export.append(menu_export)


def unregister():
    for cls in classes:
        unregister_class(cls)

    VIEW3D_MT_add.remove(menu_add)
    TOPBAR_MT_file_import.remove(menu_import)
    TOPBAR_MT_file_export.remove(menu_export)


if __name__ == "__main__":
    register()
