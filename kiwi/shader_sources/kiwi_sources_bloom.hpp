#ifndef KIWI_SOURCES_BLOOM_HPP
#define KIWI_SOURCES_BLOOM_HPP

namespace kiwi
{
	namespace source
	{
		namespace bloom_threshold
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace bloom_gaussian_filter
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace bloom_blend_4_layers
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace bloom_blend_8_layers
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_BLOOM_HPP