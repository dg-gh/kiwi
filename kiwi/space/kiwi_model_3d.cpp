#include "space/kiwi_model_3d.hpp"

#if defined(__AVX2__) && defined(__FMA__)
#ifndef _KIWI_AVX2_FMA
#define _KIWI_AVX2_FMA
#endif // _KIWI_AVX2_FMA
#include <immintrin.h>
#endif

GLfloat* kiwi::model_3d::data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

kiwi::model_3d& kiwi::model_3d::set_base_model(kiwi::model_3d* base_model_ptr) noexcept
{
	set_free();

	GLfloat X = m_matrix_rel[12] - base_model_ptr->m_matrix_free[12];
	GLfloat Y = m_matrix_rel[13] - base_model_ptr->m_matrix_free[13];
	GLfloat Z = m_matrix_rel[14] - base_model_ptr->m_matrix_free[14];

#if defined(_KIWI_AVX2_FMA)
	__m128 vfree0 = _mm_set_ps(m_matrix_free[0], m_matrix_free[4], m_matrix_free[8], 0.0f);
	__m128 vfree1 = _mm_set_ps(m_matrix_free[1], m_matrix_free[5], m_matrix_free[9], 0.0f);
	__m128 vfree2 = _mm_set_ps(m_matrix_free[2], m_matrix_free[6], m_matrix_free[10], 0.0f);

	__m128 vacc0 = _mm_mul_ps(vfree0, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel)));
	__m128 vacc1 = _mm_mul_ps(vfree0, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 4));
	__m128 vacc2 = _mm_mul_ps(vfree0, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 8));
	__m128 vacc3 = _mm_mul_ps(vfree0, _mm_broadcast_ss(&X));

	_mm_fmadd_ps(vfree1, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 1), vacc0);
	_mm_fmadd_ps(vfree1, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 5), vacc1);
	_mm_fmadd_ps(vfree1, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 9), vacc2);
	_mm_fmadd_ps(vfree1, _mm_broadcast_ss(&Y), vacc3);

	_mm_fmadd_ps(vfree2, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 2), vacc0);
	_mm_fmadd_ps(vfree2, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 6), vacc1);
	_mm_fmadd_ps(vfree2, _mm_broadcast_ss(static_cast<float*>(m_matrix_rel) + 10), vacc2);
	_mm_fmadd_ps(vfree2, _mm_broadcast_ss(&Z), vacc3);

	_mm_storeu_ps(static_cast<float*>(m_matrix_rel), vacc0);
	_mm_storeu_ps(static_cast<float*>(m_matrix_rel) + 4, vacc1);
	_mm_storeu_ps(static_cast<float*>(m_matrix_rel) + 8, vacc2);
	_mm_storeu_ps(static_cast<float*>(m_matrix_rel) + 12, vacc3);
