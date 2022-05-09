#include "inputs/kiwi_mouse.hpp"


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

			std::atomic<float> mouse_X{ 0.0f };
			std::atomic<float> mouse_Y{ 0.0f };

			GLFWwindow* m_window_ptr = nullptr;
		};

		class button_input
		{

		public:

			std::atomic<bool> mouse_1_press{ false };
			std::atomic<bool> mouse_2_press{ false };
			std::atomic<bool> mouse_3_press{ false };
			std::atomic<bool> mouse_4_press{ false };
			std::atomic<bool> mouse_5_press{ false };
			std::atomic<bool> mouse_6_press{ false };
			std::atomic<bool> mouse_7_press{ false };
			std::atomic<bool> mouse_8_press{ false };

			std::atomic<bool> mouse_1_release{ false };
			std::atomic<bool> mouse_2_release{ false };
			std::atomic<bool> mouse_3_release{ false };
			std::atomic<bool> mouse_4_release{ false };
			std::atomic<bool> mouse_5_release{ false };
			std::atomic<bool> mouse_6_release{ false };
			std::atomic<bool> mouse_7_release{ false };
			std::atomic<bool> mouse_8_release{ false };
		};
	}
}

namespace kiwi
{
	static GLFWwindow* mouse_context_window_ptr;
	static kiwi::mouse::position_input user_mouse_position_input;
	static kiwi::mouse::button_input user_mouse_button_input;
}

float kiwi::mouse::X() noexcept { return user_mouse_position_input.mouse_X; }
float kiwi::mouse::Y() noexcept { return user_mouse_position_input.mouse_Y; }

bool kiwi::mouse::button_1() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS; }
bool kiwi::mouse::button_2() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS; }
bool kiwi::mouse::button_3() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS; }
bool kiwi::mouse::button_4() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS; }
bool kiwi::mouse::button_5() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_5) == GLFW_PRESS; }
bool kiwi::mouse::button_6() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_6) == GLFW_PRESS; }
bool kiwi::mouse::button_7() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_7) == GLFW_PRESS; }
bool kiwi::mouse::button_8() noexcept { return glfwGetMouseButton(kiwi::mouse_context_window_ptr, GLFW_MOUSE_BUTTON_8) == GLFW_PRESS; }

bool kiwi::mouse::button_1_press() noexcept { return kiwi::user_mouse_button_input.mouse_1_press.load(); }
bool kiwi::mouse::button_2_press() noexcept { return kiwi::user_mouse_button_input.mouse_2_press.load(); }
bool kiwi::mouse::button_3_press() noexcept { return kiwi::user_mouse_button_input.mouse_3_press.load(); }
bool kiwi::mouse::button_4_press() noexcept { return kiwi::user_mouse_button_input.mouse_4_press.load(); }
bool kiwi::mouse::button_5_press() noexcept { return kiwi::user_mouse_button_input.mouse_5_press.load(); }
bool kiwi::mouse::button_6_press() noexcept { return kiwi::user_mouse_button_input.mouse_6_press.load(); }
bool kiwi::mouse::button_7_press() noexcept { return kiwi::user_mouse_button_input.mouse_7_press.load(); }
bool kiwi::mouse::button_8_press() noexcept { return kiwi::user_mouse_button_input.mouse_8_press.load(); }

bool kiwi::mouse::button_1_release() noexcept { return kiwi::user_mouse_button_input.mouse_1_release.load(); }
bool kiwi::mouse::button_2_release() noexcept { return kiwi::user_mouse_button_input.mouse_2_release.load(); }
bool kiwi::mouse::button_3_release() noexcept { return kiwi::user_mouse_button_input.mouse_3_release.load(); }
bool kiwi::mouse::button_4_release() noexcept { return kiwi::user_mouse_button_input.mouse_4_release.load(); }
bool kiwi::mouse::button_5_release() noexcept { return kiwi::user_mouse_button_input.mouse_5_release.load(); }
bool kiwi::mouse::button_6_release() noexcept { return kiwi::user_mouse_button_input.mouse_6_release.load(); }
bool kiwi::mouse::button_7_release() noexcept { return kiwi::user_mouse_button_input.mouse_7_release.load(); }
bool kiwi::mouse::button_8_release() noexcept { return kiwi::user_mouse_button_input.mouse_8_release.load(); }

