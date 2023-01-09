#include "space/kiwi_picker.hpp"
#include "shader_sources/kiwi_sources_picker.hpp"


namespace kiwi
{
	class picker_2d;
	class picker_instanced_XY_id_2d;

	class picker_3d;
	class picker_instanced_XYZ_id_3d;

	class picker_2d
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint id_location = -1;
	};

	class picker_instanced_XY_id_2d
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
	};



	class picker_3d
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint id_location = -1;
	};

	class picker_instanced_XYZ_id_3d
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
	};
}

namespace kiwi
{
	class picker_buffers
	{

	public:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		picker_buffers() = default;
		picker_buffers(const kiwi::picker_buffers&) = delete;
		kiwi::picker_buffers& operator=(const kiwi::picker_buffers&) = delete;
		picker_buffers(kiwi::picker_buffers&&) = delete;
		kiwi::picker_buffers& operator=(kiwi::picker_buffers&&) = delete;
		~picker_buffers() = default;

		kiwi::picker_2d m_program_picker_2d;
		kiwi::picker_instanced_XY_id_2d m_program_picker_instanced_XY_id_2d;
		kiwi::picker_3d m_program_picker_3d;
		kiwi::picker_instanced_XYZ_id_3d m_program_picker_instanced_XYZ_id_3d;
	};

	std::unique_ptr<kiwi::picker_buffers> picker_buffers_ptr;
}


bool kiwi::draw_id_init()
{
	if (!kiwi::picker_buffers_ptr)
	{
		bool success = true;

		try
		{
			kiwi::picker_buffers_ptr = std::make_unique<kiwi::picker_buffers>();

			if (!kiwi::picker_buffers_ptr)
			{
				return false;
			}

			success &= kiwi::picker_buffers_ptr->m_program_picker_2d.init();
			success &= kiwi::picker_buffers_ptr->m_program_picker_instanced_XY_id_2d.init();

			success &= kiwi::picker_buffers_ptr->m_program_picker_3d.init();
			success &= kiwi::picker_buffers_ptr->m_program_picker_instanced_XYZ_id_3d.init();
		}
		catch (...)
		{
			return false;
		}

		return success;
	}
	else
	{
		return false;
	}
}

void kiwi::draw_id_terminate() noexcept
{
	kiwi::picker_buffers_ptr.reset();
}


kiwi::picker& kiwi::picker::init(std::size_t width, std::size_t height) noexcept
{
	m_texture_buffer.allocate(kiwi::pixel_format::i16u, kiwi::size(width, height), 1, kiwi::pixel_mapping::nearest, kiwi::pixel_wrapping::clamp);
	m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(width, height));

	{
		kiwi::scoped_frame frame(m_frame_buffer);

		frame.get_frame_buffer()
			.attach_texture(&m_texture_buffer, 0)
			.attach_render_buffer(&m_render_buffer);
	}

	return *this;
}

kiwi::picker& kiwi::picker::resize(std::size_t width, std::size_t height) noexcept
{
	m_texture_buffer.allocate(kiwi::pixel_format::i16u, kiwi::size(width, height), 1, kiwi::pixel_mapping::nearest, kiwi::pixel_wrapping::clamp);
	m_render_buffer.allocate(kiwi::render_buffer_type::f24_st8, kiwi::size(width, height));

	return *this;
}

kiwi::picker& kiwi::picker::collect() noexcept
{
	m_frame_buffer.use_with_texture(0);
	return *this;
}

GLushort kiwi::picker::pick_id(std::size_t pixel_X, std::size_t pixel_Y) const noexcept
{
	GLushort entity_id;
	glReadPixels(static_cast<GLint>(pixel_X), static_cast<GLint>(pixel_Y), 1, 1, GL_RED_INTEGER, GL_UNSIGNED_SHORT, &entity_id);
	return entity_id;
}


kiwi::_picker_2d_proxy kiwi::draw_id_2d_with() noexcept
{
	kiwi::_picker_2d_proxy proxy;
	proxy.m_transformation_matrix_ptr = kiwi::window_matrix_data();
	return proxy;
}

kiwi::_picker_2d_proxy kiwi::draw_id_2d_with(const GLfloat* const mvp_matrix_ptr) noexcept
{
	kiwi::_picker_2d_proxy proxy;
	proxy.m_transformation_matrix_ptr = mvp_matrix_ptr;
	return proxy;
}

kiwi::_picker_3d_proxy kiwi::draw_id_3d_with(const GLfloat* const mvp_matrix_ptr) noexcept
{
	kiwi::_picker_3d_proxy proxy;
	proxy.m_transformation_matrix_ptr = mvp_matrix_ptr;
	return proxy;
}


kiwi::_draw_basic_proxy kiwi::_picker_2d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::picker_buffers_ptr->m_program_picker_2d.program
		.set_uniform_3x3f(kiwi::picker_buffers_ptr->m_program_picker_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1ui(kiwi::picker_buffers_ptr->m_program_picker_2d.id_location, static_cast<GLuint>(entity_id));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

/*
kiwi::_draw_instanced_basic_proxy kiwi::_picker_2d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XY_id_set& XY_id_set,
	const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	vertex_buffer.to_location(0);
	XY_id_set.to_binding(0);

	kiwi::picker_buffers_ptr->m_program_picker_instanced_XY_id_2d.program
		.set_uniform_3x3f(kiwi::picker_buffers_ptr->m_program_picker_instanced_XY_id_2d.mvp_matrix_location, m_transformation_matrix_ptr);

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

	kiwi::picker_buffers_ptr->m_program_picker_instanced_XY_id_2d.program
		.set_uniform_3x3f(kiwi::picker_buffers_ptr->m_program_picker_instanced_XY_id_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_id_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
*/

kiwi::_draw_basic_proxy kiwi::_picker_3d_proxy::using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::picker_buffers_ptr->m_program_picker_3d.program
		.set_uniform_4x4f(kiwi::picker_buffers_ptr->m_program_picker_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1ui(kiwi::picker_buffers_ptr->m_program_picker_3d.id_location, static_cast<GLuint>(entity_id));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}



bool kiwi::picker_2d::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::picker_2d::vertex_shader(),
		kiwi::source::picker_2d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		id_location = program.new_uniform_location("u_entity_id");
	}

	return success;
}

bool kiwi::picker_instanced_XY_id_2d::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::picker_XY_id_2d::vertex_shader(),
		kiwi::source::picker_XY_id_2d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::picker_3d::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::picker_3d::vertex_shader(),
		kiwi::source::picker_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		id_location = program.new_uniform_location("u_entity_id");
	}

	return success;
}

bool kiwi::picker_instanced_XYZ_id_3d::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::picker_XYZ_id_3d::vertex_shader(),
		kiwi::source::picker_XYZ_id_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}