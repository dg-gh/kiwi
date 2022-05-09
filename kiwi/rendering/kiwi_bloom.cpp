#include "rendering/kiwi_bloom.hpp"


kiwi::bloom& kiwi::bloom::set_scale(GLfloat scale) noexcept
{
	m_scale = scale;
	m_UV_scale_final[0] = m_scale * m_UV_scale[0];
	m_UV_scale_final[1] = m_scale * m_UV_scale[1];
	return *this;
}

kiwi::bloom& kiwi::bloom::set_threshold(GLfloat threshold) noexcept
{
	m_threshold = threshold;
	return *this;
}

kiwi::bloom& kiwi::bloom::set_layer_coefficients(GLfloat layer_1_coeff, GLfloat layer_2_coeff, GLfloat layer_3_coeff,
	GLfloat layer_4_coeff, GLfloat layer_5_coeff, GLfloat layer_6_coeff, GLfloat layer_7_coeff) noexcept
{
	{
		GLfloat blend[3] = { layer_1_coeff, layer_2_coeff, layer_3_coeff };
		m_blend_program.set_uniform_3f(m_blend_location, static_cast<GLfloat*>(blend));
	}

	if (m_extended)
	{
		GLfloat blend_extended[4] = { layer_4_coeff, layer_5_coeff, layer_6_coeff, layer_7_coeff };
		m_blend_program.set_uniform_4f(m_blend_extended_location, static_cast<GLfloat*>(blend_extended));
	}

	return *this;
}

