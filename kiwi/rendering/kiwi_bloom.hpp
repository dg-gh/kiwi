#ifndef KIWI_BLOOM_HPP
#define KIWI_BLOOM_HPP

#include "rendering/kiwi_program.hpp"
#include "rendering/kiwi_buffer_vertex.hpp"
#include "rendering/kiwi_buffer_frame.hpp"


namespace kiwi
{
	class bloom
	{

	public:

		kiwi::bloom& set_scale(GLfloat scale) noexcept;
		kiwi::bloom& set_threshold(GLfloat threshold) noexcept;
		kiwi::bloom& set_layer_coefficients(GLfloat layer_1_coeff, GLfloat layer_2_coeff, GLfloat layer_3_coeff,
			GLfloat layer_4_coeff = 0.0f, GLfloat layer_5_coeff = 0.0f, GLfloat layer_6_coeff = 0.0f, GLfloat layer_7_coeff = 0.0f) noexcept;

		kiwi::bloom& init(std::size_t screen_width, std::size_t screen_height, bool extended) noexcept;
		kiwi::bloom& resize(std::size_t screen_width, std::size_t screen_height) noexcept;

		kiwi::bloom& collect() noexcept;

		kiwi::bloom& process() noexcept;

		kiwi::bloom& recollect_ground_layer() noexcept;

		kiwi::bloom& draw() noexcept;
		kiwi::bloom& draw_to_current() noexcept;
		kiwi::bloom& draw(kiwi::frame_buffer& target, std::size_t color_attachment) noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		kiwi::frame_buffer m_frame_buffer;
		kiwi::frame_buffer m_frame_buffer_extended;
		kiwi::frame_buffer m_multisampled_frame_buffer;

		kiwi::texture_buffer m_textures[16];
		kiwi::texture_buffer m_multisampled_texture;

		kiwi::render_buffer m_render_buffer;
		kiwi::render_buffer m_multisampled_render_buffer;

		kiwi::program m_threshold_program;
		kiwi::program m_blur_program;
		kiwi::program m_blend_program;
		GLint m_threshold_location = -1;
		GLint m_distance_location = -1;
		GLint m_horizontal_location = -1;
		GLint m_blur_scale_location = -1;
		GLint m_blend_location = -1;
		GLint m_blend_extended_location = -1;

		GLfloat m_UV_scale[2] = { GL1, GL1 };
		GLfloat m_UV_scale_final[2] = { GL1, GL1 };
		GLfloat m_quad_scale[2] = { GL1, GL1 };
		GLfloat m_pixel_size = GL0;
		GLfloat m_scale = GL1;
		GLfloat m_threshold = GL1;

		bool m_redraw = false;
		bool m_extended = true;
	};

	class scoped_bloom_redraw_pass;

	class scoped_bloom_pass
	{

	public:

		friend class scoped_bloom_redraw_pass;

		scoped_bloom_pass(kiwi::bloom& rhs) noexcept
		{
			rhs.collect();
			m_bloom_ptr = &rhs;
			m_bloom_processed = false;
		}

		scoped_bloom_pass() = delete;
		scoped_bloom_pass(const kiwi::scoped_bloom_pass&) = delete;
		kiwi::scoped_bloom_pass& operator=(const kiwi::scoped_bloom_pass&) = delete;
		scoped_bloom_pass(kiwi::scoped_bloom_pass&&) = delete;
		kiwi::scoped_bloom_pass& operator=(kiwi::scoped_bloom_pass&&) = delete;
		~scoped_bloom_pass()
		{
			if (!m_bloom_processed)
			{
				m_bloom_ptr->process();
			}

			m_bloom_ptr->draw();
		}

	private:

		kiwi::bloom* m_bloom_ptr;
		bool m_bloom_processed;
	};

	class scoped_bloom_redraw_pass
	{

	public:

		scoped_bloom_redraw_pass(kiwi::scoped_bloom_pass& rhs) noexcept
		{
			rhs.m_bloom_ptr->process();
			rhs.m_bloom_processed = true;
			rhs.m_bloom_ptr->recollect_ground_layer();	
		}

		scoped_bloom_redraw_pass() = delete;
		scoped_bloom_redraw_pass(const kiwi::scoped_bloom_redraw_pass&) = delete;
		kiwi::scoped_bloom_redraw_pass& operator=(const kiwi::scoped_bloom_redraw_pass&) = delete;
		scoped_bloom_redraw_pass(kiwi::scoped_bloom_redraw_pass&&) = delete;
		kiwi::scoped_bloom_redraw_pass& operator=(kiwi::scoped_bloom_redraw_pass&&) = delete;
		~scoped_bloom_redraw_pass() {}
	};
}

#endif // KIWI_BLOOM_HPP