#include "rendering/kiwi_glyph_2d.hpp"


thread_local unsigned int kiwi::glyph_2d::m_static_instance_count = 0;
thread_local kiwi::program kiwi::glyph_2d::m_text_program = kiwi::program();
thread_local kiwi::vertex_buffer kiwi::glyph_2d::m_XY = kiwi::vertex_buffer();
thread_local kiwi::texture_buffer kiwi::glyph_2d::m_default_atlas_texture = kiwi::texture_buffer();

thread_local GLint kiwi::glyph_2d::m_uniform_XY_UV_size = -1;
thread_local GLint kiwi::glyph_2d::m_uniform_RGBA = -1;
thread_local GLint kiwi::glyph_2d::m_uniform_mvp_matrix = -1;

thread_local GLfloat kiwi::glyph_2d::m_XY_UV_shift[4] = {
	static_cast<GLfloat>(0),
	static_cast<GLfloat>(0),
	static_cast<GLfloat>(0),
	static_cast<GLfloat>(0)
};


kiwi::glyph_2d::glyph_2d() noexcept
{
	m_static_instance_count++;
}

kiwi::glyph_2d::~glyph_2d()
{
	m_static_instance_count--;
	if (m_static_instance_count == 0)
	{
		m_default_atlas_texture.delete_id();
		m_text_program.delete_program();
		m_XY.delete_id();

		m_uniform_XY_UV_size = -1;
		m_uniform_RGBA = -1;
		m_uniform_mvp_matrix = -1;
	}
}

