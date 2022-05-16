#include "buffers/kiwi_buffer_geometric.hpp"
#include "shader_sources/kiwi_sources_basic_2d.hpp"


// 2D

kiwi::geometric_buffer_2d& kiwi::geometric_buffer_2d::collect() noexcept
{
	GLenum arr[4] = { 0, 1, 2, 3 };
	m_frame_buffer.use_with_textures(static_cast<GLenum*>(arr), 4);
	return *this;
}

kiwi::geometric_buffer_2d& kiwi::geometric_buffer_2d::draw(const GLfloat* const view_right_up_XY_ptr, GLfloat view_Z, const kiwi::lightset& lights,
	const kiwi::light_selection& selection, bool blit_depth_buffer) noexcept
{
	m_frame_buffer.exit_frame();

	kiwi::mode::disable_depth();

	m_albedo_RGB.to_binding(0);
	m_N.to_binding(1);
	m_RMEC.to_binding(2);
	m_lightmap_RGB.to_binding(3);

	lights.to_binding(0, 1, 2);
	selection.to_binding(3, 4, 5);

	m_deferred_2d_lighting.set_uniform_3x3f(m_view_left_up_XY_location, view_right_up_XY_ptr)
		.set_uniform_1f(m_view_Z_location, view_Z)
		.set_uniform_3ui(m_light_count_location, selection.number_of_lights_data())
		.set_uniform_3f(m_ambient_light_RGB_location, lights.ambient_RGB_data());

	glDrawArrays(GL_QUADS, 0, 4);

	if (blit_depth_buffer)
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_frame_buffer.get_id());
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
		glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, m_width, m_height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
	}

	return *this;
}

kiwi::geometric_buffer_2d& kiwi::geometric_buffer_2d::draw_to_current(const GLfloat* const view_right_up_XY_ptr, GLfloat view_Z, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer) noexcept
{
	kiwi::mode::disable_depth();

	m_albedo_RGB.to_binding(0);
	m_N.to_binding(1);
	m_RMEC.to_binding(2);
	m_lightmap_RGB.to_binding(3);

	lights.to_binding(0, 1, 2);
	selection.to_binding(3, 4, 5);

	m_deferred_2d_lighting.set_uniform_3x3f(m_view_left_up_XY_location, view_right_up_XY_ptr)
		.set_uniform_1f(m_view_Z_location, view_Z)
		.set_uniform_3ui(m_light_count_location, selection.number_of_lights_data())
		.set_uniform_3f(m_ambient_light_RGB_location, lights.ambient_RGB_data());

	glDrawArrays(GL_QUADS, 0, 4);

	if (blit_depth_buffer)
	{
		const kiwi::frame_buffer* ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
		GLuint draw_id;
		if (ptr != nullptr)
		{
			draw_id = ptr->get_id();
		}
		else
		{
			draw_id = 0;
		}

		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_frame_buffer.get_id());
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_id);
		glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, m_width, m_height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
	}

	return *this;
}

kiwi::geometric_buffer_2d& kiwi::geometric_buffer_2d::draw(const GLfloat* const view_right_up_XY_ptr, GLfloat view_Z, const kiwi::lightset& lights, const kiwi::light_selection& selection,
	kiwi::frame_buffer& frame_buffer, std::size_t color_attachment, bool blit_depth_buffer) noexcept
{
	frame_buffer.use_with_texture(color_attachment);

	kiwi::mode::disable_depth();

	m_albedo_RGB.to_binding(0);
	m_N.to_binding(1);
	m_RMEC.to_binding(2);
	m_lightmap_RGB.to_binding(3);

	lights.to_binding(0, 1, 2);
	selection.to_binding(3, 4, 5);

	m_deferred_2d_lighting.set_uniform_3x3f(m_view_left_up_XY_location, view_right_up_XY_ptr)
		.set_uniform_1f(m_view_Z_location, view_Z)
		.set_uniform_3ui(m_light_count_location, selection.number_of_lights_data())
		.set_uniform_3f(m_ambient_light_RGB_location, lights.ambient_RGB_data());

	glDrawArrays(GL_QUADS, 0, 4);

	if (blit_depth_buffer)
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_frame_buffer.get_id());
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
		glBlitFramebuffer(0, 0, static_cast<GLint>(m_width), static_cast<GLint>(m_height),
			0, 0, static_cast<GLint>(m_width), static_cast<GLint>(m_height),
			GL_DEPTH_BUFFER_BIT, GL_NEAREST);
	}

	return *this;
}

