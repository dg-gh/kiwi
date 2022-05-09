#ifndef KIWI_MOUSE_HPP
#define KIWI_MOUSE_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	void mouse_init();
	void mouse_init(GLFWwindow* window_ptr, bool rescale_screen_coordinates);

	namespace mouse
	{
		float X() noexcept;
		float Y() noexcept;

		bool button_1() noexcept;
		bool button_2() noexcept;
		bool button_3() noexcept;
		bool button_4() noexcept;
		bool button_5() noexcept;
		bool button_6() noexcept;
		bool button_7() noexcept;
		bool button_8() noexcept;

		bool button_1_press() noexcept;
		bool button_2_press() noexcept;
		bool button_3_press() noexcept;
		bool button_4_press() noexcept;
		bool button_5_press() noexcept;
		bool button_6_press() noexcept;
		bool button_7_press() noexcept;
		bool button_8_press() noexcept;

		bool button_1_release() noexcept;
		bool button_2_release() noexcept;
		bool button_3_release() noexcept;
		bool button_4_release() noexcept;
		bool button_5_release() noexcept;
		bool button_6_release() noexcept;
		bool button_7_release() noexcept;
		bool button_8_release() noexcept;

		bool in_box(float X_min, float Y_min, float X_max, float Y_max) noexcept;
		bool in_tri(float X0, float Y0, float X1, float Y1, float X2, float Y2) noexcept;
		bool in_tri(const float* const tri_ptr) noexcept;
		bool in_circle(float X_orig, float Y_orig, float radius) noexcept;
		
		void clear_events() noexcept;
	}
}

#endif // KIWI_MOUSE_HPP