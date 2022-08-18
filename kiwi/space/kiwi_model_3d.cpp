#include "space/kiwi_model_3d.hpp"
#include "header_utils/kiwi_simd.hpp"

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

	return *this;
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

void kiwi::model_3d::m44xm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept
{
#if defined(_KIWI_AVX2_FMA)
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
#if defined(_KIWI_AVX2_FMA)
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
