#include "space/kiwi_camera_2d.hpp"
#include "header_utils/kiwi_simd.hpp"


kiwi::camera_2d& kiwi::camera_2d::set_new_projection_matrix(GLfloat screen_ratio) noexcept
{
	if (screen_ratio > GL1)
	{
		m_X_factor = GL1 / screen_ratio;
		m_Y_factor = GL1;
	}
	else
	{
		m_X_factor = GL1;
		m_Y_factor = screen_ratio;
	}

	eval();
	return *this;
}

const GLfloat* kiwi::camera_2d::data() noexcept
{
	if (m_XY_modified  | m_angle_modified) { eval(); }
	return static_cast<const GLfloat*>(m_vp_matrix);
}

kiwi::camera_2d::operator const GLfloat* () noexcept
{
	if (m_XY_modified | m_angle_modified) { eval(); }
	return static_cast<const GLfloat*>(m_vp_matrix);
}

const GLfloat* kiwi::camera_2d::data(const GLfloat* const model_matrix_ptr) noexcept
{
	if (m_XY_modified | m_angle_modified) { eval(); }
	m33xm33(static_cast<GLfloat*>(m_mvp_matrix), static_cast<const GLfloat*>(m_vp_matrix), model_matrix_ptr);
	return static_cast<const GLfloat*>(m_mvp_matrix);
}

const GLfloat* kiwi::camera_2d::operator()(const GLfloat* const model_matrix_ptr) noexcept
{
	if (m_XY_modified | m_angle_modified) { eval(); }
	m33xm33(static_cast<GLfloat*>(m_mvp_matrix), static_cast<const GLfloat*>(m_vp_matrix), model_matrix_ptr);
	return static_cast<const GLfloat*>(m_mvp_matrix);
}

const GLfloat* kiwi::camera_2d::XY_data() noexcept
{
	return static_cast<const GLfloat*>(m_right_up_XY) + 6;
}

const GLfloat* kiwi::camera_2d::right_dir_data() noexcept
{
	if (m_angle_modified) { eval_angles(); }
	return static_cast<const GLfloat*>(m_right_up_XY);
}

const GLfloat* kiwi::camera_2d::up_dir_data() noexcept
{
	if (m_angle_modified) { eval_angles(); }
	return static_cast<const GLfloat*>(m_right_up_XY) + 3;
}

GLfloat kiwi::camera_2d::get_X() const noexcept
{
	return m_right_up_XY[6];
}

GLfloat kiwi::camera_2d::get_Y() const noexcept
{
	return m_right_up_XY[7];
}

GLfloat kiwi::camera_2d::get_angle() const noexcept
{
	return m_yaw;
}

GLfloat kiwi::camera_2d::get_scale() const noexcept
{
	return m_scale;
}

kiwi::camera_2d& kiwi::camera_2d::pick_XY(GLfloat X_screen, GLfloat Y_screen, GLfloat* XY_picked) noexcept
{
	GLfloat scale_inv = GL1 / m_scale;
	GLfloat XY_screen_rescaled[2] = { scale_inv * X_screen, scale_inv * Y_screen };

	*XY_picked = m_right_up_XY[0] * XY_screen_rescaled[0] + m_right_up_XY[3] * XY_screen_rescaled[1] + m_right_up_XY[6];
	*(XY_picked + 1) = m_right_up_XY[1] * XY_screen_rescaled[0] + m_right_up_XY[4] * XY_screen_rescaled[1] + m_right_up_XY[7];

	return *this;
}

const kiwi::camera_2d& kiwi::camera_2d::pick_XY(GLfloat X_screen, GLfloat Y_screen, GLfloat* XY_picked) const noexcept
{
	GLfloat scale_inv = GL1 / m_scale;
	GLfloat XY_screen_rescaled[2] = { scale_inv * X_screen, scale_inv * Y_screen };

	*XY_picked = m_right_up_XY[0] * XY_screen_rescaled[0] + m_right_up_XY[3] * XY_screen_rescaled[1] + m_right_up_XY[6];
	*(XY_picked + 1) = m_right_up_XY[1] * XY_screen_rescaled[0] + m_right_up_XY[4] * XY_screen_rescaled[1] + m_right_up_XY[7];

	return *this;
}

