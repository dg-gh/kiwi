#ifndef KIWI_DRAW_HPP
#define KIWI_DRAW_HPP

#include "context/kiwi_context.hpp"
#include "rendering/kiwi_buffer_vertex.hpp"
#include "rendering/kiwi_buffer_index.hpp"
#include "rendering/kiwi_buffer_storage.hpp"
#include "rendering/kiwi_buffer_texture.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_sets.hpp"


namespace kiwi
{
	bool draw_init();
	void draw_terminate() noexcept;


	class _draw_proxy;
	class _load_2d_proxy;
	class _load_3d_proxy;

	class _draw_basic_proxy;
	class _draw_instanced_basic_proxy;
	class _load_basic_2d_proxy;
	class _load_basic_3d_proxy;

	kiwi::_load_basic_2d_proxy draw_2d_with() noexcept;
	kiwi::_load_basic_2d_proxy draw_2d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

	kiwi::_load_2d_proxy draw_2d_with(const kiwi::program& prog) noexcept;
	kiwi::_load_2d_proxy draw_2d_with(const kiwi::program& prog, const GLfloat* const transformation_matrix_ptr, GLint transformation_matrix_location) noexcept;

	kiwi::_load_basic_3d_proxy draw_3d_with(const GLfloat* const transformation_matrix_ptr) noexcept;

	kiwi::_load_3d_proxy draw_3d_with(const kiwi::program& prog, const GLfloat* const transformation_matrix_ptr, GLint transformation_matrix_location) noexcept;


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

