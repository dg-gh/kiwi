#ifndef KIWI_BUFFER_UNIFORM_HPP
#define KIWI_BUFFER_UNIFORM_HPP

#include "header_utils/kiwi_glcall.hpp"
#include <cstddef>


namespace kiwi
{
	class uniform_buffer
	{

	private:

		GLuint m_buffer_index;
		std::size_t m_data_current_size;

	public:

		uniform_buffer() noexcept;
		uniform_buffer(const kiwi::uniform_buffer&) = delete;
		uniform_buffer& operator=(const kiwi::uniform_buffer&) = delete;
		uniform_buffer(kiwi::uniform_buffer&& rhs) noexcept;
		uniform_buffer& operator=(kiwi::uniform_buffer&& rhs) noexcept;
		~uniform_buffer();

		kiwi::uniform_buffer& new_id() noexcept;
		kiwi::uniform_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::uniform_buffer& bind() noexcept;
		const kiwi::uniform_buffer& bind() const noexcept;
		kiwi::uniform_buffer& to_binding(GLuint binding) noexcept;
		const kiwi::uniform_buffer& to_binding(GLuint binding) const noexcept;
		kiwi::uniform_buffer& to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) noexcept;
		const kiwi::uniform_buffer& to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) const noexcept;
		kiwi::uniform_buffer& unbind() noexcept;
		const kiwi::uniform_buffer& unbind() const noexcept;

		kiwi::uniform_buffer& allocate(std::size_t number_of_bytes) noexcept;
		kiwi::uniform_buffer& load(const void* const data_ptr, std::size_t number_of_bytes) noexcept;
		kiwi::uniform_buffer& substitute(const void* const data_ptr, std::size_t begin_byte, std::size_t number_of_bytes) noexcept;
	};
}

#endif // KIWI_BUFFER_UNIFORM_HPP