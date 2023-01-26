#include "rendering/kiwi_draw_basic.hpp"
#include "shader_sources/kiwi_sources_basic_2d.hpp"
#include "shader_sources/kiwi_sources_basic_3d.hpp"
#include "shader_sources/kiwi_sources_sprites.hpp"
#include <memory>


namespace kiwi
{
	class basic_2d_solid_color;
	class basic_2d_color_gradient;
	class basic_2d_texture;
	class basic_2d_texture_alpha_test;
	class basic_2d_no_shade;

	class basic_2d_solid_color_sprites;
	class basic_2d_texture_sprites;
	class basic_2d_texture_array_sprites;

	class basic_3d_solid_color;
	class basic_3d_bicolor_point_dist;
	class basic_3d_bicolor_point_dir;
	class basic_3d_bicolor_axis_dir;
	class basic_3d_color_gradient;
	class basic_3d_texture;
	class basic_3d_texture_alpha_test;
	class basic_3d_skybox;
	class basic_3d_no_shade;

	class basic_3d_solid_color_sprite;
	class basic_3d_solid_color_sprites;

	class basic_3d_texture_sprite;
	class basic_3d_texture_sprites;
	class basic_3d_texture_array_sprites;


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
		GLint RGBAx_location = -1;
		GLint RGBAo_location = -1;

		bool init() noexcept;
	};

	class basic_2d_texture
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint RGBAx_location = -1;
		GLint RGBAo_location = -1;

		bool init() noexcept;
	};

	class basic_2d_texture_alpha_test
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint RGBAx_location = -1;
		GLint RGBAo_location = -1;
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
		GLint XY_UV_size_location = -1;
		GLint alpha_discard_location = -1;

		bool init() noexcept;
	};

	class basic_2d_texture_array_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint XY_size_location = -1;
		GLint alpha_discard_location = -1;

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

	class basic_3d_bicolor_point_dist
	{

	public:

		kiwi::program program;
		GLint m_matrix_location = -1;
		GLint mvp_matrix_location = -1;
		GLint point_XYZ_location = -1;
		GLint near_RGBA_location = -1;
		GLint far_RGBA_location = -1;
		GLint near_far_dist_location = -1;

		bool init() noexcept;
	};

	class basic_3d_bicolor_point_dir
	{

	public:

		kiwi::program program;
		GLint m_matrix_location = -1;
		GLint mvp_matrix_location = -1;
		GLint point_XYZ_location = -1;
		GLint front_RGBA_location = -1;
		GLint side_RGBA_location = -1;

		bool init() noexcept;
	};

	class basic_3d_bicolor_axis_dir
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
		GLint RGBAx_location = -1;
		GLint RGBAo_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint RGBAx_location = -1;
		GLint RGBAo_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_alpha_test
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_location = -1;
		GLint RGBAx_location = -1;
		GLint RGBAo_location = -1;
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
		GLint XYZA_location = -1;
		GLint RGBA_location = -1;
		GLint depth_scaling_location = -1;

		bool init() noexcept;
	};

	class basic_3d_solid_color_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;
		GLint depth_scaling_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprite
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;
		GLint XYZA_location = -1;
		GLint depth_scaling_location = -1;
		GLint alpha_discard_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;
		GLint XY_UV_size_location = -1;
		GLint depth_scaling_location = -1;
		GLint alpha_discard_location = -1;

		bool init() noexcept;
	};

	class basic_3d_texture_array_sprites
	{

	public:

		kiwi::program program;
		GLint mvp_matrix_2d_location = -1;
		GLint mvp_matrix_3d_location = -1;
		GLint XY_size_location = -1;
		GLint depth_scaling_location = -1;
		GLint alpha_discard_location = -1;

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
		kiwi::basic_2d_texture_array_sprites m_program_texture_array_sprites_2d;

		kiwi::basic_3d_solid_color m_program_solid_color_3d;
		kiwi::basic_3d_bicolor_point_dist m_program_bicolor_point_dist_3d;
		kiwi::basic_3d_bicolor_point_dir m_program_bicolor_point_dir_3d;
		kiwi::basic_3d_color_gradient m_program_color_gradient_3d;
		kiwi::basic_3d_texture m_program_texture_3d;
		kiwi::basic_3d_texture_alpha_test m_program_texture_alpha_test_3d;
		kiwi::basic_3d_skybox m_program_skybox_3d;
		kiwi::basic_3d_no_shade m_program_no_shade_3d;

		kiwi::basic_3d_solid_color_sprite m_program_solid_color_sprite_3d;
		kiwi::basic_3d_solid_color_sprites m_program_solid_color_sprites_3d;

		kiwi::basic_3d_texture_sprite m_program_texture_sprite_3d;
		kiwi::basic_3d_texture_sprites m_program_texture_sprites_3d;
		kiwi::basic_3d_texture_array_sprites m_program_texture_array_sprites_split_3d;

		GLfloat RGBA1111[4] = { GL1, GL1, GL1, GL1 };
		GLfloat RGBA0000[4] = { GL0, GL0, GL0, GL0 };
	};

	std::unique_ptr<kiwi::default_buffers> default_buffers_ptr;
}

