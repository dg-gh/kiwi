#include "inputs/kiwi_keyboard.hpp"
#include <atomic>

namespace kiwi
{
	namespace keyboard
	{
		class key_input
		{

		public:

			// event press

			std::atomic<bool> space_press{ false };
			std::atomic<bool> apostrophe_press{ false };
			std::atomic<bool> comma_press{ false };
			std::atomic<bool> minus_press{ false };
			std::atomic<bool> period_press{ false };
			std::atomic<bool> slash_press{ false };

			std::atomic<bool> A_press{ false };
			std::atomic<bool> B_press{ false };
			std::atomic<bool> C_press{ false };
			std::atomic<bool> D_press{ false };
			std::atomic<bool> E_press{ false };
			std::atomic<bool> F_press{ false };
			std::atomic<bool> G_press{ false };
			std::atomic<bool> H_press{ false };
			std::atomic<bool> I_press{ false };
			std::atomic<bool> J_press{ false };
			std::atomic<bool> K_press{ false };
			std::atomic<bool> L_press{ false };
			std::atomic<bool> M_press{ false };
			std::atomic<bool> N_press{ false };
			std::atomic<bool> O_press{ false };
			std::atomic<bool> P_press{ false };
			std::atomic<bool> Q_press{ false };
			std::atomic<bool> R_press{ false };
			std::atomic<bool> S_press{ false };
			std::atomic<bool> T_press{ false };
			std::atomic<bool> U_press{ false };
			std::atomic<bool> V_press{ false };
			std::atomic<bool> W_press{ false };
			std::atomic<bool> X_press{ false };
			std::atomic<bool> Y_press{ false };
			std::atomic<bool> Z_press{ false };

			std::atomic<bool> num0_press{ false };
			std::atomic<bool> num1_press{ false };
			std::atomic<bool> num2_press{ false };
			std::atomic<bool> num3_press{ false };
			std::atomic<bool> num4_press{ false };
			std::atomic<bool> num5_press{ false };
			std::atomic<bool> num6_press{ false };
			std::atomic<bool> num7_press{ false };
			std::atomic<bool> num8_press{ false };
			std::atomic<bool> num9_press{ false };

			std::atomic<bool> numpad0_press{ false };
			std::atomic<bool> numpad1_press{ false };
			std::atomic<bool> numpad2_press{ false };
			std::atomic<bool> numpad3_press{ false };
			std::atomic<bool> numpad4_press{ false };
			std::atomic<bool> numpad5_press{ false };
			std::atomic<bool> numpad6_press{ false };
			std::atomic<bool> numpad7_press{ false };
			std::atomic<bool> numpad8_press{ false };
			std::atomic<bool> numpad9_press{ false };

			std::atomic<bool> add_press{ false };
			std::atomic<bool> sub_press{ false };
			std::atomic<bool> mul_press{ false };
			std::atomic<bool> div_press{ false };

			std::atomic<bool> f1_press{ false };
			std::atomic<bool> f2_press{ false };
			std::atomic<bool> f3_press{ false };
			std::atomic<bool> f4_press{ false };
			std::atomic<bool> f5_press{ false };
			std::atomic<bool> f6_press{ false };
			std::atomic<bool> f7_press{ false };
			std::atomic<bool> f8_press{ false };
			std::atomic<bool> f9_press{ false };
			std::atomic<bool> f10_press{ false };
			std::atomic<bool> f11_press{ false };
			std::atomic<bool> f12_press{ false };

			std::atomic<bool> escape_press{ false };
			std::atomic<bool> enter_press{ false };
			std::atomic<bool> tab_press{ false };
			std::atomic<bool> backspace_press{ false };
			std::atomic<bool> insert_press{ false };
			std::atomic<bool> delete__press{ false };
			std::atomic<bool> right_press{ false };
			std::atomic<bool> left_press{ false };
			std::atomic<bool> down_press{ false };
			std::atomic<bool> up_press{ false };
			std::atomic<bool> alt_press{ false };
			std::atomic<bool> shift_press{ false };
			std::atomic<bool> ctrl_press{ false };

			// event release

			std::atomic<bool> space_release{ false };
			std::atomic<bool> apostrophe_release{ false };
			std::atomic<bool> comma_release{ false };
			std::atomic<bool> minus_release{ false };
			std::atomic<bool> period_release{ false };
			std::atomic<bool> slash_release{ false };

			std::atomic<bool> A_release{ false };
			std::atomic<bool> B_release{ false };
			std::atomic<bool> C_release{ false };
			std::atomic<bool> D_release{ false };
			std::atomic<bool> E_release{ false };
			std::atomic<bool> F_release{ false };
			std::atomic<bool> G_release{ false };
			std::atomic<bool> H_release{ false };
			std::atomic<bool> I_release{ false };
			std::atomic<bool> J_release{ false };
			std::atomic<bool> K_release{ false };
			std::atomic<bool> L_release{ false };
			std::atomic<bool> M_release{ false };
			std::atomic<bool> N_release{ false };
			std::atomic<bool> O_release{ false };
			std::atomic<bool> P_release{ false };
			std::atomic<bool> Q_release{ false };
			std::atomic<bool> R_release{ false };
			std::atomic<bool> S_release{ false };
			std::atomic<bool> T_release{ false };
			std::atomic<bool> U_release{ false };
			std::atomic<bool> V_release{ false };
			std::atomic<bool> W_release{ false };
			std::atomic<bool> X_release{ false };
			std::atomic<bool> Y_release{ false };
			std::atomic<bool> Z_release{ false };

