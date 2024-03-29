#include "shader_sources/kiwi_sources_bloom.hpp"

const char* const kiwi::source::bloom_threshold::vertex_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	out vec2 UV;																				\n"

		"	vec2 quad_XY[4] = {																			\n"
		"		vec2(-1.0, -1.0),																		\n"
		"		vec2(1.0, -1.0),																		\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(-1.0, 1.0)																			\n"
		"	};																							\n"

		"	vec2 quad_UV[4] = {																			\n"
		"		vec2(0.0, 0.0),																			\n"
		"		vec2(1.0, 0.0),																			\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(0.0, 1.0)																			\n"
		"	};																							\n"

		"	void main()																					\n"
		"	{																							\n"
		"		gl_Position = vec4(quad_XY[gl_VertexID], 0.0, 1.0);										\n"
		"		UV = quad_UV[gl_VertexID];																\n"
		"	}																							\n"
		;
}
const char* const kiwi::source::bloom_threshold::fragment_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	in vec2 UV;																					\n"
		"	out vec4 out_color;																			\n"
		"	uniform sampler2D Tx;																		\n"
		"	uniform float u_threshold;																	\n"

		"	void main()																					\n"
		"	{																							\n"
		"		out_color = texture(Tx, UV);															\n"

		"		float pass_factor1 = 0.5 * (max(max(out_color[0], out_color[1]), out_color[2])			\n"
		"			- u_threshold);																		\n"

		"		float pass_factor2 = 0.5 * (out_color[0] + out_color[1] + out_color[2]					\n"
		"			- min(min(out_color[0], out_color[1]), out_color[2]))								\n"
		"			- u_threshold;																		\n"

		"		float pass_factor = max(pass_factor1, pass_factor2);									\n"

		"		if (pass_factor < 0.0)																	\n"
		"		{																						\n"
		"			out_color = vec4(0.0);																\n"
		"		}																						\n"
		"		else																					\n"
		"		{																						\n"
		"			out_color.xyz *= pass_factor;														\n"
		"		}																						\n"
		"	}																							\n"
		;
}

const char* const kiwi::source::bloom_gaussian_filter::vertex_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	out vec2 UV;																				\n"

		"	vec2 quad_XY[4] = {																			\n"
		"		vec2(-1.0, -1.0),																		\n"
		"		vec2(1.0, -1.0),																		\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(-1.0, 1.0)																			\n"
		"	};																							\n"

		"	vec2 quad_UV[4] = {																			\n"
		"		vec2(0.0, 0.0),																			\n"
		"		vec2(1.0, 0.0),																			\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(0.0, 1.0)																			\n"
		"	};																							\n"

		"	void main()																					\n"
		"	{																							\n"
		"		gl_Position = vec4(quad_XY[gl_VertexID], 0.0, 1.0);										\n"
		"		UV = quad_UV[gl_VertexID];																\n"
		"	}																							\n"
		;
}
const char* const kiwi::source::bloom_gaussian_filter::fragment_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	in vec2 UV;																					\n"
		"	layout (location = 0) out vec4 out_color;													\n"
		"	uniform sampler2D Tx;																		\n"
		"	uniform float u_distance;																	\n"
		"	uniform int u_horizontal;																	\n"
		"	uniform vec2 u_scale;																		\n"

		"	float weight[5] = { 0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216 };					\n"

		"	void main()																					\n"
		"	{																							\n"
		"		vec3 RGB = weight[0] * vec3(texture(Tx, UV)); 											\n"

		"		if (u_horizontal == 1)																	\n"
		"		{																						\n"
		"			float d = u_scale[0] * u_distance;													\n"
		"			for (uint n = 1; n < 5; n++)														\n"
		"			{																					\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV - vec2(n * d, 0.0)));					\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV + vec2(n * d, 0.0)));					\n"
		"			}																					\n"
		"		}																						\n"
		"		else																					\n"
		"		{																						\n"
		"			float d = u_scale[1] * u_distance;													\n"
		"			for (uint n = 1; n < 5; n++)														\n"
		"			{																					\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV - vec2(0.0, n * d)));					\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV + vec2(0.0, n * d)));					\n"
		"			}																					\n"
		"		}																						\n"
		"		out_color = vec4(RGB, 1.0);																\n"
		"	}																							\n"
		;
}

