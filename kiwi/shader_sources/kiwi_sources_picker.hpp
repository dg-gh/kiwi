#ifndef KIWI_SOURCES_PICKER_HPP
#define KIWI_SOURCES_PICKER_HPP

namespace kiwi
{
	namespace source
	{
		namespace picker_2d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace picker_XY_id_2d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace picker_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}

		namespace picker_XYZ_id_3d
		{
			const char* const vertex_shader() noexcept;
			const char* const fragment_shader() noexcept;
		}
	}
}

#endif // KIWI_SOURCES_PICKER_HPP