			std::atomic<bool> num0_release{ false };
			std::atomic<bool> num1_release{ false };
			std::atomic<bool> num2_release{ false };
			std::atomic<bool> num3_release{ false };
			std::atomic<bool> num4_release{ false };
			std::atomic<bool> num5_release{ false };
			std::atomic<bool> num6_release{ false };
			std::atomic<bool> num7_release{ false };
			std::atomic<bool> num8_release{ false };
			std::atomic<bool> num9_release{ false };

			std::atomic<bool> numpad0_release{ false };
			std::atomic<bool> numpad1_release{ false };
			std::atomic<bool> numpad2_release{ false };
			std::atomic<bool> numpad3_release{ false };
			std::atomic<bool> numpad4_release{ false };
			std::atomic<bool> numpad5_release{ false };
			std::atomic<bool> numpad6_release{ false };
			std::atomic<bool> numpad7_release{ false };
			std::atomic<bool> numpad8_release{ false };
			std::atomic<bool> numpad9_release{ false };

			std::atomic<bool> add_release{ false };
			std::atomic<bool> sub_release{ false };
			std::atomic<bool> mul_release{ false };
			std::atomic<bool> div_release{ false };

			std::atomic<bool> f1_release{ false };
			std::atomic<bool> f2_release{ false };
			std::atomic<bool> f3_release{ false };
			std::atomic<bool> f4_release{ false };
			std::atomic<bool> f5_release{ false };
			std::atomic<bool> f6_release{ false };
			std::atomic<bool> f7_release{ false };
			std::atomic<bool> f8_release{ false };
			std::atomic<bool> f9_release{ false };
			std::atomic<bool> f10_release{ false };
			std::atomic<bool> f11_release{ false };
			std::atomic<bool> f12_release{ false };

			std::atomic<bool> escape_release{ false };
			std::atomic<bool> enter_release{ false };
			std::atomic<bool> tab_release{ false };
			std::atomic<bool> backspace_release{ false };
			std::atomic<bool> insert_release{ false };
			std::atomic<bool> delete__release{ false };
			std::atomic<bool> right_release{ false };
			std::atomic<bool> left_release{ false };
			std::atomic<bool> down_release{ false };
			std::atomic<bool> up_release{ false };
			std::atomic<bool> alt_release{ false };
			std::atomic<bool> shift_release{ false };
			std::atomic<bool> ctrl_release{ false };
		};
	}
}


namespace kiwi
{
	static GLFWwindow* keyboard_context_window_ptr;
	static kiwi::keyboard::key_input user_keyboard_key_input;
}

