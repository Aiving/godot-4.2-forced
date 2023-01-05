/**************************************************************************/
/*  register_editor_types.cpp                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "register_editor_types.h"

#include "editor/animation_track_editor.h"
#include "editor/debugger/debug_adapter/debug_adapter_server.h"
#include "editor/editor_command_palette.h"
#include "editor/editor_feature_profile.h"
#include "editor/editor_file_dialog.h"
#include "editor/editor_file_system.h"
#include "editor/editor_node.h"
#include "editor/editor_paths.h"
#include "editor/editor_resource_picker.h"
#include "editor/editor_resource_preview.h"
#include "editor/editor_run_script.h"
#include "editor/editor_settings.h"
#include "editor/editor_translation_parser.h"
#include "editor/editor_undo_redo_manager.h"
#include "editor/filesystem_dock.h"
#include "editor/import/editor_import_plugin.h"
#include "editor/import/resource_importer_scene.h"
#include "editor/plugins/animation_tree_editor_plugin.h"
#include "editor/plugins/audio_stream_editor_plugin.h"
#include "editor/plugins/audio_stream_randomizer_editor_plugin.h"
#include "editor/plugins/bit_map_editor_plugin.h"
#include "editor/plugins/bone_map_editor_plugin.h"
#include "editor/plugins/camera_3d_editor_plugin.h"
#include "editor/plugins/cast_2d_editor_plugin.h"
#include "editor/plugins/collision_polygon_2d_editor_plugin.h"
#include "editor/plugins/collision_shape_2d_editor_plugin.h"
#include "editor/plugins/control_editor_plugin.h"
#include "editor/plugins/cpu_particles_2d_editor_plugin.h"
#include "editor/plugins/cpu_particles_3d_editor_plugin.h"
#include "editor/plugins/curve_editor_plugin.h"
#include "editor/plugins/editor_debugger_plugin.h"
#include "editor/plugins/font_config_plugin.h"
#include "editor/plugins/gpu_particles_2d_editor_plugin.h"
#include "editor/plugins/gpu_particles_3d_editor_plugin.h"
#include "editor/plugins/gpu_particles_collision_sdf_editor_plugin.h"
#include "editor/plugins/gradient_editor_plugin.h"
#include "editor/plugins/gradient_texture_2d_editor_plugin.h"
#include "editor/plugins/input_event_editor_plugin.h"
#include "editor/plugins/light_occluder_2d_editor_plugin.h"
#include "editor/plugins/lightmap_gi_editor_plugin.h"
#include "editor/plugins/line_2d_editor_plugin.h"
#include "editor/plugins/material_editor_plugin.h"
#include "editor/plugins/mesh_editor_plugin.h"
#include "editor/plugins/mesh_instance_3d_editor_plugin.h"
#include "editor/plugins/mesh_library_editor_plugin.h"
#include "editor/plugins/multimesh_editor_plugin.h"
#include "editor/plugins/navigation_link_2d_editor_plugin.h"
#include "editor/plugins/navigation_polygon_editor_plugin.h"
#include "editor/plugins/node_3d_editor_gizmos.h"
#include "editor/plugins/occluder_instance_3d_editor_plugin.h"
#include "editor/plugins/packed_scene_editor_plugin.h"
#include "editor/plugins/path_2d_editor_plugin.h"
#include "editor/plugins/path_3d_editor_plugin.h"
#include "editor/plugins/physical_bone_3d_editor_plugin.h"
#include "editor/plugins/polygon_2d_editor_plugin.h"
#include "editor/plugins/polygon_3d_editor_plugin.h"
#include "editor/plugins/resource_preloader_editor_plugin.h"
#include "editor/plugins/script_editor_plugin.h"
#include "editor/plugins/shader_editor_plugin.h"
#include "editor/plugins/shader_file_editor_plugin.h"
#include "editor/plugins/skeleton_2d_editor_plugin.h"
#include "editor/plugins/skeleton_3d_editor_plugin.h"
#include "editor/plugins/skeleton_ik_3d_editor_plugin.h"
#include "editor/plugins/sprite_2d_editor_plugin.h"
#include "editor/plugins/sprite_frames_editor_plugin.h"
#include "editor/plugins/style_box_editor_plugin.h"
#include "editor/plugins/sub_viewport_preview_editor_plugin.h"
#include "editor/plugins/texture_3d_editor_plugin.h"
#include "editor/plugins/texture_editor_plugin.h"
#include "editor/plugins/texture_layered_editor_plugin.h"
#include "editor/plugins/texture_region_editor_plugin.h"
#include "editor/plugins/theme_editor_plugin.h"
#include "editor/plugins/tiles/tiles_editor_plugin.h"
#include "editor/plugins/version_control_editor_plugin.h"
#include "editor/plugins/visual_shader_editor_plugin.h"
#include "editor/plugins/voxel_gi_editor_plugin.h"

void register_editor_types() {
	ResourceLoader::set_timestamp_on_load(true);
	ResourceSaver::set_timestamp_on_save(true);

	GDREGISTER_CLASS(EditorPaths);
	GDREGISTER_CLASS(EditorPlugin);
	GDREGISTER_CLASS(EditorTranslationParserPlugin);
	GDREGISTER_CLASS(EditorImportPlugin);
	GDREGISTER_CLASS(EditorScript);
	GDREGISTER_CLASS(EditorSelection);
	GDREGISTER_CLASS(EditorFileDialog);
	GDREGISTER_ABSTRACT_CLASS(EditorSettings);
	GDREGISTER_CLASS(EditorNode3DGizmo);
	GDREGISTER_CLASS(EditorNode3DGizmoPlugin);
	GDREGISTER_ABSTRACT_CLASS(EditorResourcePreview);
	GDREGISTER_CLASS(EditorResourcePreviewGenerator);
	GDREGISTER_ABSTRACT_CLASS(EditorFileSystem);
	GDREGISTER_CLASS(EditorFileSystemDirectory);
	GDREGISTER_CLASS(EditorVCSInterface);
	GDREGISTER_ABSTRACT_CLASS(ScriptEditor);
	GDREGISTER_ABSTRACT_CLASS(ScriptEditorBase);
	GDREGISTER_CLASS(EditorSyntaxHighlighter);
	GDREGISTER_ABSTRACT_CLASS(EditorInterface);
	GDREGISTER_CLASS(EditorExportPlugin);
	GDREGISTER_ABSTRACT_CLASS(EditorExportPlatform);
	GDREGISTER_CLASS(EditorResourceConversionPlugin);
	GDREGISTER_CLASS(EditorSceneFormatImporter);
	GDREGISTER_CLASS(EditorScenePostImportPlugin);
	GDREGISTER_CLASS(EditorInspector);
	GDREGISTER_CLASS(EditorInspectorPlugin);
	GDREGISTER_CLASS(EditorProperty);
	GDREGISTER_CLASS(AnimationTrackEditPlugin);
	GDREGISTER_CLASS(ScriptCreateDialog);
	GDREGISTER_CLASS(EditorFeatureProfile);
	GDREGISTER_CLASS(EditorSpinSlider);
	GDREGISTER_CLASS(EditorResourcePicker);
	GDREGISTER_CLASS(EditorScriptPicker);
	GDREGISTER_ABSTRACT_CLASS(EditorUndoRedoManager);

	GDREGISTER_ABSTRACT_CLASS(FileSystemDock);
	GDREGISTER_VIRTUAL_CLASS(EditorFileSystemImportFormatSupportQuery);

	GDREGISTER_CLASS(EditorScenePostImport);
	GDREGISTER_CLASS(EditorCommandPalette);
	GDREGISTER_CLASS(EditorDebuggerPlugin);
	GDREGISTER_ABSTRACT_CLASS(EditorDebuggerSession);

	// This list is alphabetized, and plugins that depend on Node2D are in their own section below.
	EditorPlugins::add_by_type<AnimationTreeEditorPlugin>();
	EditorPlugins::add_by_type<AudioStreamEditorPlugin>();
	EditorPlugins::add_by_type<AudioStreamRandomizerEditorPlugin>();
	EditorPlugins::add_by_type<BitMapEditorPlugin>();
	EditorPlugins::add_by_type<BoneMapEditorPlugin>();
	EditorPlugins::add_by_type<Camera3DEditorPlugin>();
	EditorPlugins::add_by_type<ControlEditorPlugin>();
	EditorPlugins::add_by_type<CPUParticles3DEditorPlugin>();
	EditorPlugins::add_by_type<CurveEditorPlugin>();
	EditorPlugins::add_by_type<DebugAdapterServer>();
	EditorPlugins::add_by_type<FontEditorPlugin>();
	EditorPlugins::add_by_type<GPUParticles3DEditorPlugin>();
	EditorPlugins::add_by_type<GPUParticlesCollisionSDF3DEditorPlugin>();
	EditorPlugins::add_by_type<GradientEditorPlugin>();
	EditorPlugins::add_by_type<GradientTexture2DEditorPlugin>();
	EditorPlugins::add_by_type<InputEventEditorPlugin>();
	EditorPlugins::add_by_type<LightmapGIEditorPlugin>();
	EditorPlugins::add_by_type<MaterialEditorPlugin>();
	EditorPlugins::add_by_type<MeshEditorPlugin>();
	EditorPlugins::add_by_type<MeshInstance3DEditorPlugin>();
	EditorPlugins::add_by_type<MeshLibraryEditorPlugin>();
	EditorPlugins::add_by_type<MultiMeshEditorPlugin>();
	EditorPlugins::add_by_type<OccluderInstance3DEditorPlugin>();
	EditorPlugins::add_by_type<PackedSceneEditorPlugin>();
	EditorPlugins::add_by_type<Path3DEditorPlugin>();
	EditorPlugins::add_by_type<PhysicalBone3DEditorPlugin>();
	EditorPlugins::add_by_type<Polygon3DEditorPlugin>();
	EditorPlugins::add_by_type<ResourcePreloaderEditorPlugin>();
	EditorPlugins::add_by_type<ShaderEditorPlugin>();
	EditorPlugins::add_by_type<ShaderFileEditorPlugin>();
	EditorPlugins::add_by_type<Skeleton3DEditorPlugin>();
	EditorPlugins::add_by_type<SkeletonIK3DEditorPlugin>();
	EditorPlugins::add_by_type<SpriteFramesEditorPlugin>();
	EditorPlugins::add_by_type<StyleBoxEditorPlugin>();
	EditorPlugins::add_by_type<SubViewportPreviewEditorPlugin>();
	EditorPlugins::add_by_type<Texture3DEditorPlugin>();
	EditorPlugins::add_by_type<TextureEditorPlugin>();
	EditorPlugins::add_by_type<TextureLayeredEditorPlugin>();
	EditorPlugins::add_by_type<TextureRegionEditorPlugin>();
	EditorPlugins::add_by_type<ThemeEditorPlugin>();
	EditorPlugins::add_by_type<VoxelGIEditorPlugin>();

	// 2D
	EditorPlugins::add_by_type<CollisionPolygon2DEditorPlugin>();
	EditorPlugins::add_by_type<CollisionShape2DEditorPlugin>();
	EditorPlugins::add_by_type<CPUParticles2DEditorPlugin>();
	EditorPlugins::add_by_type<GPUParticles2DEditorPlugin>();
	EditorPlugins::add_by_type<LightOccluder2DEditorPlugin>();
	EditorPlugins::add_by_type<Line2DEditorPlugin>();
	EditorPlugins::add_by_type<NavigationLink2DEditorPlugin>();
	EditorPlugins::add_by_type<NavigationPolygonEditorPlugin>();
	EditorPlugins::add_by_type<Path2DEditorPlugin>();
	EditorPlugins::add_by_type<Polygon2DEditorPlugin>();
	EditorPlugins::add_by_type<Cast2DEditorPlugin>();
	EditorPlugins::add_by_type<Skeleton2DEditorPlugin>();
	EditorPlugins::add_by_type<Sprite2DEditorPlugin>();
	EditorPlugins::add_by_type<TilesEditorPlugin>();
}

void unregister_editor_types() {
	EditorNode::cleanup();
	if (EditorPaths::get_singleton()) {
		EditorPaths::free();
	}

	EditorResourcePicker::clear_caches();
}