kiwi::bloom& kiwi::bloom::init(std::size_t screen_width, std::size_t screen_height, bool extended) noexcept
{
	m_extended = extended;

	{
		GLfloat screen_width_f = static_cast<GLfloat>(screen_width);
		GLfloat screen_height_f = static_cast<GLfloat>(screen_height);

		if (screen_width_f >= screen_height_f)
		{
			m_UV_scale[0] = screen_height_f / screen_width_f;
			m_UV_scale[1] = GL1;
			m_UV_scale_final[0] = m_scale * m_UV_scale[0];
			m_UV_scale_final[1] = m_scale * m_UV_scale[1];
			m_quad_scale[0] = screen_width_f / screen_height_f;
			m_quad_scale[1] = GL1;
			m_pixel_size = static_cast<GLfloat>(2) / screen_height_f;
		}
		else
		{
			m_UV_scale[0] = GL1;
			m_UV_scale[1] = screen_width_f / screen_height_f;
			m_UV_scale_final[0] = m_scale * m_UV_scale[0];
			m_UV_scale_final[1] = m_scale * m_UV_scale[1];
			m_quad_scale[0] = GL1;
			m_quad_scale[1] = screen_height_f / screen_width_f;
			m_pixel_size = static_cast<GLfloat>(2) / screen_width_f;
		}
	}

	{
		kiwi::scoped_frame frame(m_multisampled_frame_buffer);

		m_multisampled_render_buffer.set_sampling(kiwi::render_buffer_sampling::multiple).allocate(kiwi::render_buffer_type::f24_st8,
			kiwi::size(screen_width, screen_height));

		m_multisampled_texture.set_sampling(kiwi::texture_sampling::multiple).allocate(kiwi::texture_format::f16,
			kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		frame.get_frame_buffer().attach_render_buffer(&m_multisampled_render_buffer)
			.attach_texture(&m_multisampled_texture, 0);
	}

	{
		kiwi::scoped_frame frame(m_frame_buffer);

		m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(screen_width, screen_height));

		m_textures[0].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
		m_textures[1].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
		m_textures[2].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[3].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
		m_textures[4].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[5].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
		m_textures[6].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[7].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		frame.get_frame_buffer().attach_render_buffer(&m_render_buffer);

		for (std::size_t n = 0; n < 8; n++)
		{
			frame.get_frame_buffer().attach_texture(static_cast<kiwi::texture_buffer*>(m_textures) + n, n);
		}
	}

	if (m_extended)
	{
		kiwi::scoped_frame frame(m_frame_buffer_extended);

		m_textures[8].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[9].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
		m_textures[10].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[11].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
		m_textures[12].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[13].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
		m_textures[14].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[15].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);

		for (std::size_t n = 0; n < 8; n++)
		{
			frame.get_frame_buffer().attach_texture(static_cast<kiwi::texture_buffer*>(m_textures) + n + 8, n);
		}
	}

	m_threshold_program.new_program(

		"	#version 420 core																	\n"
		"	out vec2 UV;																		\n"

		"	float in_XY[8] = { -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0 };					\n"
		"	float in_UV[8] = { 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0 };						\n"

		"	void main()																			\n"
		"	{																					\n"
		"		gl_Position[0] = in_XY[2 * gl_VertexID];										\n"
		"		gl_Position[1] = in_XY[2 * gl_VertexID + 1];									\n"
		"		gl_Position[2] = 0.0;															\n"
		"		gl_Position[3] = 1.0;															\n"
		"		UV[0] = in_UV[2 * gl_VertexID];													\n"
		"		UV[1] = in_UV[2 * gl_VertexID + 1];												\n"
		"	}																					\n"
		,

		"	#version 330 core																	\n"
		"	in vec2 UV;																			\n"
		"	out vec4 color;																		\n"
		"	uniform sampler2D Tx;																\n"
		"	uniform float u_threshold;															\n"

		"	void main()																			\n"
		"	{																					\n"
		"		color = texture(Tx, UV);														\n"

		"		float pass_factor1 = 0.5 * (max(max(color[0], color[1]), color[2])				\n"
		"			- u_threshold);																\n"

		"		float pass_factor2 = 0.5 * (color[0] + color[1] + color[2]						\n"
		"			- min(min(color[0], color[1]), color[2]))									\n"
		"			- u_threshold;																\n"

		"		float pass_factor = max(pass_factor1, pass_factor2);							\n"

		"		if (pass_factor < 0.0)															\n"
		"		{																				\n"
		"			color = vec4(0.0, 0.0, 0.0, 0.0);											\n"
		"		}																				\n"
		"		else																			\n"
		"		{																				\n"
		"			color = vec4(pass_factor * vec3(color), color[3]);							\n"
		"		}																				\n"
		"	}																					\n"

	);

	m_blur_program.new_program(

		"	#version 420 core																	\n"
		"	out vec2 UV;																		\n"

		"	float in_XY[8] = { -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0 };					\n"
		"	float in_UV[8] = { 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0 };						\n"

		"	void main()																			\n"
		"	{																					\n"
		"		gl_Position[0] = in_XY[2 * gl_VertexID];										\n"
		"		gl_Position[1] = in_XY[2 * gl_VertexID + 1];									\n"
		"		gl_Position[2] = 0.0;															\n"
		"		gl_Position[3] = 1.0;															\n"
		"		UV[0] = in_UV[2 * gl_VertexID];													\n"
		"		UV[1] = in_UV[2 * gl_VertexID + 1];												\n"
		"	}																					\n"
		,

		"	#version 420 core																	\n"
		"	in vec2 UV;																			\n"
		"	layout (location = 0) out vec4 RGBA;												\n"
		"	uniform sampler2D Tx;																\n"
		"	uniform float u_distance;															\n"
		"	uniform int u_horizontal;															\n"
		"	uniform vec2 u_scale;																\n"

		"	float weight[5] = { 0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216 };			\n"

		"	void main()																			\n"
		"	{																					\n"
		"		vec3 RGB = weight[0] * vec3(texture(Tx, UV)); 									\n"

		"		if (u_horizontal == 1)															\n"
		"		{																				\n"
		"			float d = u_scale[0] * u_distance;											\n"
		"			for (uint n = 1; n < 5; n++)												\n"
		"			{																			\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV - vec2(n * d, 0.0)));			\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV + vec2(n * d, 0.0)));			\n"
		"			}																			\n"
		"		}																				\n"
		"		else																			\n"
		"		{																				\n"
		"			float d = u_scale[1] * u_distance;											\n"
		"			for (uint n = 1; n < 5; n++)												\n"
		"			{																			\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV - vec2(0.0, n * d)));			\n"
		"				RGB += weight[n] * vec3(texture(Tx, UV + vec2(0.0, n * d)));			\n"
		"			}																			\n"
		"		}																				\n"
		"		RGBA = vec4(RGB, 1.0);															\n"

		"	}																					\n"
	);

	if (m_extended)
	{
		m_blend_program.new_program(

			"	#version 420 core																	\n"
			"	out vec2 UV;																		\n"

			"	float in_XY[8] = { -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0 };					\n"
			"	float in_UV[8] = { 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0 };						\n"

			"	void main()																			\n"
			"	{																					\n"
			"		gl_Position[0] = in_XY[2 * gl_VertexID];										\n"
			"		gl_Position[1] = in_XY[2 * gl_VertexID + 1];									\n"
			"		gl_Position[2] = 0.0;															\n"
			"		gl_Position[3] = 1.0;															\n"
			"		UV[0] = in_UV[2 * gl_VertexID];													\n"
			"		UV[1] = in_UV[2 * gl_VertexID + 1];												\n"
			"	}																					\n"
			,

			"	#version 420 core																	\n"
			"	in vec2 UV;																			\n"
			"	out vec4 color;																		\n"
			"	layout (binding = 7) uniform sampler2D Tx0;											\n"
			"	layout (binding = 6) uniform sampler2D Tx1;											\n"
			"	layout (binding = 5) uniform sampler2D Tx2;											\n"
			"	layout (binding = 4) uniform sampler2D Tx3;											\n"
			"	layout (binding = 3) uniform sampler2D Tx4;											\n"
			"	layout (binding = 2) uniform sampler2D Tx5;											\n"
			"	layout (binding = 1) uniform sampler2D Tx6;											\n"
			"	layout (binding = 0) uniform sampler2D Tx7;											\n"
			"	uniform vec3 u_blend;																\n"
			"	uniform vec4 u_blend_extended;														\n"

			"	void main()																			\n"
			"	{																					\n"
			"		color = vec4(vec3(texture(Tx0, UV))												\n"
			"			+ u_blend[0] * vec3(texture(Tx1, UV))										\n"
			"			+ u_blend[1] * vec3(texture(Tx2, UV))										\n"
			"			+ u_blend[2] * vec3(texture(Tx3, UV))										\n"
			"			+ u_blend_extended[0] * vec3(texture(Tx4, UV))								\n"
			"			+ u_blend_extended[1] * vec3(texture(Tx5, UV))								\n"
			"			+ u_blend_extended[2] * vec3(texture(Tx6, UV))								\n"
			"			+ u_blend_extended[3] * vec3(texture(Tx7, UV)),								\n"
			"			1.0);																		\n"
			"	}																					\n"
		);
	}
	else
	{
		m_blend_program.new_program(

			"	#version 420 core																	\n"
			"	out vec2 UV;																		\n"

			"	float in_XY[8] = { -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0 };					\n"
			"	float in_UV[8] = { 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0 };						\n"

			"	void main()																			\n"
			"	{																					\n"
			"		gl_Position[0] = in_XY[2 * gl_VertexID];										\n"
			"		gl_Position[1] = in_XY[2 * gl_VertexID + 1];									\n"
			"		gl_Position[2] = 0.0;															\n"
			"		gl_Position[3] = 1.0;															\n"
			"		UV[0] = in_UV[2 * gl_VertexID];													\n"
			"		UV[1] = in_UV[2 * gl_VertexID + 1];												\n"
			"	}																					\n"
			,

			"	#version 420 core																	\n"
			"	in vec2 UV;																			\n"
			"	out vec4 color;																		\n"
			"	layout (binding = 3) uniform sampler2D Tx0;											\n"
			"	layout (binding = 2) uniform sampler2D Tx1;											\n"
			"	layout (binding = 1) uniform sampler2D Tx2;											\n"
			"	layout (binding = 0) uniform sampler2D Tx3;											\n"
			"	uniform vec3 u_blend;																\n"

			"	void main()																			\n"
			"	{																					\n"
			"		color = vec4(vec3(texture(Tx0, UV))												\n"
			"			+ u_blend[0] * vec3(texture(Tx1, UV))										\n"
			"			+ u_blend[1] * vec3(texture(Tx2, UV))										\n"
			"			+ u_blend[2] * vec3(texture(Tx3, UV)),										\n"
			"			1.0);																		\n"
			"	}																					\n"
		);
	}

	m_threshold_location = m_threshold_program.new_uniform_location("u_threshold");
	m_distance_location = m_blur_program.new_uniform_location("u_distance");
	m_horizontal_location = m_blur_program.new_uniform_location("u_horizontal");
	m_blur_scale_location = m_blur_program.new_uniform_location("u_scale");
	m_blend_location = m_blend_program.new_uniform_location("u_blend");
	if (m_extended) { m_blend_extended_location = m_blend_program.new_uniform_location("u_blend_extended"); }

	return *this;
}

