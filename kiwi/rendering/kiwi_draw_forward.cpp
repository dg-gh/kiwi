#include "rendering/kiwi_draw_forward.hpp"
#include "shader_sources/kiwi_sources_forward_2d.hpp"
#include "shader_sources/kiwi_sources_forward_3d.hpp"

namespace kiwi
{
	class forward_2d_solid_color;
	class forward_2d_color_gradient_sRMEC;
	class forward_2d_color_gradient_vRMEC;
	class forward_2d_texture_sRMEC;
	class forward_2d_texture_vRMEC;
	class forward_2d_texture_mRMEC;
	class forward_2d_normal_sRMEC;

	class forward_3d_solid_color;
	class forward_3d_color_gradient_sRMEC;
	class forward_3d_color_gradient_vRMEC;
	class forward_3d_texture_sRMEC;
	class forward_3d_texture_vRMEC;
	class forward_3d_texture_mRMEC;
	class forward_3d_normal_sRMEC;
	class forward_3d_normal_vRMEC;
	class forward_3d_normal_mRMEC;
	class forward_3d_parallax_sRMEC;
	class forward_3d_parallax_vRMEC;
	class forward_3d_parallax_mRMEC;


	class forward_2d_solid_color
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;

		GLint RGBA_location = -1;
	};

	class forward_2d_color_gradient_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
	};

	class forward_2d_color_gradient_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_2d_texture_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
	};

	class forward_2d_texture_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_2d_texture_mRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_2d_normal_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
	};

	class forward_2d_normal_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_2d_normal_mRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};


	class forward_3d_solid_color
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
		GLint RGBA_location = -1;
	};

	class forward_3d_color_gradient_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
	};

	class forward_3d_color_gradient_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_3d_texture_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
	};

	class forward_3d_texture_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_3d_texture_mRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_3d_normal_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
	};

	class forward_3d_normal_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_3d_normal_mRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
	};

	class forward_3d_parallax_sRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint RMEC_location = -1;
		GLint parallax_shift_location = -1;
	};

	class forward_3d_parallax_vRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
		GLint parallax_shift_location = -1;
	};

	class forward_3d_parallax_mRMEC
	{

	public:

		bool init() noexcept;

		kiwi::program program;

		GLint mvp_matrix_location = -1;
		GLint m_matrix_location = -1;
		GLint view_XYZ_location = -1;
		GLint ambient_light_RGB_location = -1;
		GLint light_count_location = -1;

		GLint C_location = -1;
		GLint parallax_shift_location = -1;
	};
}


namespace kiwi
{
	class forward_buffers
	{

	public:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		forward_buffers() = default;
		forward_buffers(const kiwi::forward_buffers&) = delete;
		kiwi::forward_buffers& operator=(const kiwi::forward_buffers&) = delete;
		forward_buffers(kiwi::forward_buffers&&) = delete;
		kiwi::forward_buffers& operator=(kiwi::forward_buffers&&) = delete;
		~forward_buffers() = default;

		kiwi::forward_2d_solid_color m_program_solid_color_2d;

		kiwi::forward_2d_color_gradient_sRMEC m_program_color_gradient_sRMEC_2d;
		kiwi::forward_2d_color_gradient_vRMEC m_program_color_gradient_vRMEC_2d;

		kiwi::forward_2d_texture_sRMEC m_program_texture_sRMEC_2d;
		kiwi::forward_2d_texture_vRMEC m_program_texture_vRMEC_2d;
		kiwi::forward_2d_texture_mRMEC m_program_texture_mRMEC_2d;

		kiwi::forward_2d_normal_sRMEC m_program_normal_sRMEC_2d;
		kiwi::forward_2d_normal_vRMEC m_program_normal_vRMEC_2d;
		kiwi::forward_2d_normal_mRMEC m_program_normal_mRMEC_2d;


		kiwi::forward_3d_solid_color m_program_solid_color_3d;

		kiwi::forward_3d_color_gradient_sRMEC m_program_color_gradient_sRMEC_3d;
		kiwi::forward_3d_color_gradient_vRMEC m_program_color_gradient_vRMEC_3d;

