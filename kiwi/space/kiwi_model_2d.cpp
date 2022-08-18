#include "space/kiwi_model_2d.hpp"
#include "header_utils/kiwi_simd.hpp"


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