kiwi::bloom& kiwi::bloom::resize(std::size_t screen_width, std::size_t screen_height) noexcept
{
	{
		GLfloat screen_width_f = static_cast<GLfloat>(screen_width);
		GLfloat screen_height_f = static_cast<GLfloat>(screen_height);

		if (screen_width_f >= screen_height_f)
		{
			m_UV_scale[0] = screen_height_f / screen_width_f;
			m_UV_scale[1] = GL1;
			m_UV_scale_final[0] = m_scale * m_UV_scale[0];
			m_UV_scale_final[1] = m_scale * m_UV_scale[1];
			m_quad_scale[0] = screen_width_f / screen_height_f;
			m_quad_scale[1] = GL1;
			m_pixel_size = static_cast<GLfloat>(2) / screen_height_f;
		}
		else
		{
			m_UV_scale[0] = GL1;
			m_UV_scale[1] = screen_width_f / screen_height_f;
			m_UV_scale_final[0] = m_scale * m_UV_scale[0];
			m_UV_scale_final[1] = m_scale * m_UV_scale[1];
			m_quad_scale[0] = GL1;
			m_quad_scale[1] = screen_height_f / screen_width_f;
			m_pixel_size = static_cast<GLfloat>(2) / screen_width_f;
		}
	}

	m_multisampled_render_buffer.set_sampling(kiwi::render_buffer_sampling::multiple).allocate(kiwi::render_buffer_type::f24_st8,
		kiwi::size(screen_width, screen_height));

	m_multisampled_texture.set_sampling(kiwi::texture_sampling::multiple).allocate(kiwi::texture_format::f16,
		kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);


	m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(screen_width, screen_height));

	m_textures[0].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
	m_textures[1].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
	m_textures[2].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

	screen_width /= 2; screen_height /= 2;

	m_textures[3].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
	m_textures[4].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

	screen_width /= 2; screen_height /= 2;

	m_textures[5].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
	m_textures[6].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

	screen_width /= 2; screen_height /= 2;

	m_textures[7].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

	if (m_extended)
	{
		m_textures[8].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[9].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);
		m_textures[10].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[11].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
		m_textures[12].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[13].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
		m_textures[14].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[15].allocate(kiwi::texture_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
	}

	return *this;
}

