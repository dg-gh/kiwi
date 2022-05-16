#include "buffers/kiwi_buffer_uniform.hpp"


kiwi::uniform_buffer::uniform_buffer() noexcept
{
	m_buffer_index = 0;
	m_data_current_size = 0;
}

kiwi::uniform_buffer::uniform_buffer(kiwi::uniform_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_data_current_size = rhs.m_data_current_size;

	rhs.m_buffer_index = 0;
	rhs.m_data_current_size = 0;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::operator=(kiwi::uniform_buffer&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_data_current_size = rhs.m_data_current_size;

	rhs.m_buffer_index = 0;
	rhs.m_data_current_size = 0;

	return *this;
}

kiwi::uniform_buffer::~uniform_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}
}


kiwi::uniform_buffer& kiwi::uniform_buffer::new_id() noexcept
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

kiwi::uniform_buffer& kiwi::uniform_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
		m_buffer_index = 0;
	}
	return *this;
}

GLuint kiwi::uniform_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

const kiwi::uniform_buffer& kiwi::uniform_buffer::bind() const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::allocate(std::size_t number_of_bytes) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBufferData(GL_UNIFORM_BUFFER, number_of_bytes, nullptr, GL_STATIC_DRAW);

	return *this;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::load(const void* const data_ptr, std::size_t number_of_bytes) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_buffer() != static_cast<const void*>(this))
		{
			glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_index);
			kiwi::context::current_buffer() = static_cast<const void*>(this);
		}
	}
	else
	{
		glGenBuffers(1, &m_buffer_index);
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	if (number_of_bytes <= m_data_current_size)
	{
		glNamedBufferSubData(m_buffer_index, 0, number_of_bytes, data_ptr);
	}
	else
	{
		glBufferData(GL_UNIFORM_BUFFER, number_of_bytes, data_ptr, GL_STATIC_DRAW);
		m_data_current_size = number_of_bytes;
	}

	return *this;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::substitute(const void* const data_ptr, std::size_t begin_byte, std::size_t number_of_bytes) noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBufferSubData(GL_UNIFORM_BUFFER, static_cast<GLintptr>(begin_byte), static_cast<GLintptr>(number_of_bytes), data_ptr);
	return *this;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::to_binding(GLuint binding) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_buffer_index);
	return *this;
}

const kiwi::uniform_buffer& kiwi::uniform_buffer::to_binding(GLuint binding) const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_buffer_index);
	return *this;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferRange(GL_UNIFORM_BUFFER, binding, m_buffer_index, static_cast<GLintptr>(begin_byte),
		static_cast<GLsizeiptr>(number_of_bytes));

	return *this;
}

const kiwi::uniform_buffer& kiwi::uniform_buffer::to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferRange(GL_UNIFORM_BUFFER, binding, m_buffer_index, static_cast<GLintptr>(begin_byte),
		static_cast<GLsizeiptr>(number_of_bytes));

	return *this;
}

kiwi::uniform_buffer& kiwi::uniform_buffer::unbind() noexcept
{
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	kiwi::context::current_buffer() = nullptr;
	return *this;
}

const kiwi::uniform_buffer& kiwi::uniform_buffer::unbind() const noexcept
{
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	kiwi::context::current_buffer() = nullptr;
	return *this;
}