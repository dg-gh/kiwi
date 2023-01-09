#include "shader_sources/kiwi_sources_sprites.hpp"

const char* const kiwi::source::solid_color_sprites_2d::vertex_shader() noexcept
{
	return

		"	#version 430 core													\n"
		"	layout (location = 0) in vec2 in_XY;								\n"
		"	layout (std430, binding = 0) buffer s_XYZA { vec4 XYZA[]; };		\n"
		"	layout (std430, binding = 1) buffer s_RGBA { vec4 RGBA[]; };		\n"
		"	out vec4 _RGBA;														\n"
		"	uniform mat3 u_mvp_M;												\n"

		"	void main()															\n"
		"	{																	\n"
		"		_RGBA = RGBA[gl_InstanceID];									\n"
		"		float C = cos(XYZA[gl_InstanceID][3]);							\n"
		"		float S = sin(XYZA[gl_InstanceID][3]);							\n"
		"		vec3 XY = u_mvp_M * vec3(vec2(XYZA[gl_InstanceID])				\n"
		"			+ mat2(C, S, -S, C) * in_XY, 1.0);							\n"
		"		gl_Position.xy = XY.xy;											\n"
		"		gl_Position.zw = vec2(XYZA[gl_InstanceID][2], 1.0);				\n"
		"	}																	\n"
		;
}
const char* const kiwi::source::solid_color_sprites_2d::fragment_shader() noexcept
{
	return

		"	#version 430 core													\n"
		"	in vec4 _RGBA;														\n"
		"	out vec4 out_color;													\n"

		"	void main()															\n"
		"	{																	\n"
		"		out_color = _RGBA;												\n"
		"	}																	\n"
		;
}

const char* const kiwi::source::texture_sprites_2d::vertex_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	layout (std430, binding = 0) buffer s_XYZA { vec4[] XYZA; };					\n"
		"	layout (std430, binding = 1) buffer s_UV_shift { vec2[] UV;	};					\n"
		"	out vec2 _UV;																	\n"
		"	uniform mat3 u_mvp_M;															\n"
		"	uniform vec4 u_XY_UV_size;														\n"

		"	const vec2 quad_XY[4] = {														\n"
		"		vec2(-0.5, -0.5),															\n"
		"		vec2(0.5, -0.5),															\n"
		"		vec2(0.5, 0.5),																\n"
		"		vec2(-0.5, 0.5)																\n"
		"	};																				\n"

		"	const vec2 quad_UV[4] = {														\n"
		"		vec2(0.0, 0.0),																\n"
		"		vec2(1.0, 0.0),																\n"
		"		vec2(1.0, 1.0),																\n"
		"		vec2(0.0, 1.0)																\n"
		"	};																				\n"

		"	void main()																		\n"
		"	{																				\n"
		"		uint quad_instance_id = gl_VertexID >> 2;									\n"
		"		uint quad_vertex_id = gl_VertexID & uint(3);								\n"

		"		_UV = UV[quad_instance_id] + quad_UV[quad_vertex_id] * u_XY_UV_size.zw;		\n"

		"		float C = cos(XYZA[quad_instance_id][3]);									\n"
		"		float S = sin(XYZA[quad_instance_id][3]);									\n"
		"		vec3 XY = u_mvp_M * vec3(vec2(XYZA[quad_instance_id])						\n"
		"			+ mat2(C, S, -S, C) * (vec2(u_XY_UV_size) * quad_XY[quad_vertex_id]),	\n"
		"			1.0);																	\n"

		"		gl_Position.xy = XY.xy;														\n"
		"		gl_Position.zw = vec2(XYZA[quad_instance_id][2], 1.0);						\n"
		"	}																				\n"
		;
}
const char* const kiwi::source::texture_sprites_2d::fragment_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	in vec2 _UV;																	\n"
		"	out vec4 out_color;																\n"
		"	layout (binding = 0) uniform sampler2D Tx;										\n"
		"	uniform float u_alpha_discard;													\n"

		"	void main()																		\n"
		"	{																				\n"
		"		out_color = texture(Tx, _UV);												\n"
		"		if (out_color[3] < u_alpha_discard)											\n"
		"		{																			\n"
		"			discard;																\n"
		"		}																			\n"
		"	}																				\n"
		;
}