		kiwi::forward_3d_texture_sRMEC m_program_texture_sRMEC_3d;
		kiwi::forward_3d_texture_vRMEC m_program_texture_vRMEC_3d;
		kiwi::forward_3d_texture_mRMEC m_program_texture_mRMEC_3d;

		kiwi::forward_3d_normal_sRMEC m_program_normal_sRMEC_3d;
		kiwi::forward_3d_normal_vRMEC m_program_normal_vRMEC_3d;
		kiwi::forward_3d_normal_mRMEC m_program_normal_mRMEC_3d;

		kiwi::forward_3d_parallax_sRMEC m_program_parallax_sRMEC_3d;
		kiwi::forward_3d_parallax_vRMEC m_program_parallax_vRMEC_3d;
		kiwi::forward_3d_parallax_mRMEC m_program_parallax_mRMEC_3d;

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

void kiwi::forward_buffers::init_black_lightmap()
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

bool kiwi::draw_forward_init()
{
	if (!kiwi::is_global_type_created<kiwi::forward_buffers>())
	{
		bool success = true;

		try
		{
			kiwi::make_global_type<kiwi::forward_buffers>();

			if (!kiwi::is_global_type_created<kiwi::forward_buffers>())
			{
				return false;
			}

			kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

			success &= buffers.m_program_solid_color_2d.init();

			success &= buffers.m_program_color_gradient_sRMEC_2d.init();
			success &= buffers.m_program_color_gradient_vRMEC_2d.init();

			success &= buffers.m_program_texture_sRMEC_2d.init();
			success &= buffers.m_program_texture_vRMEC_2d.init();
			success &= buffers.m_program_texture_mRMEC_2d.init();

			success &= buffers.m_program_normal_sRMEC_2d.init();
			success &= buffers.m_program_normal_vRMEC_2d.init();
			success &= buffers.m_program_normal_mRMEC_2d.init();


			success &= buffers.m_program_solid_color_3d.init();

			success &= buffers.m_program_color_gradient_sRMEC_3d.init();
			success &= buffers.m_program_color_gradient_vRMEC_3d.init();

			success &= buffers.m_program_texture_sRMEC_3d.init();
			success &= buffers.m_program_texture_vRMEC_3d.init();
			success &= buffers.m_program_texture_mRMEC_3d.init();

			success &= buffers.m_program_normal_sRMEC_3d.init();
			success &= buffers.m_program_normal_vRMEC_3d.init();
			success &= buffers.m_program_normal_mRMEC_3d.init();

			success &= buffers.m_program_parallax_sRMEC_3d.init();
			success &= buffers.m_program_parallax_vRMEC_3d.init();
			success &= buffers.m_program_parallax_mRMEC_3d.init();


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
void kiwi::draw_forward_terminate() noexcept
{
	kiwi::delete_global_type<kiwi::forward_buffers>();
}


kiwi::_load_forward_2d_proxy kiwi::draw_forward_2d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XY_ptr, GLfloat view_Z,
	const GLfloat* const mvp_matrix_ptr) noexcept
{
	kiwi::_load_forward_2d_proxy proxy;
	proxy.m_lightset_ptr = &lights;
	proxy.m_light_selection_ptr = &selection;
	proxy.m_view_XYZ[0] = view_XY_ptr[0];
	proxy.m_view_XYZ[1] = view_XY_ptr[1];
	proxy.m_view_XYZ[2] = view_Z;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = static_cast<const GLfloat*>(kiwi::get_global_type<kiwi::forward_buffers>().m_identity_matrix_2d);
	return proxy;
}

kiwi::_load_forward_2d_proxy kiwi::draw_forward_2d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XY_ptr, GLfloat view_Z,
	const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept
{
	kiwi::_load_forward_2d_proxy proxy;
	proxy.m_lightset_ptr = &lights;
	proxy.m_light_selection_ptr = &selection;
	proxy.m_view_XYZ[0] = view_XY_ptr[0];
	proxy.m_view_XYZ[1] = view_XY_ptr[1];
	proxy.m_view_XYZ[2] = view_Z;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = m_matrix_ptr;
	return proxy;
}

kiwi::_load_forward_3d_proxy kiwi::draw_forward_3d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XYZ_ptr,
	const GLfloat* const mvp_matrix_ptr) noexcept
{
	kiwi::_load_forward_3d_proxy proxy;
	proxy.m_lightset_ptr = &lights;
	proxy.m_light_selection_ptr = &selection;
	proxy.m_view_XYZ_ptr = view_XYZ_ptr;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = static_cast<const GLfloat*>(kiwi::get_global_type<kiwi::forward_buffers>().m_identity_matrix_3d);
	return proxy;
}

kiwi::_load_forward_3d_proxy kiwi::draw_forward_3d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XYZ_ptr,
	const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept
{
	kiwi::_load_forward_3d_proxy proxy;
	proxy.m_lightset_ptr = &lights;
	proxy.m_light_selection_ptr = &selection;
	proxy.m_view_XYZ_ptr = view_XYZ_ptr;
	proxy.m_mvp_matrix_ptr = mvp_matrix_ptr;
	proxy.m_m_matrix_ptr = m_matrix_ptr;
	return proxy;
}


// 2D

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_solid_color_2d.program.set_uniform_3x3f(buffers.m_program_solid_color_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_solid_color_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_solid_color_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_solid_color_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_solid_color_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_solid_color_2d.RMEC_location, RMEC.data())
		.set_uniform_4f(buffers.m_program_solid_color_2d.RGBA_location, solid_color.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(6);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_color_gradient_sRMEC_2d.program.set_uniform_3x3f(buffers.m_program_color_gradient_sRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_color_gradient_sRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_sRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_color_gradient_sRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_color_gradient_sRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_color_gradient_sRMEC_2d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
	const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_color_gradient_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_color_gradient_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_color_gradient_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_color_gradient_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_color_gradient_vRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
	const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_color_gradient_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_color_gradient_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_color_gradient_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_color_gradient_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_color_gradient_vRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// TEXTURE 2D

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_sRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_sRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_sRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_sRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_sRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_sRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_texture_sRMEC_2d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
	const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC, const kiwi::vertex_buffer& UV_lightmap_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	UV_lightmap_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_sRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_sRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_sRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_sRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_sRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_sRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_texture_sRMEC_2d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::texture_buffer& RMEC_texture_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::texture_buffer& RMEC_texture_buffer, const kiwi::texture_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
	const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_texture_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_texture_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// NORMAL 2D

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_sRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_sRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_sRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_sRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_sRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_sRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_normal_sRMEC_2d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::RMEC& RMEC,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	normal_map.to_binding(1);
	lightmap.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_sRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_sRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_sRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_sRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_sRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_sRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_normal_sRMEC_2d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
	const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
	const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_vRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_vRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
	const kiwi::texture_buffer& RMEC_texture_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
	const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_2d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_2d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::texture_buffer& RMEC_texture_buffer,
	GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TB_buffer.to_location(1, 0, 2);
	TB_buffer.to_location(2, 2, 2);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_2d.program.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_3x3f(buffers.m_program_normal_mRMEC_2d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.view_XYZ_location, static_cast<const GLfloat*>(m_view_XYZ))
		.set_uniform_3f(buffers.m_program_normal_mRMEC_2d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_2d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_2d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}



// 3D

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_solid_color_3d.program.set_uniform_4x4f(buffers.m_program_solid_color_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_solid_color_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_solid_color_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_solid_color_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_solid_color_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_solid_color_3d.RMEC_location, RMEC.data())
		.set_uniform_4f(buffers.m_program_solid_color_3d.RGBA_location, solid_color.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	color_vertex_buffer.to_location(6);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_color_gradient_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_color_gradient_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_color_gradient_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_color_gradient_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_color_gradient_sRMEC_3d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_color_gradient_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_color_gradient_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_color_gradient_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_color_gradient_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_color_gradient_vRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	color_vertex_buffer.to_location(6);
	RMEC_vertex_buffer.to_location(7);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_color_gradient_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_color_gradient_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_color_gradient_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_color_gradient_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_color_gradient_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_color_gradient_vRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// TEXTURE 3D

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_texture_sRMEC_3d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_texture_sRMEC_3d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_vRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	N_buffer.to_location(1);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	RMEC_texture_buffer.to_binding(3);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_texture_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_texture_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_texture_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_texture_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_texture_mRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// NORMAL 3D

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_normal_sRMEC_3d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_normal_sRMEC_3d.RMEC_location, RMEC.data());

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_vRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_map) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_3d.C_location, color_ceiling);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_normal_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_normal_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_normal_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_normal_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_normal_mRMEC_3d.C_location, static_cast<GLfloat>(1));

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


// PARALLAX 3D

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_parallax_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_parallax_sRMEC_3d.RMEC_location, RMEC.data())
		.set_uniform_1f(buffers.m_program_parallax_sRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_parallax_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_sRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_sRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_sRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_sRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_sRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_sRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_4f(buffers.m_program_parallax_sRMEC_3d.RMEC_location, RMEC.data())
		.set_uniform_1f(buffers.m_program_parallax_sRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_parallax_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.C_location, static_cast<GLfloat>(1))
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	buffers.m_lightmap_black_vertex.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	buffers.m_lightmap_black.to_binding(1);
	normal_parallax_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.C_location, color_ceiling)
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_parallax_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.C_location, static_cast<GLfloat>(1))
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

	vertex_buffer.to_location(0);
	TBN_buffer.to_location(1, 0, 3);
	TBN_buffer.to_location(2, 3, 3);
	TBN_buffer.to_location(3, 6, 3);
	UV_buffer.to_location(4);
	lightmap_UV_buffer.to_location(5);
	RMEC_vertex_buffer.to_location(7);

	texture.to_binding(0);
	lightmap.to_binding(1);
	normal_parallax_map.to_binding(2);

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_vRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_vRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_vRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_vRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.C_location, color_ceiling)
		.set_uniform_1f(buffers.m_program_parallax_vRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.C_location, static_cast<GLfloat>(1))
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.C_location, color_ceiling)
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.C_location, static_cast<GLfloat>(1))
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}

