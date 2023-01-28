#ifndef _KIWI_CAMERA_3D_HPP
#define _KIWI_CAMERA_3D_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_frame.hpp"
#include "header_utils/kiwi_restrict.hpp"
#include <cmath>


namespace kiwi
{
	class camera_3d
	{

	public:

		camera_3d() = default;
		camera_3d(const kiwi::camera_3d&) = default;
		kiwi::camera_3d& operator=(const kiwi::camera_3d&) = default;
		camera_3d(kiwi::camera_3d&&) = default;
		kiwi::camera_3d& operator=(kiwi::camera_3d&&) = default;
		~camera_3d() = default;

		kiwi::camera_3d& new_projection_matrix(GLfloat screen_ratio, GLfloat fov, const kiwi::NF& near_far) noexcept;
		kiwi::camera_3d& new_projection_matrix_ortho(GLfloat screen_ratio, const kiwi::XY& scale, const kiwi::NF& near_far) noexcept;

		const GLfloat* data(const GLfloat* const model_matrix_ptr) noexcept;
		const GLfloat* operator()(const GLfloat* const model_matrix_ptr) noexcept;
		const GLfloat* skybox_data(const GLfloat* const model_matrix_ptr) noexcept;

		const GLfloat* XYZ_data() noexcept;
		const GLfloat* front_dir_data() noexcept;
		const GLfloat* right_dir_data() noexcept;
		const GLfloat* up_dir_data() noexcept;
		const GLfloat* right_front_up_XYZ_data() noexcept;
		const GLfloat* data() noexcept;
		const GLfloat* skybox_data() noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat get_Z() const noexcept;
		GLfloat get_yaw() const noexcept;
		GLfloat get_pitch() const noexcept;
		GLfloat get_roll() const noexcept;