const char* const kiwi::source::texture_array_sprites_2d::vertex_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	layout (std430, binding = 0) buffer s_XYZA { vec4[] XYZA; };					\n"
		"	layout (std430, binding = 1) buffer s_Tx_id { int[] Tx_id;	};					\n"
		"	out vec2 _UV;																	\n"
		"	out float _Tx_id;																\n"
		"	uniform mat3 u_mvp_M;															\n"
		"	uniform vec2 u_XY_size;															\n"

		"	const vec2 quad_XY[4] = {														\n"
		"		vec2(-0.5, -0.5),															\n"
		"		vec2(0.5, -0.5),															\n"
		"		vec2(0.5, 0.5),																\n"
		"		vec2(-0.5, 0.5)																\n"
		"	};																				\n"

		"	const vec2 quad_UV[4] = {														\n"
		"		vec2(0.0, 0.0),																\n"
		"		vec2(1.0, 0.0),																\n"
		"		vec2(1.0, 1.0),																\n"
		"		vec2(0.0, 1.0)																\n"
		"	};																				\n"

		"	void main()																		\n"
		"	{																				\n"
		"		uint quad_instance_id = gl_VertexID >> 2;									\n"
		"		uint quad_vertex_id = gl_VertexID & uint(3);								\n"

		"		_UV = quad_UV[quad_vertex_id];												\n"
		"		_Tx_id = float(Tx_id[quad_instance_id]);									\n"

		"		float C = cos(XYZA[quad_instance_id][3]);									\n"
		"		float S = sin(XYZA[quad_instance_id][3]);									\n"
		"		vec3 XY = u_mvp_M * vec3(vec2(XYZA[quad_instance_id])						\n"
		"			+ mat2(C, S, -S, C) * (u_XY_size * quad_XY[quad_vertex_id]),			\n"
		"			1.0);																	\n"

		"		gl_Position.xy = XY.xy;														\n"
		"		gl_Position.zw = vec2(XYZA[quad_instance_id][2], 1.0);						\n"
		"	}																				\n"
		;
}
const char* const kiwi::source::texture_array_sprites_2d::fragment_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	in vec2 _UV;																	\n"
		"	in float _Tx_id;																\n"
		"	out vec4 out_color;																\n"
		"	layout (binding = 0) uniform sampler2DArray Tx;									\n"
		"	uniform float u_alpha_discard;													\n"

		"	void main()																		\n"
		"	{																				\n"
		"		out_color = texture(Tx, vec3(_UV, _Tx_id));									\n"
		"		if (out_color[3] < u_alpha_discard)											\n"
		"		{																			\n"
		"			discard;																\n"
		"		}																			\n"
		"	}																				\n"
		;
}

const char* const kiwi::source::solid_color_sprite_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core													\n"
		"	layout (location = 0) in vec2 in_XY;								\n"
		"	uniform vec4 u_XYZA;												\n"
		"	uniform mat3 u_mvp_M_2d;											\n"
		"	uniform mat4 u_mvp_M_3d;											\n"
		"	uniform uint u_depth_scaling;										\n"

		"	void main()															\n"
		"	{																	\n"
		"		float C = cos(u_XYZA[3]);										\n"
		"		float S = sin(u_XYZA[3]);										\n"
		"		vec3 XY = u_mvp_M_2d * vec3(mat2(C, S, -S, C) * in_XY, 1.0);	\n"

		"		gl_Position = u_mvp_M_3d * vec4(vec3(u_XYZA), 1.0);				\n"
		"		if (u_depth_scaling == 0)										\n"
		"		{																\n"
		"			gl_Position.xy += gl_Position[3] * XY.xy;					\n"
		"		}																\n"
		"		else															\n"
		"		{																\n"
		"			gl_Position.xy += XY.xy;									\n"
		"		}																\n"
		"	}																	\n"
		;
}
const char* const kiwi::source::solid_color_sprite_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core													\n"
		"	out vec4 out_color;													\n"
		"	uniform vec4 u_RGBA;												\n"

		"	void main()															\n"
		"	{																	\n"
		"		out_color = u_RGBA;												\n"
		"	}																	\n"
		;
}

