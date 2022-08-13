#ifndef KIWI_DRAW_HPP
#define KIWI_DRAW_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_cubemap.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_index.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "buffers/kiwi_buffer_texture.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_sets.hpp"


namespace kiwi
{
	bool draw_init();
	void draw_terminate() noexcept;

	class _draw_basic_proxy;
	class _draw_instanced_basic_proxy;
	class _load_basic_2d_proxy;
	class _load_basic_3d_proxy;
	class _load_spec_2d_proxy;
	class _load_spec_3d_proxy;
	class _draw_quad_sprite_proxy;

	kiwi::_load_basic_2d_proxy draw_2d_with() noexcept;
	kiwi::_load_basic_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

	kiwi::_load_basic_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept;
	kiwi::_load_spec_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;


	class _load_basic_2d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend kiwi::_load_basic_2d_proxy draw_2d_with() noexcept;
		friend kiwi::_load_basic_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_buffer& texture, GLfloat alpha_test_value) noexcept;
		kiwi::_draw_basic_proxy using_no_shade(const kiwi::vertex_buffer& vertex_buffer) noexcept;

		kiwi::_draw_instanced_basic_proxy using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer,
			const kiwi::XYZA_RGBA_set& XYZA_RGBA_set) noexcept;
		kiwi::_draw_instanced_basic_proxy using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer,
			const kiwi::XYZA_set& XYZA_set, const kiwi::RGBA_set& RGBA_set) noexcept;

		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_UV_set& XYZA_UV_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard) noexcept;
		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::UV_set& UV_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard) noexcept;
	};

	class _load_basic_3d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend kiwi::_load_basic_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_buffer& texture_buffer) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_buffer& texture_buffer, GLfloat alpha_test_value) noexcept;

		void using_skybox(const kiwi::cubemap_buffer& skybox_buffer) noexcept;
		kiwi::_draw_basic_proxy using_no_shade(const kiwi::vertex_buffer& vertex_buffer, GLfloat depth_offset = static_cast<GLfloat>(0)) noexcept;

		kiwi::_draw_basic_proxy using_solid_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const GLfloat* const XYZang_ptr, const kiwi::RGBA& solid_color,
			bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_instanced_basic_proxy using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZA_RGBA_set& XYZang_RGBA_set,
			bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_instanced_basic_proxy using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZA_set& XYZA_set, const kiwi::RGBA_set& RGBA_set,
			bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;

		kiwi::_draw_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_buffer& texture_buffer, const GLfloat* const XYZA_ptr,
			GLfloat alpha_discard, bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_UV_set& XYZA_UV_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard, bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::UV_set& UV_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard, bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
	};


	class _load_spec_3d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;
		const GLfloat* m_matrix_ptr;

	public:

		friend kiwi::_load_spec_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_dualcolor_point_dist(const kiwi::vertex_buffer& vertex_buffer, const GLfloat* const point_ptr, const kiwi::RGBA& color_near,
			const kiwi::RGBA& color_far, GLfloat near_dist, GLfloat far_dist) noexcept;
		kiwi::_draw_basic_proxy using_bicolor_point_dir(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const GLfloat* const point_ptr, const kiwi::RGBA& color_front, const kiwi::RGBA& color_side) noexcept;
		kiwi::_draw_basic_proxy using_bicolor_axis_dir(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer,
			const GLfloat* const axis_ptr, const kiwi::RGBA& solid_color_forward, const kiwi::RGBA& solid_color_backward) noexcept;
	};

	class _draw_basic_proxy
	{

	private:

		std::size_t m_vertex_count;
		int m_index_count;
		const GLuint* m_index_data_ptr;

	public:

		friend class _load_basic_2d_proxy;
		friend class _load_basic_3d_proxy;

		friend class _load_spec_2d_proxy;
		friend class _load_spec_3d_proxy;

		friend class _picker_2d_proxy;
		friend class _picker_3d_proxy;

		kiwi::_draw_basic_proxy& using_indices(const kiwi::index_buffer& index_buffer) noexcept;
		kiwi::_draw_basic_proxy& using_indices(const kiwi::index_buffer& index_buffer, std::size_t index_count) noexcept;
		kiwi::_draw_basic_proxy& using_indices(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		kiwi::_draw_basic_proxy& using_indices(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;


		void points() noexcept;
		void points(std::size_t vertex_or_index_count) noexcept;
		void points(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void lines() noexcept;
		void lines(std::size_t vertex_or_index_count) noexcept;
		void lines(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangles() noexcept;
		void triangles(std::size_t vertex_or_index_count) noexcept;
		void triangles(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void quads() noexcept;
		void quads(std::size_t vertex_or_index_count) noexcept;
		void quads(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void line_strip() noexcept;
		void line_strip(std::size_t vertex_or_index_count) noexcept;
		void line_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void line_loop() noexcept;
		void line_loop(std::size_t vertex_or_index_count) noexcept;
		void line_loop(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangle_strip() noexcept;
		void triangle_strip(std::size_t vertex_or_index_count) noexcept;
		void triangle_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangle_fan() noexcept;
		void triangle_fan(std::size_t vertex_or_index_count) noexcept;
		void triangle_fan(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
	};

	class _draw_instanced_basic_proxy
	{

	private:

		std::size_t m_vertex_count;
		std::size_t m_instance_count;
		int m_index_count;
		const GLuint* m_index_data_ptr;

	public:

		friend class _load_basic_2d_proxy;
		friend class _load_basic_3d_proxy;

		friend class _picker_2d_proxy;
		friend class _picker_3d_proxy;

		kiwi::_draw_instanced_basic_proxy& using_indices(const kiwi::index_buffer& index_buffer) noexcept;
		kiwi::_draw_instanced_basic_proxy& using_indices(const kiwi::index_buffer& index_buffer, std::size_t index_count) noexcept;
		kiwi::_draw_instanced_basic_proxy& using_indices(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		kiwi::_draw_instanced_basic_proxy& using_indices(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;


		void points_instanced() noexcept;
		void points_instanced(std::size_t instance_count) noexcept;
		void points_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void points_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void lines_instanced() noexcept;
		void lines_instanced(std::size_t instance_count) noexcept;
		void lines_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void lines_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangles_instanced() noexcept;
		void triangles_instanced(std::size_t instance_count) noexcept;
		void triangles_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void triangles_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void quads_instanced() noexcept;
		void quads_instanced(std::size_t instance_count) noexcept;
		void quads_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void quads_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void line_strip_instanced() noexcept;
		void line_strip_instanced(std::size_t instance_count) noexcept;
		void line_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void line_loop_instanced() noexcept;
		void line_loop_instanced(std::size_t instance_count) noexcept;
		void line_loop_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangle_strip_instanced() noexcept;
		void triangle_strip_instanced(std::size_t instance_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangle_fan_instanced() noexcept;
		void triangle_fan_instanced(std::size_t instance_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
	};

	class _draw_quad_sprite_proxy
	{

	private:

		std::size_t m_sprite_count;

	public:

		friend class _load_basic_2d_proxy;
		friend class _load_basic_3d_proxy;

		void quad_sprites() noexcept;
		void quad_sprites(std::size_t sprite_count) noexcept;
		void quad_sprites(std::size_t sprite_begin, std::size_t sprite_count) noexcept;
	};
}

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

#endif // KIWI_DRAW_HPP