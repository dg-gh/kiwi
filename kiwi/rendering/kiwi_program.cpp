#include "rendering/kiwi_program.hpp"
#include <iostream>


kiwi::program::program() noexcept
{
	m_program_index = 0;
	m_vertex_shader_index = 0;
	m_fragment_shader_index = 0;
}

kiwi::program::program(program&& rhs) noexcept
{
	m_program_index = rhs.m_program_index;
	m_vertex_shader_index = rhs.m_vertex_shader_index;
	m_fragment_shader_index = rhs.m_fragment_shader_index;

	rhs.m_program_index = 0;
	rhs.m_vertex_shader_index = 0;
	rhs.m_fragment_shader_index = 0;
}

kiwi::program& kiwi::program::operator=(program&& rhs) noexcept
{
	delete_program();

	m_program_index = rhs.m_program_index;
	m_vertex_shader_index = rhs.m_vertex_shader_index;
	m_fragment_shader_index = rhs.m_fragment_shader_index;

	rhs.m_program_index = 0;
	rhs.m_vertex_shader_index = 0;
	rhs.m_fragment_shader_index = 0;

	return *this;
}

kiwi::program::~program()
{
	delete_program();
}

GLuint kiwi::program::get_id() const noexcept
{
	return m_program_index;
}

kiwi::program& kiwi::program::use() noexcept
{
	glUseProgram(m_program_index);
	return *this;
}

const kiwi::program& kiwi::program::use() const noexcept
{
	glUseProgram(m_program_index);
	return *this;
}

bool kiwi::program::new_program(const char* vertex_shader_source, const char* fragment_shader_source) noexcept
{
	if (m_program_index != 0)
	{
		glDetachShader(m_program_index, m_vertex_shader_index);
		glDetachShader(m_program_index, m_fragment_shader_index);

		glDeleteProgram(m_program_index);

		glDeleteShader(m_vertex_shader_index);
		glDeleteShader(m_fragment_shader_index);

		m_program_index = 0;
		m_vertex_shader_index = 0;
		m_fragment_shader_index = 0;
	}

	{
		m_vertex_shader_index = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(m_vertex_shader_index, 1, &vertex_shader_source, nullptr);
		glCompileShader(m_vertex_shader_index);

		GLint result;
		glGetShaderiv(m_vertex_shader_index, GL_COMPILE_STATUS, &result);

		if (result == 0)
		{
			std::cout << "vertex shader compilation failed !\n\n";
			std::cout << vertex_shader_source << "\n" << std::endl;

			glDeleteShader(m_vertex_shader_index);
			m_vertex_shader_index = 0;
			return false;
		}
	}

	{
		m_fragment_shader_index = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(m_fragment_shader_index, 1, &fragment_shader_source, nullptr);
		glCompileShader(m_fragment_shader_index);

		GLint result;
		glGetShaderiv(m_fragment_shader_index, GL_COMPILE_STATUS, &result);

		if (result == 0)
		{
			std::cout << "fragment shader compilation failed !\n\n";
			std::cout << fragment_shader_source << "\n" << std::endl;
	
			glDeleteShader(m_vertex_shader_index);
			glDeleteShader(m_fragment_shader_index);
			m_vertex_shader_index = 0;
			m_fragment_shader_index = 0;
			return false;
		}
	}

	m_program_index = glCreateProgram();

	glAttachShader(m_program_index, m_vertex_shader_index);
	glAttachShader(m_program_index, m_fragment_shader_index);

	glLinkProgram(m_program_index);
	glValidateProgram(m_program_index);

	return true;
}

void kiwi::program::delete_program() noexcept
{
	if (m_program_index != 0)
	{
		glDetachShader(m_program_index, m_vertex_shader_index);
		glDetachShader(m_program_index, m_fragment_shader_index);

		glDeleteProgram(m_program_index);

		glDeleteShader(m_vertex_shader_index);
		glDeleteShader(m_fragment_shader_index);

		m_program_index = 0;
		m_vertex_shader_index = 0;
		m_fragment_shader_index = 0;
	}
}


