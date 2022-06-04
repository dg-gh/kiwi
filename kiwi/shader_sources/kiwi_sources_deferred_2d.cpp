#include "shader_sources/kiwi_sources_deferred_2d.hpp"

#define NORMAL_FUNC_2D \
"	vec3 map_normal(sampler2D a_Tx_nmap, vec2 a_UV, mat2 a_TB)		 									\n"\
"	{																									\n"\
"		vec4 nmap = texture(a_Tx_nmap, a_UV);															\n"\
"		float coeff_T = 2.0 * nmap[0] - 1.0;															\n"\
"		float coeff_B = 2.0 * nmap[1] - 1.0;															\n"\
"		return normalize(vec3(coeff_T * a_TB[0] + coeff_B * a_TB[1], nmap[2]));							\n"\
"	}																									\n"

const char* const kiwi::source::deferred_2d_lighting_pass::vertex_shader() noexcept
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
const char* const kiwi::source::deferred_2d_lighting_pass::fragment_shader() noexcept
{
	return
		
		"	#version 430 core																					\n"
		"	in vec2 screen_XY;																					\n"
		"	layout (binding = 0) uniform sampler2D Tx_albedo;													\n"
		"	layout (binding = 1) uniform sampler2D Tx_N_dir;													\n"
		"	layout (binding = 2) uniform sampler2D Tx_RMEC;														\n"
		"	layout (binding = 3) uniform sampler2D Tx_lmap;														\n"
		"	out vec4 color;																						\n"


		"	struct skylight_t { vec3 dir; vec4 RGBD; };															\n"\
		"	layout (std430, binding = 0) buffer s_skylights { skylight_t skylight[]; };							\n"\
		\
		"	struct pointlight_t { vec3 XYZ; vec4 RGBD; vec2 att; };												\n"\
		"	layout (std430, binding = 1) buffer s_pointlights { pointlight_t pointlight[]; };					\n"\
		\
		"	struct spotlight_t { vec3 XYZ; vec3 dir; vec4 RGBD; vec4 att; };									\n"\
		"	layout (std430, binding = 2) buffer s_spotlights { spotlight_t spotlight[]; };						\n"\

		"	layout (std430, binding = 3) buffer s_skylight_id { int skylight_id[]; };							\n"
		"	layout (std430, binding = 4) buffer s_pointlight_id { int pointlight_id[]; };						\n"
		"	layout (std430, binding = 5) buffer s_spotlight_id { int spotlight_id[]; };							\n"
		"	uniform uvec3 u_light_count;																		\n"


		"	uniform vec3 u_ambient_light_RGB;																	\n"

		"	uniform mat3 u_view_right_up_XY;																	\n"
		"	uniform float u_view_Z;																				\n"

		"	uniform vec2 u_scale;																				\n"


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
		"		return a_F0 + (temp - temp * a_F0);																\n"
		"	}																									\n"

		"	void main()																							\n"
		"	{																									\n"
		"		vec2 UV = 0.5 + 0.5 * screen_XY; 																\n"

		"		vec3 XYZ = vec3(vec2(u_view_right_up_XY * vec3(u_scale * screen_XY, 1.0)), 0.0); 				\n"

		"		vec3 V_dir = normalize(vec3(vec2(u_view_right_up_XY[2]), u_view_Z) - XYZ); 						\n"
		"		vec3 N_dir = vec3(texture(Tx_N_dir, UV));														\n"
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

		// SKYLIGHTS // 4xfl : dir // 4xfl : RGBD
		"		for (uint k = 0; k < u_light_count[0]; k++)														\n"
		"		{																								\n"
		"			int n = skylight_id[k];																		\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				float dot_NL = -dot(N_dir, skylight[n].dir);											\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					vec3 radiance = dot_NL * vec3(skylight[n].RGBD);									\n"

		"					vec3 H_dir = normalize(V_dir - skylight[n].dir);									\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = skylight[n].RGBD[3] * dielec;											\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"

		// POINTLIGHTS // 4xfl : XYZ // 4xfl : RGBD // 4xfl : att
		"		for (uint k = 0; k < u_light_count[1]; k++)														\n"
		"		{																								\n"
		"			int n = pointlight_id[k];																	\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir_unnorm = pointlight[n].XYZ - XYZ;											\n"
		"				vec3 L_dir = normalize(L_dir_unnorm);													\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					float L_dist = length(L_dir_unnorm);												\n"
		"					float att_sqrt = pointlight[n].att[0] * L_dist;										\n"

		"					vec3 radiance = (dot_NL / (pointlight[n].att[1] + att_sqrt * att_sqrt))				\n"
		"						* vec3(pointlight[n].RGBD);														\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = pointlight[n].RGBD[3] * dielec;										\n"
		"					diff += (temp - temp * GGX_F_HV) * radiance;										\n"

		"					spec += (GGX_G(dot_NL, alpha_sq) * GGX_G_NV											\n"
		"						* GGX_D(H_dir, N_dir, alpha_sq))												\n"
		"						* GGX_F_HV * radiance;															\n"
		"				}																						\n"
		"			}																							\n"
		"		}																								\n"

		// SPOTLIGHTS // 4xfl : XYZ // 4xfl : dir // 4xfl : RGBD // 4xfl : att
		"		for (uint k = 0; k < u_light_count[2]; k++)														\n"
		"		{																								\n"
		"			int n = spotlight_id[k];																	\n"
		"			if (n >= 0)																					\n"
		"			{																							\n"
		"				vec3 L_dir_unnorm = spotlight[n].XYZ - XYZ;												\n"
		"				vec3 L_dir = normalize(L_dir_unnorm);													\n"
		"				float dot_NL = dot(N_dir, L_dir);														\n"

		"				if (dot_NL > 0.0)																		\n"
		"				{																						\n"
		"					float L_dist = length(L_dir_unnorm);												\n"
		"					float att_sqrt = spotlight[n].att[0] * L_dist;										\n"

		"					float intensity = smoothstep(spotlight[n].att[2], spotlight[n].att[3],				\n"
		"						-dot(L_dir, normalize(spotlight[n].dir)))										\n"
		"						* (dot_NL / (spotlight[n].att[1] + att_sqrt * att_sqrt));						\n"
		"					vec3 radiance = intensity * vec3(spotlight[n].RGBD);								\n"

		"					vec3 H_dir = normalize(L_dir + V_dir);												\n"
		"					vec3 GGX_F_HV = GGX_F(H_dir, V_dir, fresnel);										\n"

		"					float temp = spotlight[n].RGBD[3] * dielec;											\n"
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

const char* const kiwi::source::deferred_2d_solid_color::vertex_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"

		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"
		"	}													\n"
		;
}
const char* const kiwi::source::deferred_2d_solid_color::fragment_shader() noexcept
{
	return
		"	#version 430 core									\n"

		"	layout (location = 0) out vec4 g_albedo;			\n"
		"	layout (location = 1) out vec4 g_N_dir;				\n"
		"	layout (location = 2) out vec4 g_RMEC;				\n"
		"	layout (location = 3) out vec4 g_lmap;				\n"

		"	uniform vec3 u_RGB;									\n"
		"	uniform vec4 u_RMEC;								\n"

		"	void main()											\n"
		"	{													\n"
		"		g_albedo = vec4(u_RGB, 1.0);					\n"
		"		g_N_dir = vec4(0.0, 0.0, 1.0, 1.0);				\n"
		"		g_RMEC = u_RMEC;								\n"
		"		g_lmap = vec4(0.0);								\n"
		"	}													\n"
		;
}