const char* const kiwi::source::bloom_blend_4_layers::vertex_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	out vec2 UV;																				\n"

		"	vec2 quad_XY[4] = {																			\n"
		"		vec2(-1.0, -1.0),																		\n"
		"		vec2(1.0, -1.0),																		\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(-1.0, 1.0)																			\n"
		"	};																							\n"

		"	vec2 quad_UV[4] = {																			\n"
		"		vec2(0.0, 0.0),																			\n"
		"		vec2(1.0, 0.0),																			\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(0.0, 1.0)																			\n"
		"	};																							\n"

		"	void main()																					\n"
		"	{																							\n"
		"		gl_Position = vec4(quad_XY[gl_VertexID], 0.0, 1.0);										\n"
		"		UV = quad_UV[gl_VertexID];																\n"
		"	}																							\n"
		;
}
const char* const kiwi::source::bloom_blend_4_layers::fragment_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	in vec2 UV;																					\n"
		"	out vec4 out_color;																			\n"
		"	layout (binding = 3) uniform sampler2D Tx0;													\n"
		"	layout (binding = 2) uniform sampler2D Tx1;													\n"
		"	layout (binding = 1) uniform sampler2D Tx2;													\n"
		"	layout (binding = 0) uniform sampler2D Tx3;													\n"
		"	uniform vec3 u_blend;																		\n"

		"	void main()																					\n"
		"	{																							\n"
		"		out_color = vec4(vec3(texture(Tx0, UV))													\n"
		"			+ u_blend[0] * vec3(texture(Tx1, UV))												\n"
		"			+ u_blend[1] * vec3(texture(Tx2, UV))												\n"
		"			+ u_blend[2] * vec3(texture(Tx3, UV)),												\n"
		"			1.0);																				\n"
		"	}																							\n"
		;
}

const char* const kiwi::source::bloom_blend_8_layers::vertex_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	out vec2 UV;																				\n"

		"	vec2 quad_XY[4] = {																			\n"
		"		vec2(-1.0, -1.0),																		\n"
		"		vec2(1.0, -1.0),																		\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(-1.0, 1.0)																			\n"
		"	};																							\n"

		"	vec2 quad_UV[4] = {																			\n"
		"		vec2(0.0, 0.0),																			\n"
		"		vec2(1.0, 0.0),																			\n"
		"		vec2(1.0, 1.0),																			\n"
		"		vec2(0.0, 1.0)																			\n"
		"	};																							\n"

		"	void main()																					\n"
		"	{																							\n"
		"		gl_Position = vec4(quad_XY[gl_VertexID], 0.0, 1.0);										\n"
		"		UV = quad_UV[gl_VertexID];																\n"
		"	}																							\n"
		;
}
const char* const kiwi::source::bloom_blend_8_layers::fragment_shader() noexcept
{
	return

		"	#version 430 core																			\n"
		"	in vec2 UV;																					\n"
		"	out vec4 out_color;																			\n"
		"	layout (binding = 7) uniform sampler2D Tx0;													\n"
		"	layout (binding = 6) uniform sampler2D Tx1;													\n"
		"	layout (binding = 5) uniform sampler2D Tx2;													\n"
		"	layout (binding = 4) uniform sampler2D Tx3;													\n"
		"	layout (binding = 3) uniform sampler2D Tx4;													\n"
		"	layout (binding = 2) uniform sampler2D Tx5;													\n"
		"	layout (binding = 1) uniform sampler2D Tx6;													\n"
		"	layout (binding = 0) uniform sampler2D Tx7;													\n"
		"	uniform vec3 u_blend;																		\n"
		"	uniform vec4 u_blend_extended;																\n"

		"	void main()																					\n"
		"	{																							\n"
		"		out_color = vec4(vec3(texture(Tx0, UV))													\n"
		"			+ u_blend[0] * vec3(texture(Tx1, UV))												\n"
		"			+ u_blend[1] * vec3(texture(Tx2, UV))												\n"
		"			+ u_blend[2] * vec3(texture(Tx3, UV))												\n"
		"			+ u_blend_extended[0] * vec3(texture(Tx4, UV))										\n"
		"			+ u_blend_extended[1] * vec3(texture(Tx5, UV))										\n"
		"			+ u_blend_extended[2] * vec3(texture(Tx6, UV))										\n"
		"			+ u_blend_extended[3] * vec3(texture(Tx7, UV)),										\n"
		"			1.0);																				\n"
		"	}																							\n"
		;
}