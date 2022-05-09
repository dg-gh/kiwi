#ifndef KIWI_BUFFER_INDEX_HPP
#define KIWI_BUFFER_INDEX_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	class index_buffer
	{

	private:

		GLuint m_buffer_index;
		std::size_t m_index_count;
		std::size_t m_current_data_size;

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
		kiwi::index_buffer& unbind() noexcept;
		const kiwi::index_buffer& unbind() const noexcept;

		kiwi::index_buffer& load(const GLuint* const index_data_ptr, std::size_t new_index_count) noexcept;
		std::size_t index_count() const noexcept;
	};
}

#endif // KIWI_BUFFER_INDEX_HPP