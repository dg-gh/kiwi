#ifndef KIWI_BUFFER_RENDER_HPP
#define KIWI_BUFFER_RENDER_HPP

#include "context/kiwi_context.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	enum class render_buffer_type {
		f16,
		f24,
		f32,
		st8,
		f24_st8,
		f32_st8
	};

	enum class render_buffer_sampling { unique, multiple };

	class render_buffer
	{

	private:

		GLuint m_buffer_index;
		GLenum m_rbtype;
		std::size_t m_width;
		std::size_t m_height;
		kiwi::render_buffer_sampling m_sampling;

	public:

		render_buffer() noexcept;
		render_buffer(const render_buffer&) = delete;
		render_buffer& operator=(const render_buffer&) = delete;
		render_buffer(render_buffer&& rhs) noexcept;
		render_buffer& operator=(render_buffer&& rhs) noexcept;
		~render_buffer();

		kiwi::render_buffer& new_id() noexcept;
		kiwi::render_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::render_buffer& bind() noexcept;
		const kiwi::render_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::render_buffer_type buffer_type() const noexcept;

		kiwi::render_buffer& allocate(kiwi::render_buffer_type rbtype, kiwi::size size_2d) noexcept;

		kiwi::render_buffer& set_sampling(kiwi::render_buffer_sampling sampling) noexcept;
		kiwi::render_buffer_sampling get_sampling() const noexcept;
	};
}

#endif // KIWI_BUFFER_RENDER_HPP