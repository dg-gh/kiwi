#include "buffers/kiwi_buffer_cubemap.hpp"


kiwi::cubemap::cubemap() noexcept
{
	m_buffer_index = 0;
	m_pixel_buffer_type = kiwi::pixel_buffer_type::cubemap;
	m_dim = 0;
	m_width = 0;
	m_format = kiwi::pixel_format::u8;
}

kiwi::cubemap::cubemap(kiwi::cubemap&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_dim = rhs.m_dim;
	m_width = rhs.m_width;
	m_format = rhs.m_format;

	rhs.m_buffer_index = 0;
	rhs.m_dim = 0;
	rhs.m_width = 0;
	rhs.m_format = kiwi::pixel_format::u8;
}

kiwi::cubemap& kiwi::cubemap::operator=(kiwi::cubemap&& rhs) noexcept
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

kiwi::cubemap::~cubemap()
{
	if (m_buffer_index != 0)
	{
		glDeleteTextures(1, &m_buffer_index);
	}
}

kiwi::cubemap& kiwi::cubemap::new_id() noexcept
{
	if (m_buffer_index != 0)
	{
		delete_id();
	}
	glGenTextures(1, &m_buffer_index);
	return *this;
}

kiwi::cubemap& kiwi::cubemap::delete_id() noexcept
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

GLuint kiwi::cubemap::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::cubemap& kiwi::cubemap::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_buffer_index);
	return *this;
}

const kiwi::cubemap& kiwi::cubemap::bind() const noexcept
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_buffer_index);
	return *this;
}

void kiwi::cubemap::unbind() noexcept
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

kiwi::cubemap& kiwi::cubemap::to_binding(GLenum binding) noexcept
{
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_buffer_index);
	return *this;
}

const kiwi::cubemap& kiwi::cubemap::to_binding(GLenum binding) const noexcept
{
	glActiveTexture(GL_TEXTURE0 + binding);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_buffer_index);
	return *this;
}

std::size_t kiwi::cubemap::pixel_dim() const noexcept
{
	return m_dim;
}

std::size_t kiwi::cubemap::width() const noexcept
{
	return m_width;
}

std::size_t kiwi::cubemap::height() const noexcept
{
	return m_width;
}

kiwi::cubemap& kiwi::cubemap::load(
	const void* const Xp_data_ptr, const void* const Xm_data_ptr,
	const void* const Yp_data_ptr, const void* const Ym_data_ptr,
	const void* const Zp_data_ptr, const void* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim,
	kiwi::pixel_mapping mapping, kiwi::pixel_format format) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(GL_TEXTURE_2D, m_buffer_index);

	m_dim = pixel_dim;
	m_width = width;

	{
		GLint _internal_format;
		GLenum _color_format;
		GLenum _type;
		set_pixel_format(format, pixel_dim, &_internal_format, &_color_format, &_type);

		GLsizei reso = static_cast<GLsizei>(width);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, _internal_format, reso, reso, 0, _color_format, _type, Ym_data_ptr);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, _internal_format, reso, reso, 0, _color_format, _type, Yp_data_ptr);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, _type, Zm_data_ptr);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, _type, Zp_data_ptr);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, _type, Xp_data_ptr);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, _type, Xm_data_ptr);
		m_format = format;
	}

	{
		GLint _mapping_mag;
		GLint _mapping_min;
		bool _mipmap;
		set_pixel_mapping(mapping, &_mapping_mag, &_mapping_min, &_mipmap);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		if (_mipmap)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}

	return *this;
}

kiwi::cubemap& kiwi::cubemap::load_u8(
	const unsigned char* const Xp_data_ptr, const unsigned char* const Xm_data_ptr,
	const unsigned char* const Yp_data_ptr, const unsigned char* const Ym_data_ptr,
	const unsigned char* const Zp_data_ptr, const unsigned char* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::u8);
}

kiwi::cubemap& kiwi::cubemap::load_u16(
	const GLushort* const Xp_data_ptr, const GLushort* const Xm_data_ptr,
	const GLushort* const Yp_data_ptr, const GLushort* const Ym_data_ptr,
	const GLushort* const Zp_data_ptr, const GLushort* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::u16);
}

kiwi::cubemap& kiwi::cubemap::load_f32(
	const GLfloat* const Xp_data_ptr, const GLfloat* const Xm_data_ptr,
	const GLfloat* const Yp_data_ptr, const GLfloat* const Ym_data_ptr,
	const GLfloat* const Zp_data_ptr, const GLfloat* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::f32);
}

kiwi::cubemap& kiwi::cubemap::load_u8u(
	const unsigned char* const Xp_data_ptr, const unsigned char* const Xm_data_ptr,
	const unsigned char* const Yp_data_ptr, const unsigned char* const Ym_data_ptr,
	const unsigned char* const Zp_data_ptr, const unsigned char* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::u8u);
}