#else // SIMD
	m_matrix_rel[0] = base_model_ptr->m_matrix_free[0] * m_matrix_rel[0] + base_model_ptr->m_matrix_free[1] * m_matrix_rel[1] + base_model_ptr->m_matrix_free[2] * m_matrix_rel[2];
	m_matrix_rel[1] = base_model_ptr->m_matrix_free[4] * m_matrix_rel[0] + base_model_ptr->m_matrix_free[5] * m_matrix_rel[1] + base_model_ptr->m_matrix_free[6] * m_matrix_rel[2];
	m_matrix_rel[2] = base_model_ptr->m_matrix_free[8] * m_matrix_rel[0] + base_model_ptr->m_matrix_free[9] * m_matrix_rel[1] + base_model_ptr->m_matrix_free[10] * m_matrix_rel[2];

	m_matrix_rel[4] = base_model_ptr->m_matrix_free[0] * m_matrix_rel[4] + base_model_ptr->m_matrix_free[1] * m_matrix_rel[5] + base_model_ptr->m_matrix_free[2] * m_matrix_rel[6];
	m_matrix_rel[5] = base_model_ptr->m_matrix_free[4] * m_matrix_rel[4] + base_model_ptr->m_matrix_free[5] * m_matrix_rel[5] + base_model_ptr->m_matrix_free[6] * m_matrix_rel[6];
	m_matrix_rel[6] = base_model_ptr->m_matrix_free[8] * m_matrix_rel[4] + base_model_ptr->m_matrix_free[9] * m_matrix_rel[5] + base_model_ptr->m_matrix_free[10] * m_matrix_rel[6];

	m_matrix_rel[8] = base_model_ptr->m_matrix_free[0] * m_matrix_rel[8] + base_model_ptr->m_matrix_free[1] * m_matrix_rel[9] + base_model_ptr->m_matrix_free[2] * m_matrix_rel[9];
	m_matrix_rel[9] = base_model_ptr->m_matrix_free[4] * m_matrix_rel[8] + base_model_ptr->m_matrix_free[5] * m_matrix_rel[9] + base_model_ptr->m_matrix_free[6] * m_matrix_rel[9];
	m_matrix_rel[10] = base_model_ptr->m_matrix_free[8] * m_matrix_rel[8] + base_model_ptr->m_matrix_free[9] * m_matrix_rel[9] + base_model_ptr->m_matrix_free[10] * m_matrix_rel[9];

	m_matrix_rel[12] = base_model_ptr->m_matrix_free[0] * X + base_model_ptr->m_matrix_free[1] * Y + base_model_ptr->m_matrix_free[2] * Z;
	m_matrix_rel[13] = base_model_ptr->m_matrix_free[4] * X + base_model_ptr->m_matrix_free[5] * Y + base_model_ptr->m_matrix_free[6] * Z;
	m_matrix_rel[14] = base_model_ptr->m_matrix_free[8] * X + base_model_ptr->m_matrix_free[9] * Y + base_model_ptr->m_matrix_free[10] * Z;
#endif // SIMD

	m_yaw = std::atan2(m_matrix_rel[1], m_matrix_rel[0]);
	m_pitch = std::atan2(m_matrix_rel[2], std::sqrt(m_matrix_rel[0] * m_matrix_rel[0] + m_matrix_rel[1] * m_matrix_rel[1]));
	m_roll = std::atan2(-m_matrix_rel[6], m_matrix_rel[10]);

	m_XYZ_modified = true;
	m_angles_modified = true;

	m_parent_model_ptr = base_model_ptr;
}

kiwi::model_3d* kiwi::model_3d::get_base_model() const noexcept
{
	return m_parent_model_ptr;
}

kiwi::model_3d& kiwi::model_3d::set_free() noexcept
{
	eval();

	if (m_parent_model_ptr != nullptr)
	{
		m_parent_model_ptr->eval();

		m_yaw = std::atan2(m_matrix_free[1], m_matrix_free[0]);
		m_pitch = std::atan2(m_matrix_free[2], std::sqrt(m_matrix_free[0] * m_matrix_free[0] + m_matrix_free[1] * m_matrix_free[1]));
		m_roll = std::atan2(-m_matrix_free[6], m_matrix_free[10]);

		for (std::size_t n = 0; n < 16; n++)
		{
			m_matrix_rel[n] = m_matrix_free[n];
		}

		m_parent_model_ptr = nullptr;
	}

	return *this;
}

GLfloat* kiwi::model_3d::front_dir_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel);
}

GLfloat* kiwi::model_3d::left_dir_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel) + 4;
}

GLfloat* kiwi::model_3d::up_dir_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel) + 8;
}

GLfloat* kiwi::model_3d::front_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

GLfloat* kiwi::model_3d::left_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 4;
}

GLfloat* kiwi::model_3d::up_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 8;
}

GLfloat kiwi::model_3d::get_X() const noexcept
{
	return m_matrix_rel[12];
}

GLfloat kiwi::model_3d::get_Y() const noexcept
{
	return m_matrix_rel[13];
}

GLfloat kiwi::model_3d::get_Z() const noexcept
{
	return m_matrix_rel[14];
}

const GLfloat* kiwi::model_3d::XYZ_data() noexcept
{
	return static_cast<const GLfloat*>(m_matrix_rel) + 12;
}

