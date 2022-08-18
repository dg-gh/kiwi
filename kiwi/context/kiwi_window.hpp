#ifndef KIWI_FREE_WINDOW_HPP
#define KIWI_FREE_WINDOW_HPP

#include "context/kiwi_context.hpp"
#include "header_utils/kiwi_basic_data.hpp"


namespace kiwi
{
	class window
	{

	public:

		window() = default;
		window(const kiwi::window&) = delete;
		kiwi::window& operator=(const kiwi::window&) = delete;
		window(kiwi::window&&) = delete;
		kiwi::window& operator=(kiwi::window&&) = delete;
		virtual ~window();

		bool show(const kiwi::size& size_2d, const char* const new_title);

		void exit_window();

		bool good();

		bool window_resized() noexcept;

		void set_window_resizable(bool window_resizable) noexcept;
		void set_aspect_ratio_free(bool free_aspect_ratio) noexcept;
		void set_window_fullscreen(bool window_fullscreen) noexcept;
		void set_anti_aliasing(bool anti_aliasing_enabled) noexcept;

		GLFWwindow* this_window() noexcept;

	private:

		bool m_window_resizable = false;
		bool m_window_free_ratio = false;
		bool m_window_fullscreen = false;
		bool m_window_anti_aliasing = false;

		bool m_window_running = false;

		unsigned int m_window_state_counter = 0;
	};
}

#endif // KIWI_FREE_WINDOW_HPP