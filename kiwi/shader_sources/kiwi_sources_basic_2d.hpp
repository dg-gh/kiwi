#ifndef _KIWI_SOURCES_BASIC_2D_HPP
#define _KIWI_SOURCES_BASIC_2D_HPP

namespace kiwi
{
	namespace source
	{
		namespace basic_2d_solid_color
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_2d_color_gradient
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_2d_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_2d_texture_alpha_test
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_2d_point_dist_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_2d_plane_dist_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_2d_no_shade
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // _KIWI_SOURCES_BASIC_2D_HPP