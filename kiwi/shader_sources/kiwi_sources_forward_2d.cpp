#include "shader_sources/kiwi_sources_forward_2d.hpp"

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

#define GGX_FUNC_2D \
"	float GGX_G(float a_dot_ND, float a_alpha_sq)														\n"\
"	{																									\n"\
"		return a_dot_ND / (a_dot_ND + sqrt(a_alpha_sq													\n"\
"			+ a_dot_ND * (a_dot_ND - a_dot_ND * a_alpha_sq)));											\n"\
"	}																									\n"\
\
"	float GGX_D(float a_dot_NH, float a_alpha_sq)														\n"\
"	{																									\n"\
"		float NH = max(a_dot_NH, 0.0);																	\n"\
"		float temp = (NH * NH) * (a_alpha_sq - 1.0) + 1.0;												\n"\
"		return (0.318310 * a_alpha_sq) / (temp * temp);													\n"\
"	}																									\n"\
\
"	vec3 GGX_F(vec3 a_H_dir, vec3 a_V_dir, vec3 a_F0)													\n"\
"	{																									\n"\
"		float temp = 1.0 - dot(a_H_dir, a_V_dir);														\n"\
"		float temp_sq = temp * temp;																	\n"\
"		temp = temp_sq * temp_sq * temp;																\n"\
"		return temp + (1.0 - temp) * a_F0;																\n"\
"	}																									\n"

#define NORMAL_FUNC_2D \
"	vec3 map_normal(sampler2D a_Tx_nmap, vec2 a_UV, mat2 a_TB)		 									\n"\
"	{																									\n"\
"		vec4 nmap = texture(a_Tx_nmap, a_UV);															\n"\
"		float coeff_T = 2.0 * nmap[0] - 1.0;															\n"\
"		float coeff_B = 2.0 * nmap[1] - 1.0;															\n"\
"		return normalize(vec3(coeff_T * a_TB[0] + coeff_B * a_TB[1], nmap[2]));							\n"\
"	}																									\n"

#define GGX_FUNC_2D_NORMAL \
"	float GGX_G(float a_dot_ND, float a_alpha_sq)														\n"\
"	{																									\n"\
"		return 1.0 / (a_dot_ND + sqrt((1.0 - a_alpha_sq) * (a_dot_ND * a_dot_ND) + a_alpha_sq));		\n"\
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

// SKYLIGHTS // 4xfl : dir // 4xfl : RGBD
#define SKYLIGHTS_2D \
"		for (uint k = 0; k < u_light_count[0]; k++)														\n"\
"		{																								\n"\
"			int n = skylight_id[k];																		\n"\
"			if (n >= 0)																					\n"\
"			{																							\n"\
"				float dot_NL = -(skylight[n].dir[2]);													\n"\
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
"						* GGX_D(H_dir[2], alpha_sq))													\n"\
"						* GGX_F_HV * radiance;															\n"\
"				}																						\n"\
"			}																							\n"\
"		}																								\n"

// POINTLIGHTS // 4xfl : XYZ // 4xfl : RGBD // 4xfl : att
#define POINTLIGHTS_2D \
"		for (uint k = 0; k < u_light_count[1]; k++)														\n"\
"		{																								\n"\
"			int n = pointlight_id[k];																	\n"\
"			if (n >= 0)																					\n"\
"			{																							\n"\
"				vec3 L_dir_unnorm = pointlight[n].XYZ - moved_XYZ;										\n"\
"				vec3 L_dir = normalize(L_dir_unnorm);													\n"\
"				float dot_NL = L_dir[2];																\n"\
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
"						* GGX_D(H_dir[2], alpha_sq))													\n"\
"						* GGX_F_HV * radiance;															\n"\
"				}																						\n"\
"			}																							\n"\
"		}																								\n"

// SPOTLIGHTS // 4xfl : XYZ // 4xfl : dir // 4xfl : RGBD // 4xfl : att
#define SPOTLIGHTS_2D \
"		for (uint k = 0; k < u_light_count[2]; k++)														\n"\
"		{																								\n"\
"			int n = spotlight_id[k];																	\n"\
"			if (n >= 0)																					\n"\
"			{																							\n"\
"				vec3 L_dir_unnorm = spotlight[n].XYZ - moved_XYZ;										\n"\
"				vec3 L_dir = normalize(L_dir_unnorm);													\n"\
"				float dot_NL = L_dir[2];																\n"\
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
"						* GGX_D(H_dir[2], alpha_sq))													\n"\
"						* GGX_F_HV * radiance;															\n"\
"				}																						\n"\
"			}																							\n"\
"		}																								\n"