void kiwi::camera_2d::eval_angles() noexcept
{
	m_right_up_XY[0] = std::cos(m_yaw);
	m_right_up_XY[1] = std::sin(m_yaw);

	m_right_up_XY[3] = -m_right_up_XY[1];
	m_right_up_XY[4] = m_right_up_XY[0];

	m_angle_modified = false;
}

void kiwi::camera_2d::eval() noexcept
{
	m_right_up_XY[0] = std::cos(m_yaw);
	m_right_up_XY[1] = std::sin(m_yaw);

	m_right_up_XY[3] = -m_right_up_XY[1];
	m_right_up_XY[4] = m_right_up_XY[0];

	GLfloat m_X_factor_scaled = m_scale * m_X_factor;
	GLfloat m_Y_factor_scaled = m_scale * m_Y_factor;

	m_vp_matrix[0] = m_X_factor_scaled * m_right_up_XY[0];
	m_vp_matrix[1] = -(m_Y_factor_scaled * m_right_up_XY[1]);

	m_vp_matrix[3] = m_X_factor_scaled * m_right_up_XY[1];
	m_vp_matrix[4] = m_Y_factor_scaled * m_right_up_XY[0];

	m_vp_matrix[6] = -(m_X_factor_scaled * (m_right_up_XY[0] * m_right_up_XY[6] + m_right_up_XY[1] * m_right_up_XY[7]));
	m_vp_matrix[7] = m_Y_factor_scaled * (m_right_up_XY[1] * m_right_up_XY[6] - m_right_up_XY[0] * m_right_up_XY[7]);

	m_XY_modified = false;
	m_angle_modified = false;
}

void kiwi::camera_2d::m33xm33(GLfloat* _KIWI_RESTRICT pfC, const GLfloat* pfA, const GLfloat* pfB) const noexcept
{
#if defined(_KIWI_AVX2_FMA)
	__m128 vregA0 = _mm_loadu_ps(pfA);
	__m128 vregA1 = _mm_loadu_ps(pfA + 3);
	__m128 vregA2 = _mm_loadu_ps(pfA + 6);

	__m128 vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB));
	__m128 vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB + 3));
	union { __m128 v; float arr[4]; } vregC2;
	vregC2.v = _mm_mul_ps(vregA0, _mm_broadcast_ss(pfB + 6));

	vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 1), vregC0);
	vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 4), vregC1);
	vregC2.v = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pfB + 7), vregC2.v);

	vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 2), vregC0);
	vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 5), vregC1);
	vregC2.v = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 8), vregC2.v);

	_mm_storeu_ps(pfC, vregC0);
	_mm_storeu_ps(pfC + 3, vregC1);
	*(pfC + 6) = vregC2.arr[0];
	*(pfC + 7) = vregC2.arr[1];
	*(pfC + 8) = vregC2.arr[2];
#else // SIMD
	const GLfloat* pB = pfB;
	GLfloat* pC = pfC;
	GLfloat regB;
	for (std::size_t j = 0; j < 3; j++)
	{
		regB = *pB++;
		*pC = *pfA * regB;
		*(pC + 1) = *(pfA + 1) * regB;
		*(pC + 2) = *(pfA + 2) * regB;
		regB = *pB++;
		*pC += *(pfA + 3) * regB;
		*(pC + 1) += *(pfA + 4) * regB;
		*(pC + 2) += *(pfA + 5) * regB;
		regB = *pB++;
		*pC += *(pfA + 6) * regB;
		*(pC + 1) += *(pfA + 7) * regB;
		*(pC + 2) += *(pfA + 8) * regB;
		pC += 3;
	}
#endif // SIMD
}