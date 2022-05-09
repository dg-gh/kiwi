#include "space/kiwi_camera_2d.hpp"

#if defined(__AVX2__) && defined(__FMA__)
#ifndef _KIWI_AVX2_FMA
#define _KIWI_AVX2_FMA
#endif // _KIWI_AVX2_FMA
#include <immintrin.h>
#endif


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

const GLfloat* kiwi::camera_2d::data() const noexcept
{
	return static_cast<const GLfloat*>(m_vp_matrix);
}

const GLfloat* kiwi::camera_2d::data(const GLfloat* const model_matrix_ptr) noexcept
{
	m33xm33(static_cast<GLfloat*>(m_mvp_matrix), static_cast<const GLfloat*>(m_vp_matrix), model_matrix_ptr);
	return static_cast<const GLfloat*>(m_mvp_matrix);
}

const GLfloat* kiwi::camera_2d::data(kiwi::model_2d& model) noexcept
{
	m33xm33(static_cast<GLfloat*>(m_mvp_matrix), static_cast<const GLfloat*>(m_vp_matrix), model.data());
	return static_cast<const GLfloat*>(m_mvp_matrix);
}

const GLfloat* kiwi::camera_2d::XY_data() const noexcept
{
	return static_cast<const GLfloat*>(m_right_up_XY) + 6;
}

const GLfloat* kiwi::camera_2d::right_dir_data() const noexcept
{
	return static_cast<const GLfloat*>(m_right_up_XY);
}

