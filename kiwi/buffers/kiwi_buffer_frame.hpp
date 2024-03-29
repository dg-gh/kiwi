#ifndef _KIWI_BUFFER_FRAME_HPP
#define _KIWI_BUFFER_FRAME_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_pixel.hpp"
#include "buffers/kiwi_buffer_texture_2d.hpp"
#include "buffers/kiwi_buffer_render.hpp"


namespace kiwi
{
	class frame_buffer
	{

	private:

		static constexpr std::size_t m_max_number_of_attachments = 8;

		GLuint m_frame_buffer_index;

		kiwi::pixel_buffer* m_texture_buffer_ptr[m_max_number_of_attachments];

		mutable GLenum m_textures_in_use[m_max_number_of_attachments];

		kiwi::render_buffer* m_render_buffer_ptr;

	public:

		frame_buffer() noexcept;
		frame_buffer(const frame_buffer&) = delete;
		frame_buffer& operator=(const frame_buffer&) = delete;
		frame_buffer(frame_buffer&&) noexcept;
		frame_buffer& operator=(frame_buffer&&) noexcept;
		~frame_buffer();

		kiwi::frame_buffer& new_id() noexcept;
		kiwi::frame_buffer& delete_id() noexcept;
		GLuint get_id() const noexcept;

		kiwi::frame_buffer& bind() noexcept;
		const kiwi::frame_buffer& bind() const noexcept;
		static void unbind() noexcept;

		kiwi::frame_buffer& use_with_texture(std::size_t color_attachment) noexcept;
		const kiwi::frame_buffer& use_with_texture(std::size_t color_attachment) const noexcept;

		kiwi::frame_buffer& use_with_textures(const GLenum* const color_attachments_ptr, std::size_t number_of_color_attachments) noexcept;
		const kiwi::frame_buffer& use_with_textures(const GLenum* const color_attachments_ptr, std::size_t number_of_color_attachments) const noexcept;

		static void exit_frame() noexcept;

		kiwi::frame_buffer& attach_texture(kiwi::texture_2d* texture_buffer_ptr, std::size_t color_attachment) noexcept;
		kiwi::frame_buffer& detach_texture(std::size_t color_attachment) noexcept;
		kiwi::frame_buffer& detach_all_textures() noexcept;

		kiwi::pixel_buffer* get_texture(std::size_t color_attachment) const noexcept;

		kiwi::frame_buffer& attach_render_buffer(kiwi::render_buffer* render_buffer_ptr) noexcept;
		kiwi::frame_buffer& detach_render_buffer() noexcept;
	};

	class scoped_frame
	{

	private:

		kiwi::frame_buffer* m_current_frame_buffer_ptr;
		const kiwi::frame_buffer* m_exit_frame_buffer_ptr;
		std::size_t m_exit_color_attachment;
		bool m_action_on_exit;

	public:

		scoped_frame(kiwi::frame_buffer& rhs) noexcept;
		scoped_frame(kiwi::frame_buffer& rhs, std::size_t texture_number) noexcept;
		scoped_frame(kiwi::frame_buffer& rhs, const GLenum* const texture_locations_ptr, std::size_t location_count) noexcept;

		kiwi::scoped_frame& set_frame_buffer_on_exit(const kiwi::frame_buffer& exit_frame_buffer, std::size_t color_attachment) noexcept;
		kiwi::scoped_frame& set_default_frame_buffer_on_exit() noexcept;

		kiwi::frame_buffer& get_frame_buffer() noexcept;

		scoped_frame() = delete;
		scoped_frame(const kiwi::scoped_frame&) = delete;
		kiwi::scoped_frame& operator=(const kiwi::scoped_frame&) = delete;
		scoped_frame(kiwi::scoped_frame&&) = delete;
		kiwi::scoped_frame& operator=(kiwi::scoped_frame&&) = delete;
		~scoped_frame();
	};
}


namespace kiwi
{
	class scoped_blit
	{

	public:

		scoped_blit(kiwi::frame_buffer& draw_frame, kiwi::frame_buffer& read_frame) noexcept;

		scoped_blit() = delete;
		scoped_blit(const kiwi::scoped_blit&) = delete;
		kiwi::scoped_blit& operator=(const kiwi::scoped_blit&) = delete;
		scoped_blit(kiwi::scoped_blit&&) = delete;
		kiwi::scoped_blit& operator=(kiwi::scoped_blit&&) = delete;
		~scoped_blit();

		kiwi::scoped_blit& no_action_on_exit() noexcept;
		kiwi::scoped_blit& set_frame_buffer_on_exit(const kiwi::frame_buffer& exit_frame_buffer, std::size_t color_attachment) noexcept;
		kiwi::scoped_blit& set_default_frame_buffer_on_exit() noexcept;
		kiwi::scoped_blit& blit(std::size_t draw_location, std::size_t read_location) noexcept;

	private:

		kiwi::frame_buffer* m_read_ptr;
		kiwi::frame_buffer* m_draw_ptr;
		const kiwi::frame_buffer* m_exit_frame_buffer_ptr;
		std::size_t m_exit_color_attachment;
		bool m_action_on_exit;
	};
}


namespace kiwi
{
	class frame_spec
	{

	public:

		kiwi::frame_spec& resize(const kiwi::XY& bottom_left, const kiwi::XY& top_right, const kiwi::size& size_2d) noexcept;

		int frame_width() const noexcept;
		int frame_height() const noexcept;
		GLint X_to_pixel(GLfloat X) const noexcept;
		GLint Y_to_pixel(GLfloat Y) const noexcept;
		GLfloat frame_ratio() const noexcept;
		GLfloat frame_ratio_inv()const  noexcept;
		GLfloat min_X() const  noexcept;
		GLfloat max_X() const noexcept;
		GLfloat min_Y() const noexcept;
		GLfloat max_Y() const noexcept;
		GLfloat pixel_X() const noexcept;
		GLfloat pixel_Y() const  noexcept;
		const GLfloat* window_matrix_data() const noexcept;
		bool in_frame(GLfloat X, GLfloat Y) const noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);
		static constexpr GLfloat GL2 = static_cast<GLfloat>(2);

		int m_screen_width = 0;
		int m_screen_height = 0;
		GLfloat m_screen_ratio = GL0;
		GLfloat m_screen_ratio_inv = GL0;
		GLfloat m_min_X = GL0;
		GLfloat m_max_X = GL0;
		GLfloat m_min_Y = GL0;
		GLfloat m_max_Y = GL0;
		GLfloat m_pixel_X = GL0;
		GLfloat m_pixel_Y = GL0;
		GLfloat m_window_matrix[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_a_X = GL1;
		GLfloat m_b_X = GL0;
		GLfloat m_a_Y = GL1;
		GLfloat m_b_Y = GL0;

		GLfloat m_from_X = GL0;
		GLfloat m_to_X = GL0;
		GLfloat m_from_Y = GL0;
		GLfloat m_to_Y = GL0;
	};
}

#endif // _KIWI_BUFFER_FRAME_HPP