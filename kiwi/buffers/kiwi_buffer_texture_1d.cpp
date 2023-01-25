#include "buffers/kiwi_buffer_texture_1d.hpp"

kiwi::texture_1d::texture_1d() noexcept
{
	m_buffer_index = 0;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::texture_1d;
	m_dim = 0;
	m_width = 0;
	m_format = kiwi::pixel_format::u8;
}

kiwi::texture_1d::texture_1d(kiwi::texture_1d&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::texture_1d;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_format = kiwi::pixel_format::u8;
}

kiwi::texture_1d& kiwi::texture_1d::operator=(kiwi::texture_1d&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_format = kiwi::pixel_format::u8;

	return *this;
}

kiwi::texture_1d::~texture_1d()
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}
}

kiwi::texture_1d& kiwi::texture_1d::new_id() noexcept
{
	if (m_buffer_index != 0)
	{
		delete_id();
	}

	glGenTextures(1, &m_buffer_index);
	return *this;
}

kiwi::texture_1d& kiwi::texture_1d::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
		m_buffer_index = 0;
		m_dim = 0;
		m_width = 0;
		m_format = kiwi::pixel_format::u8;
	}
	return *this;
}

kiwi::texture_1d& kiwi::texture_1d::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(GL_TEXTURE_1D, m_buffer_index);
	return *this;
}

const kiwi::texture_1d& kiwi::texture_1d::bind() const noexcept
{
	glBindTexture(GL_TEXTURE_1D, m_buffer_index);
	return *this;
}

void kiwi::texture_1d::unbind() noexcept
{
	glBindTexture(GL_TEXTURE_1D, 0);
}

kiwi::texture_1d& kiwi::texture_1d::load(const void* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dim, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping, kiwi::pixel_format format) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(GL_TEXTURE_1D, m_buffer_index);

	m_dim = pixel_dim;

	{
		GLint _internal_format;
		GLenum _color_format;
		GLenum _type;
		set_pixel_format(format, pixel_dim, &_internal_format, &_color_format, &_type);

		if ((size_1d <= m_width) && (m_format == format))
		{
			glTexSubImage1D(GL_TEXTURE_1D, 0, 0, static_cast<GLsizei>(size_1d), _color_format, _type, texture_data_ptr);
		}
		else
		{
			glTexImage1D(GL_TEXTURE_1D, 0, _internal_format, static_cast<GLsizei>(size_1d), 0, _color_format, _type, texture_data_ptr);
			m_format = format;
		}

		m_width = size_1d;
	}

	{
		GLint _wrapping;
		set_pixel_wrapping(wrapping, &_wrapping);

		GLint _mapping_mag;
		GLint _mapping_min;
		bool _mipmap;
		set_pixel_mapping(mapping, &_mapping_mag, &_mapping_min, &_mipmap);

		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, _wrapping);
		glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, _wrapping);

		if (_mipmap)
		{
			glGenerateMipmap(GL_TEXTURE_1D);
		}
	}

	return *this;
}

kiwi::texture_1d& kiwi::texture_1d::load_u8(const unsigned char* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u8);
}

kiwi::texture_1d& kiwi::texture_1d::load_u16(const GLushort* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u16);
}

kiwi::texture_1d& kiwi::texture_1d::load_f32(const GLfloat* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::f32);
}

kiwi::texture_1d& kiwi::texture_1d::load_u8u(const unsigned char* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u8u);
}

kiwi::texture_1d& kiwi::texture_1d::load_u16u(const GLushort* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u16u);
}

kiwi::texture_1d& kiwi::texture_1d::load_u32u(const GLuint* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u32u);
}

kiwi::texture_1d& kiwi::texture_1d::load_i8u(const char* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::i8u);
}

kiwi::texture_1d& kiwi::texture_1d::load_i16u(const GLshort* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::i16u);
}

kiwi::texture_1d& kiwi::texture_1d::load_i32u(const GLint* const texture_data_ptr, std::size_t size_1d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_1d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::i32u);
}


kiwi::texture_1d& kiwi::texture_1d::allocate(kiwi::pixel_format format, std::size_t size_1d, std::size_t pixel_dim,
	kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(GL_TEXTURE_1D, m_buffer_index);

	m_dim = pixel_dim;
	m_width = size_1d;
	m_format = format;

	GLint _internal_format;
	GLenum _color_format;
	GLenum _type;
	set_pixel_format(format, pixel_dim, &_internal_format, &_color_format, &_type);

	GLint _wrapping;
	set_pixel_wrapping(wrapping, &_wrapping);

	GLint _mapping_mag;
	GLint _mapping_min;
	bool _mipmap;
	set_pixel_mapping(mapping, &_mapping_mag, &_mapping_min, &_mipmap);

	glTexImage1D(GL_TEXTURE_1D, 0, _internal_format, static_cast<GLsizei>(m_width), 0, _color_format, _type, nullptr);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, _mapping_mag);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, _wrapping);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, _wrapping);

	return *this;
}

kiwi::texture_1d& kiwi::texture_1d::to_binding(GLenum binding) noexcept
{
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_1D, m_buffer_index);
	return *this;
}

const kiwi::texture_1d& kiwi::texture_1d::to_binding(GLenum binding) const noexcept
{
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_1D, m_buffer_index);
	return *this;
}

kiwi::texture_1d& kiwi::texture_1d::to_binding_for_compute(GLuint binding) noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, m_buffer_index, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

const kiwi::texture_1d& kiwi::texture_1d::to_binding_for_compute(GLuint binding) const noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, m_buffer_index, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

kiwi::texture_1d& kiwi::texture_1d::unbind_for_compute(GLuint binding) noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, 0, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

const kiwi::texture_1d& kiwi::texture_1d::unbind_for_compute(GLuint binding) const noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, 0, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

std::size_t kiwi::texture_1d::pixel_dim() const noexcept
{
	return m_dim;
}

std::size_t kiwi::texture_1d::width() const noexcept
{
	return m_width;
}

std::size_t kiwi::texture_1d::height() const noexcept
{
	return 1;
}

kiwi::texture_1d& kiwi::texture_1d::set_format(kiwi::pixel_format format) noexcept
{
	m_format = format;
	return *this;
}

kiwi::pixel_format kiwi::texture_1d::get_format() const noexcept
{
	return m_format;
}