#ifndef _KIWI_SOURCES_BASIC_3D_HPP
#define _KIWI_SOURCES_BASIC_3D_HPP

namespace kiwi
{
	namespace source
	{
		namespace basic_3d_solid_color
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_color_gradient
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_texture_alpha_test
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_point_dist_texture		
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_plane_dist_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_normal_dir_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_normal_cubemap_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_skybox
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace basic_3d_no_shade
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // _KIWI_SOURCES_BASIC_3D_HPP