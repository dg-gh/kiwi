#include "context/kiwi_looper_1th.hpp"


void kiwi::looper_1th::setup()
{
	// setup buffers, shaders and programs
	// kiwi::draw_init();
	// kiwi::keyboard_init();
	// kiwi::mouse_init();
}

void kiwi::looper_1th::loop(GLfloat loop_time_elapsed)
{
	// kiwi::keyboard::clear_events();
	// kiwi::mouse::clear_events();
	// kiwi::poll_for_events();
	// display stuff
}

bool kiwi::looper_1th::exit_condition() { return false; }

void kiwi::looper_1th::exit()
{
	// terminate buffers, shaders and programs
	// kiwi::draw_terminate();
}

bool kiwi::looper_1th::window_resized() noexcept
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

bool kiwi::looper_1th::show(kiwi::size size_2d, const char* new_title)
{
	// glfw init

	if (!glfwInit())
	{
		return false;
	}

	// window specs

	int new_screen_width = static_cast<int>(size_2d[0]);
	int new_screen_height = static_cast<int>(size_2d[1]);

	if (m_window_resizable) { glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); }
	else { glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); }

	if (m_window_anti_aliasing) { glfwWindowHint(GLFW_SAMPLES, 4); }

	if (m_window_fullscreen)
	{
		kiwi::context::window() = glfwCreateWindow(new_screen_width, new_screen_height,
			new_title, glfwGetPrimaryMonitor(), nullptr);
	}
	else
	{
		kiwi::context::window() = glfwCreateWindow(new_screen_width, new_screen_height,
			new_title, nullptr, nullptr);
	}

	if (kiwi::context::window() == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(kiwi::context::window());
	glfwSetWindowSizeCallback(kiwi::context::window(), kiwi::context::window_resize_callback);
	kiwi::context::window_resize_callback(kiwi::context::window(), new_screen_width, new_screen_height);
	m_window_state_counter = kiwi::window_state_counter();

	if (m_window_resizable && !m_window_free_ratio)
	{
		glfwSetWindowAspectRatio(kiwi::context::window(), new_screen_width, new_screen_height);
	}

	// glew init

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return false;
	}

	// display

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ZERO);
	if (m_window_anti_aliasing) { glEnable(GL_MULTISAMPLE); }

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

			glfwSwapBuffers(kiwi::context::window());

			if (exit_condition() || glfwWindowShouldClose(kiwi::context::window()))
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

			glfwSwapBuffers(kiwi::context::window());

			if (exit_condition() || glfwWindowShouldClose(kiwi::context::window()))
			{
				// exit
				break;
			}
		}
	}

	exit();

	glfwSetWindowAspectRatio(kiwi::context::window(), GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwDestroyWindow(kiwi::context::window());
	glfwTerminate();
	kiwi::context::delete_window_size_info();
	kiwi::context::window() = nullptr;
	return true;
}

kiwi::looper_1th& kiwi::looper_1th::set_window_resizable(bool window_resizable) noexcept
{
	m_window_resizable = window_resizable;
	return *this;
}

kiwi::looper_1th& kiwi::looper_1th::set_aspect_ratio_free(bool free_aspect_ratio) noexcept
{
	m_window_free_ratio = free_aspect_ratio;
	return *this;
}

kiwi::looper_1th& kiwi::looper_1th::set_window_fullscreen(bool window_fullscreen) noexcept
{
	m_window_fullscreen = window_fullscreen;
	return *this;
}

kiwi::looper_1th& kiwi::looper_1th::set_anti_aliasing(bool anti_aliasing_enabled) noexcept
{
	m_window_anti_aliasing = anti_aliasing_enabled;
	return *this;
}

kiwi::looper_1th& kiwi::looper_1th::set_timeframe(double new_timeframe) noexcept
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

GLFWwindow* kiwi::looper_1th::this_window() noexcept
{
	return kiwi::context::window();
}