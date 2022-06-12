#include "context/kiwi_looper_2th.hpp"


void kiwi::looper_2th::setup_loop() { }

void kiwi::looper_2th::setup_display()
{
	// setup buffers, shaders and programs

	// kiwi::draw_init();
	// kiwi::keyboard_init();
	// kiwi::mouse_init();
}

void kiwi::looper_2th::loop(GLfloat loop_time_elapsed) { call_display(); }

void kiwi::looper_2th::display(GLfloat display_time_elapsed)
{
	// kiwi::keyboard::clear_events();
	// kiwi::mouse::clear_events();
	// kiwi::poll_for_events();

	// display stuff
}

bool kiwi::looper_2th::exit_condition() { return false; }

void kiwi::looper_2th::exit_display()
{
	// terminate buffers, shaders and programs

	// kiwi::draw_terminate();
}

void kiwi::looper_2th::exit_loop() { }

void kiwi::looper_2th::call_display() noexcept
{
	if (!m_display_busy.test_and_set())
	{
		m_display_wait.clear();
	}
}

bool kiwi::looper_2th::window_resized() noexcept
{
	unsigned int temp = kiwi::window_state_counter();

	if (m_window_state_counter == temp)
	{
		return false;
	}
	else
	{
		m_window_state_counter = temp;
		return true;
	}
}

bool kiwi::looper_2th::show(const kiwi::size& size_2d, const char* const new_title)
{
	setup_loop();

	// launch display thread

	if (!m_display_thread.joinable())
	{
		int new_screen_width = static_cast<int>(size_2d[0]);
		int new_screen_height = static_cast<int>(size_2d[1]);

		m_display_thread = std::thread(&kiwi::looper_2th::display_function, this,
			new_screen_width,
			new_screen_height,
			new_title
		);
	}

	while (!m_display_setup_finished.load())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}

	if (m_display_setup_failed.load())
	{
		m_display_thread.join();
		return false;
	}

	m_loop_clock_start = std::chrono::steady_clock::now();

	m_display_wait.test_and_set();

	// loop

	while (!m_display_running.load())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}

	if (m_loop_clock_sleep_time != 0)
	{
		while (true)
		{
			// frame scheduling
			while ((m_loop_clock_stop - m_loop_clock_start).count() < m_loop_clock_sleep_time)
			{
				m_loop_clock_stop = std::chrono::steady_clock::now();
			}
			float loop_time_elapsed = static_cast<float>(factor_s_per_tick * static_cast<double>((m_loop_clock_stop - m_loop_clock_start).count()));
			m_loop_clock_start = std::chrono::steady_clock::now();

			// loop content
			loop(loop_time_elapsed);

			if (exit_condition() || kiwi::context::window_should_close())
			{
				// exit
				m_display_running.store(false);
				m_display_wait.clear();
				break;
			}
		}
	}
	else
	{
		while (true)
		{
			// frame
			m_loop_clock_stop = std::chrono::steady_clock::now();
			float loop_time_elapsed = static_cast<float>(factor_s_per_tick * static_cast<double>((m_loop_clock_stop - m_loop_clock_start).count()));
			m_loop_clock_start = std::chrono::steady_clock::now();

			// loop content
			loop(loop_time_elapsed);

			if (exit_condition() || kiwi::context::window_should_close())
			{
				// exit
				m_display_running.store(false);
				m_display_wait.clear();
				break;
			}
		}
	}

	// exit
	m_display_thread.join();

	exit_loop();

	if (m_buffer_cleanup_enabled.load())
	{
		kiwi::context::pop_tiny_window();
		kiwi::context::window_terminate();
		kiwi::context::delete_window_size_info();
		kiwi::context::window() = nullptr;
	}

	return true;
}

kiwi::looper_2th& kiwi::looper_2th::set_window_resizable(bool window_resizable) noexcept
{
	m_window_resizable = window_resizable;
	return *this;
}

kiwi::looper_2th& kiwi::looper_2th::set_aspect_ratio_free(bool free_aspect_ratio) noexcept
{
	m_window_free_ratio = free_aspect_ratio;
	return *this;
}

kiwi::looper_2th& kiwi::looper_2th::set_window_fullscreen(bool window_fullscreen) noexcept
{
	m_window_fullscreen = window_fullscreen;
	return *this;
}

kiwi::looper_2th& kiwi::looper_2th::set_anti_aliasing(bool anti_aliasing_enabled) noexcept
{
	m_window_anti_aliasing = anti_aliasing_enabled;
	return *this;
}

kiwi::looper_2th& kiwi::looper_2th::set_timeframe(double new_timeframe) noexcept
{
	if (new_timeframe > 0.0)
	{
		m_loop_clock_sleep_time = static_cast<std::chrono::time_point<std::chrono::steady_clock>::rep>(factor_tick_per_s * new_timeframe);
	}
	else
	{
		m_loop_clock_sleep_time = 0;
	}
	return *this;
}

kiwi::looper_2th& kiwi::looper_2th::enable_automatic_display_cleanup(bool cleanup_enabled) noexcept
{
	m_buffer_cleanup_enabled.store(cleanup_enabled);
	return *this;
}

void kiwi::looper_2th::display_function(std::size_t new_screen_width, std::size_t new_screen_height, const char* const new_title)
{
	if (!kiwi::context::window_init(new_screen_width, new_screen_height,
		m_window_resizable,
		m_window_free_ratio,
		m_window_fullscreen,
		m_window_anti_aliasing,
		new_title))
	{
		m_display_setup_failed.store(true);
		m_display_setup_finished.store(true);
		return;
	}

	m_window_state_counter = kiwi::window_state_counter();

	setup_display();

	m_display_running.store(true);

	while (true)
	{
		m_display_busy.clear();

		while (m_display_wait.test_and_set())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

		// frame
		m_display_clock_stop = std::chrono::steady_clock::now();
		float display_time_elapsed = static_cast<float>(factor_s_per_tick * static_cast<double>((m_display_clock_stop - m_display_clock_start).count()));
		m_display_clock_start = std::chrono::steady_clock::now();

		// display content
		display(display_time_elapsed);

		kiwi::swap_buffers();

		if (!m_display_running.load())
		{
			exit_display();
			kiwi::context::window_terminate();
			break;
		}
	}
}