#ifndef KIWI_SOURCES_SPRITES_HPP
#define KIWI_SOURCES_SPRITES_HPP

namespace kiwi
{
	namespace source
	{
		namespace solid_color_sprites_2d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace texture_sprites_2d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace texture_array_sprites_2d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace solid_color_sprite_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace solid_color_sprites_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace texture_sprite_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace texture_sprites_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace texture_array_sprites_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_SPRITES_HPP