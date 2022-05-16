#include "buffers/kiwi_buffer_render.hpp"


kiwi::render_buffer::render_buffer() noexcept
{
	m_buffer_index = 0;
	m_rbtype = GL_DEPTH24_STENCIL8;
	m_width = 0;
	m_height = 0;
	m_sampling = kiwi::render_buffer_sampling::unique;
}

kiwi::render_buffer::render_buffer(render_buffer&& rhs) noexcept
{
	m_buffer_index = rhs.m_buffer_index;
	m_rbtype = rhs.m_rbtype;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_sampling = rhs.m_sampling;

	rhs.m_buffer_index = 0;
	rhs.m_rbtype = GL_DEPTH24_STENCIL8;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_sampling = kiwi::render_buffer_sampling::unique;
}

kiwi::render_buffer& kiwi::render_buffer::operator=(render_buffer&& rhs) noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteRenderbuffers(1, &m_buffer_index);
	}

	m_buffer_index = rhs.m_buffer_index;
	m_rbtype = rhs.m_rbtype;
	m_width = rhs.m_width;
	m_height = rhs.m_height;
	m_sampling = rhs.m_sampling;

	rhs.m_buffer_index = 0;
	rhs.m_rbtype = GL_DEPTH24_STENCIL8;
	rhs.m_width = 0;
	rhs.m_height = 0;
	rhs.m_sampling = kiwi::render_buffer_sampling::unique;

	return *this;
}

kiwi::render_buffer::~render_buffer()
{
	if (m_buffer_index != 0)
	{
		glDeleteRenderbuffers(1, &m_buffer_index);
	}
}

kiwi::render_buffer& kiwi::render_buffer::new_id() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenRenderbuffers(1, &m_buffer_index);
	}
	else
	{
		delete_id();
		glGenRenderbuffers(1, &m_buffer_index);
	}
	return *this;
}

kiwi::render_buffer& kiwi::render_buffer::delete_id() noexcept
{
	if (m_buffer_index != 0)
	{
		glDeleteRenderbuffers(1, &m_buffer_index);
		m_buffer_index = 0;
		m_rbtype = GL_DEPTH24_STENCIL8;
		m_width = 0;
		m_height = 0;
	}
	return *this;
}

GLuint kiwi::render_buffer::get_id() const noexcept
{
	return m_buffer_index;
}

kiwi::render_buffer& kiwi::render_buffer::bind() noexcept
{
	if (m_buffer_index == 0)
	{
		glGenRenderbuffers(1, &m_buffer_index);
	}

	if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
	{
		glBindRenderbuffer(GL_RENDERBUFFER, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

const kiwi::render_buffer& kiwi::render_buffer::bind() const noexcept
{
	if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
	{
		glBindRenderbuffer(GL_RENDERBUFFER, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

void kiwi::render_buffer::unbind() noexcept
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	kiwi::context::current_texture_buffer() = nullptr;
}

kiwi::render_buffer_type kiwi::render_buffer::buffer_type() const noexcept
{
	switch (m_rbtype)
	{
	case GL_DEPTH_COMPONENT16: return kiwi::render_buffer_type::f16; break;
	case GL_DEPTH_COMPONENT24: return kiwi::render_buffer_type::f24; break;
	case GL_DEPTH_COMPONENT32F: return kiwi::render_buffer_type::f32; break;
	case GL_STENCIL_INDEX8: return kiwi::render_buffer_type::st8; break;
	case GL_DEPTH24_STENCIL8: return kiwi::render_buffer_type::f24_st8; break;
	case GL_DEPTH32F_STENCIL8: return kiwi::render_buffer_type::f32_st8; break;
	}
}

kiwi::render_buffer& kiwi::render_buffer::allocate(kiwi::render_buffer_type rbtype, kiwi::size size_2d) noexcept
{
	if (m_buffer_index != 0)
	{
		if (kiwi::context::current_texture_buffer() != static_cast<const void*>(this))
		{
			glBindRenderbuffer(GL_RENDERBUFFER, m_buffer_index);
			kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
		}
	}
	else
	{
		glGenRenderbuffers(1, &m_buffer_index);
		glBindRenderbuffer(GL_RENDERBUFFER, m_buffer_index);
		kiwi::context::current_texture_buffer() = static_cast<const void*>(this);
	}

	switch (rbtype)
	{
	case kiwi::render_buffer_type::f16: m_rbtype = GL_DEPTH_COMPONENT16; break;
	case kiwi::render_buffer_type::f24: m_rbtype = GL_DEPTH_COMPONENT24; break;
	case kiwi::render_buffer_type::f32: m_rbtype = GL_DEPTH_COMPONENT32F; break;
	case kiwi::render_buffer_type::st8: m_rbtype = GL_STENCIL_INDEX8; break;
	case kiwi::render_buffer_type::f24_st8: m_rbtype = GL_DEPTH24_STENCIL8; break;
	case kiwi::render_buffer_type::f32_st8: m_rbtype = GL_DEPTH32F_STENCIL8; break;
	}

	switch (m_sampling)
	{
	case kiwi::render_buffer_sampling::unique:
		glRenderbufferStorage(GL_RENDERBUFFER, m_rbtype, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]));
		break;

	case kiwi::render_buffer_sampling::multiple:
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, m_rbtype, static_cast<GLsizei>(size_2d[0]), static_cast<GLsizei>(size_2d[1]));
		break;
	}

	return *this;
}

kiwi::render_buffer& kiwi::render_buffer::set_sampling(kiwi::render_buffer_sampling sampling) noexcept
{
	m_sampling = sampling;
	return *this;
}

kiwi::render_buffer_sampling kiwi::render_buffer::get_sampling() const noexcept
{
	return m_sampling;
}