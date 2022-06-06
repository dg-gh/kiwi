#include "shader_sources/kiwi_sources_deferred_3d.hpp"

#define NORMAL_FUNC_3D \
"	vec3 map_normal(sampler2D a_Tx_map, vec2 a_UV, mat3 a_TBN)		 									\n"\
"	{																									\n"\
"		vec4 nmap = texture(a_Tx_map, a_UV);															\n"\
"		float coeff_T = 2.0 * nmap[0] - 1.0;															\n"\
"		float coeff_B = 2.0 * nmap[1] - 1.0;															\n"\
"		return normalize(coeff_T * a_TBN[0] + coeff_B * a_TBN[1] + nmap[2] * a_TBN[2]);					\n"\
"	}																									\n"

#define PARALLAX_FUNC_3D \
"	vec2 parallax_shift(vec2 a_UV, sampler2D a_Tx_map, int a_RGBA_comp, float a_depth,					\n"\
"		vec3 a_V_dir, mat3 a_TBN)																		\n"\
"	{																									\n"\
"		const float min_layers = 8;																		\n"\
"		const float max_layers = 32;																	\n"\
"		float view_ortho = dot(a_TBN[2], a_V_dir);														\n"\
\
"		float layer_size = 1.0 / mix(max_layers, min_layers, view_ortho);								\n"\
\
"		vec2 UV_shift = (layer_size * a_depth * (texture(a_Tx_map, a_UV)[a_RGBA_comp]) / view_ortho)	\n"\
"			* vec2(dot(a_V_dir, a_TBN[0]), dot(a_V_dir, a_TBN[1]));										\n"\
\
"		vec2  new_UV = a_UV;																			\n"\
"		float current_layer_depth = 0.0;																\n"\
"		float current_depth_map_value = texture(a_Tx_map, new_UV)[a_RGBA_comp];							\n"\
\
"		while (current_layer_depth < current_depth_map_value)											\n"\
"		{																								\n"\
"			new_UV -= UV_shift;																			\n"\
"			current_depth_map_value = texture(a_Tx_map, new_UV)[a_RGBA_comp];							\n"\
"			current_layer_depth += layer_size;															\n"\
"		}																								\n"\
\
"		vec2 previous_UV = new_UV + UV_shift;															\n"\
\
"		float after_depth = current_depth_map_value - current_layer_depth;								\n"\
"		float previous_depth = texture(a_Tx_map, previous_UV)[a_RGBA_comp]								\n"\
"			- current_layer_depth + layer_size;															\n"\
\
"		float weight = after_depth / (after_depth - previous_depth);									\n"\
"		return mix(new_UV, previous_UV, weight);														\n"\
"	}																									\n"

