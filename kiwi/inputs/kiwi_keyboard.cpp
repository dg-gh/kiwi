#include "inputs/kiwi_keyboard.hpp"
#include <bitset>

namespace kiwi
{
	static GLFWwindow* keyboard_context_window_ptr;
	static std::bitset<768> user_keyboard_key_input;
}

namespace kiwi
{
	namespace keyboard
	{
		void callback(GLFWwindow*, int key, int, int action, int) noexcept
		{
			action = (action > 1) ? 1 : action;
			kiwi::user_keyboard_key_input[static_cast<std::size_t>(key + action * 384)] = true; 
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


bool kiwi::keyboard::space_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_SPACE + 384]; }
bool kiwi::keyboard::apostrophe_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_APOSTROPHE + 384]; }
bool kiwi::keyboard::comma_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_COMMA + 384]; }
bool kiwi::keyboard::minus_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_MINUS + 384]; }
bool kiwi::keyboard::period_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_PERIOD + 384]; }
bool kiwi::keyboard::slash_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_SLASH + 384]; }

bool kiwi::keyboard::A_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_A + 384]; }
bool kiwi::keyboard::B_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_B + 384]; }
bool kiwi::keyboard::C_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_C + 384]; }
bool kiwi::keyboard::D_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_D + 384]; }
bool kiwi::keyboard::E_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_E + 384]; }
bool kiwi::keyboard::F_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F + 384]; }
bool kiwi::keyboard::G_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_G + 384]; }
bool kiwi::keyboard::H_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_H + 384]; }
bool kiwi::keyboard::I_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_I + 384]; }
bool kiwi::keyboard::J_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_J + 384]; }
bool kiwi::keyboard::K_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_K + 384]; }
bool kiwi::keyboard::L_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_L + 384]; }
bool kiwi::keyboard::M_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_M + 384]; }
bool kiwi::keyboard::N_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_N + 384]; }
bool kiwi::keyboard::O_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_O + 384]; }
bool kiwi::keyboard::P_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_P + 384]; }
bool kiwi::keyboard::Q_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_Q + 384]; }
bool kiwi::keyboard::R_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_R + 384]; }
bool kiwi::keyboard::S_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_S + 384]; }
bool kiwi::keyboard::T_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_T + 384]; }
bool kiwi::keyboard::U_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_U + 384]; }
bool kiwi::keyboard::V_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_V + 384]; }
bool kiwi::keyboard::W_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_W + 384]; }
bool kiwi::keyboard::X_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_X + 384]; }
bool kiwi::keyboard::Y_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_Y + 384]; }
bool kiwi::keyboard::Z_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_Z + 384]; }

bool kiwi::keyboard::key0_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_0 + 384]; }
bool kiwi::keyboard::key1_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_1 + 384]; }
bool kiwi::keyboard::key2_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_2 + 384]; }
bool kiwi::keyboard::key3_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_3 + 384]; }
bool kiwi::keyboard::key4_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_4 + 384]; }
bool kiwi::keyboard::key5_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_5 + 384]; }
bool kiwi::keyboard::key6_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_6 + 384]; }
bool kiwi::keyboard::key7_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_7 + 384]; }
bool kiwi::keyboard::key8_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_8 + 384]; }
bool kiwi::keyboard::key9_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_9 + 384]; }

bool kiwi::keyboard::pad0_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_0 + 384]; }
bool kiwi::keyboard::pad1_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_1 + 384]; }
bool kiwi::keyboard::pad2_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_2 + 384]; }
bool kiwi::keyboard::pad3_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_3 + 384]; }
bool kiwi::keyboard::pad4_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_4 + 384]; }
bool kiwi::keyboard::pad5_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_5 + 384]; }
bool kiwi::keyboard::pad6_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_6 + 384]; }
bool kiwi::keyboard::pad7_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_7 + 384]; }
bool kiwi::keyboard::pad8_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_8 + 384]; }
bool kiwi::keyboard::pad9_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_9 + 384]; }

bool kiwi::keyboard::add_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_ADD + 384]; }
bool kiwi::keyboard::sub_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_SUBTRACT + 384]; }
bool kiwi::keyboard::mul_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_MULTIPLY + 384]; }
bool kiwi::keyboard::div_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_DIVIDE + 384]; }

bool kiwi::keyboard::F1_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F1 + 384]; }
bool kiwi::keyboard::F2_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F2 + 384]; }
bool kiwi::keyboard::F3_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F3 + 384]; }
bool kiwi::keyboard::F4_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F4 + 384]; }
bool kiwi::keyboard::F5_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F5 + 384]; }
bool kiwi::keyboard::F6_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F6 + 384]; }
bool kiwi::keyboard::F7_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F7 + 384]; }
bool kiwi::keyboard::F8_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F8 + 384]; }
bool kiwi::keyboard::F9_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F9 + 384]; }
bool kiwi::keyboard::F10_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F10 + 384]; }
bool kiwi::keyboard::F11_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F11 + 384]; }
bool kiwi::keyboard::F12_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F12 + 384]; }

bool kiwi::keyboard::escape_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_ESCAPE + 384]; }
bool kiwi::keyboard::enter_press() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_ENTER + 384]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_KP_ENTER + 384];
}
bool kiwi::keyboard::tab_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_TAB + 384]; }
bool kiwi::keyboard::backspace_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_BACKSPACE + 384]; }
bool kiwi::keyboard::insert_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_INSERT + 384]; }
bool kiwi::keyboard::del_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_DELETE + 384]; }
bool kiwi::keyboard::right_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT + 384]; }
bool kiwi::keyboard::left_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT + 384]; }
bool kiwi::keyboard::down_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_DOWN + 384]; }
bool kiwi::keyboard::up_press() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_UP + 384]; }
bool kiwi::keyboard::alt_press() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT_ALT + 384]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT_ALT + 384];
}
bool kiwi::keyboard::shift_press() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT_SHIFT + 384]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT_SHIFT + 384];
}
bool kiwi::keyboard::ctrl_press() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT_CONTROL + 384]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT_CONTROL + 384];
}


