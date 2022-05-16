#include "buffers/kiwi_buffer_frame.hpp"


kiwi::frame_buffer::frame_buffer() noexcept
{
	m_frame_buffer_index = 0;

	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		m_texture_buffer_ptr[n] = nullptr;
	}
	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		m_textures_in_use[n] = 0;
	}
	m_number_of_textures_in_use = 0;
	m_width = 0;
	m_height = 0;

	m_render_buffer_ptr = nullptr;
}

kiwi::frame_buffer::frame_buffer(kiwi::frame_buffer&& rhs) noexcept
{
	m_frame_buffer_index = rhs.m_frame_buffer_index;

	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		m_texture_buffer_ptr[n] = rhs.m_texture_buffer_ptr[n];
	}
	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		m_textures_in_use[n] = rhs.m_textures_in_use[n];
	}
	m_number_of_textures_in_use = rhs.m_number_of_textures_in_use;
	m_width = rhs.m_width;
	m_height = rhs.m_height;

	m_render_buffer_ptr = rhs.m_render_buffer_ptr;


	rhs.m_frame_buffer_index = 0;

	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		rhs.m_texture_buffer_ptr[n] = nullptr;
	}
	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		rhs.m_textures_in_use[n] = 0;
	}
	rhs.m_number_of_textures_in_use = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;

	m_render_buffer_ptr = nullptr;
}

kiwi::frame_buffer& kiwi::frame_buffer::operator=(kiwi::frame_buffer&& rhs) noexcept
{
	detach_all_textures();
	detach_render_buffer();

	if (m_frame_buffer_index != 0)
	{
		glDeleteFramebuffers(1, &m_frame_buffer_index);
	}

	m_frame_buffer_index = rhs.m_frame_buffer_index;

	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		m_texture_buffer_ptr[n] = rhs.m_texture_buffer_ptr[n];
	}
	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		m_textures_in_use[n] = rhs.m_textures_in_use[n];
	}
	m_number_of_textures_in_use = rhs.m_number_of_textures_in_use;
	m_width = rhs.m_width;
	m_height = rhs.m_height;

	m_render_buffer_ptr = rhs.m_render_buffer_ptr;


	rhs.m_frame_buffer_index = 0;

	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		rhs.m_texture_buffer_ptr[n] = nullptr;
	}
	for (std::size_t n = 0; n < m_max_number_of_attachments; n++)
	{
		rhs.m_textures_in_use[n] = 0;
	}
	rhs.m_number_of_textures_in_use = 0;
	rhs.m_width = 0;
	rhs.m_height = 0;

	rhs.m_render_buffer_ptr = nullptr;

	return *this;
}

kiwi::frame_buffer::~frame_buffer()
{
	detach_all_textures();
	detach_render_buffer();

	if (m_frame_buffer_index != 0)
	{
		glDeleteFramebuffers(1, &m_frame_buffer_index);
	}
}

kiwi::frame_buffer& kiwi::frame_buffer::new_id() noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}
	else
	{
		detach_all_textures();
		detach_render_buffer();

		delete_id();
		glGenFramebuffers(1, &m_frame_buffer_index);
	}
	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::delete_id() noexcept
{
	detach_all_textures();
	detach_render_buffer();

	if (m_frame_buffer_index != 0)
	{
		glDeleteFramebuffers(1, &m_frame_buffer_index);
		m_frame_buffer_index = 0;
	}
	return *this;
}

GLuint kiwi::frame_buffer::get_id() const noexcept
{
	return m_frame_buffer_index;
}

kiwi::frame_buffer& kiwi::frame_buffer::bind() noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::bind() const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}
	return *this;
}

void kiwi::frame_buffer::unbind() noexcept
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	kiwi::context::current_frame_buffer() = nullptr;
}

