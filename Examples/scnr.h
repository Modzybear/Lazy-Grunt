struct scnr
{
	dependency dont_use;
	dependency wont_use;
	dependency cant_use;
	block_pointer skies;
	uint16_t type;
	uint16_t flags;
	block_pointer child_scenarios;
	float local_north;
	char unknown1[0xa0];
	block_pointer predicted_resources;
	block_pointer functions;
	uint32_t editor_scenario_data;
	block_pointer comments;
	char unknown2[0xec];
	block_pointer object_names;
	block_pointer scenery;
	block_pointer scenery_palette;
	block_pointer bipeds;
	block_pointer biped_palette;
	block_pointer vehicle;
	block_pointer vehicle_palette;
	block_pointer equipment;
	block_pointer equipment_palette;
	block_pointer weapons;
	block_pointer weapon_palette;
	block_pointer device_groups;
	block_pointer machines;
	block_pointer machine_palette;
	block_pointer controls;
	block_pointer control_palette;
	block_pointer light_fixtures;
	block_pointer light_fixtures_palette;
	block_pointer sound_scenery;
	block_pointer sound_scenery_palette;
	char unknown3[0x60];
	block_pointer player_starting_profile;
	block_pointer player_starting_locations;
	block_pointer trigger_volumes;
	block_pointer recorded_animations;
	block_pointer netgame_flags;
	block_pointer netgame_equipment;
	block_pointer starting_equipment;
	block_pointer bsp_switch_trigger_volumes;
	block_pointer decals;
	block_pointer decal_palette;
	block_pointer detail_object_collection_palette;
	char unknown4[0x60];
	block_pointer actor_palette;
	block_pointer encounters;
	block_pointer command_lists;
	block_pointer ai_animation_references;
	block_pointer ai_script_references;
	block_pointer ai_recording_references;
	block_pointer ai_conversations;
	uint32_t script_syntax_data;
	uint32_t script_string_data;
	block_pointer scripts;
	block_pointer globals;
	block_pointer references;
	char unknown5[0x30];
	block_pointer cutscene_flags;
	block_pointer cutscene_camera_points;
	block_pointer cutscene_titles;
	char unknown6[0x78];
	dependency custom_object_names;
	dependency ingame_help_text;
	dependency hud_messages;
	block_pointer structure_bsps;
};

struct skies
{
	dependency sky;
};

struct child_scenarios
{
	dependency child_scenario;
};

struct predicted_resources
{
	uint16_t type;
	uint16_t resource_index;
	uint16_t tag_index;
};

struct functions
{
	uint16_t flags;
	char [4] name;
	float period;
	uint32_t scale_period_by;
	uint16_t function;
	uint32_t scale_function_by;
	uint16_t wobble_function;
	float wobble_period;
	float wobble_magnitude;
	float square_wave_threshold;
	uint16_t step_count;
	uint16_t map_to;
	uint16_t sawtooth_count;
	uint32_t scale_result_by;
	uint16_t bounds_mode;
	float bounds_from;
	float bounds_to;
	uint32_t turn_off_with;
};

struct comments
{
	float position_x;
	float position_y;
	float position_z;
	uint32_t comment;
	block_pointer comment;
};

struct comment
{
	string128 comment;
};

struct object_names
{
	char [4] name;
};

struct scenery
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
};

struct scenery_palette
{
	dependency name;
};

struct bipeds
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	char unknown1[0x2c];
	float body_vitality;
	uint16_t flags;
};

struct biped_palette
{
	dependency name;
};

struct vehicle
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	char unknown1[0x2c];
	float body_vitality;
	uint16_t flags;
	char multiplayer_team_index;
	uint16_t multiplayer_spawn_flags;
};

struct vehicle_palette
{
	dependency name;
};

struct equipment
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	uint16_t miscellaneous_flags;
};

struct equipment_palette
{
	dependency name;
};

struct weapons
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	char unknown1[0x2c];
	uint16_t rounds_left;
	uint16_t rounds_loaded;
	uint16_t miscellaneous_flags;
};

struct weapon_palette
{
	dependency name;
};

struct device_groups
{
	char [4] name;
	float initial_value;
	uint16_t flags;
};

