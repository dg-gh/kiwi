#include "context/kiwi_context.hpp"


void kiwi::poll_for_events()
{
	glfwPollEvents();
}

void kiwi::wait_for_events()
{
	glfwWaitEvents();
}

namespace kiwi
{
	class window_context
	{

	public:

		GLFWwindow* window_ptr = nullptr;
		GLbitfield state = GL_COLOR_BUFFER_BIT;
		const void* current_buffer_ptr = nullptr;
		const void* current_texture_ptr = nullptr;
		const void* current_frame_ptr = nullptr;
		std::size_t current_color_attachment = 0;
		const void* current_program_ptr = nullptr;


		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

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

		unsigned int m_state_counter = 0;
	};

	static kiwi::window_context user_window_context;
}

void kiwi::swap_buffers()
{
	glfwSwapBuffers(kiwi::user_window_context.window_ptr);
}

void kiwi::swap_buffers(GLFWwindow* window_ptr)
{
	glfwSwapBuffers(window_ptr);
}

void kiwi::clear_frame_buffer()
{
	glClear(kiwi::user_window_context.state);
}

void kiwi::clear_frame_buffer(GLbitfield& state)
{
	glClear(state);
}

void kiwi::clear_color_buffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void kiwi::clear_depth_buffer()
{
	glClear(GL_DEPTH_BUFFER_BIT);
}

void kiwi::clear_stencil_buffer()
{
	glClear(GL_STENCIL_BUFFER_BIT);
}

void kiwi::mode::clear_color(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
	glClearColor(R, G, B, A);
}

void kiwi::mode::enable_transparency()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void kiwi::mode::disable_transparency()
{
	glBlendFunc(GL_ONE, GL_ZERO);
}

void kiwi::mode::enable_point_sizing()
{
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void kiwi::mode::disable_point_sizing()
{
	glDisable(GL_PROGRAM_POINT_SIZE);
}

void kiwi::mode::enable_point_smoothing()
{
	glEnable(GL_POINT_SMOOTH);
}

void kiwi::mode::disable_point_smoothing()
{
	glDisable(GL_POINT_SMOOTH);
}

void kiwi::mode::set_point_size(GLfloat size)
{
	glPointSize(size);
}

void kiwi::mode::set_point_size_default()
{
	glPointSize(static_cast<GLfloat>(1.0f));
}

void kiwi::mode::enable_line_sizing()
{
	glEnable(GL_LINE_WIDTH);
}

void kiwi::mode::disable_line_sizing()
{
	glDisable(GL_LINE_WIDTH);
}

void kiwi::mode::enable_line_smoothing()
{
	glEnable(GL_LINE_SMOOTH);
}

void kiwi::mode::disable_line_smoothing()
{
	glDisable(GL_LINE_SMOOTH);
}

void kiwi::mode::set_line_size(GLfloat size)
{
	glLineWidth(static_cast<GLfloat>(size));
}

void kiwi::mode::set_line_size_default()
{
	glLineWidth(static_cast<GLfloat>(1.0f));
}

void kiwi::mode::enable_depth()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	kiwi::context::state() |= GL_DEPTH_BUFFER_BIT;
}

void kiwi::mode::disable_depth()
{
	glDisable(GL_DEPTH_TEST);
	GLbitfield state = kiwi::context::state();
	kiwi::context::state() = GL_COLOR_BUFFER_BIT | (state & GL_STENCIL_BUFFER_BIT);
}

void kiwi::mode::enable_depth(GLbitfield& state)
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	state |= GL_DEPTH_BUFFER_BIT;
}

void kiwi::mode::disable_depth(GLbitfield& state)
{
	glDisable(GL_DEPTH_TEST);
	state = GL_COLOR_BUFFER_BIT | (state & GL_STENCIL_BUFFER_BIT);
}

void kiwi::mode::enable_stencil_buffer()
{
	glEnable(GL_STENCIL_TEST);
	kiwi::context::state() |= GL_STENCIL_BUFFER_BIT;
}

void kiwi::mode::disable_stencil_buffer()
{
	glDisable(GL_STENCIL_TEST);
	GLbitfield state = kiwi::context::state();
	kiwi::context::state() = GL_COLOR_BUFFER_BIT | (state & GL_DEPTH_BUFFER_BIT);
}

void kiwi::mode::enable_stencil_buffer(GLbitfield& state)
{
	glEnable(GL_STENCIL_TEST);
	state |= GL_STENCIL_BUFFER_BIT;
}

