#ifndef _KIWI_DRAW_FORWARD_HPP
#define _KIWI_DRAW_FORWARD_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_index.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "buffers/kiwi_buffer_texture_2d.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_sets.hpp"


namespace kiwi
{
	bool draw_forward_init();
	void draw_forward_terminate() noexcept;

	class _load_forward_2d_proxy;
	class _load_forward_3d_proxy;
	class _draw_forward_proxy;

	kiwi::_load_forward_2d_proxy draw_forward_2d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XY_ptr, GLfloat view_Z,
		const GLfloat* const mvp_matrix_ptr) noexcept;

	kiwi::_load_forward_2d_proxy draw_forward_2d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XY_ptr, GLfloat view_Z,
		const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

	kiwi::_load_forward_3d_proxy draw_forward_3d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XYZ_ptr,
		const GLfloat* const mvp_matrix_ptr) noexcept;

	kiwi::_load_forward_3d_proxy draw_forward_3d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XYZ_ptr,
		const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

	class _load_forward_2d_proxy
	{

	private:

		const kiwi::lightset* m_lightset_ptr;
		const kiwi::light_selection* m_light_selection_ptr;
		GLfloat m_view_XYZ[3];
		const GLfloat* m_mvp_matrix_ptr;
		const GLfloat* m_m_matrix_ptr;

	public:

		friend kiwi::_load_forward_2d_proxy draw_forward_2d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XY_ptr, GLfloat view_Z,
			const GLfloat* const mvp_matrix_ptr) noexcept;

		friend kiwi::_load_forward_2d_proxy draw_forward_2d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XY_ptr, GLfloat view_Z,
			const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;


		// 2D

		kiwi::_draw_forward_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_forward_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;


		// TEXTURE 2D

		kiwi::_draw_forward_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::texture_2d& RMEC_texture_buffer) noexcept;

		kiwi::_draw_forward_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx) noexcept;

		kiwi::_draw_forward_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::texture_2d& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;

		kiwi::_draw_forward_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;


		// NORMAL 2D

		kiwi::_draw_forward_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& normal_map,
			const kiwi::texture_2d& RMEC_texture_buffer) noexcept;

		kiwi::_draw_forward_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& normal_map,
			const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx) noexcept;

		kiwi::_draw_forward_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& normal_map, const kiwi::texture_2d& RMEC_texture_buffer,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;

		kiwi::_draw_forward_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& normal_map,
			const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx, const kiwi::vertex_buffer& lightmap_UV_buffer,
			const kiwi::texture_2d& lightmap) noexcept;
	};

	class _load_forward_3d_proxy
	{

	private:

		const kiwi::lightset* m_lightset_ptr;
		const kiwi::light_selection* m_light_selection_ptr;
		const GLfloat* m_view_XYZ_ptr;
		const GLfloat* m_mvp_matrix_ptr;
		const GLfloat* m_m_matrix_ptr;

	public:

		friend kiwi::_load_forward_3d_proxy draw_forward_3d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XYZ_ptr,
			const GLfloat* const mvp_matrix_ptr) noexcept;

		friend kiwi::_load_forward_3d_proxy draw_forward_3d_with(const kiwi::lightset& lights, const kiwi::light_selection& selection, const GLfloat* const view_XYZ_ptr,
			const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;


		// 3D

		kiwi::_draw_forward_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_forward_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;


		// TEXTURE 3D

		kiwi::_draw_forward_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::texture_2d& RMEC_texture_buffer) noexcept;

		kiwi::_draw_forward_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx) noexcept;

		kiwi::_draw_forward_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;

		kiwi::_draw_forward_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;


		// NORMAL 3D

		kiwi::_draw_forward_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer,
			const kiwi::texture_2d& normal_map) noexcept;

		kiwi::_draw_forward_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx,
			const kiwi::texture_2d& normal_map) noexcept;

		kiwi::_draw_forward_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer,
			const kiwi::texture_2d& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;

		kiwi::_draw_forward_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx,
			const kiwi::texture_2d& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;


		// PARALLAX 3D

		kiwi::_draw_forward_proxy using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer,
			const kiwi::texture_2d& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_forward_proxy using_parallax(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx,
			const kiwi::texture_2d& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_forward_proxy using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer,
			const kiwi::texture_2d& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;

		kiwi::_draw_forward_proxy using_parallax_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture, const kiwi::texture_2d& RMEC_texture_buffer, const kiwi::ECx& ECx,
			const kiwi::texture_2d& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_2d& lightmap) noexcept;
	};

	class _draw_forward_proxy
	{

	private:

		std::size_t m_vertex_count;

	public:

		friend class _load_forward_2d_proxy;
		friend class _load_forward_3d_proxy;

		void triangles() noexcept;
		void quads() noexcept;
		void triangles(std::size_t vertex_count) noexcept;
		void quads(std::size_t vertex_count) noexcept;
		void triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
	};
}

#endif // _KIWI_DRAW_FORWARD_HPP