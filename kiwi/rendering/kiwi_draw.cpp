#include "rendering/kiwi_draw.hpp"
#include "shader_sources/kiwi_sources_basic_2d.hpp"
#include "shader_sources/kiwi_sources_basic_3d.hpp"

namespace kiwi
{
	class basic_2d_solid_color;
	class basic_2d_color_gradient;
	class basic_2d_texture;
	class basic_2d_texture_alpha_test;
	class basic_2d_no_shade;
	class basic_2d_solid_color_sprites;
	class basic_2d_texture_sprites;

	class basic_3d_solid_color;
	class basic_3d_color_gradient;
	class basic_3d_texture;
	class basic_3d_texture_alpha_test;
	class basic_3d_skybox;
	class basic_3d_no_shade;

	class basic_3d_solid_color_sprite;
	class basic_3d_texture_sprite;

	class basic_3d_solid_color_sprites;
	class basic_3d_solid_color_sprites_split;
	class basic_3d_solid_color_sprites_matrix;
	class basic_3d_solid_color_sprites_matrix_split;

	class basic_3d_texture_sprites;
	class basic_3d_texture_sprites_split;
	class basic_3d_texturer_sprites_matrix;
	class basic_3d_texture_sprites_matrix_split;



	class basic_2d_solid_color
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint RGBA_location = -1;

