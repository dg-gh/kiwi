#include "inputs/kiwi_mouse.hpp"
#include <bitset>


namespace kiwi
{
	namespace mouse
	{
		class position_input
		{

		public:

			double X_shift = 0.0;
			double Y_shift = 0.0;
			double X_scale = 1.0;
			double Y_scale = 1.0;

			float mouse_X{ 0.0f };
			float mouse_Y{ 0.0f };

			GLFWwindow* m_window_ptr = nullptr;
		};
	}
}

namespace kiwi
{
	static GLFWwindow* mouse_context_window_ptr;
	static kiwi::mouse::position_input user_mouse_position_input;
	static std::bitset<16> user_mouse_button_input;
}

float kiwi::mouse::X() noexcept { return user_mouse_position_input.mouse_X; }
float kiwi::mouse::Y() noexcept { return user_mouse_position_input.mouse_Y; }

bool kiwi::mouse::button1() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS; }
bool kiwi::mouse::button2() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS; }
bool kiwi::mouse::button3() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS; }
bool kiwi::mouse::button4() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS; }
bool kiwi::mouse::button5() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_5) == GLFW_PRESS; }
bool kiwi::mouse::button6() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_6) == GLFW_PRESS; }
bool kiwi::mouse::button7() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_7) == GLFW_PRESS; }
bool kiwi::mouse::button8() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_8) == GLFW_PRESS; }

bool kiwi::mouse::button1_press() noexcept { return kiwi::user_mouse_button_input[8]; }
bool kiwi::mouse::button2_press() noexcept { return kiwi::user_mouse_button_input[9]; }
bool kiwi::mouse::button3_press() noexcept { return kiwi::user_mouse_button_input[10]; }
bool kiwi::mouse::button4_press() noexcept { return kiwi::user_mouse_button_input[11]; }
bool kiwi::mouse::button5_press() noexcept { return kiwi::user_mouse_button_input[12]; }
bool kiwi::mouse::button6_press() noexcept { return kiwi::user_mouse_button_input[13]; }
bool kiwi::mouse::button7_press() noexcept { return kiwi::user_mouse_button_input[14]; }
bool kiwi::mouse::button8_press() noexcept { return kiwi::user_mouse_button_input[15]; }

bool kiwi::mouse::button1_release() noexcept { return kiwi::user_mouse_button_input[0]; }
bool kiwi::mouse::button2_release() noexcept { return kiwi::user_mouse_button_input[1]; }
bool kiwi::mouse::button3_release() noexcept { return kiwi::user_mouse_button_input[2]; }
bool kiwi::mouse::button4_release() noexcept { return kiwi::user_mouse_button_input[3]; }
bool kiwi::mouse::button5_release() noexcept { return kiwi::user_mouse_button_input[4]; }
bool kiwi::mouse::button6_release() noexcept { return kiwi::user_mouse_button_input[5]; }
bool kiwi::mouse::button7_release() noexcept { return kiwi::user_mouse_button_input[6]; }
bool kiwi::mouse::button8_release() noexcept { return kiwi::user_mouse_button_input[7]; }

bool kiwi::mouse::in_box(const kiwi::XY& XY_min, const kiwi::XY& XY_max) noexcept
{
	return (((XY_min.X() < kiwi::user_mouse_position_input.mouse_X) && (kiwi::user_mouse_position_input.mouse_X < XY_max.X()))
		&& ((XY_min.Y() < kiwi::user_mouse_position_input.mouse_Y) && (kiwi::user_mouse_position_input.mouse_Y < XY_max.Y())));
}

bool kiwi::mouse::in_box(float X_min, float Y_min, float X_max, float Y_max) noexcept
{
	return (((X_min < kiwi::user_mouse_position_input.mouse_X) && (kiwi::user_mouse_position_input.mouse_X < X_max))
		&& ((Y_min < kiwi::user_mouse_position_input.mouse_Y) && (kiwi::user_mouse_position_input.mouse_Y < Y_max)));
}

