#ifndef _KIWI_MODEL_3D_HPP
#define _KIWI_MODEL_3D_HPP

#include "header_utils/kiwi_glcall.hpp"
#include "header_utils/kiwi_restrict.hpp"
#include <cmath>


namespace kiwi
{
	class model_3d
	{

	public:

		model_3d() = default;
		model_3d(const kiwi::model_3d&) = default;
		kiwi::model_3d& operator=(const kiwi::model_3d&) = default;
		model_3d(kiwi::model_3d&&) = default;
		kiwi::model_3d& operator=(kiwi::model_3d&&) = default;
		~model_3d() = default;

		inline const GLfloat* data() noexcept;
		inline operator const GLfloat* () noexcept;

		kiwi::model_3d& set_base_model(kiwi::model_3d* base_model_ptr) noexcept;
		kiwi::model_3d* get_base_model() const noexcept;
		kiwi::model_3d& set_free() noexcept;

		inline const GLfloat* front_dir_data() noexcept;
		inline const GLfloat* left_dir_data() noexcept;
		inline const GLfloat* up_dir_data() noexcept;

		inline const GLfloat* front_dir_data_free() noexcept;
		inline const GLfloat* left_dir_data_free() noexcept;
		inline const GLfloat* up_dir_data_free() noexcept;

		inline GLfloat get_X() const noexcept;
		inline GLfloat get_Y() const noexcept;
		inline GLfloat get_Z() const noexcept;
		inline const GLfloat* XYZ_data() noexcept;
		inline GLfloat get_yaw() const noexcept;
		inline GLfloat get_pitch() const noexcept;
		inline GLfloat get_roll() const noexcept;

		inline GLfloat get_X_free() noexcept;
		inline GLfloat get_Y_free() noexcept;
		inline GLfloat get_Z_free() noexcept;
		inline const GLfloat* XYZ_data_free() noexcept;
		inline GLfloat get_yaw_free() noexcept;
		inline GLfloat get_pitch_free() noexcept;
		inline GLfloat get_roll_free() noexcept;

