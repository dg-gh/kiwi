#ifndef KIWI_PROGRAM_HPP
#define KIWI_PROGRAM_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_uniform.hpp"

namespace kiwi
{
	class program
	{

	private:

		GLuint m_program_index;
		GLuint m_vertex_shader_index;
		GLuint m_fragment_shader_index;

	public:

		program() noexcept;
		program(const program&) = delete;
		program& operator=(const program&) = delete;
		program(program&& rhs) noexcept;
		program& operator=(program&& rhs) noexcept;
		~program();

		GLuint get_id() const noexcept;
		kiwi::program& use() noexcept;
		const kiwi::program& use() const noexcept;

		bool new_program(const char* vertex_shader_source, const char* fragment_shader_source) noexcept;
		void delete_program() noexcept;

		GLuint new_uniform_block_index(const char* const uniform_variable, GLuint binding = 0) const noexcept;
		kiwi::program& set_uniform_block(const kiwi::uniform_buffer& uniform_buffer, GLuint binding = 0) noexcept;
		const kiwi::program& set_uniform_block(const kiwi::uniform_buffer& uniform_buffer, GLuint binding = 0) const noexcept;

		GLint new_uniform_location(const char* const uniform_variable) const noexcept;

		kiwi::program& set_uniform_1f(const char* const uniform_variable,
			GLfloat u0) noexcept;
		const kiwi::program& set_uniform_1f(const char* const uniform_variable,
			GLfloat u0) const noexcept;
		kiwi::program& set_uniform_1f(GLint location,
			GLfloat u0) noexcept;
		const kiwi::program& set_uniform_1f(GLint location,
			GLfloat u0) const noexcept;

		kiwi::program& set_uniform_2f(const char* const uniform_variable,
			GLfloat u0, GLfloat u1) noexcept;
		const kiwi::program& set_uniform_2f(const char* const uniform_variable,
			GLfloat u0, GLfloat u1) const noexcept;
		kiwi::program& set_uniform_2f(GLint location,
			GLfloat u0, GLfloat u1) noexcept;
		const kiwi::program& set_uniform_2f(GLint location,
			GLfloat u0, GLfloat u1) const noexcept;

		kiwi::program& set_uniform_3f(const char* const uniform_variable,
			GLfloat u0, GLfloat u1, GLfloat u2) noexcept;
		const kiwi::program& set_uniform_3f(const char* const uniform_variable,
			GLfloat u0, GLfloat u1, GLfloat u2) const noexcept;
		kiwi::program& set_uniform_3f(GLint location,
			GLfloat u0, GLfloat u1, GLfloat u2) noexcept;
		const kiwi::program& set_uniform_3f(GLint location,
			GLfloat u0, GLfloat u1, GLfloat u2) const noexcept;

		kiwi::program& set_uniform_4f(const char* const uniform_variable,
			GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) noexcept;
		const kiwi::program& set_uniform_4f(const char* const uniform_variable,
			GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) const noexcept;
		kiwi::program& set_uniform_4f(GLint location,
			GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) noexcept;
		const kiwi::program& set_uniform_4f(GLint location,
			GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) const noexcept;

