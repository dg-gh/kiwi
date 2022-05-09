#include "context/kiwi_window.hpp"


kiwi::window::~window()
{
	if (m_window_running)
	{
		exit_window();
	}
}

bool kiwi::window::show(kiwi::size size_2d, const char* new_title)
{
	// glfw init

	if (!glfwInit())
	{
		return false;
	}

	// window specs

	if (m_window_resizable) { glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); }
	else { glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); }

	if (m_window_anti_aliasing) { glfwWindowHint(GLFW_SAMPLES, 4); }

	int new_screen_width = static_cast<int>(size_2d[0]);
	int new_screen_height = static_cast<int>(size_2d[1]);

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

	m_window_running = true;

	return true;
}

bool kiwi::window::good()
{
	return !glfwWindowShouldClose(kiwi::context::window());
}


bool kiwi::window::window_resized() noexcept
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

void kiwi::window::exit_window()
{
	glfwSetWindowAspectRatio(kiwi::context::window(), GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwDestroyWindow(kiwi::context::window());
	glfwTerminate();
	kiwi::context::delete_window_size_info();
	kiwi::context::window() = nullptr;
	m_window_running = false;
}


void kiwi::window::set_window_resizable(bool window_resizable) noexcept
{
	m_window_resizable = window_resizable;
}

void kiwi::window::set_aspect_ratio_free(bool free_aspect_ratio) noexcept
{
	m_window_free_ratio = free_aspect_ratio;
}

void kiwi::window::set_window_fullscreen(bool window_fullscreen) noexcept
{
	m_window_fullscreen = window_fullscreen;
}

void kiwi::window::set_anti_aliasing(bool anti_aliasing_enabled) noexcept
{
	m_window_anti_aliasing = anti_aliasing_enabled;
}

GLFWwindow* kiwi::window::this_window() noexcept
{
	return kiwi::context::window();
}