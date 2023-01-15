#ifndef _KIWI_BUFFER_INDEX_HPP
#define _KIWI_BUFFER_INDEX_HPP

#include "header_utils/kiwi_glcall.hpp"
#include <cstddef>


namespace kiwi
{
	class index_buffer
	{

	private:

		GLuint m_buffer_index;
		std::size_t m_index_count;
		std::size_t m_data_current_size;

	public:

		index_buffer() noexcept;
		index_buffer(const index_buffer&) = delete;
		index_buffer& operator=(const index_buffer&) = delete;
		index_buffer(index_buffer&& rhs) noexcept;
		index_buffer& operator=(index_buffer&& rhs) noexcept;
		~index_buffer();

		kiwi::index_buffer& new_id() noexcept;
		kiwi::index_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::index_buffer& bind() noexcept;
		const kiwi::index_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::index_buffer& load(const GLuint* const index_data_ptr, std::size_t new_index_count) noexcept;
		kiwi::index_buffer& allocate(std::size_t new_index_count) noexcept;
		kiwi::index_buffer& substitute(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t number_of_indices) noexcept;
		std::size_t index_count() const noexcept;
	};
}

#endif // _KIWI_BUFFER_INDEX_HPP