GLfloat kiwi::model_3d::get_yaw() const noexcept
{
	return m_yaw;
}

GLfloat kiwi::model_3d::get_pitch() const noexcept
{
	return m_pitch;
}

GLfloat kiwi::model_3d::get_roll() const noexcept
{
	return m_roll;
}

GLfloat kiwi::model_3d::get_X_free() noexcept
{
	eval();
	return m_matrix_free[12];
}

GLfloat kiwi::model_3d::get_Y_free() noexcept
{
	eval();
	return m_matrix_free[13];
}

GLfloat kiwi::model_3d::get_Z_free() noexcept
{
	eval();
	return m_matrix_free[14];
}

const GLfloat* kiwi::model_3d::XYZ_data_free() noexcept
{
	eval();
	return static_cast<const GLfloat*>(m_matrix_free) + 12;
}

GLfloat kiwi::model_3d::get_yaw_free() noexcept
{
	eval();
	return std::atan2(m_matrix_free[1], m_matrix_free[0]);
}

GLfloat kiwi::model_3d::get_pitch_free() noexcept
{
	eval();
	return std::atan2(m_matrix_free[2], std::sqrt(m_matrix_free[0] * m_matrix_free[0] + m_matrix_free[1] * m_matrix_free[1]));
}

GLfloat kiwi::model_3d::get_roll_free() noexcept
{
	eval();
	return std::atan2(-m_matrix_free[6], m_matrix_free[10]);
}

