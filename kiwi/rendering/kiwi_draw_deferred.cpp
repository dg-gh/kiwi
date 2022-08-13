#include "rendering/kiwi_draw_deferred.hpp"
#include "shader_sources/kiwi_sources_deferred_2d.hpp"
#include "shader_sources/kiwi_sources_deferred_3d.hpp"

namespace kiwi
{
	class deferred_2d_solid_color;
	class deferred_2d_color_gradient;
	class deferred_2d_texture;
	class deferred_2d_normal;

	class deferred_3d_solid_color;
	class deferred_3d_color_gradient;
	class deferred_3d_texture;
	class deferred_3d_normal;
	class deferred_3d_parallax;


	class deferred_2d_solid_color
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;

		GLint RMEC_location = -1;

		GLint RGB_location = -1;
	};

	class deferred_2d_color_gradient
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;

		GLint C_location = -1;
	};

	class deferred_2d_texture
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;

		GLint C_location = -1;
	};

	class deferred_2d_normal
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;

		GLint C_location = -1;
	};




	class deferred_3d_solid_color
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;

		GLint RMEC_location = -1;

		GLint RGB_location = -1;
	};

	class deferred_3d_color_gradient
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;

		GLint C_location = -1;
	};

	class deferred_3d_texture
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;

		GLint C_location = -1;
	};

	class deferred_3d_normal
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;

		GLint C_location = -1;
	};

	class deferred_3d_parallax
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;

		GLint C_location = -1;
		GLint parallax_shift_location = -1;
	};
}


namespace kiwi
{
	class deferred_buffers
	{

	public:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		deferred_buffers() = default;
		deferred_buffers(const kiwi::deferred_buffers&) = delete;
		kiwi::deferred_buffers& operator=(const kiwi::deferred_buffers&) = delete;
		deferred_buffers(kiwi::deferred_buffers&&) = delete;
		kiwi::deferred_buffers& operator=(kiwi::deferred_buffers&&) = delete;
		~deferred_buffers() = default;

		kiwi::deferred_2d_solid_color m_program_solid_color_2d;
		kiwi::deferred_2d_color_gradient m_program_color_gradient_2d;
		kiwi::deferred_2d_texture m_program_texture_2d;
		kiwi::deferred_2d_normal m_program_normal_mRMEC_2d;

		kiwi::deferred_3d_solid_color m_program_solid_color_3d;
		kiwi::deferred_3d_color_gradient m_program_color_gradient_3d;
		kiwi::deferred_3d_texture m_program_texture_3d;
		kiwi::deferred_3d_normal m_program_normal_3d;
		kiwi::deferred_3d_parallax m_program_parallax_3d;

		GLfloat m_identity_matrix_3d[16] = {
			GL1, GL0, GL0, GL0,
			GL0, GL1, GL0, GL0,
			GL0, GL0, GL1, GL0,
			GL0, GL0, GL0, GL1
		};
		GLfloat m_identity_matrix_2d[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};

		kiwi::vertex_buffer m_lightmap_black_vertex;
		kiwi::texture_buffer m_lightmap_black;

		void init_black_lightmap();
	};
}

void kiwi::deferred_buffers::init_black_lightmap()
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	{
		GLfloat lightmap_black_vertex[4 * 2] = { GL0, GL0, GL1, GL0, GL1, GL1, GL0, GL1 };
		m_lightmap_black_vertex.load(static_cast<GLfloat*>(lightmap_black_vertex), 4, 2);
	}

	unsigned char lightmap_black[4 * 4 * 3] = { 0 };
	m_lightmap_black.load(static_cast<unsigned char*>(lightmap_black), kiwi::size(4, 4), 3, kiwi::texture_mapping::nearest, kiwi::texture_borders::clamp);
}

