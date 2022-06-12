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

kiwi::frame_buffer& kiwi::frame_buffer::use_with_texture(std::size_t color_attachment) noexcept
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

	kiwi::context::current_color_attachment() = color_attachment;

	GLenum texture_in_use = GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment);

	glDrawBuffers(1, &texture_in_use);

	glViewport(0, 0, static_cast<GLsizei>(m_texture_buffer_ptr[color_attachment]->width()),
		static_cast<GLsizei>(m_texture_buffer_ptr[color_attachment]->height()));

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::use_with_texture(std::size_t color_attachment) const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	kiwi::context::current_color_attachment() = color_attachment;

	GLenum texture_in_use = GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment);

	glDrawBuffers(1, &texture_in_use);

	glViewport(0, 0, static_cast<GLsizei>(m_texture_buffer_ptr[color_attachment]->width()),
		static_cast<GLsizei>(m_texture_buffer_ptr[color_attachment]->height()));

	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::use_with_textures(const GLenum* const color_attachments_ptr, std::size_t number_of_color_attachments) noexcept
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

	kiwi::context::current_color_attachment() = static_cast<std::size_t>(*color_attachments_ptr);

	GLenum textures_in_use[8];

	for (std::size_t n = 0; n < number_of_color_attachments; n++)
	{
		textures_in_use[n] = GL_COLOR_ATTACHMENT0 + *(color_attachments_ptr + n);
	}

	glDrawBuffers(static_cast<GLsizei>(number_of_color_attachments), static_cast<GLenum*>(textures_in_use));

	std::size_t first_texture_number = static_cast<std::size_t>(*color_attachments_ptr);

	glViewport(0, 0, static_cast<GLsizei>(m_texture_buffer_ptr[first_texture_number]->width()),
		static_cast<GLsizei>(m_texture_buffer_ptr[first_texture_number]->height()));

	return *this;
}

const kiwi::frame_buffer& kiwi::frame_buffer::use_with_textures(const GLenum* const color_attachments_ptr, std::size_t number_of_color_attachments) const noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	kiwi::context::current_color_attachment() = static_cast<std::size_t>(*color_attachments_ptr);

	GLenum textures_in_use[8];

	for (std::size_t n = 0; n < number_of_color_attachments; n++)
	{
		textures_in_use[n] = GL_COLOR_ATTACHMENT0 + *(color_attachments_ptr + n);
	}

	glDrawBuffers(static_cast<GLsizei>(number_of_color_attachments), static_cast<GLenum*>(textures_in_use));

	std::size_t first_texture_number = static_cast<std::size_t>(*color_attachments_ptr);

	glViewport(0, 0, static_cast<GLsizei>(m_texture_buffer_ptr[first_texture_number]->width()),
		static_cast<GLsizei>(m_texture_buffer_ptr[first_texture_number]->height()));

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

kiwi::frame_buffer& kiwi::frame_buffer::attach_texture(kiwi::texture_buffer* texture_buffer_ptr, std::size_t color_attachment) noexcept
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

	if (m_texture_buffer_ptr[color_attachment] != texture_buffer_ptr)
	{
		m_texture_buffer_ptr[color_attachment] = texture_buffer_ptr;
		if (texture_buffer_ptr->get_format() != kiwi::texture_format::depth)
		{
			switch (texture_buffer_ptr->get_sampling())
			{

			case kiwi::texture_sampling::unique:
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment), GL_TEXTURE_2D, texture_buffer_ptr->get_id(), 0);
				break;

			case kiwi::texture_sampling::multiple:
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment), GL_TEXTURE_2D_MULTISAMPLE, texture_buffer_ptr->get_id(), 0);
				break;
			}
		}
		else
		{
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment), GL_DEPTH_COMPONENT, texture_buffer_ptr->get_id(), 0);
		}
	}
	return *this;
}

kiwi::frame_buffer& kiwi::frame_buffer::detach_texture(std::size_t color_attachment) noexcept
{
	if (kiwi::context::current_frame_buffer() != static_cast<const void*>(this))
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frame_buffer_index);
		kiwi::context::current_frame_buffer() = static_cast<const void*>(this);
	}

	if (m_texture_buffer_ptr[color_attachment] != nullptr)
	{
		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment), 0, 0);
		m_texture_buffer_ptr[color_attachment] = nullptr;
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

	for (std::size_t color_attachment = 0; color_attachment < m_max_number_of_attachments; color_attachment++)
	{
		if (m_texture_buffer_ptr[color_attachment] != nullptr)
		{
			glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(color_attachment), 0, 0);
			m_texture_buffer_ptr[color_attachment] = nullptr;
			return *this;
		}
	}
	return *this;
}

