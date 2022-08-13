#ifndef KIWI_SOURCES_FORWARD_2D_HPP
#define KIWI_SOURCES_FORWARD_2D_HPP

namespace kiwi
{
	namespace source
	{
		namespace forward_2d_solid_color
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_2d_color_gradient_vRMEC
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_2d_texture_mRMEC
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace forward_2d_normal_mRMEC
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_FORWARD_2D_HPP