kiwi::_draw_forward_proxy kiwi::_load_forward_3d_proxy::using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
	const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
	const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
	const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept
{
	kiwi::global_type<kiwi::forward_buffers> buffers = kiwi::get_global_type<kiwi::forward_buffers>();

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

	m_lightset_ptr->to_binding(0, 1, 2);
	m_light_selection_ptr->to_binding(3, 4, 5);

	buffers.m_program_parallax_mRMEC_3d.program.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.mvp_matrix_location, m_mvp_matrix_ptr)
		.set_uniform_4x4f(buffers.m_program_parallax_mRMEC_3d.m_matrix_location, m_m_matrix_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.view_XYZ_location, m_view_XYZ_ptr)
		.set_uniform_3f(buffers.m_program_parallax_mRMEC_3d.ambient_light_RGB_location, m_lightset_ptr->ambient_RGB_data())
		.set_uniform_3ui(buffers.m_program_parallax_mRMEC_3d.light_count_location, m_light_selection_ptr->number_of_lights_data())
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.C_location, color_ceiling)
		.set_uniform_1f(buffers.m_program_parallax_mRMEC_3d.parallax_shift_location, parallax_shift_factor);

	kiwi::_draw_forward_proxy proxy;
	proxy.m_vertex_count = vertex_buffer.vertex_count();
	return proxy;
}


