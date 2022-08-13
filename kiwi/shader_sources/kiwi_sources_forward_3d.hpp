#ifndef KIWI_SOURCES_FORWARD_3D_HPP
#define KIWI_SOURCES_FORWARD_3D_HPP

namespace kiwi
{
	namespace source
	{
		namespace forward_3d_solid_color
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_3d_color_gradient
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_3d_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_3d_normal
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_3d_parallax
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_FORWARD_3D_HPP