		inline kiwi::model_3d& set_X(GLfloat X, bool condition = true) noexcept;
		inline kiwi::model_3d& set_Y(GLfloat Y, bool condition = true) noexcept;
		inline kiwi::model_3d& set_Z(GLfloat Z, bool condition = true) noexcept;
		inline kiwi::model_3d& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition = true) noexcept;
		inline kiwi::model_3d& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, bool condition = true) noexcept;
		inline kiwi::model_3d& move_X(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_Y(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_Z(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition = true) noexcept;
		inline kiwi::model_3d& move_XYZ(const GLfloat* const _KIWI_RESTRICT distance_XYZ_ptr, bool condition = true) noexcept;
		inline kiwi::model_3d& set_yaw(GLfloat yaw, bool condition = true) noexcept;
		inline kiwi::model_3d& set_pitch(GLfloat pitch, bool condition = true) noexcept;
		inline kiwi::model_3d& set_roll(GLfloat roll, bool condition = true) noexcept;
		inline kiwi::model_3d& set_angles(GLfloat yaw, GLfloat pitch, GLfloat roll, bool condition = true) noexcept;

		inline kiwi::model_3d& move_front(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_back(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_left(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_right(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_up(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_down(GLfloat distance, bool condition = true) noexcept;

		inline kiwi::model_3d& move_front_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_back_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_left_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_right_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_up_h(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_3d& move_down_h(GLfloat distance, bool condition = true) noexcept;

		inline kiwi::model_3d& turn_left(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::model_3d& turn_right(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::model_3d& turn_up(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::model_3d& turn_down(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::model_3d& tilt_left(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::model_3d& tilt_right(GLfloat angle, bool condition = true) noexcept;

		inline kiwi::model_3d& eval() noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		GLfloat m_matrix_free[16] = {
			GL1, GL0, GL0, GL0,
			GL0, GL1, GL0, GL0,
			GL0, GL0, GL1, GL0,
			GL0, GL0, GL0, GL1,
		};
		GLfloat m_matrix_rel[16] = {
			GL1, GL0, GL0, GL0,
			GL0, GL1, GL0, GL0,
			GL0, GL0, GL1, GL0,
			GL0, GL0, GL0, GL1,
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

		kiwi::model_3d* m_parent_model_ptr = nullptr;
		unsigned int m_state_counter = 0;
		unsigned int m_parent_model_state_counter = 0;

		bool m_XYZ_modified = false;
		bool m_angles_modified = false;

		void m44xm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
		void m44xv4(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* pfB) const noexcept;
	};
}


// INLINES IMPLEMENTATION

inline const GLfloat* kiwi::model_3d::data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

inline kiwi::model_3d::operator const GLfloat* () noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

inline const GLfloat* kiwi::model_3d::front_dir_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel);
}

inline const GLfloat* kiwi::model_3d::left_dir_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel) + 4;
}

inline const GLfloat* kiwi::model_3d::up_dir_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel) + 8;
}

inline const GLfloat* kiwi::model_3d::front_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

inline const GLfloat* kiwi::model_3d::left_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 4;
}

inline const GLfloat* kiwi::model_3d::up_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 8;
}

inline GLfloat kiwi::model_3d::get_X() const noexcept
{
	return m_matrix_rel[12];
}

inline GLfloat kiwi::model_3d::get_Y() const noexcept
{
	return m_matrix_rel[13];
}

inline GLfloat kiwi::model_3d::get_Z() const noexcept
{
	return m_matrix_rel[14];
}

inline const GLfloat* kiwi::model_3d::XYZ_data() noexcept
{
	return static_cast<const GLfloat*>(m_matrix_rel) + 12;
}

inline GLfloat kiwi::model_3d::get_yaw() const noexcept
{
	return m_yaw;
}

inline GLfloat kiwi::model_3d::get_pitch() const noexcept
{
	return m_pitch;
}

inline GLfloat kiwi::model_3d::get_roll() const noexcept
{
	return m_roll;
}

inline GLfloat kiwi::model_3d::get_X_free() noexcept
{
	eval();
	return m_matrix_free[12];
}

inline GLfloat kiwi::model_3d::get_Y_free() noexcept
{
	eval();
	return m_matrix_free[13];
}

inline GLfloat kiwi::model_3d::get_Z_free() noexcept
{
	eval();
	return m_matrix_free[14];
}

inline const GLfloat* kiwi::model_3d::XYZ_data_free() noexcept
{
	eval();
	return static_cast<const GLfloat*>(m_matrix_free) + 12;
}

inline GLfloat kiwi::model_3d::get_yaw_free() noexcept
{
	eval();
	return std::atan2(m_matrix_free[1], m_matrix_free[0]);
}

inline GLfloat kiwi::model_3d::get_pitch_free() noexcept
{
	eval();
	return std::atan2(m_matrix_free[2], std::sqrt(m_matrix_free[0] * m_matrix_free[0] + m_matrix_free[1] * m_matrix_free[1]));
}

inline GLfloat kiwi::model_3d::get_roll_free() noexcept
{
	eval();
	return std::atan2(-m_matrix_free[6], m_matrix_free[10]);
}

inline kiwi::model_3d& kiwi::model_3d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] = X;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[13] = Y;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_Z(GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] = Z;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] = X;
		m_matrix_rel[13] = Y;
		m_matrix_rel[14] = Z;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] = *XYZ_ptr;
		m_matrix_rel[13] = *(XYZ_ptr + 1);
		m_matrix_rel[14] = *(XYZ_ptr + 2);
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_X(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_Y(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[13] += distance;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_Z(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] += distance;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance_X;
		m_matrix_rel[13] += distance_Y;
		m_matrix_rel[14] += distance_Z;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_XYZ(const GLfloat* const _KIWI_RESTRICT distance_XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += *distance_XYZ_ptr;
		m_matrix_rel[13] += *(distance_XYZ_ptr + 1);
		m_matrix_rel[14] += *(distance_XYZ_ptr + 2);
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_yaw(GLfloat yaw, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = yaw;
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_pitch(GLfloat pitch, bool condition) noexcept
{
	if (condition)
	{
		m_pitch = pitch;
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_roll(GLfloat roll, bool condition) noexcept
{
	if (condition)
	{
		m_roll = roll;
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::set_angles(GLfloat yaw, GLfloat pitch, GLfloat roll, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = yaw;
		m_pitch = pitch;
		m_roll = roll;
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_front(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_matrix_rel[0];
		m_matrix_rel[13] += distance * m_matrix_rel[1];
		m_matrix_rel[14] += distance * m_matrix_rel[2];
		m_matrix_rel[15] += distance * m_matrix_rel[3];
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_back(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_matrix_rel[0];
		m_matrix_rel[13] -= distance * m_matrix_rel[1];
		m_matrix_rel[14] -= distance * m_matrix_rel[2];
		m_matrix_rel[15] -= distance * m_matrix_rel[3];
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_matrix_rel[4];
		m_matrix_rel[13] += distance * m_matrix_rel[5];
		m_matrix_rel[14] += distance * m_matrix_rel[6];
		m_matrix_rel[15] += distance * m_matrix_rel[7];
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_matrix_rel[4];
		m_matrix_rel[13] -= distance * m_matrix_rel[5];
		m_matrix_rel[14] -= distance * m_matrix_rel[6];
		m_matrix_rel[15] -= distance * m_matrix_rel[7];
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_matrix_rel[8];
		m_matrix_rel[13] += distance * m_matrix_rel[9];
		m_matrix_rel[14] += distance * m_matrix_rel[10];
		m_matrix_rel[15] += distance * m_matrix_rel[11];
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_matrix_rel[8];
		m_matrix_rel[13] -= distance * m_matrix_rel[9];
		m_matrix_rel[14] -= distance * m_matrix_rel[10];
		m_matrix_rel[15] -= distance * m_matrix_rel[11];
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_front_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_cos_yaw;
		m_matrix_rel[13] += distance * m_sin_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_back_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_cos_yaw;
		m_matrix_rel[13] -= distance * m_sin_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_left_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_sin_yaw;
		m_matrix_rel[13] += distance * m_cos_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_right_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_sin_yaw;
		m_matrix_rel[13] -= distance * m_cos_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_up_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] += distance;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::move_down_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] -= distance;
		m_XYZ_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::turn_left(GLfloat angle, bool condition) noexcept
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

inline kiwi::model_3d& kiwi::model_3d::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw -= angle;
		while (m_yaw < pi) { m_yaw += pi_t2; }
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::turn_up(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_pitch += angle;
		while (m_pitch > pi) { m_pitch -= pi_t2; }
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::turn_down(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_pitch -= angle;
		while (m_pitch < pi) { m_pitch += pi_t2; }
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::tilt_left(GLfloat angle, bool condition) noexcept
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

inline kiwi::model_3d& kiwi::model_3d::tilt_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_roll -= angle;
		while (m_roll < pi) { m_roll += pi_t2; }
		m_angles_modified = true;
	}
	return *this;
}

inline kiwi::model_3d& kiwi::model_3d::eval() noexcept
{
	if (m_parent_model_ptr == nullptr)
	{
		if (m_XYZ_modified)
		{
			m_matrix_free[12] = m_matrix_rel[12];
			m_matrix_free[13] = m_matrix_rel[13];
			m_matrix_free[14] = m_matrix_rel[14];
			m_matrix_rel[15] = GL1;

			m_XYZ_modified = false;

			m_state_counter++;
		}

		if (m_angles_modified)
		{
			m_cos_yaw = std::cos(m_yaw);
			m_sin_yaw = std::sin(m_yaw);

			m_cos_pitch = std::cos(m_pitch);
			m_sin_pitch = std::sin(m_pitch);

			m_cos_roll = std::cos(m_roll);
			m_sin_roll = std::sin(m_roll);

			m_matrix_rel[0] = m_cos_yaw * m_cos_pitch;
			m_matrix_rel[1] = m_sin_yaw * m_cos_pitch;
			m_matrix_rel[2] = m_sin_pitch;

			m_matrix_rel[4] = m_cos_yaw * m_sin_pitch * m_sin_roll - m_sin_yaw * m_cos_roll;
			m_matrix_rel[5] = m_cos_yaw * m_cos_roll + m_sin_yaw * m_sin_pitch * m_sin_roll;
			m_matrix_rel[6] = -(m_cos_pitch * m_sin_roll);

			m_matrix_rel[8] = -(m_sin_yaw * m_sin_roll + m_cos_yaw * m_sin_pitch * m_cos_roll);
			m_matrix_rel[9] = m_cos_yaw * m_sin_roll - m_sin_yaw * m_sin_pitch * m_cos_roll;
			m_matrix_rel[10] = m_cos_pitch * m_cos_roll;

			for (std::size_t n = 0; n < 12; n++)
			{
				m_matrix_free[n] = m_matrix_rel[n];
			}

			m_angles_modified = false;

			m_state_counter++;
		}
	}
	else
	{
		m_parent_model_ptr->eval();

		if (m_parent_model_state_counter != m_parent_model_ptr->m_state_counter
			|| m_XYZ_modified || m_angles_modified)
		{
			if (m_angles_modified)
			{
				m_cos_yaw = std::cos(m_yaw);
				m_sin_yaw = std::sin(m_yaw);

				m_cos_pitch = std::cos(m_pitch);
				m_sin_pitch = std::sin(m_pitch);

				m_cos_roll = std::cos(m_roll);
				m_sin_roll = std::sin(m_roll);
			}

			m_matrix_rel[15] = GL1;

			m_matrix_rel[0] = m_cos_yaw * m_cos_pitch;
			m_matrix_rel[1] = m_sin_yaw * m_cos_pitch;
			m_matrix_rel[2] = m_sin_pitch;

			m_matrix_rel[4] = m_cos_yaw * m_sin_pitch * m_sin_roll - m_sin_yaw * m_cos_roll;
			m_matrix_rel[5] = m_cos_yaw * m_cos_roll + m_sin_yaw * m_sin_pitch * m_sin_roll;
			m_matrix_rel[6] = -(m_cos_pitch * m_sin_roll);

			m_matrix_rel[8] = -(m_sin_yaw * m_sin_roll + m_cos_yaw * m_sin_pitch * m_cos_roll);
			m_matrix_rel[9] = m_cos_yaw * m_sin_roll - m_sin_yaw * m_sin_pitch * m_cos_roll;
			m_matrix_rel[10] = m_cos_pitch * m_cos_roll;

			m44xm44(static_cast<GLfloat*>(m_matrix_free),
				static_cast<GLfloat*>(m_parent_model_ptr->m_matrix_free),
				static_cast<GLfloat*>(m_matrix_rel));

			m_parent_model_state_counter = m_parent_model_ptr->m_state_counter;

			m_XYZ_modified = false;
			m_angles_modified = false;

			m_state_counter++;
		}
	}

	return *this;
}


#endif // _KIWI_MODEL_3D_HPP