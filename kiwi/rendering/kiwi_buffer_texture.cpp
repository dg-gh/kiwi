#include "rendering/kiwi_buffer_texture.hpp"

kiwi::texture_buffer::texture_buffer() noexcept
{
	m_buffer_index = 0;
	m_current_size = 0;
	m_dim = 0;
	m_width = 0;
	m_height = 0;
	m_format = kiwi::texture_format::u8;
	m_sampling = GL_TEXTURE_2D;
}

kiwi::texture_buffer::texture_buffer(kiwi::texture_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_current_size = rhs.m_current_size;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_format = rhs.m_format;
	m_sampling = rhs.m_sampling;

	rhs.m_buffer_index = 0;
	rhs.m_current_size = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_format = kiwi::texture_format::u8;
	rhs.m_sampling = GL_TEXTURE_2D;
}

kiwi::texture_buffer& kiwi::texture_buffer::operator=(kiwi::texture_buffer&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_current_size = rhs.m_current_size;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_format = rhs.m_format;
	m_sampling = rhs.m_sampling;

	rhs.m_buffer_index = 0;
	rhs.m_current_size = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_format = kiwi::texture_format::u8;
	rhs.m_sampling = GL_TEXTURE_2D;

	return *this;
}

kiwi::texture_buffer::~texture_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}
}

kiwi::texture_buffer& kiwi::texture_buffer::new_id() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}
	else
	{
		delete_id();
		glGenTextures(1, &m_buffer_index);
	}
	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
		m_buffer_index = 0;
		m_current_size = 0;
		m_dim = 0;
		m_width = 0;
		m_height = 0;
		m_format = kiwi::texture_format::u8;
	}
	return *this;
}

GLuint kiwi::texture_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::texture_buffer& kiwi::texture_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
	{
		glBindTexture(m_sampling, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}
	return *this;
}

const kiwi::texture_buffer& kiwi::texture_buffer::bind() const noexcept
{
	if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
	{
		glBindTexture(m_sampling, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

void kiwi::texture_buffer::unbind() noexcept
{
	glBindTexture(GL_TEXTURE_2D, 0);
	kiwi::context::current_texture_buffer() = nullptr;
}

kiwi::texture_buffer& kiwi::texture_buffer::load(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED; _internal_format = GL_R8; break;
	case 2: _color_format = GL_RG; _internal_format = GL_RG8; break;
	case 3: _color_format = GL_RGB; _internal_format = GL_RGB8; break;
	case 4: _color_format = GL_RGBA; _internal_format = GL_RGBA8; break;
	default: _color_format = GL_RED; _internal_format = GL_R8; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::u8))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_UNSIGNED_BYTE, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::u8;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_u8(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED; _internal_format = GL_R8; break;
	case 2: _color_format = GL_RG; _internal_format = GL_RG8; break;
	case 3: _color_format = GL_RGB; _internal_format = GL_RGB8; break;
	case 4: _color_format = GL_RGBA; _internal_format = GL_RGBA8; break;
	default: _color_format = GL_RED; _internal_format = GL_R8; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::u8))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_UNSIGNED_BYTE, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::u8;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_u16(const GLushort* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED; _internal_format = GL_R16; break;
	case 2: _color_format = GL_RG; _internal_format = GL_RG16; break;
	case 3: _color_format = GL_RGB; _internal_format = GL_RGB16; break;
	case 4: _color_format = GL_RGBA; _internal_format = GL_RGBA16; break;
	default: _color_format = GL_RED; _internal_format = GL_R16; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::u16))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_UNSIGNED_SHORT, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_UNSIGNED_SHORT, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::u16;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_f32(const GLfloat* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED; _internal_format = GL_R32F; break;
	case 2: _color_format = GL_RG; _internal_format = GL_RG32F; break;
	case 3: _color_format = GL_RGB; _internal_format = GL_RGB32F; break;
	case 4: _color_format = GL_RGBA; _internal_format = GL_RGBA32F; break;
	default: _color_format = GL_RED; _internal_format = GL_R32F; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::f32))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_FLOAT, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_FLOAT, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::f32;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}