void kiwi::mode::disable_stencil_buffer(GLbitfield& state)
{
	glDisable(GL_STENCIL_TEST);
	state = GL_COLOR_BUFFER_BIT | (state & GL_DEPTH_BUFFER_BIT);
}

void kiwi::mode::enable_face_culling(bool counter_clockwise_front_faces, bool cull_back_faces)
{
	glEnable(GL_CULL_FACE);

	if (counter_clockwise_front_faces)
	{
		glFrontFace(GL_CCW);
	}
	else
	{
		glFrontFace(GL_CW);
	}

	if (cull_back_faces)
	{
		glCullFace(GL_BACK);
	}
	else
	{
		glCullFace(GL_FRONT);
	}
}

void kiwi::mode::disable_face_culling()
{
	glDisable(GL_CULL_FACE);
}

void kiwi::mode::enter_subwindow(float X_min, float Y_min, float X_max, float Y_max, bool rescale_screen_coordinates)
{
	int screen_width;
	int screen_height;
	glfwGetWindowSize(kiwi::context::window(), &screen_width, &screen_height);

	if (rescale_screen_coordinates)
	{
		float screen_ratio = static_cast<float>(screen_width) / static_cast<float>(screen_height);
		float screen_ratio_inv = static_cast<float>(screen_height) / static_cast<float>(screen_width);

		if (screen_width >= screen_height)
		{
			float factor_X = 0.5f * static_cast<float>(screen_width) * screen_ratio_inv;
			float factor_Y = 0.5f * static_cast<float>(screen_height);
			glViewport(static_cast<int>(factor_X * (X_min + screen_ratio)), static_cast<int>(factor_Y * (Y_min + 1.0f)),
				static_cast<GLsizei>(factor_X * (X_max - X_min)), static_cast<GLsizei>(factor_Y * (Y_max - Y_min)));
		}
		else
		{
			float factor_X = 0.5f * static_cast<float>(screen_width);
			float factor_Y = 0.5f * static_cast<float>(screen_height) * screen_ratio;
			glViewport(static_cast<int>(factor_X * (X_min + 1.0f)), static_cast<int>(factor_Y * (Y_min + screen_ratio_inv)),
				static_cast<GLsizei>(factor_X * (X_max - X_min)), static_cast<GLsizei>(factor_Y * (Y_max - Y_min)));
		}
	}
	else
	{
		if (screen_width >= screen_height)
		{
			float screen_ratio_inv = static_cast<float>(screen_height) / static_cast<float>(screen_width);

			float factor_X = 0.5f * static_cast<float>(screen_width) * screen_ratio_inv;
			float factor_Y = 0.5f * static_cast<float>(screen_height);
			glViewport(static_cast<int>(factor_X * (X_min + 1.0f)), static_cast<int>(factor_Y * (Y_min + 1.0f)),
				static_cast<GLsizei>(factor_X * (X_max + 1.0f)), static_cast<GLsizei>(factor_Y * (Y_max + 1.0f)));
		}
		else
		{
			float screen_ratio = static_cast<float>(screen_width) / static_cast<float>(screen_height);

			float factor_X = 0.5f * static_cast<float>(screen_width);
			float factor_Y = 0.5f * static_cast<float>(screen_height) * screen_ratio;
			glViewport(static_cast<int>(factor_X * (X_min + 1.0f)), static_cast<int>(factor_Y * (Y_min + 1.0f)),
				static_cast<GLsizei>(factor_X * (X_max + 1.0f)), static_cast<GLsizei>(factor_Y * (Y_max + 1.0f)));
		}
	}
}

void kiwi::mode::exit_subwindow()
{
	int screen_width;
	int screen_height;
	glfwGetWindowSize(kiwi::context::window(), &screen_width, &screen_height);
	glViewport(0, 0, static_cast<GLsizei>(screen_width), static_cast<GLsizei>(screen_height));
}


kiwi::GLFWwindow_pointer& kiwi::context::window() noexcept
{
	return kiwi::user_window_context.window_ptr;
}

GLbitfield& kiwi::context::state() noexcept
{
	return kiwi::user_window_context.state;
}

kiwi::current_buffer_pointer& kiwi::context::current_buffer() noexcept
{
	return kiwi::user_window_context.current_buffer_ptr;
}

kiwi::current_texture_pointer& kiwi::context::current_texture_buffer() noexcept
{
	return kiwi::user_window_context.current_texture_ptr;
}