const char* const kiwi::source::deferred_2d_color_gradient_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 6) in vec3 in_RGB;				\n"
		"	out vec4 RGB1;										\n"

		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		RGB1 = vec4(in_RGB, 1.0);						\n"
		"	}													\n"
		;
}
const char* const kiwi::source::deferred_2d_color_gradient_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	in vec4 RGB1;										\n"

		"	layout (location = 0) out vec4 g_albedo;			\n"
		"	layout (location = 1) out vec4 g_N_dir;				\n"
		"	layout (location = 2) out vec4 g_RMEC;				\n"
		"	layout (location = 3) out vec4 g_lmap;				\n"

		"	uniform vec4 u_RGBA;								\n"
		"	uniform vec4 u_RMEC;								\n"

		"	void main()											\n"
		"	{													\n"
		"		g_albedo = u_RGBA;								\n"
		"		g_N_dir = vec4(0.0, 0.0, 1.0, 1.0);				\n"
		"		g_RMEC = u_RMEC;								\n"
		"		g_lmap = vec4(0.0);								\n"
		"	}													\n"
		;
}

const char* const kiwi::source::deferred_2d_color_gradient_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 6) in vec3 in_RGB;				\n"
		"	layout (location = 7) in vec4 in_RMEC;				\n"
		"	out vec4 RGB1;										\n"
		"	out vec4 RMEC;										\n"

		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		RGB1 = vec4(in_RGB, 1.0);						\n"
		"		RMEC = in_RMEC;									\n"
		"	}													\n"
		;
}
const char* const kiwi::source::deferred_2d_color_gradient_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	in vec4 RGB1;										\n"
		"	in vec4 RMEC;										\n"

		"	layout (location = 0) out vec4 g_albedo;			\n"
		"	layout (location = 1) out vec4 g_N_dir;				\n"
		"	layout (location = 2) out vec4 g_RMEC;				\n"
		"	layout (location = 3) out vec4 g_lmap;				\n"

		"	uniform float u_C;									\n"

		"	void main()											\n"
		"	{													\n"
		"		g_albedo = RGB1;								\n"
		"		g_N_dir = vec4(0.0, 0.0, 1.0, 1.0);				\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));	\n"
		"		g_lmap = vec4(0.0);								\n"
		"	}													\n"
		;
}

