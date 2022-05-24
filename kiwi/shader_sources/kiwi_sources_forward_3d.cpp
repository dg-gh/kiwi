#include "shader_sources/kiwi_sources_forward_3d.hpp"

#define LIGHTSET_BUFFERS \
"	struct skylight_t { vec3 dir; vec4 RGBD; };															\n"\
"	layout (std430, binding = 0) buffer s_skylights { skylight_t skylight[]; };							\n"\
\
"	struct pointlight_t { vec3 XYZ; vec4 RGBD; vec2 att; };												\n"\
"	layout (std430, binding = 1) buffer s_pointlights { pointlight_t pointlight[]; };					\n"\
\
"	struct spotlight_t { vec3 XYZ; vec3 dir; vec4 RGBD; vec4 att; };									\n"\
"	layout (std430, binding = 2) buffer s_spotlights { spotlight_t spotlight[]; };						\n"\
\
"	layout (std430, binding = 3) buffer s_skylight_id { int skylight_id[]; };							\n"\
"	layout (std430, binding = 4) buffer s_pointlight_id { int pointlight_id[]; };						\n"\
"	layout (std430, binding = 5) buffer s_spotlight_id { int spotlight_id[]; };							\n"\
"	uniform uvec3 u_light_count;																		\n"

#define GGX_FUNC_3D \
"	float GGX_G(float a_dot_ND, float a_alpha_sq)														\n"\
"	{																									\n"\
"		return a_dot_ND / (a_dot_ND + sqrt(a_alpha_sq													\n"\
"			+ a_dot_ND * (a_dot_ND - a_dot_ND * a_alpha_sq)));											\n"\
"	}																									\n"\
\
"	float GGX_D(vec3 a_H, vec3 a_N, float a_alpha_sq)													\n"\
"	{																									\n"\
"		float NH = max(dot(a_N, a_H), 0.0);																\n"\
"		float temp = (NH * NH) * (a_alpha_sq - 1.0) + 1.0;												\n"\
"		return (0.318310 * a_alpha_sq) / (temp * temp);													\n"\
"	}																									\n"\
\
"	vec3 GGX_F(vec3 a_H_dir, vec3 a_V_dir, vec3 a_F0)													\n"\
"	{																									\n"\
"		float temp = 1.0 - dot(a_H_dir, a_V_dir);														\n"\
"		float temp_sq = temp * temp;																	\n"\
"		return vec3(temp) + (1.0 - (temp_sq * temp_sq) * temp) * a_F0;									\n"\
"	}																									\n"

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

// SKYLIGHTS // 4xfl : dir // 4xfl : RGBD
#define SKYLIGHTS_3D \
"		for (uint k = 0; k < u_light_count[0]; k++)														\n"\
"		{																								\n"\
"			int n = skylight_id[k];																		\n"\
"			if (n >= 0)																					\n"\
"			{																							\n"\
"				float dot_NL = -dot(moved_N_dir, skylight[n].dir);										\n"\
\
"				if (dot_NL > 0.0)																		\n"\
"				{																						\n"\
"					vec3 radiance = dot_NL * vec3(skylight[n].RGBD);									\n"\
\
"					vec3 H_dir = normalize(V_dir - skylight[n].dir);									\n"\
"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"\
\
"					float temp = skylight[n].RGBD[3] * dielec;											\n"\
"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"\
\
"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"\
"						* GGX_D(H_dir, moved_N_dir, alpha_sq))											\n"\
"						* GGX_F_HV * radiance;															\n"\
"				}																						\n"\
"			}																							\n"\
"		}																								\n"