kiwi::texture_buffer& kiwi::texture_buffer::load_u8u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED_INTEGER; _internal_format = GL_R8UI; break;
	case 2: _color_format = GL_RG_INTEGER; _internal_format = GL_RG8UI; break;
	case 3: _color_format = GL_RGB_INTEGER; _internal_format = GL_RGB8UI; break;
	case 4: _color_format = GL_RGBA_INTEGER; _internal_format = GL_RGBA8UI; break;
	default: _color_format = GL_RED_INTEGER; _internal_format = GL_R8UI; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::u8u))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_UNSIGNED_BYTE, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::u8u;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_u16u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED_INTEGER; _internal_format = GL_R16UI; break;
	case 2: _color_format = GL_RG_INTEGER; _internal_format = GL_RG16UI; break;
	case 3: _color_format = GL_RGB_INTEGER; _internal_format = GL_RGB16UI; break;
	case 4: _color_format = GL_RGBA_INTEGER; _internal_format = GL_RGBA16UI; break;
	default: _color_format = GL_RED_INTEGER; _internal_format = GL_R16UI; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::u16u))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_UNSIGNED_SHORT, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_UNSIGNED_SHORT, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::u16u;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_u32u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED_INTEGER; _internal_format = GL_R32UI; break;
	case 2: _color_format = GL_RG_INTEGER; _internal_format = GL_RG32UI; break;
	case 3: _color_format = GL_RGB_INTEGER; _internal_format = GL_RGB32UI; break;
	case 4: _color_format = GL_RGBA_INTEGER; _internal_format = GL_RGBA32UI; break;
	default: _color_format = GL_RED_INTEGER; _internal_format = GL_R32UI; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::u32u))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_UNSIGNED_INT, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_UNSIGNED_INT, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::u32u;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}


kiwi::texture_buffer& kiwi::texture_buffer::load_i8u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED_INTEGER; _internal_format = GL_R8I; break;
	case 2: _color_format = GL_RG_INTEGER; _internal_format = GL_RG8I; break;
	case 3: _color_format = GL_RGB_INTEGER; _internal_format = GL_RGB8I; break;
	case 4: _color_format = GL_RGBA_INTEGER; _internal_format = GL_RGBA8I; break;
	default: _color_format = GL_RED_INTEGER; _internal_format = GL_R8I; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::i8u))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_BYTE, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_BYTE, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::i8u;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_i16u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED_INTEGER; _internal_format = GL_R16I; break;
	case 2: _color_format = GL_RG_INTEGER; _internal_format = GL_RG16I; break;
	case 3: _color_format = GL_RGB_INTEGER; _internal_format = GL_RGB16I; break;
	case 4: _color_format = GL_RGBA_INTEGER; _internal_format = GL_RGBA16I; break;
	default: _color_format = GL_RED_INTEGER; _internal_format = GL_R16I; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::i16u))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_SHORT, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_SHORT, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::i16u;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::load_i32u(const unsigned char* const texture_data_ptr, kiwi::size size_2d,
	std::size_t pixel_dimension, kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(GL_TEXTURE_2D, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLint _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	switch (pixel_dimension)
	{
	case 1: _color_format = GL_RED_INTEGER; _internal_format = GL_R32I; break;
	case 2: _color_format = GL_RG_INTEGER; _internal_format = GL_RG32I; break;
	case 3: _color_format = GL_RGB_INTEGER; _internal_format = GL_RGB32I; break;
	case 4: _color_format = GL_RGBA_INTEGER; _internal_format = GL_RGBA32I; break;
	default: _color_format = GL_RED_INTEGER; _internal_format = GL_R32I; break;
	}

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::texture_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	if ((_size <= m_current_size) && (m_format == kiwi::texture_format::i32u))
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), _color_format, GL_INT, texture_data_ptr);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, GL_INT, texture_data_ptr);
		m_current_size = _size;
		m_format = kiwi::texture_format::i32u;
	}

	m_sampling = GL_TEXTURE_2D;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}