bool kiwi::draw_init()
{
	if (!kiwi::default_buffers_ptr)
	{
		bool success = true;

		try
		{
			kiwi::default_buffers_ptr = std::make_unique<kiwi::default_buffers>();

			if (!kiwi::default_buffers_ptr)
			{
				return false;
			}

			success &= default_buffers_ptr->m_program_solid_color_2d.init();
			success &= default_buffers_ptr->m_program_color_gradient_2d.init();
			success &= default_buffers_ptr->m_program_texture_2d.init();
			success &= default_buffers_ptr->m_program_texture_alpha_test_2d.init();
			success &= default_buffers_ptr->m_program_no_shade_2d.init();

			success &= default_buffers_ptr->m_program_solid_color_sprites_2d.init();
			success &= default_buffers_ptr->m_program_texture_sprites_2d.init();
			success &= default_buffers_ptr->m_program_texture_array_sprites_2d.init();

			success &= default_buffers_ptr->m_program_solid_color_3d.init();
			success &= default_buffers_ptr->m_program_color_gradient_3d.init();
			success &= default_buffers_ptr->m_program_bicolor_point_dist_3d.init();
			success &= default_buffers_ptr->m_program_bicolor_point_dir_3d.init();
			success &= default_buffers_ptr->m_program_texture_3d.init();
			success &= default_buffers_ptr->m_program_texture_alpha_test_3d.init();
			success &= default_buffers_ptr->m_program_skybox_3d.init();
			success &= default_buffers_ptr->m_program_no_shade_3d.init();

			success &= default_buffers_ptr->m_program_solid_color_sprite_3d.init();
			success &= default_buffers_ptr->m_program_solid_color_sprites_3d.init();

			success &= default_buffers_ptr->m_program_texture_sprite_3d.init();
			success &= default_buffers_ptr->m_program_texture_sprites_3d.init();
			success &= default_buffers_ptr->m_program_texture_array_sprites_split_3d.init();
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
	kiwi::default_buffers_ptr.reset();
}



// 2D SELECT PROGRAM

kiwi::_load_basic_2d_proxy kiwi::draw_2d_with(const GLfloat* const transformation_matrix_ptr) noexcept
{
	kiwi::_load_basic_2d_proxy proxy;
	proxy.m_transformation_matrix_ptr = transformation_matrix_ptr;
	return proxy;
}

// 3D SELECT PROGRAM

kiwi::_load_basic_3d_proxy kiwi::draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept
{
	kiwi::_load_basic_3d_proxy proxy;
	proxy.m_transformation_matrix_ptr = transformation_matrix_ptr;
	return proxy;
}

kiwi::_load_spec_3d_proxy kiwi::draw_3d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept
{
	kiwi::_load_spec_3d_proxy proxy;
	proxy.m_transformation_matrix_ptr = transformation_matrix_ptr;
	proxy.m_matrix_ptr = m_matrix_ptr;
	return proxy;
}

// 2D SELECT BUFFERS

kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::default_buffers_ptr->m_program_solid_color_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_solid_color_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_solid_color_2d.RGBA_location, solid_color.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept
{
	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_color_gradient_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.RGBAx_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA1111))
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
	const kiwi::RGBA& RGBAx) noexcept
{
	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_color_gradient_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
	const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept
{
	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_color_gradient_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_2d.RGBAo_location, RGBAo.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_2d.RGBAx_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA1111))
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_2d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
	const kiwi::RGBA& RGBAx) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_2d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_2d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
	const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_2d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_2d.RGBAo_location, RGBAo.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture, GLfloat alpha_test_value) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.alpha_test_location, alpha_test_value)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.RGBAx_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA1111))
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.alpha_test_location, alpha_test_value)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.RGBAo_location, RGBAo.data())
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_2d.alpha_test_location, alpha_test_value);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_2d_proxy::using_no_shade(const kiwi::vertex_buffer& vertex_buffer) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::default_buffers_ptr->m_program_no_shade_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_no_shade_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_2d_proxy::using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer,
	const kiwi::XYZA_set& XYZA_set, const kiwi::RGBA_set& RGBA_set) noexcept
{
	vertex_buffer.to_location(0);
	XYZA_set.to_binding(0);
	RGBA_set.to_binding(1);

	kiwi::default_buffers_ptr->m_program_solid_color_sprites_2d.program
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_solid_color_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr);

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZA_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_quad_sprite_proxy kiwi::_load_basic_2d_proxy::using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::UV_set& UV_set, const kiwi::XY& XY_size,
	GLfloat alpha_discard) noexcept
{
	XYZA_set.to_binding(0);
	UV_set.to_binding(1, 0);

	GLfloat arr[4] = { XY_size[0], XY_size[1], UV_set.get_U_size(), UV_set.get_V_size() };

	kiwi::default_buffers_ptr->m_program_texture_sprites_2d.program
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_sprites_2d.XY_UV_size_location, static_cast<GLfloat*>(arr))
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_sprites_2d.alpha_discard_location, alpha_discard);

	kiwi::_draw_quad_sprite_proxy proxy;
	proxy.m_sprite_count = XYZA_set.instance_count();
	return proxy;
}

