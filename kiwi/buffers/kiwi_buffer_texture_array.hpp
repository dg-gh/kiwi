#ifndef KIWI_BUFFER_TEXTURE_ARRAY_HPP
#define KIWI_BUFFER_TEXTURE_ARRAY_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	enum class texture_array_mapping {
		nearest,
		linear,
		nearest_mipmap_nearest,
		linear_mipmap_nearest,
		nearest_mipmap_linear,
		linear_mipmap_linear
	};
	enum class texture_array_borders { repeat, repeat_mirrored, clamp, pad };
	enum class texture_array_format {
		u8, u16,
		f16, f32,
		u8u, u16u, u32u,
		i8u, i16u, i32u,
		depth
	};
	enum class texture_array_sampling { unique, multiple };

	class texture_array_buffer : public kiwi::pixel_buffer
	{

	private:

		GLsizei m_current_size;
		std::size_t m_dim;
		std::size_t m_width;
		std::size_t m_height;
		kiwi::texture_array_format m_format;
		GLenum m_sampling;

	public:

		texture_array_buffer() noexcept;
		texture_array_buffer(const texture_array_buffer&) = delete;
		texture_array_buffer& operator=(const texture_array_buffer&) = delete;
		texture_array_buffer(texture_array_buffer&& rhs) noexcept;
		texture_array_buffer& operator=(texture_array_buffer&& rhs) noexcept;
		~texture_array_buffer();

		kiwi::texture_array_buffer& new_id() noexcept;
		kiwi::texture_array_buffer& delete_id() noexcept;

		kiwi::texture_array_buffer& bind() noexcept;
		const kiwi::texture_array_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::texture_array_buffer& load(const unsigned char* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_u8(const unsigned char* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_u16(const GLushort* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_f32(const GLfloat* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_u8u(const unsigned char* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_u16u(const GLushort* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_u32u(const GLuint* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;


		kiwi::texture_array_buffer& load_i8u(const char* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_i16u(const GLshort* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;

		kiwi::texture_array_buffer& load_i32u(const GLint* const texture_array_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;


		kiwi::texture_array_buffer& allocate(kiwi::texture_array_format format, kiwi::size size_2d, std::size_t pixel_dimension,
			kiwi::texture_array_mapping mapping, kiwi::texture_array_borders borders) noexcept;


		kiwi::texture_array_buffer& to_binding(GLenum binding) noexcept;
		const kiwi::texture_array_buffer& to_binding(GLenum binding) const noexcept;
		kiwi::texture_array_buffer& to_binding_for_compute(GLuint binding) noexcept;
		const kiwi::texture_array_buffer& to_binding_for_compute(GLuint binding) const noexcept;
		kiwi::texture_array_buffer& unbind_for_compute(GLuint binding) noexcept;
		const kiwi::texture_array_buffer& unbind_for_compute(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;

		kiwi::texture_array_buffer& set_format(kiwi::texture_array_format format) noexcept;
		kiwi::texture_array_format get_format() const noexcept;

		kiwi::texture_array_buffer& set_sampling(kiwi::texture_array_sampling sampling) noexcept;
		kiwi::texture_array_sampling get_sampling() const noexcept;

	private:

		void pixel_format(kiwi::texture_array_format format, std::size_t pixel_dimension,
			GLenum* type_ptr, GLenum* color_format_ptr, GLint* internal_format_ptr) const noexcept;

		GLint pixel_internal_format(kiwi::texture_array_format format, std::size_t pixel_dimension) const noexcept;
	};
}

#endif // KIWI_BUFFER_TEXTURE_ARRAY_HPP