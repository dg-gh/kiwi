#ifndef KIWI_SOURCES_GLYPH_HPP
#define KIWI_SOURCES_GLYPH_HPP

namespace kiwi
{
	namespace source
	{
		namespace glyph_2d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace glyph_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_GLYPH_HPP