namespace kiwi
{
	namespace keyboard
	{
		void callback(GLFWwindow*, int key, int, int action, int) noexcept
		{
			switch (key)
			{

			case GLFW_KEY_SPACE:
				kiwi::user_keyboard_key_input.space_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.space_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_APOSTROPHE:
				kiwi::user_keyboard_key_input.apostrophe_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.apostrophe_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_COMMA:
				kiwi::user_keyboard_key_input.comma_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.comma_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_MINUS:
				kiwi::user_keyboard_key_input.minus_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.minus_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_PERIOD:
				kiwi::user_keyboard_key_input.period_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.period_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_SLASH:
				kiwi::user_keyboard_key_input.slash_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.slash_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_A:
				kiwi::user_keyboard_key_input.A_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.A_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_B:
				kiwi::user_keyboard_key_input.B_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.B_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_C:
				kiwi::user_keyboard_key_input.C_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.C_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_D:
				kiwi::user_keyboard_key_input.D_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.D_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_E:
				kiwi::user_keyboard_key_input.E_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.E_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F:
				kiwi::user_keyboard_key_input.F_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.F_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_G:
				kiwi::user_keyboard_key_input.G_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.G_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_H:
				kiwi::user_keyboard_key_input.H_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.H_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_I:
				kiwi::user_keyboard_key_input.I_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.I_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_J:
				kiwi::user_keyboard_key_input.J_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.J_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_K:
				kiwi::user_keyboard_key_input.K_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.K_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_L:
				kiwi::user_keyboard_key_input.L_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.L_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_M:
				kiwi::user_keyboard_key_input.M_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.M_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_N:
				kiwi::user_keyboard_key_input.N_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.N_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_O:
				kiwi::user_keyboard_key_input.O_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.O_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_P:
				kiwi::user_keyboard_key_input.P_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.P_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_Q:
				kiwi::user_keyboard_key_input.Q_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.Q_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_R:
				kiwi::user_keyboard_key_input.R_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.R_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_S:
				kiwi::user_keyboard_key_input.S_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.S_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_T:
				kiwi::user_keyboard_key_input.T_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.T_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_U:
				kiwi::user_keyboard_key_input.U_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.U_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_V:
				kiwi::user_keyboard_key_input.V_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.V_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_W:
				kiwi::user_keyboard_key_input.W_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.W_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_X:
				kiwi::user_keyboard_key_input.X_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.X_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_Y:
				kiwi::user_keyboard_key_input.Y_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.Y_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_Z:
				kiwi::user_keyboard_key_input.Z_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.Z_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_0:
				kiwi::user_keyboard_key_input.num0_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num0_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_1:
				kiwi::user_keyboard_key_input.num1_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num1_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_2:
				kiwi::user_keyboard_key_input.num2_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num2_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_3:
				kiwi::user_keyboard_key_input.num3_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num3_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_4:
				kiwi::user_keyboard_key_input.num4_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num4_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_5:
				kiwi::user_keyboard_key_input.num5_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num5_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_6:
				kiwi::user_keyboard_key_input.num6_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num6_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_7:
				kiwi::user_keyboard_key_input.num7_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num7_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_8:
				kiwi::user_keyboard_key_input.num8_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num8_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_9:
				kiwi::user_keyboard_key_input.num9_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.num9_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_0:
				kiwi::user_keyboard_key_input.numpad0_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad0_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_1:
				kiwi::user_keyboard_key_input.numpad1_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad1_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_2:
				kiwi::user_keyboard_key_input.numpad2_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad2_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_3:
				kiwi::user_keyboard_key_input.numpad3_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad3_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_4:
				kiwi::user_keyboard_key_input.numpad4_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad4_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_5:
				kiwi::user_keyboard_key_input.numpad5_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad5_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_6:
				kiwi::user_keyboard_key_input.numpad6_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad6_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_7:
				kiwi::user_keyboard_key_input.numpad7_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad7_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_8:
				kiwi::user_keyboard_key_input.numpad8_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad8_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_9:
				kiwi::user_keyboard_key_input.numpad9_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.numpad9_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_ADD:
				kiwi::user_keyboard_key_input.add_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.add_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_SUBTRACT:
				kiwi::user_keyboard_key_input.sub_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.sub_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_MULTIPLY:
				kiwi::user_keyboard_key_input.mul_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.mul_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_DIVIDE:
				kiwi::user_keyboard_key_input.div_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.div_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_KP_ENTER:
				kiwi::user_keyboard_key_input.enter_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.enter_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F1:
				kiwi::user_keyboard_key_input.f1_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f1_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F2:
				kiwi::user_keyboard_key_input.f2_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f2_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F3:
				kiwi::user_keyboard_key_input.f3_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f3_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F4:
				kiwi::user_keyboard_key_input.f4_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f4_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F5:
				kiwi::user_keyboard_key_input.f5_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f5_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F6:
				kiwi::user_keyboard_key_input.f6_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f6_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F7:
				kiwi::user_keyboard_key_input.f7_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f7_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F8:
				kiwi::user_keyboard_key_input.f8_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f8_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F9:
				kiwi::user_keyboard_key_input.f9_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f9_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F10:
				kiwi::user_keyboard_key_input.f10_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f10_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F11:
				kiwi::user_keyboard_key_input.f11_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f11_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_F12:
				kiwi::user_keyboard_key_input.f12_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.f12_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_ESCAPE:
				kiwi::user_keyboard_key_input.escape_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.escape_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_ENTER:
				kiwi::user_keyboard_key_input.enter_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.enter_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_TAB:
				kiwi::user_keyboard_key_input.tab_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.tab_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_BACKSPACE:
				kiwi::user_keyboard_key_input.backspace_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.backspace_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_INSERT:
				kiwi::user_keyboard_key_input.insert_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.insert_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_DELETE:
				kiwi::user_keyboard_key_input.delete__press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.delete__release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_RIGHT:
				kiwi::user_keyboard_key_input.right_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.right_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_LEFT:
				kiwi::user_keyboard_key_input.left_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.left_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_DOWN:
				kiwi::user_keyboard_key_input.down_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.down_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_UP:
				kiwi::user_keyboard_key_input.up_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.up_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_LEFT_ALT:
				kiwi::user_keyboard_key_input.alt_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.alt_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_RIGHT_ALT:
				kiwi::user_keyboard_key_input.alt_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.alt_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_LEFT_SHIFT:
				kiwi::user_keyboard_key_input.shift_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.shift_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_RIGHT_SHIFT:
				kiwi::user_keyboard_key_input.shift_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.shift_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_LEFT_CONTROL:
				kiwi::user_keyboard_key_input.ctrl_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.ctrl_release.store(action == GLFW_RELEASE);
				break;
			case GLFW_KEY_RIGHT_CONTROL:
				kiwi::user_keyboard_key_input.ctrl_press.store(action == GLFW_PRESS);
				kiwi::user_keyboard_key_input.ctrl_release.store(action == GLFW_RELEASE);
				break;

			default:
				break;
			}
		}
	}
}

void kiwi::keyboard_init()
{
	glfwSetInputMode(kiwi::context::window(), GLFW_STICKY_KEYS, GLFW_TRUE);
	glfwSetKeyCallback(kiwi::context::window(), &kiwi::keyboard::callback);
	keyboard_context_window_ptr = kiwi::context::window();
}

void kiwi::keyboard_init(GLFWwindow* window_ptr)
{
	glfwSetInputMode(window_ptr, GLFW_STICKY_KEYS, GLFW_TRUE);
	glfwSetKeyCallback(window_ptr, &kiwi::keyboard::callback);
	keyboard_context_window_ptr = window_ptr;
}

