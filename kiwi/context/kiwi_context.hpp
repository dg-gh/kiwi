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


namespace kiwi
{
	class RGBA
	{

	public:

		RGBA(GLfloat R, GLfloat G, GLfloat B) noexcept;
		RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept;

		RGBA() = default;
		RGBA(const kiwi::RGBA&) = default;
		kiwi::RGBA& operator=(const kiwi::RGBA&) = default;
		RGBA(kiwi::RGBA&&) = default;
		kiwi::RGBA& operator=(kiwi::RGBA&&) = default;
		~RGBA() = default;

		GLfloat& operator[](std::size_t offset) noexcept;
		const GLfloat& operator[](std::size_t offset) const noexcept;

		GLfloat& R() noexcept;
		const GLfloat& R() const noexcept;
		GLfloat& G() noexcept;
		const GLfloat& G() const noexcept;
		GLfloat& B() noexcept;
		const GLfloat& B() const noexcept;
		GLfloat& A() noexcept;
		const GLfloat& A() const noexcept;

		GLfloat* data() noexcept;
		const GLfloat* data() const noexcept;

	private:

		GLfloat m_RGBA[4] = { static_cast<GLfloat>(0) };
	};

	class size
	{

	public:

		size(std::size_t X, std::size_t Y) noexcept;

		size() = default;
		size(const kiwi::size&) = default;
		kiwi::size& operator=(const kiwi::size&) = default;
		size(kiwi::size&&) = default;
		kiwi::size& operator=(kiwi::size&&) = default;
		~size() = default;

		std::size_t& operator[](std::size_t offset) noexcept;
		const std::size_t& operator[](std::size_t offset) const noexcept;

		std::size_t& X() noexcept;
		const std::size_t& X() const noexcept;
		std::size_t& Y() noexcept;
		const std::size_t& Y() const noexcept;

		std::size_t* data() noexcept;
		const std::size_t* data() const noexcept;

	private:

		std::size_t m_resolution[2] = { 0, 0 };
	};

	class XYZ;

	class XY
	{

	public:

		friend class XYZ;

		XY(GLfloat X, GLfloat Y) noexcept;
		XY(kiwi::XYZ _XYZ) noexcept;

		XY() = default;
		XY(const kiwi::XY&) = default;
		kiwi::XY& operator=(const kiwi::XY&) = default;
		XY(kiwi::XY&&) = default;
		kiwi::XY& operator=(kiwi::XY&&) = default;
		~XY() = default;

		GLfloat& operator[](std::size_t offset) noexcept;
		const GLfloat& operator[](std::size_t offset) const noexcept;

		GLfloat& X() noexcept;
		const GLfloat& X() const noexcept;
		GLfloat& Y() noexcept;
		const GLfloat& Y() const noexcept;

		GLfloat* data() noexcept;
		const GLfloat* data() const noexcept;

	private:

		GLfloat m_XY[2] = { static_cast<GLfloat>(0), static_cast<GLfloat>(0) };
	};

	class XYZ
	{

	public:

		friend class XY;

		XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		XYZ(kiwi::XY _XY) noexcept;
		XYZ(kiwi::XY _XY, GLfloat Z) noexcept;

		XYZ() = default;
		XYZ(const kiwi::XYZ&) = default;
		kiwi::XYZ& operator=(const kiwi::XYZ&) = default;
		XYZ(kiwi::XYZ&&) = default;
		kiwi::XYZ& operator=(kiwi::XYZ&&) = default;
		~XYZ() = default;

		GLfloat& operator[](std::size_t offset) noexcept;
		const GLfloat& operator[](std::size_t offset) const noexcept;

		GLfloat& X() noexcept;
		const GLfloat& X() const noexcept;
		GLfloat& Y() noexcept;
		const GLfloat& Y() const noexcept;
		GLfloat& Z() noexcept;
		const GLfloat& Z() const noexcept;

		GLfloat* data() noexcept;
		const GLfloat* data() const noexcept;

	private:

		GLfloat m_XYZ[3] = { static_cast<GLfloat>(0), static_cast<GLfloat>(0), static_cast<GLfloat>(0) };
	};

	class RMEC
	{

	public:

		RMEC(GLfloat roughness) noexcept;
		RMEC(GLfloat roughness, GLfloat metalness) noexcept;
		RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity) noexcept;
		RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity, GLfloat ceiling) noexcept;

		RMEC() = default;
		RMEC(const kiwi::RMEC&) = default;
		kiwi::RMEC& operator=(const kiwi::RMEC&) = default;
		RMEC(kiwi::RMEC&&) = default;
		kiwi::RMEC& operator=(kiwi::RMEC&&) = default;
		~RMEC() = default;

		GLfloat& operator[](std::size_t offset) noexcept;
		const GLfloat& operator[](std::size_t offset) const noexcept;

		GLfloat& roughness() noexcept;
		const GLfloat& roughness() const noexcept;
		GLfloat& metalness() noexcept;
		const GLfloat& metalness() const noexcept;
		GLfloat& emissivity() noexcept;
		const GLfloat& emissivity() const noexcept;
		GLfloat& ceiling() noexcept;
		const GLfloat& ceiling() const noexcept;

		GLfloat* data() noexcept;
		const GLfloat* data() const noexcept;

	private:

		GLfloat m_RMEC[4] = { static_cast<GLfloat>(1), static_cast<GLfloat>(0), static_cast<GLfloat>(0), static_cast<GLfloat>(1) };
	};
}


#endif // KIWI_CONTEXT_HPP