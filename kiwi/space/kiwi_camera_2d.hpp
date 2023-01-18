#ifndef _KIWI_CAMERA_2D_HPP
#define _KIWI_CAMERA_2D_HPP

#include "header_utils/kiwi_glcall.hpp"
#include "header_utils/kiwi_restrict.hpp"
#include <cmath>


namespace kiwi
{
	class camera_2d
	{

	public:

		camera_2d() = default;
		camera_2d(const kiwi::camera_2d&) = default;
		kiwi::camera_2d& operator=(const kiwi::camera_2d&) = default;
		camera_2d(kiwi::camera_2d&&) = default;
		kiwi::camera_2d& operator=(kiwi::camera_2d&&) = default;
		~camera_2d() = default;

		kiwi::camera_2d& set_new_projection_matrix(GLfloat screen_ratio) noexcept;

		const GLfloat* data() noexcept;
		operator const GLfloat* () noexcept;

		const GLfloat* data(const GLfloat* const model_matrix_ptr) noexcept;
		const GLfloat* operator()(const GLfloat* const model_matrix_ptr) noexcept;

		const GLfloat* XY_data() noexcept;
		const GLfloat* right_dir_data() noexcept;
		const GLfloat* up_dir_data() noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat get_angle() const noexcept;
		GLfloat get_scale() const noexcept;

		inline kiwi::camera_2d& set_X(GLfloat X, bool condition = true) noexcept;
		inline kiwi::camera_2d& set_Y(GLfloat Y, bool condition = true) noexcept;
		inline kiwi::camera_2d& set_XY(GLfloat X, GLfloat Y, bool condition = true) noexcept;
		inline kiwi::camera_2d& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr, bool condition = true) noexcept;
		inline kiwi::camera_2d& set_angle(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_2d& set_scale(GLfloat scale, bool condition = true) noexcept;

		inline kiwi::camera_2d& turn_left(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_2d& turn_right(GLfloat angle, bool condition = true) noexcept;

		inline kiwi::camera_2d& move_up(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_2d& move_down(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_2d& move_right(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_2d& move_left(GLfloat distance, bool condition = true) noexcept;

		inline bool in_view(const GLfloat* const object_XY_ptr) noexcept;
		inline bool in_view(GLfloat object_X, GLfloat object_Y) noexcept;
		inline bool in_view(const GLfloat* const object_XY_ptr, GLfloat object_radius) noexcept;
		inline bool in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_radius) noexcept;

		kiwi::camera_2d& pick_XY(GLfloat X_screen, GLfloat Y_screen, GLfloat* XY_picked) noexcept;
		const kiwi::camera_2d& pick_XY(GLfloat X_screen, GLfloat Y_screen, GLfloat* XY_picked) const noexcept;

		void eval_angles() noexcept;
		void eval() noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		GLfloat m_mvp_matrix[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_vp_matrix[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_right_up_XY[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};

		GLfloat m_yaw = GL0;
		GLfloat m_scale = GL1;

		GLfloat m_X_factor = GL1;
		GLfloat m_Y_factor = GL1;

		void m33xm33(GLfloat* _KIWI_RESTRICT pfC, const GLfloat* pfA, const GLfloat* pfB) const noexcept;

		bool m_XY_modified = false;
		bool m_angle_modified = false;
	};
}


// INLINE IMPLEMENTATION

inline kiwi::camera_2d& kiwi::camera_2d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] = X;
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[7] = Y;
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::set_XY(GLfloat X, GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] = X;
		m_right_up_XY[7] = Y;
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] = *XY_ptr;
		m_right_up_XY[7] = *(XY_ptr + 1);
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::set_angle(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = angle;
		m_angle_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::set_scale(GLfloat scale, bool condition) noexcept
{
	if (condition)
	{
		m_scale = scale;
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::turn_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw += angle;
		while (m_yaw > pi) { m_yaw -= pi_t2; }
		m_angle_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		if (m_angle_modified) { eval_angles(); }
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw -= angle;
		while (m_yaw < -pi) { m_yaw += pi_t2; }
		m_angle_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angle_modified) { eval_angles(); }
		m_right_up_XY[6] -= distance * m_right_up_XY[0];
		m_right_up_XY[7] -= distance * m_right_up_XY[1];
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angle_modified) { eval_angles(); }
		m_right_up_XY[6] += distance * m_right_up_XY[0];
		m_right_up_XY[7] += distance * m_right_up_XY[1];
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angle_modified) { eval_angles(); }
		m_right_up_XY[6] -= distance * m_right_up_XY[1];
		m_right_up_XY[7] += distance * m_right_up_XY[0];
		m_XY_modified = true;
	}

	return *this;
}

inline kiwi::camera_2d& kiwi::camera_2d::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angle_modified) { eval_angles(); }
		m_right_up_XY[6] += distance * m_right_up_XY[1];
		m_right_up_XY[7] -= distance * m_right_up_XY[0];
		m_XY_modified = true;
	}

	return *this;
}

inline bool kiwi::camera_2d::in_view(const GLfloat* const object_XY_ptr) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_XY_ptr[0] + m_vp_matrix[3] * object_XY_ptr[1] + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_XY_ptr[0] + m_vp_matrix[4] * object_XY_ptr[1] + m_vp_matrix[7];
	return ((-m_X_factor <= X_screen) & (X_screen <= m_X_factor)) & ((-m_Y_factor <= Y_screen) & (Y_screen <= m_Y_factor));
}

inline bool kiwi::camera_2d::in_view(GLfloat object_X, GLfloat object_Y) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_X + m_vp_matrix[3] * object_Y + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_X + m_vp_matrix[4] * object_Y + m_vp_matrix[7];
	return ((-m_X_factor <= X_screen) & (X_screen <= m_X_factor)) & ((-m_Y_factor <= Y_screen) & (Y_screen <= m_Y_factor));
}

inline bool kiwi::camera_2d::in_view(const GLfloat* const object_XY_ptr, GLfloat object_radius) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_XY_ptr[0] + m_vp_matrix[3] * object_XY_ptr[1] + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_XY_ptr[0] + m_vp_matrix[4] * object_XY_ptr[1] + m_vp_matrix[7];
	GLfloat X_bound = m_X_factor + object_radius;
	GLfloat Y_bound = m_Y_factor + object_radius;
	return ((-X_bound <= X_screen) & (X_screen <= X_bound)) & ((-Y_bound <= Y_screen) & (Y_screen <= Y_bound));
}

inline bool kiwi::camera_2d::in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_radius) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_X + m_vp_matrix[3] * object_Y + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_X + m_vp_matrix[4] * object_Y + m_vp_matrix[7];
	GLfloat X_bound = m_X_factor + object_radius;
	GLfloat Y_bound = m_Y_factor + object_radius;
	return ((-X_bound <= X_screen) & (X_screen <= X_bound)) & ((-Y_bound <= Y_screen) & (Y_screen <= Y_bound));
}

#endif // _KIWI_CAMERA_2D_HPP