bool kiwi::keyboard::space_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_SPACE]; }
bool kiwi::keyboard::apostrophe_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_APOSTROPHE]; }
bool kiwi::keyboard::comma_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_COMMA]; }
bool kiwi::keyboard::minus_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_MINUS]; }
bool kiwi::keyboard::period_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_PERIOD]; }
bool kiwi::keyboard::slash_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_SLASH]; }

bool kiwi::keyboard::A_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_A]; }
bool kiwi::keyboard::B_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_B]; }
bool kiwi::keyboard::C_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_C]; }
bool kiwi::keyboard::D_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_D]; }
bool kiwi::keyboard::E_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_E]; }
bool kiwi::keyboard::F_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F]; }
bool kiwi::keyboard::G_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_G]; }
bool kiwi::keyboard::H_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_H]; }
bool kiwi::keyboard::I_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_I]; }
bool kiwi::keyboard::J_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_J]; }
bool kiwi::keyboard::K_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_K]; }
bool kiwi::keyboard::L_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_L]; }
bool kiwi::keyboard::M_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_M]; }
bool kiwi::keyboard::N_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_N]; }
bool kiwi::keyboard::O_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_O]; }
bool kiwi::keyboard::P_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_P]; }
bool kiwi::keyboard::Q_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_Q]; }
bool kiwi::keyboard::R_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_R]; }
bool kiwi::keyboard::S_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_S]; }
bool kiwi::keyboard::T_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_T]; }
bool kiwi::keyboard::U_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_U]; }
bool kiwi::keyboard::V_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_V]; }
bool kiwi::keyboard::W_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_W]; }
bool kiwi::keyboard::X_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_X]; }
bool kiwi::keyboard::Y_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_Y]; }
bool kiwi::keyboard::Z_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_Z]; }

bool kiwi::keyboard::key0_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_0]; }
bool kiwi::keyboard::key1_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_1]; }
bool kiwi::keyboard::key2_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_2]; }
bool kiwi::keyboard::key3_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_3]; }
bool kiwi::keyboard::key4_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_4]; }
bool kiwi::keyboard::key5_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_5]; }
bool kiwi::keyboard::key6_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_6]; }
bool kiwi::keyboard::key7_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_7]; }
bool kiwi::keyboard::key8_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_8]; }
bool kiwi::keyboard::key9_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_9]; }

bool kiwi::keyboard::pad0_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_0]; }
bool kiwi::keyboard::pad1_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_1]; }
bool kiwi::keyboard::pad2_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_2]; }
bool kiwi::keyboard::pad3_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_3]; }
bool kiwi::keyboard::pad4_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_4]; }
bool kiwi::keyboard::pad5_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_5]; }
bool kiwi::keyboard::pad6_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_6]; }
bool kiwi::keyboard::pad7_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_7]; }
bool kiwi::keyboard::pad8_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_8]; }
bool kiwi::keyboard::pad9_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_9]; }

bool kiwi::keyboard::add_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_ADD]; }
bool kiwi::keyboard::sub_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_SUBTRACT]; }
bool kiwi::keyboard::mul_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_MULTIPLY]; }
bool kiwi::keyboard::div_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_KP_DIVIDE]; }

bool kiwi::keyboard::F1_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F1]; }
bool kiwi::keyboard::F2_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F2]; }
bool kiwi::keyboard::F3_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F3]; }
bool kiwi::keyboard::F4_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F4]; }
bool kiwi::keyboard::F5_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F5]; }
bool kiwi::keyboard::F6_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F6]; }
bool kiwi::keyboard::F7_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F7]; }
bool kiwi::keyboard::F8_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F8]; }
bool kiwi::keyboard::F9_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F9]; }
bool kiwi::keyboard::F10_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F10]; }
bool kiwi::keyboard::F11_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F11]; }
bool kiwi::keyboard::F12_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_F12]; }

bool kiwi::keyboard::escape_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_ESCAPE]; }
bool kiwi::keyboard::enter_release() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_ENTER]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_KP_ENTER];
}
bool kiwi::keyboard::tab_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_TAB]; }
bool kiwi::keyboard::backspace_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_BACKSPACE]; }
bool kiwi::keyboard::insert_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_INSERT]; }
bool kiwi::keyboard::del_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_DELETE]; }
bool kiwi::keyboard::right_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT]; }
bool kiwi::keyboard::left_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT]; }
bool kiwi::keyboard::down_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_DOWN]; }
bool kiwi::keyboard::up_release() noexcept { return kiwi::user_keyboard_key_input[GLFW_KEY_UP]; }
bool kiwi::keyboard::alt_release() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT_ALT]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT_ALT];
}
bool kiwi::keyboard::shift_release() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT_SHIFT]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT_SHIFT];
}
bool kiwi::keyboard::ctrl_release() noexcept {
	return kiwi::user_keyboard_key_input[GLFW_KEY_LEFT_CONTROL]
		|| kiwi::user_keyboard_key_input[GLFW_KEY_RIGHT_CONTROL];
}


void kiwi::keyboard::clear_events() noexcept
{
	std::memset(&kiwi::user_keyboard_key_input, 0, sizeof(kiwi::user_keyboard_key_input));
}