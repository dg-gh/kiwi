#ifndef _KIWI_BUFFER_TEXTURE_1D_HPP
#define _KIWI_BUFFER_TEXTURE_1D_HPP

#include "header_utils/kiwi_glcall.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	class texture_1d : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_width;
		kiwi::pixel_format m_format;

	public:

		texture_1d() noexcept;
		texture_1d(const texture_1d&) = delete;
		texture_1d& operator=(const texture_1d&) = delete;
		texture_1d(texture_1d&& rhs) noexcept;
		texture_1d& operator=(texture_1d&& rhs) noexcept;
		~texture_1d();

		kiwi::texture_1d& new_id() noexcept;
		kiwi::texture_1d& delete_id() noexcept;

		kiwi::texture_1d& bind() noexcept;
		const kiwi::texture_1d& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::texture_1d& load(const void* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping,
			kiwi::pixel_format format = kiwi::pixel_format::u8) noexcept;

		kiwi::texture_1d& load_u8(const unsigned char* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_u16(const GLushort* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_f32(const GLfloat* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_u8u(const unsigned char* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_u16u(const GLushort* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_u32u(const GLuint* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_1d& load_i8u(const char* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_i16u(const GLshort* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_1d& load_i32u(const GLint* const texture_data_ptr,
			std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_1d& allocate(kiwi::pixel_format format, std::size_t size_1d, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;


		kiwi::texture_1d& to_binding(GLenum binding) noexcept;
		const kiwi::texture_1d& to_binding(GLenum binding) const noexcept;
		kiwi::texture_1d& to_binding_for_compute(GLuint binding) noexcept;
		const kiwi::texture_1d& to_binding_for_compute(GLuint binding) const noexcept;
		kiwi::texture_1d& unbind_for_compute(GLuint binding) noexcept;
		const kiwi::texture_1d& unbind_for_compute(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;

		kiwi::texture_1d& set_format(kiwi::pixel_format format) noexcept;
		kiwi::pixel_format get_format() const noexcept;
	};
}

#endif // _KIWI_BUFFER_TEXTURE_1D_HPP