bool kiwi::mouse::in_triangle(const kiwi::XY& XY0, const kiwi::XY& XY1, const kiwi::XY& XY2) noexcept
{
	float s = XY0.Y() * XY2.X() - XY0.X() * XY2.Y() + (XY2.Y() - XY0.Y()) * kiwi::user_mouse_position_input.mouse_X
		+ (XY0.X() - XY2.X()) * kiwi::user_mouse_position_input.mouse_Y;
	float t = XY0.X() * XY1.Y() - XY0.Y() * XY1.X() + (XY0.Y() - XY1.Y()) * kiwi::user_mouse_position_input.mouse_X
		+ (XY1.X() - XY0.X()) * kiwi::user_mouse_position_input.mouse_Y;

	if ((s < 0) != (t < 0)) { return false; }
	else
	{
		float A = XY0.Y() * (XY2.X() - XY1.X()) + XY0.X() * (XY1.Y() - XY2.Y()) + XY1.X() * XY2.Y() - XY1.Y() * XY2.X();
		return A < 0 ? (s < 0 && s + t > A) : (s > 0 && s + t < A);
	}
}

bool kiwi::mouse::in_triangle(float X0, float Y0, float X1, float Y1, float X2, float Y2) noexcept
{
	float s = Y0 * X2 - X0 * Y2 + (Y2 - Y0) * kiwi::user_mouse_position_input.mouse_X
		+ (X0 - X2) * kiwi::user_mouse_position_input.mouse_Y;
	float t = X0 * Y1 - Y0 * X1 + (Y0 - Y1) * kiwi::user_mouse_position_input.mouse_X
		+ (X1 - X0) * kiwi::user_mouse_position_input.mouse_Y;

	if ((s < 0) != (t < 0)) { return false; }
	else
	{
		float A = Y0 * (X2 - X1) + X0 * (Y1 - Y2) + X1 * Y2 - Y1 * X2;
		return A < 0 ? (s < 0 && s + t > A) : (s > 0 && s + t < A);
	}
}

bool kiwi::mouse::in_triangle(const float* const triangle_ptr) noexcept
{
	float s = *(triangle_ptr + 1) * *(triangle_ptr + 4) - *triangle_ptr * *(triangle_ptr + 5)
		+ (*(triangle_ptr + 5) - *(triangle_ptr + 1)) * kiwi::user_mouse_position_input.mouse_X
		+ (*triangle_ptr - *(triangle_ptr + 4)) * kiwi::user_mouse_position_input.mouse_Y;
	float t = *triangle_ptr * *(triangle_ptr + 3) - *(triangle_ptr + 1) * *(triangle_ptr + 2)
		+ (*(triangle_ptr + 1) - *(triangle_ptr + 3)) * kiwi::user_mouse_position_input.mouse_X
		+ (*(triangle_ptr + 2) - *triangle_ptr) * kiwi::user_mouse_position_input.mouse_Y;

	if ((s < 0) != (t < 0))
	{
		return false;
	}
	else
	{
		float A = *(triangle_ptr + 1) * (*(triangle_ptr + 4) - *(triangle_ptr + 2)) + *triangle_ptr * (*(triangle_ptr + 3)
			- *(triangle_ptr + 5)) + *(triangle_ptr + 2) * *(triangle_ptr + 5) - *(triangle_ptr + 3) * *(triangle_ptr + 4);
		return A < 0 ? (s < 0 && s + t > A) : (s > 0 && s + t < A);
	}
}

bool kiwi::mouse::in_circle(const kiwi::XY& XY_orig, float radius) noexcept
{
	float dx = kiwi::user_mouse_position_input.mouse_X - XY_orig.X();
	float dy = kiwi::user_mouse_position_input.mouse_Y - XY_orig.Y();
	return (dx * dx + dy * dy < radius * radius);
}

bool kiwi::mouse::in_circle(float X_orig, float Y_orig, float radius) noexcept
{
	float dx = kiwi::user_mouse_position_input.mouse_X - X_orig;
	float dy = kiwi::user_mouse_position_input.mouse_Y - Y_orig;
	return (dx * dx + dy * dy < radius * radius);
}

namespace kiwi
{
	namespace mouse
	{
		void button_callback(GLFWwindow*, int button, int action, int) noexcept
		{
			action = (action > 1) ? 1 : action;
			std::size_t offset = static_cast<std::size_t>(button - GLFW_MOUSE_BUTTON_1 + 8 * action);

			kiwi::user_mouse_button_input[offset] = true;
		}