kiwi::current_frame_pointer& kiwi::context::current_frame_buffer() noexcept
{
	return kiwi::user_window_context.current_frame_ptr;
}

kiwi::current_color_attachment& kiwi::context::current_color_attachment() noexcept
{
	return kiwi::user_window_context.current_color_attachment;
}

kiwi::current_program_pointer& kiwi::context::current_program() noexcept
{
	return kiwi::user_window_context.current_program_ptr;
}

int kiwi::screen_width() noexcept { return kiwi::user_window_context.m_screen_width; }
int kiwi::screen_height() noexcept { return kiwi::user_window_context.m_screen_height; }
GLint kiwi::X_to_pixel(GLfloat X) noexcept
{
	return kiwi::user_window_context.m_a_X * X + kiwi::user_window_context.m_b_X;
}
GLint kiwi::Y_to_pixel(GLfloat Y) noexcept
{
	return kiwi::user_window_context.m_a_Y * Y + kiwi::user_window_context.m_b_Y;
}
GLfloat kiwi::screen_ratio() noexcept { return kiwi::user_window_context.m_screen_ratio; }
GLfloat kiwi::screen_ratio_inv() noexcept { return kiwi::user_window_context.m_screen_ratio_inv; }
GLfloat kiwi::min_X() noexcept { return kiwi::user_window_context.m_min_X; }
GLfloat kiwi::max_X() noexcept { return kiwi::user_window_context.m_max_X; }
GLfloat kiwi::min_Y() noexcept { return kiwi::user_window_context.m_min_Y; }
GLfloat kiwi::max_Y() noexcept { return kiwi::user_window_context.m_max_Y; }
GLfloat kiwi::pixel_X() noexcept { return kiwi::user_window_context.m_pixel_X; }
GLfloat kiwi::pixel_Y() noexcept { return kiwi::user_window_context.m_pixel_Y; }
const GLfloat* kiwi::window_matrix_data() noexcept { return static_cast<const GLfloat*>(kiwi::user_window_context.m_window_matrix); }
unsigned int kiwi::window_state_counter() noexcept { return kiwi::user_window_context.m_state_counter; }

void kiwi::context::window_resize_callback(GLFWwindow* window, int new_screen_width, int new_screen_height)
{
	static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	static constexpr GLfloat GL1 = static_cast<GLfloat>(1);
	static constexpr GLfloat GL2 = static_cast<GLfloat>(2);

	glViewport(0, 0, static_cast<GLsizei>(new_screen_width), static_cast<GLsizei>(new_screen_height));

	kiwi::user_window_context.m_screen_width = new_screen_width;
	kiwi::user_window_context.m_screen_height = new_screen_height;

	GLfloat new_screen_width_f = static_cast<GLfloat>(new_screen_width);
	GLfloat new_screen_height_f = static_cast<GLfloat>(new_screen_height);

	kiwi::user_window_context.m_screen_ratio = static_cast<float>(new_screen_width_f) / static_cast<float>(new_screen_height_f);
	kiwi::user_window_context.m_screen_ratio_inv = static_cast<float>(new_screen_height_f) / static_cast<float>(new_screen_width_f);

	if (new_screen_width >= new_screen_height)
	{
		kiwi::user_window_context.m_min_X = -kiwi::user_window_context.m_screen_ratio;
		kiwi::user_window_context.m_max_X = kiwi::user_window_context.m_screen_ratio;
		kiwi::user_window_context.m_min_Y = -GL1;
		kiwi::user_window_context.m_max_Y = GL1;
		kiwi::user_window_context.m_pixel_X = GL2 / new_screen_height_f;
		kiwi::user_window_context.m_pixel_Y = kiwi::user_window_context.m_pixel_X;

		kiwi::user_window_context.m_window_matrix[0] = kiwi::user_window_context.m_screen_ratio_inv;
		kiwi::user_window_context.m_window_matrix[4] = GL1;

		kiwi::user_window_context.m_b_X = static_cast<GLfloat>(kiwi::user_window_context.m_screen_width / 2);
		kiwi::user_window_context.m_a_X = kiwi::user_window_context.m_screen_ratio_inv * kiwi::user_window_context.m_b_X;
		kiwi::user_window_context.m_b_Y = static_cast<GLfloat>(kiwi::user_window_context.m_screen_height / 2);
		kiwi::user_window_context.m_a_Y = kiwi::user_window_context.m_b_Y;
	}
	else
	{
		kiwi::user_window_context.m_min_X = -GL1;
		kiwi::user_window_context.m_max_X = GL1;
		kiwi::user_window_context.m_min_Y = -kiwi::user_window_context.m_screen_ratio_inv;
		kiwi::user_window_context.m_max_Y = kiwi::user_window_context.m_screen_ratio_inv;
		kiwi::user_window_context.m_pixel_X = GL2 / new_screen_width_f;
		kiwi::user_window_context.m_pixel_Y = kiwi::user_window_context.m_pixel_X;

		kiwi::user_window_context.m_window_matrix[0] = GL1;
		kiwi::user_window_context.m_window_matrix[4] = kiwi::user_window_context.m_screen_ratio;

		kiwi::user_window_context.m_b_X = static_cast<GLfloat>(kiwi::user_window_context.m_screen_width / 2);
		kiwi::user_window_context.m_a_X = kiwi::user_window_context.m_b_X;
		kiwi::user_window_context.m_b_Y = static_cast<GLfloat>(kiwi::user_window_context.m_screen_height / 2);
		kiwi::user_window_context.m_a_Y = kiwi::user_window_context.m_screen_ratio * kiwi::user_window_context.m_b_Y;
	}

	kiwi::user_window_context.m_state_counter++;
}