// POINTLIGHTS // 4xfl : XYZ // 4xfl : RGBD // 4xfl : att
#define POINTLIGHTS_3D \
"		for (uint k = 0; k < u_light_count[1]; k++)														\n"\
"		{																								\n"\
"			int n = pointlight_id[k];																	\n"\
"			if (n >= 0)																					\n"\
"			{																							\n"\
"				vec3 L_dir_unnorm = pointlight[n].XYZ - moved_XYZ;										\n"\
"				vec3 L_dir = normalize(L_dir_unnorm);													\n"\
"				float dot_NL = dot(moved_N_dir, L_dir);													\n"\
\
"				if (dot_NL > 0.0)																		\n"\
"				{																						\n"\
"					float L_dist = length(L_dir_unnorm);												\n"\
"					float att_sqrt = pointlight[n].att[0] * L_dist;										\n"\
\
"					vec3 radiance = (dot_NL / (pointlight[n].att[1] + att_sqrt * att_sqrt))				\n"\
"						* vec3(pointlight[n].RGBD);														\n"\
\
"					vec3 H_dir = normalize(L_dir + V_dir);												\n"\
"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"\
\
"					float temp = pointlight[n].RGBD[3] * dielec;										\n"\
"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"\
\
"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"\
"						* GGX_D(H_dir, moved_N_dir, alpha_sq))											\n"\
"						* GGX_F_HV * radiance;															\n"\
"				}																						\n"\
"			}																							\n"\
"		}																								\n"

// SPOTLIGHTS // 4xfl : XYZ // 4xfl : dir // 4xfl : RGBD // 4xfl : att
#define SPOTLIGHTS_3D \
"		for (uint k = 0; k < u_light_count[2]; k++)														\n"\
"		{																								\n"\
"			int n = spotlight_id[k];																	\n"\
"			if (n >= 0)																					\n"\
"			{																							\n"\
"				vec3 L_dir_unnorm = spotlight[n].XYZ - moved_XYZ;										\n"\
"				vec3 L_dir = normalize(L_dir_unnorm);													\n"\
"				float dot_NL = dot(moved_N_dir, L_dir);													\n"\
\
"				if (dot_NL > 0.0)																		\n"\
"				{																						\n"\
"					float L_dist = length(L_dir_unnorm);												\n"\
"					float att_sqrt = spotlight[n].att[0] * L_dist;										\n"\
\
"					float intensity = smoothstep(spotlight[n].att[2], spotlight[n].att[3],				\n"\
"						-dot(L_dir, normalize(spotlight[n].dir)))										\n"\
"						* (dot_NL / (spotlight[n].att[1] + att_sqrt * att_sqrt));						\n"\
"					vec3 radiance = intensity * vec3(spotlight[n].RGBD);								\n"\
\
"					vec3 H_dir = normalize(L_dir + V_dir);												\n"\
"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"\
\
"					float temp = spotlight[n].RGBD[3] * dielec;											\n"\
"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"\
\
"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"\
"						* GGX_D(H_dir, moved_N_dir, alpha_sq))											\n"\
"						* GGX_F_HV * radiance;															\n"\
"				}																						\n"\
"			}																							\n"\
"		}																								\n"


