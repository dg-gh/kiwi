#include "buffers/kiwi_buffer_texture_2d_array.hpp"
#include "header_utils/kiwi_glcall.hpp"

kiwi::texture_2d_array::texture_2d_array() noexcept
{
	m_buffer_index = 0;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::texture_2d;
	m_dim = 0;
	m_width = 0;
	m_height = 0;
	m_layer_count = 0;
	m_format = kiwi::pixel_format::u8;
}

kiwi::texture_2d_array::texture_2d_array(kiwi::texture_2d_array&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::texture_2d;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_layer_count = rhs.m_layer_count;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_layer_count = 0;
	rhs.m_format = kiwi::pixel_format::u8;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::operator=(kiwi::texture_2d_array&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		_KIWI_GLCALL(glDeleteTextures(1, &m_buffer_index));
	}

	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_layer_count = rhs.m_layer_count;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_layer_count = 0;
	rhs.m_format = kiwi::pixel_format::u8;

	return *this;
}

kiwi::texture_2d_array::~texture_2d_array()
{
	if (m_buffer_index != 0)
	{
		_KIWI_GLCALL(glDeleteTextures(1, &m_buffer_index));
	}
}

kiwi::texture_2d_array& kiwi::texture_2d_array::new_id() noexcept
{
	if (m_buffer_index != 0)
	{
		delete_id();
	}

	_KIWI_GLCALL(glGenTextures(1, &m_buffer_index));
	return *this;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		_KIWI_GLCALL(glDeleteTextures(1, &m_buffer_index));
		m_buffer_index = 0;
		m_dim = 0;
		m_width = 0;
		m_height = 0;
		m_layer_count = 0;
		m_format = kiwi::pixel_format::u8;
	}
	return *this;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));
	return *this;
}

const kiwi::texture_2d_array& kiwi::texture_2d_array::bind() const noexcept
{
	_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));
	return *this;
}

void kiwi::texture_2d_array::unbind() noexcept
{
	_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, 0));
}

kiwi::texture_2d_array& kiwi::texture_2d_array::allocate(kiwi::pixel_format format, kiwi::size size_2d,
	std::size_t layer_count, std::size_t pixel_dim,
	kiwi::pixel_mapping mapping, kiwi::pixel_wrapping wrapping) noexcept
{
	if (m_buffer_index == 0)
	{
		_KIWI_GLCALL(glGenTextures(1, &m_buffer_index));
	}

	_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));

	{
		GLint _internal_format;
		set_pixel_format(format, pixel_dim, &_internal_format);

		_KIWI_GLCALL(glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, _internal_format, static_cast<GLsizei>(size_2d[0]),
			static_cast<GLsizei>(size_2d[1]), static_cast<GLsizei>(layer_count)));
		m_format = format;
		m_dim = pixel_dim;
		m_width = size_2d[0];
		m_height = size_2d[1];
		m_layer_count = layer_count;
	}

	{
		GLint _wrapping;
		set_pixel_wrapping(wrapping, &_wrapping);

		GLint _mapping_mag;
		GLint _mapping_min;
		bool _mipmap;
		set_pixel_mapping(mapping, &_mapping_mag, &_mapping_min, &_mipmap);

		_KIWI_GLCALL(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, _mapping_mag));
		_KIWI_GLCALL(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, _mapping_min));
		_KIWI_GLCALL(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, _wrapping));
		_KIWI_GLCALL(glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, _wrapping));

		if (_mipmap)
		{
			_KIWI_GLCALL(glGenerateMipmap(GL_TEXTURE_2D_ARRAY));
		}
	}

	return *this;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::load(const void* const texture_array_data_ptr) noexcept
{
	if (m_buffer_index != 0)
	{
		_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));

		{
			GLint _internal_format;
			GLenum _color_format;
			GLenum _type;
			set_pixel_format(m_format, m_dim, &_internal_format, &_color_format, &_type);

			_KIWI_GLCALL(glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0,
				static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), static_cast<GLsizei>(m_layer_count),
				_color_format, _type, texture_array_data_ptr));
		}
	}

	return *this;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::load(const void* const texture_array_data_ptr,
	std::size_t layer_count) noexcept
{
	if (m_buffer_index != 0 && layer_count <= m_layer_count)
	{
		_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));

		{
			GLint _internal_format;
			GLenum _color_format;
			GLenum _type;
			set_pixel_format(m_format, m_dim, &_internal_format, &_color_format, &_type);

			_KIWI_GLCALL(glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0,
				static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), static_cast<GLsizei>(layer_count),
				_color_format, _type, texture_array_data_ptr));
		}
	}

	return *this;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::load(const void* const texture_array_data_ptr,
	std::size_t first_layer, std::size_t layer_count) noexcept
{
	if (m_buffer_index != 0 && first_layer + layer_count <= m_layer_count)
	{
		_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));
		
		{
			GLint _internal_format;
			GLenum _color_format;
			GLenum _type;
			set_pixel_format(m_format, m_dim, &_internal_format, &_color_format, &_type);

			_KIWI_GLCALL(glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, static_cast<GLint>(first_layer),
				static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), static_cast<GLsizei>(layer_count),
				_color_format, _type, texture_array_data_ptr));
		}
	}

	return *this;
}

kiwi::texture_2d_array& kiwi::texture_2d_array::to_binding(GLenum binding) noexcept
{
	_KIWI_GLCALL(glActiveTexture(GL_TEXTURE0 + binding));
	_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));
	return *this;
}

const kiwi::texture_2d_array& kiwi::texture_2d_array::to_binding(GLenum binding) const noexcept
{
	_KIWI_GLCALL(glActiveTexture(GL_TEXTURE0 + binding));
	_KIWI_GLCALL(glBindTexture(GL_TEXTURE_2D_ARRAY, m_buffer_index));
	return *this;
}

std::size_t kiwi::texture_2d_array::pixel_dim() const noexcept
{
	return m_dim;
}

std::size_t kiwi::texture_2d_array::width() const noexcept
{
	return m_width;
}

std::size_t kiwi::texture_2d_array::height() const noexcept
{
	return m_height;
}

std::size_t kiwi::texture_2d_array::layer_count() const noexcept
{
	return m_layer_count;
}