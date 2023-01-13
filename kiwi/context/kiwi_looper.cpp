#include "context/kiwi_looper.hpp"


void kiwi::looper::setup()
{
	// setup buffers, shaders and programs
	// kiwi::draw_init();
	// kiwi::keyboard_init();
	// kiwi::mouse_init();
}

void kiwi::looper::loop(GLfloat loop_time_elapsed)
{
	// kiwi::keyboard::clear_events();
	// kiwi::mouse::clear_events();
	// kiwi::poll_for_events();
	// display stuff
}

bool kiwi::looper::exit_condition() { return false; }

int kiwi::looper::exit()
{
	// terminate buffers, shaders and programs
	// kiwi::draw_terminate();
	return 0;
}

bool kiwi::looper::window_resized() noexcept
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

int kiwi::looper::show(const kiwi::size& size_2d, const char* const new_title)
{
	if (!kiwi::context::window_init(size_2d[0], size_2d[1],
		m_window_resizable,
		m_window_free_ratio,
		m_window_fullscreen,
		m_window_anti_aliasing,
		new_title))
	{
		return -1;
	}

	m_window_state_counter = kiwi::window_state_counter();

	setup();

	if (m_timeframe_int != 0)
	{
		m_loop_clock_start = std::chrono::steady_clock::now();

		while (true)
		{
			// frame delay
			std::this_thread::sleep_for(std::chrono::milliseconds(m_timeframe_int
				- static_cast<long long>(factor_ms_per_tick * static_cast<double>((std::chrono::steady_clock::now() - m_loop_clock_start).count()))
			));

			float loop_time_elapsed = static_cast<float>(factor_s_per_tick
				* static_cast<double>((std::chrono::steady_clock::now() - m_loop_clock_start).count()));
			m_loop_clock_start = std::chrono::steady_clock::now();

			// loop content
			loop(loop_time_elapsed);

			kiwi::swap_buffers();

			if (exit_condition() || kiwi::context::window_should_close())
			{
				// exit
				break;
			}
		}
	}
	else
	{
		m_loop_clock_start = std::chrono::steady_clock::now();

		while (true)
		{
			// frame delay
			float loop_time_elapsed = static_cast<float>(factor_s_per_tick
				* static_cast<double>((std::chrono::steady_clock::now() - m_loop_clock_start).count()));
			m_loop_clock_start = std::chrono::steady_clock::now();

			// loop content
			loop(loop_time_elapsed);

			kiwi::swap_buffers();

			if (exit_condition() || kiwi::context::window_should_close())
			{
				// exit
				break;
			}
		}
	}

	int result = exit();

	kiwi::context::window_terminate();
	kiwi::context::delete_window_size_info();
	kiwi::context::window() = nullptr;
	return result;
}

kiwi::looper& kiwi::looper::set_window_resizable(bool window_resizable) noexcept
{
	m_window_resizable = window_resizable;
	return *this;
}

kiwi::looper& kiwi::looper::set_aspect_ratio_free(bool free_aspect_ratio) noexcept
{
	m_window_free_ratio = free_aspect_ratio;
	return *this;
}

kiwi::looper& kiwi::looper::set_window_fullscreen(bool window_fullscreen) noexcept
{
	m_window_fullscreen = window_fullscreen;
	return *this;
}

kiwi::looper& kiwi::looper::set_anti_aliasing(bool anti_aliasing_enabled) noexcept
{
	m_window_anti_aliasing = anti_aliasing_enabled;
	return *this;
}

kiwi::looper& kiwi::looper::set_timeframe(double new_timeframe) noexcept
{
	if (new_timeframe > 0.0)
	{
		m_loop_clock_sleep_time = static_cast<std::chrono::time_point<std::chrono::steady_clock>::rep>(factor_tick_per_s * new_timeframe);
		m_timeframe_int = static_cast<long long>(1000.0 * new_timeframe);
	}
	else
	{
		m_timeframe_int = 0;
	}
	return *this;
}