kiwi::_draw_quad_sprite_proxy kiwi::_load_basic_2d_proxy::using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::id_set& id_set, const kiwi::XY& XY_size,
	GLfloat alpha_discard) noexcept
{
	XYZA_set.to_binding(0);
	id_set.to_binding(1, 0);

	GLfloat arr[2] = { XY_size[0], XY_size[1] };

	kiwi::default_buffers_ptr->m_program_texture_array_sprites_2d.program
		.set_uniform_2f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_2d.XY_size_location, static_cast<GLfloat*>(arr))
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_2d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_2d.alpha_discard_location, alpha_discard);

	kiwi::_draw_quad_sprite_proxy proxy;
	proxy.m_sprite_count = XYZA_set.instance_count();
	return proxy;
}


// 3D SELECT BUFFERS

kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::default_buffers_ptr->m_program_solid_color_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_solid_color_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_solid_color_3d.RGBA_location, solid_color.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept
{
	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_color_gradient_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.RGBAx_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA1111))
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
	const kiwi::RGBA& RGBAx) noexcept
{
	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_color_gradient_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
	const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept
{
	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_color_gradient_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_color_gradient_3d.RGBAo_location, RGBAo.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_3d.RGBAx_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA1111))
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_3d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer, const kiwi::RGBA& RGBAx) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_3d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_3d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_3d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_3d.RGBAo_location, RGBAo.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer, GLfloat alpha_test_value) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.alpha_test_location, alpha_test_value)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.RGBAx_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA1111))
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.alpha_test_location, alpha_test_value)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.RGBAo_location, static_cast<const GLfloat*>(kiwi::default_buffers_ptr->RGBA0000));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.mvp_matrix_location, m_transformation_matrix_ptr)	
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.RGBAx_location, RGBAx.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.RGBAo_location, RGBAo.data())
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_alpha_test_3d.alpha_test_location, alpha_test_value);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

