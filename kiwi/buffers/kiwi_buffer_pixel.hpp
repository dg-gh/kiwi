#ifndef KIWI_BUFFER_PIXEL_HPP
#define KIWI_BUFFER_PIXEL_HPP

#include "context/kiwi_context.hpp"

namespace kiwi
{
	enum class pixel_buffer_type { texture_2d, cubemap };

	class pixel_buffer
	{

	protected:

		GLuint m_buffer_index;
		kiwi::pixel_buffer_type m_pixel_buffer_type;

	public:

		GLuint get_id() noexcept;
		kiwi::pixel_buffer_type get_pixel_buffer_type() const noexcept;
		virtual std::size_t width() const noexcept = 0;
		virtual std::size_t height() const noexcept = 0;
	};
}


#endif // KIWI_BUFFER_PIXEL_HPP