GLuint kiwi::program::new_uniform_block_index(const char* const uniform_variable, GLuint binding) const noexcept
{
	glUseProgram(m_program_index);
	GLuint uniform_block_index = glGetUniformBlockIndex(m_program_index, uniform_variable);
	glUniformBlockBinding(m_program_index, uniform_block_index, binding);
	return uniform_block_index;
}

kiwi::program& kiwi::program::set_uniform_block(const kiwi::uniform_buffer& uniform_buffer, GLuint binding) noexcept
{
	glUseProgram(m_program_index);
	glUniformBlockBinding(m_program_index, uniform_buffer.bind().get_id(), binding);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_block(const kiwi::uniform_buffer& uniform_buffer, GLuint binding) const noexcept
{
	glUseProgram(m_program_index);
	glUniformBlockBinding(m_program_index, uniform_buffer.bind().get_id(), binding);
	return *this;
}

GLint kiwi::program::new_uniform_location(const char* const uniform_variable) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return -1;
	}

	glUseProgram(m_program_index);

	GLint loc = glGetUniformLocation(m_program_index, uniform_variable);
	if (loc == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}

	return loc;
}

kiwi::program& kiwi::program::set_uniform_1f(const char* const uniform_variable,
	GLfloat u0) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform1f(location, u0);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_1f(const char* const uniform_variable,
	GLfloat u0) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform1f(location, u0);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_1f(GLint location,
	GLfloat u0) noexcept
{
	glUseProgram(m_program_index);
	glUniform1f(location, u0);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_1f(GLint location,
	GLfloat u0) const noexcept
{
	glUseProgram(m_program_index);
	glUniform1f(location, u0);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_2f(const char* const uniform_variable,
	GLfloat u0, GLfloat u1) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2f(location, u0, u1);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2f(const char* const uniform_variable,
	GLfloat u0, GLfloat u1) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2f(location, u0, u1);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_2f(GLint location,
	GLfloat u0, GLfloat u1) noexcept
{
	glUseProgram(m_program_index);
	glUniform2f(location, u0, u1);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2f(GLint location,
	GLfloat u0, GLfloat u1) const noexcept
{
	glUseProgram(m_program_index);
	glUniform2f(location, u0, u1);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3f(const char* const uniform_variable,
	GLfloat u0, GLfloat u1, GLfloat u2) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3f(location, u0, u1, u2);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3f(const char* const uniform_variable,
	GLfloat u0, GLfloat u1, GLfloat u2) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3f(location, u0, u1, u2);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3f(GLint location,
	GLfloat u0, GLfloat u1, GLfloat u2) noexcept
{
	glUseProgram(m_program_index);
	glUniform3f(location, u0, u1, u2);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3f(GLint location,
	GLfloat u0, GLfloat u1, GLfloat u2) const noexcept
{
	glUseProgram(m_program_index);
	glUniform3f(location, u0, u1, u2);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4f(const char* const uniform_variable,
	GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4f(location, u0, u1, u2, u3);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4f(const char* const uniform_variable,
	GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4f(location, u0, u1, u2, u3);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4f(GLint location,
	GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) noexcept
{
	glUseProgram(m_program_index);
	glUniform4f(location, u0, u1, u2, u3);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4f(GLint location,
	GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) const noexcept
{
	glUseProgram(m_program_index);
	glUniform4f(location, u0, u1, u2, u3);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_2f(const char* const uniform_variable,
	const GLfloat* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2fv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2f(const char* const uniform_variable,
	const GLfloat* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2fv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_2f(GLint location,
	const GLfloat* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform2fv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2f(GLint location,
	const GLfloat* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform2fv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3f(const char* const uniform_variable,
	const GLfloat* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3fv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3f(const char* const uniform_variable,
	const GLfloat* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3fv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3f(GLint location,
	const GLfloat* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform3fv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3f(GLint location,
	const GLfloat* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform3fv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4f(const char* const uniform_variable,
	const GLfloat* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4fv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4f(const char* const uniform_variable,
	const GLfloat* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4fv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4f(GLint location,
	const GLfloat* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform4fv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4f(GLint location,
	const GLfloat* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform4fv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3x3f(const char* const uniform_variable,
	const GLfloat* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniformMatrix3fv(location, 1, GL_FALSE, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3x3f(const char* const uniform_variable,
	const GLfloat* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniformMatrix3fv(location, 1, GL_FALSE, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3x3f(GLint location,
	const GLfloat* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniformMatrix3fv(location, 1, GL_FALSE, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3x3f(GLint location,
	const GLfloat* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniformMatrix3fv(location, 1, GL_FALSE, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4x4f(const char* const uniform_variable,
	const GLfloat* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4x4f(const char* const uniform_variable,
	const GLfloat* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4x4f(GLint location,
	const GLfloat* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniformMatrix4fv(location, 1, GL_FALSE, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4x4f(GLint location,
	const GLfloat* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniformMatrix4fv(location, 1, GL_FALSE, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_1i(const char* const uniform_variable,
	GLint u0) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform1i(location, u0);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_1i(const char* const uniform_variable,
	GLint u0) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform1i(location, u0);
	}
	return *this;
}


kiwi::program& kiwi::program::set_uniform_1i(GLint location,
	GLint u0) noexcept
{
	glUseProgram(m_program_index);
	glUniform1i(location, u0);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_1i(GLint location,
	GLint u0) const noexcept
{
	glUseProgram(m_program_index);
	glUniform1i(location, u0);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_2i(const char* const uniform_variable,
	GLint u0, GLint u1) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2i(location, u0, u1);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2i(const char* const uniform_variable,
	GLint u0, GLint u1) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2i(location, u0, u1);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_2i(GLint location,
	GLint u0, GLint u1) noexcept
{
	glUseProgram(m_program_index);
	glUniform2i(location, u0, u1);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2i(GLint location,
	GLint u0, GLint u1) const noexcept
{
	glUseProgram(m_program_index);
	glUniform2i(location, u0, u1);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3i(const char* const uniform_variable,
	GLint u0, GLint u1, GLint u2) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3i(location, u0, u1, u2);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3i(const char* const uniform_variable,
	GLint u0, GLint u1, GLint u2) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3i(location, u0, u1, u2);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3i(GLint location,
	GLint u0, GLint u1, GLint u2) noexcept
{
	glUseProgram(m_program_index);
	glUniform3i(location, u0, u1, u2);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3i(GLint location,
	GLint u0, GLint u1, GLint u2) const noexcept
{
	glUseProgram(m_program_index);
	glUniform3i(location, u0, u1, u2);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4i(const char* const uniform_variable,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4ui(location, u0, u1, u2, u3);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4i(const char* const uniform_variable,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4ui(location, u0, u1, u2, u3);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4i(GLint location,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept
{
	glUseProgram(m_program_index);
	glUniform4ui(location, u0, u1, u2, u3);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4i(GLint location,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept
{
	glUseProgram(m_program_index);
	glUniform4ui(location, u0, u1, u2, u3);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_2i(const char* const uniform_variable,
	const GLint* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2iv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2i(const char* const uniform_variable,
	const GLint* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2iv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_2i(GLint location,
	const GLint* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform2iv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2i(GLint location,
	const GLint* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform2iv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3i(const char* const uniform_variable,
	const GLint* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3iv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3i(const char* const uniform_variable,
	const GLint* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3iv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3i(GLint location,
	const GLint* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform3iv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3i(GLint location,
	const GLint* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform3iv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4i(const char* const uniform_variable,
	const GLint* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4iv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4i(const char* const uniform_variable,
	const GLint* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4iv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4i(GLint location,
	const GLint* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform4iv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4i(GLint location,
	const GLint* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform4iv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_1ui(const char* const uniform_variable,
	GLuint u0) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform1ui(location, u0);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_1ui(const char* const uniform_variable,
	GLuint u0) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform1ui(location, u0);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_1ui(GLint location,
	GLuint u0) noexcept
{
	glUseProgram(m_program_index);
	glUniform1ui(location, u0);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_1ui(GLint location,
	GLuint u0) const noexcept
{
	glUseProgram(m_program_index);
	glUniform1ui(location, u0);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_2ui(const char* const uniform_variable,
	GLuint u0, GLuint u1) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2ui(location, u0, u1);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2ui(const char* const uniform_variable,
	GLuint u0, GLuint u1) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2ui(location, u0, u1);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_2ui(GLint location,
	GLuint u0, GLuint u1) noexcept
{
	glUseProgram(m_program_index);
	glUniform2ui(location, u0, u1);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2ui(GLint location,
	GLuint u0, GLuint u1) const noexcept
{
	glUseProgram(m_program_index);
	glUniform2ui(location, u0, u1);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3ui(const char* const uniform_variable,
	GLuint u0, GLuint u1, GLuint u2) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3ui(location, u0, u1, u2);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3ui(const char* const uniform_variable,
	GLuint u0, GLuint u1, GLuint u2) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3ui(location, u0, u1, u2);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3ui(GLint location,
	GLuint u0, GLuint u1, GLuint u2) noexcept
{
	glUseProgram(m_program_index);
	glUniform3ui(location, u0, u1, u2);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3ui(GLint location,
	GLuint u0, GLuint u1, GLuint u2) const noexcept
{
	glUseProgram(m_program_index);
	glUniform3ui(location, u0, u1, u2);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4ui(const char* const uniform_variable,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4ui(location, u0, u1, u2, u3);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4ui(const char* const uniform_variable,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4ui(location, u0, u1, u2, u3);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4ui(GLint location,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept
{
	glUseProgram(m_program_index);
	glUniform4ui(location, u0, u1, u2, u3);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4ui(GLint location,
	GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept
{
	glUseProgram(m_program_index);
	glUniform4ui(location, u0, u1, u2, u3);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_2ui(const char* const uniform_variable,
	const GLuint* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2uiv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2ui(const char* const uniform_variable,
	const GLuint* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform2uiv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_2ui(GLint location,
	const GLuint* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform2uiv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_2ui(GLint location,
	const GLuint* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform2uiv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_3ui(const char* const uniform_variable,
	const GLuint* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3uiv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3ui(const char* const uniform_variable,
	const GLuint* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform3uiv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_3ui(GLint location,
	const GLuint* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform3uiv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_3ui(GLint location,
	const GLuint* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform3uiv(location, 1, values_ptr);
	return *this;
}


kiwi::program& kiwi::program::set_uniform_4ui(const char* const uniform_variable,
	const GLuint* const values_ptr) noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4uiv(location, 1, values_ptr);
	}
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4ui(const char* const uniform_variable,
	const GLuint* const values_ptr) const noexcept
{
	if (m_program_index == 0)
	{
		std::cout << "program invalid for uniform variable : " << uniform_variable << '\n' << std::endl;
		return *this;
	}

	glUseProgram(m_program_index);
	GLint location = glGetUniformLocation(m_program_index, uniform_variable);
	if (location == -1)
	{
		std::cout << "uniform variable not found : " << uniform_variable << '\n' << std::endl;
	}
	else
	{
		glUniform4uiv(location, 1, values_ptr);
	}
	return *this;
}

kiwi::program& kiwi::program::set_uniform_4ui(GLint location,
	const GLuint* const values_ptr) noexcept
{
	glUseProgram(m_program_index);
	glUniform4uiv(location, 1, values_ptr);
	return *this;
}

const kiwi::program& kiwi::program::set_uniform_4ui(GLint location,
	const GLuint* const values_ptr) const noexcept
{
	glUseProgram(m_program_index);
	glUniform4uiv(location, 1, values_ptr);
	return *this;
}