kiwi::bloom& kiwi::bloom::collect() noexcept
{
	m_frame_buffer.use_with_texture(0);
	return *this;
}

kiwi::bloom& kiwi::bloom::process() noexcept
{
	m_frame_buffer.use_with_texture(1);
	kiwi::clear_frame_buffer();
	kiwi::mode::disable_depth();
	m_textures[0].to_binding(0);
	m_threshold_program.set_uniform_1f(m_threshold_location, m_threshold);
	glDrawArrays(GL_QUADS, 0, 4);

	constexpr GLfloat GL2 = static_cast<GLfloat>(2);

	m_frame_buffer.use_with_texture(2);
	m_blur_program.set_uniform_1f(m_distance_location, m_pixel_size)
		.set_uniform_1i(m_horizontal_location, 0)
		.set_uniform_2f(m_blur_scale_location, static_cast<GLfloat*>(m_UV_scale_final));
	m_textures[1].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	m_frame_buffer.use_with_texture(3);
	m_blur_program.set_uniform_1i(m_horizontal_location, 1);
	m_textures[2].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);


	m_frame_buffer.use_with_texture(4);
	m_blur_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(2) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
	m_textures[3].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	m_frame_buffer.use_with_texture(5);
	m_blur_program.set_uniform_1i(m_horizontal_location, 1);
	m_textures[4].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);


	m_frame_buffer.use_with_texture(6);
	m_blur_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(4) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
	m_textures[5].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	m_frame_buffer.use_with_texture(7);
	m_blur_program.set_uniform_1i(m_horizontal_location, 1);
	m_textures[6].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	if (m_extended)
	{
		m_frame_buffer_extended.use_with_texture(0);
		kiwi::clear_frame_buffer();
		kiwi::mode::disable_depth();
		m_blur_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(8) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[7].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(1);
		m_blur_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[8].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(2);
		m_blur_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(16) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[9].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(3);
		m_blur_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[10].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);


		m_frame_buffer_extended.use_with_texture(4);
		m_blur_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(32) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[11].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(5);
		m_blur_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[12].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);


		m_frame_buffer_extended.use_with_texture(6);
		m_blur_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(64) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[13].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(7);
		m_blur_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[14].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);
	}

	return *this;
}