const char* const kiwi::source::deferred_2d_texture_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 4) in vec2 in_UV;				\n"
		"	layout (location = 5) in vec2 in_UV_lmap;			\n"
		"	out vec2 UV;										\n"
		"	out vec2 UV_lmap;									\n"

		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		UV = in_UV;										\n"
		"		UV_lmap = in_UV_lmap;							\n"
		"	}													\n"
		;
}
const char* const kiwi::source::deferred_2d_texture_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	in vec2 UV;											\n"
		"	in vec2 UV_lmap;									\n"

		"	layout (location = 0) out vec4 g_albedo;			\n"
		"	layout (location = 1) out vec4 g_N_dir;				\n"
		"	layout (location = 2) out vec4 g_RMEC;				\n"
		"	layout (location = 3) out vec4 g_lmap;				\n"

		"	uniform vec4 u_RMEC;								\n"

		"	layout (binding = 0) uniform sampler2D Tx;			\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;		\n"

		"	void main()											\n"
		"	{													\n"
		"		g_albedo = texture(Tx, UV);						\n"
		"		g_N_dir = vec4(0.0, 0.0, 1.0, 1.0);				\n"
		"		g_RMEC = u_RMEC;								\n"
		"		g_lmap = texture(Tx_lmap, UV);					\n"
		"	}													\n"
		;
}

const char* const kiwi::source::deferred_2d_texture_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 4) in vec2 in_UV;				\n"
		"	layout (location = 5) in vec2 in_UV_lmap;			\n"
		"	layout (location = 7) in vec4 in_RMEC;				\n"
		"	out vec2 UV;										\n"
		"	out vec2 UV_lmap;									\n"
		"	out vec4 RMEC;										\n"

		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		UV = in_UV;										\n"
		"		UV_lmap = in_UV_lmap;							\n"
		"		RMEC = in_RMEC;									\n"
		"	}													\n"
		;
}
const char* const kiwi::source::deferred_2d_texture_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	in vec2 UV;											\n"
		"	in vec2 UV_lmap;									\n"
		"	in vec4 RMEC;										\n"

		"	layout (location = 0) out vec4 g_albedo;			\n"
		"	layout (location = 1) out vec4 g_N_dir;				\n"
		"	layout (location = 2) out vec4 g_RMEC;				\n"
		"	layout (location = 3) out vec4 g_lmap;				\n"

		"	uniform float u_C;									\n"

		"	layout (binding = 0) uniform sampler2D Tx;			\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;		\n"

		"	void main()											\n"
		"	{													\n"
		"		g_albedo = texture(Tx, UV);						\n"
		"		g_N_dir = vec4(0.0, 0.0, 1.0, 1.0);				\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));	\n"
		"		g_lmap = texture(Tx_lmap, UV);					\n"
		"	}													\n"
		;
}