kiwi::texture_buffer& kiwi::texture_buffer::allocate(kiwi::texture_format format, kiwi::size size_2d, std::size_t pixel_dimension,
	kiwi::texture_mapping mapping, kiwi::texture_borders borders) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
		{
			glBindTexture(m_sampling, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<void*>(this);
		}
	}
	else
	{
		glGenTextures(1, &m_buffer_index);
		glBindTexture(m_sampling, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}

	m_dim = pixel_dimension;
	m_width = size_2d[0];
	m_height = size_2d[1];
	m_format = format;

	GLsizei _size = static_cast<GLsizei>(m_width * m_height);
	GLenum _type;
	GLenum _color_format;
	GLint _internal_format;
	GLint _mapping;
	GLint _mapping_min;
	GLint _borders;
	bool mipmap = false;

	p_format(m_format, pixel_dimension, &_type, &_color_format, &_internal_format);

	switch (mapping)
	{
	case kiwi::texture_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::texture_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::texture_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; break;
	case kiwi::texture_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; break;
	}

	switch (borders)
	{
	case kiwi::texture_borders::repeat: _borders = GL_REPEAT; break;
	case kiwi::texture_borders::repeat_mirrored: _borders = GL_MIRRORED_REPEAT; break;
	case kiwi::texture_borders::clamp: _borders = GL_CLAMP_TO_EDGE; break;
	case kiwi::texture_borders::pad: _borders = GL_CLAMP_TO_BORDER; break;
	}

	switch (m_sampling)
	{

	case GL_TEXTURE_2D:
		glTexImage2D(GL_TEXTURE_2D, 0, _internal_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, _color_format, _type, nullptr);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mapping);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _borders);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _borders);
		break;

	case GL_TEXTURE_2D_MULTISAMPLE:
		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, _color_format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), GL_TRUE);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MAG_FILTER, _mapping);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_S, _borders);
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_WRAP_T, _borders);
		break;
	}

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	m_current_size = _size;

	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::to_binding(GLenum binding) noexcept
{
	if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
	{
		glActiveTexture(GL_TEXTURE0 + binding);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

const kiwi::texture_buffer& kiwi::texture_buffer::to_binding(GLenum binding) const noexcept
{
	if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
	{
		glActiveTexture(GL_TEXTURE0 + binding);
		glBindTexture(GL_TEXTURE_2D, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::to_binding_for_compute(GLuint binding) noexcept
{
	glBindImageTexture(binding, m_buffer_index, 0, GL_FALSE, 0, GL_READ_WRITE, p_internal_format(m_format, m_dim));
	return *this;
}

const kiwi::texture_buffer& kiwi::texture_buffer::to_binding_for_compute(GLuint binding) const noexcept
{
	glBindImageTexture(binding, m_buffer_index, 0, GL_FALSE, 0, GL_READ_WRITE, p_internal_format(m_format, m_dim));
	return *this;
}

kiwi::texture_buffer& kiwi::texture_buffer::unbind_for_compute(GLuint binding) noexcept
{
	glBindImageTexture(binding, 0, 0, GL_FALSE, 0, GL_READ_WRITE, p_internal_format(m_format, m_dim));
	return *this;
}

const kiwi::texture_buffer& kiwi::texture_buffer::unbind_for_compute(GLuint binding) const noexcept
{
	glBindImageTexture(binding, 0, 0, GL_FALSE, 0, GL_READ_WRITE, p_internal_format(m_format, m_dim));
	return *this;
}

std::size_t kiwi::texture_buffer::pixel_dim() const noexcept
{
	return m_dim;
}

std::size_t kiwi::texture_buffer::width() const noexcept
{
	return m_width;
}

std::size_t kiwi::texture_buffer::height() const noexcept
{
	return m_height;
}

kiwi::texture_buffer& kiwi::texture_buffer::set_format(kiwi::texture_format format) noexcept
{
	m_format = format;
	return *this;
}

kiwi::texture_format kiwi::texture_buffer::get_format() const noexcept
{
	return m_format;
}

kiwi::texture_buffer& kiwi::texture_buffer::set_sampling(kiwi::texture_sampling sampling) noexcept
{
	switch (sampling)
	{
	case kiwi::texture_sampling::unique: m_sampling = GL_TEXTURE_2D; break;
	case kiwi::texture_sampling::multiple: m_sampling = GL_TEXTURE_2D_MULTISAMPLE; break;
	}

	return *this;
}

kiwi::texture_sampling kiwi::texture_buffer::get_sampling() const noexcept
{
	switch (m_sampling)
	{
	case GL_TEXTURE_2D: return kiwi::texture_sampling::unique; break;
	case GL_TEXTURE_2D_MULTISAMPLE: return kiwi::texture_sampling::multiple; break;
	default: return kiwi::texture_sampling::unique; break;
	}
}

void kiwi::texture_buffer::p_format(kiwi::texture_format format, std::size_t pixel_dimension,
	GLenum* type_ptr, GLenum* color_format_ptr, GLint* internal_format_ptr) const noexcept
{
	switch (pixel_dimension)
	{
	case 1:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16: *internal_format_ptr = GL_R16; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::f16: *internal_format_ptr = GL_R16F; *color_format_ptr = GL_RED; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::texture_format::f32: *internal_format_ptr = GL_R32F; *color_format_ptr = GL_RED; *type_ptr = GL_FLOAT; break;
		case kiwi::texture_format::u8u: *internal_format_ptr = GL_R8UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16u: *internal_format_ptr = GL_R16UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::u32u: *internal_format_ptr = GL_R32UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::texture_format::i8u: *internal_format_ptr = GL_R8I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::texture_format::i16u: *internal_format_ptr = GL_R16I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::texture_format::i32u: *internal_format_ptr = GL_R32I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::texture_format::depth: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;
		}
		break;
	}

	case 2:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: *internal_format_ptr = GL_RG8; *color_format_ptr = GL_RG; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16: *internal_format_ptr = GL_RG16; *color_format_ptr = GL_RG; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::f16: *internal_format_ptr = GL_RG16F; *color_format_ptr = GL_RG; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::texture_format::f32: *internal_format_ptr = GL_RG32F; *color_format_ptr = GL_RG; *type_ptr = GL_FLOAT; break;
		case kiwi::texture_format::u8u: *internal_format_ptr = GL_RG8UI; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16u: *internal_format_ptr = GL_RG16UI; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::u32u: *internal_format_ptr = GL_RG32UI; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::texture_format::i8u: *internal_format_ptr = GL_RG8I; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::texture_format::i16u: *internal_format_ptr = GL_RG16I; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::texture_format::i32u: *internal_format_ptr = GL_RG32I; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::texture_format::depth: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;
		}
		break;
	}

	case 3:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: *internal_format_ptr = GL_RGB8; *color_format_ptr = GL_RGB; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16: *internal_format_ptr = GL_RGB16; *color_format_ptr = GL_RGB; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::f16: *internal_format_ptr = GL_RGB16F; *color_format_ptr = GL_RGB; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::texture_format::f32: *internal_format_ptr = GL_RGB32F; *color_format_ptr = GL_RGB; *type_ptr = GL_FLOAT; break;
		case kiwi::texture_format::u8u: *internal_format_ptr = GL_RGB8UI; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16u: *internal_format_ptr = GL_RGB16UI; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::u32u: *internal_format_ptr = GL_RGB32UI; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::texture_format::i8u: *internal_format_ptr = GL_RGB8I; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::texture_format::i16u: *internal_format_ptr = GL_RGB16I; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::texture_format::i32u: *internal_format_ptr = GL_RGB32I; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::texture_format::depth: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;
		}
		break;
	}

	case 4:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: *internal_format_ptr = GL_RGBA8; *color_format_ptr = GL_RGBA; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16: *internal_format_ptr = GL_RGBA16; *color_format_ptr = GL_RGBA; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::f16: *internal_format_ptr = GL_RGBA16F; *color_format_ptr = GL_RGBA; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::texture_format::f32: *internal_format_ptr = GL_RGBA32F; *color_format_ptr = GL_RGBA; *type_ptr = GL_FLOAT; break;
		case kiwi::texture_format::u8u: *internal_format_ptr = GL_RGBA8UI; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16u: *internal_format_ptr = GL_RGBA16UI; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::u32u: *internal_format_ptr = GL_RGBA32UI; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::texture_format::i8u: *internal_format_ptr = GL_RGBA8I; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::texture_format::i16u: *internal_format_ptr = GL_RGBA16I; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::texture_format::i32u: *internal_format_ptr = GL_RGBA32I; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::texture_format::depth: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;
		}
		break;
	}

	default:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16: *internal_format_ptr = GL_R16; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::f16: *internal_format_ptr = GL_R16F; *color_format_ptr = GL_RED; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::texture_format::f32: *internal_format_ptr = GL_R32F; *color_format_ptr = GL_RED; *type_ptr = GL_FLOAT; break;
		case kiwi::texture_format::u8u: *internal_format_ptr = GL_R8UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::texture_format::u16u: *internal_format_ptr = GL_R16UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::texture_format::u32u: *internal_format_ptr = GL_R32UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::texture_format::i8u: *internal_format_ptr = GL_R8I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::texture_format::i16u: *internal_format_ptr = GL_R16I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::texture_format::i32u: *internal_format_ptr = GL_R32I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::texture_format::depth: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;
		}
		break;
	}

	}
}

