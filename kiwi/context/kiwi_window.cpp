#include "context/kiwi_window.hpp"


kiwi::window::~window()
{
	if (m_window_running)
	{
		exit_window();
	}
}

bool kiwi::window::show(const kiwi::size& size_2d, const char* const new_title)
{
	if (!kiwi::context::window_init(size_2d[0], size_2d[1],
		m_window_resizable,
		m_window_free_ratio,
		m_window_fullscreen,
		m_window_anti_aliasing,
		new_title))
	{
		return false;
	}

	m_window_state_counter = kiwi::window_state_counter();

	m_window_running = true;

	return true;
}

bool kiwi::window::good()
{
	return !kiwi::context::window_should_close();
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
	kiwi::context::window_terminate();
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