kiwi::glyph_2d& kiwi::glyph_2d::init(std::size_t char_capacity)
{

	if (m_text_program.get_id() == 0)
	{
		m_text_program.new_program(

			"	#version 430 core																	\n"
			"	layout (location = 0) in vec2 in_XY;												\n"
			"	layout (std430, binding = 0) buffer s_XY_UV_shift { vec2[][2] u_XY_UV_shift; };		\n"
			"	uniform vec4 u_XY_UV_size;															\n"
			"	uniform mat3 u_mvp_M;																\n"
			"	out vec2 UV;																		\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 in_XYh = u_mvp_M * vec3(u_XY_UV_shift[gl_InstanceID][0]					\n"
			"			+ in_XY * u_XY_UV_size.xy, 1.0);											\n"

			"		gl_Position = vec4(in_XYh[0], in_XYh[1], 0.0, 1.0);								\n"

			"		UV = u_XY_UV_shift[gl_InstanceID][1] + in_XY * u_XY_UV_size.zw;					\n"
			"	}																					\n"

			,

			"	#version 330 core																	\n"
			"	in vec2 UV;																			\n"
			"	uniform vec4 u_color;																\n"
			"	out vec4 color;																		\n"
			"	uniform sampler2D Tx;																\n"
			"	void main()																			\n"
			"	{																					\n"
			"		color = u_color * texture(Tx, UV);												\n"
			"	}																					\n"
		);

		m_uniform_XY_UV_size = m_text_program.new_uniform_location("u_XY_UV_size");
		m_uniform_RGBA = m_text_program.new_uniform_location("u_color");
		m_text_program.set_uniform_4f(m_uniform_RGBA, GL1, GL1, GL1, GL1);
		m_uniform_mvp_matrix = m_text_program.new_uniform_location("u_mvp_M");
	}

	if (m_XY.get_id() == 0)
	{
		GLfloat arr[8] = { GL0, GL0, GL1, GL0, GL1, GL1, GL0, GL1 };
		m_XY.load(static_cast<GLfloat*>(arr), 4, 2);
	}

	if (m_default_atlas_texture.get_id() == 0)
	{
		generate_default_atlas_texture();
	}

	m_XY_UV_coordinates.allocate(char_capacity * (4 * sizeof(GLfloat)));

	generate_default_atlas_function();

	m_capacity = char_capacity;
	m_glyph_count = 0;

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::use_default_atlas()
{
	m_atlas_texture = &m_default_atlas_texture;
	generate_default_atlas_function();
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr, std::function<void(const int, GLfloat* ptr)> atlas_function)
{
	m_atlas_texture = atlas_texture_ptr;
	m_atlas_coordinate_function = std::move(atlas_function);
	m_glyph_count = 0;
	return *this;
}

const kiwi::texture_buffer* kiwi::glyph_2d::get_atlas_texture() const noexcept
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

kiwi::glyph_2d& kiwi::glyph_2d::set_origin(GLfloat X, GLfloat Y) noexcept
{
	m_origin[0] = X;
	m_origin[1] = Y;
	m_XY_UV_shift[0] = X;
	m_XY_UV_shift[1] = Y;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::set_tile_size(GLfloat width, GLfloat height, GLfloat horizontal_offset, GLfloat vertical_offset) noexcept
{
	m_XY_UV_size[0] = width;
	m_XY_UV_size[1] = height;
	m_glyph_offset = width + horizontal_offset;
	m_endline_offset = height + vertical_offset;
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::set_atlas_tile_size(GLfloat width, GLfloat height) noexcept
{
	m_XY_UV_size[2] = width;
	m_XY_UV_size[3] = height;
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	m_RGBA[0] = R;
	m_RGBA[1] = G;
	m_RGBA[2] = B;
	m_RGBA[3] = A;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_text(const char* const ptr) noexcept
{
	for (std::size_t n = 0; n < m_capacity; n++)
	{
		if (*(ptr + n) != 0)
		{
			m_atlas_coordinate_function(static_cast<int>(*(ptr + n)), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
			m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
				m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
			
			m_XY_UV_shift[0] += m_glyph_offset;
			m_glyph_count++;
		}
		else
		{
			return *this;
		}
	}

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_text(const char* const ptr, std::size_t glyph_count) noexcept
{
	for (std::size_t n = 0; n < glyph_count; n++)
	{
		m_atlas_coordinate_function(static_cast<int>(*(ptr + n)), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
		m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
			m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

		m_XY_UV_shift[0] += m_glyph_offset;
		m_glyph_count++;
	}

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_text(char glyph) noexcept
{
	m_atlas_coordinate_function(static_cast<int>(glyph), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
		m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

	m_XY_UV_shift[0] += m_glyph_offset;
	m_glyph_count++;

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_wtext(const wchar_t* const ptr) noexcept
{
	for (std::size_t n = 0; n < m_capacity; n++)
	{
		if (*(ptr + n) != 0)
		{
			m_atlas_coordinate_function(static_cast<int>(*(ptr + n)), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
			m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
				m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

			m_XY_UV_shift[0] += m_glyph_offset;
			m_glyph_count++;
		}
		else
		{
			return *this;
		}
	}

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_wtext(const wchar_t* const ptr, std::size_t glyph_count) noexcept
{
	for (std::size_t n = 0; n < glyph_count; n++)
	{
		m_atlas_coordinate_function(static_cast<int>(*(ptr + n)), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
		m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
			m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

		m_XY_UV_shift[0] += m_glyph_offset;
		m_glyph_count++;
	}

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_wtext(wchar_t glyph) noexcept
{
	m_atlas_coordinate_function(static_cast<int>(glyph), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
		m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

	m_XY_UV_shift[0] += m_glyph_offset;
	m_glyph_count++;

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_glyph(const int* const ptr, std::size_t glyph_count) noexcept
{
	for (std::size_t n = 0; n < glyph_count; n++)
	{
		m_atlas_coordinate_function(*(ptr + n), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
		m_XY_UV_coordinates.substitute(m_XY_UV_shift, m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

		m_XY_UV_shift[0] += m_glyph_offset;
		m_glyph_count++;
	}

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::append_glyph(int glyph) noexcept
{
	m_atlas_coordinate_function(glyph, static_cast<GLfloat*>(m_XY_UV_shift) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift),
		m_glyph_count * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));

	m_XY_UV_shift[0] += m_glyph_offset;
	m_glyph_count++;

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::update_text(std::size_t glyph_number, char glyph) noexcept
{
	m_atlas_coordinate_function(static_cast<int>(glyph), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::update_wtext(std::size_t glyph_number, wchar_t glyph) noexcept
{
	m_atlas_coordinate_function(static_cast<int>(glyph), static_cast<GLfloat*>(m_XY_UV_shift) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::update_glyph(std::size_t glyph_number, int glyph) noexcept
{
	m_atlas_coordinate_function(glyph, static_cast<GLfloat*>(m_XY_UV_shift) + 2);
	m_XY_UV_coordinates.substitute(static_cast<GLfloat*>(m_XY_UV_shift) + 2,
		glyph_number * (4 * sizeof(GLfloat)) + (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));

	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::space(std::size_t glyph_count) noexcept
{
	m_XY_UV_shift[0] += static_cast<GLfloat>(glyph_count) * m_glyph_offset;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::end_line() noexcept
{
	m_XY_UV_shift[0] = m_origin[0];
	m_XY_UV_shift[1] -= m_endline_offset;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::end_line_up() noexcept
{
	m_XY_UV_shift[0] = m_origin[0];
	m_XY_UV_shift[1] += m_endline_offset;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::jump_to(GLfloat X, GLfloat Y) noexcept
{
	m_XY_UV_shift[0] = m_origin[0] + X * m_glyph_offset;
	m_XY_UV_shift[1] = m_origin[1] - Y * m_endline_offset;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::draw_with() noexcept
{
	m_XY_UV_coordinates.to_binding(0);
	m_XY.to_location(0);
	m_atlas_texture->bind();

	m_text_program.set_uniform_4f(m_uniform_XY_UV_size, static_cast<GLfloat*>(m_XY_UV_size))
		.set_uniform_4f(m_uniform_RGBA, static_cast<GLfloat*>(m_RGBA))
		.set_uniform_3x3f(m_uniform_mvp_matrix, kiwi::window_matrix_data());

	glDrawArraysInstanced(GL_QUADS, 0, 4, static_cast<GLsizei>(m_glyph_count));
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::draw_with(const GLfloat* const mvp_matrix_ptr) noexcept
{
	m_XY_UV_coordinates.to_binding(0);
	m_XY.to_location(0);
	m_atlas_texture->bind();

	m_text_program.set_uniform_4f(m_uniform_XY_UV_size, static_cast<GLfloat*>(m_XY_UV_size))
		.set_uniform_4f(m_uniform_RGBA, static_cast<GLfloat*>(m_RGBA))
		.set_uniform_3x3f(m_uniform_mvp_matrix, mvp_matrix_ptr);

	glDrawArraysInstanced(GL_QUADS, 0, 4, static_cast<GLsizei>(m_glyph_count));
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::clear_buffer() noexcept
{
	m_XY_UV_shift[0] = m_origin[0];
	m_XY_UV_shift[1] = m_origin[1];
	m_glyph_count = 0;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::clear_buffer(std::size_t glyph_count) noexcept
{
	m_glyph_count = (glyph_count < m_glyph_count) ? m_glyph_count - glyph_count : 0;
	return *this;
}

kiwi::glyph_2d& kiwi::glyph_2d::clear_buffer_after(std::size_t glyph_number) noexcept
{
	m_glyph_count = (glyph_number < m_glyph_count) ? glyph_number : m_glyph_count;
	return *this;
}

std::size_t kiwi::glyph_2d::capacity() const noexcept
{
	return m_capacity;
}

void kiwi::glyph_2d::generate_default_atlas_function()
{
	m_atlas_coordinate_function = [](const int val, GLfloat* ptr)
	{
		constexpr GLfloat offset_factor = static_cast<GLfloat>(14) / static_cast<GLfloat>(1330);
		*ptr = offset_factor * static_cast<GLfloat>(val - static_cast<int>(' '));
		*(ptr + 1) = GL0;
	};
	constexpr GLfloat offset_factor = static_cast<GLfloat>(14) / static_cast<GLfloat>(1330);
	m_XY_UV_size[2] = offset_factor;
	m_XY_UV_size[3] = GL1;
}

void kiwi::glyph_2d::generate_default_atlas_texture()
{
	std::string str =
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"000000000000000000000000000000300000cc00c000c30fc00000030c00000000003000000c000000f30ff3cff0cf00030ff00f30c000f30ef00000c0000000"
		"0000000300f70303cf30cf0cf30ff3c000cf0c0c0ff30f30303cff0303c0c0cf0c000c33c0c0ff00c00cf00c00303c0c0030cff00f00000c300000ff30000cf3"
		"cf30cf00ff0cf10300ef0c0c0ff30f303030f30303c0c0cf0c000003c000ff00c30cf30c00cc0c0c0ef0cff00c00c00c0000000000c00000033003000f0ef300"
		"000e007000000000c1000000300000ef1cff0ff38f700c0cf70ef10300ef18f70000070000000000000c00ef1c0c0ff18f70ff1cff03008f70303cff0ef1c0c0"
		"ff3c0c03038f703008ff0303cf700308f70870c1e03030c00ff30c300000f00000cff00008ff0ff18f70ef38f70c008f70303cff0ef1c0c0ef0c0c03038f7030"
		"000c0300cf708f18ff08708f707838f70ff30830030070000000000000000cc0cf303c3c9700000c108300c000300e000000000300c1e003083007830030083c"
		"0e0c00c1e00830c0083000300000300000c100303c0e0783c0e0300c000783c0c0030c1e0303c000303c0c0783c0007c1c0c00830c007830f30fc3c0c0030c00"
		"003000c003000000000000703c0e0783c0c07000300003c0c0030c1e0303c100303c0c0783c000003c00008307e07030f30ff3837008383000700c0083000000"
		"0000000000330ff1c1f03e100008300c106b10c000300000000c1007030c00c10c0c00c000c0303030030300c00300c000e00000c100000300c0c0303c0c0303"
		"c000300c0c03030c00303c0e0300c0c0383c0c0300c87030300c0030c0c0ec1cff07830c007000c000830c000000000000c1c0303c0c0303c000c0000c03030c"
		"00303c0e0300c0c0303c0c0ff00ff030000e0c03c0c0ec1ccc0cf000c0c100c000300c0000000000300000ff30ce0e00ccf000007000e08f700300c000000000"
		"e00c3c00300e000030030003c0c0c00c0c000300000300c10ff30e00030ccf0303c0c0300c0c0300c000303c0c003000c03c1c000303c0f0303c000373c0c000"
		"30c00303c1e0b7383700308300030007003000000000000ef3c0c0300c0c0ff30300cf3c0c003000c03c1c000333c0c0303cf70ef3c000cf10300303c1e03330"
		"e10cf30e000300c0003000000000c00000cff00b30700b330000c000030cf00c0003000000000700f130c0007000e0ff300e0383070078300c00000c00830cff"
		"00700c103f3c0c0303c000303c000300c0f03030c00003c830300c0c03e3c0c0300ccc038300e0030c0c0303ccc0cf00c00c100c000e00c0000000000000ff03"
		"03c000303cff0c008ff03030c00003c830300ccc0303c0c0383c1c03008f30c00c0c0303c0c08708ff00700e000300c1000000000300000cc00f708308700000"
		"03000c0cff0ff30000ff30000830cec003008300f1cff0ff1cf708308f70cf30000000070000008300e0ccc0ff3cf70300c0c0ff0cf303c3cff003000c0f70c0"
		"00303ccd0303cf30303cf70cf10c00303c0c03030e100300e000300c1003000000000000003c0c0303c0c03030300703c0c003000c0f70c000333c0c0303c0c0"
		"303c3c07000300303c0c03030f303030830c100c000e0cc300000c000000330ef00c10e100000c000030ff3cff0000cff00000c103730c000c10c703c0cf30ff"
		"00c10ef18ff00000000c1000000e00070333cff0ff1c000303cf30ff0c000ff30c00003cf10300c0c0b33c0c0ff1c0c0ff18f30030c0c0303c0c08700e100700"
		"c008300c00000000000000e0383c1e0303c1e0ff1c1c03830c00003cf10300cff0383c1e0383c1c0f93c100c00c0c0303c0c0ec1c0c00c107000300830ff1000"
		"00300000ff3cd000e0ce0000003000c00f30030000000000000e0c8f033000e0083c030300c0000e0c1e070300000000e00ff30c10383ccf0303c0c0300c0c03"
		"00c000300c0c003000c03e0c000333c7c0303c0e0303c0e07000c00303c0c03030f30cf00830030070003000000000000ef1cf70ef18ff0ef1cf70ef3cf70e30"
		"0cf03e0c000ff1cf70ef1cf70ef3ce70ef3cf30303c0c0303c1e0303cff08300c0007087e00000c00000cff073000703700000c100830ef10c00000000000000"
		"703c3cd0000300c07c0c0003000070303c0c00000000070cff0830c0c03f3c0c0303c000303c000300c0003030c00003c070300ced0f03c0c0303c0c0303c000"
		"030c0c0303c0c0ec183700c10c00e000c0000000000008f30ff00f30cf30f30c000ff0ff08f000f3c070300c330ff00f30ff00ff03f00ff0ff0c0c0303c0c030"
		"3c0c0ff30c000300c00c0300000300330cc08ff0f83c8100300e000708d6003000000000000083c0e0e30c0c03038330300c000083c0c03030c0003008300000"
		"700303c0c0303c0c0303c0c0300c000303c0c003000c0383c000ff3c1c0303c0c0303c0c03000c00303c0c0303c1e078300e0030c10003003300000c00000c00"
		"000000c00000300000c0000000000381c00000000000000000000000000003000000000000000000000000300c0003000000000c00cc00330cf3c3c07600c000"
		"700e000300c00000000000000c07830f00783c1e0cd0c00070000c0783c1e00300c000c00000c00c1e0783c1e0383c1e0383c000300c1e03030c00003c0c0300"
		"c3f0303c1e0383c1e0383c100030c0c0303c0c0303c0c00030c003000c00cf00000830000030000000030000c1000003000000000c0003000000000000000000"
		"000000000c000000000000000000000000c100300e0000000000300330cc00c00f008f100300830c100000000000000000000008f708308f70ef10e30ff38f70"
		"ff38f70ef1000000000000000000ef18f70ef1cf70ef1cf70ff3cff0ef1c0c0ff3cff0303c000783c0c0ef1cf70ef1cf70ef3cff0303c0c0303c0c0303cff00f"
		"00000c300e100000700000c00000000c00000e30000c00003000c0300c00000000000000000000000000003000000000000000000000000e00c00c1000000000"
		"c00cc00330030c300c300c000c00300000000000000000000000cf00c00cf00f300f0cff0cf1cff0cf00f30000000000000000000f30cf00f30ff00f30ff0cff"
		"0ff30f30303cff0ff3c0c0300c0c03030f30ff00f30ff00ff0ff3c0c0303c0c0303c0c0ff30c300000f000300000c000000300000000300000f000003000c000"
		"03c0003000000000000000000000000000c000000000000000000000000030030030000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
		"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

	std::vector<unsigned char> ustr(16 * str.size(), 0);
	unsigned char white4x8[4] = { 255, 255, 255, 255 };
	std::uint32_t white32 = reinterpret_cast<std::uint32_t&>(white4x8[0]);
	std::uint32_t* ptr32 = reinterpret_cast<std::uint32_t*>(ustr.data());

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

		if (dispatch & static_cast<unsigned int>(1)) { *ptr32 = white32; }
		if (dispatch & static_cast<unsigned int>(2)) { *(ptr32 + 1) = white32; }
		if (dispatch & static_cast<unsigned int>(4)) { *(ptr32 + 2) = white32; }
		if (dispatch & static_cast<unsigned int>(8)) { *(ptr32 + 3) = white32; }
		ptr32 += 4;
	}

	m_default_atlas_texture.load(ustr.data(), kiwi::size(1330, 18), 4,
		kiwi::texture_mapping::linear, kiwi::texture_borders::clamp);
}