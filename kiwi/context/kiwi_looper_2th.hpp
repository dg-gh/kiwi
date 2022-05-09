#ifndef KIWI_LOOPER_2TH_HPP
#define KIWI_LOOPER_2TH_HPP

#include "context/kiwi_context.hpp"


namespace kiwi
{
	class looper_2th
	{

	public:

		looper_2th() = default;
		looper_2th(const kiwi::looper_2th&) = delete;
		kiwi::looper_2th& operator=(const kiwi::looper_2th&) = delete;
		looper_2th(kiwi::looper_2th&&) = delete;
		kiwi::looper_2th& operator=(kiwi::looper_2th&&) = delete;
		virtual ~looper_2th() = default;

	protected:

		virtual void setup_loop(); // { }
		virtual void setup_display();
		// {
			// setup buffers, shaders and programs
			// kiwi::draw_init();
			// kiwi::keyboard_init();
			// kiwi::mouse_init();
		// }

		virtual void loop(GLfloat loop_time_elapsed); // { call_display(); }
		virtual void display(GLfloat display_time_elapsed);
		// {
			// kiwi::keyboard::clear_events();
			// kiwi::mouse::clear_events();
			// kiwi::poll_for_events();
			// display stuff
		// }

		virtual bool exit_condition(); // { return false; }
		virtual void exit_display();
		// {
			// terminate buffers, shaders and programs
			// kiwi::draw_terminate();
		// }
		virtual void exit_loop(); // { }

		void call_display() noexcept;

		bool window_resized() noexcept;

	public:

		bool show(kiwi::size size_2d, const char* const new_title);

		kiwi::looper_2th& set_window_resizable(bool window_resizable) noexcept;
		kiwi::looper_2th& set_aspect_ratio_free(bool free_aspect_ratio) noexcept;
		kiwi::looper_2th& set_window_fullscreen(bool window_fullscreen) noexcept;
		kiwi::looper_2th& set_anti_aliasing(bool anti_aliasing_enabled) noexcept;
		kiwi::looper_2th& set_timeframe(double new_timeframe) noexcept;

		kiwi::looper_2th& enable_automatic_display_cleanup(bool cleanup_enabled) noexcept;

	protected:
		
		GLFWwindow* this_window() noexcept;

	private:

		void display_function(int new_screen_width, int new_screen_height, const char* const new_title);

		static constexpr double factor_tick_per_s = static_cast<double>(
			std::chrono::steady_clock::duration::period::den
			/ std::chrono::steady_clock::duration::period::num);

		static constexpr double factor_s_per_tick =
			static_cast<double>(std::chrono::steady_clock::duration::period::num)
			/ static_cast<double>(std::chrono::steady_clock::duration::period::den);

		std::thread m_display_thread;

		bool m_window_resizable = false;
		bool m_window_free_ratio = false;
		bool m_window_fullscreen = false;
		bool m_window_anti_aliasing = false;

		char padd0[64] = { 0 };

		std::chrono::time_point<std::chrono::steady_clock> m_loop_clock_start;
		std::chrono::time_point<std::chrono::steady_clock> m_loop_clock_stop;
		std::chrono::time_point<std::chrono::steady_clock>::rep m_loop_clock_sleep_time = 0;

		char padd1[64] = { 0 };

		std::chrono::time_point<std::chrono::steady_clock> m_display_clock_start;
		std::chrono::time_point<std::chrono::steady_clock> m_display_clock_stop;
		unsigned int m_window_state_counter = 0;

		char padd2[64] = { 0 };

		std::atomic_flag m_display_busy = ATOMIC_FLAG_INIT;
		std::atomic_flag m_display_wait = ATOMIC_FLAG_INIT;
		std::atomic<bool> m_display_running{ false };
		std::atomic<bool> m_display_setup_finished{ false };
		std::atomic<bool> m_display_setup_failed{ false };
		std::atomic<bool> m_buffer_cleanup_enabled{ true };

		char padd3[64] = { 0 };
	};
}

#endif // KIWI_LOOPER_2TH_HPP