bool kiwi::mouse::in_box(float X_min, float Y_min, float X_max, float Y_max) noexcept
{
	return (((X_min < kiwi::user_mouse_position_input.mouse_X) && (kiwi::user_mouse_position_input.mouse_X < X_max))
		&& ((Y_min < kiwi::user_mouse_position_input.mouse_Y) && (kiwi::user_mouse_position_input.mouse_Y < Y_max)));
}

bool kiwi::mouse::in_tri(float X0, float Y0, float X1, float Y1, float X2, float Y2) noexcept
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

bool kiwi::mouse::in_tri(const float* const tri_ptr) noexcept
{
	float s = *(tri_ptr + 1) * *(tri_ptr + 4) - *tri_ptr * *(tri_ptr + 5)
		+ (*(tri_ptr + 5) - *(tri_ptr + 1)) * kiwi::user_mouse_position_input.mouse_X
		+ (*tri_ptr - *(tri_ptr + 4)) * kiwi::user_mouse_position_input.mouse_Y;
	float t = *tri_ptr * *(tri_ptr + 3) - *(tri_ptr + 1) * *(tri_ptr + 2)
		+ (*(tri_ptr + 1) - *(tri_ptr + 3)) * kiwi::user_mouse_position_input.mouse_X
		+ (*(tri_ptr + 2) - *tri_ptr) * kiwi::user_mouse_position_input.mouse_Y;

	if ((s < 0) != (t < 0))
	{
		return false;
	}
	else
	{
		float A = *(tri_ptr + 1) * (*(tri_ptr + 4) - *(tri_ptr + 2)) + *tri_ptr * (*(tri_ptr + 3)
			- *(tri_ptr + 5)) + *(tri_ptr + 2) * *(tri_ptr + 5) - *(tri_ptr + 3) * *(tri_ptr + 4);
		return A < 0 ? (s < 0 && s + t > A) : (s > 0 && s + t < A);
	}
}

bool kiwi::mouse::in_circle(float X_orig, float Y_orig, float radius) noexcept
{
	float dx = kiwi::user_mouse_position_input.mouse_X - X_orig;
	float dy = kiwi::user_mouse_position_input.mouse_Y - Y_orig;
	return (dx * dx + dy * dy < radius* radius);
}

namespace kiwi
{
	namespace mouse
	{
		void button_callback(GLFWwindow*, int button, int action, int) noexcept
		{
			switch (button)
			{

			case GLFW_MOUSE_BUTTON_1:
				kiwi::user_mouse_button_input.mouse_1_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_1_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_2:
				kiwi::user_mouse_button_input.mouse_2_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_2_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_3:
				kiwi::user_mouse_button_input.mouse_3_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_3_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_4:
				kiwi::user_mouse_button_input.mouse_4_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_4_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_5:
				kiwi::user_mouse_button_input.mouse_5_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_5_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_6:
				kiwi::user_mouse_button_input.mouse_6_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_6_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_7:
				kiwi::user_mouse_button_input.mouse_7_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_7_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_MOUSE_BUTTON_8:
				kiwi::user_mouse_button_input.mouse_8_press.store(action == GLFW_PRESS);
				kiwi::user_mouse_button_input.mouse_8_release.store(action == GLFW_RELEASE);
				break;

			default:
				break;
			}
		}

		void position_callback(GLFWwindow*, double input_mouse_X, double input_mouse_Y) noexcept
		{
			kiwi::user_mouse_position_input.mouse_X.store(
				static_cast<float>(kiwi::user_mouse_position_input.X_scale * (input_mouse_X - kiwi::user_mouse_position_input.X_shift)));
			kiwi::user_mouse_position_input.mouse_Y.store(
				static_cast<float>(kiwi::user_mouse_position_input.Y_scale * (kiwi::user_mouse_position_input.Y_shift - input_mouse_Y)));
		}
	}
}

void kiwi::mouse::clear_events() noexcept
{
	std::memset(&user_mouse_button_input, 0, sizeof(kiwi::mouse::button_input));
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