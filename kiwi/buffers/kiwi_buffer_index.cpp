#include "buffers/kiwi_buffer_index.hpp"


kiwi::index_buffer::index_buffer() noexcept
{
	m_buffer_index = 0;
	m_index_count = 0;
	m_current_data_size = 0;
}

kiwi::index_buffer::index_buffer(kiwi::index_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_index_count = rhs.m_index_count;
	m_current_data_size = rhs.m_current_data_size;

	rhs.m_buffer_index = 0;
	rhs.m_index_count = 0;
	rhs.m_current_data_size = 0;
}

kiwi::index_buffer& kiwi::index_buffer::operator=(kiwi::index_buffer&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_index_count = rhs.m_index_count;
	m_current_data_size = rhs.m_current_data_size;

	rhs.m_buffer_index = 0;
	rhs.m_index_count = 0;
	rhs.m_current_data_size = 0;

	return *this;
}

kiwi::index_buffer::~index_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}
}

kiwi::index_buffer& kiwi::index_buffer::new_id() noexcept
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

kiwi::index_buffer& kiwi::index_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
		m_buffer_index = 0;
		m_index_count = 0;
		m_current_data_size = 0;
	}
	return *this;
}

GLuint kiwi::index_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::index_buffer& kiwi::index_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

const kiwi::index_buffer& kiwi::index_buffer::bind() const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

void kiwi::index_buffer::unbind() noexcept
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	kiwi::context::current_buffer() = nullptr;
}

kiwi::index_buffer& kiwi::index_buffer::load(const GLuint* const index_data_ptr, std::size_t new_index_count) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_buffer() != static_cast<const void*>(this))
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_index);
			kiwi::context::current_buffer() = static_cast<const void*>(this);
		}
	}
	else
	{
		glGenBuffers(1, &m_buffer_index);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	if (new_index_count <= m_current_data_size)
	{
		glNamedBufferSubData(m_buffer_index, 0, new_index_count * sizeof(GLfloat), static_cast<const void* const>(index_data_ptr));
	}
	else
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, new_index_count * sizeof(GLuint), static_cast<const void* const>(index_data_ptr), GL_STATIC_DRAW);
		m_current_data_size = new_index_count;
	}

	m_index_count = new_index_count;
	return *this;
}

std::size_t kiwi::index_buffer::index_count() const noexcept
{
	return m_index_count;
}