const char* const kiwi::source::deferred_2d_texture_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 4) in vec2 in_UV;				\n"
		"	layout (location = 5) in vec2 in_UV_lmap;			\n"
		"	out vec2 UV;										\n"
		"	out vec2 UV_lmap;									\n"
		"	out vec4 RMEC;										\n"

		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		UV = in_UV;										\n"
		"		UV_lmap = in_UV_lmap;							\n"
		"	}													\n"
		;
}
const char* const kiwi::source::deferred_2d_texture_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core									\n"
		"	in vec2 UV;											\n"
		"	in vec2 UV_lmap;									\n"

		"	layout (location = 0) out vec4 g_albedo;			\n"
		"	layout (location = 1) out vec4 g_N_dir;				\n"
		"	layout (location = 2) out vec4 g_RMEC;				\n"
		"	layout (location = 3) out vec4 g_lmap;				\n"

		"	uniform float u_C;									\n"

		"	layout (binding = 0) uniform sampler2D Tx;			\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;		\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;		\n"

		"	void main()											\n"
		"	{													\n"
		"		g_albedo = texture(Tx, UV);						\n"
		"		g_N_dir = vec4(0.0, 0.0, 1.0, 1.0);				\n"
		"		g_RMEC = texture(Tx_RMEC, UV);					\n"
		"		g_RMEC[3] = max(g_RMEC[3], u_C);				\n"
		"		g_lmap = texture(Tx_lmap, UV);					\n"
		"	}													\n"
		;
}

const char* const kiwi::source::deferred_2d_normal_sRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core												\n"
		"	layout (location = 0) in vec3 in_XY;							\n"
		"	layout (location = 1) in vec2 in_T_dir;							\n"
		"	layout (location = 2) in vec2 in_B_dir;							\n"
		"	layout (location = 4) in vec2 in_UV;							\n"
		"	layout (location = 5) in vec2 in_UV_lmap;						\n"
		"	out vec2 UV;													\n"
		"	out vec2 UV_lmap;												\n"
		"	out mat2 moved_TB;												\n"

		"	uniform mat3 u_mvp_M;											\n"
		"	uniform mat3 u_m_M; 											\n"

		"	void main()														\n"
		"	{																\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);				\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],					\n"
		"			in_XY[2], 1.0);											\n"

		"		UV = in_UV;													\n"
		"		UV_lmap = in_UV_lmap;										\n"
		"		moved_TB = mat2(u_m_M) * mat2(in_T_dir, in_B_dir);			\n"
		"	}																\n"
		;
}
const char* const kiwi::source::deferred_2d_normal_sRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core												\n"
		"	in vec2 UV;														\n"
		"	in vec2 UV_lmap;												\n"
		"	in mat2 moved_TB;												\n"

		"	layout (location = 0) out vec4 g_albedo;						\n"
		"	layout (location = 1) out vec4 g_N_dir;							\n"
		"	layout (location = 2) out vec4 g_RMEC;							\n"
		"	layout (location = 3) out vec4 g_lmap;							\n"

		"	uniform vec4 u_RMEC;											\n"

		"	layout (binding = 0) uniform sampler2D Tx;						\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;					\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;					\n"

		NORMAL_FUNC_2D

		"	void main()														\n"
		"	{																\n"
		"		g_albedo = texture(Tx, UV);									\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, UV, moved_TB), 1.0);		\n"
		"		g_RMEC = u_RMEC;											\n"
		"		g_lmap = texture(Tx_lmap, UV);								\n"
		"	}																\n"
		;
}