		void position_callback(GLFWwindow*, double input_mouse_X, double input_mouse_Y) noexcept
		{
			kiwi::user_mouse_position_input.mouse_X
				= static_cast<float>(kiwi::user_mouse_position_input.X_scale
				* (input_mouse_X - kiwi::user_mouse_position_input.X_shift));
			kiwi::user_mouse_position_input.mouse_Y
				= static_cast<float>(kiwi::user_mouse_position_input.Y_scale
				* (kiwi::user_mouse_position_input.Y_shift - input_mouse_Y));
		}
	}
}

void kiwi::mouse::clear_events() noexcept
{
	std::memset(&kiwi::user_mouse_button_input, 0, sizeof(kiwi::user_mouse_button_input));
}

void kiwi::mouse_init()
{
	glfwSetInputMode(kiwi::context::window(), GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	glfwSetMouseButtonCallback(kiwi::context::window(), &kiwi::mouse::button_callback);
	glfwSetCursorPosCallback(kiwi::context::window(), &kiwi::mouse::position_callback);
	mouse_context_window_ptr = kiwi::context::window();

	int screen_width;
	int screen_height;
	glfwGetWindowSize(kiwi::context::window(), &screen_width, &screen_height);

	if (screen_width >= screen_height)
	{
		kiwi::user_mouse_position_input.X_shift = 0.5 * static_cast<double>(screen_width);
		kiwi::user_mouse_position_input.Y_shift = 0.5 * static_cast<double>(screen_height);
		kiwi::user_mouse_position_input.X_scale = 1.0 / kiwi::user_mouse_position_input.Y_shift;
		kiwi::user_mouse_position_input.Y_scale = 1.0 / kiwi::user_mouse_position_input.Y_shift;
	}
	else
	{
		kiwi::user_mouse_position_input.X_shift = 0.5 * static_cast<double>(screen_width);
		kiwi::user_mouse_position_input.Y_shift = 0.5 * static_cast<double>(screen_height);
		kiwi::user_mouse_position_input.X_scale = 1.0 / kiwi::user_mouse_position_input.X_shift;
		kiwi::user_mouse_position_input.Y_scale = 1.0 / kiwi::user_mouse_position_input.X_shift;
	}
}

void kiwi::mouse_init(GLFWwindow* window_ptr, bool rescale_screen_coordinates)
{
	glfwSetInputMode(window_ptr, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	glfwSetMouseButtonCallback(window_ptr, &kiwi::mouse::button_callback);
	glfwSetCursorPosCallback(window_ptr, &kiwi::mouse::position_callback);
	mouse_context_window_ptr = window_ptr;

	int screen_width;
	int screen_height;
	glfwGetWindowSize(kiwi::context::window(), &screen_width, &screen_height);

	if (rescale_screen_coordinates)
	{
		if (screen_width >= screen_height)
		{
			kiwi::user_mouse_position_input.X_shift = 0.5 * static_cast<double>(screen_width);
			kiwi::user_mouse_position_input.Y_shift = 0.5 * static_cast<double>(screen_height);
			kiwi::user_mouse_position_input.X_scale = 1.0 / kiwi::user_mouse_position_input.Y_shift;
			kiwi::user_mouse_position_input.Y_scale = 1.0 / kiwi::user_mouse_position_input.Y_shift;
		}
		else
		{
			kiwi::user_mouse_position_input.X_shift = 0.5 * static_cast<double>(screen_width);
			kiwi::user_mouse_position_input.Y_shift = 0.5 * static_cast<double>(screen_height);
			kiwi::user_mouse_position_input.X_scale = 1.0 / kiwi::user_mouse_position_input.X_shift;
			kiwi::user_mouse_position_input.Y_scale = 1.0 / kiwi::user_mouse_position_input.X_shift;
		}
	}
	else
	{
		kiwi::user_mouse_position_input.X_shift = 0.5 * static_cast<double>(screen_width);
		kiwi::user_mouse_position_input.Y_shift = 0.5 * static_cast<double>(screen_height);
		kiwi::user_mouse_position_input.X_scale = 1.0 / kiwi::user_mouse_position_input.X_shift;
		kiwi::user_mouse_position_input.Y_scale = 1.0 / kiwi::user_mouse_position_input.Y_shift;
	}
}