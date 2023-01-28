#include "shader_sources/kiwi_sources_basic_2d.hpp"

const char* const kiwi::source::basic_2d_solid_color::vertex_shader() noexcept
{
	return
		"	#version 330 core									\n"
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
const char* const kiwi::source::basic_2d_solid_color::fragment_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	out vec4 out_color;									\n"
		"	uniform vec4 u_RGBA;								\n"

		"	void main()											\n"
		"	{													\n"
		"		out_color = u_RGBA;								\n"
		"	}													\n"
		;
}

const char* const kiwi::source::basic_2d_color_gradient::vertex_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 1) in vec4 in_RGBA;				\n"
		"	out vec4 RGBA;										\n"
		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		RGBA = in_RGBA;									\n"
		"	}													\n"
		;
}
const char* const kiwi::source::basic_2d_color_gradient::fragment_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	in vec4 RGBA;										\n"
		"	out vec4 out_color;									\n"
		"	uniform vec4 u_RGBAx;								\n"
		"	uniform vec4 u_RGBAo;								\n"

		"	void main()											\n"
		"	{													\n"
		"		out_color = u_RGBAx * RGBA + u_RGBAo;			\n"
		"	}													\n"
		;
}

const char* const kiwi::source::basic_2d_texture::vertex_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 1) in vec2 in_UV;				\n"
		"	out vec2 UV;										\n"
		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		UV = in_UV;										\n"
		"	}													\n"
		;
}
const char* const kiwi::source::basic_2d_texture::fragment_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	in vec2 UV;											\n"
		"	out vec4 out_color;									\n"
		"	uniform sampler2D Tx;								\n"
		"	uniform vec4 u_RGBAx;								\n"
		"	uniform vec4 u_RGBAo;								\n"

		"	void main()											\n"
		"	{													\n"
		"		out_color = u_RGBAx * texture(Tx, UV)			\n"
		"			+ u_RGBAo;									\n"
		"	}													\n"
		;
}

const char* const kiwi::source::basic_2d_texture_alpha_test::vertex_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	layout (location = 1) in vec2 in_UV;				\n"
		"	out vec2 UV;										\n"
		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"

		"		UV = in_UV;										\n"
		"	}													\n"
		;
}
const char* const kiwi::source::basic_2d_texture_alpha_test::fragment_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	in vec2 UV;											\n"
		"	out vec4 out_color;									\n"
		"	uniform sampler2D Tx;								\n"
		"	uniform vec4 u_RGBAx;								\n"
		"	uniform vec4 u_RGBAo;								\n"
		"	uniform float u_alpha_test;							\n"

		"	void main()											\n"
		"	{													\n"
		"		out_color = u_RGBAx * texture(Tx, UV)			\n"
		"			+ u_RGBAo;									\n"

		"		if (out_color[3] < u_alpha_test)				\n"
		"		{												\n"
		"			discard;									\n"
		"		}												\n"
		"	}													\n"
		;
}

const char* const kiwi::source::basic_2d_point_dist_texture::vertex_shader() noexcept
{
	return
		"	#version 330 core												\n"
		"	layout (location = 0) in vec3 in_XY;							\n"
		"	out vec2 moved_XY;												\n"
		"	uniform mat3 u_mvp_M;											\n"
		"	uniform mat3 u_m_M;												\n"

		"	void main()														\n"
		"	{																\n"
		"		vec3 XY1 = vec3(vec2(in_XY), 1.0);							\n"
		"		vec3 in_XYh = u_mvp_M * XY1;								\n"
		"		gl_Position = vec4(in_XYh[0], in_XYh[1],					\n"
		"			in_XY[2], 1.0);											\n"
		"		moved_XY = vec2(u_m_M * XY1);								\n"
		"	}																\n"
		;
}
const char* const kiwi::source::basic_2d_point_dist_texture::fragment_shader() noexcept
{
	return
		"	#version 330 core												\n"
		"	in vec2 moved_XY;												\n"
		"	out vec4 out_color;												\n"
		"	uniform sampler1D Tx;											\n"
		"	uniform vec2 u_XY_orig;											\n"
		"	uniform vec2 u_near_far;										\n"
		"	uniform vec4 u_RGBAx;											\n"
		"	uniform vec4 u_RGBAo;											\n"

		"	void main()														\n"
		"	{																\n"
		"		float U = (length(moved_XY - u_XY_orig) - u_near_far[0])	\n"
		"			/ (u_near_far[1] - u_near_far[0]);						\n"
		"		out_color = u_RGBAx * texture(Tx, U)						\n"
		"			+ u_RGBAo;												\n"
		"	}																\n"
		;
}

const char* const kiwi::source::basic_2d_plane_dist_texture::vertex_shader() noexcept
{
	return
		"	#version 330 core												\n"
		"	layout (location = 0) in vec3 in_XY;							\n"
		"	out vec2 moved_XY;												\n"
		"	uniform mat3 u_mvp_M;											\n"
		"	uniform mat3 u_m_M;												\n"

		"	void main()														\n"
		"	{																\n"
		"		vec3 XY1 = vec3(vec2(in_XY), 1.0);							\n"
		"		vec3 in_XYh = u_mvp_M * XY1;								\n"
		"		gl_Position = vec4(in_XYh[0], in_XYh[1],					\n"
		"			in_XY[2], 1.0);											\n"
		"		moved_XY = vec2(u_m_M * XY1);								\n"
		"	}																\n"
		;
}
const char* const kiwi::source::basic_2d_plane_dist_texture::fragment_shader() noexcept
{
	return
		"	#version 330 core												\n"
		"	in vec2 moved_XY;												\n"
		"	out vec4 out_color;												\n"
		"	uniform sampler1D Tx;											\n"
		"	uniform vec2 u_XY_orig;											\n"
		"	uniform vec2 u_XY_dir;											\n"
		"	uniform vec2 u_near_far;										\n"
		"	uniform vec4 u_RGBAx;											\n"
		"	uniform vec4 u_RGBAo;											\n"

		"	void main()														\n"
		"	{																\n"
		"		float U = (dot(moved_XY - u_XY_orig,						\n"
		"			normalize(u_XY_dir)) - u_near_far[0])					\n"
		"			/ (u_near_far[1] - u_near_far[0]);						\n"
		"		out_color = u_RGBAx * texture(Tx, U)						\n"
		"			+ u_RGBAo;												\n"
		"	}																\n"
		;
}

const char* const kiwi::source::basic_2d_no_shade::vertex_shader() noexcept
{
	return
		"	#version 330 core									\n"
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
const char* const kiwi::source::basic_2d_no_shade::fragment_shader() noexcept
{
	return
		"	#version 330 core									\n"
		"	void main() { }										\n"
		;
}