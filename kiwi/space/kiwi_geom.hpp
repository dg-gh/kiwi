#ifndef KIWI_GEOM_HPP
#define KIWI_GEOM_HPP

#include "kiwi_includes.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"


namespace kiwi
{
	class _load_frame_proxy;
	kiwi::_load_frame_proxy load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept;

	class _load_frame_proxy
	{

	public:

		friend _load_frame_proxy load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept;

		void N_from_2d_lines_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);
		void N_from_2d_lines_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);

		void TB_from_2d_triangles(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);
		void TB_from_2d_quads(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);

		void N_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		void N_from_3d_triangles_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		void N_from_3d_quads_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		void N_from_3d_quads_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);

		void TBN_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		void TBN_from_3d_triangles_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		void TBN_from_3d_quads_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		void TBN_from_3d_quads_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);

	private:

		kiwi::vertex_buffer* m_buffer_ptr;
	};

	void make_N_from_2d_lines_ccw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_N_from_2d_lines_cw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_TB_from_2d_triangles(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_TB_from_2d_quads(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_N_from_3d_triangles_ccw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_N_from_3d_triangles_cw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_N_from_3d_quads_ccw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_N_from_3d_quads_cw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_TBN_from_3d_triangles_ccw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_TBN_from_3d_triangles_cw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_TBN_from_3d_quads_ccw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_TBN_from_3d_quads_cw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;
}

#endif // KIWI_GEOM_HPP