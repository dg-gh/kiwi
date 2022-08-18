#ifndef KIWI_BUFFER_CUBEMAP_HPP
#define KIWI_BUFFER_CUBEMAP_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	enum class cubemap_mapping {
		nearest,
		linear,
		nearest_mipmap_nearest,
		linear_mipmap_nearest,
		nearest_mipmap_linear,
		linear_mipmap_linear
	};
	enum class cubemap_format {
		u8, u16,
		f16, f32,
		u8u, u16u, u32u,
		i8u, i16u, i32u,
		depth
	};
	enum class cubemap_face {
		Xp, Xm,
		Yp, Ym,
		Zp, Zm
	};

	class cubemap_buffer : public kiwi::pixel_buffer
	{

	private:

		std::size_t m_dim;
		std::size_t m_resolution;
		kiwi::cubemap_format m_format;

	public:

		cubemap_buffer() noexcept;
		cubemap_buffer(const cubemap_buffer&) = delete;
		cubemap_buffer& operator=(const cubemap_buffer&) = delete;
		cubemap_buffer(cubemap_buffer&& rhs) noexcept;
		cubemap_buffer& operator=(cubemap_buffer&& rhs) noexcept;
		~cubemap_buffer();

		kiwi::cubemap_buffer& new_id() noexcept;
		kiwi::cubemap_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::cubemap_buffer& bind() noexcept;
		const kiwi::cubemap_buffer& bind() const noexcept;
		static void unbind() noexcept;

		std::size_t pixel_dim() const noexcept;
		std::size_t width() const noexcept override;
		std::size_t height() const noexcept override;

		kiwi::cubemap_buffer& to_binding(GLenum binding) noexcept;
		const kiwi::cubemap_buffer& to_binding(GLenum binding) const noexcept;

		kiwi::cubemap_buffer& load(
			const unsigned char* const Xp_data_ptr,
			const unsigned char* const Xm_data_ptr,
			const unsigned char* const Yp_data_ptr,
			const unsigned char* const Ym_data_ptr,
			const unsigned char* const Zp_data_ptr,
			const unsigned char* const Zm_data_ptr,
			std::size_t resolution, std::size_t pixel_dimension,
			kiwi::cubemap_mapping mapping) noexcept;

		kiwi::cubemap_buffer& load(
			const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
			std::size_t resolution, std::size_t pixel_dimension,
			kiwi::cubemap_mapping mapping) noexcept;

		kiwi::cubemap_buffer& load(
			const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
			const kiwi::size& size_2d, std::size_t pixel_dimension,
			kiwi::cubemap_mapping mapping) noexcept;
	};
}

#endif // KIWI_BUFFER_CUBEMAP_HPP