#ifndef KIWI_PICKER_HPP
#define KIWI_PICKER_HPP

#include "rendering/kiwi_buffer_vertex.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_buffer_frame.hpp"
#include "rendering/kiwi_sets.hpp"
#include "rendering/kiwi_draw.hpp"


namespace kiwi
{
	class scoped_picker;
	class picker_2d_proxy;
	class picker_3d_proxy;

	class picker
	{

	public:

		friend class scoped_picker;
		friend class picker_2d_proxy;
		friend class picker_3d_proxy;

		picker() = default;
		picker(const kiwi::picker&) = delete;
		kiwi::picker& operator=(const kiwi::picker&) = delete;
		picker(kiwi::picker&&) = delete;
		kiwi::picker& operator=(kiwi::picker&&) = delete;
		~picker() = default;

		kiwi::picker& init(std::size_t width, std::size_t height);
		kiwi::picker& resize(std::size_t width, std::size_t height);

	private:

		kiwi::frame_buffer m_frame_buffer;
		kiwi::texture_buffer m_texture_buffer;
		kiwi::render_buffer m_render_buffer;

		kiwi::program m_program_2d;
		kiwi::program m_program_3d;
		kiwi::program m_program_instanced_2d;
		GLint m_uniform_mvp_matrix_2d = -1;
		GLint m_uniform_mvp_matrix_3d = -1;
		GLint m_uniform_id_2d = -1;
		GLint m_uniform_id_3d = -1;
		GLint m_uniform_mvp_matrix_instanced_2d = -1;
	};

	class scoped_picker
	{

	public:

		scoped_picker(kiwi::picker& rhs);

		scoped_picker() = delete;
		scoped_picker(const kiwi::scoped_picker&) = delete;
		kiwi::scoped_picker& operator=(const kiwi::scoped_picker&) = delete;
		scoped_picker(kiwi::scoped_picker&&) = delete;
		kiwi::scoped_picker& operator=(kiwi::scoped_picker&&) = delete;
		~scoped_picker();

		kiwi::picker_2d_proxy assign_id_2d_with();
		kiwi::picker_2d_proxy assign_id_2d_with(const GLfloat* const mvp_matrix_ptr);
		kiwi::picker_3d_proxy assign_id_3d_with(const GLfloat* const mvp_matrix_ptr);

		kiwi::scoped_picker& clear_on_exit() noexcept;
		kiwi::scoped_picker& save_on_exit() noexcept;

		GLushort pick_id(std::size_t pixel_X, std::size_t pixel_Y) const;

	private:

		kiwi::picker* m_picker_ptr;
		bool m_clear_on_exit;
	};

	class picker_2d_proxy
	{

	private:

		kiwi::picker* m_picker_ptr;
		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend class scoped_picker;

		kiwi::_draw_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept;
		kiwi::_draw_instanced_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XY_id_set& XY_id_set,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_id_set& XYZ_id_set,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
	};

	class picker_3d_proxy
	{

	private:

		kiwi::picker* m_picker_ptr;
		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend class scoped_picker;

		kiwi::_draw_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept;
	};
}

#endif // KIWI_PICKER_HPP