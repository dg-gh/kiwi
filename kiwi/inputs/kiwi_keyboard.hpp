#ifndef _KIWI_KEYBOARD_HPP
#define _KIWI_KEYBOARD_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	void keyboard_init();
	void keyboard_init(GLFWwindow* window_ptr);

	namespace keyboard
	{
		void clear_events() noexcept;

		bool space() noexcept;
		bool apostrophe() noexcept;
		bool comma() noexcept;
		bool minus() noexcept;
		bool period() noexcept;
		bool slash() noexcept;

		bool A() noexcept;
		bool B() noexcept;
		bool C() noexcept;
		bool D() noexcept;
		bool E() noexcept;
		bool F() noexcept;
		bool G() noexcept;
		bool H() noexcept;
		bool I() noexcept;
		bool J() noexcept;
		bool K() noexcept;
		bool L() noexcept;
		bool M() noexcept;
		bool N() noexcept;
		bool O() noexcept;
		bool P() noexcept;
		bool Q() noexcept;
		bool R() noexcept;
		bool S() noexcept;
		bool T() noexcept;
		bool U() noexcept;
		bool V() noexcept;
		bool W() noexcept;
		bool X() noexcept;
		bool Y() noexcept;
		bool Z() noexcept;

		bool key0() noexcept;
		bool key1() noexcept;
		bool key2() noexcept;
		bool key3() noexcept;
		bool key4() noexcept;
		bool key5() noexcept;
		bool key6() noexcept;
		bool key7() noexcept;
		bool key8() noexcept;
		bool key9() noexcept;

		bool pad0() noexcept;
		bool pad1() noexcept;
		bool pad2() noexcept;
		bool pad3() noexcept;
		bool pad4() noexcept;
		bool pad5() noexcept;
		bool pad6() noexcept;
		bool pad7() noexcept;
		bool pad8() noexcept;
		bool pad9() noexcept;

		bool add() noexcept;
		bool sub() noexcept;
		bool mul() noexcept;
		bool div() noexcept;

		bool F1() noexcept;
		bool F2() noexcept;
		bool F3() noexcept;
		bool F4() noexcept;
		bool F5() noexcept;
		bool F6() noexcept;
		bool F7() noexcept;
		bool F8() noexcept;
		bool F9() noexcept;
		bool F10() noexcept;
		bool F11() noexcept;
		bool F12() noexcept;

		bool escape() noexcept;
		bool enter() noexcept;
		bool tab() noexcept;
		bool backspace() noexcept;
		bool insert() noexcept;
		bool del() noexcept;
		bool right() noexcept;
		bool left() noexcept;
		bool down() noexcept;
		bool up() noexcept;
		bool alt() noexcept;
		bool shift() noexcept;
		bool ctrl() noexcept;

		bool space_press() noexcept;
		bool apostrophe_press() noexcept;
		bool comma_press() noexcept;
		bool minus_press() noexcept;
		bool period_press() noexcept;
		bool slash_press() noexcept;

		bool A_press() noexcept;
		bool B_press() noexcept;
		bool C_press() noexcept;
		bool D_press() noexcept;
		bool E_press() noexcept;
		bool F_press() noexcept;
		bool G_press() noexcept;
		bool H_press() noexcept;
		bool I_press() noexcept;
		bool J_press() noexcept;
		bool K_press() noexcept;
		bool L_press() noexcept;
		bool M_press() noexcept;
		bool N_press() noexcept;
		bool O_press() noexcept;
		bool P_press() noexcept;
		bool Q_press() noexcept;
		bool R_press() noexcept;
		bool S_press() noexcept;
		bool T_press() noexcept;
		bool U_press() noexcept;
		bool V_press() noexcept;
		bool W_press() noexcept;
		bool X_press() noexcept;
		bool Y_press() noexcept;
		bool Z_press() noexcept;

		bool key0_press() noexcept;
		bool key1_press() noexcept;
		bool key2_press() noexcept;
		bool key3_press() noexcept;
		bool key4_press() noexcept;
		bool key5_press() noexcept;
		bool key6_press() noexcept;
		bool key7_press() noexcept;
		bool key8_press() noexcept;
		bool key9_press() noexcept;

		bool pad0_press() noexcept;
		bool pad1_press() noexcept;
		bool pad2_press() noexcept;
		bool pad3_press() noexcept;
		bool pad4_press() noexcept;
		bool pad5_press() noexcept;
		bool pad6_press() noexcept;
		bool pad7_press() noexcept;
		bool pad8_press() noexcept;
		bool pad9_press() noexcept;

		bool add_press() noexcept;
		bool sub_press() noexcept;
		bool mul_press() noexcept;
		bool div_press() noexcept;

		bool F1_press() noexcept;
		bool F2_press() noexcept;
		bool F3_press() noexcept;
		bool F4_press() noexcept;
		bool F5_press() noexcept;
		bool F6_press() noexcept;
		bool F7_press() noexcept;
		bool F8_press() noexcept;
		bool F9_press() noexcept;
		bool F10_press() noexcept;
		bool F11_press() noexcept;
		bool F12_press() noexcept;

		bool escape_press() noexcept;
		bool enter_press() noexcept;
		bool tab_press() noexcept;
		bool backspace_press() noexcept;
		bool insert_press() noexcept;
		bool del_press() noexcept;
		bool right_press() noexcept;
		bool left_press() noexcept;
		bool down_press() noexcept;
		bool up_press() noexcept;
		bool alt_press() noexcept;
		bool shift_press() noexcept;
		bool ctrl_press() noexcept;

		bool space_release() noexcept;
		bool apostrophe_release() noexcept;
		bool comma_release() noexcept;
		bool minus_release() noexcept;
		bool period_release() noexcept;
		bool slash_release() noexcept;

		bool A_release() noexcept;
		bool B_release() noexcept;
		bool C_release() noexcept;
		bool D_release() noexcept;
		bool E_release() noexcept;
		bool F_release() noexcept;
		bool G_release() noexcept;
		bool H_release() noexcept;
		bool I_release() noexcept;
		bool J_release() noexcept;
		bool K_release() noexcept;
		bool L_release() noexcept;
		bool M_release() noexcept;
		bool N_release() noexcept;
		bool O_release() noexcept;
		bool P_release() noexcept;
		bool Q_release() noexcept;
		bool R_release() noexcept;
		bool S_release() noexcept;
		bool T_release() noexcept;
		bool U_release() noexcept;
		bool V_release() noexcept;
		bool W_release() noexcept;
		bool X_release() noexcept;
		bool Y_release() noexcept;
		bool Z_release() noexcept;

		bool key0_release() noexcept;
		bool key1_release() noexcept;
		bool key2_release() noexcept;
		bool key3_release() noexcept;
		bool key4_release() noexcept;
		bool key5_release() noexcept;
		bool key6_release() noexcept;
		bool key7_release() noexcept;
		bool key8_release() noexcept;
		bool key9_release() noexcept;

		bool pad0_release() noexcept;
		bool pad1_release() noexcept;
		bool pad2_release() noexcept;
		bool pad3_release() noexcept;
		bool pad4_release() noexcept;
		bool pad5_release() noexcept;
		bool pad6_release() noexcept;
		bool pad7_release() noexcept;
		bool pad8_release() noexcept;
		bool pad9_release() noexcept;

		bool add_release() noexcept;
		bool sub_release() noexcept;
		bool mul_release() noexcept;
		bool div_release() noexcept;

		bool F1_release() noexcept;
		bool F2_release() noexcept;
		bool F3_release() noexcept;
		bool F4_release() noexcept;
		bool F5_release() noexcept;
		bool F6_release() noexcept;
		bool F7_release() noexcept;
		bool F8_release() noexcept;
		bool F9_release() noexcept;
		bool F10_release() noexcept;
		bool F11_release() noexcept;
		bool F12_release() noexcept;

		bool escape_release() noexcept;
		bool enter_release() noexcept;
		bool tab_release() noexcept;
		bool backspace_release() noexcept;
		bool insert_release() noexcept;
		bool del_release() noexcept;
		bool right_release() noexcept;
		bool left_release() noexcept;
		bool down_release() noexcept;
		bool up_release() noexcept;
		bool alt_release() noexcept;
		bool shift_release() noexcept;
		bool ctrl_release() noexcept;
	}
}

#endif // _KIWI_KEYBOARD_HPP