		kiwi::_draw_instanced_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XY_RGBA_set& XY_RGBA_set) noexcept;
		kiwi::_draw_instanced_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_RGBA_set& XYZ_RGBA_set) noexcept;
		kiwi::_draw_instanced_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::XY_UV_set& XY_UV_set) noexcept;
		kiwi::_draw_instanced_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::XYZ_UV_set& XYZ_UV_set) noexcept;
	};

	class _load_2d_proxy
	{

	private:

		const kiwi::program* m_program_ptr;

	public:

		friend kiwi::_load_2d_proxy draw_2d_with(const kiwi::program& prog) noexcept;
		friend kiwi::_load_2d_proxy draw_2d_with(const kiwi::program& prog, const GLfloat* const transformation_matrix_ptr, GLint transformation_matrix_location) noexcept;

		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
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
		kiwi::_draw_basic_proxy using_no_shade(const kiwi::vertex_buffer& vertex_buffer, GLfloat depth_offset = static_cast<GLfloat>(0)) noexcept;

		kiwi::_draw_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::RGBA& solid_color, const GLfloat* const XYZ_ptr,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_RGBA_set& XYZ_RGBA_set,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_set& XYZ_set, const kiwi::XYZ_set& RGBA_set,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_RGBA_set& XYZ_RGBA_set, const kiwi::mat3x3f_set& mat3x3f_set,
			const GLfloat* const vp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_color_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_set& XYZ_set, const kiwi::XYZ_set& RGBA_set, const kiwi::mat3x3f_set& mat3x3f_set,
			const GLfloat* const vp_matrix_2d_ptr = nullptr) noexcept;

		kiwi::_draw_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::texture_buffer& texture_buffer, const GLfloat* const XYZ_ptr, const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::XYZ_UV_set& XYZ_UV_set, const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::XYZ_set& XYZ_set, const kiwi::UV_set& UV_set, const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::XYZ_UV_set& XYZ_UV_set, const kiwi::mat3x3f_set& mat3x3f_set, const GLfloat* const vp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_texture_sprite(const kiwi::vertex_buffer& vertex_buffer, const kiwi::vertex_buffer& UV_buffer,
			const kiwi::XYZ_set& XYZ_set, const kiwi::UV_set& UV_set, const kiwi::mat3x3f_set& mat3x3f_set, const GLfloat* const vp_matrix_2d_ptr = nullptr) noexcept;
	};

	class _load_3d_proxy
	{

	private:

		const kiwi::program* m_program_ptr;

	public:

		friend kiwi::_load_3d_proxy draw_3d_with(const kiwi::program& prog, const GLfloat* const transformation_matrix_ptr, GLint transformation_matrix_location) noexcept;

		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;
		kiwi::_draw_proxy using_data(
			const kiwi::vertex_buffer* const* const vertex_buffers_ptr, const GLuint* const vertex_pipeline_locations_ptr, std::size_t vertex_buffer_count,
			const kiwi::texture_buffer* const* const texture_buffers_ptr, const GLuint* const texture_pipeline_locations_ptr, std::size_t texture_buffer_count) noexcept;

		kiwi::_draw_proxy using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location) noexcept;
		kiwi::_draw_proxy using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location, std::size_t begin_float, std::size_t number_of_floats) noexcept;
		kiwi::_draw_proxy using_texture_data(const kiwi::texture_buffer& texture_buffer, GLuint location) noexcept;
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

		friend class picker_2d_proxy;
		friend class picker_3d_proxy;

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

		friend class picker_2d_proxy;
		friend class picker_3d_proxy;

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


	class _draw_proxy
	{

	private:

		std::size_t m_vertex_count;
		const kiwi::program* m_program_ptr;
		int m_index_count;
		const GLuint* m_index_data_ptr;

	public:

		friend class _load_2d_proxy;
		friend class _load_3d_proxy;

		kiwi::_draw_proxy& using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location) noexcept;
		kiwi::_draw_proxy& using_vertex_data(const kiwi::vertex_buffer& vertex_buffer, GLuint location, std::size_t begin_float, std::size_t number_of_floats) noexcept;
		kiwi::_draw_proxy& using_texture_data(const kiwi::texture_buffer& texture_buffer, GLuint location) noexcept;
		kiwi::_draw_proxy& using_storage_buffer(const kiwi::storage_buffer& storage_buffer, GLuint binding) noexcept;
		kiwi::_draw_proxy& using_storage_buffer(const kiwi::storage_buffer& storage_buffer, GLuint binding, std::size_t begin_byte, std::size_t number_of_bytes) noexcept;

		kiwi::_draw_proxy& using_uniform_1f(GLint location, GLfloat u0) noexcept;
		kiwi::_draw_proxy& using_uniform_2f(GLint location, GLfloat u0, GLfloat u1) noexcept;
		kiwi::_draw_proxy& using_uniform_3f(GLint location, GLfloat u0, GLfloat u1, GLfloat u2) noexcept;
		kiwi::_draw_proxy& using_uniform_4f(GLint location, GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3) noexcept;

		kiwi::_draw_proxy& using_uniform_2f(GLint location, const GLfloat* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_3f(GLint location, const GLfloat* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_4f(GLint location, const GLfloat* const values_ptr) noexcept;

		kiwi::_draw_proxy& using_uniform_3x3f(GLint location, const GLfloat* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_4x4f(GLint location, const GLfloat* const values_ptr) noexcept;

		kiwi::_draw_proxy& using_uniform_1i(GLint location, GLint u0) noexcept;
		kiwi::_draw_proxy& using_uniform_2i(GLint location, GLint u0, GLint u1) noexcept;
		kiwi::_draw_proxy& using_uniform_3i(GLint location, GLint u0, GLint u1, GLint u2) noexcept;
		kiwi::_draw_proxy& using_uniform_4i(GLint location, GLint u0, GLint u1, GLint u2, GLint u3) noexcept;

		kiwi::_draw_proxy& using_uniform_2i(GLint location, const GLint* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_3i(GLint location, const GLint* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_4i(GLint location, const GLint* const values_ptr) noexcept;

		kiwi::_draw_proxy& using_uniform_1ui(GLint location, GLuint u0) noexcept;
		kiwi::_draw_proxy& using_uniform_2ui(GLint location, GLuint u0, GLuint u1) noexcept;
		kiwi::_draw_proxy& using_uniform_3ui(GLint location, GLuint u0, GLuint u1, GLuint u2) noexcept;
		kiwi::_draw_proxy& using_uniform_4ui(GLint location, GLuint u0, GLuint u1, GLuint u2, GLuint u3) noexcept;

		kiwi::_draw_proxy& using_uniform_2ui(GLint location, const GLuint* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_3ui(GLint location, const GLuint* const values_ptr) noexcept;
		kiwi::_draw_proxy& using_uniform_4ui(GLint location, const GLuint* const values_ptr) noexcept;


		kiwi::_draw_proxy& using_indices(const kiwi::index_buffer& index_buffer) noexcept;
		kiwi::_draw_proxy& using_indices(const kiwi::index_buffer& index_buffer, std::size_t index_count) noexcept;
		kiwi::_draw_proxy& using_indices(const GLuint* const index_data_ptr, std::size_t index_count) noexcept;
		kiwi::_draw_proxy& using_indices(const GLuint* const index_data_ptr, std::size_t begin_index, std::size_t index_count) noexcept;


		void points() noexcept;
		void points(std::size_t vertex_or_index_count) noexcept;
		void points(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void points_instanced(std::size_t instance_count) noexcept;
		void points_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void points_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void lines() noexcept;
		void lines(std::size_t vertex_or_index_count) noexcept;
		void lines(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void lines_instanced(std::size_t instance_count) noexcept;
		void lines_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void lines_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangles() noexcept;
		void triangles(std::size_t vertex_or_index_count) noexcept;
		void triangles(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void triangles_instanced(std::size_t instance_count) noexcept;
		void triangles_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void triangles_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void quads() noexcept;
		void quads(std::size_t vertex_or_index_count) noexcept;
		void quads(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void quads_instanced(std::size_t instance_count) noexcept;
		void quads_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void quads_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void line_strip() noexcept;
		void line_strip(std::size_t vertex_or_index_count) noexcept;
		void line_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void line_strip_instanced(std::size_t instance_count) noexcept;
		void line_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void line_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void line_loop() noexcept;
		void line_loop(std::size_t vertex_or_index_count) noexcept;
		void line_loop(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void line_loop_instanced(std::size_t instance_count) noexcept;
		void line_loop_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void line_loop_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangle_fan() noexcept;
		void triangle_fan(std::size_t vertex_or_index_count) noexcept;
		void triangle_fan(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void triangle_fan_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;

		void triangle_strip() noexcept;
		void triangle_strip(std::size_t vertex_or_index_count) noexcept;
		void triangle_strip(std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count, std::size_t vertex_or_index_count) noexcept;
		void triangle_strip_instanced(std::size_t instance_count, std::size_t begin_vertex_or_index, std::size_t vertex_or_index_count) noexcept;
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