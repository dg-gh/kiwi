#ifndef KIWI_KEYBOARD_HPP
#define KIWI_KEYBOARD_HPP

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

		bool space(kiwi::key_down_t) noexcept;
		bool apostrophe(kiwi::key_down_t) noexcept;
		bool comma(kiwi::key_down_t) noexcept;
		bool minus(kiwi::key_down_t) noexcept;
		bool period(kiwi::key_down_t) noexcept;
		bool slash(kiwi::key_down_t) noexcept;

		bool A(kiwi::key_down_t) noexcept;
		bool B(kiwi::key_down_t) noexcept;
		bool C(kiwi::key_down_t) noexcept;
		bool D(kiwi::key_down_t) noexcept;
		bool E(kiwi::key_down_t) noexcept;
		bool F(kiwi::key_down_t) noexcept;
		bool G(kiwi::key_down_t) noexcept;
		bool H(kiwi::key_down_t) noexcept;
		bool I(kiwi::key_down_t) noexcept;
		bool J(kiwi::key_down_t) noexcept;
		bool K(kiwi::key_down_t) noexcept;
		bool L(kiwi::key_down_t) noexcept;
		bool M(kiwi::key_down_t) noexcept;
		bool N(kiwi::key_down_t) noexcept;
		bool O(kiwi::key_down_t) noexcept;
		bool P(kiwi::key_down_t) noexcept;
		bool Q(kiwi::key_down_t) noexcept;
		bool R(kiwi::key_down_t) noexcept;
		bool S(kiwi::key_down_t) noexcept;
		bool T(kiwi::key_down_t) noexcept;
		bool U(kiwi::key_down_t) noexcept;
		bool V(kiwi::key_down_t) noexcept;
		bool W(kiwi::key_down_t) noexcept;
		bool X(kiwi::key_down_t) noexcept;
		bool Y(kiwi::key_down_t) noexcept;
		bool Z(kiwi::key_down_t) noexcept;

		bool key0(kiwi::key_down_t) noexcept;
		bool key1(kiwi::key_down_t) noexcept;
		bool key2(kiwi::key_down_t) noexcept;
		bool key3(kiwi::key_down_t) noexcept;
		bool key4(kiwi::key_down_t) noexcept;
		bool key5(kiwi::key_down_t) noexcept;
		bool key6(kiwi::key_down_t) noexcept;
		bool key7(kiwi::key_down_t) noexcept;
		bool key8(kiwi::key_down_t) noexcept;
		bool key9(kiwi::key_down_t) noexcept;

		bool pad0(kiwi::key_down_t) noexcept;
		bool pad1(kiwi::key_down_t) noexcept;
		bool pad2(kiwi::key_down_t) noexcept;
		bool pad3(kiwi::key_down_t) noexcept;
		bool pad4(kiwi::key_down_t) noexcept;
		bool pad5(kiwi::key_down_t) noexcept;
		bool pad6(kiwi::key_down_t) noexcept;
		bool pad7(kiwi::key_down_t) noexcept;
		bool pad8(kiwi::key_down_t) noexcept;
		bool pad9(kiwi::key_down_t) noexcept;

		bool add(kiwi::key_down_t) noexcept;
		bool sub(kiwi::key_down_t) noexcept;
		bool mul(kiwi::key_down_t) noexcept;
		bool div(kiwi::key_down_t) noexcept;

		bool F1(kiwi::key_down_t) noexcept;
		bool F2(kiwi::key_down_t) noexcept;
		bool F3(kiwi::key_down_t) noexcept;
		bool F4(kiwi::key_down_t) noexcept;
		bool F5(kiwi::key_down_t) noexcept;
		bool F6(kiwi::key_down_t) noexcept;
		bool F7(kiwi::key_down_t) noexcept;
		bool F8(kiwi::key_down_t) noexcept;
		bool F9(kiwi::key_down_t) noexcept;
		bool F10(kiwi::key_down_t) noexcept;
		bool F11(kiwi::key_down_t) noexcept;
		bool F12(kiwi::key_down_t) noexcept;

		bool escape(kiwi::key_down_t) noexcept;
		bool enter(kiwi::key_down_t) noexcept;
		bool tab(kiwi::key_down_t) noexcept;
		bool backspace(kiwi::key_down_t) noexcept;
		bool insert(kiwi::key_down_t) noexcept;
		bool del(kiwi::key_down_t) noexcept;
		bool right(kiwi::key_down_t) noexcept;
		bool left(kiwi::key_down_t) noexcept;
		bool down(kiwi::key_down_t) noexcept;
		bool up(kiwi::key_down_t) noexcept;
		bool alt(kiwi::key_down_t) noexcept;
		bool shift(kiwi::key_down_t) noexcept;
		bool ctrl(kiwi::key_down_t) noexcept;

		bool space(kiwi::key_up_t) noexcept;
		bool apostrophe(kiwi::key_up_t) noexcept;
		bool comma(kiwi::key_up_t) noexcept;
		bool minus(kiwi::key_up_t) noexcept;
		bool period(kiwi::key_up_t) noexcept;
		bool slash(kiwi::key_up_t) noexcept;

		bool A(kiwi::key_up_t) noexcept;
		bool B(kiwi::key_up_t) noexcept;
		bool C(kiwi::key_up_t) noexcept;
		bool D(kiwi::key_up_t) noexcept;
		bool E(kiwi::key_up_t) noexcept;
		bool F(kiwi::key_up_t) noexcept;
		bool G(kiwi::key_up_t) noexcept;
		bool H(kiwi::key_up_t) noexcept;
		bool I(kiwi::key_up_t) noexcept;
		bool J(kiwi::key_up_t) noexcept;
		bool K(kiwi::key_up_t) noexcept;
		bool L(kiwi::key_up_t) noexcept;
		bool M(kiwi::key_up_t) noexcept;
		bool N(kiwi::key_up_t) noexcept;
		bool O(kiwi::key_up_t) noexcept;
		bool P(kiwi::key_up_t) noexcept;
		bool Q(kiwi::key_up_t) noexcept;
		bool R(kiwi::key_up_t) noexcept;
		bool S(kiwi::key_up_t) noexcept;
		bool T(kiwi::key_up_t) noexcept;
		bool U(kiwi::key_up_t) noexcept;
		bool V(kiwi::key_up_t) noexcept;
		bool W(kiwi::key_up_t) noexcept;
		bool X(kiwi::key_up_t) noexcept;
		bool Y(kiwi::key_up_t) noexcept;
		bool Z(kiwi::key_up_t) noexcept;

		bool key0(kiwi::key_up_t) noexcept;
		bool key1(kiwi::key_up_t) noexcept;
		bool key2(kiwi::key_up_t) noexcept;
		bool key3(kiwi::key_up_t) noexcept;
		bool key4(kiwi::key_up_t) noexcept;
		bool key5(kiwi::key_up_t) noexcept;
		bool key6(kiwi::key_up_t) noexcept;
		bool key7(kiwi::key_up_t) noexcept;
		bool key8(kiwi::key_up_t) noexcept;
		bool key9(kiwi::key_up_t) noexcept;

		bool pad0(kiwi::key_up_t) noexcept;
		bool pad1(kiwi::key_up_t) noexcept;
		bool pad2(kiwi::key_up_t) noexcept;
		bool pad3(kiwi::key_up_t) noexcept;
		bool pad4(kiwi::key_up_t) noexcept;
		bool pad5(kiwi::key_up_t) noexcept;
		bool pad6(kiwi::key_up_t) noexcept;
		bool pad7(kiwi::key_up_t) noexcept;
		bool pad8(kiwi::key_up_t) noexcept;
		bool pad9(kiwi::key_up_t) noexcept;

		bool add(kiwi::key_up_t) noexcept;
		bool sub(kiwi::key_up_t) noexcept;
		bool mul(kiwi::key_up_t) noexcept;
		bool div(kiwi::key_up_t) noexcept;

		bool F1(kiwi::key_up_t) noexcept;
		bool F2(kiwi::key_up_t) noexcept;
		bool F3(kiwi::key_up_t) noexcept;
		bool F4(kiwi::key_up_t) noexcept;
		bool F5(kiwi::key_up_t) noexcept;
		bool F6(kiwi::key_up_t) noexcept;
		bool F7(kiwi::key_up_t) noexcept;
		bool F8(kiwi::key_up_t) noexcept;
		bool F9(kiwi::key_up_t) noexcept;
		bool F10(kiwi::key_up_t) noexcept;
		bool F11(kiwi::key_up_t) noexcept;
		bool F12(kiwi::key_up_t) noexcept;

		bool escape(kiwi::key_up_t) noexcept;
		bool enter(kiwi::key_up_t) noexcept;
		bool tab(kiwi::key_up_t) noexcept;
		bool backspace(kiwi::key_up_t) noexcept;
		bool insert(kiwi::key_up_t) noexcept;
		bool del(kiwi::key_up_t) noexcept;
		bool right(kiwi::key_up_t) noexcept;
		bool left(kiwi::key_up_t) noexcept;
		bool down(kiwi::key_up_t) noexcept;
		bool up(kiwi::key_up_t) noexcept;
		bool alt(kiwi::key_up_t) noexcept;
		bool shift(kiwi::key_up_t) noexcept;
		bool ctrl(kiwi::key_up_t) noexcept;
	}
}

#endif // KIWI_KEYBOARD_HPP