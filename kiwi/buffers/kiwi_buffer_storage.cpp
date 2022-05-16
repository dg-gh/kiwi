#include "buffers/kiwi_buffer_storage.hpp"


kiwi::storage_buffer::storage_buffer() noexcept
{
	m_buffer_index = 0;
	m_data_current_size = 0;
}

kiwi::storage_buffer::storage_buffer(kiwi::storage_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_data_current_size = rhs.m_data_current_size;

	rhs.m_buffer_index = 0;
	rhs.m_data_current_size = 0;
}

kiwi::storage_buffer& kiwi::storage_buffer::operator=(kiwi::storage_buffer&& rhs) noexcept
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

kiwi::storage_buffer::~storage_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
	}
}

kiwi::storage_buffer& kiwi::storage_buffer::new_id() noexcept
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

kiwi::storage_buffer& kiwi::storage_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteBuffers(1, &m_buffer_index);
		m_buffer_index = 0;
		m_data_current_size = 0;
	}
	return *this;
}

GLuint kiwi::storage_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::storage_buffer& kiwi::storage_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

const kiwi::storage_buffer& kiwi::storage_buffer::bind() const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

void kiwi::storage_buffer::unbind() noexcept
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
	kiwi::context::current_buffer() = nullptr;
}

kiwi::storage_buffer& kiwi::storage_buffer::load(const void* const storage_data_ptr, std::size_t number_of_bytes) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_buffer() != static_cast<const void*>(this))
		{
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
			kiwi::context::current_buffer() = static_cast<const void*>(this);
		}
	}
	else
	{
		glGenBuffers(1, &m_buffer_index);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	if (number_of_bytes <= m_data_current_size)
	{
		glNamedBufferSubData(m_buffer_index, 0, number_of_bytes, storage_data_ptr);
	}
	else
	{
		glBufferData(GL_SHADER_STORAGE_BUFFER, number_of_bytes, storage_data_ptr, GL_STATIC_DRAW);
		m_data_current_size = number_of_bytes;
	}

	return *this;
}

kiwi::storage_buffer& kiwi::storage_buffer::allocate(std::size_t number_of_bytes) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_buffer() != static_cast<const void*>(this))
		{
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
			kiwi::context::current_buffer() = static_cast<const void*>(this);
		}
	}
	else
	{
		glGenBuffers(1, &m_buffer_index);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBufferData(GL_SHADER_STORAGE_BUFFER, number_of_bytes, nullptr, GL_DYNAMIC_DRAW);
	m_data_current_size = number_of_bytes;

	return *this;
}

kiwi::storage_buffer& kiwi::storage_buffer::substitute(const void* const storage_data_ptr, std::size_t begin_byte, std::size_t number_of_bytes) noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_buffer_index);
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glNamedBufferSubData(m_buffer_index, static_cast<GLintptr>(begin_byte),
		static_cast<GLsizeiptr>(number_of_bytes), storage_data_ptr);

	return *this;
}

kiwi::storage_buffer& kiwi::storage_buffer::to_binding(GLuint binding) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, binding, m_buffer_index);
	return *this;
}

const kiwi::storage_buffer& kiwi::storage_buffer::to_binding(GLuint binding) const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, binding, m_buffer_index);
	return *this;
}

kiwi::storage_buffer& kiwi::storage_buffer::to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenBuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferRange(GL_SHADER_STORAGE_BUFFER, binding, m_buffer_index, static_cast<GLintptr>(begin_byte),
		static_cast<GLsizeiptr>(number_of_bytes));

	return *this;
}

const kiwi::storage_buffer& kiwi::storage_buffer::to_binding(GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) const noexcept
{
	if (kiwi::context::current_buffer() != static_cast<const void*>(this))
	{
		kiwi::context::current_buffer() = static_cast<const void*>(this);
	}

	glBindBufferRange(GL_SHADER_STORAGE_BUFFER, binding, m_buffer_index, static_cast<GLintptr>(begin_byte),
		static_cast<GLsizeiptr>(number_of_bytes));

	return *this;
}