void kiwi::context::delete_window_size_info()
{
	static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	kiwi::user_window_context.m_screen_width = 0;
	kiwi::user_window_context.m_screen_height = 0;
	kiwi::user_window_context.m_screen_ratio = GL0;
	kiwi::user_window_context.m_screen_ratio_inv = GL0;
	kiwi::user_window_context.m_min_X = GL0;
	kiwi::user_window_context.m_max_X = GL0;
	kiwi::user_window_context.m_min_Y = GL0;
	kiwi::user_window_context.m_max_Y = GL0;
	kiwi::user_window_context.m_pixel_X = GL0;
	kiwi::user_window_context.m_pixel_Y = GL0;

	kiwi::user_window_context.m_window_matrix[0] = GL1;
	kiwi::user_window_context.m_window_matrix[1] = GL0;
	kiwi::user_window_context.m_window_matrix[2] = GL0;
	kiwi::user_window_context.m_window_matrix[3] = GL0;
	kiwi::user_window_context.m_window_matrix[4] = GL1;
	kiwi::user_window_context.m_window_matrix[5] = GL0;
	kiwi::user_window_context.m_window_matrix[6] = GL0;
	kiwi::user_window_context.m_window_matrix[7] = GL0;
	kiwi::user_window_context.m_window_matrix[8] = GL1;

	kiwi::user_window_context.m_a_X = GL1;
	kiwi::user_window_context.m_a_Y = GL0;
	kiwi::user_window_context.m_b_X = GL1;
	kiwi::user_window_context.m_b_Y = GL0;

	kiwi::user_window_context.m_state_counter = 0;
}

kiwi::RGBA::RGBA(GLfloat R, GLfloat G, GLfloat B) noexcept : m_RGBA{ R, G, B, 1.0f } {}

kiwi::RGBA::RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept : m_RGBA{ R, G, B, A } {}

GLfloat& kiwi::RGBA::operator[](std::size_t offset) noexcept
{
	return m_RGBA[offset];
}

const GLfloat& kiwi::RGBA::operator[](std::size_t offset) const noexcept
{
	return m_RGBA[offset];
}

GLfloat& kiwi::RGBA::R() noexcept
{
	return m_RGBA[0];
}

const GLfloat& kiwi::RGBA::R() const noexcept
{
	return m_RGBA[0];
}

GLfloat& kiwi::RGBA::G() noexcept
{
	return m_RGBA[1];
}

const GLfloat& kiwi::RGBA::G() const noexcept
{
	return m_RGBA[1];
}

GLfloat& kiwi::RGBA::B() noexcept
{
	return m_RGBA[2];
}

const GLfloat& kiwi::RGBA::B() const noexcept
{
	return m_RGBA[2];
}

GLfloat& kiwi::RGBA::A() noexcept
{
	return m_RGBA[3];
}

const GLfloat& kiwi::RGBA::A() const noexcept
{
	return m_RGBA[3];
}

GLfloat* kiwi::RGBA::data() noexcept
{
	return static_cast<GLfloat*>(m_RGBA);
}

const GLfloat* kiwi::RGBA::data() const noexcept
{
	return static_cast<const GLfloat*>(m_RGBA);
}


