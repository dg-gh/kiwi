#include "shader_sources/kiwi_sources_basic_3d.hpp"

const char* const kiwi::source::basic_3d_solid_color::vertex_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	layout (location = 0) in vec3 in_XYZ;			\n"
		"	uniform mat4 u_mvp_M;							\n"

		"	void main()										\n"
		"	{												\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);	\n"
		"	}												\n"
		;
}
const char* const kiwi::source::basic_3d_solid_color::fragment_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	out vec4 color;									\n"
		"	uniform vec4 u_RGBA;							\n"

		"	void main()										\n"
		"	{												\n"
		"		color = u_RGBA;								\n"
		"	}												\n"
		;
}

const char* const kiwi::source::basic_3d_color_gradient::vertex_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	layout (location = 0) in vec3 in_XYZ;			\n"
		"	layout (location = 1) in vec4 in_RGBA;			\n"
		"	out vec4 RGBA;									\n"
		"	uniform mat4 u_mvp_M;							\n"

		"	void main()										\n"
		"	{												\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);	\n"
		"		RGBA = in_RGBA;								\n"
		"	}												\n"
		;
}
const char* const kiwi::source::basic_3d_color_gradient::fragment_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	in vec4 RGBA;									\n"
		"	out vec4 color;									\n"

		"	void main()										\n"
		"	{												\n"
		"		color = RGBA;								\n"
		"	}												\n"
		;
}

const char* const kiwi::source::basic_3d_texture::vertex_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	layout (location = 0) in vec3 in_XYZ;			\n"
		"	layout (location = 1) in vec2 in_UV;			\n"
		"	out vec2 UV;									\n"
		"	uniform mat4 u_mvp_M;							\n"

		"	void main()										\n"
		"	{												\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);	\n"
		"		UV = in_UV;									\n"
		"	}												\n"
		;
}
const char* const kiwi::source::basic_3d_texture::fragment_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	in vec2 UV;										\n"
		"	out vec4 color;									\n"
		"	uniform sampler2D Tx;							\n"

		"	void main()										\n"
		"	{												\n"
		"		color = texture(Tx, UV);					\n"
		"	}												\n"
		;
}

const char* const kiwi::source::basic_3d_texture_alpha_test::vertex_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	layout (location = 0) in vec3 in_XYZ;			\n"
		"	layout (location = 1) in vec2 in_UV;			\n"
		"	out vec2 UV;									\n"
		"	uniform mat4 u_mvp_M;							\n"

		"	void main()										\n"
		"	{												\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);	\n"
		"		UV = in_UV;									\n"
		"	}												\n"
		;
}
const char* const kiwi::source::basic_3d_texture_alpha_test::fragment_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	in vec2 UV;										\n"
		"	out vec4 color;									\n"
		"	uniform sampler2D Tx;							\n"
		"	uniform float u_alpha_test;						\n"

		"	void main()										\n"
		"	{												\n"
		"		color = texture(Tx, UV);					\n"

		"		if (color[3] < u_alpha_test)				\n"
		"		{											\n"
		"			discard;								\n"
		"		}											\n"
		"	}												\n"
		;
}

const char* const kiwi::source::basic_3d_no_shade::vertex_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	layout (location = 0) in vec3 in_XYZ;			\n"
		"	out vec3 XYZ;									\n"
		"	uniform mat4 u_mvp_M;							\n"
		"	uniform float u_depth_offset;					\n"

		"	void main()										\n"
		"	{												\n"
		"		vec4 position = u_mvp_M * vec4(in_XYZ, 1.0);\n"
		"		position[2] += u_depth_offset;				\n"
		"		gl_Position = position;						\n"
		"	}												\n"
		;
}
const char* const kiwi::source::basic_3d_no_shade::fragment_shader() noexcept
{
	return
		"	#version 330 core								\n"
		"	void main() { }									\n"
		;
}