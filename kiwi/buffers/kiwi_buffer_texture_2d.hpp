#ifndef _KIWI_BUFFER_TEXTURE_2D_HPP
#define _KIWI_BUFFER_TEXTURE_2D_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	class texture_2d;
	using texture = texture_2d;

	class texture_2d : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_width;
		std::size_t m_height;
		kiwi::pixel_format m_format;
		GLenum m_sampling;

	public:

		texture_2d() noexcept;
		texture_2d(const texture_2d&) = delete;
		texture_2d& operator=(const texture_2d&) = delete;
		texture_2d(texture_2d&& rhs) noexcept;
		texture_2d& operator=(texture_2d&& rhs) noexcept;
		~texture_2d();

		kiwi::texture_2d& new_id() noexcept;
		kiwi::texture_2d& delete_id() noexcept;

		kiwi::texture_2d& bind() noexcept;
		const kiwi::texture_2d& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::texture_2d& load(const void* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping,
			kiwi::pixel_format format = kiwi::pixel_format::u8) noexcept;

		kiwi::texture_2d& load_u8(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_u16(const GLushort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_f32(const GLfloat* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_u8u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_u16u(const GLushort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_u32u(const GLuint* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_2d& load_i8u(const char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_i16u(const GLshort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d& load_i32u(const GLint* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_2d& allocate(kiwi::pixel_format format, kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_2d& to_binding(GLenum binding) noexcept;
		const kiwi::texture_2d& to_binding(GLenum binding) const noexcept;
		kiwi::texture_2d& to_binding_for_compute(GLuint binding) noexcept;
		const kiwi::texture_2d& to_binding_for_compute(GLuint binding) const noexcept;
		kiwi::texture_2d& unbind_for_compute(GLuint binding) noexcept;
		const kiwi::texture_2d& unbind_for_compute(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;

		kiwi::texture_2d& set_format(kiwi::pixel_format format) noexcept;
		kiwi::pixel_format get_format() const noexcept;

		kiwi::texture_2d& set_sampling(kiwi::texture_sampling sampling) noexcept;
		kiwi::texture_sampling get_sampling() const noexcept;
	};
}

#endif // _KIWI_BUFFER_TEXTURE_2D_HPP