kiwi::model_3d& kiwi::model_3d::set_X(GLfloat X) noexcept
{
	m_matrix_rel[12] = X;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_Y(GLfloat Y) noexcept
{
	m_matrix_rel[13] = Y;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_Z(GLfloat Z) noexcept
{
	m_matrix_rel[14] = Z;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	m_matrix_rel[12] = X;
	m_matrix_rel[13] = Y;
	m_matrix_rel[14] = Z;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_matrix_rel[12] = *XYZ_ptr;
	m_matrix_rel[13] = *(XYZ_ptr + 1);
	m_matrix_rel[14] = *(XYZ_ptr + 2);
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_yaw(GLfloat yaw) noexcept
{
	m_yaw = yaw;
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_pitch(GLfloat pitch) noexcept
{
	m_pitch = pitch;
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_roll(GLfloat roll) noexcept
{
	m_roll = roll;
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_angles(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept
{
	m_yaw = yaw;
	m_pitch = pitch;
	m_roll = roll;
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_front(GLfloat distance) noexcept
{
	m_matrix_rel[12] += distance * m_matrix_rel[0];
	m_matrix_rel[13] += distance * m_matrix_rel[1];
	m_matrix_rel[14] += distance * m_matrix_rel[2];
	m_matrix_rel[15] += distance * m_matrix_rel[3];
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_back(GLfloat distance) noexcept
{
	m_matrix_rel[12] -= distance * m_matrix_rel[0];
	m_matrix_rel[13] -= distance * m_matrix_rel[1];
	m_matrix_rel[14] -= distance * m_matrix_rel[2];
	m_matrix_rel[15] -= distance * m_matrix_rel[3];
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_left(GLfloat distance) noexcept
{
	m_matrix_rel[12] += distance * m_matrix_rel[4];
	m_matrix_rel[13] += distance * m_matrix_rel[5];
	m_matrix_rel[14] += distance * m_matrix_rel[6];
	m_matrix_rel[15] += distance * m_matrix_rel[7];
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_right(GLfloat distance) noexcept
{
	m_matrix_rel[12] -= distance * m_matrix_rel[4];
	m_matrix_rel[13] -= distance * m_matrix_rel[5];
	m_matrix_rel[14] -= distance * m_matrix_rel[6];
	m_matrix_rel[15] -= distance * m_matrix_rel[7];
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_up(GLfloat distance) noexcept
{
	m_matrix_rel[12] += distance * m_matrix_rel[8];
	m_matrix_rel[13] += distance * m_matrix_rel[9];
	m_matrix_rel[14] += distance * m_matrix_rel[10];
	m_matrix_rel[15] += distance * m_matrix_rel[11];
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_down(GLfloat distance) noexcept
{
	m_matrix_rel[12] -= distance * m_matrix_rel[8];
	m_matrix_rel[13] -= distance * m_matrix_rel[9];
	m_matrix_rel[14] -= distance * m_matrix_rel[10];
	m_matrix_rel[15] -= distance * m_matrix_rel[11];
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_front_h(GLfloat distance) noexcept
{
	m_matrix_rel[12] += distance * m_cos_yaw;
	m_matrix_rel[13] += distance * m_sin_yaw;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_back_h(GLfloat distance) noexcept
{
	m_matrix_rel[12] -= distance * m_cos_yaw;
	m_matrix_rel[13] -= distance * m_sin_yaw;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_left_h(GLfloat distance) noexcept
{
	m_matrix_rel[12] -= distance * m_sin_yaw;
	m_matrix_rel[13] += distance * m_cos_yaw;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_right_h(GLfloat distance) noexcept
{
	m_matrix_rel[12] += distance * m_sin_yaw;
	m_matrix_rel[13] -= distance * m_cos_yaw;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_up_h(GLfloat distance) noexcept
{
	m_matrix_rel[14] += distance;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_down_h(GLfloat distance) noexcept
{
	m_matrix_rel[14] -= distance;
	m_XYZ_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::turn_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw += angle;
	while (m_yaw > pi) { m_yaw -= pi_t2; }
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::turn_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw -= angle;
	while (m_yaw < pi) { m_yaw += pi_t2; }
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::turn_up(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_pitch += angle;
	while (m_pitch > pi) { m_pitch -= pi_t2; }
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::turn_down(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_pitch -= angle;
	while (m_pitch < pi) { m_pitch += pi_t2; }
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::tilt_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_roll += angle;
	while (m_roll > pi) { m_roll -= pi_t2; }
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::tilt_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_roll -= angle;
	while (m_roll < pi) { m_roll += pi_t2; }
	m_angles_modified = true;
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] = X;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[13] = Y;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_Z(GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] = Z;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::set_XYZ(const GLfloat* const XYZ_ptr, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::set_yaw(GLfloat yaw, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = yaw;
		m_angles_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_pitch(GLfloat pitch, bool condition) noexcept
{
	if (condition)
	{
		m_pitch = pitch;
		m_angles_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_roll(GLfloat roll, bool condition) noexcept
{
	if (condition)
	{
		m_roll = roll;
		m_angles_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::set_angles(GLfloat yaw, GLfloat pitch, GLfloat roll, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_front(GLfloat distance, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_back(GLfloat distance, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_left(GLfloat distance, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_right(GLfloat distance, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_up(GLfloat distance, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_down(GLfloat distance, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::move_front_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_cos_yaw;
		m_matrix_rel[13] += distance * m_sin_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_back_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_cos_yaw;
		m_matrix_rel[13] -= distance * m_sin_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_left_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] -= distance * m_sin_yaw;
		m_matrix_rel[13] += distance * m_cos_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_right_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[12] += distance * m_sin_yaw;
		m_matrix_rel[13] -= distance * m_cos_yaw;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_up_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] += distance;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::move_down_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[14] -= distance;
		m_XYZ_modified = true;
	}
	return *this;
}

kiwi::model_3d& kiwi::model_3d::turn_left(GLfloat angle, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::turn_right(GLfloat angle, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::turn_up(GLfloat angle, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::turn_down(GLfloat angle, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::tilt_left(GLfloat angle, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::tilt_right(GLfloat angle, bool condition) noexcept
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

kiwi::model_3d& kiwi::model_3d::eval() noexcept
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

void kiwi::model_3d::m44xm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	__m128 vregA0 = _mm_loadu_ps(pfA);
	__m128 vregA1 = _mm_loadu_ps(pfA + 4);
	__m128 vregA2 = _mm_loadu_ps(pfA + 8);
	__m128 vregA3 = _mm_loadu_ps(pfA + 12);

	__m128 vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB));
	__m128 vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB + 4));
	vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 1), vregC0);
	vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 5), vregC1);
	vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 2), vregC0);
	vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 6), vregC1);
	vregC0 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pfB + 3), vregC0);
	vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pfB + 7), vregC1);
	_mm_storeu_ps(pfC, vregC0);
	_mm_storeu_ps(pfC + 4, vregC1);

	vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB + 8));
	vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB + 12));
	vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 9), vregC0);
	vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 13), vregC1);
	vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 10), vregC0);
	vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 14), vregC1);
	vregC0 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pfB + 11), vregC0);
	vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pfB + 15), vregC1);
	_mm_storeu_ps(pfC + 8, vregC0);
	_mm_storeu_ps(pfC + 12, vregC1);
#else // SIMD
	const GLfloat* pB = pfB;
	GLfloat* pC = pfC;
	GLfloat regB0; GLfloat regB1;
	for (std::size_t j = 0; j < 4; j++)
	{
		regB0 = *pB++;
		*pC = *pfA * regB0;
		*(pC + 1) = *(pfA + 1) * regB0;
		*(pC + 2) = *(pfA + 2) * regB0;
		*(pC + 3) = *(pfA + 3) * regB0;
		regB1 = *pB++;
		*pC += *(pfA + 4) * regB1;
		*(pC + 1) += *(pfA + 5) * regB1;
		*(pC + 2) += *(pfA + 6) * regB1;
		*(pC + 3) += *(pfA + 7) * regB1;
		regB0 = *pB++;
		*pC += *(pfA + 8) * regB0;
		*(pC + 1) += *(pfA + 9) * regB0;
		*(pC + 2) += *(pfA + 10) * regB0;
		*(pC + 3) += *(pfA + 11) * regB0;
		regB1 = *pB++;
		*pC += *(pfA + 12) * regB1;
		*(pC + 1) += *(pfA + 13) * regB1;
		*(pC + 2) += *(pfA + 14) * regB1;
		*(pC + 3) += *(pfA + 15) * regB1;
		pC += 4;
	}
#endif // SIMD
}

void kiwi::model_3d::m44xv4(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	__m128 vregC = _mm_mul_ps(_mm_loadu_ps(pfA), _mm_broadcast_ss(pfB));
	vregC = _mm_fmadd_ps(_mm_loadu_ps(pfA + 4), _mm_broadcast_ss(pfB + 1), vregC);
	vregC = _mm_fmadd_ps(_mm_loadu_ps(pfA + 8), _mm_broadcast_ss(pfB + 2), vregC);
	vregC = _mm_fmadd_ps(_mm_loadu_ps(pfA + 12), _mm_broadcast_ss(pfB + 3), vregC);
	_mm_storeu_ps(pfC, vregC);
#else // SIMD
	const GLfloat* pB = pfB;
	GLfloat regB0; GLfloat regB1;
	regB0 = *pB++;
	*pfC = *pfA * regB0;
	*(pfC + 1) = *(pfA + 1) * regB0;
	*(pfC + 2) = *(pfA + 2) * regB0;
	*(pfC + 3) = *(pfA + 3) * regB0;
	regB1 = *pB++;
	*pfC += *(pfA + 4) * regB1;
	*(pfC + 1) += *(pfA + 5) * regB1;
	*(pfC + 2) += *(pfA + 6) * regB1;
	*(pfC + 3) += *(pfA + 7) * regB1;
	regB0 = *pB++;
	*pfC += *(pfA + 8) * regB0;
	*(pfC + 1) += *(pfA + 9) * regB0;
	*(pfC + 2) += *(pfA + 10) * regB0;
	*(pfC + 3) += *(pfA + 11) * regB0;
	regB1 = *pB;
	*pfC += *(pfA + 12) * regB1;
	*(pfC + 1) += *(pfA + 13) * regB1;
	*(pfC + 2) += *(pfA + 14) * regB1;
	*(pfC + 3) += *(pfA + 15) * regB1;
#endif // SIMD
}