kiwi::pixel_buffer* kiwi::frame_buffer::get_texture(std::size_t color_attachment) const noexcept
{
	return m_texture_buffer_ptr[color_attachment];
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


kiwi::scoped_frame::scoped_frame(kiwi::frame_buffer& rhs) noexcept
{
	m_exit_frame_buffer_ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	rhs.bind();
	m_current_frame_buffer_ptr = &rhs;
	m_exit_color_attachment = kiwi::context::current_color_attachment();
	m_action_on_exit = true;
}

kiwi::scoped_frame::scoped_frame(kiwi::frame_buffer& rhs, std::size_t color_attachment) noexcept
{
	m_exit_frame_buffer_ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	rhs.use_with_texture(color_attachment);
	m_current_frame_buffer_ptr = &rhs;
	m_exit_color_attachment = kiwi::context::current_color_attachment();
	m_action_on_exit = true;
}

kiwi::scoped_frame::scoped_frame(kiwi::frame_buffer& rhs, const GLenum* const color_attachments_ptr, std::size_t color_attachment_count) noexcept
{
	m_exit_frame_buffer_ptr = static_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	rhs.use_with_textures(color_attachments_ptr, color_attachment_count);
	m_current_frame_buffer_ptr = &rhs;
	m_exit_color_attachment = kiwi::context::current_color_attachment();
	m_action_on_exit = true;
}

kiwi::scoped_frame& kiwi::scoped_frame::set_frame_buffer_on_exit(const kiwi::frame_buffer& exit_frame_buffer, std::size_t color_attachment) noexcept
{
	m_exit_frame_buffer_ptr = &exit_frame_buffer;
	m_exit_color_attachment = color_attachment;
	return *this;
}

kiwi::scoped_frame& kiwi::scoped_frame::set_default_frame_buffer_on_exit() noexcept
{
	m_exit_frame_buffer_ptr = nullptr;
	return *this;
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


kiwi::scoped_blit::scoped_blit(kiwi::frame_buffer& draw_frame, kiwi::frame_buffer& read_frame) noexcept
{
	glBindFramebuffer(GL_READ_FRAMEBUFFER, read_frame.get_id());
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_frame.get_id());
	m_read_ptr = &read_frame;
	m_draw_ptr = &draw_frame;
	m_exit_frame_buffer_ptr = reinterpret_cast<const kiwi::frame_buffer*>(kiwi::context::current_frame_buffer());
	m_exit_color_attachment = kiwi::context::current_color_attachment();
	m_action_on_exit = true;
}

kiwi::scoped_blit::~scoped_blit()
{
	if (true)
	{
		if (m_exit_frame_buffer_ptr == nullptr)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
		else
		{
			m_exit_frame_buffer_ptr->use_with_texture(m_exit_color_attachment);
		}
	}
}

kiwi::scoped_blit& kiwi::scoped_blit::no_action_on_exit() noexcept
{
	m_action_on_exit = false;
	return *this;
}

kiwi::scoped_blit& kiwi::scoped_blit::set_frame_buffer_on_exit(const kiwi::frame_buffer& exit_frame_buffer, std::size_t color_attachment) noexcept
{
	m_exit_frame_buffer_ptr = &exit_frame_buffer;
	m_exit_color_attachment = color_attachment;
	return *this;
}

kiwi::scoped_blit& kiwi::scoped_blit::set_default_frame_buffer_on_exit() noexcept
{
	m_exit_frame_buffer_ptr = nullptr;
	return *this;
}

kiwi::scoped_blit& kiwi::scoped_blit::blit(std::size_t draw_location, std::size_t read_location) noexcept
{
	glReadBuffer(GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(read_location));
	GLenum location[1] = { GL_COLOR_ATTACHMENT0 + static_cast<GLenum>(draw_location) };
	glDrawBuffers(1, static_cast<GLenum*>(location));
	GLint width = static_cast<GLint>(m_read_ptr->get_texture(read_location)->width());
	GLint height = static_cast<GLint>(m_read_ptr->get_texture(read_location)->height());
	glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_NEAREST);
	return *this;
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