kiwi::frame_buffer& kiwi::frame_buffer::use() noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	if (m_number_of_textures_in_use != 0)
	{
		glDrawBuffers(m_number_of_textures_in_use, static_cast<GLenum*>(m_textures_in_use));
		glViewport(0, 0, m_width, m_height);
	}

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::use() const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	if (m_number_of_textures_in_use != 0)
	{
		glDrawBuffers(m_number_of_textures_in_use, static_cast<GLenum*>(m_textures_in_use));
		glViewport(0, 0, m_width, m_height);
	}

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::use_with_all_textures() noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	{
		GLenum* textures_ptr = static_cast<GLenum*>(m_textures_in_use);

		for (GLenum n = 0; n < m_max_number_of_attachments; n++)
		{
			if (m_texture_buffer_ptr[static_cast<std::size_t>(n)] != nullptr)
			{
				*textures_ptr++ = n;
			}
		}

		m_number_of_textures_in_use = static_cast<GLsizei>(textures_ptr - static_cast<GLenum*>(m_textures_in_use));
	}

	if (m_number_of_textures_in_use != 0)
	{
		std::size_t width = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[0])]->width();
		std::size_t height = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[0])]->height();
		m_textures_in_use[0] += GL_COLOR_ATTACHMENT0;

		for (std::size_t n = 1; n < static_cast<std::size_t>(m_number_of_textures_in_use); n++)
		{
			std::size_t temp_width = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[n])]->width();
			width = (width < temp_width) ? width : temp_width;
			std::size_t temp_height = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[n])]->height();
			height = (height < temp_height) ? height : temp_height;
			m_textures_in_use[n] += GL_COLOR_ATTACHMENT0;
		}

		glDrawBuffers(m_number_of_textures_in_use, static_cast<GLenum*>(m_textures_in_use));
		m_width = static_cast<GLsizei>(width);
		m_height = static_cast<GLsizei>(height);
		glViewport(0, 0, m_width, m_height);
	}
	else
	{
		m_width = 0;
		m_height = 0;
	}

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::use_with_all_textures() const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	{
		GLenum* textures_ptr = static_cast<GLenum*>(m_textures_in_use);

		for (GLenum n = 0; n < m_max_number_of_attachments; n++)
		{
			if (m_texture_buffer_ptr[static_cast<std::size_t>(n)] != nullptr)
			{
				*textures_ptr++ = n;
			}
		}

		m_number_of_textures_in_use = static_cast<GLsizei>(textures_ptr - static_cast<GLenum*>(m_textures_in_use));
	}

	if (m_number_of_textures_in_use != 0)
	{
		std::size_t width = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[0])]->width();
		std::size_t height = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[0])]->height();
		m_textures_in_use[0] += GL_COLOR_ATTACHMENT0;

		for (std::size_t n = 1; n < static_cast<std::size_t>(m_number_of_textures_in_use); n++)
		{
			std::size_t temp_width = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[n])]->width();
			width = (width < temp_width) ? width : temp_width;
			std::size_t temp_height = m_texture_buffer_ptr[static_cast<std::size_t>(m_textures_in_use[n])]->height();
			height = (height < temp_height) ? height : temp_height;
			m_textures_in_use[n] += GL_COLOR_ATTACHMENT0;
		}

		glDrawBuffers(m_number_of_textures_in_use, static_cast<GLenum*>(m_textures_in_use));
		m_width = static_cast<GLsizei>(width);
		m_height = static_cast<GLsizei>(height);
		glViewport(0, 0, m_width, m_height);
	}
	else
	{
		m_width = 0;
		m_height = 0;
	}

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::use_with_texture(std::size_t texture_number) noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(texture_number);
	m_number_of_textures_in_use = 1;

	glDrawBuffers(1, static_cast<GLenum*>(m_textures_in_use));
	m_width = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->width());
	m_height = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->height());
	glViewport(0, 0, m_width, m_height);

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::use_with_texture(std::size_t texture_number) const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(texture_number);
	m_number_of_textures_in_use = 1;

	glDrawBuffers(1, static_cast<GLenum*>(m_textures_in_use));
	m_width = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->width());
	m_height = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->height());
	glViewport(0, 0, m_width, m_height);

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::reserve_texture(std::size_t texture_number) noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(texture_number);
	m_number_of_textures_in_use = 1;

	m_width = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->width());
	m_height = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->height());

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::reserve_texture(std::size_t texture_number) const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(texture_number);
	m_number_of_textures_in_use = 1;

	m_width = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->width());
	m_height = static_cast<GLsizei>(m_texture_buffer_ptr[texture_number]->height());

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::use_with_textures(GLenum* texture_locations_ptr, std::size_t number_of_textures) noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	std::size_t width = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->width();
	std::size_t height = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->height();
	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + *texture_locations_ptr;
	m_number_of_textures_in_use = static_cast<GLsizei>(number_of_textures);

	for (std::size_t n = 1; n < number_of_textures; n++)
	{
		std::size_t temp_width = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->width();
		width = (width < temp_width) ? width : temp_width;
		std::size_t temp_height = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->height();
		height = (height < temp_height) ? height : temp_height;
		m_textures_in_use[n] = GL_COLOR_ATTACHMENT0 + *(texture_locations_ptr + n);
	}
	glDrawBuffers(m_number_of_textures_in_use, static_cast<GLenum*>(m_textures_in_use));
	m_width = static_cast<GLsizei>(width);
	m_height = static_cast<GLsizei>(height);
	glViewport(0, 0, m_width, m_height);

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::use_with_textures(GLenum* texture_locations_ptr, std::size_t number_of_textures) const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	std::size_t width = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->width();
	std::size_t height = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->height();
	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + *texture_locations_ptr;
	m_number_of_textures_in_use = static_cast<GLsizei>(number_of_textures);

	for (std::size_t n = 1; n < number_of_textures; n++)
	{
		std::size_t temp_width = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->width();
		width = (width < temp_width) ? width : temp_width;
		std::size_t temp_height = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->height();
		height = (height < temp_height) ? height : temp_height;
		m_textures_in_use[n] = GL_COLOR_ATTACHMENT0 + *(texture_locations_ptr + n);
	}
	glDrawBuffers(m_number_of_textures_in_use, static_cast<GLenum*>(m_textures_in_use));
	m_width = static_cast<GLsizei>(width);
	m_height = static_cast<GLsizei>(height);
	glViewport(0, 0, m_width, m_height);

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::reserve_textures(GLenum* texture_locations_ptr, std::size_t number_of_textures) noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	std::size_t width = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->width();
	std::size_t height = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->height();
	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + *texture_locations_ptr;
	m_number_of_textures_in_use = static_cast<GLsizei>(number_of_textures);

	for (std::size_t n = 1; n < number_of_textures; n++)
	{
		std::size_t temp_width = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->width();
		width = (width < temp_width) ? width : temp_width;
		std::size_t temp_height = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->height();
		height = (height < temp_height) ? height : temp_height;
		m_textures_in_use[n] = GL_COLOR_ATTACHMENT0 + *(texture_locations_ptr + n);
	}

	m_width = static_cast<GLsizei>(width);
	m_height = static_cast<GLsizei>(height);

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::reserve_textures(GLenum* texture_locations_ptr, std::size_t number_of_textures) const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	std::size_t width = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->width();
	std::size_t height = m_texture_buffer_ptr[static_cast<std::size_t>(*texture_locations_ptr)]->height();
	m_textures_in_use[0] = GL_COLOR_ATTACHMENT0 + *texture_locations_ptr;
	m_number_of_textures_in_use = static_cast<GLsizei>(number_of_textures);

	for (std::size_t n = 1; n < number_of_textures; n++)
	{
		std::size_t temp_width = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->width();
		width = (width < temp_width) ? width : temp_width;
		std::size_t temp_height = m_texture_buffer_ptr[static_cast<std::size_t>(*(texture_locations_ptr + n))]->height();
		height = (height < temp_height) ? height : temp_height;
		m_textures_in_use[n] = GL_COLOR_ATTACHMENT0 + *(texture_locations_ptr + n);
	}

	m_width = static_cast<GLsizei>(width);
	m_height = static_cast<GLsizei>(height);

	return *this;
}

