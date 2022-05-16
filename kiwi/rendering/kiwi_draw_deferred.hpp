#ifndef KIWI_DRAW_DEFERRED_HPP
#define KIWI_DRAW_DEFERRED_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_index.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "buffers/kiwi_buffer_texture.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_sets.hpp"


namespace kiwi
{
	bool draw_deferred_init();
	void draw_deferred_terminate() noexcept;

	class _load_deferred_2d_proxy;
	class _load_deferred_3d_proxy;
	class _draw_deferred_proxy;

	kiwi::_load_deferred_2d_proxy draw_deferred_2d_with(const GLfloat* const mvp_matrix_ptr) noexcept;

	kiwi::_load_deferred_2d_proxy draw_deferred_2d_with(const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

	kiwi::_load_deferred_3d_proxy draw_deferred_3d_with(const GLfloat* const mvp_matrix_ptr) noexcept;

	kiwi::_load_deferred_3d_proxy draw_deferred_3d_with(const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

	class _load_deferred_2d_proxy
	{

	private:

		GLfloat m_view_XYZ[3];
		const GLfloat* m_mvp_matrix_ptr;
		const GLfloat* m_m_matrix_ptr;

	public:

		friend kiwi::_load_deferred_2d_proxy draw_deferred_2d_with(const GLfloat* const mvp_matrix_ptr) noexcept;

		friend kiwi::_load_deferred_2d_proxy draw_deferred_2d_with(const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;


		kiwi::_draw_deferred_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_deferred_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_deferred_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::texture_buffer& RMEC_texture_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::texture_buffer& RMEC_texture_buffer, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::RMEC& RMEC, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::texture_buffer& RMEC_texture_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map, const kiwi::texture_buffer& RMEC_texture_buffer,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TB_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& normal_map,
			const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling, const kiwi::vertex_buffer& lightmap_UV_buffer,
			const kiwi::texture_buffer& lightmap) noexcept;
	};

	class _load_deferred_3d_proxy
	{

	private:

		const GLfloat* m_view_XYZ_ptr;
		const GLfloat* m_mvp_matrix_ptr;
		const GLfloat* m_m_matrix_ptr;

	public:

		friend kiwi::_load_deferred_3d_proxy draw_deferred_3d_with(const GLfloat* const mvp_matrix_ptr) noexcept;

		friend kiwi::_load_deferred_3d_proxy draw_deferred_3d_with(const GLfloat* const mvp_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;


		kiwi::_draw_deferred_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::RGBA& solid_color, const kiwi::RMEC& RMEC) noexcept;


		kiwi::_draw_deferred_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_deferred_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& color_vertex_buffer, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept;


		// TEXTURE 3D

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::RMEC& RMEC) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& coord_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::vertex_buffer& RMEC_vertex_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::texture_buffer& RMEC_texture_buffer) noexcept;

		kiwi::_draw_deferred_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture,
			const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_texture_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		// NORMAL 3D

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
			const kiwi::texture_buffer& normal_map) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
			const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
			const kiwi::texture_buffer& normal_map) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_map) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
			const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
			const kiwi::texture_buffer& normal_map) noexcept;

		kiwi::_draw_deferred_proxy using_normal(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_map) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
			const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_normal_lightmapped(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_map, const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		// PARALLAX 3D

		kiwi::_draw_deferred_proxy using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_deferred_proxy using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::RMEC& RMEC,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		kiwi::_draw_deferred_proxy using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_deferred_proxy using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_deferred_proxy using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::vertex_buffer& RMEC_vertex_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;


		kiwi::_draw_deferred_proxy using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_deferred_proxy using_parallax(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor) noexcept;

		kiwi::_draw_deferred_proxy using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;

		kiwi::_draw_deferred_proxy using_parallax_lightmapped(const GLfloat* const view_XYZ_ptr, const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& TBN_buffer,
			const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture, const kiwi::texture_buffer& RMEC_texture_buffer, GLfloat color_ceiling,
			const kiwi::texture_buffer& normal_parallax_map, GLfloat parallax_shift_factor,
			const kiwi::vertex_buffer& lightmap_UV_buffer, const kiwi::texture_buffer& lightmap) noexcept;
	};

	class _draw_deferred_proxy
	{

	private:

		std::size_t m_vertex_count;

	public:

		friend class _load_deferred_2d_proxy;
		friend class _load_deferred_3d_proxy;

		void triangles() noexcept;
		void quads() noexcept;
		void triangles(std::size_t vertex_count) noexcept;
		void quads(std::size_t vertex_count) noexcept;
		void triangles(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
		void quads(std::size_t begin_vertex, std::size_t vertex_count) noexcept;
	};
}

#endif // KIWI_DRAW_DEFERRED_HPP