void kiwi::_load_basic_3d_proxy::using_skybox(const kiwi::cubemap& skybox_buffer) noexcept
{
	skybox_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_skybox_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_skybox_3d.mvp_matrix_location, m_transformation_matrix_ptr);

	glDrawArrays(GL_QUADS, 0, 24);
}
kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_no_shade(const kiwi::vertex_buffer& vertex_buffer, GLfloat depth_offset) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::default_buffers_ptr->m_program_no_shade_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_no_shade_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_no_shade_3d.depth_offset_location, depth_offset);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_solid_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const GLfloat* const XYZA_ptr, const kiwi::RGBA& solid_color,
	bool depth_scaling, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	vertex_buffer.to_location(0);

	kiwi::default_buffers_ptr->m_program_solid_color_sprite_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_solid_color_sprite_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr)
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_solid_color_sprite_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_solid_color_sprite_3d.XYZA_location, XYZA_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_solid_color_sprite_3d.RGBA_location, solid_color.data())
		.set_uniform_1ui(kiwi::default_buffers_ptr->m_program_solid_color_sprite_3d.depth_scaling_location, static_cast<GLuint>(depth_scaling));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_instanced_basic_proxy kiwi::_load_basic_3d_proxy::using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZA_set& XYZA_set, const kiwi::RGBA_set& RGBA_set,
	bool depth_scaling, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	vertex_buffer.to_location(0);
	XYZA_set.to_binding(0);
	RGBA_set.to_binding(1);

	kiwi::default_buffers_ptr->m_program_solid_color_sprites_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_solid_color_sprites_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr)
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_solid_color_sprites_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr)
		.set_uniform_1ui(kiwi::default_buffers_ptr->m_program_solid_color_sprites_3d.depth_scaling_location, static_cast<GLuint>(depth_scaling));

	kiwi::_draw_instanced_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_instance_count = XYZA_set.instance_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}

kiwi::_draw_basic_proxy kiwi::_load_basic_3d_proxy::using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_2d& texture_buffer, const GLfloat* const XYZA_ptr,
	GLfloat alpha_discard, bool depth_scaling, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	vertex_buffer.to_location(0);
	UV_buffer.to_location(1);
	texture_buffer.to_binding(0);

	kiwi::default_buffers_ptr->m_program_texture_sprite_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_sprite_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr)
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_sprite_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_sprite_3d.XYZA_location, XYZA_ptr)
		.set_uniform_1ui(kiwi::default_buffers_ptr->m_program_texture_sprite_3d.depth_scaling_location, static_cast<GLuint>(depth_scaling))
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_sprite_3d.alpha_discard_location, alpha_discard);

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_quad_sprite_proxy kiwi::_load_basic_3d_proxy::using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::UV_set& UV_set, const kiwi::XY& XY_size,
	GLfloat alpha_discard, bool depth_scaling, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	XYZA_set.to_binding(0);
	UV_set.to_binding(1, 0);

	GLfloat arr[4] = { XY_size[0], XY_size[1], UV_set.get_U_size(), UV_set.get_V_size() };

	kiwi::default_buffers_ptr->m_program_texture_sprites_3d.program
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_texture_sprites_3d.XY_UV_size_location, static_cast<GLfloat*>(arr))
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_sprites_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr)
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_sprites_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr)
		.set_uniform_1ui(kiwi::default_buffers_ptr->m_program_texture_sprites_3d.depth_scaling_location, static_cast<GLuint>(depth_scaling))
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_sprites_3d.alpha_discard_location, alpha_discard);

	kiwi::_draw_quad_sprite_proxy proxy;
	proxy.m_sprite_count = XYZA_set.instance_count();
	return proxy;
}
kiwi::_draw_quad_sprite_proxy kiwi::_load_basic_3d_proxy::using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::id_set& id_set, const kiwi::XY& XY_size,
	GLfloat alpha_discard, bool depth_scaling, const GLfloat* const mvp_matrix_2d_ptr) noexcept
{
	XYZA_set.to_binding(0);
	id_set.to_binding(1, 0);

	GLfloat arr[2] = { XY_size[0], XY_size[1] };

	kiwi::default_buffers_ptr->m_program_texture_array_sprites_split_3d.program
		.set_uniform_2f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_split_3d.XY_size_location, static_cast<GLfloat*>(arr))
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_split_3d.mvp_matrix_3d_location, m_transformation_matrix_ptr)
		.set_uniform_3x3f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_split_3d.mvp_matrix_2d_location, mvp_matrix_2d_ptr)
		.set_uniform_1ui(kiwi::default_buffers_ptr->m_program_texture_array_sprites_split_3d.depth_scaling_location, static_cast<GLuint>(depth_scaling))
		.set_uniform_1f(kiwi::default_buffers_ptr->m_program_texture_array_sprites_split_3d.alpha_discard_location, alpha_discard);

	kiwi::_draw_quad_sprite_proxy proxy;
	proxy.m_sprite_count = XYZA_set.instance_count();
	return proxy;
}