kiwi::size::size(std::size_t X, std::size_t Y) noexcept : m_resolution{ X, Y } {}


std::size_t& kiwi::size::operator[](std::size_t offset) noexcept
{
	return m_resolution[offset];
}

const std::size_t& kiwi::size::operator[](std::size_t offset) const noexcept
{
	return m_resolution[offset];
}

std::size_t& kiwi::size::X() noexcept
{
	return m_resolution[0];
}

const std::size_t& kiwi::size::X() const noexcept
{
	return m_resolution[0];
}

std::size_t& kiwi::size::Y() noexcept
{
	return m_resolution[1];
}

const std::size_t& kiwi::size::Y() const noexcept
{
	return m_resolution[1];
}

std::size_t* kiwi::size::data() noexcept
{
	return static_cast<std::size_t*>(m_resolution);
}

const std::size_t* kiwi::size::data() const noexcept
{
	return static_cast<const std::size_t*>(m_resolution);
}


kiwi::XY::XY(GLfloat X, GLfloat Y) noexcept : m_XY{ X, Y } {}

kiwi::XY::XY(kiwi::XYZ _XYZ) noexcept : m_XY{ _XYZ.m_XYZ[0], _XYZ.m_XYZ[1] } {}

GLfloat& kiwi::XY::operator[](std::size_t offset) noexcept
{
	return m_XY[offset];
}

const GLfloat& kiwi::XY::operator[](std::size_t offset) const noexcept
{
	return m_XY[offset];
}

GLfloat& kiwi::XY::X() noexcept
{
	return m_XY[0];
}

const GLfloat& kiwi::XY::X() const noexcept
{
	return m_XY[0];
}

GLfloat& kiwi::XY::Y() noexcept
{
	return m_XY[1];
}

const GLfloat& kiwi::XY::Y() const noexcept
{
	return m_XY[1];
}

GLfloat* kiwi::XY::data() noexcept
{
	return static_cast<GLfloat*>(m_XY);
}

const GLfloat* kiwi::XY::data() const noexcept
{
	return static_cast<const GLfloat*>(m_XY);
}


kiwi::XYZ::XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept : m_XYZ{ X, Y, Z } {}

kiwi::XYZ::XYZ(kiwi::XY _XY) noexcept : m_XYZ{ _XY.m_XY[0], _XY.m_XY[1], static_cast<GLfloat>(0) } {}

kiwi::XYZ::XYZ(kiwi::XY _XY, GLfloat Z) noexcept : m_XYZ{ _XY.m_XY[0], _XY.m_XY[1], Z } {}

GLfloat& kiwi::XYZ::operator[](std::size_t offset) noexcept
{
	return m_XYZ[offset];
}

const GLfloat& kiwi::XYZ::operator[](std::size_t offset) const noexcept
{
	return m_XYZ[offset];
}

GLfloat& kiwi::XYZ::X() noexcept
{
	return m_XYZ[0];
}

const GLfloat& kiwi::XYZ::X() const noexcept
{
	return m_XYZ[0];
}

GLfloat& kiwi::XYZ::Y() noexcept
{
	return m_XYZ[1];
}

const GLfloat& kiwi::XYZ::Y() const noexcept
{
	return m_XYZ[1];
}

GLfloat& kiwi::XYZ::Z() noexcept
{
	return m_XYZ[2];
}

const GLfloat& kiwi::XYZ::Z() const noexcept
{
	return m_XYZ[2];
}

GLfloat* kiwi::XYZ::data() noexcept
{
	return static_cast<GLfloat*>(m_XYZ);
}

const GLfloat* kiwi::XYZ::data() const noexcept
{
	return static_cast<const GLfloat*>(m_XYZ);
}


kiwi::UV::UV(GLfloat U, GLfloat V) noexcept : m_UV{ U, V } {}

GLfloat& kiwi::UV::operator[](std::size_t offset) noexcept
{
	return m_UV[offset];
}

const GLfloat& kiwi::UV::operator[](std::size_t offset) const noexcept
{
	return m_UV[offset];
}

GLfloat& kiwi::UV::U() noexcept
{
	return m_UV[0];
}

const GLfloat& kiwi::UV::U() const noexcept
{
	return m_UV[0];
}

GLfloat& kiwi::UV::V() noexcept
{
	return m_UV[1];
}

const GLfloat& kiwi::UV::V() const noexcept
{
	return m_UV[1];
}

