#ifndef _KIWI_MOUSE_HPP
#define _KIWI_MOUSE_HPP

#include "context/kiwi_context.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	void mouse_init();
	void mouse_init(GLFWwindow* window_ptr, bool rescale_screen_coordinates);

	namespace mouse
	{
		float X() noexcept;
		float Y() noexcept;

		bool button1() noexcept;
		bool button2() noexcept;
		bool button3() noexcept;
		bool button4() noexcept;
		bool button5() noexcept;
		bool button6() noexcept;
		bool button7() noexcept;
		bool button8() noexcept;

		bool button1_press() noexcept;
		bool button2_press() noexcept;
		bool button3_press() noexcept;
		bool button4_press() noexcept;
		bool button5_press() noexcept;
		bool button6_press() noexcept;
		bool button7_press() noexcept;
		bool button8_press() noexcept;

		bool button1_release() noexcept;
		bool button2_release() noexcept;
		bool button3_release() noexcept;
		bool button4_release() noexcept;
		bool button5_release() noexcept;
		bool button6_release() noexcept;
		bool button7_release() noexcept;
		bool button8_release() noexcept;

		bool in_box(const kiwi::XY& XY_min, const kiwi::XY& XY_max) noexcept;
		bool in_box(float X_min, float Y_min, float X_max, float Y_max) noexcept;

		bool in_triangle(const kiwi::XY& XY0, const kiwi::XY& XY1, const kiwi::XY& XY2) noexcept;
		bool in_triangle(float X0, float Y0, float X1, float Y1, float X2, float Y2) noexcept;
		bool in_triangle(const float* const triangle_ptr) noexcept;

		bool in_circle(const kiwi::XY& XY_orig, float radius) noexcept;
		bool in_circle(float X_orig, float Y_orig, float radius) noexcept;
		
		void clear_events() noexcept;
	}
}

#endif // _KIWI_MOUSE_HPP