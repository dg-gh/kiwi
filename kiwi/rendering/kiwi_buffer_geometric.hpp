#include "rendering/kiwi_buffer_vertex.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_buffer_frame.hpp"
#include "shader_sources/kiwi_sources_deferred_2d.hpp"
#include "shader_sources/kiwi_sources_deferred_3d.hpp"
#include "rendering/kiwi_sets.hpp"


namespace kiwi
{
	class geometric_buffer_2d
	{

	public:

		kiwi::geometric_buffer_2d& collect() noexcept;

		kiwi::geometric_buffer_2d& draw(const GLfloat* const view_right_up_XY_ptr, GLfloat view_Z, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer = false) noexcept;
		kiwi::geometric_buffer_2d& draw_to_current(const GLfloat* const view_right_up_XY_ptr, GLfloat view_Z, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer = false) noexcept;
		kiwi::geometric_buffer_2d& draw(const GLfloat* const view_right_up_XY_ptr, GLfloat view_Z, const kiwi::lightset& lights, const kiwi::light_selection& selection,
			kiwi::frame_buffer& frame_buffer, std::size_t color_attachmaent, bool blit_depth_buffer = false) noexcept;

		kiwi::geometric_buffer_2d& set_scale(GLfloat scale) noexcept;

		bool init(std::size_t width, std::size_t height) noexcept;

		kiwi::texture_buffer& get_albedo_texture() noexcept;
		const kiwi::texture_buffer& get_albedo_texture() const noexcept;

		kiwi::texture_buffer& get_normal_texture() noexcept;
		const kiwi::texture_buffer& get_normal_texture() const noexcept;

		kiwi::texture_buffer& get_RMEC_texture() noexcept;
		const kiwi::texture_buffer& get_RMEC_texture() const noexcept;

		kiwi::texture_buffer& get_lightmap_texture() noexcept;
		const kiwi::texture_buffer& get_lightmap_texture() const noexcept;

		kiwi::frame_buffer& get_frame_buffer() noexcept;
		const kiwi::frame_buffer& get_frame_buffer() const noexcept;

	private:

		kiwi::frame_buffer m_frame_buffer;
		kiwi::render_buffer m_depth_buffer;
		kiwi::texture_buffer m_albedo_RGB;
		kiwi::texture_buffer m_N;
		kiwi::texture_buffer m_RMEC;
		kiwi::texture_buffer m_lightmap_RGB;

		kiwi::program m_deferred_2d_lighting;

		GLint m_view_left_up_XY_location = -1;
		GLint m_view_Z_location = -1;
		GLint m_ambient_light_RGB_location = -1;
		GLint m_light_count_location = -1;
		GLint m_scale_location = -1;
		GLfloat m_screen_ratio = static_cast<GLfloat>(1);

		std::size_t m_width = 0;
		std::size_t m_height = 0;
	};
}


namespace kiwi
{
	class geometric_buffer_3d
	{

	public:

		kiwi::geometric_buffer_3d& collect() noexcept;

		kiwi::geometric_buffer_3d& draw(const GLfloat* const view_XYZ_front_left_up_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer = false) noexcept;
		kiwi::geometric_buffer_3d& draw_to_current(const GLfloat* const view_XYZ_front_left_up_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection, bool blit_depth_buffer = false) noexcept;
		kiwi::geometric_buffer_3d& draw(const GLfloat* const view_XYZ_front_left_up_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection,
			kiwi::frame_buffer& frame_buffer, std::size_t color_attachmaent, bool blit_depth_buffer = false) noexcept;

		kiwi::geometric_buffer_3d& set_perspective(GLfloat fov, GLfloat z_near, GLfloat z_far) noexcept;
		kiwi::geometric_buffer_3d& set_perspective() noexcept;
		kiwi::geometric_buffer_3d& set_ortho(const kiwi::XY& scale, GLfloat z_near, GLfloat z_far) noexcept;
		kiwi::geometric_buffer_3d& set_ortho() noexcept;

		bool init(std::size_t width, std::size_t height) noexcept;

		kiwi::texture_buffer& get_albedo_texture() noexcept;
		const kiwi::texture_buffer& get_albedo_texture() const noexcept;

		kiwi::texture_buffer& get_depth_texture() noexcept;
		const kiwi::texture_buffer& get_depth_texture() const noexcept;

		kiwi::texture_buffer& get_normal_texture() noexcept;
		const kiwi::texture_buffer& get_normal_texture() const noexcept;

		kiwi::texture_buffer& get_RMEC_texture() noexcept;
		const kiwi::texture_buffer& get_RMEC_texture() const noexcept;

		kiwi::texture_buffer& get_lightmap_texture() noexcept;
		const kiwi::texture_buffer& get_lightmap_texture() const noexcept;

		kiwi::frame_buffer& get_frame_buffer() noexcept;
		const kiwi::frame_buffer& get_frame_buffer() const noexcept;

	private:

		kiwi::frame_buffer m_frame_buffer;
		kiwi::render_buffer m_depth_buffer;
		kiwi::texture_buffer m_albedo_RGB;
		kiwi::texture_buffer m_N;
		kiwi::texture_buffer m_Z;
		kiwi::texture_buffer m_RMEC;
		kiwi::texture_buffer m_lightmap_RGB;

		kiwi::program m_deferred_3d_lighting;
		kiwi::program m_deferred_3d_lighting_ortho;

		GLint m_view_front_left_up_XYZ_location = -1;
		GLint m_ambient_light_RGB_location = -1;
		GLint m_light_count_location = -1;
		GLint m_scale_location = -1;
		GLint m_tan_half_fov_a_b_location = -1;

		GLint m_view_front_left_up_XYZ_location_ortho = -1;
		GLint m_ambient_light_RGB_location_ortho = -1;
		GLint m_light_count_location_ortho = -1;
		GLint m_scale_location_ortho = -1;
		GLint m_a_b_location_ortho = -1;

		std::size_t m_width = 0;
		std::size_t m_height = 0;

		bool m_perspective = true;
	};
}

namespace kiwi
{
	class scoped_deferred_3d_pass
	{

	public:

		scoped_deferred_3d_pass() = delete;
		scoped_deferred_3d_pass(const kiwi::scoped_deferred_3d_pass&) = delete;
		kiwi::scoped_deferred_3d_pass& operator=(const kiwi::scoped_deferred_3d_pass&) = delete;
		scoped_deferred_3d_pass(kiwi::scoped_deferred_3d_pass&&) = delete;
		kiwi::scoped_deferred_3d_pass& operator=(kiwi::scoped_deferred_3d_pass&&) = delete;

		scoped_deferred_3d_pass(kiwi::geometric_buffer_3d& g_buffer, const GLfloat* const view_XYZ_front_left_up_ptr, const kiwi::lightset& lights, const kiwi::light_selection& selection) noexcept
		{
			g_buffer.collect();
			m_geometric_buffer_ptr = &g_buffer;
			m_view_XYZ_front_left_up_ptr = view_XYZ_front_left_up_ptr;
			m_lights_ptr = &lights;
			m_selection_ptr = &selection;
		}

		~scoped_deferred_3d_pass()
		{
			m_geometric_buffer_ptr->draw(m_view_XYZ_front_left_up_ptr, *m_lights_ptr, *m_selection_ptr);
		}


	private:

		kiwi::geometric_buffer_3d* m_geometric_buffer_ptr;
		const GLfloat* m_view_XYZ_front_left_up_ptr;
		const kiwi::lightset* m_lights_ptr;
		const kiwi::light_selection* m_selection_ptr;
	};
}