#ifndef _KIWI_BUFFER_STORAGE_HPP
#define _KIWI_BUFFER_STORAGE_HPP

#include "header_utils/kiwi_glcall.hpp"
#include <cstddef>


namespace kiwi
{
	class storage_buffer
	{

	private:

		GLuint m_buffer_index;
		std::size_t m_data_current_size;

	public:

		storage_buffer() noexcept;
		storage_buffer(const storage_buffer&) = delete;
		storage_buffer& operator=(const storage_buffer&) = delete;
		storage_buffer(storage_buffer&& rhs) noexcept;
		storage_buffer& operator=(storage_buffer&& rhs) noexcept;
		~storage_buffer();

		kiwi::storage_buffer& new_id() noexcept;
		kiwi::storage_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::storage_buffer& bind() noexcept;
		const kiwi::storage_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::storage_buffer& load(const void* const storage_data_ptr, std::size_t number_of_bytes) noexcept;
		kiwi::storage_buffer& allocate(std::size_t number_of_bytes) noexcept;
		kiwi::storage_buffer& substitute(const void* const storage_data_ptr, std::size_t begin_byte, std::size_t number_of_bytes) noexcept;
		kiwi::storage_buffer& to_binding(GLuint binding) noexcept;
		const kiwi::storage_buffer& to_binding(GLuint binding) const noexcept;
		kiwi::storage_buffer& to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) noexcept;
		const kiwi::storage_buffer& to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) const noexcept;
	};
}

#endif // _KIWI_BUFFER_STORAGE_HPP