const char* const kiwi::source::deferred_2d_normal_vRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core												\n"
		"	layout (location = 0) in vec3 in_XY;							\n"
		"	layout (location = 1) in vec2 in_T_dir;							\n"
		"	layout (location = 2) in vec2 in_B_dir;							\n"
		"	layout (location = 4) in vec2 in_UV;							\n"
		"	layout (location = 5) in vec2 in_UV_lmap;						\n"
		"	layout (location = 7) in vec4 in_RMEC;							\n"
		"	out vec2 UV;													\n"
		"	out vec2 UV_lmap;												\n"
		"	out vec4 RMEC;													\n"
		"	out mat2 moved_TB;												\n"

		"	uniform mat3 u_mvp_M;											\n"
		"	uniform mat3 u_m_M; 											\n"

		"	void main()														\n"
		"	{																\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);				\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],					\n"
		"			in_XY[2], 1.0);											\n"

		"		UV = in_UV;													\n"
		"		UV_lmap = in_UV_lmap;										\n"
		"		RMEC = in_RMEC;												\n"
		"		moved_TB = mat2(u_m_M) * mat2(in_T_dir, in_B_dir);			\n"
		"	}																\n"
		;
}
const char* const kiwi::source::deferred_2d_normal_vRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core												\n"
		"	in vec2 UV;														\n"
		"	in vec2 UV_lmap;												\n"
		"	in vec4 RMEC;													\n"
		"	in mat2 moved_TB;												\n"

		"	layout (location = 0) out vec4 g_albedo;						\n"
		"	layout (location = 1) out vec4 g_N_dir;							\n"
		"	layout (location = 2) out vec4 g_RMEC;							\n"
		"	layout (location = 3) out vec4 g_lmap;							\n"

		"	uniform float u_C;												\n"

		"	layout (binding = 0) uniform sampler2D Tx;						\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;					\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;					\n"

		NORMAL_FUNC_2D

		"	void main()														\n"
		"	{																\n"
		"		g_albedo = texture(Tx, UV);									\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, UV, moved_TB), 1.0);		\n"
		"		g_RMEC = vec4(vec3(RMEC), max(RMEC[3], u_C));				\n"
		"		g_lmap = texture(Tx_lmap, UV);								\n"
		"	}																\n"
		;
}

const char* const kiwi::source::deferred_2d_normal_mRMEC::vertex_shader() noexcept
{
	return
		"	#version 430 core												\n"
		"	layout (location = 0) in vec3 in_XY;							\n"
		"	layout (location = 1) in vec2 in_T_dir;							\n"
		"	layout (location = 2) in vec2 in_B_dir;							\n"
		"	layout (location = 4) in vec2 in_UV;							\n"
		"	layout (location = 5) in vec2 in_UV_lmap;						\n"
		"	out vec2 UV;													\n"
		"	out vec2 UV_lmap;												\n"
		"	out vec4 RMEC;													\n"
		"	out mat2 moved_TB;												\n"

		"	uniform mat3 u_mvp_M;											\n"
		"	uniform mat3 u_m_M; 											\n"

		"	void main()														\n"
		"	{																\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);				\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],					\n"
		"			in_XY[2], 1.0);											\n"

		"		UV = in_UV;													\n"
		"		UV_lmap = in_UV_lmap;										\n"
		"		moved_TB = mat2(u_m_M) * mat2(in_T_dir, in_B_dir);			\n"
		"	}																\n"
		;
}
const char* const kiwi::source::deferred_2d_normal_mRMEC::fragment_shader() noexcept
{
	return
		"	#version 430 core												\n"
		"	in vec2 UV;														\n"
		"	in vec2 UV_lmap;												\n"
		"	in mat2 moved_TB;												\n"

		"	layout (location = 0) out vec4 g_albedo;						\n"
		"	layout (location = 1) out vec4 g_N_dir;							\n"
		"	layout (location = 2) out vec4 g_RMEC;							\n"
		"	layout (location = 3) out vec4 g_lmap;							\n"

		"	uniform float u_C;												\n"

		"	layout (binding = 0) uniform sampler2D Tx;						\n"
		"	layout (binding = 1) uniform sampler2D Tx_lmap;					\n"
		"	layout (binding = 2) uniform sampler2D Tx_nmap;					\n"
		"	layout (binding = 3) uniform sampler2D Tx_RMEC;					\n"

		NORMAL_FUNC_2D

		"	void main()														\n"
		"	{																\n"
		"		g_albedo = texture(Tx, UV);									\n"
		"		g_N_dir = vec4(map_normal(Tx_nmap, UV, moved_TB), 1.0);		\n"
		"		g_RMEC = texture(Tx_RMEC, UV);								\n"
		"		g_RMEC[3] = max(g_RMEC[3], u_C);							\n"
		"		g_lmap = texture(Tx_lmap, UV);								\n"
		"	}																\n"
		;
}