// SKYLIGHTS // 4xfl : dir // 4xfl : RGBD
#define SKYLIGHTS_2D_NORMAL \
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
"		}																								\n"\

// POINTLIGHTS // 4xfl : XYZ // 4xfl : RGBD // 4xfl : att
#define POINTLIGHTS_2D_NORMAL \
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
#define SPOTLIGHTS_2D_NORMAL \
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


const char* const kiwi::source::forward_2d_solid_color::vertex_shader() noexcept
{
	return
		"	#version 330 core																					\n"
		"	layout (location = 0) in vec3 in_XY;																\n"
		"	out vec2 XY;																						\n"
		"	uniform mat3 u_mvp_M;																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);													\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],														\n"
		"			in_XY[2], 1.0);																				\n"

		"		XY = vec2(in_XY);																				\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_2d_solid_color::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec2 XY;																							\n"
		"	out vec4 color;																						\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec4 u_RMEC;																				\n"

		"	uniform vec4 u_RGBA;																				\n"

		"	uniform vec3 u_view_XYZ;																			\n"
		"	uniform mat3 u_m_M;																					\n"

		GGX_FUNC_2D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 moved_XYZ = vec3(vec2(u_m_M * vec3(XY, 1.0)), 0.0); 										\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		float dot_NV = V_dir[2];																		\n"

		"		float alpha_sq = u_RMEC[0] * u_RMEC[0];															\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - u_RMEC[1];																	\n"
		"		vec3 fresnel = mix(vec3(0.04), vec3(u_RGBA), u_RMEC[1]);										\n"

		"		vec3 diff = vec3(3.14159 * u_RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_2D
		POINTLIGHTS_2D
		SPOTLIGHTS_2D

		"		color = vec4(0.318310 * (max(diff, u_ambient_light_RGB)											\n"
		"			* vec3(u_RGBA)) + spec, u_RGBA[3]);															\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > u_RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((u_RMEC[3] - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_2d_color_gradient_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 330 core																					\n"
		"	layout (location = 0) in vec3 in_XY;																\n"
		"	layout (location = 6) in vec4 in_RGBA;																\n"
		"	layout (location = 7) in vec4 in_RMEC;																\n"
		"	out vec2 XY;																						\n"
		"	out vec4 RGBA;																						\n"
		"	out vec4 RMEC;																						\n"
		"	uniform mat3 u_mvp_M;																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);													\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],														\n"
		"			in_XY[2], 1.0);																				\n"

		"		XY = vec2(in_XY);																				\n"
		"		RGBA = in_RGBA;																					\n"
		"		RMEC = in_RMEC;																					\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_2d_color_gradient_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec2 XY;																							\n"
		"	in vec4 RGBA;																						\n"
		"	in vec4 RMEC;																						\n"
		"	out vec4 color;																						\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"

		"	uniform vec3 u_view_XYZ;																			\n"
		"	uniform mat3 u_m_M;																					\n"

		GGX_FUNC_2D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 moved_XYZ = vec3(vec2(u_m_M * vec3(XY, 1.0)), 0.0); 										\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		float dot_NV = V_dir[2];																		\n"

		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec3 fresnel = mix(vec3(0.04), vec3(RGBA), RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * RMEC[2]);															\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_2D
		POINTLIGHTS_2D
		SPOTLIGHTS_2D

		"		color = vec4(0.318310 * (max(diff, u_ambient_light_RGB)											\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		if (M > RMEC[3])																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((RMEC[3] - m) / (M - m)) * (vec3(color) - m);								\n"
		"		}																								\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_2d_texture_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 330 core																					\n"
		"	layout (location = 0) in vec3 in_XY;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec2 XY;																						\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat3 u_mvp_M;																				\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);													\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],														\n"
		"			in_XY[2], 1.0);																				\n"

		"		XY = vec2(in_XY);																				\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_2d_texture_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec2 XY;																							\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	out vec4 color;																						\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec2 u_ECx;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"
		"	uniform mat3 u_m_M;																					\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		GGX_FUNC_2D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 moved_XYZ = vec3(vec2(u_m_M * vec3(XY, 1.0)), 0.0); 										\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		float dot_NV = V_dir[2];																		\n"

		"		vec4 RMEC = texture(Tx_RMEC, UV);																\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.04), vec3(RGBA), RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_ECx[0] * RMEC[2]);													\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_2D
		POINTLIGHTS_2D
		SPOTLIGHTS_2D

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)), u_ambient_light_RGB)		\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = u_ECx[1] * RMEC[3];																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"
		"	}																									\n"
		;
}

