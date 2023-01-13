#ifndef KIWI_PICKER_HPP
#define KIWI_PICKER_HPP

#include "buffers/kiwi_buffer_vertex.hpp"
#include "buffers/kiwi_buffer_frame.hpp"
#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_sets.hpp"
#include "rendering/kiwi_draw.hpp"

namespace kiwi
{
	bool draw_id_init();
	void draw_id_terminate() noexcept;
}


namespace kiwi
{
	class _picker_2d_proxy;
	class _picker_3d_proxy;

	class picker
	{

	public:

		friend class _picker_2d_proxy;
		friend class _picker_3d_proxy;

		picker() = default;
		picker(const kiwi::picker&) = delete;
		kiwi::picker& operator=(const kiwi::picker&) = delete;
		picker(kiwi::picker&&) = delete;
		kiwi::picker& operator=(kiwi::picker&&) = delete;
		~picker() = default;

		kiwi::picker& init(std::size_t width, std::size_t height) noexcept;
		kiwi::picker& resize(std::size_t width, std::size_t height) noexcept;

		kiwi::picker& collect() noexcept;
		GLushort pick_id(std::size_t pixel_X, std::size_t pixel_Y) const noexcept;

	private:

		kiwi::frame_buffer m_frame_buffer;
		kiwi::texture_2d m_texture_buffer;
		kiwi::render_buffer m_render_buffer;
	};

	kiwi::_picker_2d_proxy draw_id_2d_with() noexcept;
	kiwi::_picker_2d_proxy draw_id_2d_with(const GLfloat* const mvp_matrix_ptr) noexcept;
	kiwi::_picker_3d_proxy draw_id_3d_with(const GLfloat* const mvp_matrix_ptr) noexcept;

	class _picker_2d_proxy
	{

	private:

		kiwi::picker* m_picker_ptr;
		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend kiwi::_picker_2d_proxy draw_id_2d_with() noexcept;
		friend kiwi::_picker_2d_proxy draw_id_2d_with(const GLfloat* const mvp_matrix_ptr) noexcept;
		friend class scoped_picker;

		kiwi::_draw_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept;
		/*
		kiwi::_draw_instanced_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XY_id_set& XY_id_set,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		kiwi::_draw_instanced_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, const kiwi::XYZ_id_set& XYZ_id_set,
			const GLfloat* const mvp_matrix_2d_ptr = nullptr) noexcept;
		*/
	};

	class _picker_3d_proxy
	{

	private:

		kiwi::picker* m_picker_ptr;
		const GLfloat* m_transformation_matrix_ptr;

	public:

		friend kiwi::_picker_3d_proxy draw_id_3d_with(const GLfloat* const mvp_matrix_ptr) noexcept;
		friend class scoped_picker;

		kiwi::_draw_basic_proxy using_vertex(const kiwi::vertex_buffer& vertex_buffer, GLushort entity_id) noexcept;
	};
}

#endif // KIWI_PICKER_HPP