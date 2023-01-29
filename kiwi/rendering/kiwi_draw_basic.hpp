#ifndef _KIWI_DRAW_HPP
#define _KIWI_DRAW_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_cubemap.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_index.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "buffers/kiwi_buffer_texture_1d.hpp"
#include "buffers/kiwi_buffer_texture_2d.hpp"
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

	kiwi::_load_basic_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr = kiwi::window_matrix_data()) noexcept;
	kiwi::_load_spec_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

	kiwi::_load_basic_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept;
	kiwi::_load_spec_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;


	class _load_basic_2d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend kiwi::_load_basic_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer, const kiwi::texture_2d& texture,
			const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture, GLfloat alpha_test_value) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture, GLfloat alpha_test_value, const kiwi::RGBA& RGBA) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
		kiwi::_draw_basic_proxy using_no_shade(const kiwi::vertex_buffer& vertex_buffer) noexcept;

		kiwi::_draw_instanced_basic_proxy using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer,
			const kiwi::XYZA_set& XYZA_set, const kiwi::RGBA_set& RGBA_set) noexcept;

		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::UV_set& UV_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard) noexcept;
		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::id_set& id_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard) noexcept;
	};

	class _load_spec_2d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;
		const GLfloat* m_m_matrix_ptr;

	public:

		friend kiwi::_load_spec_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_point_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XY& origin, const kiwi::NF& near_far) noexcept;
		kiwi::_draw_basic_proxy using_point_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XY& origin, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_point_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XY& origin, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
		kiwi::_draw_basic_proxy using_plane_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XY& origin, const kiwi::XY& dir, const kiwi::NF& near_far) noexcept;
		kiwi::_draw_basic_proxy using_plane_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XY& origin, const kiwi::XY& dir, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_plane_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XY& origin, const kiwi::XY& dir,  const kiwi::NF& near_far, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
	};

	class _load_basic_3d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend kiwi::_load_basic_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_solid_color(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_color_gradient(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& color_vertex_buffer,
			const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer, GLfloat alpha_test_value) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_texture_alpha_test(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer, GLfloat alpha_test_value, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;

		void using_skybox(const kiwi::cubemap& skybox_buffer) noexcept;
		void using_skybox(const kiwi::cubemap& skybox_buffer, const kiwi::RGBA& RGBAx) noexcept;
		void using_skybox(const kiwi::cubemap& skybox_buffer, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;

		kiwi::_draw_basic_proxy using_no_shade(const kiwi::vertex_buffer& vertex_buffer, GLfloat depth_offset = static_cast<GLfloat>(0)) noexcept;

		kiwi::_draw_basic_proxy using_solid_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ& position, GLfloat angle, const kiwi::RGBA& solid_color,
			bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_instanced_basic_proxy using_solid_color_sprites(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZA_set& XYZA_set, const kiwi::RGBA_set& RGBA_set,
			bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;

		kiwi::_draw_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_2d& texture_buffer, const kiwi::XYZ& position, GLfloat angle,
			GLfloat alpha_discard, bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::UV_set& UV_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard, bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
		kiwi::_draw_quad_sprite_proxy using_texture_sprites(const kiwi::XYZA_set& XYZA_set, const kiwi::id_set& id_set, const kiwi::XY& XY_size,
			GLfloat alpha_discard, bool depth_scaling = true, const GLfloat* const mvp_matrix_2d_ptr = kiwi::window_matrix_data()) noexcept;
	};


	class _load_spec_3d_proxy
	{

	private:

		const GLfloat* m_transformation_matrix_ptr;
		const GLfloat* m_m_matrix_ptr;

	public:

		friend kiwi::_load_spec_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr, const GLfloat* const m_matrix_ptr) noexcept;

		kiwi::_draw_basic_proxy using_point_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& origin, const kiwi::NF& near_far) noexcept;
		kiwi::_draw_basic_proxy using_point_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& origin, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_point_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& origin, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;

		kiwi::_draw_basic_proxy using_plane_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& origin, const kiwi::XYZ& dir, const kiwi::NF& near_far) noexcept;
		kiwi::_draw_basic_proxy using_plane_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& origin, const kiwi::XYZ& dir, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_plane_dist_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& origin, const kiwi::XYZ& dir, const kiwi::NF& near_far, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;

		kiwi::_draw_basic_proxy using_normal_dir_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& dir) noexcept;
		kiwi::_draw_basic_proxy using_normal_dir_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& dir, const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_normal_dir_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer, const kiwi::texture_1d& texture,
			const kiwi::XYZ& dir, const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;

		kiwi::_draw_basic_proxy using_normal_cubemap_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer, const kiwi::cubemap& cubemap) noexcept;
		kiwi::_draw_basic_proxy using_normal_cubemap_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer, const kiwi::cubemap& cubemap,
			const kiwi::RGBA& RGBAx) noexcept;
		kiwi::_draw_basic_proxy using_normal_cubemap_texture(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& N_buffer, const kiwi::cubemap& cubemap,
			const kiwi::RGBA& RGBAx, const kiwi::RGBA& RGBAo) noexcept;
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

#endif // _KIWI_DRAW_HPP