		inline kiwi::camera_3d& set_X(GLfloat X, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_Y(GLfloat Y, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_Z(GLfloat Z, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_yaw(GLfloat yaw, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_pitch(GLfloat pitch, bool condition = true) noexcept;
		inline kiwi::camera_3d& set_angles_yp(GLfloat yaw, GLfloat pitch, bool condition = true) noexcept;
		inline kiwi::camera_3d& follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& follow(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& look_at(GLfloat X, GLfloat Y, GLfloat Z, bool condition = true) noexcept;
		inline kiwi::camera_3d& look_at(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, bool condition = true) noexcept;

		inline kiwi::camera_3d& move_front(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_back(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_left(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_right(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_up(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_down(GLfloat distance, bool condition = true) noexcept;

		inline kiwi::camera_3d& move_front_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_back_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_left_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_right_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_X(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_Y(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_Z(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition = true) noexcept;
		inline kiwi::camera_3d& move_XYZ(const GLfloat* const _KIWI_RESTRICT distance_XYZ_ptr, bool condition = true) noexcept;

		inline kiwi::camera_3d& turn_up(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_3d& turn_down(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_3d& turn_left(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_3d& turn_right(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_3d& roll_left(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::camera_3d& roll_right(GLfloat angle, bool condition = true) noexcept;

		inline bool in_view(const GLfloat* const object_XYZ_ptr) const noexcept;
		inline bool in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z) const noexcept;
		inline bool in_view(const GLfloat* const object_XYZ_ptr, GLfloat object_radius) const noexcept;
		inline bool in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z, GLfloat object_radius) const noexcept;

		GLfloat pick_view_depth(GLfloat X_screen, GLfloat Y_screen) const;
		GLfloat pick_view_depth(GLfloat X_screen, GLfloat Y_screen, const kiwi::frame_spec& frame) const;
		kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked);
		kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked, const kiwi::frame_spec& frame);
		const kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked) const;
		const kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked, const kiwi::frame_spec& frame) const;

		void eval_angles() noexcept;
		void eval() noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);
		static constexpr GLfloat GL2 = static_cast<GLfloat>(2);

		GLfloat m_mvp_matrix[16] = { GL0 };
		GLfloat m_vp_matrix[16] = { GL0 };
		GLfloat m_p_matrix[16] = {
			GL0, GL0, GL0, GL0,
			GL0, GL0, GL0, GL0,
			GL0, GL0, GL0, GL0,
			GL0, GL0, GL0, GL0
		};
		GLfloat m_v_matrix[16] = {
			GL0, GL0, GL0, GL0,
			GL0, GL0, GL0, GL0,
			GL0, GL0, GL0, GL0,
			GL0, GL0, GL0, GL1
		};
		GLfloat m_mskybox_matrix[16] = { GL0 };
		GLfloat m_skybox_matrix[16] = { GL0 };

		GLfloat m_right_front_up_XYZ[16] = {
			GL1, GL0, GL0, GL0,
			GL0, GL1, GL0, GL0,
			GL0, GL0, GL1, GL0,
			GL0, GL0, GL0, GL0,
		};
		

		GLfloat m_yaw = GL0;
		GLfloat m_pitch = GL0;
		GLfloat m_roll = GL0;

		GLfloat m_cos_yaw = GL1;
		GLfloat m_sin_yaw = GL0;
		GLfloat m_cos_pitch = GL1;
		GLfloat m_sin_pitch = GL0;
		GLfloat m_cos_roll = GL1;
		GLfloat m_sin_roll = GL0;

		GLfloat m_tan_half_fov;

		GLfloat m_cos_half_fov_x;
		GLfloat m_sin_half_fov_x;

		GLfloat m_cos_half_fov_y;
		GLfloat m_sin_half_fov_y;

		GLfloat m_z_near;
		GLfloat m_z_far;
		GLfloat m_mz;
		GLfloat m_dz;
		GLfloat m_scale_X;
		GLfloat m_scale_Y;
		GLfloat m_bound_X;
		GLfloat m_bound_Y;

		bool m_XYZ_modified = false;
		bool m_angles_modified = false;

		void m44xm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
		void m44xv4(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
		void m33hxm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;

		bool m_perspective;
	};
}


// INLINE IMPLEMENTATION

inline kiwi::camera_3d& kiwi::camera_3d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[12] = X;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[13] = Y;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_Z(GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[14] = Z;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[12] = X;
		m_right_front_up_XYZ[13] = Y;
		m_right_front_up_XYZ[14] = Z;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_XYZ(const GLfloat* const  _KIWI_RESTRICT XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[12] = *XYZ_ptr;
		m_right_front_up_XYZ[13] = *(XYZ_ptr + 1);
		m_right_front_up_XYZ[14] = *(XYZ_ptr + 2);
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_yaw(GLfloat yaw, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = yaw;
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_pitch(GLfloat pitch, bool condition) noexcept
{
	if (condition)
	{
		m_pitch = pitch;
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::set_angles_yp(GLfloat yaw, GLfloat pitch, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = yaw;
		m_pitch = pitch;
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] = X - distance * m_right_front_up_XYZ[4];
		m_right_front_up_XYZ[13] = Y - distance * m_right_front_up_XYZ[5];
		m_right_front_up_XYZ[14] = Z - distance * m_right_front_up_XYZ[6];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::follow(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] = *XYZ_ptr - distance * m_right_front_up_XYZ[4];
		m_right_front_up_XYZ[13] = *(XYZ_ptr + 1) - distance * m_right_front_up_XYZ[5];
		m_right_front_up_XYZ[14] = *(XYZ_ptr + 2) - distance * m_right_front_up_XYZ[6];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::look_at(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		GLfloat dX = X - m_right_front_up_XYZ[12];
		GLfloat dY = Y - m_right_front_up_XYZ[13];
		GLfloat dZ = Z - m_right_front_up_XYZ[14];
		m_yaw = std::atan2(dY, dX);
		m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::look_at(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		GLfloat dX = *XYZ_ptr - m_right_front_up_XYZ[12];
		GLfloat dY = *(XYZ_ptr + 1) - m_right_front_up_XYZ[13];
		GLfloat dZ = *(XYZ_ptr + 2) - m_right_front_up_XYZ[14];
		m_yaw = std::atan2(dY, dX);
		m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_front(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] += distance * m_right_front_up_XYZ[4];
		m_right_front_up_XYZ[13] += distance * m_right_front_up_XYZ[5];
		m_right_front_up_XYZ[14] += distance * m_right_front_up_XYZ[6];
		m_right_front_up_XYZ[15] += distance * m_right_front_up_XYZ[7];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_back(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] -= distance * m_right_front_up_XYZ[4];
		m_right_front_up_XYZ[13] -= distance * m_right_front_up_XYZ[5];
		m_right_front_up_XYZ[14] -= distance * m_right_front_up_XYZ[6];
		m_right_front_up_XYZ[15] -= distance * m_right_front_up_XYZ[7];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] -= distance * m_right_front_up_XYZ[0];
		m_right_front_up_XYZ[13] -= distance * m_right_front_up_XYZ[1];
		m_right_front_up_XYZ[14] -= distance * m_right_front_up_XYZ[2];
		m_right_front_up_XYZ[15] -= distance * m_right_front_up_XYZ[3];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] += distance * m_right_front_up_XYZ[0];
		m_right_front_up_XYZ[13] += distance * m_right_front_up_XYZ[1];
		m_right_front_up_XYZ[14] += distance * m_right_front_up_XYZ[2];
		m_right_front_up_XYZ[15] += distance * m_right_front_up_XYZ[3];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] += distance * m_right_front_up_XYZ[8];
		m_right_front_up_XYZ[13] += distance * m_right_front_up_XYZ[9];
		m_right_front_up_XYZ[14] += distance * m_right_front_up_XYZ[10];
		m_right_front_up_XYZ[15] += distance * m_right_front_up_XYZ[11];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] -= distance * m_right_front_up_XYZ[8];
		m_right_front_up_XYZ[13] -= distance * m_right_front_up_XYZ[9];
		m_right_front_up_XYZ[14] -= distance * m_right_front_up_XYZ[10];
		m_right_front_up_XYZ[15] -= distance * m_right_front_up_XYZ[11];
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_front_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] += distance * m_cos_yaw;
		m_right_front_up_XYZ[13] += distance * m_sin_yaw;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_back_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] -= distance * m_cos_yaw;
		m_right_front_up_XYZ[13] -= distance * m_sin_yaw;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_left_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] -= distance * m_sin_yaw;
		m_right_front_up_XYZ[13] += distance * m_cos_yaw;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_right_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		if (m_angles_modified) { eval_angles(); }
		m_right_front_up_XYZ[12] += distance * m_sin_yaw;
		m_right_front_up_XYZ[13] -= distance * m_cos_yaw;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_X(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[12] += distance;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_Y(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[13] += distance;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_Z(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[14] += distance;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[12] += distance_X;
		m_right_front_up_XYZ[13] += distance_Y;
		m_right_front_up_XYZ[14] += distance_Z;
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::move_XYZ(const GLfloat* const _KIWI_RESTRICT distance_XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_right_front_up_XYZ[12] += *distance_XYZ_ptr;
		m_right_front_up_XYZ[13] += *(distance_XYZ_ptr + 1);
		m_right_front_up_XYZ[14] += *(distance_XYZ_ptr + 2);
		m_XYZ_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::turn_up(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
		m_pitch += angle;
		while (m_pitch > pi_d2) { m_pitch = pi_d2; }
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::turn_down(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
		m_pitch -= angle;
		while (m_pitch < -pi_d2) { m_pitch = -pi_d2; }
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::turn_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw += angle;
		while (m_yaw > pi) { m_yaw -= pi_t2; }
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw -= angle;
		while (m_yaw < -pi) { m_yaw += pi_t2; }
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::roll_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_roll += angle;
		while (m_roll > pi) { m_roll -= pi_t2; }
		m_angles_modified = true;
	}

	return *this;
}

inline kiwi::camera_3d& kiwi::camera_3d::roll_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_roll -= angle;
		while (m_roll < -pi) { m_roll += pi_t2; }
		m_angles_modified = true;
	}

	return *this;
}

inline bool kiwi::camera_3d::in_view(const GLfloat* const object_XYZ_ptr) const noexcept
{
	GLfloat object_XYZ[4];
	object_XYZ[0] = *object_XYZ_ptr;
	object_XYZ[1] = *(object_XYZ_ptr + 1);
	object_XYZ[2] = *(object_XYZ_ptr + 2);
	object_XYZ[3] = GL1;

	GLfloat object_XYZ_in_view[4];

	m44xv4(static_cast<GLfloat*>(object_XYZ_in_view),
		static_cast<const GLfloat*>(m_v_matrix),
		static_cast<const GLfloat*>(object_XYZ));

	if (m_perspective)
	{
		GLfloat bound_X = m_sin_half_fov_x * object_XYZ_in_view[2];
		GLfloat bound_Y = m_sin_half_fov_y * object_XYZ_in_view[2];

		GLfloat check_X = m_cos_half_fov_x * object_XYZ_in_view[0];
		GLfloat check_Y = m_cos_half_fov_y * object_XYZ_in_view[1];

		return ((m_z_near <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far))
			& ((-bound_X <= check_X) & (check_X <= bound_X))
			& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		return ((m_z_near <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far))
			& ((-m_bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= m_bound_X))
			& ((-m_bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= m_bound_Y));
	}
}

inline bool kiwi::camera_3d::in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z) const noexcept
{
	GLfloat object_XYZ[4];
	object_XYZ[0] = object_X;
	object_XYZ[1] = object_Y;
	object_XYZ[2] = object_Z;
	object_XYZ[3] = GL1;

	GLfloat object_XYZ_in_view[4];

	m44xv4(static_cast<GLfloat*>(object_XYZ_in_view),
		static_cast<const GLfloat*>(m_v_matrix),
		static_cast<const GLfloat*>(object_XYZ));

	if (m_perspective)
	{
		GLfloat bound_X = m_sin_half_fov_x * object_XYZ_in_view[2];
		GLfloat bound_Y = m_sin_half_fov_y * object_XYZ_in_view[2];

		GLfloat check_X = m_cos_half_fov_x * object_XYZ_in_view[0];
		GLfloat check_Y = m_cos_half_fov_y * object_XYZ_in_view[1];

		return ((m_z_near <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far))
			& ((-bound_X <= check_X) & (check_X <= bound_X))
			& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		return ((m_z_near <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far))
			& ((-m_bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= m_bound_X))
			& ((-m_bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= m_bound_Y));
	}
}

inline bool kiwi::camera_3d::in_view(const GLfloat* const object_XYZ_ptr, GLfloat object_radius) const noexcept
{
	GLfloat object_XYZ[4];
	object_XYZ[0] = *object_XYZ_ptr;
	object_XYZ[1] = *(object_XYZ_ptr + 1);
	object_XYZ[2] = *(object_XYZ_ptr + 2);
	object_XYZ[3] = GL1;

	GLfloat object_XYZ_in_view[4];

	m44xv4(static_cast<GLfloat*>(object_XYZ_in_view),
		static_cast<const GLfloat*>(m_v_matrix),
		static_cast<const GLfloat*>(object_XYZ));

	if (m_perspective)
	{
		GLfloat bound_X = m_sin_half_fov_x * object_XYZ_in_view[2] + object_radius;
		GLfloat bound_Y = m_sin_half_fov_y * object_XYZ_in_view[2] + object_radius;

		GLfloat check_X = m_cos_half_fov_x * object_XYZ_in_view[0];
		GLfloat check_Y = m_cos_half_fov_y * object_XYZ_in_view[1];

		return ((m_z_near - object_radius <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far + object_radius))
			& ((-bound_X <= check_X) & (check_X <= bound_X))
			& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		GLfloat bound_X = m_bound_X + object_radius;
		GLfloat bound_Y = m_bound_Y + object_radius;

		return ((m_z_near - object_radius <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far + object_radius))
			& ((-bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= bound_X))
			& ((-bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= bound_Y));
	}
}

inline bool kiwi::camera_3d::in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z, GLfloat object_radius) const noexcept
{
	GLfloat object_XYZ[4];
	object_XYZ[0] = object_X;
	object_XYZ[1] = object_Y;
	object_XYZ[2] = object_Z;
	object_XYZ[3] = GL1;

	GLfloat object_XYZ_in_view[4];

	m44xv4(static_cast<GLfloat*>(object_XYZ_in_view),
		static_cast<const GLfloat*>(m_v_matrix),
		static_cast<const GLfloat*>(object_XYZ));

	if (m_perspective)
	{
		GLfloat bound_X = m_sin_half_fov_x * object_XYZ_in_view[2] + object_radius;
		GLfloat bound_Y = m_sin_half_fov_y * object_XYZ_in_view[2] + object_radius;

		GLfloat check_X = m_cos_half_fov_x * object_XYZ_in_view[0];
		GLfloat check_Y = m_cos_half_fov_y * object_XYZ_in_view[1];

		return ((m_z_near - object_radius <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far + object_radius))
			& ((-bound_X <= check_X) & (check_X <= bound_X))
			& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		GLfloat bound_X = m_bound_X + object_radius;
		GLfloat bound_Y = m_bound_Y + object_radius;

		return ((m_z_near - object_radius <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far + object_radius))
			& ((-bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= bound_X))
			& ((-bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= bound_Y));
	}
}

inline GLfloat kiwi::camera_3d::pick_view_depth(GLfloat X_screen, GLfloat Y_screen) const
{
	GLfloat depth_sampled;
	glReadPixels(kiwi::X_to_pixel(X_screen), kiwi::Y_to_pixel(Y_screen),
		1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth_sampled);

	if (m_perspective)
	{
		return m_mz / (m_z_far - depth_sampled * m_dz);
	}
	else
	{
		return m_z_near + m_dz * depth_sampled;
	}
}

#endif // _KIWI_CAMERA_3D_HPP