const char* const kiwi::source::forward_3d_solid_color::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out vec3 _moved_N_dir;																				\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		_moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_solid_color::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in vec3 _moved_N_dir;																				\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec4 u_RGBA;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		GGX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = normalize(_moved_N_dir); 													\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = u_RMEC[0] * u_RMEC[0];															\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - u_RMEC[1];																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(u_RGBA), u_RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff, (0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)					\n"
		"			* vec3(u_RGBA)) + spec, u_RGBA[3]);															\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > u_RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((u_RMEC[3] - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_color_gradient_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 6) in vec4 in_RGBA;																\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out vec3 _moved_N_dir;																				\n"
		"	out vec4 RGBA;																						\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		_moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		RGBA = in_RGBA;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_color_gradient_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in vec3 _moved_N_dir;																				\n"
		"	in vec4 RGBA;																						\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		GGX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = normalize(_moved_N_dir); 													\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = u_RMEC[0] * u_RMEC[0];															\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - u_RMEC[1];																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), u_RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		// CLOSING
		"		color = vec4(0.318310 * (max(diff, (0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)					\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > u_RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((u_RMEC[3] - m) / (M - m)) * (vec3(color) - m);							\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_color_gradient_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 6) in vec4 in_RGBA;																\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out vec3 _moved_N_dir;																				\n"
		"	out vec4 RGBA;																						\n"
		"	out vec4 RMEC;																						\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		_moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		RGBA = in_RGBA;																					\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_color_gradient_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in vec3 _moved_N_dir;																				\n"
		"	in vec4 RGBA;																						\n"
		"	in vec4 RMEC;																						\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		GGX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = normalize(_moved_N_dir); 													\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff, (0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)					\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (vec3(color) - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_texture_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out vec3 _moved_N_dir;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		_moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_texture_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in vec3 _moved_N_dir;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"

		GGX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = normalize(_moved_N_dir); 													\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = u_RMEC[0] * u_RMEC[0];															\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - u_RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), u_RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(u_RMEC[3], 1.0);															\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_texture_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out vec3 _moved_N_dir;																				\n"
		"	out vec4 RMEC;																						\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		_moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		RMEC = in_RMEC;																					\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_texture_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in vec3 _moved_N_dir;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	in vec4 RMEC;																						\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"

		GGX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = normalize(_moved_N_dir); 													\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_texture_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out vec3 _moved_N_dir;																				\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		_moved_N_dir = mat3(u_m_M) * in_N_dir;															\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_texture_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in vec3 _moved_N_dir;																				\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		GGX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = normalize(_moved_N_dir); 													\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		vec4 RMEC = texture(Tx_RMEC, UV);																\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_normal_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat3 moved_TBN;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_normal_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		GGX_FUNC_3D
		NORMAL_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, UV, moved_TBN); 											\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = u_RMEC[0] * u_RMEC[0];															\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - u_RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), u_RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > u_RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((u_RMEC[3] - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_normal_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	layout (location = 6) in vec4 in_RMEC;																\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat3 moved_TBN;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	out vec4 RMEC;																						\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_normal_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	in vec4 RMEC;																						\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		GGX_FUNC_3D
		NORMAL_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, UV, moved_TBN); 											\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_normal_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat3 moved_TBN;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_normal_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		GGX_FUNC_3D
		NORMAL_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, UV, moved_TBN); 											\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		vec4 RMEC = texture(Tx_RMEC, UV);																\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_parallax_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat3 moved_TBN;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_parallax_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	uniform float u_shift_factor;																		\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		GGX_FUNC_3D
		NORMAL_FUNC_3D
		PARALLAX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec2 shifted_UV = parallax_shift(UV, Tx_nmap, 3, u_shift_factor, V_dir,	moved_TBN);				\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, shifted_UV, moved_TBN); 									\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = u_RMEC[0] * u_RMEC[0];															\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - u_RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, shifted_UV);															\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), u_RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > u_RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((u_RMEC[3] - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_parallax_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	layout (location = 6) in vec4 in_RMEC;																\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat3 moved_TBN;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	out vec4 RMEC;																						\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_parallax_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	in vec4 RMEC;																						\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	uniform float u_shift_factor;																		\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"

		GGX_FUNC_3D
		NORMAL_FUNC_3D
		PARALLAX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec2 shifted_UV = parallax_shift(UV, Tx_nmap, 3, u_shift_factor, V_dir, moved_TBN);				\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, shifted_UV, moved_TBN); 									\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, shifted_UV);															\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_3d_parallax_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	layout (location = 0) in vec3 in_XYZ;																\n"
		"	layout (location = 1) in vec3 in_T_dir;																\n"
		"	layout (location = 2) in vec3 in_B_dir;																\n"
		"	layout (location = 3) in vec3 in_N_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat3 moved_TBN;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat4 u_mvp_M;																				\n"
		"	uniform mat4 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);														\n"
		"		moved_XYZ = vec3(u_m_M * vec4(in_XYZ, 1.0));													\n"
		"		moved_TBN = mat3(u_m_M) * mat3(in_T_dir, in_B_dir, in_N_dir);									\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_3d_parallax_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat3 moved_TBN;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	layout (location = 0) out vec4 color;																\n"
		"	layout (location = 1) out vec4 normal_vec;															\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform float u_C;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	uniform float u_shift_factor;																		\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		GGX_FUNC_3D
		NORMAL_FUNC_3D
		PARALLAX_FUNC_3D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec2 shifted_UV = parallax_shift(UV, Tx_nmap, 3, u_shift_factor, V_dir,	moved_TBN);				\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, shifted_UV, moved_TBN); 									\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		vec4 RMEC = texture(Tx_RMEC, shifted_UV);														\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, shifted_UV);															\n"
		"		vec3 fresnel = mix(vec3(0.4), vec3(RGBA), RMEC[1]);												\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_3D
		POINTLIGHTS_3D
		SPOTLIGHTS_3D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = max(RMEC[3], u_C);																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"

		"		normal_vec = vec4(moved_N_dir, 1.0);															\n"
		"	}																									\n"
		;
}