void kiwi::frame_buffer::exit_frame() noexcept
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	kiwi::context::current_frame_buffer() = nullptr;
	int screen_width;
	int screen_height;
	glfwGetWindowSize(kiwi::context::window(), &screen_width, &screen_height);
	glViewport(0, 0, static_cast<GLint>(screen_width), static_cast<GLint>(screen_height));
}

kiwi::frame_buffer& kiwi::frame_buffer::attach_texture(kiwi::texture_buffer* texture_buffer_ptr, std::size_t location) noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	if (m_texture_buffer_ptr[location] != texture_buffer_ptr)
	{
		m_texture_buffer_ptr[location] = texture_buffer_ptr;
		if (texture_buffer_ptr->get_format() != kiwi::texture_format::depth)
		{
			switch (texture_buffer_ptr->get_sampling())
			{

			case kiwi::texture_sampling::unique:
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(location), GL_TEXTURE_2D, texture_buffer_ptr->get_id(), 0);
				break;

			case kiwi::texture_sampling::multiple:
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(location), GL_TEXTURE_2D_MULTISAMPLE, texture_buffer_ptr->get_id(), 0);
				break;
			}
		}
		else
		{
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(location), GL_DEPTH_COMPONENT, texture_buffer_ptr->get_id(), 0);
		}
	}
	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::detach_texture(std::size_t location) noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	if (m_texture_buffer_ptr[location] != nullptr)
	{
		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(location), 0, 0);
		m_texture_buffer_ptr[location] = nullptr;
		return *this;
	}
}

