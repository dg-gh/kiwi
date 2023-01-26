#ifndef _KIWI_DRAW_CALL_HPP
#define _KIWI_DRAW_CALL_HPP

#include "header_utils/kiwi_glcall.hpp"
#include <cstddef>


namespace kiwi
{
	namespace draw_call
	{
		void points(std::size_t vertex_count) noexcept;
		void points(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void points_indexed(std::size_t index_count) noexcept;
		void points_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void points_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void points_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void points_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void points_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void points_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void points_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void lines(std::size_t vertex_count) noexcept;
		void lines(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void lines_indexed(std::size_t index_count) noexcept;
		void lines_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void lines_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void lines_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void lines_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void lines_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void lines_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void lines_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void triangles(std::size_t vertex_count) noexcept;
		void triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void triangles_indexed(std::size_t index_count) noexcept;
		void triangles_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void triangles_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void triangles_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void triangles_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void triangles_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void triangles_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void triangles_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void quads(std::size_t vertex_count) noexcept;
		void quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void quads_indexed(std::size_t index_count) noexcept;
		void quads_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void quads_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void quads_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void quads_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void quads_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void quads_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void quads_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void line_strip(std::size_t vertex_count) noexcept;
		void line_strip(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void line_strip_indexed(std::size_t index_count) noexcept;
		void line_strip_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void line_strip_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void line_strip_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void line_strip_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void line_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void line_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void line_loop(std::size_t vertex_count) noexcept;
		void line_loop(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void line_loop_indexed(std::size_t index_count) noexcept;
		void line_loop_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void line_loop_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void line_loop_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void line_loop_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void line_loop_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void line_loop_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void triangle_strip(std::size_t vertex_count) noexcept;
		void triangle_strip(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void triangle_strip_indexed(std::size_t index_count) noexcept;
		void triangle_strip_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void triangle_strip_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void triangle_strip_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void triangle_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void triangle_strip_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;

		void triangle_fan(std::size_t vertex_count) noexcept;
		void triangle_fan(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void triangle_fan_indexed(std::size_t index_count) noexcept;
		void triangle_fan_indexed(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void triangle_fan_indexed(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void triangle_fan_indexed_instanced(std::size_t instance_count, std::size_t index_count) noexcept;
		void triangle_fan_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		void triangle_fan_indexed_instanced(std::size_t instance_count, const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;
	}
}

#endif // _KIWI_DRAW_CALL_HPP