void kiwi::_draw_forward_proxy::triangles() noexcept
{
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vertex_count));
}
void kiwi::_draw_forward_proxy::quads() noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(m_vertex_count));
}
void kiwi::_draw_forward_proxy::triangles(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::_draw_forward_proxy::quads(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::_draw_forward_proxy::triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::_draw_forward_proxy::quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, static_cast<GLsizei>(begin_vertex), static_cast<GLsizei>(vertex_count));
}



bool kiwi::forward_2d_solid_color::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_solid_color::vertex_shader(),
		kiwi::source::forward_2d_solid_color::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
		RGBA_location = program.new_uniform_location("u_RGBA");
	}

	return success;
}

bool kiwi::forward_2d_color_gradient_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_color_gradient_sRMEC::vertex_shader(),
		kiwi::source::forward_2d_color_gradient_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_2d_color_gradient_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_color_gradient_vRMEC::vertex_shader(),
		kiwi::source::forward_2d_color_gradient_vRMEC::fragment_shader()
	);
	
	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_2d_texture_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_texture_sRMEC::vertex_shader(),
		kiwi::source::forward_2d_texture_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_2d_texture_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_texture_vRMEC::vertex_shader(),
		kiwi::source::forward_2d_texture_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_2d_texture_mRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_texture_mRMEC::vertex_shader(),
		kiwi::source::forward_2d_texture_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_2d_normal_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_normal_sRMEC::vertex_shader(),
		kiwi::source::forward_2d_normal_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_2d_normal_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_normal_vRMEC::vertex_shader(),
		kiwi::source::forward_2d_normal_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_2d_normal_mRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_2d_normal_mRMEC::vertex_shader(),
		kiwi::source::forward_2d_normal_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}