		bool init() noexcept;
	};

	class basic_2d_color_gradient
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_2d_texture
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_2d_texture_alpha_test
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint alpha_test_location = -1;

		bool init() noexcept;
	};

	class basic_2d_no_shade
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_2d_solid_color_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_2d_texture_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint RGBA_location = -1;

		bool init() noexcept;
	};

	class basic_3d_color_gradient
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_alpha_test
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint alpha_test_location = -1;

		bool init() noexcept;
	};

	class basic_3d_skybox
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;

		bool init() noexcept;
	};

	class basic_3d_no_shade
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint depth_offset_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color_sprite
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;
		GLint XYZ_location = -1;
		GLint RGBA_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprite
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;
		GLint XYZ_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color_sprites_split
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color_sprites_matrix
	{

	public:

		kiwi::program program;
		GLint vp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color_sprites_matrix_split
	{

	public:

		kiwi::program program;
		GLint vp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprites_split
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprites_matrix
	{

	public:

		kiwi::program program;
		GLint vp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprites_matrix_split
	{

	public:

		kiwi::program program;
		GLint vp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;

		bool init() noexcept;
	};


	class default_buffers
	{

	public:

		default_buffers() = default;
		default_buffers(const kiwi::default_buffers&) = delete;
		kiwi::default_buffers& operator=(const kiwi::default_buffers&) = delete;
		default_buffers(kiwi::default_buffers&&) = delete;
		kiwi::default_buffers& operator=(kiwi::default_buffers&&) = delete;
		~default_buffers() = default;

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		kiwi::basic_2d_solid_color m_program_solid_color_2d;
		kiwi::basic_2d_color_gradient m_program_color_gradient_2d;
		kiwi::basic_2d_texture m_program_texture_2d;
		kiwi::basic_2d_texture_alpha_test m_program_texture_alpha_test_2d;
		kiwi::basic_2d_no_shade m_program_no_shade_2d;

		kiwi::basic_2d_solid_color_sprites m_program_solid_color_sprites_2d;
		kiwi::basic_2d_texture_sprites m_program_texture_sprites_2d;

		kiwi::basic_3d_solid_color m_program_solid_color_3d;
		kiwi::basic_3d_color_gradient m_program_color_gradient_3d;
		kiwi::basic_3d_texture m_program_texture_3d;
		kiwi::basic_3d_texture_alpha_test m_program_texture_alpha_test_3d;
		kiwi::basic_3d_skybox m_program_skybox_3d;
		kiwi::basic_3d_no_shade m_program_no_shade_3d;

		kiwi::basic_3d_solid_color_sprite m_program_solid_color_sprite_3d;
		kiwi::basic_3d_texture_sprite m_program_texture_sprite_3d;

		kiwi::basic_3d_solid_color_sprites m_program_solid_color_sprites_3d;
		kiwi::basic_3d_solid_color_sprites_split m_program_solid_color_sprites_split_3d;
		kiwi::basic_3d_solid_color_sprites_matrix m_program_solid_color_sprites_matrix_3d;
		kiwi::basic_3d_solid_color_sprites_matrix_split m_program_solid_color_sprites_matrix_split_3d;

		kiwi::basic_3d_texture_sprites m_program_texture_sprites_3d;
		kiwi::basic_3d_texture_sprites_split m_program_texture_sprites_split_3d;
		kiwi::basic_3d_texture_sprites_matrix m_program_texture_sprites_matrix_3d;
		kiwi::basic_3d_texture_sprites_matrix_split m_program_texture_sprites_matrix_split_3d;
	};
}

bool kiwi::draw_init()
{
	if (!kiwi::is_global_type_created<kiwi::default_buffers>())
	{
		bool success = true;

		try
		{
			kiwi::make_global_type<kiwi::default_buffers>();

			if (!kiwi::is_global_type_created<kiwi::default_buffers>())
			{
				return false;
			}

			kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

			success &= buffers.m_program_solid_color_2d.init();
			success &= buffers.m_program_color_gradient_2d.init();
			success &= buffers.m_program_texture_2d.init();
			success &= buffers.m_program_texture_alpha_test_2d.init();
			success &= buffers.m_program_no_shade_2d.init();

			success &= buffers.m_program_solid_color_sprites_2d.init();
			success &= buffers.m_program_texture_sprites_2d.init();

			success &= buffers.m_program_solid_color_3d.init();
			success &= buffers.m_program_texture_3d.init();
			success &= buffers.m_program_texture_alpha_test_3d.init();
			success &= buffers.m_program_skybox_3d.init();
			success &= buffers.m_program_no_shade_3d.init();

			success &= buffers.m_program_solid_color_sprite_3d.init();
			success &= buffers.m_program_texture_sprite_3d.init();

			success &= buffers.m_program_solid_color_sprites_3d.init();
			success &= buffers.m_program_solid_color_sprites_split_3d.init();
			success &= buffers.m_program_solid_color_sprites_matrix_3d.init();
			success &= buffers.m_program_solid_color_sprites_matrix_split_3d.init();

			success &= buffers.m_program_texture_sprites_3d.init();
			success &= buffers.m_program_texture_sprites_split_3d.init();
			success &= buffers.m_program_texture_sprites_matrix_3d.init();
			success &= buffers.m_program_texture_sprites_matrix_split_3d.init();
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
void kiwi::draw_terminate() noexcept
{
	kiwi::delete_global_type<kiwi::default_buffers>();
}



// 2D SELECT PROGRAM

kiwi::_load_basic_2d_proxy kiwi::draw_2d_with() noexcept
{
	kiwi::_load_basic_2d_proxy proxy;
	proxy.m_transformation_matrix_ptr = kiwi::window_matrix_data();
	return proxy;
}
kiwi::_load_basic_2d_proxy kiwi::draw_2d_with(const GLfloat* const transformation_matrix_ptr) noexcept
{
	kiwi::_load_basic_2d_proxy proxy;
	proxy.m_transformation_matrix_ptr = transformation_matrix_ptr;
	return proxy;
}

kiwi::_load_2d_proxy kiwi::draw_2d_with(const kiwi::program& prog) noexcept
{
	kiwi::_load_2d_proxy proxy;
	proxy.m_program_ptr = &prog;
	return proxy;
}
kiwi::_load_2d_proxy kiwi::draw_2d_with(const kiwi::program& prog, const GLfloat* const transformation_matrix_matrix_ptr, GLint transformation_matrix_location) noexcept
{
	kiwi::_load_2d_proxy proxy;
	prog.set_uniform_3x3f(transformation_matrix_location, transformation_matrix_matrix_ptr);
	proxy.m_program_ptr = &prog;
	return proxy;
}


// 3D SELECT PROGRAM

kiwi::_load_basic_3d_proxy kiwi::draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept
{
	kiwi::_load_basic_3d_proxy proxy;
	proxy.m_transformation_matrix_ptr = transformation_matrix_ptr;
	return proxy;
}

kiwi::_load_3d_proxy kiwi::draw_3d_with(const kiwi::program& prog, const GLfloat* const transformation_matrix_ptr, GLint transformation_matrix_location) noexcept
{
	kiwi::_load_3d_proxy proxy;
	prog.set_uniform_4x4f(transformation_matrix_location, transformation_matrix_ptr);
	proxy.m_program_ptr = &prog;
	return proxy;
}


// 2D SELECT BUFFERS

kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);

	buffers.m_program_solid_color_2d.program.set_uniform_3x3f(buffers.m_program_solid_color_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(buffers.m_program_solid_color_2d.RGBA_location, solid_color.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	buffers.m_program_color_gradient_2d.program.set_uniform_3x3f(buffers.m_program_color_gradient_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, GLfloat alpha_test_value) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	buffers.m_program_texture_alpha_test_2d.program.set_uniform_3x3f(buffers.m_program_texture_alpha_test_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_alpha_test_2d.alpha_test_location, alpha_test_value);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_no_shade(const kiwi::vertex_buffer& vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);

	buffers.m_program_no_shade_2d.program.set_uniform_3x3f(buffers.m_program_no_shade_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_2d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XY_RGBA_set& XY_RGBA_set) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	XY_RGBA_set.to_binding(0);

	buffers.m_program_solid_color_sprites_2d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XY_RGBA_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_2d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_RGBA_set& XYZ_RGBA_set) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	XYZ_RGBA_set.to_binding(0);

	buffers.m_program_solid_color_sprites_2d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_RGBA_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_2d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::XY_UV_set& XY_UV_set) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	XY_UV_set.to_binding(0, 0);

	buffers.m_program_texture_sprites_2d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XY_UV_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_2d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::XYZ_UV_set& XYZ_UV_set) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	XYZ_UV_set.to_binding(0, 0);

	buffers.m_program_texture_sprites_2d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_UV_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_proxy kiwi::_load_2d_proxy::using_data(
	const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(vertex_buffers_ptr + n)->to_location(*(vertex_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffers_ptr->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_2d_proxy::using_data(
	const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(*(vertex_buffers_ptr + n))->to_location(*(vertex_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = (*vertex_buffers_ptr)->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_2d_proxy::using_data(
	const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(vertex_buffers_ptr + n)->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(texture_buffers_ptr + n)->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffers_ptr->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_2d_proxy::using_data(
	const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(*(vertex_buffers_ptr + n))->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(texture_buffers_ptr + n)->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = (*vertex_buffers_ptr)->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_2d_proxy::using_data(
	const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(vertex_buffers_ptr + n)->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(*(texture_buffers_ptr + n))->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffers_ptr->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_2d_proxy::using_data(
	const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(*(vertex_buffers_ptr + n))->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(*texture_buffers_ptr + n)->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = (*vertex_buffers_ptr)->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}


// 3D SELECT BUFFERS

kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);

	buffers.m_program_solid_color_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(buffers.m_program_solid_color_3d.RGBA_location, solid_color.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	buffers.m_program_color_gradient_3d.program.set_uniform_4x4f(buffers.m_program_color_gradient_3d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture_buffer) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	buffers.m_program_texture_3d.program.set_uniform_4x4f(buffers.m_program_texture_3d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture_buffer, GLfloat alpha_test_value) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	buffers.m_program_texture_alpha_test_3d.program.set_uniform_4x4f(buffers.m_program_texture_alpha_test_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_alpha_test_3d.alpha_test_location, alpha_test_value);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

void kiwi::_load_basic_3d_proxy::using_skybox(const kiwi::cubemap_buffer& skybox_buffer) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	skybox_buffer.to_binding(0);

	buffers.m_program_skybox_3d.program.set_uniform_4x4f(buffers.m_program_skybox_3d.mvp_matrix_location, m_transformation_matrix_ptr);

	glDrawArrays(GL_QUADS, 0, 24);
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_no_shade(const kiwi::vertex_buffer& vertex_buffer, GLfloat depth_offset) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);

	buffers.m_program_no_shade_3d.program.set_uniform_4x4f(buffers.m_program_no_shade_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(buffers.m_program_no_shade_3d.depth_offset_location, depth_offset);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color, const GLfloat* const XYZ_ptr,
	const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);

	buffers.m_program_solid_color_sprite_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_sprite_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (mvp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_solid_color_sprite_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprite_3d.mvp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_solid_color_sprite_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprite_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr);
	}

	buffers.m_program_solid_color_sprite_3d.program.set_uniform_3f(buffers.m_program_solid_color_sprite_3d.XYZ_location, XYZ_ptr)
		.set_uniform_4f(buffers.m_program_solid_color_sprite_3d.RGBA_location, solid_color.data());
		
	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_RGBA_set& XYZ_RGBA_set,
	const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	XYZ_RGBA_set.to_binding(0);

	buffers.m_program_solid_color_sprites_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_sprites_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (mvp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_solid_color_sprites_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_3d.mvp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_solid_color_sprites_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_RGBA_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_set& XYZ_set, const kiwi::XYZ_set& RGBA_set,
	const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	XYZ_set.to_binding(0);
	RGBA_set.to_binding(1);

	buffers.m_program_solid_color_sprites_split_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_sprites_split_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (mvp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_solid_color_sprites_split_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_split_3d.mvp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_solid_color_sprites_split_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_split_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_RGBA_set& XYZ_RGBA_set,
	const kiwi::mat3x3f_set& mat3x3f_set, const GLfloat* const vp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	XYZ_RGBA_set.to_binding(0);
	mat3x3f_set.to_binding(1);

	buffers.m_program_solid_color_sprites_matrix_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_sprites_matrix_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (vp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_solid_color_sprites_matrix_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_matrix_3d.vp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_solid_color_sprites_matrix_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_matrix_3d.vp_matrix_2d_location, vp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_RGBA_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_set& XYZ_set, const kiwi::XYZ_set& RGBA_set,
	const kiwi::mat3x3f_set& mat3x3f_set, const GLfloat* const vp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	XYZ_set.to_binding(0);
	RGBA_set.to_binding(1);
	mat3x3f_set.to_binding(2);

	buffers.m_program_solid_color_sprites_matrix_split_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_sprites_matrix_split_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (vp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_solid_color_sprites_matrix_split_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_matrix_split_3d.vp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_solid_color_sprites_matrix_split_3d.program.set_uniform_3x3f(buffers.m_program_solid_color_sprites_matrix_split_3d.vp_matrix_2d_location, vp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture_buffer, const GLfloat* const XYZ_ptr, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	buffers.m_program_texture_sprite_3d.program.set_uniform_4x4f(buffers.m_program_texture_sprite_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (mvp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_texture_sprite_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprite_3d.mvp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_texture_sprite_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprite_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr);
	}

	buffers.m_program_texture_sprite_3d.program.set_uniform_3f(buffers.m_program_texture_sprite_3d.XYZ_location, XYZ_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::XYZ_UV_set& XYZ_UV_set, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	XYZ_UV_set.to_binding(0, 0);

	buffers.m_program_texture_sprites_3d.program.set_uniform_4x4f(buffers.m_program_texture_sprites_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (mvp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_texture_sprites_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_3d.mvp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_texture_sprites_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_UV_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::XYZ_set& XYZ_set, const kiwi::UV_set& UV_set, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	XYZ_set.to_binding(0);
	UV_set.to_binding(1, 0);

	buffers.m_program_texture_sprites_split_3d.program.set_uniform_4x4f(buffers.m_program_texture_sprites_split_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (mvp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_texture_sprites_split_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_split_3d.mvp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_texture_sprites_split_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_split_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::XYZ_UV_set& XYZ_UV_set, const kiwi::mat3x3f_set& mat3x3f_set, const GLfloat* const vp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	XYZ_UV_set.to_binding(0, 0);
	mat3x3f_set.to_binding(1);

	buffers.m_program_texture_sprites_matrix_3d.program.set_uniform_4x4f(buffers.m_program_texture_sprites_matrix_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (vp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_texture_sprites_matrix_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_matrix_3d.vp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_texture_sprites_matrix_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_matrix_3d.vp_matrix_2d_location, vp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_UV_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::XYZ_set& XYZ_set, const kiwi::UV_set& UV_set, const kiwi::mat3x3f_set& mat3x3f_set, const GLfloat* const vp_matrix_2d_ptr) noexcept
{
	kiwi::global_type<kiwi::default_buffers> buffers = kiwi::get_global_type<kiwi::default_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	XYZ_set.to_binding(0);
	UV_set.to_binding(1, 0);
	mat3x3f_set.to_binding(2);

	buffers.m_program_texture_sprites_matrix_split_3d.program.set_uniform_4x4f(buffers.m_program_texture_sprites_matrix_split_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr);

	if (vp_matrix_2d_ptr == nullptr)
	{
		buffers.m_program_texture_sprites_matrix_split_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_matrix_split_3d.vp_matrix_2d_location, kiwi::window_matrix_data());
	}
	else
	{
		buffers.m_program_texture_sprites_matrix_split_3d.program.set_uniform_3x3f(buffers.m_program_texture_sprites_matrix_split_3d.vp_matrix_2d_location, vp_matrix_2d_ptr);
	}

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZ_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_proxy kiwi::_load_3d_proxy::using_data(
	const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(vertex_buffers_ptr + n)->to_location(*(vertex_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffers_ptr->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_data(
	const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(*(vertex_buffers_ptr + n))->to_location(*(vertex_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = (*vertex_buffers_ptr)->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_data(
	const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(vertex_buffers_ptr + n)->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(texture_buffers_ptr + n)->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffers_ptr->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_data(
	const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(*(vertex_buffers_ptr + n))->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(texture_buffers_ptr + n)->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = (*vertex_buffers_ptr)->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_data(
	const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(vertex_buffers_ptr + n)->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(*(texture_buffers_ptr + n))->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffers_ptr->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_data(
	const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
	const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept
{
	for (std::size_t n = 0; n < vertex_buffer_count; n++)
	{
		(*(vertex_buffers_ptr + n))->to_location(*(vertex_pipeline_locations_ptr + n));
	}
	for (std::size_t n = 0; n < texture_buffer_count; n++)
	{
		(*(texture_buffers_ptr + n))->to_binding(*(texture_pipeline_locations_ptr + n));
	}

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = (*vertex_buffers_ptr)->vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_proxy kiwi::_load_3d_proxy::using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location) noexcept
{
	vertex_buffer.to_location(location);

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location, std::size_t begin_float, std::size_t number_of_floats) noexcept
{
	vertex_buffer.to_location(location, begin_float, number_of_floats);

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_proxy kiwi::_load_3d_proxy::using_texture_data(const kiwi::texture_buffer& texture_buffer, GLuint location) noexcept
{
	texture_buffer.to_binding(location);

	kiwi::_draw_proxy proxy;
	proxy.m_vertex_count = 0;
	proxy.m_program_ptr = m_program_ptr;
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}


////// 2D/3D SET UNIFORMS //////

kiwi::_draw_proxy& kiwi::_draw_proxy::using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location) noexcept
{
	vertex_buffer.to_location(location);
	if (m_vertex_count == 0)
	{
		m_vertex_count = vertex_buffer.vertex_count();
	}
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location, std::size_t begin_float, std::size_t number_of_floats) noexcept
{
	vertex_buffer.to_location(location, begin_float, number_of_floats);
	if (m_vertex_count == 0)
	{
		m_vertex_count = vertex_buffer.vertex_count();
	}
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_texture_data(const kiwi::texture_buffer& texture_buffer, GLuint location) noexcept
{
	texture_buffer.to_binding(location);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_storage_buffer(const kiwi::storage_buffer& storage_buffer, GLuint binding) noexcept
{
	storage_buffer.to_binding(binding);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_storage_buffer(const kiwi::storage_buffer& storage_buffer, GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) noexcept
{
	storage_buffer.to_binding(binding, begin_byte, number_of_bytes);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_1f(GLint location, GLfloat u0) noexcept
{
	m_program_ptr->set_uniform_1f(location, u0);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_2f(GLint location, GLfloat u0, GLfloat u1) noexcept
{
	m_program_ptr->set_uniform_2f(location, u0, u1);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3f(GLint location, GLfloat u0, GLfloat u1, GLfloat u2) noexcept
{
	m_program_ptr->set_uniform_3f(location, u0, u1, u2);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4f(GLint location, GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) noexcept
{
	m_program_ptr->set_uniform_4f(location, u0, u1, u2, u3);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_2f(GLint location, const GLfloat* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_2f(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3f(GLint location, const GLfloat* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_3f(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4f(GLint location, const GLfloat* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_4f(location, values_ptr);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3x3f(GLint location, const GLfloat* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_3x3f(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4x4f(GLint location, const GLfloat* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_4x4f(location, values_ptr);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_1i(GLint location, GLint u0) noexcept
{
	m_program_ptr->set_uniform_1i(location, u0);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_2i(GLint location, GLint u0, GLint u1) noexcept
{
	m_program_ptr->set_uniform_2i(location, u0, u1);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3i(GLint location, GLint u0, GLint u1, GLint u2) noexcept
{
	m_program_ptr->set_uniform_3i(location, u0, u1, u2);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4i(GLint location, GLint u0, GLint u1, GLint u2, GLint u3) noexcept
{
	m_program_ptr->set_uniform_4i(location, u0, u1, u2, u3);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_2i(GLint location, const GLint* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_2i(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3i(GLint location, const GLint* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_3i(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4i(GLint location, const GLint* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_4i(location, values_ptr);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_1ui(GLint location, GLuint u0) noexcept
{
	m_program_ptr->set_uniform_1ui(location, u0);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_2ui(GLint location, GLuint u0, GLuint u1) noexcept
{
	m_program_ptr->set_uniform_2ui(location, u0, u1);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3ui(GLint location, GLuint u0, GLuint u1, GLuint u2) noexcept
{
	m_program_ptr->set_uniform_3ui(location, u0, u1, u2);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4ui(GLint location, GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept
{
	m_program_ptr->set_uniform_4ui(location, u0, u1, u2, u3);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_2ui(GLint location, const GLuint* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_2ui(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_3ui(GLint location, const GLuint* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_3ui(location, values_ptr);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_uniform_4ui(GLint location, const GLuint* const values_ptr) noexcept
{
	m_program_ptr->set_uniform_4ui(location, values_ptr);
	return *this;
}


////// 2D/3D USE INDICES //////

kiwi::_draw_basic_proxy& kiwi::_draw_basic_proxy::using_indices(const kiwi::index_buffer& index_buffer) noexcept
{
	index_buffer.bind();
	m_index_count = static_cast<int>(index_buffer.index_count());
	return *this;
}
kiwi::_draw_basic_proxy& kiwi::_draw_basic_proxy::using_indices(const kiwi::index_buffer& index_buffer, std::size_t index_count) noexcept
{
	index_buffer.bind();
	m_index_count = static_cast<int>(index_count);
	return *this;
}
kiwi::_draw_basic_proxy& kiwi::_draw_basic_proxy::using_indices(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	m_index_data_ptr = index_data_ptr;
	m_index_count = static_cast<int>(index_count);
	return *this;
}
kiwi::_draw_basic_proxy& kiwi::_draw_basic_proxy::using_indices(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	m_index_data_ptr = index_data_ptr + begin_index;
	m_index_count = static_cast<int>(index_count);
	return *this;
}

kiwi::_draw_instanced_basic_proxy& kiwi::_draw_instanced_basic_proxy::using_indices(const kiwi::index_buffer& index_buffer) noexcept
{
	index_buffer.bind();
	m_index_count = static_cast<int>(index_buffer.index_count());
	return *this;
}
kiwi::_draw_instanced_basic_proxy& kiwi::_draw_instanced_basic_proxy::using_indices(const kiwi::index_buffer& index_buffer, std::size_t index_count) noexcept
{
	index_buffer.bind();
	m_index_count = static_cast<int>(index_count);
	return *this;
}
kiwi::_draw_instanced_basic_proxy& kiwi::_draw_instanced_basic_proxy::using_indices(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	m_index_data_ptr = index_data_ptr;
	m_index_count = static_cast<int>(index_count);
	return *this;
}
kiwi::_draw_instanced_basic_proxy& kiwi::_draw_instanced_basic_proxy::using_indices(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	m_index_data_ptr = index_data_ptr + begin_index;
	m_index_count = static_cast<int>(index_count);
	return *this;
}

kiwi::_draw_proxy& kiwi::_draw_proxy::using_indices(const kiwi::index_buffer& index_buffer) noexcept
{
	index_buffer.bind();
	m_index_count = static_cast<int>(index_buffer.index_count());
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_indices(const kiwi::index_buffer& index_buffer, std::size_t index_count) noexcept
{
	index_buffer.bind();
	m_index_count = static_cast<int>(index_count);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_indices(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	m_index_data_ptr = index_data_ptr;
	m_index_count = static_cast<int>(index_count);
	return *this;
}
kiwi::_draw_proxy& kiwi::_draw_proxy::using_indices(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	m_index_data_ptr = index_data_ptr + begin_index;
	m_index_count = static_cast<int>(index_count);
	return *this;
}


////// 2D/3D DRAW //////

void kiwi::_draw_basic_proxy::points() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::points(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::points(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_POINTS, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::lines() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::lines(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::lines(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINES, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::triangles() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::triangles(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::triangles(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLES, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::quads() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::quads(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::quads(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_QUADS, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::line_strip() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::line_strip(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::line_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_STRIP, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::line_loop() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::line_loop(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::line_loop(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_LOOP, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::triangle_strip() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::triangle_strip(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::triangle_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}

void kiwi::_draw_basic_proxy::triangle_fan() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::triangle_fan(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_basic_proxy::triangle_fan(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}


void kiwi::_draw_instanced_basic_proxy::points_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::points_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::points_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::points_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_instanced_basic_proxy::lines_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::lines_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::lines_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::lines_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_instanced_basic_proxy::triangles_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangles_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangles_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangles_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_instanced_basic_proxy::quads_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::quads_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::quads_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::quads_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_instanced_basic_proxy::line_strip_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::line_strip_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::line_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_instanced_basic_proxy::line_loop_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_LOOP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::line_loop_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_LOOP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::line_loop_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_LOOP, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_instanced_basic_proxy::triangle_strip_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangle_strip_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}


void kiwi::_draw_instanced_basic_proxy::triangle_fan_instanced() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(m_instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(m_instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangle_fan_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_instanced_basic_proxy::triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}



void kiwi::_draw_proxy::points() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::points(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::points(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_POINTS, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::points_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::points_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::points_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_POINTS, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::lines() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::lines(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::lines(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINES, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::lines_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::lines_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::lines_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINES, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::triangles() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::triangles(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::triangles(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLES, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::triangles_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::triangles_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::triangles_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLES, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::quads() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::quads(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::quads(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_QUADS, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::quads_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::quads_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::quads_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_QUADS, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::line_strip() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(m_vertex_count));
	}
	else
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(m_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::line_strip(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::line_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_STRIP, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::line_strip_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::line_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::line_loop() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(m_vertex_count));
	}
}
void kiwi::_draw_proxy::line_loop(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::line_loop(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_LINE_LOOP, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::line_loop_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::line_loop_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_LINE_LOOP, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::triangle_strip() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(m_vertex_count));
	}
}
void kiwi::_draw_proxy::triangle_strip(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::triangle_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::triangle_strip_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::_draw_proxy::triangle_fan() noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(m_vertex_count));
	}
}
void kiwi::_draw_proxy::triangle_fan(std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_or_index_count));
	}
	else
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr));
	}
}
void kiwi::_draw_proxy::triangle_fan(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArrays(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex_or_index), static_cast<GLsizei>(vertex_or_index_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count),
			GL_UNSIGNED_INT, static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index));
	}
}
void kiwi::_draw_proxy::triangle_fan_instanced(std::size_t instance_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(m_vertex_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(m_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr), static_cast<GLsizei>(instance_count));
	}
}
void kiwi::_draw_proxy::triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept
{
	if (m_index_count == -1)
	{
		glDrawArraysInstanced(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex_or_index),
			static_cast<GLsizei>(vertex_or_index_count), static_cast<GLsizei>(instance_count));
	}
	else if (m_index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(vertex_or_index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(m_index_data_ptr + begin_vertex_or_index), static_cast<GLsizei>(instance_count));
	}
}


// DRAW CALL FREE FUNCTIONS

void kiwi::draw_call::points(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::points(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_POINTS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::points_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::points_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::points_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::points_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_POINTS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::lines(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::lines(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::lines_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::lines_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::lines_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::lines_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::triangles(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangles_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::triangles_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::triangles_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::triangles_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::quads(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::quads_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::quads_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::quads_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::quads_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_QUADS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, ::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::line_strip(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_strip(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_strip_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::line_strip_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::line_strip_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::line_strip_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::line_loop(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_loop(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_LOOP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_loop_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::line_loop_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::line_loop_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::line_loop_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_LOOP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::triangle_strip(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_strip(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_strip_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::triangle_strip_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::triangle_strip_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::triangle_fan(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_fan(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_fan_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::triangle_fan_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::triangle_fan_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}


bool kiwi::basic_2d_solid_color::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_2d_solid_color::vertex_shader(),
		kiwi::source::basic_2d_solid_color::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		RGBA_location = program.new_uniform_location("u_RGBA");
	}

	return success;
}

bool kiwi::basic_2d_color_gradient::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_2d_color_gradient::vertex_shader(),
		kiwi::source::basic_2d_color_gradient::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::basic_2d_texture::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_2d_texture::vertex_shader(),
		kiwi::source::basic_2d_texture::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::basic_2d_texture_alpha_test::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_2d_texture_alpha_test::vertex_shader(),
		kiwi::source::basic_2d_texture_alpha_test::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		alpha_test_location = program.new_uniform_location("u_alpha_test");
	}

	return success;
}

bool kiwi::basic_2d_no_shade::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_2d_no_shade::vertex_shader(),
		kiwi::source::basic_2d_no_shade::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::basic_2d_solid_color_sprites::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (std430, binding = 0) buffer s_XY_RGBA { vec4 XY_RGBA[][2]; };	\n"
		"	out vec4 RGBA;															\n"
		"	uniform mat3 u_mvp_M;													\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec3 in_XYh = u_mvp_M * vec3(in_XY									\n"
		"			+ vec2(XY_RGBA[gl_InstanceID][0]), 1.0);						\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],							\n"
		"			XY_RGBA[gl_InstanceID][0][2], 1.0);								\n"

		"		RGBA = XY_RGBA[gl_InstanceID][1];									\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec4 RGBA;															\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = RGBA;														\n"
		"	}																		\n"
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::basic_2d_texture_sprites::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (location = 1) in vec2 in_UV;									\n"
		"	layout (std430, binding = 0) buffer s_XY_UV { vec4 XY_UV[][2]; };		\n"
		"	out vec2 UV;															\n"
		"	uniform mat3 u_mvp_M;													\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec3 in_XYh = u_mvp_M * vec3(in_XY									\n"
		"			+ vec2(XY_UV[gl_InstanceID][0]), 1.0);							\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],							\n"
		"			XY_UV[gl_InstanceID][0][2], 1.0);								\n"

		"		UV = in_UV + vec2(XY_UV[gl_InstanceID][1]);							\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec2 UV;																\n"
		"	out vec4 color;															\n"
		"	uniform sampler2D Tx;													\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = texture(Tx, UV);											\n"
		"	}																		\n"
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}


bool kiwi::basic_3d_solid_color::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_solid_color::vertex_shader(),
		kiwi::source::basic_3d_solid_color::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		RGBA_location = program.new_uniform_location("u_RGBA");
	}

	return success;
}

bool kiwi::basic_3d_color_gradient::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_color_gradient::vertex_shader(),
		kiwi::source::basic_3d_color_gradient::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::basic_3d_texture::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_texture::vertex_shader(),
		kiwi::source::basic_3d_texture::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
	}

	return success;
}

bool kiwi::basic_3d_texture_alpha_test::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_texture_alpha_test::vertex_shader(),
		kiwi::source::basic_3d_texture_alpha_test::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		alpha_test_location = program.new_uniform_location("u_alpha_test");
	}

	return success;
}

bool kiwi::basic_3d_skybox::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_skybox::vertex_shader(),
		kiwi::source::basic_3d_skybox::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		program.set_uniform_1i("skybox", static_cast<GLint>(0));
	}

	return success;
}

bool kiwi::basic_3d_no_shade::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_no_shade::vertex_shader(),
		kiwi::source::basic_3d_no_shade::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		depth_offset_location = program.new_uniform_location("u_depth_offset");
	}

	return success;
}

bool kiwi::basic_3d_solid_color_sprite::init() noexcept
{
	bool success = program.new_program(

		"	#version 330 core								\n"
		"	layout (location = 0) in vec2 in_XY;			\n"
		"	uniform vec3 u_XYZ;								\n"
		"	uniform mat3 u_mvp_M_2d;						\n"
		"	uniform mat4 u_mvp_M_3d;						\n"

		"	void main()										\n"
		"	{												\n"
		"		vec4 XYZ = u_mvp_M_3d * vec4(u_XYZ, 1.0);	\n"
		"		vec3 XY = u_mvp_M_2d * vec3(in_XY, 1.0);	\n"
		"		XYZ.xy += XY.xy;							\n"

		"		gl_Position = XYZ;							\n"
		"	}												\n"
		,

		"	#version 330 core								\n"
		"	out vec4 color;									\n"
		"	uniform vec4 u_RGBA;							\n"

		"	void main()										\n"
		"	{												\n"
		"		color = u_RGBA;								\n"
		"	}												\n"
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		XYZ_location = program.new_uniform_location("u_XYZ");
		RGBA_location = program.new_uniform_location("u_RGBA");
	}

	return success;
}

bool kiwi::basic_3d_solid_color_sprites::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ_RGBA { vec4 XYZ_RGBA[][2]; };	\n"
		"	out vec4 RGBA;															\n"
		"	uniform mat3 u_mvp_M_2d;												\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * XYZ_RGBA[gl_InstanceID][0];					\n"
		"		RGBA = XYZ_RGBA[gl_InstanceID][1];									\n"
		"		vec3 XY = u_mvp_M_2d * vec3(in_XY, 1.0);							\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec4 RGBA;															\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = RGBA;														\n"
		"	}																		\n"
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_solid_color_sprites_split::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ { vec4 t_XYZ[]; };			\n"
		"	layout (std430, binding = 1) buffer s_RGBA { vec4 t_RGBA[]; };			\n"
		"	out vec4 RGBA;															\n"
		"	uniform mat3 u_mvp_M_2d;												\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * t_XYZ[gl_InstanceID];						\n"
		"		RGBA = t_RGBA[gl_InstanceID];										\n"
		"		vec3 XY = u_mvp_M_2d * vec3(in_XY, 1.0);							\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec4 RGBA;															\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = RGBA;														\n"
		"	}																		\n"
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_solid_color_sprites_matrix::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ_RGBA { vec4 XYZ_RGBA[][2]; };	\n"
		"	layout (std430, binding = 1) buffer s_m_M_2d { mat3 m_M_2d[]; };		\n"
		"	out vec4 RGBA;															\n"
		"	uniform mat3 u_vp_M_2d;													\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * XYZ_RGBA[gl_InstanceID][0];					\n"
		"		RGBA = XYZ_RGBA[gl_InstanceID][1];									\n"
		"		vec3 XY = u_vp_M_2d * (m_M_2d[gl_InstanceID] * vec3(in_XY, 1.0));	\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec4 RGBA;															\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = RGBA;														\n"
		"	}																		\n"
	);

	if (success)
	{
		vp_matrix_2d_location = program.new_uniform_location("u_vp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_solid_color_sprites_matrix_split::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ { vec4 t_XYZ[]; };			\n"
		"	layout (std430, binding = 1) buffer s_RGBA { vec4 t_RGBA[]; };			\n"
		"	layout (std430, binding = 2) buffer s_m_M_2d { mat3 m_M_2d[]; };		\n"
		"	out vec4 RGBA;															\n"
		"	uniform mat3 u_vp_M_2d;													\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * t_XYZ[gl_InstanceID];						\n"
		"		RGBA = t_RGBA[gl_InstanceID];										\n"
		"		vec3 XY = u_vp_M_2d * (m_M_2d[gl_InstanceID] * vec3(in_XY, 1.0));	\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec4 RGBA;															\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = RGBA;														\n"
		"	}																		\n"
	);
	
	if (success)
	{
		vp_matrix_2d_location = program.new_uniform_location("u_vp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprite::init() noexcept
{
	bool success = program.new_program(

		"	#version 330 core								\n"
		"	layout (location = 0) in vec2 in_XY;			\n"
		"	layout (location = 1) in vec2 in_UV;			\n"
		"	out vec2 UV;									\n"
		"	uniform vec3 u_XYZ;								\n"
		"	uniform mat3 u_mvp_M_2d;						\n"
		"	uniform mat4 u_mvp_M_3d;						\n"

		"	void main()										\n"
		"	{												\n"
		"		vec4 XYZ = u_mvp_M_3d * vec4(u_XYZ, 1.0);	\n"
		"		vec3 XY = u_mvp_M_2d * vec3(in_XY, 1.0);	\n"
		"		XYZ.xy += XY.xy;							\n"

		"		gl_Position = XYZ;							\n"
		"		UV = in_UV;									\n"
		"	}												\n"
		,

		"	#version 330 core								\n"
		"	in vec2 UV;										\n"
		"	out vec4 color;									\n"
		"	uniform sampler2D Tx;							\n"

		"	void main()										\n"
		"	{												\n"
		"		color = texture(Tx, UV);					\n"
		"	}												\n"
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		XYZ_location = program.new_uniform_location("u_XYZ");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprites::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (location = 1) in vec2 in_UV;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ_UV { vec4 XYZ_UV[][2]; };		\n"
		"	out vec2 UV;															\n"
		"	uniform mat3 u_mvp_M_2d;												\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * XYZ_UV[gl_InstanceID][0];					\n"
		"		vec3 XY = u_mvp_M_2d * vec3(in_XY, 1.0);							\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"		UV = in_UV + vec2(XYZ_UV[gl_InstanceID][1]);						\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec2 UV;																\n"
		"	uniform sampler2D Tx;													\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = texture(Tx, UV);											\n"
		"	}																		\n"
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprites_split::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (location = 1) in vec2 in_UV;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ { vec4 t_XYZ[]; };			\n"
		"	layout (std430, binding = 1) buffer s_UV { vec2 t_UV[]; };				\n"
		"	out vec2 UV;															\n"
		"	uniform mat3 u_mvp_M_2d;												\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * t_XYZ[gl_InstanceID];						\n"
		"		vec3 XY = u_mvp_M_2d * vec3(in_XY, 1.0);							\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"		UV = in_UV + t_UV[gl_InstanceID];									\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec2 UV;																\n"
		"	uniform sampler2D Tx;													\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = texture(Tx, UV);											\n"
		"	}																		\n"
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprites_matrix::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (location = 1) in vec2 in_UV;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ_UV { vec4 XYZ_UV[][2]; };		\n"
		"	layout (std430, binding = 1) buffer s_m_M_2d { mat3 m_M_2d[]; };		\n"
		"	out vec2 UV;															\n"
		"	uniform mat3 u_vp_M_2d;													\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * XYZ_UV[gl_InstanceID][0];					\n"
		"		vec3 XY = u_vp_M_2d * (m_M_2d[gl_InstanceID] * vec3(in_XY, 1.0));	\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"		UV = in_UV + vec2(XYZ_UV[gl_InstanceID][1]);						\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec2 UV;																\n"
		"	uniform sampler2D Tx;													\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = texture(Tx, UV);											\n"
		"	}																		\n"
	);

	if (success)
	{
		vp_matrix_2d_location = program.new_uniform_location("u_vp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprites_matrix_split::init() noexcept
{
	bool success = program.new_program(

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	layout (location = 1) in vec2 in_UV;									\n"
		"	layout (std430, binding = 0) buffer s_XYZ { vec4 t_XYZ[]; };			\n"
		"	layout (std430, binding = 1) buffer s_UV { vec2 t_UV[]; };				\n"
		"	layout (std430, binding = 2) buffer s_m_M_2d { mat3 m_M_2d[]; };		\n"
		"	out vec2 UV;															\n"
		"	uniform mat3 u_vp_M_2d;													\n"
		"	uniform mat4 u_mvp_M_3d;												\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec4 XYZ = u_mvp_M_3d * t_XYZ[gl_InstanceID];						\n"
		"		vec3 XY = u_vp_M_2d * (m_M_2d[gl_InstanceID] * vec3(in_XY, 1.0));	\n"
		"		XYZ.xy += XY.xy;													\n"

		"		gl_Position = XYZ;													\n"
		"		UV = in_UV + t_UV[gl_InstanceID];									\n"
		"	}																		\n"
		,

		"	#version 330 core														\n"
		"	in vec2 UV;																\n"
		"	uniform sampler2D Tx;													\n"
		"	out vec4 color;															\n"

		"	void main()																\n"
		"	{																		\n"
		"		color = texture(Tx, UV);											\n"
		"	}																		\n"
	);

	if (success)
	{
		vp_matrix_2d_location = program.new_uniform_location("u_vp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
	}

	return success;
}