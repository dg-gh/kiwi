#ifndef _KIWI_BUFFER_TEXTURE_HPP
#define _KIWI_BUFFER_TEXTURE_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	class texture_buffer;
	using texture_2d_buffer = texture_buffer;

	class texture_buffer : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_width;
		std::size_t m_height;
		kiwi::pixel_format m_format;
		GLenum m_sampling;

	public:

		texture_buffer() noexcept;
		texture_buffer(const texture_buffer&) = delete;
		texture_buffer& operator=(const texture_buffer&) = delete;
		texture_buffer(texture_buffer&& rhs) noexcept;
		texture_buffer& operator=(texture_buffer&& rhs) noexcept;
		~texture_buffer();

		kiwi::texture_buffer& new_id() noexcept;
		kiwi::texture_buffer& delete_id() noexcept;

		kiwi::texture_buffer& bind() noexcept;
		const kiwi::texture_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::texture_buffer& load(const void* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping,
			kiwi::pixel_format format = kiwi::pixel_format::u8) noexcept;

		kiwi::texture_buffer& load_u8(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_u16(const GLushort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_f32(const GLfloat* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_u8u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_u16u(const GLushort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_u32u(const GLuint* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_buffer& load_i8u(const char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_i16u(const GLshort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_buffer& load_i32u(const GLint* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_buffer& allocate(kiwi::pixel_format format, kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_buffer& to_binding(GLenum binding) noexcept;
		const kiwi::texture_buffer& to_binding(GLenum binding) const noexcept;
		kiwi::texture_buffer& to_binding_for_compute(GLuint binding) noexcept;
		const kiwi::texture_buffer& to_binding_for_compute(GLuint binding) const noexcept;
		kiwi::texture_buffer& unbind_for_compute(GLuint binding) noexcept;
		const kiwi::texture_buffer& unbind_for_compute(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;

		kiwi::texture_buffer& set_format(kiwi::pixel_format format) noexcept;
		kiwi::pixel_format get_format() const noexcept;

		kiwi::texture_buffer& set_sampling(kiwi::texture_sampling sampling) noexcept;
		kiwi::texture_sampling get_sampling() const noexcept;
	};
}

#endif // _KIWI_BUFFER_TEXTURE_HPP