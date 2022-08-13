#ifndef KIWI_LOOPER_1TH_HPP
#define KIWI_LOOPER_1TH_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	class looper_1th
	{

	public:

		looper_1th() = default;
		looper_1th(const kiwi::looper_1th&) = delete;
		kiwi::looper_1th& operator=(const kiwi::looper_1th&) = delete;
		looper_1th(kiwi::looper_1th&&) = delete;
		kiwi::looper_1th& operator=(kiwi::looper_1th&&) = delete;
		virtual ~looper_1th() = default;

	protected:

		virtual void setup();
		// {
			// setup buffers, shaders and programs

			// kiwi::draw_init();
			// kiwi::keyboard_init();
			// kiwi::mouse_init();
		// }

		virtual void loop(GLfloat loop_time_elapsed);
		// {
			// kiwi::keyboard::clear_events();
			// kiwi::mouse::clear_events();
			// kiwi::poll_for_events();

			// display stuff
		// }

		virtual bool exit_condition(); // { return false; }
		virtual int exit();
		// {
			// terminate buffers, shaders and programs

			// kiwi::draw_terminate();
		// }

		bool window_resized() noexcept;

	public:

		int show(const kiwi::size& size_2d, const char* const new_title);

		kiwi::looper_1th& set_window_resizable(bool window_resizable) noexcept;
		kiwi::looper_1th& set_aspect_ratio_free(bool free_aspect_ratio) noexcept;
		kiwi::looper_1th& set_window_fullscreen(bool window_fullscreen) noexcept;
		kiwi::looper_1th& set_anti_aliasing(bool anti_aliasing_enabled) noexcept;
		kiwi::looper_1th& set_timeframe(double new_timeframe) noexcept; // can be redefined any time

	private:

		static constexpr double factor_tick_per_s = static_cast<double>(
			std::chrono::steady_clock::duration::period::den
			/ std::chrono::steady_clock::duration::period::num);

		static constexpr double factor_s_per_tick =
			static_cast<double>(std::chrono::steady_clock::duration::period::num)
			/ static_cast<double>(std::chrono::steady_clock::duration::period::den);

		static constexpr double factor_ms_per_tick = 1000.0 * factor_s_per_tick;

		bool m_window_resizable = false;
		bool m_window_free_ratio = false;
		bool m_window_fullscreen = false;
		bool m_window_anti_aliasing = false;

		std::chrono::time_point<std::chrono::steady_clock> m_loop_clock_start;
		std::chrono::time_point<std::chrono::steady_clock>::rep m_loop_clock_sleep_time = 0;
		long long m_timeframe_int = 0;

		unsigned int m_window_state_counter = 0;
	};
}

#endif // KIWI_LOOPER_1TH_HPP