kiwi::frame_buffer& kiwi::frame_buffer::detach_all_textures() noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	for (std::size_t location = 0; location < m_max_number_of_attachments; location++)
	{
		if (m_texture_buffer_ptr[location] != nullptr)
		{
			glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(location), 0, 0);
			m_texture_buffer_ptr[location] = nullptr;
			return *this;
		}
	}
	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::textures_in_use(GLenum* arr, std::size_t* number_of_textures_in_use) noexcept
{
	std::size_t number = static_cast<std::size_t>(m_number_of_textures_in_use);

	for (std::size_t n = 0; n < number; n++)
	{
		arr[n] = static_cast<GLenum>(m_textures_in_use[n] - GL_COLOR_ATTACHMENT0);
	}
	*number_of_textures_in_use = number;

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::textures_in_use(GLenum* arr, std::size_t* number_of_textures_in_use) const noexcept
{
	std::size_t number = static_cast<std::size_t>(m_number_of_textures_in_use);

	for (std::size_t n = 0; n < number; n++)
	{
		arr[n] = static_cast<GLenum>(m_textures_in_use[n] - GL_COLOR_ATTACHMENT0);
	}
	*number_of_textures_in_use = number;

	return *this;
}

kiwi::texture_buffer* kiwi::frame_buffer::get_texture(std::size_t location) const noexcept
{
	return m_texture_buffer_ptr[location];
}

kiwi::frame_buffer& kiwi::frame_buffer::attach_render_buffer(kiwi::render_buffer* render_buffer_ptr) noexcept
{
	if (m_frame_buffer_index == 0)
	{
		glGenFramebuffers(1, &m_frame_buffer_index);
	}

	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	m_render_buffer_ptr = render_buffer_ptr;

	switch (render_buffer_ptr->buffer_type())
	{

	case kiwi::render_buffer_type::f16:
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, render_buffer_ptr->get_id());
		break;

	case kiwi::render_buffer_type::f24:
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, render_buffer_ptr->get_id());
		break;

	case kiwi::render_buffer_type::f32:
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, render_buffer_ptr->get_id());
		break;

	case kiwi::render_buffer_type::st8:
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, render_buffer_ptr->get_id());
		break;

	case kiwi::render_buffer_type::f24_st8:
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, render_buffer_ptr->get_id());
		break;

	case kiwi::render_buffer_type::f32_st8:
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, render_buffer_ptr->get_id());
		break;
	}

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::detach_render_buffer() noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	if (m_render_buffer_ptr != nullptr)
	{
		switch (m_render_buffer_ptr->buffer_type())
		{

		case kiwi::render_buffer_type::f16:
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, 0, 0);
			break;

		case kiwi::render_buffer_type::f24:
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, 0, 0);
			break;

		case kiwi::render_buffer_type::f32:
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, 0, 0);
			break;

		case kiwi::render_buffer_type::st8:
			glFramebufferTexture(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, 0, 0);
			break;

		case kiwi::render_buffer_type::f24_st8:
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, 0, 0);
			break;

		case kiwi::render_buffer_type::f32_st8:
			glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, 0, 0);
			break;
		}

		m_render_buffer_ptr = nullptr;
	}

	return *this;
}


kiwi::scoped_frame::scoped_frame(kiwi::frame_buffer& rhs)
{
	m_exit_frame_buffer_ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	rhs.use();
	m_current_frame_buffer_ptr = &rhs;
	m_action_on_exit = true;
}

kiwi::scoped_frame::scoped_frame(kiwi::frame_buffer& rhs, std::size_t texture_number)
{
	m_exit_frame_buffer_ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	rhs.use_with_texture(texture_number);
	m_current_frame_buffer_ptr = &rhs;
	m_action_on_exit = true;
}

kiwi::scoped_frame::scoped_frame(kiwi::frame_buffer& rhs, GLenum* texture_locations, std::size_t location_count)
{
	m_exit_frame_buffer_ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	rhs.use_with_textures(texture_locations, location_count);
	m_current_frame_buffer_ptr = &rhs;
	m_action_on_exit = true;
}

kiwi::frame_buffer& kiwi::scoped_frame::get_frame_buffer() noexcept
{
	return *m_current_frame_buffer_ptr;
}

