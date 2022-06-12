#include "buffers/kiwi_buffer_pixel.hpp"

GLuint kiwi::pixel_buffer::get_id() noexcept
{
	return m_buffer_index;
}

kiwi::pixel_buffer_type kiwi::pixel_buffer::get_pixel_buffer_type() const noexcept
{
	return m_pixel_buffer_type;
}