struct machines
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	uint32_t power_group;
	uint32_t position_group;
	uint16_t flags_1;
	uint16_t flags_2;
};

struct machine_palette
{
	dependency name;
};

struct controls
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	uint32_t power_group;
	uint32_t position_group;
	uint16_t flags_1;
	uint16_t flags_2;
	uint16_t dont_touch_this;
};

struct control_palette
{
	dependency name;
};

struct light_fixtures
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
	uint32_t power_group;
	uint32_t position_group;
	uint16_t flags_1;
	colorRGB color;
	float intensity;
	float falloff_angle;
	float cutoff_angle;
};

struct light_fixtures_palette
{
	dependency name;
};

struct sound_scenery
{
	uint32_t type;
	uint32_t name;
	uint16_t not_placed;
	uint16_t desired_permutation;
	float position_x;
	float position_y;
	float position_z;
	float rotation_y;
	float rotation_p;
	float rotation_r;
};

struct sound_scenery_palette
{
	dependency name;
};

struct player_starting_profile
{
	char [4] name;
	float starting_health_modifier;
	float starting_shield_modifier;
	dependency primary_weapon;
	uint16_t primary_weapon_rounds_loaded;
	uint16_t primary_weapon_rounds_left;
	dependency secondary_weapon;
	uint16_t secondary_weapon_rounds_loaded;
	uint16_t secondary_weapon_rounds_left;
	char starting_fragmentation_grenade_count;
	char starting_plasma_grenade_count;
	char starting_unknown_1_grenade_count;
	char starting_unknown_2_grenade_count;
};

struct player_starting_locations
{
	float position_x;
	float position_y;
	float position_z;
	float facing;
	uint16_t team_index;
	uint16_t bsp_index;
	uint16_t type_0;
	uint16_t type_1;
	uint16_t type_2;
	uint16_t type_3;
};

struct trigger_volumes
{
	char [4] name;
};

struct recorded_animations
{
	char [4] name;
	char version;
	char raw_animation_data;
	uint16_t unit_control_data_version;
	uint16_t length_of_animation;
	uint32_t recorded_animation_event_stream;
};

struct netgame_flags
{
	float position_x;
	float position_y;
	float position_z;
	float facing;
	uint16_t type;
	uint16_t team_index;
	dependency weapon_group;
};

struct netgame_equipment
{
	uint16_t flags;
	uint16_t type_0;
	uint16_t type_1;
	uint16_t type_2;
	uint16_t type_3;
	uint16_t team_index;
	uint16_t spawn_time;
	char unknown1[0x32];
	float position_x;
	float position_y;
	float position_z;
	float facing;
	dependency item_collection;
};

struct starting_equipment
{
	uint16_t flags;
	uint16_t type_0;
	uint16_t type_1;
	uint16_t type_2;
	uint16_t type_3;
	char unknown1[0x32];
	dependency item_collection_1;
	dependency item_collection_2;
	dependency item_collection_3;
	dependency item_collection_4;
	dependency item_collection_5;
	dependency item_collection_6;
};

struct bsp_switch_trigger_volumes
{
	uint32_t trigger_volume;
	uint16_t source;
	uint16_t destination;
};

struct decals
{
	uint32_t decal_type;
	int8 yaw;
	int8 pitch;
	float position_x;
	float position_y;
	float position_z;
};

struct decal_palette
{
	dependency reference;
};

struct detail_object_collection_palette
{
	dependency name;
};

struct actor_palette
{
	dependency reference;
};

struct encounters
{
	char [4] name;
	uint16_t flags;
	uint16_t team_index;
	uint16_t search_behavior;
	uint16_t manual_bsp_index;
	float respawn_delay_from;
	float respawn_delay_to;
	char unknown1[0x50];
	block_pointer squads;
	block_pointer platoons;
	block_pointer firing_positions;
	block_pointer player_starting_locations;
};