kiwi::_draw_basic_proxy kiwi::_load_spec_3d_proxy::using_dualcolor_point_dist(const kiwi::vertex_buffer& vertex_buffer, const GLfloat* const point_ptr, const kiwi::RGBA& color_near,
	const kiwi::RGBA& color_far, GLfloat near_dist, GLfloat far_dist) noexcept
{
	vertex_buffer.to_location(0);

	GLfloat near_far_dist[2] = { near_dist, far_dist };

	kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.m_matrix_location, m_matrix_ptr)
		.set_uniform_3f(kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.point_XYZ_location, point_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.near_RGBA_location, color_near.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.far_RGBA_location, color_far.data())
		.set_uniform_2f(kiwi::default_buffers_ptr->m_program_bicolor_point_dist_3d.near_far_dist_location, static_cast<GLfloat*>(near_far_dist));

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
}
kiwi::_draw_basic_proxy kiwi::_load_spec_3d_proxy::using_bicolor_point_dir(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const GLfloat* const point_ptr, const kiwi::RGBA& color_front, const kiwi::RGBA& color_side) noexcept
{
	vertex_buffer.to_location(0);
	N_buffer.to_location(1);

	kiwi::default_buffers_ptr->m_program_bicolor_point_dir_3d.program
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dir_3d.mvp_matrix_location, m_transformation_matrix_ptr)
		.set_uniform_4x4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dir_3d.m_matrix_location, m_matrix_ptr)
		.set_uniform_3f(kiwi::default_buffers_ptr->m_program_bicolor_point_dir_3d.point_XYZ_location, point_ptr)
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dir_3d.front_RGBA_location, color_front.data())
		.set_uniform_4f(kiwi::default_buffers_ptr->m_program_bicolor_point_dir_3d.side_RGBA_location, color_side.data());

	kiwi::_draw_basic_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	proxy.m_index_count = -1;
	proxy.m_index_data_ptr = nullptr;
	return proxy;
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


void kiwi::_draw_quad_sprite_proxy::quad_sprites() noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(4 * m_sprite_count));
}
void kiwi::_draw_quad_sprite_proxy::quad_sprites(std::size_t sprite_count) noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(4 * sprite_count));
}
void kiwi::_draw_quad_sprite_proxy::quad_sprites(std::size_t sprite_begin, std::size_t sprite_count) noexcept
{
	glDrawArrays(GL_QUADS, static_cast<GLint>(4 * sprite_begin), static_cast<GLsizei>(4 * sprite_count));
}


// DRAW CALL FREE FUNCTIONS

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
		RGBAx_location = program.new_uniform_location("u_RGBAx");
		RGBAo_location = program.new_uniform_location("u_RGBAo");
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
		RGBAx_location = program.new_uniform_location("u_RGBAx");
		RGBAo_location = program.new_uniform_location("u_RGBAo");
		program.set_uniform_1i("Tx", static_cast<GLint>(0));
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
		RGBAx_location = program.new_uniform_location("u_RGBAx");
		RGBAo_location = program.new_uniform_location("u_RGBAo");
		alpha_test_location = program.new_uniform_location("u_alpha_test");
		program.set_uniform_1i("Tx", static_cast<GLint>(0));
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
		kiwi::source::solid_color_sprites_2d::vertex_shader(),
		kiwi::source::solid_color_sprites_2d::fragment_shader()
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
		kiwi::source::texture_sprites_2d::vertex_shader(),
		kiwi::source::texture_sprites_2d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		XY_UV_size_location = program.new_uniform_location("u_XY_UV_size");
		alpha_discard_location = program.new_uniform_location("u_alpha_discard");
	}

	return success;
}

