#ifndef KIWI_GLYPH_2D_HPP
#define KIWI_GLYPH_2D_HPP

#include "rendering/kiwi_program.hpp"
#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_texture.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "context/kiwi_context.hpp"


namespace kiwi
{
	class glyph_2d
	{

	public:

		glyph_2d() noexcept;
		glyph_2d(const kiwi::glyph_2d&) = delete;
		kiwi::glyph_2d& operator=(const kiwi::glyph_2d&) = delete;
		glyph_2d(kiwi::glyph_2d&&) = delete;
		kiwi::glyph_2d& operator=(kiwi::glyph_2d&&) = delete;
		~glyph_2d();

		bool init(std::size_t char_capacity);

		kiwi::glyph_2d& use_default_atlas();
		kiwi::glyph_2d& set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr, std::function<void(const int, GLfloat* ptr)> atlas_function);
		const kiwi::texture_buffer* get_atlas_texture() const noexcept;

		kiwi::glyph_2d& set_origin(GLfloat X, GLfloat Y) noexcept;
		kiwi::glyph_2d& set_origin(const GLfloat* const XY_ptr) noexcept;
		kiwi::glyph_2d& set_tile_size(GLfloat width, GLfloat height, GLfloat horizontal_offset = GL0, GLfloat vertical_offset = GL0) noexcept;
		kiwi::glyph_2d& set_atlas_tile_size(GLfloat width, GLfloat height) noexcept;
		kiwi::glyph_2d& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = GL1) noexcept;

		kiwi::glyph_2d& append_text(const char* const ptr) noexcept;
		kiwi::glyph_2d& append_text(const char* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_2d& append_text(char glyph) noexcept;

		kiwi::glyph_2d& append_wtext(const wchar_t* const ptr) noexcept;
		kiwi::glyph_2d& append_wtext(const wchar_t* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_2d& append_wtext(wchar_t glyph) noexcept;

		kiwi::glyph_2d& append_glyph(const int* const ptr, std::size_t glyph_count) noexcept;
		kiwi::glyph_2d& append_glyph(int glyph) noexcept;

		kiwi::glyph_2d& update_text(std::size_t glyph_number, char glyph) noexcept;
		kiwi::glyph_2d& update_wtext(std::size_t glyph_number, wchar_t glyph) noexcept;
		kiwi::glyph_2d& update_glyph(std::size_t glyph_number, int glyph) noexcept;

		kiwi::glyph_2d& space(std::size_t glyph_count) noexcept;
		kiwi::glyph_2d& end_line() noexcept;
		kiwi::glyph_2d& end_line_up() noexcept;
		kiwi::glyph_2d& jump_to(GLfloat X, GLfloat Y) noexcept;

		kiwi::glyph_2d& draw_with() noexcept;
		kiwi::glyph_2d& draw_with(const GLfloat* const mvp_matrix_ptr) noexcept;
		kiwi::glyph_2d& clear_buffer() noexcept;
		kiwi::glyph_2d& clear_buffer(std::size_t glyph_count) noexcept;
		kiwi::glyph_2d& clear_buffer_after(std::size_t glyph_number) noexcept;

		std::size_t capacity() const noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		thread_local static unsigned int m_static_instance_count;

		thread_local static kiwi::program m_text_program;
		thread_local static kiwi::texture_buffer m_default_atlas_texture;

		thread_local static GLint m_XY_UV_size_location;
		thread_local static GLint m_RGBA_location;
		thread_local static GLint m_mvp_matrix_location;

		thread_local static GLfloat m_XY_UV_shift[4];


		kiwi::storage_buffer m_XY_UV_coordinates;
		const kiwi::texture_buffer* m_atlas_texture = &m_default_atlas_texture;
		std::function<void(const int, GLfloat*)> m_atlas_coordinate_function;

		GLfloat m_XY_UV_size[4] = { GL0, GL0, GL0, GL0 };
		GLfloat m_RGBA[4] = { GL1, GL1, GL1, GL1 };

		GLfloat m_origin[2] = { GL0, GL0 };
		GLfloat m_glyph_offset = GL0;
		GLfloat m_endline_offset = GL0;

		std::size_t m_glyph_count = 0;
		std::size_t m_capacity = 0;

		void generate_default_atlas_function();
		void generate_default_atlas_texture();
	};
}

#endif // KIWI_GLYPH_2D_HPP