kiwi::cubemap& kiwi::cubemap::load_u16u(
	const GLushort* const Xp_data_ptr, const GLushort* const Xm_data_ptr,
	const GLushort* const Yp_data_ptr, const GLushort* const Ym_data_ptr,
	const GLushort* const Zp_data_ptr, const GLushort* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::u16u);
}

kiwi::cubemap& kiwi::cubemap::load_u32u(
	const GLuint* const Xp_data_ptr, const GLuint* const Xm_data_ptr,
	const GLuint* const Yp_data_ptr, const GLuint* const Ym_data_ptr,
	const GLuint* const Zp_data_ptr, const GLuint* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::u32u);
}

kiwi::cubemap& kiwi::cubemap::load_i8u(
	const char* const Xp_data_ptr, const char* const Xm_data_ptr,
	const char* const Yp_data_ptr, const char* const Ym_data_ptr,
	const char* const Zp_data_ptr, const char* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::i8u);
}

kiwi::cubemap& kiwi::cubemap::load_i16u(
	const GLshort* const Xp_data_ptr, const GLshort* const Xm_data_ptr,
	const GLshort* const Yp_data_ptr, const GLshort* const Ym_data_ptr,
	const GLshort* const Zp_data_ptr, const GLshort* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::i16u);
}

kiwi::cubemap& kiwi::cubemap::load_i32u(
	const GLint* const Xp_data_ptr, const GLint* const Xm_data_ptr,
	const GLint* const Yp_data_ptr, const GLint* const Ym_data_ptr,
	const GLint* const Zp_data_ptr, const GLint* const Zm_data_ptr,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load(
		static_cast<const void* const>(Xp_data_ptr), static_cast<const void* const>(Xm_data_ptr),
		static_cast<const void* const>(Yp_data_ptr), static_cast<const void* const>(Ym_data_ptr),
		static_cast<const void* const>(Zp_data_ptr), static_cast<const void* const>(Zm_data_ptr),
		width, pixel_dim, mapping, kiwi::pixel_format::i32u);
}

kiwi::cubemap& kiwi::cubemap::load_face(
	const void* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim,
	kiwi::pixel_mapping mapping, kiwi::pixel_format format) noexcept
{
	if (m_buffer_index == 0)
	{
		glGenTextures(1, &m_buffer_index);
	}

	glBindTexture(GL_TEXTURE_2D, m_buffer_index);

	m_dim = pixel_dim;
	m_width = width;

	{
		GLint _internal_format;
		GLenum _color_format;
		GLenum _type;
		set_pixel_format(format, pixel_dim, &_internal_format, &_color_format, &_type);

		GLsizei reso = static_cast<GLsizei>(width);

		switch (face)
		{
		case kiwi::cubemap_face::Xp: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, _type, texture_data_ptr); break;
		case kiwi::cubemap_face::Xm: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, _internal_format, reso, reso, 0, _color_format, _type, texture_data_ptr); break;
		case kiwi::cubemap_face::Yp: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, _internal_format, reso, reso, 0, _color_format, _type, texture_data_ptr); break;
		case kiwi::cubemap_face::Ym: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, _internal_format, reso, reso, 0, _color_format, _type, texture_data_ptr); break;
		case kiwi::cubemap_face::Zp: glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, _type, texture_data_ptr); break;
		case kiwi::cubemap_face::Zm: glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, _internal_format, reso, reso, 0, _color_format, _type, texture_data_ptr); break;
		}
		m_format = format;
	}

	{
		GLint _mapping_mag;
		GLint _mapping_min;
		bool _mipmap;
		set_pixel_mapping(mapping, &_mapping_mag, &_mapping_min, &_mipmap);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, _mapping_mag);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, _mapping_min);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		if (_mipmap)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}

	return *this;
}

kiwi::cubemap& kiwi::cubemap::load_face_u8(
	const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::u8);
}

kiwi::cubemap& kiwi::cubemap::load_face_u16(
	const GLushort* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::u16);
}

kiwi::cubemap& kiwi::cubemap::load_face_f32(
	const GLfloat* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::f32);
}

kiwi::cubemap& kiwi::cubemap::load_face_u8u(
	const unsigned char* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::u8u);
}

kiwi::cubemap& kiwi::cubemap::load_face_u16u(
	const GLushort* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::u16u);
}

kiwi::cubemap& kiwi::cubemap::load_face_u32u(
	const GLuint* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::u32u);
}


kiwi::cubemap& kiwi::cubemap::load_face_i8u(
	const char* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::i8u);
}

kiwi::cubemap& kiwi::cubemap::load_face_i16u(
	const GLshort* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::i16u);
}

kiwi::cubemap& kiwi::cubemap::load_face_i32u(
	const GLint* const texture_data_ptr, kiwi::cubemap_face face,
	std::size_t width, std::size_t pixel_dim, kiwi::pixel_mapping mapping) noexcept
{
	return load_face(static_cast<const void* const>(texture_data_ptr), face, width, pixel_dim, mapping, kiwi::pixel_format::i32u);
}