GLfloat* kiwi::UV::data() noexcept
{
	return static_cast<GLfloat*>(m_UV);
}

const GLfloat* kiwi::UV::data() const noexcept
{
	return static_cast<const GLfloat*>(m_UV);
}


kiwi::RMEC::RMEC(GLfloat roughness) noexcept : m_RMEC{ roughness, static_cast<GLfloat>(0), static_cast<GLfloat>(0), static_cast<GLfloat>(1) } {}

kiwi::RMEC::RMEC(GLfloat roughness, GLfloat metalness) noexcept : m_RMEC{ roughness, metalness, static_cast<GLfloat>(0), static_cast<GLfloat>(1) } {}

kiwi::RMEC::RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity) noexcept : m_RMEC{ roughness, metalness, emissivity, static_cast<GLfloat>(1) } {}

kiwi::RMEC::RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity, GLfloat ceiling) noexcept : m_RMEC{ roughness, metalness, emissivity, ceiling } {}

GLfloat& kiwi::RMEC::operator[](std::size_t offset) noexcept
{
	return m_RMEC[offset];
}

const GLfloat& kiwi::RMEC::operator[](std::size_t offset) const noexcept
{
	return m_RMEC[offset];
}

GLfloat& kiwi::RMEC::roughness() noexcept
{
	return m_RMEC[0];
}

const GLfloat& kiwi::RMEC::roughness() const noexcept
{
	return m_RMEC[0];
}

GLfloat& kiwi::RMEC::metalness() noexcept
{
	return m_RMEC[1];
}

const GLfloat& kiwi::RMEC::metalness() const noexcept
{
	return m_RMEC[1];
}

GLfloat& kiwi::RMEC::emissivity() noexcept
{
	return m_RMEC[2];
}

const GLfloat& kiwi::RMEC::emissivity() const noexcept
{
	return m_RMEC[2];
}

GLfloat& kiwi::RMEC::ceiling() noexcept
{
	return m_RMEC[3];
}

const GLfloat& kiwi::RMEC::ceiling() const noexcept
{
	return m_RMEC[3];
}

GLfloat* kiwi::RMEC::data() noexcept
{
	return static_cast<GLfloat*>(m_RMEC);
}

const GLfloat* kiwi::RMEC::data() const noexcept
{
	return static_cast<const GLfloat*>(m_RMEC);
}

bool kiwi::context::window_init(std::size_t width, std::size_t height,
	bool window_resizable,
	bool free_aspect_ratio,
	bool window_fullscreen,
	bool anti_aliasing_enabled,
	const char* const new_title)
{
	if (!glfwInit())
	{
		return false;
	}

	// window specs

	int new_screen_width = static_cast<int>(width);
	int new_screen_height = static_cast<int>(height);

	if (window_resizable) { glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); }
	else { glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); }

	if (anti_aliasing_enabled) { glfwWindowHint(GLFW_SAMPLES, 4); }

	if (window_fullscreen)
	{
		kiwi::context::window() = glfwCreateWindow(new_screen_width, new_screen_height,
			new_title, glfwGetPrimaryMonitor(), nullptr);
	}
	else
	{
		kiwi::context::window() = glfwCreateWindow(new_screen_width, new_screen_height,
			new_title, nullptr, nullptr);
	}

	if (kiwi::context::window() == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(kiwi::context::window());
	glfwSetWindowSizeCallback(kiwi::context::window(), kiwi::context::window_resize_callback);
	kiwi::context::window_resize_callback(kiwi::context::window(), new_screen_width, new_screen_height);

	if (window_resizable && !free_aspect_ratio)
	{
		glfwSetWindowAspectRatio(kiwi::context::window(), new_screen_width, new_screen_height);
	}

	// glew init

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return false;
	}

	// display

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ZERO);
	if (anti_aliasing_enabled) { glEnable(GL_MULTISAMPLE); }

	return true;
}

void kiwi::context::window_terminate()
{
	glfwSetWindowAspectRatio(kiwi::user_window_context.window_ptr, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwDestroyWindow(kiwi::user_window_context.window_ptr);
	glfwTerminate();
}

bool kiwi::context::window_should_close()
{
	return glfwWindowShouldClose(kiwi::user_window_context.window_ptr);
}

void kiwi::context::pop_tiny_window()
{
	glfwInit();
	kiwi::user_window_context.window_ptr = glfwCreateWindow(1, 1, "", nullptr, nullptr);
}