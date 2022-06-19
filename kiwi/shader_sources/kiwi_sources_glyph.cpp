#include "shader_sources/kiwi_sources_glyph.hpp"

const char* const kiwi::source::glyph_2d::vertex_shader() noexcept
{
	return
		"	#version 430 core																		\n"
		"	struct XY_UV_shift_t { vec2 XY; vec2 UV; };												\n"
		"	layout (std430, binding = 0) buffer s_XY_UV_shift { XY_UV_shift_t[] u_XY_UV_shift; };	\n"
		"	uniform vec4 u_XY_UV_size;																\n"
		"	uniform mat3 u_mvp_M;																	\n"
		"	out vec2 UV;																			\n"

		"	vec2 square[4] = { vec2(0.0, 0.0), vec2(1.0, 0.0), vec2(1.0, 1.0), vec2(0.0, 1.0) };	\n"

		"	void main()																				\n"
		"	{																						\n"
		"		uint quad_instance_id = gl_VertexID >> 2;											\n"
		"		uint quad_vertex_id = gl_VertexID & uint(3);										\n"
		"		vec3 in_XYh = u_mvp_M * vec3(u_XY_UV_shift[quad_instance_id].XY						\n"
		"			+ square[quad_vertex_id] * u_XY_UV_size.xy, 1.0);								\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1], 0.0, 1.0);									\n"

		"		UV = u_XY_UV_shift[quad_instance_id].UV + square[quad_vertex_id] * u_XY_UV_size.zw;	\n"
		"	}																						\n"
		;
}
const char* const kiwi::source::glyph_2d::fragment_shader() noexcept
{
	return
		"	#version 430 core																		\n"
		"	in vec2 UV;																				\n"
		"	uniform vec4 u_RGBA;																	\n"
		"	out vec4 color;																			\n"
		"	uniform sampler2D Tx;																	\n"
		"	void main()																				\n"
		"	{																						\n"
		"		color = u_RGBA * texture(Tx, UV);													\n"
		"	}																						\n"
		;
}

const char* const kiwi::source::glyph_3d::vertex_shader() noexcept
{
	return
		"	#version 430 core																		\n"
		"	struct XY_UV_shift_t { vec2 XY; vec2 UV; };												\n"
		"	layout (std430, binding = 0) buffer s_XY_UV_shift { XY_UV_shift_t[] u_XY_UV_shift; };	\n"
		"	uniform vec4 u_XY_UV_size;																\n"
		"	uniform mat4 u_mvp_M;																	\n"
		"	uniform mat3 u_right_up_orig;															\n"
		"	out vec2 UV;																			\n"

		"	vec2 square[4] = { vec2(0.0, 0.0), vec2(1.0, 0.0), vec2(1.0, 1.0), vec2(0.0, 1.0) };	\n"

		"	void main()																				\n"
		"	{																						\n"
		"		uint quad_instance_id = gl_VertexID >> 2;											\n"
		"		uint quad_vertex_id = gl_VertexID & uint(3);										\n"
		"		vec3 plane_coord = vec3(u_XY_UV_shift[quad_instance_id].XY							\n"
		"			+ square[quad_vertex_id] * u_XY_UV_size.xy, 1.0);								\n"

		"		gl_Position = u_mvp_M * vec4(u_right_up_orig * plane_coord, 1.0);					\n"

		"		UV = u_XY_UV_shift[quad_instance_id].UV + square[quad_vertex_id] * u_XY_UV_size.zw; \n"
		"	}																						\n"
		;
}
const char* const kiwi::source::glyph_3d::fragment_shader() noexcept
{
	return
		"	#version 430 core																		\n"
		"	in vec2 UV;																				\n"
		"	uniform vec4 u_RGBA;																	\n"
		"	uniform float u_alpha_discard;															\n"
		"	out vec4 color;																			\n"
		"	uniform sampler2D Tx;																	\n"
		"	void main()																				\n"
		"	{																						\n"
		"		color = u_RGBA * texture(Tx, UV);													\n"
		"		if (color[3] < u_alpha_discard)														\n"
		"		{																					\n"
		"			discard;																		\n"
		"		}																					\n"
		"	}																						\n"
		;
}
