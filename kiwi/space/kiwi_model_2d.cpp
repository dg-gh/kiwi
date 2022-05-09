#include "space/kiwi_model_2d.hpp"

#if defined(__AVX2__) && defined(__FMA__)
#ifndef _KIWI_AVX2_FMA
#define _KIWI_AVX2_FMA
#endif // _KIWI_AVX2_FMA
#include <immintrin.h>
#endif


GLfloat* kiwi::model_2d::data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

kiwi::model_2d& kiwi::model_2d::set_base_model(kiwi::model_2d* base_model_ptr) noexcept
{
	set_free();

	base_model_ptr->eval();

	GLfloat X = m_matrix_rel[6] - base_model_ptr->m_matrix_free[6];
	GLfloat Y = m_matrix_rel[7] - base_model_ptr->m_matrix_free[7];
	m_matrix_rel[6] = base_model_ptr->m_matrix_free[0] * X + base_model_ptr->m_matrix_free[1] * Y;
	m_matrix_rel[7] = base_model_ptr->m_matrix_free[3] * X + base_model_ptr->m_matrix_free[4] * Y;

	kiwi::model_2d* model_ptr = base_model_ptr;
	m_yaw -= model_ptr->m_yaw;
	while (model_ptr->m_parent_model_ptr != nullptr)
	{
		model_ptr = model_ptr->m_parent_model_ptr;
		m_yaw -= model_ptr->m_yaw;
	}
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	while (m_yaw < -pi) { m_yaw += pi_t2; }

	m_XY_modified = true;
	m_angle_modified = true;

	m_parent_model_ptr = base_model_ptr;

	return eval();
}

kiwi::model_2d* kiwi::model_2d::get_base_model() const noexcept
{
	return m_parent_model_ptr;
}

kiwi::model_2d& kiwi::model_2d::set_free() noexcept
{
	if (m_parent_model_ptr != nullptr)
	{
		m_parent_model_ptr->eval();

		GLfloat X = m_matrix_rel[6];
		GLfloat Y = m_matrix_rel[7];
		m_matrix_rel[6] = m_parent_model_ptr->m_matrix_free[0] * X + m_parent_model_ptr->m_matrix_free[3] * Y + m_parent_model_ptr->m_matrix_free[6];
		m_matrix_rel[7] = m_parent_model_ptr->m_matrix_free[1] * X + m_parent_model_ptr->m_matrix_free[4] * Y + m_parent_model_ptr->m_matrix_free[7];

		kiwi::model_2d* model_ptr = m_parent_model_ptr;
		m_yaw += model_ptr->m_yaw;
		while (model_ptr->m_parent_model_ptr != nullptr)
		{
			model_ptr = model_ptr->m_parent_model_ptr;
			m_yaw += model_ptr->m_yaw;
		}
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		if (m_yaw >= GL0)
		{
			while (m_yaw > pi) { m_yaw -= pi_t2; }
		}
		else
		{
			while (m_yaw < -pi) { m_yaw += pi_t2; }
		}

		m_XY_modified = true;
		m_angle_modified = true;

		m_parent_model_ptr = nullptr;
	}

	return eval();
}

GLfloat* kiwi::model_2d::front_dir_data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_rel);
}

GLfloat* kiwi::model_2d::left_dir_data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_rel) + 3;
}

GLfloat* kiwi::model_2d::front_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

GLfloat* kiwi::model_2d::left_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 3;
}

GLfloat kiwi::model_2d::get_X() const noexcept
{
	return m_matrix_rel[6];
}

GLfloat kiwi::model_2d::get_Y() const noexcept
{
	return m_matrix_rel[7];
}

GLfloat* kiwi::model_2d::XY_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel) + 6;
}

GLfloat kiwi::model_2d::get_angle() const noexcept
{
	return m_yaw;
}

GLfloat kiwi::model_2d::get_X_free() noexcept
{
	eval();
	return m_matrix_free[6];
}

GLfloat kiwi::model_2d::get_Y_free() noexcept
{
	eval();
	return m_matrix_free[7];
}

GLfloat* kiwi::model_2d::XY_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 6;
}

GLfloat kiwi::model_2d::get_angle_free() noexcept
{
	GLfloat yaw = m_yaw;
	kiwi::model_2d* model_ptr = this;
	while (model_ptr->m_parent_model_ptr != nullptr)
	{
		model_ptr = model_ptr->m_parent_model_ptr;
		yaw += model_ptr->m_yaw;
	}
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	while (yaw > pi) { yaw -= pi_t2; }
	return yaw;
}