bool kiwi::keyboard::space() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_SPACE) == GLFW_PRESS; }
bool kiwi::keyboard::apostrophe() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_APOSTROPHE) == GLFW_PRESS; }
bool kiwi::keyboard::comma() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_COMMA) == GLFW_PRESS; }
bool kiwi::keyboard::minus() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_MINUS) == GLFW_PRESS; }
bool kiwi::keyboard::period() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_PERIOD) == GLFW_PRESS; }
bool kiwi::keyboard::slash() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_SLASH) == GLFW_PRESS; }

bool kiwi::keyboard::A() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_A) == GLFW_PRESS; }
bool kiwi::keyboard::B() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_B) == GLFW_PRESS; }
bool kiwi::keyboard::C() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_C) == GLFW_PRESS; }
bool kiwi::keyboard::D() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_D) == GLFW_PRESS; }
bool kiwi::keyboard::E() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_E) == GLFW_PRESS; }
bool kiwi::keyboard::F() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F) == GLFW_PRESS; }
bool kiwi::keyboard::G() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_G) == GLFW_PRESS; }
bool kiwi::keyboard::H() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_H) == GLFW_PRESS; }
bool kiwi::keyboard::I() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_I) == GLFW_PRESS; }
bool kiwi::keyboard::J() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_J) == GLFW_PRESS; }
bool kiwi::keyboard::K() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_K) == GLFW_PRESS; }
bool kiwi::keyboard::L() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_L) == GLFW_PRESS; }
bool kiwi::keyboard::M() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_M) == GLFW_PRESS; }
bool kiwi::keyboard::N() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_N) == GLFW_PRESS; }
bool kiwi::keyboard::O() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_O) == GLFW_PRESS; }
bool kiwi::keyboard::P() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_P) == GLFW_PRESS; }
bool kiwi::keyboard::Q() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_Q) == GLFW_PRESS; }
bool kiwi::keyboard::R() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_R) == GLFW_PRESS; }
bool kiwi::keyboard::S() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_S) == GLFW_PRESS; }
bool kiwi::keyboard::T() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_T) == GLFW_PRESS; }
bool kiwi::keyboard::U() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_U) == GLFW_PRESS; }
bool kiwi::keyboard::V() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_V) == GLFW_PRESS; }
bool kiwi::keyboard::W() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_W) == GLFW_PRESS; }
bool kiwi::keyboard::X() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_X) == GLFW_PRESS; }
bool kiwi::keyboard::Y() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_Y) == GLFW_PRESS; }
bool kiwi::keyboard::Z() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_Z) == GLFW_PRESS; }

bool kiwi::keyboard::key0() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_0) == GLFW_PRESS; }
bool kiwi::keyboard::key1() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_1) == GLFW_PRESS; }
bool kiwi::keyboard::key2() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_2) == GLFW_PRESS; }
bool kiwi::keyboard::key3() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_3) == GLFW_PRESS; }
bool kiwi::keyboard::key4() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_4) == GLFW_PRESS; }
bool kiwi::keyboard::key5() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_5) == GLFW_PRESS; }
bool kiwi::keyboard::key6() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_6) == GLFW_PRESS; }
bool kiwi::keyboard::key7() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_7) == GLFW_PRESS; }
bool kiwi::keyboard::key8() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_8) == GLFW_PRESS; }
bool kiwi::keyboard::key9() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_9) == GLFW_PRESS; }

bool kiwi::keyboard::pad0() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_0) == GLFW_PRESS; }
bool kiwi::keyboard::pad1() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_1) == GLFW_PRESS; }
bool kiwi::keyboard::pad2() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_2) == GLFW_PRESS; }
bool kiwi::keyboard::pad3() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_3) == GLFW_PRESS; }
bool kiwi::keyboard::pad4() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_4) == GLFW_PRESS; }
bool kiwi::keyboard::pad5() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_5) == GLFW_PRESS; }
bool kiwi::keyboard::pad6() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_6) == GLFW_PRESS; }
bool kiwi::keyboard::pad7() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_7) == GLFW_PRESS; }
bool kiwi::keyboard::pad8() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_8) == GLFW_PRESS; }
bool kiwi::keyboard::pad9() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_9) == GLFW_PRESS; }

bool kiwi::keyboard::add() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_ADD) == GLFW_PRESS; }
bool kiwi::keyboard::sub() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS; }
bool kiwi::keyboard::mul() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_MULTIPLY) == GLFW_PRESS; }
bool kiwi::keyboard::div() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_DIVIDE) == GLFW_PRESS; }

bool kiwi::keyboard::F1() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F1) == GLFW_PRESS; }
bool kiwi::keyboard::F2() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F2) == GLFW_PRESS; }
bool kiwi::keyboard::F3() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F3) == GLFW_PRESS; }
bool kiwi::keyboard::F4() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F4) == GLFW_PRESS; }
bool kiwi::keyboard::F5() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F5) == GLFW_PRESS; }
bool kiwi::keyboard::F6() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F6) == GLFW_PRESS; }
bool kiwi::keyboard::F7() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F7) == GLFW_PRESS; }
bool kiwi::keyboard::F8() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F8) == GLFW_PRESS; }
bool kiwi::keyboard::F9() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F9) == GLFW_PRESS; }
bool kiwi::keyboard::F10() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F10) == GLFW_PRESS; }
bool kiwi::keyboard::F11() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F11) == GLFW_PRESS; }
bool kiwi::keyboard::F12() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_F12) == GLFW_PRESS; }