GLint kiwi::texture_buffer::p_internal_format(kiwi::texture_format format, std::size_t pixel_dimension) const noexcept
{
	switch (pixel_dimension)
	{
	case 1:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: return GL_R8;
		case kiwi::texture_format::u16: return GL_R16;
		case kiwi::texture_format::f16: return GL_R16F;
		case kiwi::texture_format::f32: return GL_R32F;
		case kiwi::texture_format::u8u: return GL_R8UI;
		case kiwi::texture_format::u16u: return GL_R16UI;
		case kiwi::texture_format::u32u: return GL_R32UI;
		case kiwi::texture_format::i8u: return GL_R8I;
		case kiwi::texture_format::i16u: return GL_R16I;
		case kiwi::texture_format::i32u: return GL_R32I;
		case kiwi::texture_format::depth: return GL_DEPTH_COMPONENT;
		}
		break;
	}

	case 2:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: return GL_RG8;
		case kiwi::texture_format::u16: return GL_RG16;
		case kiwi::texture_format::f16: return GL_RG16F;
		case kiwi::texture_format::f32: return GL_RG32F;
		case kiwi::texture_format::u8u: return GL_RG8UI;
		case kiwi::texture_format::u16u: return GL_RG16UI;
		case kiwi::texture_format::u32u: return GL_RG32UI;
		case kiwi::texture_format::i8u: return GL_RG8I;
		case kiwi::texture_format::i16u: return GL_RG16I;
		case kiwi::texture_format::i32u: return GL_RG32I;
		case kiwi::texture_format::depth: return GL_DEPTH_COMPONENT;
		}
		break;
	}

	case 3:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: return GL_RGB8;
		case kiwi::texture_format::u16: return GL_RGB16;
		case kiwi::texture_format::f16: return GL_RGB16F;
		case kiwi::texture_format::f32: return GL_RGB32F;
		case kiwi::texture_format::u8u: return GL_RGB8UI;
		case kiwi::texture_format::u16u: return GL_RGB16UI;
		case kiwi::texture_format::u32u: return GL_RGB32UI;
		case kiwi::texture_format::i8u: return GL_RGB8I;
		case kiwi::texture_format::i16u: return GL_RGB16I;
		case kiwi::texture_format::i32u: return GL_RGB32I;
		case kiwi::texture_format::depth: return GL_DEPTH_COMPONENT;
		}
		break;
	}

	case 4:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: return GL_RGBA8;
		case kiwi::texture_format::u16: return GL_RGBA16;
		case kiwi::texture_format::f16: return GL_RGBA16F;
		case kiwi::texture_format::f32: return GL_RGBA32F;
		case kiwi::texture_format::u8u: return GL_RGBA8UI;
		case kiwi::texture_format::u16u: return GL_RGBA16UI;
		case kiwi::texture_format::u32u: return GL_RGBA32UI;
		case kiwi::texture_format::i8u: return GL_RGBA8I;
		case kiwi::texture_format::i16u: return GL_RGBA16I;
		case kiwi::texture_format::i32u: return GL_RGBA32I;
		case kiwi::texture_format::depth: return GL_DEPTH_COMPONENT;
		}
		break;
	}

	default:
	{
		switch (format)
		{
		case kiwi::texture_format::u8: return GL_R8;
		case kiwi::texture_format::u16: return GL_R16;
		case kiwi::texture_format::f16: return GL_R16F;
		case kiwi::texture_format::f32: return GL_R32F;
		case kiwi::texture_format::u8u: return GL_R8UI;
		case kiwi::texture_format::u16u: return GL_R16UI;
		case kiwi::texture_format::u32u: return GL_R32UI;
		case kiwi::texture_format::i8u: return GL_R8I;
		case kiwi::texture_format::i16u: return GL_R16I;
		case kiwi::texture_format::i32u: return GL_R32I;
		case kiwi::texture_format::depth: return GL_DEPTH_COMPONENT;
		}
		break;
	}

	}
}