const char* const kiwi::source::deferred_3d_lighting_pass::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	out vec2 screen_XY;																					\n"

		"	vec2 square[4] = { vec2(-1.0, -1.0), vec2(1.0, -1.0), vec2(1.0, 1.0), vec2(-1.0, 1.0) };			\n"

		"	void main()																							\n"
		"	{																									\n"
		"		screen_XY = square[gl_VertexID];																\n"
		"		gl_Position = vec4(square[gl_VertexID], 0.0, 1.0);												\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_lighting_pass::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec2 screen_XY;																					\n"
		"	layout (binding = 0) uniform sampler2D Tx_albedo;													\n"
		"	layout (binding = 1) uniform sampler2D Tx_N_dir;													\n"
		"	layout (binding = 2) uniform sampler2D Tx_Z;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"
		"	layout (binding = 4) uniform sampler2D Tx_lmap;														\n"
		"	out vec4 color;																						\n"


		"	layout (std430, binding = 0) buffer s_skylights { vec4 skylight[][2]; };							\n"

		"	layout (std430, binding = 1) buffer s_pointlights { vec4 pointlight[][3]; };						\n"

		"	layout (std430, binding = 2) buffer s_spotlights { vec4 spotlight[][4]; };							\n"

		"	layout (std430, binding = 3) buffer s_skylight_id { int skylight_id[]; };							\n"
		"	layout (std430, binding = 4) buffer s_pointlight_id { int pointlight_id[]; };						\n"
		"	layout (std430, binding = 5) buffer s_spotlight_id { int spotlight_id[]; };							\n"
		"	uniform uvec3 u_light_count;																		\n"


		"	uniform vec3 u_ambient_light_RGB;																	\n"

		"	uniform mat4 u_view_front_left_up_XYZ;																\n"

		"	uniform vec2 u_scale;																				\n"
		"	uniform vec3 u_tan_half_fov_a_b;																	\n"

		"	float GGX_G(float a_dot_ND, float a_alpha_sq)														\n"
		"	{																									\n"
		"		return a_dot_ND / (a_dot_ND + sqrt(a_alpha_sq													\n"
		"			+ a_dot_ND * (a_dot_ND - a_dot_ND * a_alpha_sq)));											\n"
		"	}																									\n"

		"	float GGX_D(vec3 a_H, vec3 a_N, float a_alpha_sq)													\n"
		"	{																									\n"
		"		float NH = max(dot(a_N, a_H), 0.0);																\n"
		"		float temp = (NH * NH) * (a_alpha_sq - 1.0) + 1.0;												\n"
		"		return (0.318310 * a_alpha_sq) / (temp * temp);													\n"
		"	}																									\n"

		"	vec3 GGX_F(vec3 a_H_dir, vec3 a_V_dir, vec3 a_F0)													\n"
		"	{																									\n"
		"		float temp = 1.0 - dot(a_H_dir, a_V_dir);														\n"
		"		float temp_sq = temp * temp;																	\n"
		"		temp = temp_sq * temp_sq * temp;																\n"
		"		return temp + (1.0 - temp) * a_F0;																\n"
		"	}																									\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec2 UV = 0.5 + 0.5 * screen_XY; 																\n"

		"		vec3 XYZ; 																						\n"
		"		{																								\n"
		"			float depth = u_tan_half_fov_a_b[1] * texture(Tx_Z, UV)[0] + u_tan_half_fov_a_b[2];			\n"
		"			vec2 left_up = (u_tan_half_fov_a_b[0] * depth) * u_scale * screen_XY;						\n"
		"			XYZ = vec3(u_view_front_left_up_XYZ * vec4(depth, left_up, 1.0));							\n"
		"		}																								\n"

		"		vec3 V_dir = normalize(vec3(u_view_front_left_up_XYZ[3]) - XYZ); 								\n"
		"		vec3 N_dir = normalize(vec3(texture(Tx_N_dir, UV)));											\n"
		"		float dot_NV = dot(N_dir, V_dir);																\n"

		"		vec4 RMEC = texture(Tx_RMEC, UV);																\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx_albedo, UV);																\n"
		"		vec3 fresnel = mix(vec3(0.04), vec3(RGBA), RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		// SKYLIGHTS // 4xfl : dir // 4xfl : RGB
		"		for (uint k = 0; k < u_light_count[0]; k++)														\n"
		"		{																								\n"
		"			int n = skylight_id[k];																		\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir = -vec3(skylight[n][0]);														\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					vec3 radiance = dot_NL * vec3(skylight[n][1]);										\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = skylight[n][1][3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"

		// POINTLIGHTS // 4xfl : XYZ // 4xfl : RGB // 4xfl : att
		"		for (uint k = 0; k < u_light_count[1]; k++)														\n"
		"		{																								\n"
		"			int n = pointlight_id[k];																	\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir_unnorm = vec3(pointlight[n][0]) - XYZ;										\n"
		"				vec3 L_dir = normalize(L_dir_unnorm);													\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					float L_dist = length(L_dir_unnorm);												\n"
		"					float att_sqrt = pointlight[n][2][0] * L_dist;										\n"

		"					vec3 radiance = (dot_NL / (pointlight[n][2][1] + att_sqrt * att_sqrt))				\n"
		"						* vec3(pointlight[n][1]);														\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = pointlight[n][1][3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"

		// SPOTLIGHTS // 4xfl : XYZ // 4xfl : dir // 4xfl : RGB // 4xfl : att
		"		for (uint k = 0; k < u_light_count[2]; k++)														\n"
		"		{																								\n"
		"			int n = spotlight_id[k];																	\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir_unnorm = vec3(spotlight[n][0]) - XYZ;										\n"
		"				vec3 L_dir = normalize(L_dir_unnorm);													\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					float L_dist = length(L_dir_unnorm);												\n"
		"					float att_sqrt = spotlight[n][3][0] * L_dist;										\n"

		"					float intensity = smoothstep(spotlight[n][3][2], spotlight[n][3][3],				\n"
		"						-dot(L_dir, normalize(vec3(spotlight[n][1]))))									\n"
		"						* (dot_NL / (spotlight[n][3][1] + att_sqrt * att_sqrt));						\n"
		"					vec3 radiance = intensity * vec3(spotlight[n][2]);									\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = spotlight[n][2][3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"
		"		color = vec4(0.318310 * (max(diff, (0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)					\n"
		"			* vec3(RGBA)) + spec, 1.0);																	\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((RMEC[3] - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_lighting_pass_ortho::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	out vec2 screen_XY;																					\n"

		"	vec2 square[4] = { vec2(-1.0, -1.0), vec2(1.0, -1.0), vec2(1.0, 1.0), vec2(-1.0, 1.0) };			\n"

		"	void main()																							\n"
		"	{																									\n"
		"		screen_XY = square[gl_VertexID];																\n"
		"		gl_Position = vec4(square[gl_VertexID], 0.0, 1.0);												\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_lighting_pass_ortho::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec2 screen_XY;																					\n"
		"	layout (binding = 0) uniform sampler2D Tx_albedo;													\n"
		"	layout (binding = 1) uniform sampler2D Tx_N_dir;													\n"
		"	layout (binding = 2) uniform sampler2D Tx_Z;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"
		"	layout (binding = 4) uniform sampler2D Tx_lmap;														\n"
		"	out vec4 color;																						\n"


		"	layout (std430, binding = 0) buffer s_skylights { vec4 skylight[][2]; };							\n"

		"	layout (std430, binding = 1) buffer s_pointlights { vec4 pointlight[][3]; };						\n"

		"	layout (std430, binding = 2) buffer s_spotlights { vec4 spotlight[][4]; };							\n"

		"	layout (std430, binding = 3) buffer s_skylight_id { int skylight_id[]; };							\n"
		"	layout (std430, binding = 4) buffer s_pointlight_id { int pointlight_id[]; };						\n"
		"	layout (std430, binding = 5) buffer s_spotlight_id { int spotlight_id[]; };							\n"
		"	uniform uvec3 u_light_count;																		\n"


		"	uniform vec3 u_ambient_light_RGB;																	\n"

		"	uniform mat4 u_view_front_left_up_XYZ;																\n"

		"	uniform vec2 u_scale;																				\n"
		"	uniform vec2 u_a_b;																					\n"

		"	float GGX_G(float a_dot_ND, float a_alpha_sq)														\n"
		"	{																									\n"
		"		return a_dot_ND / (a_dot_ND + sqrt(a_alpha_sq													\n"
		"			+ a_dot_ND * (a_dot_ND - a_dot_ND * a_alpha_sq)));											\n"
		"	}																									\n"

		"	float GGX_D(vec3 a_H, vec3 a_N, float a_alpha_sq)													\n"
		"	{																									\n"
		"		float NH = max(dot(a_N, a_H), 0.0);																\n"
		"		float temp = (NH * NH) * (a_alpha_sq - 1.0) + 1.0;												\n"
		"		return (0.318310 * a_alpha_sq) / (temp * temp);													\n"
		"	}																									\n"

		"	vec3 GGX_F(vec3 a_H_dir, vec3 a_V_dir, vec3 a_F0)													\n"
		"	{																									\n"
		"		float temp = 1.0 - dot(a_H_dir, a_V_dir);														\n"
		"		float temp_sq = temp * temp;																	\n"
		"		temp = temp_sq * temp_sq * temp;																\n"
		"		return temp + (1.0 - temp) * a_F0;																\n"
		"	}																									\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec2 UV = 0.5 + 0.5 * screen_XY; 																\n"

		"		vec3 XYZ; 																						\n"
		"		{																								\n"
		"			float depth = u_a_b[0] * texture(Tx_Z, UV)[0] + u_a_b[1];									\n"
		"			XYZ = vec3(u_view_front_left_up_XYZ	* vec4(depth, u_scale * screen_XY, 1.0));				\n"
		"		}																								\n"

		"		vec3 V_dir = normalize(vec3(u_view_front_left_up_XYZ[3]) - XYZ); 								\n"
		"		vec3 N_dir = normalize(vec3(texture(Tx_N_dir, UV)));											\n"
		"		float dot_NV = dot(N_dir, V_dir);																\n"

		"		vec4 RMEC = texture(Tx_RMEC, UV);																\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx_albedo, UV);																\n"
		"		vec3 fresnel = mix(vec3(0.04), vec3(RGBA), RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		// SKYLIGHTS // 4xfl : dir // 4xfl : RGB
		"		for (uint k = 0; k < u_light_count[0]; k++)														\n"
		"		{																								\n"
		"			int n = skylight_id[k];																		\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir = -vec3(skylight[n][0]);														\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					vec3 radiance = dot_NL * vec3(skylight[n][1]);										\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = skylight[n][1][3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"

		// POINTLIGHTS // 4xfl : XYZ // 4xfl : RGB // 4xfl : att
		"		for (uint k = 0; k < u_light_count[1]; k++)														\n"
		"		{																								\n"
		"			int n = pointlight_id[k];																	\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir_unnorm = vec3(pointlight[n][0]) - XYZ;										\n"
		"				vec3 L_dir = normalize(L_dir_unnorm);													\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					float L_dist = length(L_dir_unnorm);												\n"
		"					float att_sqrt = pointlight[n][2][0] * L_dist;										\n"

		"					vec3 radiance = (dot_NL / (pointlight[n][2][1] + att_sqrt * att_sqrt))				\n"
		"						* vec3(pointlight[n][1]);														\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = pointlight[n][1][3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"

		// SPOTLIGHTS // 4xfl : XYZ // 4xfl : dir // 4xfl : RGB // 4xfl : att
		"		for (uint k = 0; k < u_light_count[2]; k++)														\n"
		"		{																								\n"
		"			int n = spotlight_id[k];																	\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir_unnorm = vec3(spotlight[n][0]) - XYZ;										\n"
		"				vec3 L_dir = normalize(L_dir_unnorm);													\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					float L_dist = length(L_dir_unnorm);												\n"
		"					float att_sqrt = spotlight[n][3][0] * L_dist;										\n"

		"					float intensity = smoothstep(spotlight[n][3][2], spotlight[n][3][3],				\n"
		"						-dot(L_dir, normalize(vec3(spotlight[n][1]))))									\n"
		"						* (dot_NL / (spotlight[n][3][1] + att_sqrt * att_sqrt));						\n"
		"					vec3 radiance = intensity * vec3(spotlight[n][2]);									\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = spotlight[n][2][3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"
		"		color = vec4(0.318310 * (max(diff, (0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)					\n"
		"			* vec3(RGBA)) + spec, 1.0);																	\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((RMEC[3] - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"
		"	}																									\n"
		;
}