bool kiwi::geometric_buffer_2d::init(std::size_t width, std::size_t height) noexcept
{
	m_width = width;
	m_height = height;

	m_screen_ratio = static_cast<GLfloat>(width) / static_cast<GLfloat>(height);

	kiwi::size size_2d(width, height);

	{
		kiwi::scoped_frame frame(m_frame_buffer);

		m_depth_buffer.allocate(kiwi::render_buffer_type::f24_st8, size_2d);
		m_albedo_RGB.allocate(kiwi::texture_format::u8, size_2d, 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_N.allocate(kiwi::texture_format::f16, size_2d, 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_RMEC.allocate(kiwi::texture_format::f16, size_2d, 4, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_lightmap_RGB.allocate(kiwi::texture_format::u8, size_2d, 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);

		frame.get_frame_buffer().attach_render_buffer(&m_depth_buffer)
			.attach_texture(&m_albedo_RGB, 0)
			.attach_texture(&m_N, 1)
			.attach_texture(&m_RMEC, 2)
			.attach_texture(&m_lightmap_RGB, 3);
	}

	bool success = m_deferred_2d_lighting.new_program(
		kiwi::source::deferred_2d_lighting_pass::vertex_shader(),
		kiwi::source::deferred_2d_lighting_pass::fragment_shader()
	);

	m_view_left_up_XY_location = m_deferred_2d_lighting.new_uniform_location("u_view_right_up_XY");
	m_view_Z_location = m_deferred_2d_lighting.new_uniform_location("u_view_Z");
	m_light_count_location = m_deferred_2d_lighting.new_uniform_location("u_light_count");
	m_ambient_light_RGB_location = m_deferred_2d_lighting.new_uniform_location("u_ambient_light_RGB");
	m_scale_location = m_deferred_2d_lighting.new_uniform_location("u_scale");

	{
		if (m_screen_ratio >= static_cast<GLfloat>(1))
		{
			GLfloat arr[2] = { m_screen_ratio, static_cast<GLfloat>(1) };
			m_deferred_2d_lighting.set_uniform_2f(m_scale_location, static_cast<GLfloat*>(arr));
		}
		else
		{
			GLfloat arr[2] = { static_cast<GLfloat>(1), static_cast<GLfloat>(1) / m_screen_ratio };
			m_deferred_2d_lighting.set_uniform_2f(m_scale_location, static_cast<GLfloat*>(arr));
		}
	}

	return success;
}

kiwi::geometric_buffer_2d& kiwi::geometric_buffer_2d::set_scale(GLfloat scale) noexcept
{
	GLfloat scale_inv = static_cast<GLfloat>(1) / scale;

	if (m_screen_ratio >= static_cast<GLfloat>(1))
	{
		GLfloat arr[2] = { scale_inv * m_screen_ratio, scale_inv };
		m_deferred_2d_lighting.set_uniform_2f(m_scale_location, static_cast<GLfloat*>(arr));
	}
	else
	{
		GLfloat arr[2] = { scale_inv, scale_inv / m_screen_ratio };
		m_deferred_2d_lighting.set_uniform_2f(m_scale_location, static_cast<GLfloat*>(arr));
	}

	return *this;
}

kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_albedo_texture() noexcept
{
	return m_albedo_RGB;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_albedo_texture() const noexcept
{
	return m_albedo_RGB;
}

kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_normal_texture() noexcept
{
	return m_N;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_normal_texture() const noexcept
{
	return m_N;
}

kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_RMEC_texture() noexcept
{
	return m_RMEC;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_RMEC_texture() const noexcept
{
	return m_RMEC;
}

kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_lightmap_texture() noexcept
{
	return m_lightmap_RGB;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_2d::get_lightmap_texture() const noexcept
{
	return m_lightmap_RGB;
}

kiwi::frame_buffer& kiwi::geometric_buffer_2d::get_frame_buffer() noexcept
{
	return m_frame_buffer;
}
const kiwi::frame_buffer& kiwi::geometric_buffer_2d::get_frame_buffer() const noexcept
{
	return m_frame_buffer;
}


// 3D

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::collect() noexcept
{
	GLenum arr[5] = { 0, 1, 2, 3, 4 };
	m_frame_buffer.use_with_textures(static_cast<GLenum*>(arr), 5);
	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::draw(const GLfloat* const view_front_left_up_XYZ_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer) noexcept
{
	m_frame_buffer.exit_frame();

	kiwi::mode::disable_depth();

	m_albedo_RGB.to_binding(0);
	m_N.to_binding(1);
	m_Z.to_binding(2);
	m_RMEC.to_binding(3);
	m_lightmap_RGB.to_binding(4);

	lights.to_binding(0, 1, 2);
	selection.to_binding(3, 4, 5);

	if (m_perspective)
	{
		m_deferred_3d_lighting.set_uniform_4x4f(m_view_front_left_up_XYZ_location, view_front_left_up_XYZ_ptr)
			.set_uniform_3ui(m_light_count_location, selection.number_of_lights_data())
			.set_uniform_3f(m_ambient_light_RGB_location, lights.ambient_RGB_data());
	}
	else
	{
		m_deferred_3d_lighting_ortho.set_uniform_4x4f(m_view_front_left_up_XYZ_location_ortho, view_front_left_up_XYZ_ptr)
			.set_uniform_3ui(m_light_count_location_ortho, selection.number_of_lights_data())
			.set_uniform_3f(m_ambient_light_RGB_location_ortho, lights.ambient_RGB_data());
	}

	glDrawArrays(GL_QUADS, 0, 4);

	if (blit_depth_buffer)
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_frame_buffer.get_id());
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
		glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, m_width, m_height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
	}

	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::draw_to_current(const GLfloat* const view_front_left_up_XYZ_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer) noexcept
{
	kiwi::mode::disable_depth();

	m_albedo_RGB.to_binding(0);
	m_N.to_binding(1);
	m_Z.to_binding(2);
	m_RMEC.to_binding(3);
	m_lightmap_RGB.to_binding(4);

	lights.to_binding(0, 1, 2);
	selection.to_binding(3, 4, 5);

	if (m_perspective)
	{
		m_deferred_3d_lighting.set_uniform_4x4f(m_view_front_left_up_XYZ_location, view_front_left_up_XYZ_ptr)
			.set_uniform_3ui(m_light_count_location, selection.number_of_lights_data())
			.set_uniform_3f(m_ambient_light_RGB_location, lights.ambient_RGB_data());
	}
	else
	{
		m_deferred_3d_lighting_ortho.set_uniform_4x4f(m_view_front_left_up_XYZ_location_ortho, view_front_left_up_XYZ_ptr)
			.set_uniform_3ui(m_light_count_location_ortho, selection.number_of_lights_data())
			.set_uniform_3f(m_ambient_light_RGB_location_ortho, lights.ambient_RGB_data());
	}

	glDrawArrays(GL_QUADS, 0, 4);

	if (blit_depth_buffer)
	{
		const kiwi::frame_buffer* ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
		GLuint draw_id;
		if (ptr != nullptr)
		{
			draw_id = ptr->get_id();
		}
		else
		{
			draw_id = 0;
		}

		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_frame_buffer.get_id());
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_id);
		glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, m_width, m_height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
	}

	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::draw(const GLfloat* const view_front_left_up_XYZ_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection,
	kiwi::frame_buffer& frame_buffer, std::size_t color_attachment, bool blit_depth_buffer) noexcept
{
	frame_buffer.use_with_texture(color_attachment);

	kiwi::mode::disable_depth();

	m_albedo_RGB.to_binding(0);
	m_N.to_binding(1);
	m_Z.to_binding(2);
	m_RMEC.to_binding(3);
	m_lightmap_RGB.to_binding(4);

	lights.to_binding(0, 1, 2);
	selection.to_binding(3, 4, 5);

	if (m_perspective)
	{
		m_deferred_3d_lighting.set_uniform_4x4f(m_view_front_left_up_XYZ_location, view_front_left_up_XYZ_ptr)
			.set_uniform_3ui(m_light_count_location, selection.number_of_lights_data())
			.set_uniform_3f(m_ambient_light_RGB_location, lights.ambient_RGB_data());
	}
	else
	{
		m_deferred_3d_lighting_ortho.set_uniform_4x4f(m_view_front_left_up_XYZ_location_ortho, view_front_left_up_XYZ_ptr)
			.set_uniform_3ui(m_light_count_location_ortho, selection.number_of_lights_data())
			.set_uniform_3f(m_ambient_light_RGB_location_ortho, lights.ambient_RGB_data());
	}

	glDrawArrays(GL_QUADS, 0, 4);

	if (blit_depth_buffer)
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_frame_buffer.get_id());
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frame_buffer.get_id());
		glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, m_width, m_height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
	}

	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::set_perspective(GLfloat fov, GLfloat z_near, GLfloat z_far) noexcept
{
	GLfloat dz_inv = static_cast<GLfloat>(1) / (z_far - z_near);
	GLfloat arr[3] = { std::tan(static_cast<GLfloat>(0.5f) * fov), dz_inv * (z_far - z_near),
		dz_inv * (static_cast<GLfloat>(2) * z_far * z_near) };
	m_deferred_3d_lighting.set_uniform_3f(m_tan_half_fov_a_b_location, static_cast<GLfloat*>(arr));

	m_perspective = true;
	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::set_perspective() noexcept
{
	m_perspective = true;
	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::set_ortho(const kiwi::XY& scale, GLfloat z_near, GLfloat z_far) noexcept
{
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);
	GLfloat arr_scale[2] = { static_cast<GLfloat>(-0.5f) * scale[0], static_cast<GLfloat>(0.5f) * scale[1] };
	m_deferred_3d_lighting_ortho.set_uniform_2f(m_scale_location_ortho, static_cast<GLfloat*>(arr_scale));

	GLfloat arr_a_b[2] = { static_cast<GLfloat>(0.5f) * (z_far - z_near), static_cast<GLfloat>(0.5f) * (z_far + z_near) };
	m_deferred_3d_lighting_ortho.set_uniform_2f(m_a_b_location_ortho, static_cast<GLfloat*>(arr_a_b));

	m_perspective = false;
	return *this;
}

kiwi::geometric_buffer_3d& kiwi::geometric_buffer_3d::set_ortho() noexcept
{
	m_perspective = false;
	return *this;
}


bool kiwi::geometric_buffer_3d::init(std::size_t width, std::size_t height) noexcept
{
	bool success = true;

	m_width = width;
	m_height = height;

	kiwi::size size_2d(width, height);

	{
		kiwi::scoped_frame frame(m_frame_buffer);

		m_depth_buffer.allocate(kiwi::render_buffer_type::f24_st8, size_2d);
		m_albedo_RGB.allocate(kiwi::texture_format::u8, size_2d, 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_Z.allocate(kiwi::texture_format::f16, size_2d, 1, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_N.allocate(kiwi::texture_format::f16, size_2d, 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_RMEC.allocate(kiwi::texture_format::f16, size_2d, 4, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
		m_lightmap_RGB.allocate(kiwi::texture_format::u8, size_2d, 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);

		frame.get_frame_buffer().attach_render_buffer(&m_depth_buffer)
			.attach_texture(&m_albedo_RGB, 0)
			.attach_texture(&m_N, 1)
			.attach_texture(&m_Z, 2)
			.attach_texture(&m_RMEC, 3)
			.attach_texture(&m_lightmap_RGB, 4);
	}

	success &= m_deferred_3d_lighting.new_program(
		kiwi::source::deferred_3d_lighting_pass::vertex_shader(),
		kiwi::source::deferred_3d_lighting_pass::fragment_shader()
	);

	m_view_front_left_up_XYZ_location = m_deferred_3d_lighting.new_uniform_location("u_view_front_left_up_XYZ");
	m_light_count_location = m_deferred_3d_lighting.new_uniform_location("u_light_count");
	m_ambient_light_RGB_location = m_deferred_3d_lighting.new_uniform_location("u_ambient_light_RGB");
	m_scale_location = m_deferred_3d_lighting.new_uniform_location("u_scale");
	m_tan_half_fov_a_b_location = m_deferred_3d_lighting.new_uniform_location("u_tan_half_fov_a_b");

	{
		GLfloat screen_width_f = static_cast<GLfloat>(width);
		GLfloat screen_height_f = static_cast<GLfloat>(height);

		if (screen_width_f >= screen_height_f)
		{
			GLfloat arr[2] = { -screen_width_f / screen_height_f, static_cast<GLfloat>(1) };
			m_deferred_3d_lighting.set_uniform_2f(m_scale_location, static_cast<GLfloat*>(arr));
		}
		else
		{
			GLfloat arr[2] = { static_cast<GLfloat>(-1), screen_height_f / screen_width_f };
			m_deferred_3d_lighting.set_uniform_2f(m_scale_location, static_cast<GLfloat*>(arr));
		}
	}


	success &= m_deferred_3d_lighting_ortho.new_program(
		kiwi::source::deferred_3d_lighting_pass_ortho::vertex_shader(),
		kiwi::source::deferred_3d_lighting_pass_ortho::fragment_shader());

	m_view_front_left_up_XYZ_location_ortho = m_deferred_3d_lighting_ortho.new_uniform_location("u_view_front_left_up_XYZ");
	m_light_count_location_ortho = m_deferred_3d_lighting_ortho.new_uniform_location("u_light_count");
	m_ambient_light_RGB_location_ortho = m_deferred_3d_lighting_ortho.new_uniform_location("u_ambient_light_RGB");
	m_scale_location_ortho = m_deferred_3d_lighting_ortho.new_uniform_location("u_scale");
	m_a_b_location_ortho = m_deferred_3d_lighting_ortho.new_uniform_location("u_a_b");

	return success;
}

kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_albedo_texture() noexcept
{
	return m_albedo_RGB;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_albedo_texture() const noexcept
{
	return m_albedo_RGB;
}

kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_depth_texture() noexcept
{
	return m_Z;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_depth_texture() const noexcept
{
	return m_Z;
}

kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_normal_texture() noexcept
{
	return m_N;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_normal_texture() const noexcept
{
	return m_N;
}

kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_RMEC_texture() noexcept
{
	return m_RMEC;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_RMEC_texture() const noexcept
{
	return m_RMEC;
}

kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_lightmap_texture() noexcept
{
	return m_lightmap_RGB;
}
const kiwi::texture_buffer& kiwi::geometric_buffer_3d::get_lightmap_texture() const noexcept
{
	return m_lightmap_RGB;
}

kiwi::frame_buffer& kiwi::geometric_buffer_3d::get_frame_buffer() noexcept
{
	return m_frame_buffer;
}
const kiwi::frame_buffer& kiwi::geometric_buffer_3d::get_frame_buffer() const noexcept
{
	return m_frame_buffer;
}