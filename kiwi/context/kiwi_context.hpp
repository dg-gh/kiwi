#ifndef KIWI_CONTEXT_HPP
#define KIWI_CONTEXT_HPP

#include "kiwi_includes.hpp"

namespace kiwi
{
	using GLFWwindow_pointer = GLFWwindow*;
	using current_buffer_pointer = const void*;
	using current_texture_pointer = const void*;
	using current_frame_pointer = const void*;
	using current_color_attachment = std::size_t;
	using current_program_pointer = const void*;
}

namespace kiwi
{
	void poll_for_events();
	void wait_for_events();
	void clear_frame_buffer();
	void clear_frame_buffer(GLbitfield& state);
	void swap_buffers();
	void swap_buffers(GLFWwindow* window_ptr);

	void clear_color_buffer();
	void clear_depth_buffer();
	void clear_stencil_buffer();

	namespace mode
	{
		void clear_color(GLfloat R, GLfloat G, GLfloat B, GLfloat A);

		void enable_transparency();
		void disable_transparency();

		void enable_point_sizing();
		void disable_point_sizing();

		void enable_point_smoothing();
		void disable_point_smoothing();

		void set_point_size(GLfloat size);
		void set_point_size_default();

		void enable_line_sizing();
		void disable_line_sizing();

		void enable_line_smoothing();
		void disable_line_smoothing();

		void set_line_size(GLfloat size);
		void set_line_size_default();

		void enable_depth();
		void disable_depth();

		void enable_depth(GLbitfield& state);
		void disable_depth(GLbitfield& state);

		void enable_stencil_buffer();
		void disable_stencil_buffer();

		void enable_stencil_buffer(GLbitfield& state);
		void disable_stencil_buffer(GLbitfield& state);

		void enable_face_culling(bool counter_clockwise_front_faces, bool cull_back_faces);
		void disable_face_culling();

		void enter_subwindow(float X_min, float Y_min, float X_max, float Y_max, bool rescale_screen_coordinates);
		void exit_subwindow();
	}

	int screen_width() noexcept;
	int screen_height() noexcept;
	GLint X_to_pixel(GLfloat X) noexcept;
	GLint Y_to_pixel(GLfloat Y) noexcept;
	GLfloat screen_ratio() noexcept;
	GLfloat screen_ratio_inv() noexcept;
	GLfloat min_X() noexcept;
	GLfloat max_X() noexcept;
	GLfloat min_Y() noexcept;
	GLfloat max_Y() noexcept;
	GLfloat pixel_X() noexcept;
	GLfloat pixel_Y() noexcept;
	const GLfloat* window_matrix_data() noexcept;
	unsigned int window_state_counter() noexcept;

	namespace context
	{
		kiwi::GLFWwindow_pointer& window() noexcept;
		GLbitfield& state() noexcept;
		kiwi::current_buffer_pointer& current_buffer() noexcept;
		kiwi::current_texture_pointer& current_texture_buffer() noexcept;
		kiwi::current_frame_pointer& current_frame_buffer() noexcept;
		kiwi::current_color_attachment& current_color_attachment() noexcept;
		kiwi::current_program_pointer& current_program() noexcept;

		void window_resize_callback(GLFWwindow* window, int screen_width, int screen_height);
		void delete_window_size_info();

		bool window_init(std::size_t width, std::size_t height,
			bool window_resizable,
			bool free_aspect_ratio,
			bool window_fullscreen,
			bool anti_aliasing_enabled,
			const char* const new_title);

		bool window_should_close();

		void window_terminate();

		void pop_tiny_window();
	}
}

#endif // KIWI_CONTEXT_HPP