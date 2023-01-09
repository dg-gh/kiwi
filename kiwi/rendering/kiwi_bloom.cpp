#include "rendering/kiwi_bloom.hpp"
#include "shader_sources/kiwi_sources_bloom.hpp"


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

bool kiwi::bloom::init(std::size_t screen_width, std::size_t screen_height, bool extended, kiwi::texture_sampling sampling) noexcept
{
	m_extended = extended;
	m_sampling = sampling;

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

		switch (m_sampling)
		{

		case kiwi::texture_sampling::unique:
			m_multisampled_render_buffer.set_sampling(kiwi::render_buffer_sampling::unique).allocate(kiwi::render_buffer_type::f24_st8,
				kiwi::size(screen_width, screen_height));
			break;

		case kiwi::texture_sampling::multiple:
			m_multisampled_render_buffer.set_sampling(kiwi::render_buffer_sampling::multiple).allocate(kiwi::render_buffer_type::f24_st8,
				kiwi::size(screen_width, screen_height));
			break;
		}

		m_multisampled_texture.set_sampling(m_sampling).allocate(kiwi::pixel_format::f16,
			kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		frame.get_frame_buffer().attach_render_buffer(&m_multisampled_render_buffer)
			.attach_texture(&m_multisampled_texture, 0);
	}

	{
		kiwi::scoped_frame frame(m_frame_buffer);

		m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(screen_width, screen_height));

		m_textures[0].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
		m_textures[1].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
		m_textures[2].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[3].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
		m_textures[4].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[5].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
		m_textures[6].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[7].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		frame.get_frame_buffer().attach_render_buffer(&m_render_buffer);

		for (std::size_t n = 0; n < 8; n++)
		{
			frame.get_frame_buffer().attach_texture(static_cast<kiwi::texture_buffer*>(m_textures) + n, n);
		}
	}

	if (m_extended)
	{
		kiwi::scoped_frame frame(m_frame_buffer_extended);

		m_textures[8].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[9].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
		m_textures[10].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[11].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);
		m_textures[12].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[13].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);
		m_textures[14].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[15].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);

		for (std::size_t n = 0; n < 8; n++)
		{
			frame.get_frame_buffer().attach_texture(static_cast<kiwi::texture_buffer*>(m_textures) + n + 8, n);
		}
	}

	bool success = true;

	success &= m_threshold_program.new_program(
		kiwi::source::bloom_threshold::vertex_shader(),
		kiwi::source::bloom_threshold::fragment_shader()
	);

	success &= m_gaussian_filter_program.new_program(
		kiwi::source::bloom_gaussian_filter::vertex_shader(),
		kiwi::source::bloom_gaussian_filter::fragment_shader()
	);

	if (m_extended)
	{
		success &= m_blend_program.new_program(
			kiwi::source::bloom_blend_8_layers::vertex_shader(),
			kiwi::source::bloom_blend_8_layers::fragment_shader()
		);
	}
	else
	{
		success &= m_blend_program.new_program(
			kiwi::source::bloom_blend_4_layers::vertex_shader(),
			kiwi::source::bloom_blend_4_layers::fragment_shader()
		);
	}

	if (success)
	{
		m_threshold_location = m_threshold_program.new_uniform_location("u_threshold");
		m_distance_location = m_gaussian_filter_program.new_uniform_location("u_distance");
		m_horizontal_location = m_gaussian_filter_program.new_uniform_location("u_horizontal");
		m_blur_scale_location = m_gaussian_filter_program.new_uniform_location("u_scale");
		m_blend_location = m_blend_program.new_uniform_location("u_blend");
		if (m_extended)
		{
			m_blend_extended_location = m_blend_program.new_uniform_location("u_blend_extended");
		}
	}

	return success;
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

	switch (m_sampling)
	{

	case kiwi::texture_sampling::unique:
		m_multisampled_render_buffer.set_sampling(kiwi::render_buffer_sampling::unique).allocate(kiwi::render_buffer_type::f24_st8,
			kiwi::size(screen_width, screen_height));
		break;

	case kiwi::texture_sampling::multiple:
		m_multisampled_render_buffer.set_sampling(kiwi::render_buffer_sampling::multiple).allocate(kiwi::render_buffer_type::f24_st8,
			kiwi::size(screen_width, screen_height));
		break;
	}
	
	m_multisampled_texture.set_sampling(m_sampling).allocate(kiwi::pixel_format::f16,
		kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);


	m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(screen_width, screen_height));

	m_textures[0].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
	m_textures[1].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
	m_textures[2].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

	screen_width /= 2; screen_height /= 2;

	m_textures[3].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
	m_textures[4].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

	screen_width /= 2; screen_height /= 2;

	m_textures[5].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
	m_textures[6].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

	screen_width /= 2; screen_height /= 2;

	m_textures[7].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

	if (m_extended)
	{
		m_textures[8].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[9].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);
		m_textures[10].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::pad);

		screen_width /= 2; screen_height /= 2;

		m_textures[11].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);
		m_textures[12].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[13].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);
		m_textures[14].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);

		screen_width /= 2; screen_height /= 2;

		m_textures[15].allocate(kiwi::pixel_format::f16, kiwi::size(screen_width, screen_height), 4, kiwi::pixel_mapping::linear, kiwi::pixel_wrapping::clamp);
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


	m_frame_buffer.use_with_texture(2);
	m_gaussian_filter_program.set_uniform_1f(m_distance_location, m_pixel_size)
		.set_uniform_1i(m_horizontal_location, 0)
		.set_uniform_2f(m_blur_scale_location, static_cast<GLfloat*>(m_UV_scale_final));
	m_textures[1].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	m_frame_buffer.use_with_texture(3);
	m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
	m_textures[2].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);


	m_frame_buffer.use_with_texture(4);
	m_gaussian_filter_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(2) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
	m_textures[3].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	m_frame_buffer.use_with_texture(5);
	m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
	m_textures[4].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);


	m_frame_buffer.use_with_texture(6);
	m_gaussian_filter_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(4) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
	m_textures[5].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	m_frame_buffer.use_with_texture(7);
	m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
	m_textures[6].to_binding(0);
	glDrawArrays(GL_QUADS, 0, 4);

	if (m_extended)
	{
		m_frame_buffer_extended.use_with_texture(0);
		kiwi::clear_frame_buffer();
		kiwi::mode::disable_depth();
		m_gaussian_filter_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(8) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[7].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(1);
		m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[8].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(2);
		m_gaussian_filter_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(16) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[9].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(3);
		m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[10].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);


		m_frame_buffer_extended.use_with_texture(4);
		m_gaussian_filter_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(32) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[11].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(5);
		m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[12].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);


		m_frame_buffer_extended.use_with_texture(6);
		m_gaussian_filter_program.set_uniform_1f(m_distance_location, static_cast<GLfloat>(64) * m_pixel_size).set_uniform_1i(m_horizontal_location, 0);
		m_textures[13].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);

		m_frame_buffer_extended.use_with_texture(7);
		m_gaussian_filter_program.set_uniform_1i(m_horizontal_location, 1);
		m_textures[14].to_binding(0);
		glDrawArrays(GL_QUADS, 0, 4);
	}

	return *this;
}

kiwi::bloom& kiwi::bloom::recollect_ground_layer() noexcept
{
	m_multisampled_frame_buffer.use_with_texture(0);
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