kiwi::model_2d& kiwi::model_2d::set_X(GLfloat X) noexcept
{
	m_matrix_rel[6] = X;
	m_XY_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_Y(GLfloat Y) noexcept
{
	m_matrix_rel[7] = Y;
	m_XY_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_XY(GLfloat X, GLfloat Y) noexcept
{
	m_matrix_rel[6] = X;
	m_matrix_rel[7] = Y;
	m_XY_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_matrix_rel[6] = *XY_ptr;
	m_matrix_rel[7] = *(XY_ptr + 1);
	m_XY_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_angle(GLfloat angle) noexcept
{
	m_yaw = angle;
	m_angle_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::turn_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw += angle;
	while (m_yaw > pi) { m_yaw -= pi_t2; }
	m_angle_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::turn_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw -= angle;
	while (m_yaw < -pi) { m_yaw += pi_t2; }
	m_angle_modified = true;
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_front(GLfloat distance) noexcept
{
	m_matrix_rel[6] += distance * m_matrix_rel[0];
	m_matrix_rel[7] += distance * m_matrix_rel[1];
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_back(GLfloat distance) noexcept
{
	m_matrix_rel[6] -= distance * m_matrix_rel[0];
	m_matrix_rel[7] -= distance * m_matrix_rel[1];
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_left(GLfloat distance) noexcept
{
	m_matrix_rel[6] -= distance * m_matrix_rel[1];
	m_matrix_rel[7] += distance * m_matrix_rel[0];
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_right(GLfloat distance) noexcept
{
	m_matrix_rel[6] += distance * m_matrix_rel[1];
	m_matrix_rel[7] -= distance * m_matrix_rel[0];
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] = X;
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[7] = Y;
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_XY(GLfloat X, GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] = X;
		m_matrix_rel[7] = Y;
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_XY(const GLfloat* const XY_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] = *XY_ptr;
		m_matrix_rel[7] = *(XY_ptr + 1);
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::set_angle(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = angle;
		m_angle_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::turn_left(GLfloat angle, bool condition) noexcept
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

kiwi::model_2d& kiwi::model_2d::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw -= angle;
		while (m_yaw < -pi) { m_yaw += pi_t2; }
		m_angle_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_front(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += distance * m_matrix_rel[0];
		m_matrix_rel[7] += distance * m_matrix_rel[1];
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_back(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] -= distance * m_matrix_rel[0];
		m_matrix_rel[7] -= distance * m_matrix_rel[1];
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] -= distance * m_matrix_rel[1];
		m_matrix_rel[7] += distance * m_matrix_rel[0];
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += distance * m_matrix_rel[1];
		m_matrix_rel[7] -= distance * m_matrix_rel[0];
		m_XY_modified = true;
	}
	return *this;
}

kiwi::model_2d& kiwi::model_2d::eval() noexcept
{
	if (m_parent_model_ptr == nullptr)
	{
		if (m_XY_modified)
		{
			m_matrix_free[6] = m_matrix_rel[6];
			m_matrix_free[7] = m_matrix_rel[7];

			m_XY_modified = false;

			m_state_counter++;
		}

		if (m_angle_modified)
		{
			m_matrix_rel[0] = std::cos(m_yaw);
			m_matrix_rel[1] = std::sin(m_yaw);

			m_matrix_rel[3] = -m_matrix_rel[1];
			m_matrix_rel[4] = m_matrix_rel[0];

			m_matrix_free[0] = m_matrix_rel[0];
			m_matrix_free[1] = m_matrix_rel[1];
			m_matrix_free[2] = m_matrix_rel[2];
			m_matrix_free[3] = m_matrix_rel[3];
			m_matrix_free[4] = m_matrix_rel[4];

			m_angle_modified = false;

			m_state_counter++;
		}
	}
	else
	{
		m_parent_model_ptr->eval();

		if (m_parent_model_state_counter != m_parent_model_ptr->m_state_counter
			|| m_XY_modified || m_angle_modified)
		{
			if (m_angle_modified)
			{
				m_matrix_rel[0] = std::cos(m_yaw);
				m_matrix_rel[1] = std::sin(m_yaw);

				m_matrix_rel[3] = -m_matrix_rel[1];
				m_matrix_rel[4] = m_matrix_rel[0];
			}

			m33xm33(static_cast<GLfloat*>(m_matrix_free),
				static_cast<GLfloat*>(m_parent_model_ptr->m_matrix_free),
				static_cast<GLfloat*>(m_matrix_rel));

			m_parent_model_state_counter = m_parent_model_ptr->m_state_counter;

			m_XY_modified = false;
			m_angle_modified = false;

			m_state_counter++;
		}
	}

	return *this;
}

void kiwi::model_2d::m33xm33(GLfloat* const _KIWI_RESTRICT pC, const GLfloat* const pA, const GLfloat* const pB) noexcept
{
#if defined(_KIWI_AVX2_FMA)
	__m128 vregA0 = _mm_loadu_ps(pA);
	__m128 vregA1 = _mm_loadu_ps(pA + 3);
	__m128 vregA2 = _mm_loadu_ps(pA + 6);

	__m128 vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB));
	__m128 vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 3));
	union { __m128 v; float arr[4]; } vregC2;
	vregC2.v = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 6));

	vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 1), vregC0);
	vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 4), vregC1);
	vregC2.v = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 7), vregC2.v);

	vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 2), vregC0);
	vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 5), vregC1);
	vregC2.v = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 8), vregC2.v);

	_mm_storeu_ps(pC, vregC0);
	_mm_storeu_ps(pC + 3, vregC1);
	*(pC + 6) = vregC2.arr[0];
	*(pC + 7) = vregC2.arr[1];
	*(pC + 8) = vregC2.arr[2];
#else // SIMD
	GLfloat regB;
	for (std::size_t j = 0; j < 3; j++)
	{
		std::size_t offset = 3 * j;
		regB = *(pB + offset);
		*(pC + offset) = *pA * regB;
		*(pC + (offset + 1)) = *(pA + 1) * regB;
		*(pC + (offset + 2)) = *(pA + 2) * regB;
		regB = *(pB + (offset + 1));
		*(pC + offset) += *(pA + 3) * regB;
		*(pC + (offset + 1)) += *(pA + 4) * regB;
		*(pC + (offset + 2)) += *(pA + 5) * regB;
		regB = *(pB + (offset + 2));
		*(pC + offset) += *(pA + 6) * regB;
		*(pC + (offset + 1)) += *(pA + 7) * regB;
		*(pC + (offset + 2)) += *(pA + 8) * regB;
	}
#endif // SIMD
}