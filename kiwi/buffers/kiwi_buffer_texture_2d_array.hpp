#ifndef _KIWI_BUFFER_TEXTURE_ARRAY_HPP
#define _KIWI_BUFFER_TEXTURE_ARRAY_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	class texture_2d_array;
	using texture_array = texture_2d_array;

	class texture_2d_array : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_width;
		std::size_t m_height;
		std::size_t m_layer_count;
		kiwi::pixel_format m_format;

	public:

		texture_2d_array() noexcept;
		texture_2d_array(const texture_2d_array&) = delete;
		texture_2d_array& operator=(const texture_2d_array&) = delete;
		texture_2d_array(texture_2d_array&& rhs) noexcept;
		texture_2d_array& operator=(texture_2d_array&& rhs) noexcept;
		~texture_2d_array();

		kiwi::texture_2d_array& new_id() noexcept;
		kiwi::texture_2d_array& delete_id() noexcept;

		kiwi::texture_2d_array& bind() noexcept;
		const kiwi::texture_2d_array& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::texture_2d_array& allocate(kiwi::pixel_format format, kiwi::size size_2d,
			std::size_t layer_count, std::size_t pixel_dim,
			kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept;

		kiwi::texture_2d_array& load(const void* const texture_array_data_ptr) noexcept;

		kiwi::texture_2d_array& load(const void* const texture_array_data_ptr,
			std::size_t layer_count) noexcept;

		kiwi::texture_2d_array& load(const void* const texture_array_data_ptr,
			std::size_t first_layer, std::size_t layer_count) noexcept;


		kiwi::texture_2d_array& to_binding(GLenum binding) noexcept;
		const kiwi::texture_2d_array& to_binding(GLenum binding) const noexcept;
		kiwi::texture_2d_array& to_binding_for_compute(GLuint binding) noexcept;
		const kiwi::texture_2d_array& to_binding_for_compute(GLuint binding) const noexcept;
		kiwi::texture_2d_array& unbind_for_compute(GLuint binding) noexcept;
		const kiwi::texture_2d_array& unbind_for_compute(GLuint binding) const noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;
		std::size_t layer_count() const noexcept;

		kiwi::texture_2d_array& set_format(kiwi::pixel_format format) noexcept;
		kiwi::texture_sampling get_format() const noexcept;

		kiwi::texture_2d_array& set_sampling(kiwi::texture_sampling sampling) noexcept;
		kiwi::texture_sampling get_sampling() const noexcept;
	};
}

#endif // _KIWI_BUFFER_TEXTURE_ARRAY_HPP