const GLfloat* kiwi::camera_2d::up_dir_data() const noexcept
{
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

kiwi::_camera_2d_proxy kiwi::camera_2d::set_X(GLfloat X) noexcept
{
	m_right_up_XY[6] = X;

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_Y(GLfloat Y) noexcept
{
	m_right_up_XY[7] = Y;

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_XY(GLfloat X, GLfloat Y) noexcept
{
	m_right_up_XY[6] = X;
	m_right_up_XY[7] = Y;

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_right_up_XY[6] = *XY_ptr;
	m_right_up_XY[7] = *(XY_ptr + 1);

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_angle(GLfloat angle) noexcept
{
	m_yaw = angle;

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_scale(GLfloat scale) noexcept
{
	m_scale = scale;

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::turn_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw += angle;
	while (m_yaw > pi) { m_yaw -= pi_t2; }

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::turn_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw -= angle;
	while (m_yaw < -pi) { m_yaw += pi_t2; }

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_left(GLfloat distance) noexcept
{
	m_right_up_XY[6] -= distance * m_right_up_XY[0];
	m_right_up_XY[7] -= distance * m_right_up_XY[1];

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_right(GLfloat distance) noexcept
{
	m_right_up_XY[6] += distance * m_right_up_XY[0];
	m_right_up_XY[7] += distance * m_right_up_XY[1];

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_up(GLfloat distance) noexcept
{
	m_right_up_XY[6] -= distance * m_right_up_XY[1];
	m_right_up_XY[7] += distance * m_right_up_XY[0];

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_down(GLfloat distance) noexcept
{
	m_right_up_XY[6] += distance * m_right_up_XY[1];
	m_right_up_XY[7] -= distance * m_right_up_XY[0];

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition) { m_right_up_XY[6] = X; }

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition) { m_right_up_XY[7] = Y; }

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_XY(GLfloat X, GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] = X;
		m_right_up_XY[7] = Y;
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_XY(const GLfloat* const XY_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] = *XY_ptr;
		m_right_up_XY[7] = *(XY_ptr + 1);
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_angle(GLfloat angle, bool condition) noexcept
{
	if (condition) { m_yaw = angle; }

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::set_scale(GLfloat scale, bool condition) noexcept
{
	if (condition) { m_scale = scale; }

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::turn_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw += angle;
		while (m_yaw > pi) { m_yaw -= pi_t2; }
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw -= angle;
		while (m_yaw < -pi) { m_yaw += pi_t2; }
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] -= distance * m_right_up_XY[0];
		m_right_up_XY[7] -= distance * m_right_up_XY[1];
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

bool kiwi::camera_2d::in_view(const GLfloat* const object_XY_ptr) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_XY_ptr[0] + m_vp_matrix[3] * object_XY_ptr[1] + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_XY_ptr[0] + m_vp_matrix[4] * object_XY_ptr[1] + m_vp_matrix[7];
	return ((-m_X_factor <= X_screen) & (X_screen <= m_X_factor)) & ((-m_Y_factor <= Y_screen) & (Y_screen <= m_Y_factor));
}

bool kiwi::camera_2d::in_view(GLfloat object_X, GLfloat object_Y) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_X + m_vp_matrix[3] * object_Y + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_X + m_vp_matrix[4] * object_Y + m_vp_matrix[7];
	return ((-m_X_factor <= X_screen) & (X_screen <= m_X_factor)) & ((-m_Y_factor <= Y_screen) & (Y_screen <= m_Y_factor));
}

bool kiwi::camera_2d::in_view(const GLfloat* const object_XY_ptr, GLfloat object_radius) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_XY_ptr[0] + m_vp_matrix[3] * object_XY_ptr[1] + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_XY_ptr[0] + m_vp_matrix[4] * object_XY_ptr[1] + m_vp_matrix[7];
	GLfloat X_bound = m_X_factor + object_radius;
	GLfloat Y_bound = m_Y_factor + object_radius;
	return ((-X_bound <= X_screen) & (X_screen <= X_bound)) & ((-Y_bound <= Y_screen) & (Y_screen <= Y_bound));
}

bool kiwi::camera_2d::in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_radius) noexcept
{
	GLfloat X_screen = m_vp_matrix[0] * object_X + m_vp_matrix[3] * object_Y + m_vp_matrix[6];
	GLfloat Y_screen = m_vp_matrix[1] * object_X + m_vp_matrix[4] * object_Y + m_vp_matrix[7];
	GLfloat X_bound = m_X_factor + object_radius;
	GLfloat Y_bound = m_Y_factor + object_radius;
	return ((-X_bound <= X_screen) & (X_screen <= X_bound)) & ((-Y_bound <= Y_screen) & (Y_screen <= Y_bound));
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

	m_vp_matrix[6] = m_X_factor_scaled * (-(m_right_up_XY[0] * m_right_up_XY[6] + m_right_up_XY[1] * m_right_up_XY[7]));
	m_vp_matrix[7] = m_Y_factor_scaled * (m_right_up_XY[1] * m_right_up_XY[6] - m_right_up_XY[0] * m_right_up_XY[7]);
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

kiwi::_camera_2d_proxy kiwi::camera_2d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] += distance * m_right_up_XY[0];
		m_right_up_XY[7] += distance * m_right_up_XY[1];
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] -= distance * m_right_up_XY[1];
		m_right_up_XY[7] += distance * m_right_up_XY[0];
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy kiwi::camera_2d::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_right_up_XY[6] += distance * m_right_up_XY[1];
		m_right_up_XY[7] -= distance * m_right_up_XY[0];
	}

	kiwi::_camera_2d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_2d_proxy::~_camera_2d_proxy()
{
	m_parent_ptr->eval();
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_X(GLfloat X) noexcept
{
	m_parent_ptr->m_right_up_XY[6] = X;
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_Y(GLfloat Y) noexcept
{
	m_parent_ptr->m_right_up_XY[7] = Y;
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_XY(GLfloat X, GLfloat new_Y) noexcept
{
	m_parent_ptr->m_right_up_XY[6] = X;
	m_parent_ptr->m_right_up_XY[7] = new_Y;
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_parent_ptr->m_right_up_XY[6] = *XY_ptr;
	m_parent_ptr->m_right_up_XY[7] = *(XY_ptr + 1);
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_angle(GLfloat angle) noexcept
{
	m_parent_ptr->m_yaw = angle;
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_scale(GLfloat scale) noexcept
{
	m_parent_ptr->m_scale = scale;
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::turn_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_parent_ptr->m_yaw += angle;
	while (m_parent_ptr->m_yaw > pi) { m_parent_ptr->m_yaw -= pi_t2; }
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::turn_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_parent_ptr->m_yaw -= angle;
	while (m_parent_ptr->m_yaw < -pi) { m_parent_ptr->m_yaw += pi_t2; }
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_left(GLfloat distance) noexcept
{
	m_parent_ptr->m_right_up_XY[6] -= distance * m_parent_ptr->m_right_up_XY[0];
	m_parent_ptr->m_right_up_XY[7] -= distance * m_parent_ptr->m_right_up_XY[1];
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_right(GLfloat distance) noexcept
{
	m_parent_ptr->m_right_up_XY[6] += distance * m_parent_ptr->m_right_up_XY[0];
	m_parent_ptr->m_right_up_XY[7] += distance * m_parent_ptr->m_right_up_XY[1];
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_up(GLfloat distance) noexcept
{
	m_parent_ptr->m_right_up_XY[6] -= distance * m_parent_ptr->m_right_up_XY[1];
	m_parent_ptr->m_right_up_XY[7] += distance * m_parent_ptr->m_right_up_XY[0];
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_down(GLfloat distance) noexcept
{
	m_parent_ptr->m_right_up_XY[6] += distance * m_parent_ptr->m_right_up_XY[1];
	m_parent_ptr->m_right_up_XY[7] -= distance * m_parent_ptr->m_right_up_XY[0];
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::turn_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_parent_ptr->m_yaw += angle;
		while (m_parent_ptr->m_yaw > pi) { m_parent_ptr->m_yaw -= pi_t2; }
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_parent_ptr->m_yaw -= angle;
		while (m_parent_ptr->m_yaw < -pi) { m_parent_ptr->m_yaw += pi_t2; }
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_right_up_XY[6] -= distance * m_parent_ptr->m_right_up_XY[0];
		m_parent_ptr->m_right_up_XY[7] -= distance * m_parent_ptr->m_right_up_XY[1];
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_right_up_XY[6] += distance * m_parent_ptr->m_right_up_XY[0];
		m_parent_ptr->m_right_up_XY[7] += distance * m_parent_ptr->m_right_up_XY[1];
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_right_up_XY[6] -= distance * m_parent_ptr->m_right_up_XY[1];
		m_parent_ptr->m_right_up_XY[7] += distance * m_parent_ptr->m_right_up_XY[0];
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_right_up_XY[6] += distance * m_parent_ptr->m_right_up_XY[1];
		m_parent_ptr->m_right_up_XY[7] -= distance * m_parent_ptr->m_right_up_XY[0];
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_X(GLfloat X, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_right_up_XY[6] = X; }
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_right_up_XY[7] = Y; }
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_XY(GLfloat X, GLfloat new_Y, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_right_up_XY[6] = X;
		m_parent_ptr->m_right_up_XY[7] = new_Y;
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_XY(const GLfloat* const XY_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_right_up_XY[6] = *XY_ptr;
		m_parent_ptr->m_right_up_XY[7] = *(XY_ptr + 1);
	}
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_angle(GLfloat angle, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_yaw = angle; }
	return *this;
}

kiwi::_camera_2d_proxy& kiwi::_camera_2d_proxy::set_scale(GLfloat scale, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_scale = scale; }
	return *this;
}