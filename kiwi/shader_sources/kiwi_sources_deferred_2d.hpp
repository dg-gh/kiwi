#ifndef KIWI_SOURCES_DEFERRED_2D_HPP
#define KIWI_SOURCES_DEFERRED_2D_HPP

namespace kiwi
{
	namespace source
	{
		namespace deferred_2d_lighting_pass
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace deferred_2d_solid_color
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace deferred_2d_color_gradient
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace deferred_2d_texture
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace deferred_2d_normal
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_DEFERRED_2D_HPP