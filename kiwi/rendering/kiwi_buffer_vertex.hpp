#ifndef KIWI_BUFFER_VERTEX_HPP
#define KIWI_BUFFER_VERTEX_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	class vertex_buffer
	{

	private:

		GLuint m_buffer_index;
		std::size_t m_dim;
		std::size_t m_vertex_count;
		std::size_t m_data_current_size;

	public:

		vertex_buffer() noexcept;
		vertex_buffer(const vertex_buffer&) = delete;
		vertex_buffer& operator=(const vertex_buffer&) = delete;
		vertex_buffer(vertex_buffer&& rhs) noexcept;
		vertex_buffer& operator=(vertex_buffer&& rhs) noexcept;
		~vertex_buffer();

		kiwi::vertex_buffer& new_id() noexcept;
		kiwi::vertex_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::vertex_buffer& bind() noexcept;
		const kiwi::vertex_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::vertex_buffer& load(const GLfloat* const vertex_data_ptr, std::size_t new_vertex_count, std::size_t dim) noexcept;
		kiwi::vertex_buffer& allocate(std::size_t new_vertex_count, std::size_t dim) noexcept;
		kiwi::vertex_buffer& substitute(const GLfloat* const vertex_data_ptr, std::size_t begin_float, std::size_t number_of_floats) noexcept;
		kiwi::vertex_buffer& to_location(GLuint location) noexcept;
		const kiwi::vertex_buffer& to_location(GLuint location) const noexcept;
		kiwi::vertex_buffer& to_location(GLuint location, std::size_t begin_float, std::size_t number_of_floats) noexcept;
		const kiwi::vertex_buffer& to_location(GLuint location, std::size_t begin_float, std::size_t number_of_floats) const noexcept;
		std::size_t vertex_count() const noexcept;
		std::size_t dim() const noexcept;
	};
}

#endif // KIWI_BUFFER_VERTEX_HPP