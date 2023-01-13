#include "buffers/kiwi_buffer_texture_2d.hpp"

kiwi::texture_2d::texture_2d() noexcept
{
	m_buffer_index = 0;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::texture_2d;
	m_dim = 0;
	m_width = 0;
	m_height = 0;
	m_format = kiwi::pixel_format::u8;
	m_sampling = GL_TEXTURE_2D;
}

kiwi::texture_2d::texture_2d(kiwi::texture_2d&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::texture_2d;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_format = rhs.m_format;
	m_sampling = rhs.m_sampling;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_format = kiwi::pixel_format::u8;
	rhs.m_sampling = GL_TEXTURE_2D;
}

kiwi::texture_2d& kiwi::texture_2d::operator=(kiwi::texture_2d&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_format = rhs.m_format;
	m_sampling = rhs.m_sampling;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_format = kiwi::pixel_format::u8;
	rhs.m_sampling = GL_TEXTURE_2D;

	return *this;
}

kiwi::texture_2d::~texture_2d()
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}
}

kiwi::texture_2d& kiwi::texture_2d::new_id() noexcept
{
	if (m_buffer_index != 0)
	{
		delete_id();
	}

	glGenTextures(1, &m_buffer_index);
	return *this;
}

kiwi::texture_2d& kiwi::texture_2d::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
		m_buffer_index = 0;
		m_dim = 0;
		m_width = 0;
		m_height = 0;
		m_format = kiwi::pixel_format::u8;
	}
	return *this;
}

kiwi::texture_2d& kiwi::texture_2d::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(m_sampling, m_buffer_index);
	return *this;
}

const kiwi::texture_2d& kiwi::texture_2d::bind() const noexcept
{
	glBindTexture(m_sampling, m_buffer_index);
	return *this;
}

void kiwi::texture_2d::unbind() noexcept
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

kiwi::texture_2d& kiwi::texture_2d::load(const void* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dim, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping, kiwi::pixel_format format) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(GL_TEXTURE_2D, m_buffer_index);

	m_dim = pixel_dim;
	m_sampling = GL_TEXTURE_2D;

	{
		GLint _internal_format;
		GLenum _color_format;
		GLenum _type;
		set_pixel_format(format, pixel_dim, &_internal_format, &_color_format, &_type);

		if ((size_2d[0] * size_2d[1] <= m_width * m_height) && (m_format == format))
		{
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), _color_format, _type, texture_data_ptr);
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, _type, texture_data_ptr);
			m_format = format;
		}

		m_width = size_2d[0];
		m_height = size_2d[1];
	}

	{
		GLint _wrapping;
		set_pixel_wrapping(wrapping, &_wrapping);

		GLint _mapping_mag;
		GLint _mapping_min;
		bool _mipmap;
		set_pixel_mapping(mapping, &_mapping_mag, &_mapping_min, &_mipmap);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wrapping);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wrapping);

		if (_mipmap)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}

	return *this;
}

kiwi::texture_2d& kiwi::texture_2d::load_u8(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u8);
}

kiwi::texture_2d& kiwi::texture_2d::load_u16(const GLushort* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u16);
}

kiwi::texture_2d& kiwi::texture_2d::load_f32(const GLfloat* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::f32);
}

kiwi::texture_2d& kiwi::texture_2d::load_u8u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u8u);
}

kiwi::texture_2d& kiwi::texture_2d::load_u16u(const GLushort* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u16u);
}

kiwi::texture_2d& kiwi::texture_2d::load_u32u(const GLuint* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::u32u);
}

kiwi::texture_2d& kiwi::texture_2d::load_i8u(const char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::i8u);
}

kiwi::texture_2d& kiwi::texture_2d::load_i16u(const GLshort* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::i16u);
}

kiwi::texture_2d& kiwi::texture_2d::load_i32u(const GLint* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	return load(static_cast<const void* const>(texture_data_ptr), size_2d, pixel_dimension, mapping, wrapping, kiwi::pixel_format::i32u);
}


kiwi::texture_2d& kiwi::texture_2d::allocate(kiwi::pixel_format format, kiwi::size size_2d, std::size_t pixel_dim,
	kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(m_sampling, m_buffer_index);

	m_dim = pixel_dim;
	m_width = size_2d[0];
	m_height = size_2d[1];
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

	switch (m_sampling)
	{

	case GL_TEXTURE_2D:
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, _type, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wrapping);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wrapping);
	}
	break;

	case GL_TEXTURE_2D_MULTISAMPLE:
	{
		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, _color_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), GL_TRUE);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_S, _wrapping);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_T, _wrapping);
	}
	break;

	default:
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, _type, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wrapping);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wrapping);
	}
	break;
	}

	if (_mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_2d& kiwi::texture_2d::to_binding(GLenum binding) noexcept
{
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_2D, m_buffer_index);
	return *this;
}

const kiwi::texture_2d& kiwi::texture_2d::to_binding(GLenum binding) const noexcept
{
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_2D, m_buffer_index);
	return *this;
}

kiwi::texture_2d& kiwi::texture_2d::to_binding_for_compute(GLuint binding) noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, m_buffer_index, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

const kiwi::texture_2d& kiwi::texture_2d::to_binding_for_compute(GLuint binding) const noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, m_buffer_index, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

kiwi::texture_2d& kiwi::texture_2d::unbind_for_compute(GLuint binding) noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, 0, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

const kiwi::texture_2d& kiwi::texture_2d::unbind_for_compute(GLuint binding) const noexcept
{
	GLint _internal_format;
	set_pixel_format(m_format, m_dim, &_internal_format);
	glBindImageTexture(binding, 0, 0, GL_FALSE, 0, GL_READ_WRITE, _internal_format);
	return *this;
}

std::size_t kiwi::texture_2d::pixel_dim() const noexcept
{
	return m_dim;
}

std::size_t kiwi::texture_2d::width() const noexcept
{
	return m_width;
}

std::size_t kiwi::texture_2d::height() const noexcept
{
	return m_height;
}

kiwi::texture_2d& kiwi::texture_2d::set_format(kiwi::pixel_format format) noexcept
{
	m_format = format;
	return *this;
}

kiwi::pixel_format kiwi::texture_2d::get_format() const noexcept
{
	return m_format;
}

kiwi::texture_2d& kiwi::texture_2d::set_sampling(kiwi::texture_sampling sampling) noexcept
{
	switch (sampling)
	{
	case kiwi::texture_sampling::unique: m_sampling = GL_TEXTURE_2D; break;
	case kiwi::texture_sampling::multiple: m_sampling = GL_TEXTURE_2D_MULTISAMPLE; break;
	}

	return *this;
}

kiwi::texture_sampling kiwi::texture_2d::get_sampling() const noexcept
{
	switch (m_sampling)
	{
	case GL_TEXTURE_2D: return kiwi::texture_sampling::unique; break;
	case GL_TEXTURE_2D_MULTISAMPLE: return kiwi::texture_sampling::multiple; break;
	default: return kiwi::texture_sampling::unique; break;
	}
}