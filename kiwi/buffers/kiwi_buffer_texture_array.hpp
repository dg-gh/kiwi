#ifndef _KIWI_BUFFER_TEXTURE_ARRAY_HPP
#define _KIWI_BUFFER_TEXTURE_ARRAY_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	class texture_array_buffer : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_width;
		std::size_t m_height;
		std::size_t m_layer_count;
		kiwi::pixel_format m_format;

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

		kiwi::texture_array_buffer& allocate(kiwi::pixel_format format, kiwi::size size_2d,
			std::size_t layer_count, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_array_buffer& load(const void* const texture_array_data_ptr) noexcept;

		kiwi::texture_array_buffer& load(const void* const texture_array_data_ptr,
			std::size_t layer_count) noexcept;

		kiwi::texture_array_buffer& load(const void* const texture_array_data_ptr,
			std::size_t first_layer, std::size_t layer_count) noexcept;


		kiwi::texture_array_buffer& to_binding(GLenum binding) noexcept;
		const kiwi::texture_array_buffer& to_binding(GLenum binding) const noexcept;
		kiwi::texture_array_buffer& to_binding_for_compute(GLuint binding) noexcept;
		const kiwi::texture_array_buffer& to_binding_for_compute(GLuint binding) const noexcept;
		kiwi::texture_array_buffer& unbind_for_compute(GLuint binding) noexcept;
		const kiwi::texture_array_buffer& unbind_for_compute(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;
		std::size_t layer_count() const noexcept;

		kiwi::texture_array_buffer& set_format(kiwi::pixel_format format) noexcept;
		kiwi::texture_sampling get_format() const noexcept;

		kiwi::texture_array_buffer& set_sampling(kiwi::texture_sampling sampling) noexcept;
		kiwi::texture_sampling get_sampling() const noexcept;
	};
}

#endif // _KIWI_BUFFER_TEXTURE_ARRAY_HPP