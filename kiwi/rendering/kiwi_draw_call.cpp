#include "rendering/kiwi_draw_call.hpp"


void kiwi::draw_call::points(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::points(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_POINTS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::points_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::points_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::points_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::points_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_POINTS, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_POINTS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::points_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_POINTS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::lines(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::lines(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::lines_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::lines_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::lines_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::lines_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::lines_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::triangles(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangles_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::triangles_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::triangles_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::triangles_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLES, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLES, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangles_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLES, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::quads(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_QUADS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::quads_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::quads_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::quads_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::quads_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_QUADS, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_QUADS, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, ::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::quads_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_QUADS, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::line_strip(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_strip(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_strip_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::line_strip_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::line_strip_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::line_strip_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_STRIP, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::line_loop(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_loop(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_LINE_LOOP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::line_loop_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::line_loop_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::line_loop_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::line_loop_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_LOOP, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_LINE_LOOP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::line_loop_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_LINE_LOOP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::triangle_strip(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_strip(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_strip_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::triangle_strip_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::triangle_strip_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_STRIP, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}

void kiwi::draw_call::triangle_fan(std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_fan(std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArrays(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count));
}
void kiwi::draw_call::triangle_fan_indexed(std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr);
}
void kiwi::draw_call::triangle_fan_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr));
}
void kiwi::draw_call::triangle_fan_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElements(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, static_cast<const void*>(index_data_ptr + begin_index));
	}
}
void kiwi::draw_call::triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept
{
	glDrawArraysInstanced(GL_TRIANGLE_FAN, static_cast<GLint>(begin_vertex), static_cast<GLsizei>(vertex_count), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT, nullptr, static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept
{
	glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
		static_cast<const void*>(index_data_ptr), static_cast<GLsizei>(instance_count));
}
void kiwi::draw_call::triangle_fan_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept
{
	if (index_data_ptr != nullptr)
	{
		glDrawElementsInstanced(GL_TRIANGLE_FAN, static_cast<GLsizei>(index_count), GL_UNSIGNED_INT,
			static_cast<const void*>(index_data_ptr + begin_index), static_cast<GLsizei>(instance_count));
	}
}