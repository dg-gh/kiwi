#include "buffers/kiwi_buffer_vertex.hpp"


kiwi::vertex_buffer::vertex_buffer() noexcept
{
	m_buffer_index = 0;
	m_dim = 0;
	m_vertex_count = 0;
	m_data_current_size = 0;
}

kiwi::vertex_buffer::vertex_buffer(kiwi::vertex_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_vertex_count = rhs.m_vertex_count;
	m_data_current_size = rhs.m_data_current_size;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_vertex_count = 0;
	rhs.m_data_current_size = 0;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::operator=(kiwi::vertex_buffer&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_vertex_count = rhs.m_vertex_count;
	m_data_current_size = rhs.m_data_current_size;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_vertex_count = 0;
	rhs.m_data_current_size = 0;

	return *this;
}

kiwi::vertex_buffer::~vertex_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}
}

kiwi::vertex_buffer& kiwi::vertex_buffer::new_id() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}
	else
	{
		delete_id();
		glGenBuffers(1, &m_buffer_index);
	}
	return *this;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
		m_buffer_index = 0;
		m_dim = 0;
		m_data_current_size = 0;
		m_vertex_count = 0;
	}
	return *this;
}

GLuint kiwi::vertex_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	return *this;
}

const kiwi::vertex_buffer& kiwi::vertex_buffer::bind() const noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	return *this;
}

void kiwi::vertex_buffer::unbind() noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

kiwi::vertex_buffer& kiwi::vertex_buffer::load(const GLfloat* const vertex_data_ptr, std::size_t new_vertex_count, std::size_t dim) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	std::size_t data_size = new_vertex_count * dim;

	if (data_size <= m_data_current_size)
	{
		glNamedBufferSubData(m_buffer_index, 0, data_size * sizeof(GLfloat), static_cast<const void* const>(vertex_data_ptr));
	}
	else
	{
		glBufferData(GL_ARRAY_BUFFER, data_size * sizeof(GLfloat), static_cast<const void* const>(vertex_data_ptr), GL_STATIC_DRAW);
		m_data_current_size = data_size;
	}

	m_dim = dim;
	m_vertex_count = new_vertex_count;
	return *this;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::allocate(std::size_t new_vertex_count, std::size_t dim) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	m_data_current_size = new_vertex_count * dim;
	glBufferData(GL_ARRAY_BUFFER, m_data_current_size * sizeof(GLfloat), nullptr, GL_STATIC_DRAW);

	m_dim = dim;
	m_vertex_count = new_vertex_count;
	return *this;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::substitute(const GLfloat* const vertex_data_ptr, std::size_t begin_float, std::size_t number_of_floats) noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	glNamedBufferSubData(m_buffer_index, static_cast<GLintptr>(begin_float) * sizeof(GLfloat),
		static_cast<GLsizeiptr>(number_of_floats) * sizeof(GLfloat), vertex_data_ptr);

	return *this;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::to_location(GLuint location) noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, static_cast<GLint>(m_dim), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(m_dim * sizeof(GLfloat)), nullptr);
	return *this;
}

const kiwi::vertex_buffer& kiwi::vertex_buffer::to_location(GLuint location) const noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, static_cast<GLint>(m_dim), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(m_dim * sizeof(GLfloat)), nullptr);
	return *this;
}

kiwi::vertex_buffer& kiwi::vertex_buffer::to_location(GLuint location, std::size_t begin_float, std::size_t number_of_floats) noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, static_cast<GLint>(number_of_floats), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(m_dim * sizeof(GLfloat)),
		reinterpret_cast<const void*>(begin_float * sizeof(GLfloat)));
	return *this;
}

const kiwi::vertex_buffer& kiwi::vertex_buffer::to_location(GLuint location, std::size_t begin_float, std::size_t number_of_floats) const noexcept
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_index);
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, static_cast<GLint>(number_of_floats), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(m_dim * sizeof(GLfloat)),
		reinterpret_cast<const void*>(begin_float * sizeof(GLfloat)));
	return *this;
}

std::size_t kiwi::vertex_buffer::vertex_count() const noexcept
{
	return m_vertex_count;
}

std::size_t kiwi::vertex_buffer::dim() const noexcept
{
	return m_dim;
}