const char* const kiwi::source::solid_color_sprites_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core													\n"
		"	layout (location = 0) in vec2 in_XY;								\n"
		"	layout (std430, binding = 0) buffer s_XYZA { vec4 XYZA[]; };		\n"
		"	layout (std430, binding = 1) buffer s_RGBA { vec4 RGBA[]; };		\n"
		"	out vec4 _RGBA;														\n"
		"	uniform mat3 u_mvp_M_2d;											\n"
		"	uniform mat4 u_mvp_M_3d;											\n"
		"	uniform uint u_depth_scaling;										\n"

		"	void main()															\n"
		"	{																	\n"
		"		_RGBA = RGBA[gl_InstanceID];									\n"

		"		float C = cos(XYZA[gl_InstanceID][3]);							\n"
		"		float S = sin(XYZA[gl_InstanceID][3]);							\n"
		"		vec3 XY = u_mvp_M_2d * vec3(mat2(C, S, -S, C) * in_XY, 1.0);	\n"

		"		gl_Position = u_mvp_M_3d * vec4(XYZA[gl_InstanceID].xyz, 1.0);	\n"
		"		if (u_depth_scaling == 0)										\n"
		"		{																\n"
		"			gl_Position.xy += gl_Position[3] * XY.xy;					\n"
		"		}																\n"
		"		else															\n"
		"		{																\n"
		"			gl_Position.xy += XY.xy;									\n"
		"		}																\n"
		"	}																	\n"
		;
}
const char* const kiwi::source::solid_color_sprites_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core													\n"
		"	in vec4 _RGBA;														\n"
		"	out vec4 out_color;													\n"

		"	void main()															\n"
		"	{																	\n"
		"		out_color = _RGBA;												\n"
		"	}																	\n"
		;
}

const char* const kiwi::source::texture_sprite_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	layout (location = 0) in vec2 in_XY;											\n"
		"	layout (location = 1) in vec2 in_UV;											\n"
		"	out vec2 UV;																	\n"
		"	uniform vec4 u_XYZA;															\n"
		"	uniform mat3 u_mvp_M_2d;														\n"
		"	uniform mat4 u_mvp_M_3d;														\n"
		"	uniform uint u_depth_scaling;													\n"

		"	void main()																		\n"
		"	{																				\n"
		"		UV = in_UV;																	\n"

		"		float C = cos(u_XYZA[3]);													\n"
		"		float S = sin(u_XYZA[3]);													\n"
		"		vec3 XY = u_mvp_M_2d * vec3(mat2(C, S, -S, C) * in_XY, 1.0);				\n"

		"		gl_Position = u_mvp_M_3d * vec4(vec3(u_XYZA), 1.0);							\n"
		"		if (u_depth_scaling == 0)													\n"
		"		{																			\n"
		"			gl_Position.xy += gl_Position[3] * XY.xy;								\n"
		"		}																			\n"
		"		else																		\n"
		"		{																			\n"
		"			gl_Position.xy += XY.xy;												\n"
		"		}																			\n"
		"	}																				\n"
		;
}
const char* const kiwi::source::texture_sprite_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	in vec2 UV;																		\n"
		"	out vec4 out_color;																\n"
		"	layout (binding = 0) uniform sampler2D Tx;										\n"
		"	uniform float u_alpha_discard;													\n"

		"	void main()																		\n"
		"	{																				\n"
		"		out_color = texture(Tx, UV);												\n"
		"		if (out_color[3] < u_alpha_discard)											\n"
		"		{																			\n"
		"			discard;																\n"
		"		}																			\n"
		"	}																				\n"
		;
}

const char* const kiwi::source::texture_sprites_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	layout (std430, binding = 0) buffer s_XYZA { vec4[] XYZA; };					\n"
		"	layout (std430, binding = 1) buffer s_UV_shift { vec2[] UV;	};					\n"
		"	out vec2 _UV;																	\n"
		"	uniform mat3 u_mvp_M_2d;														\n"
		"	uniform mat4 u_mvp_M_3d;														\n"
		"	uniform uint u_depth_scaling;													\n"
		"	uniform vec4 u_XY_UV_size;														\n"

		"	const vec2 quad_XY[4] = {														\n"
		"		vec2(-0.5, -0.5),															\n"
		"		vec2(0.5, -0.5),															\n"
		"		vec2(0.5, 0.5),																\n"
		"		vec2(-0.5, 0.5)																\n"
		"	};																				\n"

		"	const vec2 quad_UV[4] = {														\n"
		"		vec2(0.0, 0.0),																\n"
		"		vec2(1.0, 0.0),																\n"
		"		vec2(1.0, 1.0),																\n"
		"		vec2(0.0, 1.0)																\n"
		"	};																				\n"

		"	void main()																		\n"
		"	{																				\n"
		"		uint quad_instance_id = gl_VertexID >> 2;									\n"
		"		uint quad_vertex_id = gl_VertexID & uint(3);								\n"

		"		_UV = UV[quad_instance_id] + quad_UV[quad_vertex_id] * u_XY_UV_size.zw;		\n"

		"		float C = cos(XYZA[quad_instance_id][3]);									\n"
		"		float S = sin(XYZA[quad_instance_id][3]);									\n"
		"		vec3 XY = u_mvp_M_2d * vec3(mat2(C, S, -S, C)								\n"
		"			* (vec2(u_XY_UV_size) * quad_XY[quad_vertex_id]), 1.0);					\n"

		"		gl_Position = u_mvp_M_3d * vec4(vec3(XYZA[quad_instance_id]), 1.0);			\n"
		"		if (u_depth_scaling == 0)													\n"
		"		{																			\n"
		"			gl_Position.xy += gl_Position[3] * XY.xy;								\n"
		"		}																			\n"
		"		else																		\n"
		"		{																			\n"
		"			gl_Position.xy += XY.xy;												\n"
		"		}																			\n"
		"	}																				\n"
		;
}
const char* const kiwi::source::texture_sprites_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	in vec2 _UV;																	\n"
		"	out vec4 out_color;																\n"
		"	layout (binding = 0) uniform sampler2D Tx;										\n"
		"	uniform float u_alpha_discard;													\n"

		"	void main()																		\n"
		"	{																				\n"
		"		out_color = texture(Tx, _UV);												\n"
		"		if (out_color[3] < u_alpha_discard)											\n"
		"		{																			\n"
		"			discard;																\n"
		"		}																			\n"
		"	}																				\n"
		;
}