const char* const kiwi::source::forward_2d_normal_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 330 core																					\n"
		"	layout (location = 0) in vec3 in_XY;																\n"
		"	layout (location = 1) in vec2 in_T_dir;																\n"
		"	layout (location = 2) in vec2 in_B_dir;																\n"
		"	layout (location = 4) in vec2 in_UV;																\n"
		"	layout (location = 5) in vec2 in_UV_lmap;															\n"
		"	out vec3 moved_XYZ;																					\n"
		"	out mat2 moved_TB;																					\n"
		"	out vec2 UV;																						\n"
		"	out vec2 UV_lmap;																					\n"
		"	uniform mat3 u_mvp_M;																				\n"
		"	uniform mat3 u_m_M;																					\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 temp = vec3(vec2(in_XY), 1.0);																\n"
		"		vec3 in_XYh = u_mvp_M * temp;																	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],														\n"
		"			in_XY[2], 1.0);																				\n"

		"		moved_XYZ = u_m_M * temp;																		\n"
		"		moved_XYZ[2] = 0.0;																				\n"
		"		moved_TB = mat2(u_m_M) * mat2(in_T_dir, in_B_dir);												\n"
		"		UV = in_UV;																						\n"
		"		UV_lmap = in_UV_lmap;																			\n"
		"	}																									\n"
		;
}
const char* const kiwi::source::forward_2d_normal_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core																					\n"
		"	in vec3 moved_XYZ;																					\n"
		"	in mat2 moved_TB;																					\n"
		"	in vec2 UV;																							\n"
		"	in vec2 UV_lmap;																					\n"
		"	out vec4 color;																						\n"

		LIGHTSET_BUFFERS

		"	uniform vec3 u_ambient_light_RGB;																	\n"
		"	uniform vec2 u_ECx;																					\n"

		"	uniform vec3 u_view_XYZ;																			\n"

		"	layout (binding = 0) uniform sampler2D Tx;															\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;														\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;														\n"

		GGX_FUNC_2D_NORMAL
		NORMAL_FUNC_2D

		"	void main()																							\n"
		"	{																									\n"
		"		vec3 V_dir = normalize(u_view_XYZ - moved_XYZ); 												\n"
		"		vec3 moved_N_dir = map_normal(Tx_nmap, UV, moved_TB);											\n"
		"		float dot_NV = dot(moved_N_dir, V_dir);															\n"

		"		vec4 RMEC = texture(Tx_RMEC, UV);																\n"
		"		float alpha_sq = RMEC[0] * RMEC[0];																\n"
		"		alpha_sq = alpha_sq * alpha_sq;																	\n"
		"		float GGX_G_NV = GGX_G(dot_NV, alpha_sq);														\n"

		"		float dielec = 1.0 - RMEC[1];																	\n"
		"		vec4 RGBA = texture(Tx, UV);																	\n"
		"		vec3 fresnel = mix(vec3(0.04), vec3(RGBA), RMEC[1]);											\n"

		"		vec3 diff = vec3(3.14159 * u_ECx[0] * RMEC[2]);													\n"
		"		vec3 spec = vec3(0.0);																			\n"

		SKYLIGHTS_2D_NORMAL
		POINTLIGHTS_2D_NORMAL
		SPOTLIGHTS_2D_NORMAL

		"		color = vec4(0.318310 * (max(diff + vec3(texture(Tx_lmap, UV_lmap)),							\n"
		"			(0.5 + 0.5 * dot_NV) * u_ambient_light_RGB)													\n"
		"			* vec3(RGBA)) + spec, RGBA[3]);																\n"

		"		float M = max(max(color[0], color[1]), color[2]);												\n"
		"		float ceiling = u_ECx[1] * RMEC[3];																\n"
		"		if (M > ceiling)																				\n"
		"		{																								\n"
		"			float m = min(min(min(color[0], color[1]), color[2]), 1.0);									\n"
		"			color.xyz = m + ((ceiling - m) / (M - m)) * (color.xyz - m);								\n"
		"		}																								\n"
		"	}																									\n"
		;
}