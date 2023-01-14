#ifndef _KIWI_BUFFER_CUBEMAP_HPP
#define _KIWI_BUFFER_CUBEMAP_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	enum class cubemap_face {
		Xp, Xm,
		Yp, Ym,
		Zp, Zm
	};

	class cubemap : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_width;
		kiwi::pixel_format m_format;

	public:

		cubemap() noexcept;
		cubemap(const cubemap&) = delete;
		cubemap& operator=(const cubemap&) = delete;
		cubemap(cubemap&& rhs) noexcept;
		cubemap& operator=(cubemap&& rhs) noexcept;
		~cubemap();

		kiwi::cubemap& new_id() noexcept;
		kiwi::cubemap& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::cubemap& bind() noexcept;
		const kiwi::cubemap& bind() const noexcept;
		static void unbind() noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;

		kiwi::cubemap& to_binding(GLenum binding) noexcept;
		const kiwi::cubemap& to_binding(GLenum binding) const noexcept;

		kiwi::cubemap& load(
			const void* const Xp_data_ptr, const void* const Xm_data_ptr,
			const void* const Yp_data_ptr, const void* const Ym_data_ptr,
			const void* const Zp_data_ptr, const void* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping,
			kiwi::pixel_format format = kiwi::pixel_format::u8) noexcept;

		kiwi::cubemap& load_u8(
			const unsigned char* const Xp_data_ptr, const unsigned char* const Xm_data_ptr,
			const unsigned char* const Yp_data_ptr, const unsigned char* const Ym_data_ptr,
			const unsigned char* const Zp_data_ptr, const unsigned char* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_u16(
			const GLushort* const Xp_data_ptr, const GLushort* const Xm_data_ptr,
			const GLushort* const Yp_data_ptr, const GLushort* const Ym_data_ptr,
			const GLushort* const Zp_data_ptr, const GLushort* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_f32(
			const GLfloat* const Xp_data_ptr, const GLfloat* const Xm_data_ptr,
			const GLfloat* const Yp_data_ptr, const GLfloat* const Ym_data_ptr,
			const GLfloat* const Zp_data_ptr, const GLfloat* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_u8u(
			const unsigned char* const Xp_data_ptr, const unsigned char* const Xm_data_ptr,
			const unsigned char* const Yp_data_ptr, const unsigned char* const Ym_data_ptr,
			const unsigned char* const Zp_data_ptr, const unsigned char* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_u16u(
			const GLushort* const Xp_data_ptr, const GLushort* const Xm_data_ptr,
			const GLushort* const Yp_data_ptr, const GLushort* const Ym_data_ptr,
			const GLushort* const Zp_data_ptr, const GLushort* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_u32u(
			const GLuint* const Xp_data_ptr, const GLuint* const Xm_data_ptr,
			const GLuint* const Yp_data_ptr, const GLuint* const Ym_data_ptr,
			const GLuint* const Zp_data_ptr, const GLuint* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;


		kiwi::cubemap& load_i8u(
			const char* const Xp_data_ptr, const char* const Xm_data_ptr,
			const char* const Yp_data_ptr, const char* const Ym_data_ptr,
			const char* const Zp_data_ptr, const char* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_i16u(
			const GLshort* const Xp_data_ptr, const GLshort* const Xm_data_ptr,
			const GLshort* const Yp_data_ptr, const GLshort* const Ym_data_ptr,
			const GLshort* const Zp_data_ptr, const GLshort* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_i32u(
			const GLint* const Xp_data_ptr, const GLint* const Xm_data_ptr,
			const GLint* const Yp_data_ptr, const GLint* const Ym_data_ptr,
			const GLint* const Zp_data_ptr, const GLint* const Zm_data_ptr,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;


		kiwi::cubemap& load_face(
			const void* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping,
			kiwi::pixel_format format = kiwi::pixel_format::u8) noexcept;

		kiwi::cubemap& load_face_u8(
			const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_u16(
			const GLushort* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_f32(
			const GLfloat* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_u8u(
			const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_u16u(
			const GLushort* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_u32u(
			const GLuint* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;


		kiwi::cubemap& load_face_i8u(
			const char* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_i16u(
			const GLshort* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;

		kiwi::cubemap& load_face_i32u(
			const GLint* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept;
	};
}

#endif // _KIWI_BUFFER_CUBEMAP_HPP