const char* const kiwi::source::deferred_3d_solid_color::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	out vec3 moved_N_dir;																				\n"
		"	out float view_depth;																				\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_solid_color::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec3 moved_N_dir;																				\n"
		"	in float view_depth;																				\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	uniform vec4 u_RMEC;																				\n"
		"	uniform vec3 u_RGB;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = vec4(u_RGB, 1.0);																	\n"
		"		g_N_dir = vec4(moved_N_dir, 1.0);		 														\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = u_RMEC;																				\n"
		"		g_lmap = vec4(0.0);																				\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_color_gradient_sRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 6) in vec3 in_RGB;																\n"
		"	out vec3 moved_N_dir;																				\n"
		"	out float view_depth;																				\n"
		"	out vec4 RGB1;																						\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		RGB1 = vec4(in_RGB, 1.0);																		\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_color_gradient_sRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec3 moved_N_dir;																				\n"
		"	in float view_depth;																				\n"
		"	in vec4 RGB1;																						\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform vec4 u_RMEC;																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = RGB1;																				\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_N_dir = vec4(moved_N_dir, 1.0);		 														\n"
		"		g_RMEC = u_RMEC;																				\n"
		"		g_lmap = vec4(0.0);																				\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_color_gradient_vRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 6) in vec3 in_RGB;																\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out vec3 moved_N_dir;																				\n"
		"	out float view_depth;																				\n"
		"	out vec4 RGB1;																						\n"
		"	out vec4 RMEC;																						\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		RGB1 = vec4(in_RGB, 1.0);																		\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_color_gradient_vRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec3 moved_N_dir;																				\n"
		"	in float view_depth;																				\n"
		"	in vec4 RGB1;																						\n"
		"	in vec4 RMEC;																						\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = RGB1;																				\n"
		"		g_N_dir = vec4(moved_N_dir, 1.0);																\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));													\n"
		"		g_lmap = vec4(0.0);																				\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_texture_sRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_N_dir;																				\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_texture_sRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec3 moved_N_dir;																				\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform vec4 u_RMEC;																				\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = texture(Tx, UV);																		\n"
		"		g_N_dir = vec4(moved_N_dir, 1.0);																\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = u_RMEC;																				\n"
		"		g_lmap = texture(Tx_lmap, UV);																	\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_texture_vRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out vec3 moved_N_dir;																				\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	out vec4 RMEC;																						\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_texture_vRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec3 moved_N_dir;																				\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	in vec4 RMEC;																						\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = texture(Tx, UV);																		\n"
		"		g_N_dir = vec4(moved_N_dir, 1.0);		 														\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));													\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_texture_mRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_N_dir;																				\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_texture_mRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec3 moved_N_dir;																				\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = texture(Tx, UV);																		\n"
		"		g_N_dir = vec4(moved_N_dir, 1.0);		 														\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = texture(Tx_RMEC, UV);																	\n"
		"		g_RMEC[3] = max(g_RMEC[3], u_C);																\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_normal_sRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out mat3 moved_TBN;																					\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_normal_sRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform vec4 u_RMEC;																				\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		NORMAL_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = texture(Tx, UV);																		\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, UV, moved_TBN), 1.0);		 								\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = u_RMEC;																				\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_normal_vRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out mat3 moved_TBN;																					\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	out vec4 RMEC;																						\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_normal_vRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	in vec4 RMEC;																						\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		NORMAL_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = texture(Tx, UV);																		\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, UV, moved_TBN), 1.0);		 								\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));													\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_normal_mRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out mat3 moved_TBN;																					\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_normal_mRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		NORMAL_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		g_albedo = texture(Tx, UV);																		\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, UV, moved_TBN), 1.0);		 								\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = texture(Tx_RMEC, UV);																	\n"
		"		g_RMEC[3] = max(g_RMEC[3], u_C);																\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_parallax_sRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec4 moved_XYZ1;																				\n"
		"	out mat3 moved_TBN;																					\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		moved_XYZ1 = u_m_M * vec4(in_XYZ, 1.0);															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_parallax_sRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec4 moved_XYZ1;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"
		"	uniform float u_shift_factor;																		\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		NORMAL_FUNC_3D
		PARALLAX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - vec3(moved_XYZ1)); 											\n"
		"		vec2 shifted_UV = parallax_shift(UV, Tx_nmap, 3, u_shift_factor, V_dir,	moved_TBN);				\n"
		"		g_albedo = texture(Tx, shifted_UV);																\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, shifted_UV, moved_TBN), 1.0);								\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = u_RMEC;																				\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_parallax_vRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out vec4 moved_XYZ1;																				\n"
		"	out mat3 moved_TBN;																					\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	out vec4 RMEC;																						\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		moved_XYZ1 = u_m_M * vec4(in_XYZ, 1.0);															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_parallax_vRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec4 moved_XYZ1;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	in vec4 RMEC;																						\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"
		"	uniform float u_shift_factor;																		\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		NORMAL_FUNC_3D
		PARALLAX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - vec3(moved_XYZ1)); 											\n"
		"		vec2 shifted_UV = parallax_shift(UV, Tx_nmap, 3, u_shift_factor, V_dir,	moved_TBN);				\n"
		"		g_albedo = texture(Tx, shifted_UV);																\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, shifted_UV, moved_TBN), 1.0);		 						\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));													\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::deferred_3d_parallax_mRMEC::vertex_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec4 moved_XYZ1;																				\n"
		"	out mat3 moved_TBN;																					\n"
		"	out float view_depth;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"

		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M; 																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		view_depth = gl_Position[2];																	\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		moved_XYZ1 = u_m_M * vec4(in_XYZ, 1.0);															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::deferred_3d_parallax_mRMEC::fragment_shader() noexcept
{
	return

		"	#version 430 core																					\n"
		"	in vec4 moved_XYZ1;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in float view_depth;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"

		"	layout (location = 0) out vec4 g_albedo;															\n"
		"	layout (location = 1) out vec4 g_N_dir;																\n"
		"	layout (location = 2) out vec4 g_Z;																	\n"
		"	layout (location = 3) out vec4 g_RMEC;																\n"
		"	layout (location = 4) out vec4 g_lmap;																\n"

		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"
		"	uniform float u_shift_factor;																		\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		NORMAL_FUNC_3D
		PARALLAX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - vec3(moved_XYZ1)); 											\n"
		"		vec2 shifted_UV = parallax_shift(UV, Tx_nmap, 3, u_shift_factor, V_dir,	moved_TBN);				\n"
		"		g_albedo = texture(Tx, shifted_UV);																\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, shifted_UV, moved_TBN), 1.0);			 					\n"
		"		g_Z = vec4(view_depth, 0.0, 0.0, 1.0); 															\n"
		"		g_RMEC = texture(Tx_RMEC, shifted_UV);															\n"
		"		g_RMEC[3] = max(g_RMEC[3], u_C);																\n"
		"		g_lmap = texture(Tx_lmap, UV_lmap);																\n"
		"	}																									\n"
		;
}