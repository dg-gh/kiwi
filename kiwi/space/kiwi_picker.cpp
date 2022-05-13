#include "space/kiwi_picker.hpp"
#include "shader_sources/kiwi_sources_picker.hpp"


kiwi::picker& kiwi::picker::init(std::size_t width, std::size_t height)
{
	m_texture_buffer.allocate(kiwi::texture_format::i16u, kiwi::size(width, height), 1, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
	m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(width, height));

	{
		kiwi::scoped_frame frame(m_frame_buffer);

		frame.get_frame_buffer()
			.attach_texture(&m_texture_buffer, 0)
			.attach_render_buffer(&m_render_buffer);
	}

	{
		m_program_picker_2d.new_program(
			kiwi::source::picker_2d::vertex_shader(),
			kiwi::source::picker_2d::fragment_shader()
		);

		m_uniform_mvp_matrix_2d = m_program_picker_2d.new_uniform_location("u_mvp_M");
		m_uniform_id_2d = m_program_picker_2d.new_uniform_location("u_entity_id");
	}

	{
		m_program_picker_3d.new_program(
			kiwi::source::picker_3d::vertex_shader(),
			kiwi::source::picker_3d::fragment_shader()
		);

		m_uniform_mvp_matrix_3d = m_program_picker_3d.new_uniform_location("u_mvp_M");
		m_uniform_id_3d = m_program_picker_3d.new_uniform_location("u_entity_id");
	}

	{
		m_program_instanced_XY_id_2d.new_program(
			kiwi::source::picker_XY_id_2d::vertex_shader(),
			kiwi::source::picker_XY_id_2d::fragment_shader()
		);

		m_uniform_mvp_matrix_instanced_2d = m_program_picker_2d.new_uniform_location("u_mvp_M");
	}

	{
		m_program_instanced_XY_id_2d.new_program(
			kiwi::source::picker_XYZ_id_3d::vertex_shader(),
			kiwi::source::picker_XYZ_id_3d::fragment_shader()
		);

		m_uniform_mvp_matrix_instanced_3d = m_program_picker_2d.new_uniform_location("u_mvp_M");
	}

	return *this;
}

kiwi::picker& kiwi::picker::resize(std::size_t width, std::size_t height)
{
	m_texture_buffer.allocate(kiwi::texture_format::i16u, kiwi::size(width, height), 1, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
	m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(width, height));

	return *this;
}


kiwi::scoped_picker::scoped_picker(kiwi::picker& rhs)
{
	rhs.m_frame_buffer.use_with_texture(0);
	m_picker_ptr = &rhs;
	m_clear_on_exit = true;
}

kiwi::scoped_picker::~scoped_picker()
{
	if (m_clear_on_exit)
	{
		kiwi::clear_frame_buffer();
	}
	m_picker_ptr->m_frame_buffer.exit_frame();
}

kiwi::_picker_2d_proxy kiwi::scoped_picker::assign_id_2d_with()
{
	kiwi::_picker_2d_proxy proxy;
	proxy.m_picker_ptr = m_picker_ptr;
	proxy.m_transformation_matrix_ptr = nullptr;
	return proxy;
}

kiwi::_picker_2d_proxy kiwi::scoped_picker::assign_id_2d_with(const GLfloat* const mvp_matrix_ptr)
{
	kiwi::_picker_2d_proxy proxy;
	proxy.m_picker_ptr = m_picker_ptr;
	proxy.m_transformation_matrix_ptr = mvp_matrix_ptr;
	return proxy;
}

kiwi::_picker_3d_proxy kiwi::scoped_picker::assign_id_3d_with(const GLfloat* const mvp_matrix_ptr)
{
	kiwi::_picker_3d_proxy proxy;
	proxy.m_picker_ptr = m_picker_ptr;
	proxy.m_transformation_matrix_ptr = mvp_matrix_ptr;
	return proxy;
}

kiwi::scoped_picker& kiwi::scoped_picker::clear_on_exit() noexcept
{
	m_clear_on_exit = true;
}

kiwi::scoped_picker& kiwi::scoped_picker::save_on_exit() noexcept
{
	m_clear_on_exit = false;
}

GLushort kiwi::scoped_picker::pick_id(std::size_t pixel_X, std::size_t pixel_Y) const
{
	GLushort entity_id;
	glReadPixels(static_cast<GLint>(pixel_X), static_cast<GLint>(pixel_Y), 1, 1, GL_RED_INTEGER, GL_UNSIGNED_SHORT, &entity_id);
	return entity_id;
}


kiwi::_draw_basic_proxy kiwi::_picker_2d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept
{
	vertex_buffer.to_location(0);

	if (m_transformation_matrix_ptr == nullptr)
	{
		m_picker_ptr->m_program_picker_2d.set_uniform_3x3f(m_picker_ptr->m_uniform_mvp_matrix_2d, kiwi::window_matrix_data());
	}
	else
	{
		m_picker_ptr->m_program_picker_2d.set_uniform_3x3f(m_picker_ptr->m_uniform_mvp_matrix_2d, m_transformation_matrix_ptr);
	}
	m_picker_ptr->m_program_picker_2d.set_uniform_1ui(m_picker_ptr->m_uniform_id_2d, static_cast<GLuint>(entity_id));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_instanced_basic_proxy kiwi::_picker_2d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XY_id_set& XY_id_set,
	const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	vertex_buffer.to_location(0);
	XY_id_set.to_binding(0);

	if (m_transformation_matrix_ptr == nullptr)
	{
		m_picker_ptr->m_program_instanced_XY_id_2d.set_uniform_3x3f(m_picker_ptr->m_uniform_mvp_matrix_instanced_2d, kiwi::window_matrix_data());
	}
	else
	{
		m_picker_ptr->m_program_instanced_XY_id_2d.set_uniform_3x3f(m_picker_ptr->m_uniform_mvp_matrix_instanced_2d, m_transformation_matrix_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XY_id_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_instanced_basic_proxy kiwi::_picker_2d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_id_set& XYZ_id_set, 
	const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	vertex_buffer.to_location(0);
	XYZ_id_set.to_binding(0);

	if (m_transformation_matrix_ptr == nullptr)
	{
		m_picker_ptr->m_program_instanced_XY_id_2d.set_uniform_3x3f(m_picker_ptr->m_uniform_mvp_matrix_instanced_2d, kiwi::window_matrix_data());
	}
	else
	{
		m_picker_ptr->m_program_instanced_XY_id_2d.set_uniform_3x3f(m_picker_ptr->m_uniform_mvp_matrix_instanced_2d, m_transformation_matrix_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_id_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_basic_proxy kiwi::_picker_3d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept
{
	vertex_buffer.to_location(0);

	m_picker_ptr->m_program_picker_3d.set_uniform_4x4f(m_picker_ptr->m_uniform_mvp_matrix_3d, m_transformation_matrix_ptr)
		.set_uniform_1ui(m_picker_ptr->m_uniform_id_3d, static_cast<GLuint>(entity_id));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}