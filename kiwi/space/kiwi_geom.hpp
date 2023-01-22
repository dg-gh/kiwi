#ifndef _KIWI_GEOM_HPP
#define _KIWI_GEOM_HPP

#include "buffers/kiwi_buffer_vertex.hpp"
#include "header_utils/kiwi_restrict.hpp"
#include <vector>


namespace kiwi
{
	enum class orient {
		ccw, cw
	};

	class _load_geom_proxy;
	kiwi::_load_geom_proxy load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept;

	class _load_geom_proxy
	{

	public:

		template <class _allocator = std::allocator<GLfloat>> inline void with_N_from_lines_2d(kiwi::orient orientation, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);

		template <class _allocator = std::allocator<GLfloat>> inline void with_TB_from_triangles_2d(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);
		template <class _allocator = std::allocator<GLfloat>> inline void with_TB_from_quads_2d(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2);

		template <class _allocator = std::allocator<GLfloat>> inline void with_N_from_triangles_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _allocator = std::allocator<GLfloat>> inline void with_N_from_quads_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3);

		template <class _allocator = std::allocator<GLfloat>> inline void with_TBN_from_triangles_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);
		template <class _allocator = std::allocator<GLfloat>> inline void with_TBN_from_quads_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
			std::size_t vertex_count, std::size_t vertex_dim = 3);

		friend _load_geom_proxy load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept;

	private:

		kiwi::vertex_buffer* m_buffer_ptr;
	};

	void make_N_from_lines_2d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_TB_from_triangles_2d(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_TB_from_quads_2d(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 2) noexcept;

	void make_N_from_triangles_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_N_from_quads_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_TBN_from_triangles_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;

	void make_TBN_from_quads_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
		std::size_t vertex_count, std::size_t vertex_dim = 3) noexcept;
}


// INLINE IMPLEMENTATION

template <class _allocator> inline void kiwi::_load_geom_proxy::with_N_from_lines_2d(kiwi::orient orientation, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 2);
	kiwi::make_N_from_lines_2d(orientation, temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 2);
}

template <class _allocator> inline void kiwi::_load_geom_proxy::with_TB_from_triangles_2d(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 4);
	kiwi::make_TB_from_triangles_2d(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 4);
}

template <class _allocator> inline void kiwi::_load_geom_proxy::with_TB_from_quads_2d(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 4);
	kiwi::make_TB_from_quads_2d(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 4);
}

template <class _allocator> inline void kiwi::_load_geom_proxy::with_N_from_triangles_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 3);
	kiwi::make_N_from_triangles_3d(orientation, temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

template <class _allocator> inline void kiwi::_load_geom_proxy::with_N_from_quads_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 3);
	kiwi::make_N_from_quads_3d(orientation, temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

template <class _allocator> inline void kiwi::_load_geom_proxy::with_TBN_from_triangles_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 9);
	kiwi::make_TBN_from_triangles_3d(orientation, temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

template <class _allocator> inline void kiwi::_load_geom_proxy::with_TBN_from_quads_3d(kiwi::orient orientation, const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat, _allocator> temp(vertex_count * 9);
	kiwi::make_TBN_from_quads_3d(orientation, temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

#endif // _KIWI_GEOM_HPP