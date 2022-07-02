#include "rendering/kiwi_glyph_3d.hpp"
#include "shader_sources/kiwi_sources_glyph.hpp"


thread_local unsigned int kiwi::glyph_3d::m_static_instance_count = 0;
thread_local kiwi::program kiwi::glyph_3d::m_program = kiwi::program();
thread_local kiwi::texture_buffer kiwi::glyph_3d::m_default_atlas_texture = kiwi::texture_buffer();

thread_local GLint kiwi::glyph_3d::m_XY_UV_size_location = -1;
thread_local GLint kiwi::glyph_3d::m_plane_location = -1;
thread_local GLint kiwi::glyph_3d::m_RGBA_location = -1;
thread_local GLint kiwi::glyph_3d::m_alpha_discard_location = -1;
thread_local GLint kiwi::glyph_3d::m_mvp_matrix_location = -1;


kiwi::glyph_3d::glyph_3d() noexcept
{
	m_static_instance_count++;
}

kiwi::glyph_3d::~glyph_3d()
{
	m_static_instance_count--;
	if (m_static_instance_count == 0)
	{
		m_default_atlas_texture.delete_id();
		m_program.delete_program();

		m_XY_UV_size_location = -1;
		m_RGBA_location = -1;
		m_mvp_matrix_location = -1;
	}
}

bool kiwi::glyph_3d::init(std::size_t glyph_capacity)
{
	bool success = false;

	if (m_program.get_id() == 0)
	{
		success = m_program.new_program(
			kiwi::source::glyph_3d::vertex_shader(),
			kiwi::source::glyph_3d::fragment_shader()
		);

		if (success)
		{
			m_XY_UV_size_location = m_program.new_uniform_location("u_XY_UV_size");
			m_plane_location = m_program.new_uniform_location("u_right_up_orig");
			m_RGBA_location = m_program.new_uniform_location("u_RGBA");
			m_alpha_discard_location = m_program.new_uniform_location("u_alpha_discard");
			m_program.set_uniform_4f(m_RGBA_location, GL1, GL1, GL1, GL1);
			m_mvp_matrix_location = m_program.new_uniform_location("u_mvp_M");
		}
	}

	try
	{
		if (m_default_atlas_texture.get_id() == 0)
		{
			generate_default_atlas_texture();
		}

		m_XY_UV_shift_temp_buffer.resize(m_packet_size * 4);
	}
	catch (...)
	{
		success = false;
	}

	m_XY_UV_coordinates.allocate(glyph_capacity * (4 * sizeof(GLfloat)));

	generate_default_atlas_function();

	m_capacity = glyph_capacity;
	m_glyph_count = 0;
	m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
	m_buffer_end_ptr = m_XY_UV_shift_temp_buffer.data() + (m_packet_size * 4);

	return success;
}