struct squads
{
	char [4] name;
	uint32_t actor_type;
	uint16_t initial_state;
	uint16_t return_state;
	uint16_t flags;
	uint16_t unique_leader_type;
	float squad_delay_time;
	uint16_t attacking;
	uint16_t attacking_search;
	uint16_t attacking_guard;
	uint16_t defending;
	uint16_t defending_search_careful_unreliable;
	uint16_t defending_guard;
	uint16_t pursuing;
	uint16_t normal_difficulty_count;
	uint16_t insane_difficulty_count;
	uint16_t major_upgrade;
	uint16_t respawn_minimum_actors;
	uint16_t respawn_maximum_actors;
	uint16_t respawn_total;
	float respawn_delay_from;
	float respawn_delay_to;
	char unknown1[0x34];
	block_pointer move_positions;
	block_pointer starting_locations;
};

struct move_positions
{
	float position_x;
	float position_y;
	float position_z;
	float facing;
	float weight;
	float time_from;
	float time_to;
	uint32_t animations;
	char sequence_id;
	char unknown1[0x2e];
	uint32_t surface_index;
};

struct starting_locations
{
	float position_x;
	float position_y;
	float position_z;
	float facing;
	char sequence_id;
	bit flags;
	uint16_t return__state;
	uint16_t initial_state;
	uint32_t actor_type;
	uint32_t command_list;
};

struct platoons
{
	char [4] name;
	uint16_t flags;
	uint16_t change_attacking_or_defending_status_when;
	uint16_t maneuver_when;
};

struct firing_positions
{
	float position_x;
	float position_y;
	float position_z;
	uint16_t group_index;
};

struct player_starting_locations
{
	float position_x;
	float position_y;
	float position_z;
	float facing;
	uint16_t team_index;
	uint16_t bsp_index;
	uint16_t type_0;
	uint16_t type_1;
	uint16_t type_2;
	uint16_t type_3;
};

struct command_lists
{
	char [4] name;
	uint16_t flags;
	uint16_t manual_bsp_index;
	block_pointer commands;
	block_pointer points;
};

struct commands
{
	uint16_t atom_type;
	uint16_t atom_modifier;
	float parameter_1;
	float parameter_2;
	uint32_t animation;
	uint32_t script;
	uint32_t recording;
	uint32_t object_name;
};

struct points
{
	float position_x;
	float position_y;
	float position_z;
};

struct ai_animation_references
{
	char [4] animation_name;
	dependency animation_graph;
};

struct ai_script_references
{
	char [4] script_name;
};

struct ai_recording_references
{
	char [4] recording_name;
};

struct ai_conversations
{
	char [4] name;
	uint16_t flags;
	float trigger_distance;
	float runtoplayer_distance;
	block_pointer participants;
	block_pointer lines;
};

struct participants
{
	uint16_t flags;
	uint16_t selection_type;
	uint16_t actor_type;
	uint32_t use_this_object;
	uint32_t set_new_name;
	char [4] encounter_name;
};

struct lines
{
	uint16_t flags;
	uint16_t addressee;
	float line_delay_time;
	dependency variant_1;
	dependency variant_2;
	dependency variant_3;
	dependency variant_4;
	dependency variant_5;
	dependency variant_6;
};

struct scripts
{
	char [4] name;
	uint16_t script_type;
	uint16_t return_type;
	uint32_t root_expression_index;
};

struct globals
{
	char [4] name;
	uint16_t type;
	uint32_t initialization_expression_index;
};

struct references
{
	dependency reference;
};

struct cutscene_flags
{
	char [4] name;
	float position_x;
	float position_y;
	float position_z;
	float facing_y;
	float facing_p;
};

struct cutscene_camera_points
{
	char [4] name;
	float position_x;
	float position_y;
	float position_z;
	float orientation_y;
	float orientation_p;
	float orientation_r;
	float field_of_view;
};

struct cutscene_titles
{
	char [4] name;
	uint16_t text_bounds_on_screen_t;
	uint16_t text_bounds_on_screen_l;
	uint16_t text_bounds_on_screen_b;
	uint16_t text_bounds_on_screen_r;
	uint16_t string_index;
	uint16_t justification;
	uint8_t text_color;
	uint8_t shadow_color;
	float fade_in_time;
	float up_time;
	float fade_out_time;
};

struct structure_bsps
{
	uint32_t bsp_start;
	uint32_t bsp_size;
	uint32_t bsp_magic;
	dependency structure_bsp;
};