bool kiwi::forward_3d_solid_color::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_solid_color::vertex_shader(),
		kiwi::source::forward_3d_solid_color::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
		RGBA_location = program.new_uniform_location("u_RGBA");
	}

	return success;
}

bool kiwi::forward_3d_color_gradient_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_color_gradient_sRMEC::vertex_shader(),
		kiwi::source::forward_3d_color_gradient_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_3d_color_gradient_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_color_gradient_vRMEC::vertex_shader(),
		kiwi::source::forward_3d_color_gradient_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_3d_texture_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_texture_sRMEC::vertex_shader(),
		kiwi::source::forward_3d_texture_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_3d_texture_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_texture_vRMEC::vertex_shader(),
		kiwi::source::forward_3d_texture_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_3d_texture_mRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_texture_mRMEC::vertex_shader(),
		kiwi::source::forward_3d_texture_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_3d_normal_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_normal_sRMEC::vertex_shader(),
		kiwi::source::forward_3d_normal_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_3d_normal_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_normal_vRMEC::vertex_shader(),
		kiwi::source::forward_3d_normal_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_3d_normal_mRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_normal_mRMEC::vertex_shader(),
		kiwi::source::forward_3d_normal_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_3d_parallax_sRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_parallax_sRMEC::vertex_shader(),
		kiwi::source::forward_3d_parallax_sRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");
		parallax_shift_location = program.new_uniform_location("u_shift_factor");

		light_count_location = program.new_uniform_location("u_light_count");

		RMEC_location = program.new_uniform_location("u_RMEC");
	}

	return success;
}

bool kiwi::forward_3d_parallax_vRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_parallax_vRMEC::vertex_shader(),
		kiwi::source::forward_3d_parallax_vRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");
		parallax_shift_location = program.new_uniform_location("u_shift_factor");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}

bool kiwi::forward_3d_parallax_mRMEC::init() noexcept
{
	bool success = program.new_program(
		kiwi::source::forward_3d_parallax_mRMEC::vertex_shader(),
		kiwi::source::forward_3d_parallax_mRMEC::fragment_shader()
	);

	if (success)
	{
		mvp_matrix_location = program.new_uniform_location("u_mvp_M");
		m_matrix_location = program.new_uniform_location("u_m_M");
		view_XYZ_location = program.new_uniform_location("u_view_XYZ");
		ambient_light_RGB_location = program.new_uniform_location("u_ambient_light_RGB");
		parallax_shift_location = program.new_uniform_location("u_shift_factor");

		light_count_location = program.new_uniform_location("u_light_count");

		C_location = program.new_uniform_location("u_C");
	}

	return success;
}