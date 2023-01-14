#ifndef _KIWI_GEOM_HPP
#define _KIWI_GEOM_HPP

#include "kiwi_includes.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "header_utils/kiwi_restrict.hpp"


namespace kiwi
{
	class _load_frame_proxy;
	kiwi::_load_frame_proxy load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept;

	class _load_frame_proxy
	{

	public:

		friend _load_frame_proxy load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept;

		template <class _Allocator = std::allocator<GLfloat>> inline void N_from_2d_lines_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);
		template <class _Allocator = std::allocator<GLfloat>> inline void N_from_2d_lines_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);

		template <class _Allocator = std::allocator<GLfloat>> inline void TB_from_2d_triangles(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);
		template <class _Allocator = std::allocator<GLfloat>> inline void TB_from_2d_quads(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);

		template <class _Allocator = std::allocator<GLfloat>> inline void N_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _Allocator = std::allocator<GLfloat>> inline void N_from_3d_triangles_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _Allocator = std::allocator<GLfloat>> inline void N_from_3d_quads_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _Allocator = std::allocator<GLfloat>> inline void N_from_3d_quads_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);

		template <class _Allocator = std::allocator<GLfloat>> inline void TBN_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _Allocator = std::allocator<GLfloat>> inline void TBN_from_3d_triangles_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _Allocator = std::allocator<GLfloat>> inline void TBN_from_3d_quads_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _Allocator = std::allocator<GLfloat>> inline void TBN_from_3d_quads_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
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


// INLINE IMPLEMENTATION


template <class _Allocator> inline void kiwi::_load_frame_proxy::N_from_2d_lines_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 2);
	kiwi::make_N_from_2d_lines_ccw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 2);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::N_from_2d_lines_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 2);
	kiwi::make_N_from_2d_lines_cw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 2);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::TB_from_2d_triangles(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 4);
	kiwi::make_TB_from_2d_triangles(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 4);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::TB_from_2d_quads(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 4);
	kiwi::make_TB_from_2d_quads(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 4);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::N_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 3);
	kiwi::make_N_from_3d_triangles_ccw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::N_from_3d_triangles_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 3);
	kiwi::make_N_from_3d_triangles_cw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::N_from_3d_quads_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 3);
	kiwi::make_N_from_3d_quads_ccw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::N_from_3d_quads_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 3);
	kiwi::make_N_from_3d_quads_cw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::TBN_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_triangles_ccw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::TBN_from_3d_triangles_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_triangles_cw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::TBN_from_3d_quads_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_quads_ccw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

template <class _Allocator> inline void kiwi::_load_frame_proxy::TBN_from_3d_quads_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _Allocator> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_quads_cw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

#endif // _KIWI_GEOM_HPP