bool kiwi::keyboard::escape() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_ESCAPE) == GLFW_PRESS; }
bool kiwi::keyboard::enter() noexcept {
	return (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_ENTER) == GLFW_PRESS)
		|| (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_KP_ENTER) == GLFW_PRESS);
}
bool kiwi::keyboard::tab() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_TAB) == GLFW_PRESS; }
bool kiwi::keyboard::backspace() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_BACKSPACE) == GLFW_PRESS; }
bool kiwi::keyboard::insert() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_INSERT) == GLFW_PRESS; }
bool kiwi::keyboard::del() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_DELETE) == GLFW_PRESS; }
bool kiwi::keyboard::right() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_RIGHT) == GLFW_PRESS; }
bool kiwi::keyboard::left() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_LEFT) == GLFW_PRESS; }
bool kiwi::keyboard::down() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_DOWN) == GLFW_PRESS; }
bool kiwi::keyboard::up() noexcept { return glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_UP) == GLFW_PRESS; }
bool kiwi::keyboard::alt() noexcept {
	return (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
		|| (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS);
}
bool kiwi::keyboard::shift() noexcept {
	return (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		|| (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS);
}
bool kiwi::keyboard::ctrl() noexcept {
	return (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		|| (glfwGetKey(kiwi::keyboard_context_window_ptr, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
}
bool kiwi::keyboard::space_press() noexcept { return kiwi::user_keyboard_key_input.space_press.load(); }
bool kiwi::keyboard::apostrophe_press() noexcept { return kiwi::user_keyboard_key_input.apostrophe_press.load(); }
bool kiwi::keyboard::comma_press() noexcept { return kiwi::user_keyboard_key_input.comma_press.load(); }
bool kiwi::keyboard::minus_press() noexcept { return kiwi::user_keyboard_key_input.minus_press.load(); }
bool kiwi::keyboard::period_press() noexcept { return kiwi::user_keyboard_key_input.period_press.load(); }
bool kiwi::keyboard::slash_press() noexcept { return kiwi::user_keyboard_key_input.slash_press.load(); }

bool kiwi::keyboard::A_press() noexcept { return kiwi::user_keyboard_key_input.A_press.load(); }
bool kiwi::keyboard::B_press() noexcept { return kiwi::user_keyboard_key_input.B_press.load(); }
bool kiwi::keyboard::C_press() noexcept { return kiwi::user_keyboard_key_input.C_press.load(); }
bool kiwi::keyboard::D_press() noexcept { return kiwi::user_keyboard_key_input.D_press.load(); }
bool kiwi::keyboard::E_press() noexcept { return kiwi::user_keyboard_key_input.E_press.load(); }
bool kiwi::keyboard::F_press() noexcept { return kiwi::user_keyboard_key_input.F_press.load(); }
bool kiwi::keyboard::G_press() noexcept { return kiwi::user_keyboard_key_input.G_press.load(); }
bool kiwi::keyboard::H_press() noexcept { return kiwi::user_keyboard_key_input.H_press.load(); }
bool kiwi::keyboard::I_press() noexcept { return kiwi::user_keyboard_key_input.I_press.load(); }
bool kiwi::keyboard::J_press() noexcept { return kiwi::user_keyboard_key_input.J_press.load(); }
bool kiwi::keyboard::K_press() noexcept { return kiwi::user_keyboard_key_input.K_press.load(); }
bool kiwi::keyboard::L_press() noexcept { return kiwi::user_keyboard_key_input.L_press.load(); }
bool kiwi::keyboard::M_press() noexcept { return kiwi::user_keyboard_key_input.M_press.load(); }
bool kiwi::keyboard::N_press() noexcept { return kiwi::user_keyboard_key_input.N_press.load(); }
bool kiwi::keyboard::O_press() noexcept { return kiwi::user_keyboard_key_input.O_press.load(); }
bool kiwi::keyboard::P_press() noexcept { return kiwi::user_keyboard_key_input.P_press.load(); }
bool kiwi::keyboard::Q_press() noexcept { return kiwi::user_keyboard_key_input.Q_press.load(); }
bool kiwi::keyboard::R_press() noexcept { return kiwi::user_keyboard_key_input.R_press.load(); }
bool kiwi::keyboard::S_press() noexcept { return kiwi::user_keyboard_key_input.S_press.load(); }
bool kiwi::keyboard::T_press() noexcept { return kiwi::user_keyboard_key_input.T_press.load(); }
bool kiwi::keyboard::U_press() noexcept { return kiwi::user_keyboard_key_input.U_press.load(); }
bool kiwi::keyboard::V_press() noexcept { return kiwi::user_keyboard_key_input.V_press.load(); }
bool kiwi::keyboard::W_press() noexcept { return kiwi::user_keyboard_key_input.W_press.load(); }
bool kiwi::keyboard::X_press() noexcept { return kiwi::user_keyboard_key_input.X_press.load(); }
bool kiwi::keyboard::Y_press() noexcept { return kiwi::user_keyboard_key_input.Y_press.load(); }
bool kiwi::keyboard::Z_press() noexcept { return kiwi::user_keyboard_key_input.Z_press.load(); }

bool kiwi::keyboard::key0_press() noexcept { return kiwi::user_keyboard_key_input.num0_press.load(); }
bool kiwi::keyboard::key1_press() noexcept { return kiwi::user_keyboard_key_input.num1_press.load(); }
bool kiwi::keyboard::key2_press() noexcept { return kiwi::user_keyboard_key_input.num2_press.load(); }
bool kiwi::keyboard::key3_press() noexcept { return kiwi::user_keyboard_key_input.num3_press.load(); }
bool kiwi::keyboard::key4_press() noexcept { return kiwi::user_keyboard_key_input.num4_press.load(); }
bool kiwi::keyboard::key5_press() noexcept { return kiwi::user_keyboard_key_input.num5_press.load(); }
bool kiwi::keyboard::key6_press() noexcept { return kiwi::user_keyboard_key_input.num6_press.load(); }
bool kiwi::keyboard::key7_press() noexcept { return kiwi::user_keyboard_key_input.num7_press.load(); }
bool kiwi::keyboard::key8_press() noexcept { return kiwi::user_keyboard_key_input.num8_press.load(); }
bool kiwi::keyboard::key9_press() noexcept { return kiwi::user_keyboard_key_input.num9_press.load(); }

bool kiwi::keyboard::pad0_press() noexcept { return kiwi::user_keyboard_key_input.numpad0_press.load(); }
bool kiwi::keyboard::pad1_press() noexcept { return kiwi::user_keyboard_key_input.numpad1_press.load(); }
bool kiwi::keyboard::pad2_press() noexcept { return kiwi::user_keyboard_key_input.numpad2_press.load(); }
bool kiwi::keyboard::pad3_press() noexcept { return kiwi::user_keyboard_key_input.numpad3_press.load(); }
bool kiwi::keyboard::pad4_press() noexcept { return kiwi::user_keyboard_key_input.numpad4_press.load(); }
bool kiwi::keyboard::pad5_press() noexcept { return kiwi::user_keyboard_key_input.numpad5_press.load(); }
bool kiwi::keyboard::pad6_press() noexcept { return kiwi::user_keyboard_key_input.numpad6_press.load(); }
bool kiwi::keyboard::pad7_press() noexcept { return kiwi::user_keyboard_key_input.numpad7_press.load(); }
bool kiwi::keyboard::pad8_press() noexcept { return kiwi::user_keyboard_key_input.numpad8_press.load(); }
bool kiwi::keyboard::pad9_press() noexcept { return kiwi::user_keyboard_key_input.numpad9_press.load(); }

bool kiwi::keyboard::add_press() noexcept { return kiwi::user_keyboard_key_input.add_press.load(); }
bool kiwi::keyboard::sub_press() noexcept { return kiwi::user_keyboard_key_input.sub_press.load(); }
bool kiwi::keyboard::mul_press() noexcept { return kiwi::user_keyboard_key_input.mul_press.load(); }
bool kiwi::keyboard::div_press() noexcept { return kiwi::user_keyboard_key_input.div_press.load(); }

bool kiwi::keyboard::F1_press() noexcept { return kiwi::user_keyboard_key_input.f1_press.load(); }
bool kiwi::keyboard::F2_press() noexcept { return kiwi::user_keyboard_key_input.f2_press.load(); }
bool kiwi::keyboard::F3_press() noexcept { return kiwi::user_keyboard_key_input.f3_press.load(); }
bool kiwi::keyboard::F4_press() noexcept { return kiwi::user_keyboard_key_input.f4_press.load(); }
bool kiwi::keyboard::F5_press() noexcept { return kiwi::user_keyboard_key_input.f5_press.load(); }
bool kiwi::keyboard::F6_press() noexcept { return kiwi::user_keyboard_key_input.f6_press.load(); }
bool kiwi::keyboard::F7_press() noexcept { return kiwi::user_keyboard_key_input.f7_press.load(); }
bool kiwi::keyboard::F8_press() noexcept { return kiwi::user_keyboard_key_input.f8_press.load(); }
bool kiwi::keyboard::F9_press() noexcept { return kiwi::user_keyboard_key_input.f9_press.load(); }
bool kiwi::keyboard::F10_press() noexcept { return kiwi::user_keyboard_key_input.f10_press.load(); }
bool kiwi::keyboard::F11_press() noexcept { return kiwi::user_keyboard_key_input.f11_press.load(); }
bool kiwi::keyboard::F12_press() noexcept { return kiwi::user_keyboard_key_input.f12_press.load(); }

bool kiwi::keyboard::escape_press() noexcept { return kiwi::user_keyboard_key_input.escape_press.load(); }
bool kiwi::keyboard::enter_press() noexcept { return kiwi::user_keyboard_key_input.enter_press.load(); }
bool kiwi::keyboard::tab_press() noexcept { return kiwi::user_keyboard_key_input.tab_press.load(); }
bool kiwi::keyboard::backspace_press() noexcept { return kiwi::user_keyboard_key_input.backspace_press.load(); }
bool kiwi::keyboard::insert_press() noexcept { return kiwi::user_keyboard_key_input.insert_press.load(); }
bool kiwi::keyboard::del_press() noexcept { return kiwi::user_keyboard_key_input.delete__press.load(); }
bool kiwi::keyboard::right_press() noexcept { return kiwi::user_keyboard_key_input.right_press.load(); }
bool kiwi::keyboard::left_press() noexcept { return kiwi::user_keyboard_key_input.left_press.load(); }
bool kiwi::keyboard::down_press() noexcept { return kiwi::user_keyboard_key_input.down_press.load(); }
bool kiwi::keyboard::up_press() noexcept { return kiwi::user_keyboard_key_input.up_press.load(); }
bool kiwi::keyboard::alt_press() noexcept { return kiwi::user_keyboard_key_input.alt_press.load(); }
bool kiwi::keyboard::shift_press() noexcept { return kiwi::user_keyboard_key_input.shift_press.load(); }
bool kiwi::keyboard::ctrl_press() noexcept { return kiwi::user_keyboard_key_input.ctrl_press.load(); }

bool kiwi::keyboard::space_release() noexcept { return kiwi::user_keyboard_key_input.space_release.load(); }
bool kiwi::keyboard::apostrophe_release() noexcept { return kiwi::user_keyboard_key_input.apostrophe_release.load(); }
bool kiwi::keyboard::comma_release() noexcept { return kiwi::user_keyboard_key_input.comma_release.load(); }
bool kiwi::keyboard::minus_release() noexcept { return kiwi::user_keyboard_key_input.minus_release.load(); }
bool kiwi::keyboard::period_release() noexcept { return kiwi::user_keyboard_key_input.period_release.load(); }
bool kiwi::keyboard::slash_release() noexcept { return kiwi::user_keyboard_key_input.slash_release.load(); }

bool kiwi::keyboard::A_release() noexcept { return kiwi::user_keyboard_key_input.A_release.load(); }
bool kiwi::keyboard::B_release() noexcept { return kiwi::user_keyboard_key_input.B_release.load(); }
bool kiwi::keyboard::C_release() noexcept { return kiwi::user_keyboard_key_input.C_release.load(); }
bool kiwi::keyboard::D_release() noexcept { return kiwi::user_keyboard_key_input.D_release.load(); }
bool kiwi::keyboard::E_release() noexcept { return kiwi::user_keyboard_key_input.E_release.load(); }
bool kiwi::keyboard::F_release() noexcept { return kiwi::user_keyboard_key_input.F_release.load(); }
bool kiwi::keyboard::G_release() noexcept { return kiwi::user_keyboard_key_input.G_release.load(); }
bool kiwi::keyboard::H_release() noexcept { return kiwi::user_keyboard_key_input.H_release.load(); }
bool kiwi::keyboard::I_release() noexcept { return kiwi::user_keyboard_key_input.I_release.load(); }
bool kiwi::keyboard::J_release() noexcept { return kiwi::user_keyboard_key_input.J_release.load(); }
bool kiwi::keyboard::K_release() noexcept { return kiwi::user_keyboard_key_input.K_release.load(); }
bool kiwi::keyboard::L_release() noexcept { return kiwi::user_keyboard_key_input.L_release.load(); }
bool kiwi::keyboard::M_release() noexcept { return kiwi::user_keyboard_key_input.M_release.load(); }
bool kiwi::keyboard::N_release() noexcept { return kiwi::user_keyboard_key_input.N_release.load(); }
bool kiwi::keyboard::O_release() noexcept { return kiwi::user_keyboard_key_input.O_release.load(); }
bool kiwi::keyboard::P_release() noexcept { return kiwi::user_keyboard_key_input.P_release.load(); }
bool kiwi::keyboard::Q_release() noexcept { return kiwi::user_keyboard_key_input.Q_release.load(); }
bool kiwi::keyboard::R_release() noexcept { return kiwi::user_keyboard_key_input.R_release.load(); }
bool kiwi::keyboard::S_release() noexcept { return kiwi::user_keyboard_key_input.S_release.load(); }
bool kiwi::keyboard::T_release() noexcept { return kiwi::user_keyboard_key_input.T_release.load(); }
bool kiwi::keyboard::U_release() noexcept { return kiwi::user_keyboard_key_input.U_release.load(); }
bool kiwi::keyboard::V_release() noexcept { return kiwi::user_keyboard_key_input.V_release.load(); }
bool kiwi::keyboard::W_release() noexcept { return kiwi::user_keyboard_key_input.W_release.load(); }
bool kiwi::keyboard::X_release() noexcept { return kiwi::user_keyboard_key_input.X_release.load(); }
bool kiwi::keyboard::Y_release() noexcept { return kiwi::user_keyboard_key_input.Y_release.load(); }
bool kiwi::keyboard::Z_release() noexcept { return kiwi::user_keyboard_key_input.Z_release.load(); }

bool kiwi::keyboard::key0_release() noexcept { return kiwi::user_keyboard_key_input.num0_release.load(); }
bool kiwi::keyboard::key1_release() noexcept { return kiwi::user_keyboard_key_input.num1_release.load(); }
bool kiwi::keyboard::key2_release() noexcept { return kiwi::user_keyboard_key_input.num2_release.load(); }
bool kiwi::keyboard::key3_release() noexcept { return kiwi::user_keyboard_key_input.num3_release.load(); }
bool kiwi::keyboard::key4_release() noexcept { return kiwi::user_keyboard_key_input.num4_release.load(); }
bool kiwi::keyboard::key5_release() noexcept { return kiwi::user_keyboard_key_input.num5_release.load(); }
bool kiwi::keyboard::key6_release() noexcept { return kiwi::user_keyboard_key_input.num6_release.load(); }
bool kiwi::keyboard::key7_release() noexcept { return kiwi::user_keyboard_key_input.num7_release.load(); }
bool kiwi::keyboard::key8_release() noexcept { return kiwi::user_keyboard_key_input.num8_release.load(); }
bool kiwi::keyboard::key9_release() noexcept { return kiwi::user_keyboard_key_input.num9_release.load(); }

bool kiwi::keyboard::pad0_release() noexcept { return kiwi::user_keyboard_key_input.numpad0_release.load(); }
bool kiwi::keyboard::pad1_release() noexcept { return kiwi::user_keyboard_key_input.numpad1_release.load(); }
bool kiwi::keyboard::pad2_release() noexcept { return kiwi::user_keyboard_key_input.numpad2_release.load(); }
bool kiwi::keyboard::pad3_release() noexcept { return kiwi::user_keyboard_key_input.numpad3_release.load(); }
bool kiwi::keyboard::pad4_release() noexcept { return kiwi::user_keyboard_key_input.numpad4_release.load(); }
bool kiwi::keyboard::pad5_release() noexcept { return kiwi::user_keyboard_key_input.numpad5_release.load(); }
bool kiwi::keyboard::pad6_release() noexcept { return kiwi::user_keyboard_key_input.numpad6_release.load(); }
bool kiwi::keyboard::pad7_release() noexcept { return kiwi::user_keyboard_key_input.numpad7_release.load(); }
bool kiwi::keyboard::pad8_release() noexcept { return kiwi::user_keyboard_key_input.numpad8_release.load(); }
bool kiwi::keyboard::pad9_release() noexcept { return kiwi::user_keyboard_key_input.numpad9_release.load(); }

bool kiwi::keyboard::add_release() noexcept { return kiwi::user_keyboard_key_input.add_release.load(); }
bool kiwi::keyboard::sub_release() noexcept { return kiwi::user_keyboard_key_input.sub_release.load(); }
bool kiwi::keyboard::mul_release() noexcept { return kiwi::user_keyboard_key_input.mul_release.load(); }
bool kiwi::keyboard::div_release() noexcept { return kiwi::user_keyboard_key_input.div_release.load(); }

bool kiwi::keyboard::F1_release() noexcept { return kiwi::user_keyboard_key_input.f1_release.load(); }
bool kiwi::keyboard::F2_release() noexcept { return kiwi::user_keyboard_key_input.f2_release.load(); }
bool kiwi::keyboard::F3_release() noexcept { return kiwi::user_keyboard_key_input.f3_release.load(); }
bool kiwi::keyboard::F4_release() noexcept { return kiwi::user_keyboard_key_input.f4_release.load(); }
bool kiwi::keyboard::F5_release() noexcept { return kiwi::user_keyboard_key_input.f5_release.load(); }
bool kiwi::keyboard::F6_release() noexcept { return kiwi::user_keyboard_key_input.f6_release.load(); }
bool kiwi::keyboard::F7_release() noexcept { return kiwi::user_keyboard_key_input.f7_release.load(); }
bool kiwi::keyboard::F8_release() noexcept { return kiwi::user_keyboard_key_input.f8_release.load(); }
bool kiwi::keyboard::F9_release() noexcept { return kiwi::user_keyboard_key_input.f9_release.load(); }
bool kiwi::keyboard::F10_release() noexcept { return kiwi::user_keyboard_key_input.f10_release.load(); }
bool kiwi::keyboard::F11_release() noexcept { return kiwi::user_keyboard_key_input.f11_release.load(); }
bool kiwi::keyboard::F12_release() noexcept { return kiwi::user_keyboard_key_input.f12_release.load(); }

bool kiwi::keyboard::escape_release() noexcept { return kiwi::user_keyboard_key_input.escape_release.load(); }
bool kiwi::keyboard::enter_release() noexcept { return kiwi::user_keyboard_key_input.enter_release.load(); }
bool kiwi::keyboard::tab_release() noexcept { return kiwi::user_keyboard_key_input.tab_release.load(); }
bool kiwi::keyboard::backspace_release() noexcept { return kiwi::user_keyboard_key_input.backspace_release.load(); }
bool kiwi::keyboard::insert_release() noexcept { return kiwi::user_keyboard_key_input.insert_release.load(); }
bool kiwi::keyboard::del_release() noexcept { return kiwi::user_keyboard_key_input.delete__release.load(); }
bool kiwi::keyboard::right_release() noexcept { return kiwi::user_keyboard_key_input.right_release.load(); }
bool kiwi::keyboard::left_release() noexcept { return kiwi::user_keyboard_key_input.left_release.load(); }
bool kiwi::keyboard::down_release() noexcept { return kiwi::user_keyboard_key_input.down_release.load(); }
bool kiwi::keyboard::up_release() noexcept { return kiwi::user_keyboard_key_input.up_release.load(); }
bool kiwi::keyboard::alt_release() noexcept { return kiwi::user_keyboard_key_input.alt_release.load(); }
bool kiwi::keyboard::shift_release() noexcept { return kiwi::user_keyboard_key_input.shift_release.load(); }
bool kiwi::keyboard::ctrl_release() noexcept { return kiwi::user_keyboard_key_input.ctrl_release.load(); }

void kiwi::keyboard::clear_events() noexcept
{
	std::memset(&user_keyboard_key_input, 0, sizeof(kiwi::keyboard::key_input));
}