const char* const kiwi::source::texture_array_sprites_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	layout (std430, binding = 0) buffer s_XYZA { vec4[] XYZA; };					\n"
		"	layout (std430, binding = 1) buffer s_Tx_id { int[] Tx_id;	};					\n"
		"	out vec2 _UV;																	\n"
		"	out float _Tx_id;																\n"
		"	uniform mat3 u_mvp_M_2d;														\n"
		"	uniform mat4 u_mvp_M_3d;														\n"
		"	uniform uint u_depth_scaling;													\n"
		"	uniform vec2 u_XY_size;															\n"

		"	const vec2 quad_XY[4] = {														\n"
		"		vec2(-0.5, -0.5),															\n"
		"		vec2(0.5, -0.5),															\n"
		"		vec2(0.5, 0.5),																\n"
		"		vec2(-0.5, 0.5)																\n"
		"	};																				\n"

		"	const vec2 quad_UV[4] = {														\n"
		"		vec2(0.0, 0.0),																\n"
		"		vec2(1.0, 0.0),																\n"
		"		vec2(1.0, 1.0),																\n"
		"		vec2(0.0, 1.0)																\n"
		"	};																				\n"

		"	void main()																		\n"
		"	{																				\n"
		"		uint quad_instance_id = gl_VertexID >> 2;									\n"
		"		uint quad_vertex_id = gl_VertexID & uint(3);								\n"

		"		_UV = quad_UV[quad_vertex_id];												\n"
		"		_Tx_id = float(Tx_id[quad_instance_id]);									\n"

		"		float C = cos(XYZA[quad_instance_id][3]);									\n"
		"		float S = sin(XYZA[quad_instance_id][3]);									\n"
		"		vec3 XY = u_mvp_M_2d * vec3(mat2(C, S, -S, C)								\n"
		"			* (u_XY_size * quad_XY[quad_vertex_id]), 1.0);							\n"

		"		gl_Position = u_mvp_M_3d * vec4(vec3(XYZA[quad_instance_id]), 1.0);			\n"
		"		if (u_depth_scaling == 0)													\n"
		"		{																			\n"
		"			gl_Position.xy += gl_Position[3] * XY.xy;								\n"
		"		}																			\n"
		"		else																		\n"
		"		{																			\n"
		"			gl_Position.xy += XY.xy;												\n"
		"		}																			\n"
		"	}																				\n"
		;
}
const char* const kiwi::source::texture_array_sprites_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core																\n"
		"	in vec2 _UV;																	\n"
		"	in float _Tx_id;																\n"
		"	out vec4 out_color;																\n"
		"	layout (binding = 0) uniform sampler2DArray Tx;									\n"
		"	uniform float u_alpha_discard;													\n"

		"	void main()																		\n"
		"	{																				\n"
		"		out_color = texture(Tx, vec3(_UV, _Tx_id));									\n"
		"		if (out_color[3] < u_alpha_discard)											\n"
		"		{																			\n"
		"			discard;																\n"
		"		}																			\n"
		"	}																				\n"
		;
}