bool kiwi::basic_2d_texture_array_sprites::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::texture_array_sprites_2d::vertex_shader(),
		kiwi::source::texture_array_sprites_2d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		XY_size_location = program.new_uniform_location("u_XY_size");
		alpha_discard_location = program.new_uniform_location("u_alpha_discard");
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

bool kiwi::basic_3d_bicolor_point_dist::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_bicolor_point_dist::vertex_shader(),
		kiwi::source::basic_3d_bicolor_point_dist::fragment_shader()
	);

	if (success)
	{
		m_matrix_location = program.new_uniform_location("u_m_M");
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		point_XYZ_location = program.new_uniform_location("u_point_XYZ");
		near_RGBA_location = program.new_uniform_location("u_near_RGBA");
		far_RGBA_location = program.new_uniform_location("u_far_RGBA");
		near_far_dist_location = program.new_uniform_location("u_near_far_dist");
	}

	return success;
}

bool kiwi::basic_3d_bicolor_point_dir::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::basic_3d_bicolor_point_dir::vertex_shader(),
		kiwi::source::basic_3d_bicolor_point_dir::fragment_shader()
	);

	if (success)
	{
		m_matrix_location = program.new_uniform_location("u_m_M");
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		point_XYZ_location = program.new_uniform_location("u_point_XYZ");
		front_RGBA_location = program.new_uniform_location("u_front_RGBA");
		side_RGBA_location = program.new_uniform_location("u_side_RGBA");
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
		RGBAx_location = program.new_uniform_location("u_RGBAx");
		RGBAo_location = program.new_uniform_location("u_RGBAo");
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
		RGBAx_location = program.new_uniform_location("u_RGBAx");
		RGBAo_location = program.new_uniform_location("u_RGBAo");
		program.set_uniform_1i("Tx", static_cast<GLint>(0));
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
		RGBAx_location = program.new_uniform_location("u_RGBAx");
		RGBAo_location = program.new_uniform_location("u_RGBAo");
		alpha_test_location = program.new_uniform_location("u_alpha_test");
		program.set_uniform_1i("Tx", static_cast<GLint>(0));
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
		kiwi::source::solid_color_sprite_3d::vertex_shader(),
		kiwi::source::solid_color_sprite_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		XYZA_location = program.new_uniform_location("u_XYZA");
		RGBA_location = program.new_uniform_location("u_RGBA");
		depth_scaling_location = program.new_uniform_location("u_depth_scaling");
	}

	return success;
}

bool kiwi::basic_3d_solid_color_sprites::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::solid_color_sprites_3d::vertex_shader(),
		kiwi::source::solid_color_sprites_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		depth_scaling_location = program.new_uniform_location("u_depth_scaling");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprite::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::texture_sprite_3d::vertex_shader(),
		kiwi::source::texture_sprite_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		XYZA_location = program.new_uniform_location("u_XYZA");
		depth_scaling_location = program.new_uniform_location("u_depth_scaling");
		alpha_discard_location = program.new_uniform_location("u_alpha_discard");
	}

	return success;
}

bool kiwi::basic_3d_texture_sprites::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::texture_sprites_3d::vertex_shader(),
		kiwi::source::texture_sprites_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		XY_UV_size_location = program.new_uniform_location("u_XY_UV_size");
		depth_scaling_location = program.new_uniform_location("u_depth_scaling");
		alpha_discard_location = program.new_uniform_location("u_alpha_discard");
	}

	return success;
}

bool kiwi::basic_3d_texture_array_sprites::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::texture_array_sprites_3d::vertex_shader(),
		kiwi::source::texture_array_sprites_3d::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_2d_location = program.new_uniform_location("u_mvp_M_2d");
		mvp_matrix_3d_location = program.new_uniform_location("u_mvp_M_3d");
		XY_size_location = program.new_uniform_location("u_XY_size");
		depth_scaling_location = program.new_uniform_location("u_depth_scaling");
		alpha_discard_location = program.new_uniform_location("u_alpha_discard");
	}

	return success;
}