#ifndef _KIWI_BUFFER_PIXEL_HPP
#define _KIWI_BUFFER_PIXEL_HPP

#include "context/kiwi_context.hpp"

namespace kiwi
{
	enum class pixel_buffer_type {
		texture_1d,
		texture_2d,
		texture_array_2d,
		cubemap
	};

	enum class pixel_format {
		u8, u16,
		f16, f32,
		u8u, u16u, u32u,
		i8u, i16u, i32u,
		dep16, dep32
	};

	enum class pixel_mapping {
		nearest,
		linear,
		nearest_mipmap_nearest,
		linear_mipmap_nearest,
		nearest_mipmap_linear,
		linear_mipmap_linear
	};

	enum class pixel_wrapping {
		repeat,
		repeat_mirrored,
		clamp,
		pad
	};

	enum class texture_sampling {
		unique,
		multiple
	};

	class pixel_buffer
	{

	public:

		GLuint get_id() noexcept;
		kiwi::pixel_buffer_type get_pixel_buffer_type() const noexcept;
		virtual std::size_t width() const noexcept = 0;
		virtual std::size_t height() const noexcept = 0;

	protected:

		GLuint m_buffer_index;
		kiwi::pixel_buffer_type m_pixel_buffer_type;

		static void set_pixel_mapping(kiwi::pixel_mapping mapping, GLint* mapping_mag_ptr, GLint* mapping_min_ptr) noexcept;
		static void set_pixel_mapping(kiwi::pixel_mapping mapping, GLint* mapping_mag_ptr, GLint* mapping_min_ptr, bool* mipmap_ptr) noexcept;

		static void set_pixel_wrapping(kiwi::pixel_wrapping wrapping, GLint* wrapping_ptr) noexcept;

		static void set_pixel_format(kiwi::pixel_format format, std::size_t pixel_dimension,
			GLint* internal_format_ptr) noexcept;
		static void set_pixel_format(kiwi::pixel_format format, std::size_t pixel_dimension,
			GLint* internal_format_ptr, GLenum* color_format_ptr) noexcept;
		static void set_pixel_format(kiwi::pixel_format format, std::size_t pixel_dimension,
			GLint* internal_format_ptr, GLenum* color_format_ptr, GLenum* type_ptr) noexcept;
	};
}


#endif // _KIWI_BUFFER_PIXEL_HPP