kiwi::glyph_3d& kiwi::glyph_3d::use_default_atlas()
{
	m_atlas_texture = &m_default_atlas_texture;
	generate_default_atlas_function();
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr, std::function<void(const int, const int, GLfloat* ptr)> atlas_function,
	GLfloat atlas_tile_width, GLfloat atlas_tile_height)
{
	m_atlas_texture = atlas_texture_ptr;
	m_atlas_coordinate_function = std::move(atlas_function);
	m_XY_UV_size[2] = atlas_tile_width;
	m_XY_UV_size[3] = atlas_tile_height;
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_atlas_texture(const kiwi::texture_buffer* const atlas_texture_ptr)
{
	m_atlas_texture = atlas_texture_ptr;
	return *this;
}

const kiwi::texture_buffer* kiwi::glyph_3d::get_atlas_texture() const noexcept
{
	if (m_atlas_texture != &m_default_atlas_texture)
	{
		return m_atlas_texture;
	}
	else
	{
		return nullptr;
	}
}

kiwi::glyph_3d& kiwi::glyph_3d::set_origin(GLfloat X, GLfloat Y) noexcept
{
	m_origin[0] = X;
	m_origin[1] = Y;
	m_XY[0] = GL0;
	m_XY[1] = GL0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_origin(const GLfloat* const XY_ptr) noexcept
{
	m_origin[0] = *XY_ptr;
	m_origin[1] = *(XY_ptr + 1);
	m_XY[0] = GL0;
	m_XY[1] = GL0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_plane(const kiwi::XYZ& origin_3d, const kiwi::XYZ& right_axis, const kiwi::XYZ& up_axis) noexcept
{
	std::memcpy(static_cast<GLfloat*>(m_right_up_orig), right_axis.data(), 3 * sizeof(GLfloat));
	std::memcpy(static_cast<GLfloat*>(m_right_up_orig) + 3, up_axis.data(), 3 * sizeof(GLfloat));
	std::memcpy(static_cast<GLfloat*>(m_right_up_orig) + 6, origin_3d.data(), 3 * sizeof(GLfloat));
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_plane(const GLfloat* const origin_3d_ptr, const GLfloat* const right_axis_ptr, const GLfloat* const up_axis_ptr) noexcept
{
	GLfloat arr[9];
	std::memcpy(static_cast<GLfloat*>(arr), right_axis_ptr, 3 * sizeof(GLfloat));
	std::memcpy(static_cast<GLfloat*>(arr) + 3, up_axis_ptr, 3 * sizeof(GLfloat));
	std::memcpy(static_cast<GLfloat*>(arr) + 6, origin_3d_ptr, 3 * sizeof(GLfloat));
	m_program.set_uniform_3x3f(m_plane_location, static_cast<GLfloat*>(arr));
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_tile_size(GLfloat width, GLfloat height, GLfloat horizontal_offset, GLfloat vertical_offset) noexcept
{
	m_XY_UV_size[0] = width;
	m_XY_UV_size[1] = height;
	m_X_offset = width + horizontal_offset;
	m_X_offset_inv = GL1 / m_X_offset;
	m_Y_offset = height + vertical_offset;
	m_Y_offset_inv = GL1 / m_Y_offset;
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	m_RGBA[0] = R;
	m_RGBA[1] = G;
	m_RGBA[2] = B;
	m_RGBA[3] = A;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_alpha_discard(GLfloat alpha_discard) noexcept
{
	m_alpha_discard = alpha_discard;
	return *this;
}


kiwi::glyph_3d& kiwi::glyph_3d::append_text(const char* const ptr) noexcept
{
	const char* glyph_ptr = ptr;

	while (m_glyph_count < m_capacity)
	{
		if ((*glyph_ptr != 0) && (*glyph_ptr != '\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_text(const char* const ptr, std::size_t glyph_count) noexcept
{
	const char* glyph_ptr = ptr;
	const char* glyph_end_ptr = ptr + glyph_count;

	while (m_glyph_count < m_capacity)
	{
		if ((glyph_ptr != glyph_end_ptr) && (*glyph_ptr != '\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_text(char glyph) noexcept
{
	if (m_glyph_count < m_capacity)
	{
		if (glyph != '\n')
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(glyph), 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_wtext(const wchar_t* const ptr) noexcept
{
	const wchar_t* glyph_ptr = ptr;

	while (m_glyph_count < m_capacity)
	{
		if ((*glyph_ptr != 0) && (*glyph_ptr != L'\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_wtext(const wchar_t* const ptr, std::size_t glyph_count) noexcept
{
	const wchar_t* glyph_ptr = ptr;
	const wchar_t* glyph_end_ptr = ptr + glyph_count;

	while (m_glyph_count < m_capacity)
	{
		if ((glyph_ptr != glyph_end_ptr) && (*glyph_ptr != L'\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_wtext(wchar_t glyph) noexcept
{
	if (m_glyph_count < m_capacity)
	{
		if (glyph != L'\n')
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(glyph), 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_glyph(const int* const ptr, std::size_t glyph_count) noexcept
{
	const int* glyph_ptr = ptr;
	const int* glyph_end_ptr = ptr + glyph_count;

	while (glyph_ptr != glyph_end_ptr && m_glyph_count < m_capacity)
	{
		m_XY[0] += m_X_offset;
		*m_buffer_current_ptr = m_XY[0];
		*(m_buffer_current_ptr + 1) = m_XY[1];
		m_atlas_coordinate_function(*glyph_ptr++, 0, m_buffer_current_ptr + 2);

		m_glyph_count++;
		m_buffer_current_ptr += 4;

		if (m_buffer_current_ptr == m_buffer_end_ptr)
		{
			m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
				(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
				m_packet_size * 4 * sizeof(GLfloat));

			m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_glyph(const int* const ptr, std::size_t glyph_count, int end_line_glyph) noexcept
{
	const int* glyph_ptr = ptr;
	const int* glyph_end_ptr = ptr + glyph_count;

	while (m_glyph_count < m_capacity)
	{
		if ((glyph_ptr != glyph_end_ptr) && (*glyph_ptr != end_line_glyph))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(*glyph_ptr++, 0, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == end_line_glyph)
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_glyph(int glyph) noexcept
{
	if (m_glyph_count < m_capacity)
	{
		m_XY[0] += m_X_offset;
		*m_buffer_current_ptr = m_XY[0];
		*(m_buffer_current_ptr + 1) = m_XY[1];
		m_atlas_coordinate_function(glyph, 0, m_buffer_current_ptr + 2);

		m_glyph_count++;
		m_buffer_current_ptr += 4;

		if (m_buffer_current_ptr == m_buffer_end_ptr)
		{
			m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
				(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
				m_packet_size * 4 * sizeof(GLfloat));

			m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::update_text(std::size_t glyph_number, char glyph) noexcept
{
	finish_loading();

	m_atlas_coordinate_function(static_cast<int>(glyph), 0, static_cast<GLfloat*>(m_XY) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::update_wtext(std::size_t glyph_number, wchar_t glyph) noexcept
{
	finish_loading();

	m_atlas_coordinate_function(static_cast<int>(glyph), 0, static_cast<GLfloat*>(m_XY) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::update_glyph(std::size_t glyph_number, int glyph) noexcept
{
	finish_loading();

	m_atlas_coordinate_function(glyph, 0, static_cast<GLfloat*>(m_XY) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}


kiwi::glyph_3d& kiwi::glyph_3d::append_text_modded(int mod_number, const char* const ptr) noexcept
{
	const char* glyph_ptr = ptr;

	while (m_glyph_count < m_capacity)
	{
		if ((*glyph_ptr != 0) && (*glyph_ptr != '\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_text_modded(int mod_number, const char* const ptr, std::size_t glyph_count) noexcept
{
	const char* glyph_ptr = ptr;
	const char* glyph_end_ptr = ptr + glyph_count;

	while (m_glyph_count < m_capacity)
	{
		if ((glyph_ptr != glyph_end_ptr) && (*glyph_ptr != '\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_text_modded(int mod_number, char glyph) noexcept
{
	if (m_glyph_count < m_capacity)
	{
		if (glyph != '\n')
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(glyph), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_wtext_modded(int mod_number, const wchar_t* const ptr) noexcept
{
	const wchar_t* glyph_ptr = ptr;

	while (m_glyph_count < m_capacity)
	{
		if ((*glyph_ptr != 0) && (*glyph_ptr != L'\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_wtext_modded(int mod_number, const wchar_t* const ptr, std::size_t glyph_count) noexcept
{
	const wchar_t* glyph_ptr = ptr;
	const wchar_t* glyph_end_ptr = ptr + glyph_count;

	while (m_glyph_count < m_capacity)
	{
		if ((glyph_ptr != glyph_end_ptr) && (*glyph_ptr != L'\n'))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(*glyph_ptr++), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == '\n')
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_wtext_modded(int mod_number, wchar_t glyph) noexcept
{
	if (m_glyph_count < m_capacity)
	{
		if (glyph != L'\n')
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function(static_cast<int>(glyph), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_glyph_modded(int mod_number, const int* const ptr, std::size_t glyph_count) noexcept
{
	const int* glyph_ptr = ptr;
	const int* glyph_end_ptr = ptr + glyph_count;

	while (glyph_ptr != glyph_end_ptr && m_glyph_count < m_capacity)
	{
		m_XY[0] += m_X_offset;
		*m_buffer_current_ptr = m_XY[0];
		*(m_buffer_current_ptr + 1) = m_XY[1];
		m_atlas_coordinate_function((*glyph_ptr++), mod_number, m_buffer_current_ptr + 2);

		m_glyph_count++;
		m_buffer_current_ptr += 4;

		if (m_buffer_current_ptr == m_buffer_end_ptr)
		{
			m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
				(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
				m_packet_size * 4 * sizeof(GLfloat));

			m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_glyph_modded(int mod_number, const int* const ptr, std::size_t glyph_count, int end_line_glyph) noexcept
{
	const int* glyph_ptr = ptr;
	const int* glyph_end_ptr = ptr + glyph_count;

	while (m_glyph_count < m_capacity)
	{
		if ((glyph_ptr != glyph_end_ptr) && (*glyph_ptr != end_line_glyph))
		{
			m_XY[0] += m_X_offset;
			*m_buffer_current_ptr = m_XY[0];
			*(m_buffer_current_ptr + 1) = m_XY[1];
			m_atlas_coordinate_function((*glyph_ptr++), mod_number, m_buffer_current_ptr + 2);

			m_glyph_count++;
			m_buffer_current_ptr += 4;

			if (m_buffer_current_ptr == m_buffer_end_ptr)
			{
				m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
					(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
					m_packet_size * 4 * sizeof(GLfloat));

				m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
			}
		}
		else if (*glyph_ptr == end_line_glyph)
		{
			m_XY[0] = m_origin[0];
			m_XY[1] -= m_Y_offset;
			glyph_ptr++;
		}
		else
		{
			break;
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::append_glyph_modded(int mod_number, int glyph) noexcept
{
	if (m_glyph_count < m_capacity)
	{
		m_XY[0] += m_X_offset;
		*m_buffer_current_ptr = m_XY[0];
		*(m_buffer_current_ptr + 1) = m_XY[1];
		m_atlas_coordinate_function(glyph, mod_number, m_buffer_current_ptr + 2);

		m_glyph_count++;
		m_buffer_current_ptr += 4;

		if (m_buffer_current_ptr == m_buffer_end_ptr)
		{
			m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
				(m_glyph_count - m_packet_size) * (4 * sizeof(GLfloat)),
				m_packet_size * 4 * sizeof(GLfloat));

			m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
		}
	}

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::update_text_modded(int mod_number, std::size_t glyph_number, char glyph) noexcept
{
	finish_loading();

	m_atlas_coordinate_function(static_cast<int>(glyph), mod_number, static_cast<GLfloat*>(m_XY) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::update_wtext_modded(int mod_number, std::size_t glyph_number, wchar_t glyph) noexcept
{
	finish_loading();

	m_atlas_coordinate_function(static_cast<int>(glyph), mod_number, static_cast<GLfloat*>(m_XY) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::update_glyph_modded(int mod_number, std::size_t glyph_number, int glyph) noexcept
{
	finish_loading();

	m_atlas_coordinate_function(glyph, mod_number, static_cast<GLfloat*>(m_XY) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}


kiwi::glyph_3d& kiwi::glyph_3d::space(std::size_t glyph_count) noexcept
{
	m_XY[0] += static_cast<GLfloat>(glyph_count) * m_X_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::end_line() noexcept
{
	m_XY[0] = m_origin[0];
	m_XY[1] -= m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::end_line(GLfloat lines_down) noexcept
{
	m_XY[0] = m_origin[0];
	m_XY[1] += lines_down * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_XY(GLfloat X, GLfloat Y) noexcept
{
	m_XY[0] = m_origin[0] + X * m_X_offset;
	m_XY[1] = m_origin[1] - Y * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_XY[0] = m_origin[0] + *XY_ptr * m_X_offset;
	m_XY[1] = m_origin[1] - *(XY_ptr + 1) * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_X(GLfloat X) noexcept
{
	m_XY[0] = m_origin[0] + X * m_X_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::set_Y(GLfloat Y) noexcept
{
	m_XY[1] = m_origin[1] - Y * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::move_XY(GLfloat X_offset, GLfloat Y_offset) noexcept
{
	m_XY[0] = m_origin[0] + X_offset * m_X_offset;
	m_XY[1] = m_origin[1] - Y_offset * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::move_XY(const GLfloat* const XY_offset_ptr) noexcept
{
	m_XY[0] += *XY_offset_ptr * m_X_offset;
	m_XY[1] -= *(XY_offset_ptr + 1) * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::move_X(GLfloat X_offset) noexcept
{
	m_XY[0] += X_offset * m_X_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::move_Y(GLfloat Y_offset) noexcept
{
	m_XY[1] -= Y_offset * m_Y_offset;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::draw_with(const GLfloat* const mvp_matrix_ptr) noexcept
{
	finish_loading();

	m_XY_UV_coordinates.to_binding(0);
	m_atlas_texture->to_binding(0);

	m_program.set_uniform_4f(m_XY_UV_size_location, static_cast<GLfloat*>(m_XY_UV_size))
		.set_uniform_3x3f(m_plane_location, static_cast<GLfloat*>(m_right_up_orig))
		.set_uniform_4f(m_RGBA_location, static_cast<GLfloat*>(m_RGBA))
		.set_uniform_1f(m_alpha_discard_location, m_alpha_discard)
		.set_uniform_4x4f(m_mvp_matrix_location, mvp_matrix_ptr);

	glDrawArrays(GL_QUADS, 0, 4 * static_cast<GLsizei>(m_glyph_count));
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::draw_with(const GLfloat* const mvp_matrix_ptr, std::size_t begin_glyph, std::size_t glyph_count) noexcept
{
	finish_loading();

	m_XY_UV_coordinates.to_binding(0);
	m_atlas_texture->to_binding(0);

	m_program.set_uniform_4f(m_XY_UV_size_location, static_cast<GLfloat*>(m_XY_UV_size))
		.set_uniform_3x3f(m_plane_location, static_cast<GLfloat*>(m_right_up_orig))
		.set_uniform_4f(m_RGBA_location, static_cast<GLfloat*>(m_RGBA))
		.set_uniform_1f(m_alpha_discard_location, m_alpha_discard)
		.set_uniform_4x4f(m_mvp_matrix_location, mvp_matrix_ptr);

	glDrawArrays(GL_QUADS, 4 * static_cast<GLsizei>(begin_glyph), 4 * static_cast<GLsizei>(glyph_count));
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::clear_buffer() noexcept
{
	m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();

	m_XY[0] = m_origin[0];
	m_XY[1] = m_origin[1];
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::clear_buffer(std::size_t glyph_count) noexcept
{
	finish_loading();

	m_glyph_count = (glyph_count < m_glyph_count) ? m_glyph_count - glyph_count : 0;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::clear_buffer_after(std::size_t glyph_number) noexcept
{
	finish_loading();

	m_glyph_count = (glyph_number < m_glyph_count) ? glyph_number : m_glyph_count;
	return *this;
}

kiwi::glyph_3d& kiwi::glyph_3d::finish_loading() noexcept
{
	if (m_buffer_current_ptr != m_XY_UV_shift_temp_buffer.data())
	{
		std::size_t remainder = static_cast<std::size_t>(m_buffer_current_ptr - m_XY_UV_shift_temp_buffer.data());

		m_XY_UV_coordinates.substitute(m_XY_UV_shift_temp_buffer.data(),
			(m_glyph_count - remainder / 4) * (4 * sizeof(GLfloat)),
			remainder * sizeof(GLfloat));
	}

	m_buffer_current_ptr = m_XY_UV_shift_temp_buffer.data();
	return *this;
}

GLfloat kiwi::glyph_3d::get_X() const noexcept
{
	return m_X_offset_inv * (m_XY[0] - m_origin[0]);
}

GLfloat kiwi::glyph_3d::get_Y() const noexcept
{
	return m_Y_offset_inv * (m_origin[1] - m_XY[1]);
}

GLfloat kiwi::glyph_3d::get_X_free() const noexcept
{
	return m_XY[0];
}

GLfloat kiwi::glyph_3d::get_Y_free() const noexcept
{
	return m_XY[1];
}

std::size_t kiwi::glyph_3d::glyph_count() const noexcept
{
	return m_glyph_count;
}

std::size_t kiwi::glyph_3d::capacity() const noexcept
{
	return m_capacity;
}

void kiwi::glyph_3d::generate_default_atlas_function()
{
	m_atlas_coordinate_function = [](const int val, const int mod_number, GLfloat* ptr)
	{
		constexpr GLfloat X_offset_factor = static_cast<GLfloat>(14) / static_cast<GLfloat>(1330);
		constexpr GLfloat Y_offset_factor = GL1 / static_cast<GLfloat>(m_number_of_default_colors);
		*ptr = X_offset_factor * static_cast<GLfloat>(val - static_cast<int>(' '));
		*(ptr + 1) = Y_offset_factor * static_cast<GLfloat>(mod_number);
	};
	constexpr GLfloat X_offset_factor = static_cast<GLfloat>(14) / static_cast<GLfloat>(1330);
	constexpr GLfloat Y_offset_factor = GL1 / static_cast<GLfloat>(m_number_of_default_colors);
	m_XY_UV_size[2] = X_offset_factor;
	m_XY_UV_size[3] = Y_offset_factor;
}

void kiwi::glyph_3d::generate_default_atlas_texture()
{
	std::string str =
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000300000cc00c000c30fc00000030c00000000003000000e000000f30ff3cff0cf00030ff00f30c000f30ef00000c0000000"
		"0000000300f70303cf30cf0cf30ff3c000cf0c0c0ff30f30303cff0303c0c0cf0c000c33c0c0ff00c00cf00c00303c0c0030cff00f00000c300000ff30000cf3"
		"cf30cf00ff0cf10300ef0c0c0ff3cf303038f70303c0c0cf0c000003c000ff00c70cf30c00cc0c0c0ef0cff00c00c00c0000000000c00000033003000f0ef300"
		"000e007000000000c1000008300000ef1cff0ff38f700c0cf70ef10300ef18f70000070000000000000c00ef1c0c0ff18f70ff1cff03008f70303cff0ef1c0c0"
		"ff3c0c03038f703008ff0303cf700308f70870c1e03030c00ff30c300000f00000cff00008ff0ff18f70ef38f70c008f70303cff0ff1c0c0ef1c0c03038f7030"
		"000c0300cf708f18ff08708f707838f70ff30830030070000000000000000cc0cf303c3c9700000c108300c000300e000000e00300c1e003083007830030083c"
		"0e0c00c1e00830e0083000300000300000c100303c0e0783c0e0300c000783c0c0030c1e0303c000303c0c0783c0007c1c0c00830c007830f30fc3c0c0030c00"
		"003000c003000000000000703c0e0783c1c07000300083c0c003000e03830c00303c0c0783c000003c00008307007030f30ff3837008383000700c0083000000"
		"0000000000330ff1c1f03e100008300c106b10c000300000000c1007030c00c10c0c00c000c0303030030300c08300c000e00000c100000300c0c0303c0c0303"
		"c000300c0c03030c00303c0e0300c0c0383c0c0300c87030300c0030c0c0ec1cff07830c007000c000830c000000000000c1c0303c0c0303c000c0000c03030c"
		"00003c070030c0c0303c0c0ff00ff030000e0c00c0c0ec1ccc0cf000c0c100c000300c0000000000300000ff30ce0e00ccf000007000e08f700300e000000000"
		"e00c3c00300e000030030003c0c0c00c0c00030e008300c10ff30e00030ccf0303c0c0300c0c0300c000303c0c003000c03c1c000303c0f0303c000373c0c000"
		"30c00303c1e0b7383700308300030007003000000000000ef3c0c0300c0c0ff30300cf3c0c003000c03e00c00333c0c0303cf70ef3c000cf10300303c1e03330"
		"e10cf30e000300c0003000000000c00000cff00b30700b330000c000030cf00c0083000000000700f130c0007000e0ff300e0383070078300c00000e00830cff"
		"00700c103f3c0c0303c000303c000300c0f03030c00003c830300c0c03e3c0c0300ccc038300e0030c0c0303ccc0cf00c00c100c000e00c0000000000000ff03"
		"03c000303cff0c008ff03030c00003cf10030ccc0303c0c0383c1c07008f30c00c0c0303c0c08708ff00700e000300c1000000000300000cc00f708308700000"
		"03000c0cff0ff30000ff30000830cec003008300f1cff0ff1cf708308f70cf30000000070000008300e0ccc0ff3cf70300c0c0ff0cf303c3cff003000c0f70c0"
		"00303ccd0303cf30303cf70cf10c00303c0c03030e100300e000300c1003000000000000003c0c0303c0c03030300703c0c003000c0f700c00333c0c0303c0c0"
		"303c3c07000300303c0c03030f307030830c100c000e0cc300000c000000330ef00c10e100000c000030ff3cff0000cff00000c103730c000c10c703c0cf30ff"
		"00c10ef18ff00000000c1000000e00070333cff0ff1c000303cf30ff0c000ff30c00003cf10300c0c0b33c0c0ff1c0c0ff18f30030c0c0303c0c08700e100700"
		"c008300c00000000000000e0383c1e0703c1e0ff1c1c03830c00003c830030cff0383c1e0383c1c0f93c100c00c0c0303c0c0ec1c0c00c107000300830ff1000"
		"00300000ff3cd000e0ce0000003000c00f30030000000000000e0c8f033000e0083c030300c0000e0c1e070300000000e00ff30c10383ccf0303c0c0300c0c03"
		"00c000300c0c003000c03e0c000333c7c0303c0e0303c0e07000c00303c0c03030f30cf00830030070003000000000000ef1cf70ef18ff0ef1cf70ef3cf70e30"
		"0cf03c10c00ff1cf70ef1cf70ef3ce70ef3cf30303c0c0303c1e0303cff08300c0007087e00000c00000cff073000703700c00c100830ef10c00000000000000"
		"703c3cd0000300c07c0c0003000070303c0c08300e00070cff0830c0c03f3c0c0303c000303c000300c0003030c00003c070300ced0f03c0c0303c0c0303c000"
		"030c0c0303c0c0ec183700c10c00e000c0000000000008f30ff00f30cf30f30c000ff0ff08f000f3c060030c330ff00f30ff00ff03f00ff0ff0c0c0303c0c030"
		"3c0c0ff30c000300c00c0300000300330cc08ff0f83c8100300e000708d6003000000000000083c0e0e30c0c03038330300c000083c0c03030e0083008300000"
		"700303c0c0303c0c0303c0c0300c000303c0c003000c0383c000ff3c1c0303c0c0303c0c03000c00303c0c0303c1e078300e0030c10003003300000c00000c00"
		"000000c00000300000c00000000003000c0000000000000000000000000003000000000000000000000000300c0003000000000c00cc00330cf3c3c07600c000"
		"700e000300c00000000000000c07830f00783c1e0cd0c00070000c0783c1e08300e000c00000c00c1e0783c1e0383c1e0383c000300c1e03030c00003c0c0300"
		"c3f0303c1e0383c1e0383c100030c0c0303c0c0303c0c00030c003000c00cf00000830000030000000030000c1000003000000000c0000300000000000000000"
		"000000000c000000000000000000000000c100300e0000000000300330cc00c00f008f100300830c100000000000000000000008f708308f70ef10e30ff38f70"
		"ff38f70ef1000000000000000000ef18f70ef1cf70ef1cf70ff3cff0ef1c0c0ff3cff0303c000783c0c0ef1cf70ef1cf70ef3cff0303c0c0303c0c0303cff00f"
		"00000c300e100000700000c00000000c00000e30000c00003000c03000f0000000000000000000000000003000000000000000000000000e00c00c1000000000"
		"c00cc00330030c300c300c000c00300000000000000000000000cf00c00cf00f300f0cff0cf1cff0cf00f30000000000000000000f30cf00f30ff00f30ff0cff"
		"0ff30f30303cff0ff3c0c0300c0c03030f30ff00f30ff00ff0ff3c0c0303c0c0303c0c0ff30c300000f000300000c000000300000000300000f000003000c000"
		"03c000c300000000000000000000000000c000000000000000000000000030030030000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

	std::vector<unsigned char> ustr(16 * m_number_of_default_colors * str.size(), 0);

	unsigned char color4x8[m_number_of_default_colors][4] = {
		{ 255, 255, 255, 255 },
		{ 0, 0, 0, 255 },
		{ 255, 0, 0, 255 },
		{ 0, 255, 0, 255 },
		{ 0, 0, 255, 255 },
		{ 255, 255, 0, 255 },
		{ 0, 255, 255, 255 },
		{ 255, 0, 255, 255 }
	};

	std::uint32_t* ptr32 = reinterpret_cast<std::uint32_t*>(ustr.data());

	for (std::size_t color_index = 0; color_index < m_number_of_default_colors; color_index++)
	{
		for (std::size_t n = 0; n < str.size(); n++)
		{
			char current_char = str[n];
			unsigned int dispatch = static_cast<unsigned int>(0);

			if (current_char <= '9')
			{
				dispatch = static_cast<unsigned int>(current_char - '0');
			}
			else if ('a' <= current_char)
			{
				dispatch = static_cast<unsigned int>(current_char - 'a') + static_cast<unsigned int>(10);
			}

			if (dispatch & static_cast<unsigned int>(1)) { *(ptr32 + 0) = *reinterpret_cast<std::uint32_t*>(color4x8[color_index]); }
			if (dispatch & static_cast<unsigned int>(2)) { *(ptr32 + 1) = *reinterpret_cast<std::uint32_t*>(color4x8[color_index]); }
			if (dispatch & static_cast<unsigned int>(4)) { *(ptr32 + 2) = *reinterpret_cast<std::uint32_t*>(color4x8[color_index]); }
			if (dispatch & static_cast<unsigned int>(8)) { *(ptr32 + 3) = *reinterpret_cast<std::uint32_t*>(color4x8[color_index]); }
			ptr32 += 4;
		}
	}

	m_default_atlas_texture.load(ustr.data(), kiwi::size(1330, 18 * m_number_of_default_colors), 4,
		kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
}