kiwi::bloom& kiwi::bloom::recollect_ground_layer() noexcept
{
	m_multisampled_frame_buffer.use_with_texture(0);
	kiwi::clear_frame_buffer();
	kiwi::clear_depth_buffer();
	m_redraw = true;
	return *this;
}

kiwi::bloom& kiwi::bloom::draw() noexcept
{
	if (m_redraw)
	{
		kiwi::scoped_blit bl(m_frame_buffer, m_multisampled_frame_buffer);
		bl.blit(0, 0);
		m_redraw = false;
	}

	m_frame_buffer.exit_frame();

	kiwi::mode::disable_depth();

	if (m_extended)
	{
		m_textures[0].to_binding(7);
		m_textures[3].to_binding(6);
		m_textures[5].to_binding(5);
		m_textures[7].to_binding(4);
	}

	m_textures[9].to_binding(3);
	m_textures[11].to_binding(2);
	m_textures[13].to_binding(1);
	m_textures[15].to_binding(0);

	m_blend_program.use();
	glDrawArrays(GL_QUADS, 0, 4);

	return *this;
}

kiwi::bloom& kiwi::bloom::draw_to_current() noexcept
{
	if (m_redraw)
	{
		kiwi::scoped_blit bl(m_frame_buffer, m_multisampled_frame_buffer);
		bl.blit(0, 0);
		m_redraw = false;
	}

	kiwi::mode::disable_depth();

	if (m_extended)
	{
		m_textures[0].to_binding(7);
		m_textures[3].to_binding(6);
		m_textures[5].to_binding(5);
		m_textures[7].to_binding(4);
	}

	m_textures[9].to_binding(3);
	m_textures[11].to_binding(2);
	m_textures[13].to_binding(1);
	m_textures[15].to_binding(0);

	m_blend_program.use();
	glDrawArrays(GL_QUADS, 0, 4);

	return *this;
}

kiwi::bloom& kiwi::bloom::draw(kiwi::frame_buffer& target, std::size_t color_attachment) noexcept
{
	if (m_redraw)
	{
		kiwi::scoped_blit bl(m_frame_buffer, m_multisampled_frame_buffer);
		bl.blit(0, 0);
		m_redraw = false;
	}

	target.use_with_texture(color_attachment);

	kiwi::mode::disable_depth();

	if (m_extended)
	{
		m_textures[0].to_binding(7);
		m_textures[3].to_binding(6);
		m_textures[5].to_binding(5);
		m_textures[7].to_binding(4);
		m_textures[9].to_binding(3);
		m_textures[11].to_binding(2);
		m_textures[13].to_binding(1);
		m_textures[15].to_binding(0);
	}
	else
	{
		m_textures[0].to_binding(3);
		m_textures[3].to_binding(2);
		m_textures[5].to_binding(1);
		m_textures[7].to_binding(0);
	}

	m_blend_program.use();
	glDrawArrays(GL_QUADS, 0, 4);

	return *this;
}