bool kiwi::draw_deferred_init()
{
	if (!kiwi::is_global_type_created<kiwi::deferred_buffers>())
	{
		bool success = true;

		try
		{
			kiwi::make_global_type<kiwi::deferred_buffers>();

			if (!kiwi::is_global_type_created<kiwi::deferred_buffers>())
			{
				return false;
			}

			kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

			success &= buffers.m_program_solid_color_2d.init();
			success &= buffers.m_program_color_gradient_2d.init();
			success &= buffers.m_program_texture_2d.init();
			success &= buffers.m_program_normal_mRMEC_2d.init();

			success &= buffers.m_program_solid_color_3d.init();
			success &= buffers.m_program_color_gradient_3d.init();
			success &= buffers.m_program_texture_3d.init();
			success &= buffers.m_program_normal_3d.init();
			success &= buffers.m_program_parallax_3d.init();

			buffers.init_black_lightmap();
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
void kiwi::draw_deferred_terminate() noexcept
{
	kiwi::delete_global_type<kiwi::deferred_buffers>();
}


kiwi::_load_deferred_2d_proxy kiwi::draw_deferred_2d_with(const GLfloat* const mvp_matrix_ptr) noexcept
{
	kiwi::_load_deferred_2d_proxy proxy;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = static_cast<const GLfloat*>(kiwi::get_global_type<kiwi::deferred_buffers>().m_identity_matrix_2d);
	return proxy;
}

kiwi::_load_deferred_2d_proxy kiwi::draw_deferred_2d_with(const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept
{
	kiwi::_load_deferred_2d_proxy proxy;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = m_matrix_ptr;
	return proxy;
}

kiwi::_load_deferred_3d_proxy kiwi::draw_deferred_3d_with(const GLfloat* const mvp_matrix_ptr) noexcept
{
	kiwi::_load_deferred_3d_proxy proxy;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = static_cast<const GLfloat*>(kiwi::get_global_type<kiwi::deferred_buffers>().m_identity_matrix_3d);
	return proxy;
}

kiwi::_load_deferred_3d_proxy kiwi::draw_deferred_3d_with(const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept
{
	kiwi::_load_deferred_3d_proxy proxy;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = m_matrix_ptr;
	return proxy;
}


// 2D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer,
	const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);

	buffers.m_program_solid_color_2d.program.set_uniform_3x3f(buffers.m_program_solid_color_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3f(buffers.m_program_solid_color_2d.RGB_location, solid_color.data())
		.set_uniform_4f(buffers.m_program_solid_color_2d.RMEC_location, RMEC.data());

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	buffers.m_program_color_gradient_2d.program.set_uniform_3x3f(buffers.m_program_color_gradient_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_1f(buffers.m_program_color_gradient_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	buffers.m_program_color_gradient_2d.program.set_uniform_3x3f(buffers.m_program_color_gradient_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_1f(buffers.m_program_color_gradient_2d.C_location, static_cast<GLfloat>(color_ceiling));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// TEXTURE 2D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(color_ceiling));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(color_ceiling));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// NORMAL 2D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::texture_buffer& RMEC_texture_buffer) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_normal_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_normal_mRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
	const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(color_ceiling));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::texture_buffer& RMEC_texture_buffer,
	GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_2d.program.set_uniform_3x3f(buffers.m_program_texture_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_2d.C_location, static_cast<GLfloat>(color_ceiling));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}



// 3D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);

	buffers.m_program_solid_color_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_solid_color_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_4f(buffers.m_program_solid_color_3d.RMEC_location, RMEC.data())
		.set_uniform_3f(buffers.m_program_solid_color_3d.RGB_location, solid_color.data());

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	buffers.m_program_color_gradient_3d.program.set_uniform_4x4f(buffers.m_program_color_gradient_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_color_gradient_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_color_gradient_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	buffers.m_program_color_gradient_3d.program.set_uniform_4x4f(buffers.m_program_color_gradient_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_color_gradient_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_color_gradient_3d.C_location, color_ceiling);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// TEXTURE 3D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_3d.program.set_uniform_4x4f(buffers.m_program_texture_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_3d.program.set_uniform_4x4f(buffers.m_program_texture_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_3d.C_location, color_ceiling);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_3d.program.set_uniform_4x4f(buffers.m_program_texture_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_texture_3d.program.set_uniform_4x4f(buffers.m_program_texture_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_texture_3d.C_location, color_ceiling);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// NORMAL 3D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_normal_3d.program.set_uniform_4x4f(buffers.m_program_normal_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_normal_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_normal_3d.program.set_uniform_4x4f(buffers.m_program_normal_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_normal_3d.C_location, color_ceiling);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_normal_3d.program.set_uniform_4x4f(buffers.m_program_normal_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_normal_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_normal_3d.program.set_uniform_4x4f(buffers.m_program_normal_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_1f(buffers.m_program_normal_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// PARALLAX 3D

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_parallax_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_parallax_3d.program.set_uniform_4x4f(buffers.m_program_parallax_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_3d.view_XYZ_location, view_XYZ_ptr)
		.set_uniform_1f(buffers.m_program_parallax_3d.C_location, static_cast<GLfloat>(1))
		.set_uniform_1f(buffers.m_program_parallax_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_parallax_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_parallax_3d.program.set_uniform_4x4f(buffers.m_program_parallax_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_3d.view_XYZ_location, view_XYZ_ptr)
		.set_uniform_1f(buffers.m_program_parallax_3d.C_location, color_ceiling)
		.set_uniform_1f(buffers.m_program_parallax_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_parallax_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_parallax_3d.program.set_uniform_4x4f(buffers.m_program_parallax_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_3d.view_XYZ_location, view_XYZ_ptr)
		.set_uniform_1f(buffers.m_program_parallax_3d.C_location, static_cast<GLfloat>(1))
		.set_uniform_1f(buffers.m_program_parallax_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_deferred_proxy kiwi::_load_deferred_3d_proxy::using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::deferred_buffers> buffers = kiwi::get_global_type<kiwi::deferred_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_parallax_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	buffers.m_program_parallax_3d.program.set_uniform_4x4f(buffers.m_program_parallax_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_3d.view_XYZ_location, view_XYZ_ptr)
		.set_uniform_1f(buffers.m_program_parallax_3d.C_location, color_ceiling)
		.set_uniform_1f(buffers.m_program_parallax_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_deferred_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}



void kiwi::_draw_deferred_proxy::triangles() noexcept
{
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count));
}
void kiwi::_draw_deferred_proxy::quads() noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count));
}
void kiwi::_draw_deferred_proxy::triangles(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::_draw_deferred_proxy::quads(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::_draw_deferred_proxy::triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::_draw_deferred_proxy::quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, static_cast<GLsizei>(begin_vertex), static_cast<GLsizei>(vertex_count));
}



bool kiwi::deferred_2d_solid_color::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_2d_solid_color::vertex_shader(),
		kiwi::source::deferred_2d_solid_color::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");

		RMEC_location = program.new_uniform_location("u_RMEC");
		RGB_location = program.new_uniform_location("u_RGB");
	}

	return success;
}

bool kiwi::deferred_2d_color_gradient::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_2d_color_gradient::vertex_shader(),
		kiwi::source::deferred_2d_color_gradient::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::deferred_2d_texture::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_2d_texture::vertex_shader(),
		kiwi::source::deferred_2d_texture::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::deferred_2d_normal::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_2d_normal::vertex_shader(),
		kiwi::source::deferred_2d_normal::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}


bool kiwi::deferred_3d_solid_color::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_3d_solid_color::vertex_shader(),
		kiwi::source::deferred_3d_solid_color::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");

		RMEC_location = program.new_uniform_location("u_RMEC");
		RGB_location = program.new_uniform_location("u_RGB");
	}

	return success;
}

bool kiwi::deferred_3d_color_gradient::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_3d_color_gradient_vRMEC::vertex_shader(),
		kiwi::source::deferred_3d_color_gradient_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::deferred_3d_texture::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_3d_texture_mRMEC::vertex_shader(),
		kiwi::source::deferred_3d_texture_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::deferred_3d_normal::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_3d_normal::vertex_shader(),
		kiwi::source::deferred_3d_normal::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::deferred_3d_parallax::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::deferred_3d_parallax_mRMEC::vertex_shader(),
		kiwi::source::deferred_3d_parallax_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		m_matrix_location = program.new_uniform_location("u_m_M");

		C_location = program.new_uniform_location("u_C");
		parallax_shift_location = program.new_uniform_location("u_shift_factor");
	}

	return success;
}