kiwi::scoped_frame::~scoped_frame()
{
	if (m_action_on_exit)
	{
		if (m_exit_frame_buffer_ptr == nullptr)
		{
			m_current_frame_buffer_ptr->exit_frame();
		}
		else
		{
			m_exit_frame_buffer_ptr->use_with_texture(m_exit_color_attachment);
		}
	}
}


kiwi::frame_spec& kiwi::frame_spec::resize(const kiwi::XY& bottom_left, const kiwi::XY& top_right, const kiwi::size& size_2d) noexcept
{
	m_from_X = bottom_left[0];
	m_to_X = top_right[0];
	m_from_Y = bottom_left[1];
	m_to_Y = top_right[1];

	GLfloat new_screen_width_f = m_to_X - m_from_X;
	GLfloat new_screen_height_f = m_to_Y - m_from_Y;

	m_screen_ratio = static_cast<float>(new_screen_width_f) / static_cast<float>(new_screen_height_f);
	m_screen_ratio_inv = static_cast<float>(new_screen_height_f) / static_cast<float>(new_screen_width_f);

	if (new_screen_width_f >= new_screen_height_f)
	{
		m_min_X = -m_screen_ratio;
		m_max_X = m_screen_ratio;
		m_min_Y = -GL1;
		m_max_Y = GL1;
		m_pixel_X = (GL2 * m_screen_ratio) / static_cast<GLfloat>(size_2d[0]);
		m_pixel_Y = GL2 / static_cast<GLfloat>(size_2d[1]);

		m_window_matrix[0] = m_screen_ratio_inv;
		m_window_matrix[4] = GL1;

		m_b_X = -m_from_X;
		m_a_X = static_cast<GLfloat>(size_2d[0]) / new_screen_width_f;
		m_b_Y = -m_from_Y;
		m_a_Y = static_cast<GLfloat>(size_2d[1]) / new_screen_height_f;
	}
	else
	{
		m_min_X = -GL1;
		m_max_X = GL1;
		m_min_Y = -m_screen_ratio_inv;
		m_max_Y = m_screen_ratio_inv;
		m_pixel_X = GL2 / static_cast<GLfloat>(size_2d[0]);
		m_pixel_Y = (GL2 * m_screen_ratio_inv) / static_cast<GLfloat>(size_2d[1]);

		m_window_matrix[0] = GL1;
		m_window_matrix[4] = m_screen_ratio;

		m_b_X = -m_from_X;
		m_a_X = static_cast<GLfloat>(size_2d[0]) / new_screen_width_f;
		m_b_Y = -m_from_Y;
		m_a_Y = static_cast<GLfloat>(size_2d[1]) / new_screen_height_f;
	}

	return *this;
}

int kiwi::frame_spec::frame_width() const noexcept
{
	return m_screen_width;
}

int kiwi::frame_spec::frame_height() const noexcept
{
	return m_screen_height;
}

GLint kiwi::frame_spec::X_to_pixel(GLfloat X) const noexcept
{
	return m_a_X * X + m_b_X;
}

GLint kiwi::frame_spec::Y_to_pixel(GLfloat Y) const noexcept
{
	return m_a_Y * Y + m_b_Y;
}

GLfloat kiwi::frame_spec::frame_ratio() const noexcept
{
	return m_screen_ratio;
}

GLfloat kiwi::frame_spec::frame_ratio_inv() const noexcept
{
	return m_screen_ratio_inv;
}

GLfloat kiwi::frame_spec::min_X() const noexcept
{
	return m_min_X;
}

GLfloat kiwi::frame_spec::max_X() const noexcept
{
	return m_max_X;
}

GLfloat kiwi::frame_spec::min_Y() const noexcept
{
	return m_min_Y;
}

GLfloat kiwi::frame_spec::max_Y() const noexcept
{
	return m_max_Y;
}

GLfloat kiwi::frame_spec::pixel_X() const noexcept
{
	return m_pixel_X;
}

GLfloat kiwi::frame_spec::pixel_Y() const noexcept
{
	return m_pixel_Y;
}

const GLfloat* kiwi::frame_spec::window_matrix_data() const noexcept
{
	return static_cast<const GLfloat*>(m_window_matrix);
}

bool kiwi::frame_spec::in_frame(GLfloat X, GLfloat Y) const noexcept
{
	return ((m_from_X < X) && (X < m_to_X)) && ((m_from_Y < Y) && (Y < m_to_Y));
}