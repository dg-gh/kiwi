#ifndef KIWI_BUFFER_TEXTURE_HPP
#define KIWI_BUFFER_TEXTURE_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	enum class texture_mapping {
		nearest,
		linear,
		nearest_mipmap_nearest,
		linear_mipmap_nearest,
		nearest_mipmap_linear,
		linear_mipmap_linear
	};
	enum class texture_borders { repeat, repeat_mirrored, clamp, pad };
	enum class texture_format {
		u8, u16,
		f16, f32,
		u8u, u16u, u32u,
		i8u, i16u, i32u,
		depth
	};
	enum class texture_sampling { unique, multiple };

	class texture_buffer
	{

	private:

		GLuint m_buffer_index;
		GLsizei m_current_size;
		std::size_t m_dim;
		std::size_t m_width;
		std::size_t m_height;
		kiwi::texture_format m_format;
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
		GLuint get_id() const noexcept;

		kiwi::texture_buffer& bind() noexcept;
		const kiwi::texture_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::texture_buffer& load(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_u8(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_u16(const GLushort* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_f32(const GLfloat* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_u8u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_u16u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_u32u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;


		kiwi::texture_buffer& load_i8u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_i16u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;

		kiwi::texture_buffer& load_i32u(const unsigned char* const texture_data_ptr,
			kiwi::size size_2d, std::size_t pixel_dim,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;


		kiwi::texture_buffer& allocate(kiwi::texture_format format, kiwi::size size_2d, std::size_t pixel_dimension,
			kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept;


		kiwi::texture_buffer& to_binding(GLenum binding) noexcept;
		const kiwi::texture_buffer& to_binding(GLenum binding) const noexcept;
		kiwi::texture_buffer& to_binding_for_invocation(GLuint binding) noexcept;
		const kiwi::texture_buffer& to_binding_for_invocation(GLuint binding) const noexcept;
		kiwi::texture_buffer& unbind_for_invocation(GLuint binding) noexcept;
		const kiwi::texture_buffer& unbind_for_invocation(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept;
		std::size_t height() const noexcept;

		kiwi::texture_buffer& set_format(kiwi::texture_format format) noexcept;
		kiwi::texture_format get_format() const noexcept;

		kiwi::texture_buffer& set_sampling(kiwi::texture_sampling sampling) noexcept;
		kiwi::texture_sampling get_sampling() const noexcept;

	private:

		void p_format(kiwi::texture_format format, std::size_t pixel_dimension,
			GLenum* type_ptr, GLenum* color_format_ptr, GLint* internal_format_ptr) const noexcept;

		GLint p_internal_format(kiwi::texture_format format, std::size_t pixel_dimension) const noexcept;
	};
}

#endif // KIWI_BUFFER_TEXTURE_HPP