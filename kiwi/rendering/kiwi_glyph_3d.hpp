#ifndef _KIWI_GLYPH_3D_HPP
#define _KIWI_GLYPH_3D_HPP

#include "rendering/kiwi_program.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_texture_2d.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "context/kiwi_context.hpp"
#include <vector>
#include <functional>


namespace kiwi
{
	class glyph_3d
	{

	public:

		glyph_3d() noexcept;
		glyph_3d(const kiwi::glyph_3d&) = delete;
		kiwi::glyph_3d& operator=(const kiwi::glyph_3d&) = delete;
		glyph_3d(kiwi::glyph_3d&&) = delete;
		kiwi::glyph_3d& operator=(kiwi::glyph_3d&&) = delete;
		~glyph_3d();

		bool init(std::size_t glyph_capacity);

		kiwi::glyph_3d& use_default_atlas();
		kiwi::glyph_3d& set_atlas(const kiwi::texture_2d* const atlas_texture_ptr, std::function<void(const int, const int, GLfloat* ptr)> atlas_function,
			const kiwi::UV& UV_size);
		kiwi::glyph_3d& set_atlas_texture(const kiwi::texture_2d* const atlas_texture_ptr);
		const kiwi::texture_2d* get_atlas_texture() const noexcept;

		kiwi::glyph_3d& set_origin(GLfloat X, GLfloat Y) noexcept;
		kiwi::glyph_3d& set_origin(const GLfloat* const XY_ptr) noexcept;
		kiwi::glyph_3d& set_plane(const kiwi::XYZ& origin_3d, const kiwi::XYZ& right_axis, const kiwi::XYZ& up_axis) noexcept;
		kiwi::glyph_3d& set_plane(const GLfloat* const origin_3d_ptr, const GLfloat* const right_axis_ptr, const GLfloat* const up_axis_ptr) noexcept;
		kiwi::glyph_3d& set_tile_size(GLfloat width, GLfloat height, GLfloat horizontal_offset = GL0, GLfloat vertical_offset = GL0) noexcept;

		kiwi::glyph_3d& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = GL1) noexcept;
		kiwi::glyph_3d& set_alpha_discard(GLfloat alpha_discard) noexcept;

		kiwi::glyph_3d& append_text(const char* const ptr) noexcept;
		kiwi::glyph_3d& append_text(const char* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& append_text(char glyph) noexcept;

		kiwi::glyph_3d& append_wtext(const wchar_t* const ptr) noexcept;
		kiwi::glyph_3d& append_wtext(const wchar_t* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& append_wtext(wchar_t glyph) noexcept;

		kiwi::glyph_3d& append_glyph(const int* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& append_glyph(const int* const ptr, std::size_t glyph_count, int end_line_glyph) noexcept;
		kiwi::glyph_3d& append_glyph(int glyph) noexcept;

		kiwi::glyph_3d& update_text(std::size_t glyph_number, char glyph) noexcept;
		kiwi::glyph_3d& update_wtext(std::size_t glyph_number, wchar_t glyph) noexcept;
		kiwi::glyph_3d& update_glyph(std::size_t glyph_number, int glyph) noexcept;

		kiwi::glyph_3d& append_text_modded(int mod_number, const char* const ptr) noexcept;
		kiwi::glyph_3d& append_text_modded(int mod_number, const char* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& append_text_modded(int mod_number, char glyph) noexcept;

		kiwi::glyph_3d& append_wtext_modded(int mod_number, const wchar_t* const ptr) noexcept;
		kiwi::glyph_3d& append_wtext_modded(int mod_number, const wchar_t* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& append_wtext_modded(int mod_number, wchar_t glyph) noexcept;

		kiwi::glyph_3d& append_glyph_modded(int mod_number, const int* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& append_glyph_modded(int mod_number, const int* const ptr, std::size_t glyph_count, int end_line_glyph) noexcept;
		kiwi::glyph_3d& append_glyph_modded(int mod_number, int glyph) noexcept;

		kiwi::glyph_3d& update_text_modded(int mod_number, std::size_t glyph_number, char glyph) noexcept;
		kiwi::glyph_3d& update_wtext_modded(int mod_number, std::size_t glyph_number, wchar_t glyph) noexcept;
		kiwi::glyph_3d& update_glyph_modded(int mod_number, std::size_t glyph_number, int glyph) noexcept;

		kiwi::glyph_3d& space(std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& end_line() noexcept;
		kiwi::glyph_3d& end_line(GLfloat lines_down) noexcept;
		kiwi::glyph_3d& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::glyph_3d& set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::glyph_3d& set_X(GLfloat X) noexcept;
		kiwi::glyph_3d& set_Y(GLfloat Y) noexcept;
		kiwi::glyph_3d& move_XY(GLfloat X_offset, GLfloat Y_offset) noexcept;
		kiwi::glyph_3d& move_XY(const GLfloat* const XY_offset_ptr) noexcept;
		kiwi::glyph_3d& move_X(GLfloat X_offset) noexcept;
		kiwi::glyph_3d& move_Y(GLfloat Y_offset) noexcept;

		kiwi::glyph_3d& draw_with(const GLfloat* const mvp_matrix_ptr) noexcept;
		kiwi::glyph_3d& draw_with(const GLfloat* const mvp_matrix_ptr, std::size_t begin_glyph, std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& clear_buffer() noexcept;
		kiwi::glyph_3d& clear_buffer(std::size_t glyph_count) noexcept;
		kiwi::glyph_3d& clear_buffer_after(std::size_t glyph_number) noexcept;

		kiwi::glyph_3d& finish_loading() noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat get_X_free() const noexcept;
		GLfloat get_Y_free() const noexcept;

		std::size_t glyph_count() const noexcept;
		std::size_t capacity() const noexcept;

	private:

		static constexpr std::size_t m_packet_size = 1024;
		static constexpr std::size_t m_number_of_default_colors = 8;

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		thread_local static unsigned int m_static_instance_count;

		thread_local static kiwi::program m_program;
		thread_local static kiwi::texture_2d m_default_atlas_texture;

		thread_local static GLint m_XY_UV_size_location;
		thread_local static GLint m_plane_location;
		thread_local static GLint m_RGBA_location;
		thread_local static GLint m_alpha_discard_location;
		thread_local static GLint m_mvp_matrix_location;


		kiwi::storage_buffer m_XY_UV_coordinates;
		const kiwi::texture_2d* m_atlas_texture = &m_default_atlas_texture;
		std::function<void(const int, const int, GLfloat*)> m_atlas_coordinate_function;

		GLfloat m_XY_UV_size[4] = { GL0, GL0, GL0, GL0 };
		GLfloat m_RGBA[4] = { GL1, GL1, GL1, GL1 };

		GLfloat m_XY[2] = { GL0, GL0 };
		GLfloat m_origin[2] = { GL0, GL0 };
		GLfloat m_right_up_orig[9] = {
			GL0, GL0, GL0,
			GL0, -GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_X_offset = GL0;
		GLfloat m_X_offset_inv = GL0;
		GLfloat m_Y_offset = GL0;
		GLfloat m_Y_offset_inv = GL0;
		GLfloat m_alpha_discard = static_cast<GLfloat>(0.5);

		std::size_t m_glyph_count = 0;
		std::size_t m_capacity = 0;

		std::vector<GLfloat> m_XY_UV_shift_temp_buffer;
		GLfloat* m_buffer_current_ptr = nullptr;
		GLfloat* m_buffer_end_ptr = nullptr;

		void generate_default_atlas_function();
		void generate_default_atlas_texture();
	};
}

#endif // _KIWI_GLYPH_3D_HPP