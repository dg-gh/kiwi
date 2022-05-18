#include "buffers/kiwi_buffer_cubemap.hpp"


kiwi::cubemap_buffer::cubemap_buffer() noexcept
{
	m_buffer_index = 0;
	m_dim = 0;
	m_format = kiwi::cubemap_format::u8;
}

kiwi::cubemap_buffer::cubemap_buffer(kiwi::cubemap_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;

	rhs.m_format = kiwi::cubemap_format::u8;
}

kiwi::cubemap_buffer& kiwi::cubemap_buffer::operator=(kiwi::cubemap_buffer&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_format = kiwi::cubemap_format::u8;

	return *this;
}

kiwi::cubemap_buffer::~cubemap_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}
}

kiwi::cubemap_buffer& kiwi::cubemap_buffer::new_id() noexcept
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

kiwi::cubemap_buffer& kiwi::cubemap_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
		m_buffer_index = 0;
		m_dim = 0;
		m_format = kiwi::cubemap_format::u8;
	}
	return *this;
}

GLuint kiwi::cubemap_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::cubemap_buffer& kiwi::cubemap_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	if (kiwi::context::current_texture_buffer() != static_cast<void*>(this))
	{
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<void*>(this);
	}
	return *this;
}

const kiwi::cubemap_buffer& kiwi::cubemap_buffer::bind() const noexcept
{
	if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
	{
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

void kiwi::cubemap_buffer::unbind() noexcept
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	kiwi::context::current_texture_buffer() = nullptr;
}

kiwi::cubemap_buffer& kiwi::cubemap_buffer::load(
	const unsigned char* const Xp_data_ptr,
	const unsigned char* const Xm_data_ptr,
	const unsigned char* const Yp_data_ptr,
	const unsigned char* const Ym_data_ptr,
	const unsigned char* const Zp_data_ptr,
	const unsigned char* const Zm_data_ptr,
	std::size_t resolution, std::size_t pixel_dimension,
	kiwi::cubemap_mapping mapping) noexcept
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
	case kiwi::cubemap_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::cubemap_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::cubemap_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::cubemap_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::cubemap_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::cubemap_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	GLsizei reso = static_cast<GLsizei>(resolution);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, Ym_data_ptr);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, Yp_data_ptr);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, Zm_data_ptr);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, Zp_data_ptr);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, Xp_data_ptr);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, Xm_data_ptr);
	m_format = kiwi::cubemap_format::u8;

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::cubemap_buffer& kiwi::cubemap_buffer::load(
	const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t resolution, std::size_t pixel_dimension,
	kiwi::cubemap_mapping mapping) noexcept
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
	case kiwi::cubemap_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::cubemap_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::cubemap_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::cubemap_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::cubemap_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::cubemap_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	GLsizei reso = static_cast<GLsizei>(resolution);

	switch (face)
	{
	case kiwi::cubemap_face::Xp: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Xm: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Yp: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Ym: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Zp: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Zm: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	}

	m_format = kiwi::cubemap_format::u8;

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}

kiwi::cubemap_buffer& kiwi::cubemap_buffer::load(
	const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
	const kiwi::size& size_2d, std::size_t pixel_dimension,
	kiwi::cubemap_mapping mapping) noexcept
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
	case kiwi::cubemap_mapping::nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST; break;
	case kiwi::cubemap_mapping::linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR; break;
	case kiwi::cubemap_mapping::nearest_mipmap_nearest: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::cubemap_mapping::linear_mipmap_nearest: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_NEAREST; mipmap = true; break;
	case kiwi::cubemap_mapping::nearest_mipmap_linear: _mapping = GL_NEAREST; _mapping_min = GL_NEAREST_MIPMAP_LINEAR; mipmap = true; break;
	case kiwi::cubemap_mapping::linear_mipmap_linear: _mapping = GL_LINEAR; _mapping_min = GL_LINEAR_MIPMAP_LINEAR; mipmap = true; break;
	}

	switch (face)
	{
	case kiwi::cubemap_face::Xp: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Xm: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Yp: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Ym: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Zp: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	case kiwi::cubemap_face::Zm: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, _internal_format, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]), 0, _color_format, GL_UNSIGNED_BYTE, texture_data_ptr); break;
	}

	m_format = kiwi::cubemap_format::u8;

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, _mapping);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, _mapping_min);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	if (mipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	return *this;
}