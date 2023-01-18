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

		bool button1() noexcept;
		bool button2() noexcept;
		bool button3() noexcept;
		bool button4() noexcept;
		bool button5() noexcept;
		bool button6() noexcept;
		bool button7() noexcept;
		bool button8() noexcept;

		bool button1(kiwi::key_down_t) noexcept;
		bool button2(kiwi::key_down_t) noexcept;
		bool button3(kiwi::key_down_t) noexcept;
		bool button4(kiwi::key_down_t) noexcept;
		bool button5(kiwi::key_down_t) noexcept;
		bool button6(kiwi::key_down_t) noexcept;
		bool button7(kiwi::key_down_t) noexcept;
		bool button8(kiwi::key_down_t) noexcept;

		bool button1(kiwi::key_up_t) noexcept;
		bool button2(kiwi::key_up_t) noexcept;
		bool button3(kiwi::key_up_t) noexcept;
		bool button4(kiwi::key_up_t) noexcept;
		bool button5(kiwi::key_up_t) noexcept;
		bool button6(kiwi::key_up_t) noexcept;
		bool button7(kiwi::key_up_t) noexcept;
		bool button8(kiwi::key_up_t) noexcept;

		bool in_box(float X_min, float Y_min, float X_max, float Y_max) noexcept;
		bool in_tri(float X0, float Y0, float X1, float Y1, float X2, float Y2) noexcept;
		bool in_tri(const float* const tri_ptr) noexcept;
		bool in_circle(float X_orig, float Y_orig, float radius) noexcept;
		
		void clear_events() noexcept;
	}
}

#endif // KIWI_MOUSE_HPP