		kiwi::program& set_uniform_2f(const char* const uniform_variable,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_2f(const char* const uniform_variable,
			const GLfloat* const values_ptr) const noexcept;
		kiwi::program& set_uniform_2f(GLint location,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_2f(GLint location,
			const GLfloat* const values_ptr) const noexcept;

		kiwi::program& set_uniform_3f(const char* const uniform_variable,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3f(const char* const uniform_variable,
			const GLfloat* const values_ptr) const noexcept;
		kiwi::program& set_uniform_3f(GLint location,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3f(GLint location,
			const GLfloat* const values_ptr) const noexcept;

		kiwi::program& set_uniform_4f(const char* const uniform_variable,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4f(const char* const uniform_variable,
			const GLfloat* const values_ptr) const noexcept;
		kiwi::program& set_uniform_4f(GLint location,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4f(GLint location,
			const GLfloat* const values_ptr) const noexcept;

		kiwi::program& set_uniform_3x3f(const char* const uniform_variable,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3x3f(const char* const uniform_variable,
			const GLfloat* const values_ptr) const noexcept;
		kiwi::program& set_uniform_3x3f(GLint location,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3x3f(GLint location,
			const GLfloat* const values_ptr) const noexcept;

		kiwi::program& set_uniform_4x4f(const char* const uniform_variable,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4x4f(const char* const uniform_variable,
			const GLfloat* const values_ptr) const noexcept;
		kiwi::program& set_uniform_4x4f(GLint location,
			const GLfloat* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4x4f(GLint location,
			const GLfloat* const values_ptr) const noexcept;


		kiwi::program& set_uniform_1i(const char* const uniform_variable,
			GLint u0) noexcept;
		const kiwi::program& set_uniform_1i(const char* const uniform_variable,
			GLint u0) const noexcept;
		kiwi::program& set_uniform_1i(GLint location,
			GLint u0) noexcept;
		const kiwi::program& set_uniform_1i(GLint location,
			GLint u0) const noexcept;

		kiwi::program& set_uniform_2i(const char* const uniform_variable,
			GLint u0, GLint u1) noexcept;
		const kiwi::program& set_uniform_2i(const char* const uniform_variable,
			GLint u0, GLint u1) const noexcept;
		kiwi::program& set_uniform_2i(GLint location,
			GLint u0, GLint u1) noexcept;
		const kiwi::program& set_uniform_2i(GLint location,
			GLint u0, GLint u1) const noexcept;

		kiwi::program& set_uniform_3i(const char* const uniform_variable,
			GLint u0, GLint u1, GLint u2) noexcept;
		const kiwi::program& set_uniform_3i(const char* const uniform_variable,
			GLint u0, GLint u1, GLint u2) const noexcept;
		kiwi::program& set_uniform_3i(GLint location,
			GLint u0, GLint u1, GLint u2) noexcept;
		const kiwi::program& set_uniform_3i(GLint location,
			GLint u0, GLint u1, GLint u2) const noexcept;

		kiwi::program& set_uniform_4i(const char* const uniform_variable,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept;
		const kiwi::program& set_uniform_4i(const char* const uniform_variable,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept;
		kiwi::program& set_uniform_4i(GLint location,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept;
		const kiwi::program& set_uniform_4i(GLint location,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept;

		kiwi::program& set_uniform_2i(const char* const uniform_variable,
			const GLint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_2i(const char* const uniform_variable,
			const GLint* const values_ptr) const noexcept;
		kiwi::program& set_uniform_2i(GLint location,
			const GLint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_2i(GLint location,
			const GLint* const values_ptr) const noexcept;

		kiwi::program& set_uniform_3i(const char* const uniform_variable,
			const GLint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3i(const char* const uniform_variable,
			const GLint* const values_ptr) const noexcept;
		kiwi::program& set_uniform_3i(GLint location,
			const GLint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3i(GLint location,
			const GLint* const values_ptr) const noexcept;

		kiwi::program& set_uniform_4i(const char* const uniform_variable,
			const GLint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4i(const char* const uniform_variable,
			const GLint* const values_ptr) const noexcept;
		kiwi::program& set_uniform_4i(GLint location,
			const GLint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4i(GLint location,
			const GLint* const values_ptr) const noexcept;

		kiwi::program& set_uniform_1ui(const char* const uniform_variable,
			GLuint u0) noexcept;
		const kiwi::program& set_uniform_1ui(const char* const uniform_variable,
			GLuint u0) const noexcept;
		kiwi::program& set_uniform_1ui(GLint location,
			GLuint u0) noexcept;
		const kiwi::program& set_uniform_1ui(GLint location,
			GLuint u0) const noexcept;

		kiwi::program& set_uniform_2ui(const char* const uniform_variable,
			GLuint u0, GLuint u1) noexcept;
		const kiwi::program& set_uniform_2ui(const char* const uniform_variable,
			GLuint u0, GLuint u1) const noexcept;
		kiwi::program& set_uniform_2ui(GLint location,
			GLuint u0, GLuint u1) noexcept;
		const kiwi::program& set_uniform_2ui(GLint location,
			GLuint u0, GLuint u1) const noexcept;

		kiwi::program& set_uniform_3ui(const char* const uniform_variable,
			GLuint u0, GLuint u1, GLuint u2) noexcept;
		const kiwi::program& set_uniform_3ui(const char* const uniform_variable,
			GLuint u0, GLuint u1, GLuint u2) const noexcept;
		kiwi::program& set_uniform_3ui(GLint location,
			GLuint u0, GLuint u1, GLuint u2) noexcept;
		const kiwi::program& set_uniform_3ui(GLint location,
			GLuint u0, GLuint u1, GLuint u2) const noexcept;

		kiwi::program& set_uniform_4ui(const char* const uniform_variable,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept;
		const kiwi::program& set_uniform_4ui(const char* const uniform_variable,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept;
		kiwi::program& set_uniform_4ui(GLint location,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept;
		const kiwi::program& set_uniform_4ui(GLint location,
			GLuint u0, GLuint u1, GLuint u2, GLuint u3) const noexcept;

		kiwi::program& set_uniform_2ui(const char* const uniform_variable,
			const GLuint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_2ui(const char* const uniform_variable,
			const GLuint* const values_ptr) const noexcept;
		kiwi::program& set_uniform_2ui(GLint location,
			const GLuint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_2ui(GLint location,
			const GLuint* const values_ptr) const noexcept;

		kiwi::program& set_uniform_3ui(const char* const uniform_variable,
			const GLuint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3ui(const char* const uniform_variable,
			const GLuint* const values_ptr) const noexcept;
		kiwi::program& set_uniform_3ui(GLint location,
			const GLuint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_3ui(GLint location,
			const GLuint* const values_ptr) const noexcept;

		kiwi::program& set_uniform_4ui(const char* const uniform_variable,
			const GLuint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4ui(const char* const uniform_variable,
			const GLuint* const values_ptr) const noexcept;
		kiwi::program& set_uniform_4ui(GLint location,
			const GLuint* const values_ptr) noexcept;
		const kiwi::program& set_uniform_4ui(GLint location,
			const GLuint* const values_ptr) const noexcept;
	};
}

#endif // KIWI_PROGRAM_HPP