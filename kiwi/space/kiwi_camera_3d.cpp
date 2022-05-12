#include "space/kiwi_camera_3d.hpp"

#if defined(__AVX2__) && defined(__FMA__)
#ifndef _KIWI_AVX2_FMA
#define _KIWI_AVX2_FMA
#endif // _KIWI_AVX2_FMA
#include <immintrin.h>
#endif


kiwi::camera_3d& kiwi::camera_3d::new_projection_matrix(GLfloat screen_ratio, GLfloat fov, GLfloat z_near, GLfloat z_far) noexcept
{
	if (screen_ratio >= GL1)
	{
		m_tan_half_fov = std::tan(static_cast<GLfloat>(0.5f) * fov);
		GLfloat temp = screen_ratio * m_tan_half_fov;

		GLfloat dz_inv = GL1 / (z_far - z_near);
		m_p_matrix[0] = GL1 / temp;
		m_p_matrix[5] = GL1 / m_tan_half_fov;
		m_p_matrix[10] = (z_far + z_near) * dz_inv;

		m_p_matrix[11] = GL1;
		m_p_matrix[14] = (static_cast<GLfloat>(-2) * z_near) * (z_far * dz_inv);
		m_p_matrix[15] = GL0;

		m_cos_half_fov_x = GL1 / std::sqrt(GL1 + temp * temp);
		m_sin_half_fov_x = temp * m_cos_half_fov_x;

		m_cos_half_fov_y = GL1 / std::sqrt(GL1 + m_tan_half_fov * m_tan_half_fov);
		m_sin_half_fov_y = m_tan_half_fov * m_cos_half_fov_y;
	}
	else
	{
		m_tan_half_fov = std::tan(static_cast<GLfloat>(0.5f) * fov);
		GLfloat temp = screen_ratio / m_tan_half_fov;

		GLfloat dz_inv = GL1 / (z_far - z_near);
		m_p_matrix[0] = GL1 / m_tan_half_fov;
		m_p_matrix[5] = temp;
		m_p_matrix[10] = (z_far + z_near) * dz_inv;

		m_p_matrix[11] = GL1;
		m_p_matrix[14] = (static_cast<GLfloat>(-2) * z_near) * (z_far * dz_inv);
		m_p_matrix[15] = GL0;

		m_cos_half_fov_x = GL1 / std::sqrt(GL1 + m_tan_half_fov * m_tan_half_fov);
		m_sin_half_fov_x = m_tan_half_fov * m_cos_half_fov_x;

		m_sin_half_fov_y = GL1 / std::sqrt(GL1 + temp * temp);
		m_cos_half_fov_y = temp * m_sin_half_fov_y;
	}

	m_z_near = z_near;
	m_z_far = z_far;
	m_mz = z_near * z_far;
	m_dz = z_far - z_near;

	m_perspective = true;

	eval();
	return *this;
}

kiwi::camera_3d& kiwi::camera_3d::new_projection_matrix_ortho(GLfloat screen_ratio, const kiwi::XY& scale, GLfloat z_near, GLfloat z_far) noexcept
{
	GLfloat dz_inv = GL1 / (z_far - z_near);

	m_bound_X = static_cast<GLfloat>(0.5f) * scale[0];
	m_bound_Y = static_cast<GLfloat>(0.5f) * scale[1];

	m_p_matrix[0] = GL1 / m_bound_X;
	m_p_matrix[5] = GL1 / m_bound_Y;
	m_p_matrix[10] = GL2 * dz_inv;

	m_p_matrix[11] = GL0;
	m_p_matrix[14] = -(z_near + z_far) * dz_inv;
	m_p_matrix[15] = GL1;

	if (screen_ratio >= GL1)
	{
		m_scale_X = m_bound_X / screen_ratio;
		m_scale_Y = m_bound_Y;
	}
	else
	{
		m_scale_X = m_bound_X;
		m_scale_Y = m_bound_Y * screen_ratio;
	}

	m_z_near = z_near;
	m_dz = z_far - z_near;

	m_perspective = false;

	eval();
	return *this;
}

const GLfloat* kiwi::camera_3d::data(const GLfloat* const m_matrix_ptr) noexcept
{
	m44xm44(static_cast<GLfloat*>(m_mvp_matrix), static_cast<const GLfloat*>(m_vp_matrix), m_matrix_ptr);
	return static_cast<const GLfloat*>(m_mvp_matrix);
}

const GLfloat* kiwi::camera_3d::skybox_data(const GLfloat* const m_matrix_ptr) noexcept
{
	m44xm44(static_cast<GLfloat*>(m_mskybox_matrix), static_cast<const GLfloat*>(m_skybox_matrix), m_matrix_ptr);
	return static_cast<const GLfloat*>(m_mskybox_matrix);
}

const GLfloat* kiwi::camera_3d::data(kiwi::model_3d& model) noexcept
{
	m44xm44(static_cast<GLfloat*>(m_mvp_matrix), static_cast<const GLfloat*>(m_vp_matrix), model.data());
	return static_cast<const GLfloat*>(m_mvp_matrix);
}

const GLfloat* kiwi::camera_3d::skybox_data(kiwi::model_3d& model) noexcept
{
	m44xm44(static_cast<GLfloat*>(m_mskybox_matrix), static_cast<const GLfloat*>(m_skybox_matrix), model.data());
	return static_cast<const GLfloat*>(m_mskybox_matrix);
}

const GLfloat* kiwi::camera_3d::XYZ_data() const noexcept
{
	return static_cast<const GLfloat*>(m_front_left_up_XYZ) + 12;
}

const GLfloat* kiwi::camera_3d::front_dir_data() const noexcept
{
	return static_cast<const GLfloat*>(m_front_left_up_XYZ);
}

const GLfloat* kiwi::camera_3d::left_dir_data() const noexcept
{
	return static_cast<const GLfloat*>(m_front_left_up_XYZ) + 4;
}

const GLfloat* kiwi::camera_3d::up_dir_data() const noexcept
{
	return static_cast<const GLfloat*>(m_front_left_up_XYZ) + 8;
}

const GLfloat* kiwi::camera_3d::front_left_up_XYZ_data() const noexcept
{
	return static_cast<const GLfloat*>(m_front_left_up_XYZ);
}

const GLfloat* kiwi::camera_3d::data() const noexcept
{
	return static_cast<const GLfloat*>(m_vp_matrix);
}

const GLfloat* kiwi::camera_3d::skybox_data() const noexcept
{
	return static_cast<const GLfloat*>(m_skybox_matrix);
}

GLfloat kiwi::camera_3d::get_X() const noexcept
{
	return m_front_left_up_XYZ[12];
}

GLfloat kiwi::camera_3d::get_Y() const noexcept
{
	return m_front_left_up_XYZ[13];
}

GLfloat kiwi::camera_3d::get_Z() const noexcept
{
	return m_front_left_up_XYZ[14];
}

GLfloat kiwi::camera_3d::get_yaw() const noexcept
{
	return m_yaw;
}

GLfloat kiwi::camera_3d::get_pitch() const noexcept
{
	return m_pitch;
}

GLfloat kiwi::camera_3d::get_roll() const noexcept
{
	return m_roll;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_X(GLfloat X) noexcept
{
	m_front_left_up_XYZ[12] = X;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_Y(GLfloat Y) noexcept
{
	m_front_left_up_XYZ[13] = Y;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_Z(GLfloat Z) noexcept
{
	m_front_left_up_XYZ[14] = Z;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	m_front_left_up_XYZ[12] = X;
	m_front_left_up_XYZ[13] = Y;
	m_front_left_up_XYZ[14] = Z;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_front_left_up_XYZ[12] = *XYZ_ptr;
	m_front_left_up_XYZ[13] = *(XYZ_ptr + 1);
	m_front_left_up_XYZ[14] = *(XYZ_ptr + 2);

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_yaw(GLfloat yaw) noexcept
{
	m_yaw = yaw;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_pitch(GLfloat pitch) noexcept
{
	m_pitch = pitch;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_roll(GLfloat roll) noexcept
{
	m_roll = roll;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_angles_yp(GLfloat yaw, GLfloat pitch) noexcept
{
	m_yaw = yaw;
	m_pitch = pitch;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_angles_ypr(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept
{
	m_yaw = yaw;
	m_pitch = pitch;
	m_roll = roll;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] = X - distance * m_front_left_up_XYZ[0];
	m_front_left_up_XYZ[13] = Y - distance * m_front_left_up_XYZ[1];
	m_front_left_up_XYZ[14] = Z - distance * m_front_left_up_XYZ[2];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::follow(const GLfloat* const XYZ_ptr, GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] = *XYZ_ptr - distance * m_front_left_up_XYZ[0];
	m_front_left_up_XYZ[13] = *(XYZ_ptr + 1) - distance * m_front_left_up_XYZ[1];
	m_front_left_up_XYZ[14] = *(XYZ_ptr + 2) - distance * m_front_left_up_XYZ[2];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::look_at(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat dX = X - m_front_left_up_XYZ[12];
	GLfloat dY = Y - m_front_left_up_XYZ[13];
	GLfloat dZ = Z - m_front_left_up_XYZ[14];
	m_yaw = std::atan2(dY, dX);
	m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::look_at(const GLfloat* const XYZ_ptr) noexcept
{
	GLfloat dX = *XYZ_ptr - m_front_left_up_XYZ[12];
	GLfloat dY = *(XYZ_ptr + 1) - m_front_left_up_XYZ[13];
	GLfloat dZ = *(XYZ_ptr + 2) - m_front_left_up_XYZ[14];
	m_yaw = std::atan2(dY, dX);
	m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_front(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] += distance * m_front_left_up_XYZ[0];
	m_front_left_up_XYZ[13] += distance * m_front_left_up_XYZ[1];
	m_front_left_up_XYZ[14] += distance * m_front_left_up_XYZ[2];
	m_front_left_up_XYZ[15] += distance * m_front_left_up_XYZ[3];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_back(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] -= distance * m_front_left_up_XYZ[0];
	m_front_left_up_XYZ[13] -= distance * m_front_left_up_XYZ[1];
	m_front_left_up_XYZ[14] -= distance * m_front_left_up_XYZ[2];
	m_front_left_up_XYZ[15] -= distance * m_front_left_up_XYZ[3];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_left(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] += distance * m_front_left_up_XYZ[4];
	m_front_left_up_XYZ[13] += distance * m_front_left_up_XYZ[5];
	m_front_left_up_XYZ[14] += distance * m_front_left_up_XYZ[6];
	m_front_left_up_XYZ[15] += distance * m_front_left_up_XYZ[7];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_right(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] -= distance * m_front_left_up_XYZ[4];
	m_front_left_up_XYZ[13] -= distance * m_front_left_up_XYZ[5];
	m_front_left_up_XYZ[14] -= distance * m_front_left_up_XYZ[6];
	m_front_left_up_XYZ[15] -= distance * m_front_left_up_XYZ[7];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_up(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] += distance * m_front_left_up_XYZ[8];
	m_front_left_up_XYZ[13] += distance * m_front_left_up_XYZ[9];
	m_front_left_up_XYZ[14] += distance * m_front_left_up_XYZ[10];
	m_front_left_up_XYZ[15] += distance * m_front_left_up_XYZ[11];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_down(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] -= distance * m_front_left_up_XYZ[8];
	m_front_left_up_XYZ[13] -= distance * m_front_left_up_XYZ[9];
	m_front_left_up_XYZ[14] -= distance * m_front_left_up_XYZ[10];
	m_front_left_up_XYZ[15] -= distance * m_front_left_up_XYZ[11];

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_front_h(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] += distance * m_cos_yaw;
	m_front_left_up_XYZ[13] += distance * m_sin_yaw;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_back_h(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] -= distance * m_cos_yaw;
	m_front_left_up_XYZ[13] -= distance * m_sin_yaw;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_left_h(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] -= distance * m_sin_yaw;
	m_front_left_up_XYZ[13] += distance * m_cos_yaw;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_right_h(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] += distance * m_sin_yaw;
	m_front_left_up_XYZ[13] -= distance * m_cos_yaw;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_X(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[12] += distance;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_Y(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[13] += distance;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_Z(GLfloat distance) noexcept
{
	m_front_left_up_XYZ[14] += distance;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z) noexcept
{
	m_front_left_up_XYZ[12] += distance_X;
	m_front_left_up_XYZ[13] += distance_Y;
	m_front_left_up_XYZ[14] += distance_Z;

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_XYZ(const GLfloat* const distance_XYZ_ptr) noexcept
{
	m_front_left_up_XYZ[12] += *distance_XYZ_ptr;
	m_front_left_up_XYZ[13] += *(distance_XYZ_ptr + 1);
	m_front_left_up_XYZ[14] += *(distance_XYZ_ptr + 2);

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_up(GLfloat angle) noexcept
{
	constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
	m_pitch += angle;
	while (m_pitch > pi_d2) { m_pitch = pi_d2; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_down(GLfloat angle) noexcept
{
	constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
	m_pitch -= angle;
	while (m_pitch < -pi_d2) { m_pitch = -pi_d2; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw += angle;
	while (m_yaw > pi) { m_yaw -= pi_t2; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_yaw -= angle;
	while (m_yaw < -pi) { m_yaw += pi_t2; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::roll_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_roll += angle;
	while (m_roll > pi) { m_roll -= pi_t2; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::roll_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_roll -= angle;
	while (m_roll < -pi) { m_roll += pi_t2; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition) { m_front_left_up_XYZ[12] = X; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition) { m_front_left_up_XYZ[13] = Y; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_Z(GLfloat Z, bool condition) noexcept
{
	if (condition) { m_front_left_up_XYZ[14] = Z; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] = X;
		m_front_left_up_XYZ[13] = Y;
		m_front_left_up_XYZ[14] = Z;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_XYZ(const GLfloat* const XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] = *XYZ_ptr;
		m_front_left_up_XYZ[13] = *(XYZ_ptr + 1);
		m_front_left_up_XYZ[14] = *(XYZ_ptr + 2);
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_yaw(GLfloat yaw, bool condition) noexcept
{
	if (condition) { m_yaw = yaw; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_pitch(GLfloat pitch, bool condition) noexcept
{
	if (condition) { m_pitch = pitch; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::set_angles_yp(GLfloat yaw, GLfloat pitch, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = yaw;
		m_pitch = pitch;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] = X - distance * m_front_left_up_XYZ[0];
		m_front_left_up_XYZ[13] = Y - distance * m_front_left_up_XYZ[1];
		m_front_left_up_XYZ[14] = Z - distance * m_front_left_up_XYZ[2];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::follow(const GLfloat* const XYZ_ptr, GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] = *XYZ_ptr - distance * m_front_left_up_XYZ[0];
		m_front_left_up_XYZ[13] = *(XYZ_ptr + 1) - distance * m_front_left_up_XYZ[1];
		m_front_left_up_XYZ[14] = *(XYZ_ptr + 2) - distance * m_front_left_up_XYZ[2];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::look_at(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		GLfloat dX = X - m_front_left_up_XYZ[12];
		GLfloat dY = Y - m_front_left_up_XYZ[13];
		GLfloat dZ = Z - m_front_left_up_XYZ[14];
		m_yaw = std::atan2(dY, dX);
		m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::look_at(const GLfloat* const XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		GLfloat dX = *XYZ_ptr - m_front_left_up_XYZ[12];
		GLfloat dY = *(XYZ_ptr + 1) - m_front_left_up_XYZ[13];
		GLfloat dZ = *(XYZ_ptr + 2) - m_front_left_up_XYZ[14];
		m_yaw = std::atan2(dY, dX);
		m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_front(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += distance * m_front_left_up_XYZ[0];
		m_front_left_up_XYZ[13] += distance * m_front_left_up_XYZ[1];
		m_front_left_up_XYZ[14] += distance * m_front_left_up_XYZ[2];
		m_front_left_up_XYZ[15] += distance * m_front_left_up_XYZ[3];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_back(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] -= distance * m_front_left_up_XYZ[0];
		m_front_left_up_XYZ[13] -= distance * m_front_left_up_XYZ[1];
		m_front_left_up_XYZ[14] -= distance * m_front_left_up_XYZ[2];
		m_front_left_up_XYZ[15] -= distance * m_front_left_up_XYZ[3];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += distance * m_front_left_up_XYZ[4];
		m_front_left_up_XYZ[13] += distance * m_front_left_up_XYZ[5];
		m_front_left_up_XYZ[14] += distance * m_front_left_up_XYZ[6];
		m_front_left_up_XYZ[15] += distance * m_front_left_up_XYZ[7];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] -= distance * m_front_left_up_XYZ[4];
		m_front_left_up_XYZ[13] -= distance * m_front_left_up_XYZ[5];
		m_front_left_up_XYZ[14] -= distance * m_front_left_up_XYZ[6];
		m_front_left_up_XYZ[15] -= distance * m_front_left_up_XYZ[7];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += distance * m_front_left_up_XYZ[8];
		m_front_left_up_XYZ[13] += distance * m_front_left_up_XYZ[9];
		m_front_left_up_XYZ[14] += distance * m_front_left_up_XYZ[10];
		m_front_left_up_XYZ[15] += distance * m_front_left_up_XYZ[11];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] -= distance * m_front_left_up_XYZ[8];
		m_front_left_up_XYZ[13] -= distance * m_front_left_up_XYZ[9];
		m_front_left_up_XYZ[14] -= distance * m_front_left_up_XYZ[10];
		m_front_left_up_XYZ[15] -= distance * m_front_left_up_XYZ[11];
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_front_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += distance * m_cos_yaw;
		m_front_left_up_XYZ[13] += distance * m_sin_yaw;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_back_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] -= distance * m_cos_yaw;
		m_front_left_up_XYZ[13] -= distance * m_sin_yaw;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_left_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] -= distance * m_sin_yaw;
		m_front_left_up_XYZ[13] += distance * m_cos_yaw;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_right_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += distance * m_sin_yaw;
		m_front_left_up_XYZ[13] -= distance * m_cos_yaw;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_X(GLfloat distance, bool condition) noexcept
{
	if (condition) { m_front_left_up_XYZ[12] += distance; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_Y(GLfloat distance, bool condition) noexcept
{
	if (condition) { m_front_left_up_XYZ[13] += distance; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_Z(GLfloat distance, bool condition) noexcept
{
	if (condition) { m_front_left_up_XYZ[14] += distance; }

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += distance_X;
		m_front_left_up_XYZ[13] += distance_Y;
		m_front_left_up_XYZ[14] += distance_Z;
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::move_XYZ(const GLfloat* const distance_XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_front_left_up_XYZ[12] += *distance_XYZ_ptr;
		m_front_left_up_XYZ[13] += *(distance_XYZ_ptr + 1);
		m_front_left_up_XYZ[14] += *(distance_XYZ_ptr + 2);
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_up(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
		m_pitch += angle;
		while (m_pitch > pi_d2) { m_pitch = pi_d2; }
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_down(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
		m_pitch -= angle;
		while (m_pitch < -pi_d2) { m_pitch = -pi_d2; }
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw += angle;
		while (m_yaw > pi) { m_yaw -= pi_t2; }
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::turn_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_yaw -= angle;
		while (m_yaw < -pi) { m_yaw += pi_t2; }
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::roll_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_roll += angle;
		while (m_roll > pi) { m_roll -= pi_t2; }
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

kiwi::_camera_3d_proxy kiwi::camera_3d::roll_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_roll -= angle;
		while (m_roll < -pi) { m_roll += pi_t2; }
	}

	kiwi::_camera_3d_proxy proxy;
	proxy.m_parent_ptr = this;
	return proxy;
}

bool kiwi::camera_3d::in_view(const GLfloat* const object_XYZ_ptr) const noexcept
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
			&& ((-bound_X <= check_X) & (check_X <= bound_X))
			&& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		return false;
	}
}

bool kiwi::camera_3d::in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z) const noexcept
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
			&& ((-bound_X <= check_X) & (check_X <= bound_X))
			&& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		return ((m_z_near <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far))
			&& ((-m_bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= m_bound_X))
			&& ((-m_bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= m_bound_Y));
	}
}

bool kiwi::camera_3d::in_view(const GLfloat* const object_XYZ_ptr, GLfloat object_radius) const noexcept
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
			&& ((-bound_X <= check_X) & (check_X <= bound_X))
			&& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		GLfloat bound_X = m_bound_X + object_radius;
		GLfloat bound_Y = m_bound_Y + object_radius;

		return ((m_z_near - object_radius <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far + object_radius))
			&& ((-bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= bound_X))
			&& ((-bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= bound_Y));
	}
}

bool kiwi::camera_3d::in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z, GLfloat object_radius) const noexcept
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
			&& ((-bound_X <= check_X) & (check_X <= bound_X))
			&& ((-bound_Y <= check_Y) & (check_Y <= bound_Y));
	}
	else
	{
		GLfloat bound_X = m_bound_X + object_radius;
		GLfloat bound_Y = m_bound_Y + object_radius;

		return ((m_z_near - object_radius <= object_XYZ_in_view[2]) & (object_XYZ_in_view[2] <= m_z_far + object_radius))
			&& ((-bound_X <= object_XYZ_in_view[0]) & (object_XYZ_in_view[0] <= bound_X))
			&& ((-bound_Y <= object_XYZ_in_view[1]) & (object_XYZ_in_view[1] <= bound_Y));
	}
}

GLfloat kiwi::camera_3d::pick_view_depth(GLfloat X_screen, GLfloat Y_screen) const
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

GLfloat kiwi::camera_3d::pick_view_depth(GLfloat X_screen, GLfloat Y_screen, const kiwi::frame_spec& frame) const
{
	GLfloat depth_sampled;
	glReadPixels(frame.X_to_pixel(X_screen), frame.Y_to_pixel(Y_screen),
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

kiwi::camera_3d& kiwi::camera_3d::pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked)
{
	GLfloat depth_sampled;
	glReadPixels(kiwi::X_to_pixel(X_screen), kiwi::Y_to_pixel(Y_screen),
		1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth_sampled);

	if (m_perspective)
	{
		GLfloat depth = m_mz / (m_z_far - depth_sampled * m_dz);
		
		GLfloat coeff[4] = { depth, -(X_screen * depth * m_tan_half_fov), Y_screen * depth * m_tan_half_fov, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}
	else
	{
		GLfloat depth = m_z_near + m_dz * depth_sampled;

		GLfloat coeff[4] = { depth, -(m_scale_X * X_screen), m_scale_Y * Y_screen, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}

	return *this;
}

kiwi::camera_3d& kiwi::camera_3d::pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked, const kiwi::frame_spec& frame)
{
	GLfloat depth_sampled;
	glReadPixels(frame.X_to_pixel(X_screen), frame.Y_to_pixel(Y_screen),
		1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth_sampled);

	if (m_perspective)
	{
		GLfloat depth = m_mz / (m_z_far - depth_sampled * m_dz);

		GLfloat coeff[4] = { depth, -(X_screen * depth * m_tan_half_fov), Y_screen * depth * m_tan_half_fov, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}
	else
	{
		GLfloat depth = m_z_near + m_dz * depth_sampled;

		GLfloat coeff[4] = { depth, -(m_scale_X * X_screen), m_scale_Y * Y_screen, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}

	return *this;
}

const kiwi::camera_3d& kiwi::camera_3d::pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked) const
{
	GLfloat depth_sampled;
	glReadPixels(kiwi::X_to_pixel(X_screen), kiwi::Y_to_pixel(Y_screen),
		1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth_sampled);

	if (m_perspective)
	{
		GLfloat depth = m_mz / (m_z_far - depth_sampled * m_dz);

		GLfloat coeff[4] = { depth, -(X_screen * depth * m_tan_half_fov), Y_screen * depth * m_tan_half_fov, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}
	else
	{
		GLfloat depth = m_z_near + m_dz * depth_sampled;

		GLfloat coeff[4] = { depth, -(m_scale_X * X_screen), m_scale_Y * Y_screen, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}

	return *this;
}

const kiwi::camera_3d& kiwi::camera_3d::pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked, const kiwi::frame_spec& frame) const
{
	GLfloat depth_sampled;
	glReadPixels(frame.X_to_pixel(X_screen), frame.Y_to_pixel(Y_screen),
		1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth_sampled);

	if (m_perspective)
	{
		GLfloat depth = m_mz / (m_z_far - depth_sampled * m_dz);

		GLfloat coeff[4] = { depth, -(X_screen * depth * m_tan_half_fov), Y_screen * depth * m_tan_half_fov, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}
	else
	{
		GLfloat depth = m_z_near + m_dz * depth_sampled;

		GLfloat coeff[4] = { depth, -(m_scale_X * X_screen), m_scale_Y * Y_screen, static_cast<GLfloat>(1) };
		GLfloat XYZ1_picked[4];

		m44xv4(static_cast<GLfloat*>(XYZ1_picked),
			static_cast<const GLfloat*>(m_front_left_up_XYZ),
			static_cast<const GLfloat*>(coeff));

		*XYZ_picked = XYZ1_picked[0];
		*(XYZ_picked + 1) = XYZ1_picked[1];
		*(XYZ_picked + 2) = XYZ1_picked[2];
	}

	return *this;
}

void kiwi::camera_3d::eval() noexcept
{
	// trig

	m_cos_yaw = std::cos(m_yaw);
	m_sin_yaw = std::sin(m_yaw);
	m_cos_pitch = std::cos(m_pitch);
	m_sin_pitch = std::sin(m_pitch);
	m_cos_roll = std::cos(m_roll);
	m_sin_roll = std::sin(m_roll);

	m_front_left_up_XYZ[0] = m_cos_yaw * m_cos_pitch;
	m_front_left_up_XYZ[1] = m_sin_yaw * m_cos_pitch;
	m_front_left_up_XYZ[2] = m_sin_pitch;

#if defined(__AVX2__) && defined(__FMA__)
	__m128 vcos_roll = _mm_broadcast_ss(&m_cos_roll);
	__m128 vsin_roll = _mm_broadcast_ss(&m_sin_roll);
	__m128 vleft_h = _mm_setr_ps(-m_sin_yaw, m_cos_yaw, 0.0f, 0.0f);
	__m128 vup_h = _mm_setr_ps(-(m_cos_yaw * m_sin_pitch), -(m_sin_yaw * m_sin_pitch), m_cos_pitch, 0.0f);
	_mm_storeu_ps(static_cast<GLfloat*>(m_XYZ_front_left_up) + 8, _mm_fnmadd_ps(vsin_roll, vup_h, _mm_mul_ps(vcos_roll, vleft_h)));
	_mm_storeu_ps(static_cast<GLfloat*>(m_XYZ_front_left_up) + 12, _mm_fmadd_ps(vsin_roll, vleft_h, _mm_mul_ps(vcos_roll, vup_h)));
#else // SIMD
	GLfloat left_h[3] = { -m_sin_yaw, m_cos_yaw, GL0 };
	GLfloat up_h[3] = { -(m_cos_yaw * m_sin_pitch), -(m_sin_yaw * m_sin_pitch), m_cos_pitch };

	m_front_left_up_XYZ[4] = m_cos_roll * left_h[0] - m_sin_roll * up_h[0];
	m_front_left_up_XYZ[5] = m_cos_roll * left_h[1] - m_sin_roll * up_h[1];
	m_front_left_up_XYZ[6] = m_cos_roll * left_h[2] - m_sin_roll * up_h[2];

	m_front_left_up_XYZ[8] = m_sin_roll * left_h[0] + m_cos_roll * up_h[0];
	m_front_left_up_XYZ[9] = m_sin_roll * left_h[1] + m_cos_roll * up_h[1];
	m_front_left_up_XYZ[10] = m_sin_roll * left_h[2] + m_cos_roll * up_h[2];
#endif // SIMD

	// view matrix

	m_v_matrix[0] = m_sin_yaw;
	m_v_matrix[1] = -m_cos_yaw * m_sin_pitch;
	m_v_matrix[2] = m_cos_yaw * m_cos_pitch;

	m_v_matrix[4] = -m_cos_yaw;
	m_v_matrix[5] = -m_sin_yaw * m_sin_pitch;
	m_v_matrix[6] = m_sin_yaw * m_cos_pitch;

	m_v_matrix[9] = m_cos_pitch;
	m_v_matrix[10] = m_sin_pitch;

	m_v_matrix[12] = m_cos_yaw * m_front_left_up_XYZ[13] - m_sin_yaw * m_front_left_up_XYZ[12];
	m_v_matrix[13] = m_cos_yaw * m_sin_pitch * m_front_left_up_XYZ[12] + m_sin_yaw * m_sin_pitch * m_front_left_up_XYZ[13] - m_cos_pitch * m_front_left_up_XYZ[14];
	m_v_matrix[14] = -m_cos_yaw * m_cos_pitch * m_front_left_up_XYZ[12] - m_sin_yaw * m_cos_pitch * m_front_left_up_XYZ[13] - m_sin_pitch * m_front_left_up_XYZ[14];

	// view projection matrix

	m44xm44(static_cast<GLfloat*>(m_vp_matrix), static_cast<const GLfloat*>(m_p_matrix),
		static_cast<const GLfloat*>(m_v_matrix));

	// view projection skybox matrix

	m33hxm44(static_cast<GLfloat*>(m_skybox_matrix), static_cast<const GLfloat*>(m_p_matrix),
		static_cast<const GLfloat*>(m_v_matrix));
}

void kiwi::camera_3d::m44xm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept
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

void kiwi::camera_3d::m44xv4(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept
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

void kiwi::camera_3d::m33hxm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* pfB) const noexcept
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
	vregC1 = _mm_mul_ps(vregA1, _mm_broadcast_ss(pfB + 9));
	vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pfB + 10), vregC0);
	vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pfB + 11), vregC1);
	_mm_storeu_ps(pfC + 12, vregA3);
	_mm_storeu_ps(pfC + 8, _mm_add_ps(vregC0, vregC1));
#else // SIMD
	const GLfloat* pB = pfB;
	GLfloat* pC = pfC;
	GLfloat regB0; GLfloat regB1;
	for (std::size_t j = 0; j < 3; j++)
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
	*pC = *(pfA + 12);
	*(pC + 1) = *(pfA + 13);
	*(pC + 2) = *(pfA + 14);
	*(pC + 3) = *(pfA + 15);
#endif // SIMD
}

kiwi::_camera_3d_proxy::~_camera_3d_proxy()
{
	m_parent_ptr->eval();
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_X(GLfloat X) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] = X;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_Y(GLfloat Y) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[13] = Y;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_Z(GLfloat Z) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[14] = Z;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] = X;
	m_parent_ptr->m_front_left_up_XYZ[13] = Y;
	m_parent_ptr->m_front_left_up_XYZ[14] = Z;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] = *XYZ_ptr;
	m_parent_ptr->m_front_left_up_XYZ[13] = *(XYZ_ptr + 1);
	m_parent_ptr->m_front_left_up_XYZ[14] = *(XYZ_ptr + 2);

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_yaw(GLfloat yaw) noexcept
{
	m_parent_ptr->m_yaw = yaw;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_pitch(GLfloat pitch) noexcept
{
	m_parent_ptr->m_pitch = pitch;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_roll(GLfloat roll) noexcept
{
	m_parent_ptr->m_roll = roll;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_angles_yp(GLfloat yaw, GLfloat pitch) noexcept
{
	m_parent_ptr->m_yaw = yaw;
	m_parent_ptr->m_pitch = pitch;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_angles_ypr(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept
{
	m_parent_ptr->m_yaw = yaw;
	m_parent_ptr->m_pitch = pitch;
	m_parent_ptr->m_pitch = roll;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] = X - distance * m_parent_ptr->m_front_left_up_XYZ[0];
	m_parent_ptr->m_front_left_up_XYZ[13] = Y - distance * m_parent_ptr->m_front_left_up_XYZ[1];
	m_parent_ptr->m_front_left_up_XYZ[14] = Z - distance * m_parent_ptr->m_front_left_up_XYZ[2];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::follow(const GLfloat* const XYZ_ptr, GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] = *XYZ_ptr - distance * m_parent_ptr->m_front_left_up_XYZ[0];
	m_parent_ptr->m_front_left_up_XYZ[13] = *(XYZ_ptr + 1) - distance * m_parent_ptr->m_front_left_up_XYZ[1];
	m_parent_ptr->m_front_left_up_XYZ[14] = *(XYZ_ptr + 2) - distance * m_parent_ptr->m_front_left_up_XYZ[2];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::look_at(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat dX = X - m_parent_ptr->m_front_left_up_XYZ[12];
	GLfloat dY = Y - m_parent_ptr->m_front_left_up_XYZ[13];
	GLfloat dZ = Z - m_parent_ptr->m_front_left_up_XYZ[14];
	m_parent_ptr->m_yaw = std::atan2(dY, dX);
	m_parent_ptr->m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::look_at(const GLfloat* const XYZ_ptr) noexcept
{
	GLfloat dX = *XYZ_ptr - m_parent_ptr->m_front_left_up_XYZ[12];
	GLfloat dY = *(XYZ_ptr + 1) - m_parent_ptr->m_front_left_up_XYZ[13];
	GLfloat dZ = *(XYZ_ptr + 2) - m_parent_ptr->m_front_left_up_XYZ[14];
	m_parent_ptr->m_yaw = std::atan2(dY, dX);
	m_parent_ptr->m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_front(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_front_left_up_XYZ[0];
	m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_front_left_up_XYZ[1];
	m_parent_ptr->m_front_left_up_XYZ[14] += distance * m_parent_ptr->m_front_left_up_XYZ[2];
	m_parent_ptr->m_front_left_up_XYZ[15] += distance * m_parent_ptr->m_front_left_up_XYZ[3];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_back(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_front_left_up_XYZ[0];
	m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_front_left_up_XYZ[1];
	m_parent_ptr->m_front_left_up_XYZ[14] -= distance * m_parent_ptr->m_front_left_up_XYZ[2];
	m_parent_ptr->m_front_left_up_XYZ[15] -= distance * m_parent_ptr->m_front_left_up_XYZ[3];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_left(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_front_left_up_XYZ[4];
	m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_front_left_up_XYZ[5];
	m_parent_ptr->m_front_left_up_XYZ[14] += distance * m_parent_ptr->m_front_left_up_XYZ[6];
	m_parent_ptr->m_front_left_up_XYZ[15] += distance * m_parent_ptr->m_front_left_up_XYZ[7];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_right(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_front_left_up_XYZ[4];
	m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_front_left_up_XYZ[5];
	m_parent_ptr->m_front_left_up_XYZ[14] -= distance * m_parent_ptr->m_front_left_up_XYZ[6];
	m_parent_ptr->m_front_left_up_XYZ[15] -= distance * m_parent_ptr->m_front_left_up_XYZ[7];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_up(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_front_left_up_XYZ[8];
	m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_front_left_up_XYZ[9];
	m_parent_ptr->m_front_left_up_XYZ[14] += distance * m_parent_ptr->m_front_left_up_XYZ[10];
	m_parent_ptr->m_front_left_up_XYZ[15] += distance * m_parent_ptr->m_front_left_up_XYZ[11];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_down(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_front_left_up_XYZ[8];
	m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_front_left_up_XYZ[9];
	m_parent_ptr->m_front_left_up_XYZ[14] -= distance * m_parent_ptr->m_front_left_up_XYZ[10];
	m_parent_ptr->m_front_left_up_XYZ[15] -= distance * m_parent_ptr->m_front_left_up_XYZ[11];

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_front_h(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_cos_yaw;
	m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_sin_yaw;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_back_h(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_cos_yaw;
	m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_sin_yaw;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_left_h(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_sin_yaw;
	m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_cos_yaw;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_right_h(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_sin_yaw;
	m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_cos_yaw;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_X(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_Y(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[13] += distance;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_Z(GLfloat distance) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[14] += distance;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += distance_X;
	m_parent_ptr->m_front_left_up_XYZ[13] += distance_Y;
	m_parent_ptr->m_front_left_up_XYZ[14] += distance_Z;

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_XYZ(const GLfloat* const distance_XYZ_ptr) noexcept
{
	m_parent_ptr->m_front_left_up_XYZ[12] += *distance_XYZ_ptr;
	m_parent_ptr->m_front_left_up_XYZ[13] += *(distance_XYZ_ptr + 1);
	m_parent_ptr->m_front_left_up_XYZ[14] += *(distance_XYZ_ptr + 2);

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_up(GLfloat angle) noexcept
{
	constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
	m_parent_ptr->m_pitch += angle;
	while (m_parent_ptr->m_pitch > pi_d2) { m_parent_ptr->m_pitch = pi_d2; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_down(GLfloat angle) noexcept
{
	constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
	m_parent_ptr->m_pitch -= angle;
	while (m_parent_ptr->m_pitch < -pi_d2) { m_parent_ptr->m_pitch = -pi_d2; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_parent_ptr->m_yaw += angle;
	while (m_parent_ptr->m_yaw > pi) { m_parent_ptr->m_yaw -= pi_t2; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_parent_ptr->m_yaw -= angle;
	while (m_parent_ptr->m_yaw < -pi) { m_parent_ptr->m_yaw += pi_t2; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::roll_left(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_parent_ptr->m_roll += angle;
	while (m_parent_ptr->m_roll > pi) { m_parent_ptr->m_roll -= pi_t2; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::roll_right(GLfloat angle) noexcept
{
	constexpr GLfloat pi = 3.14159265358979f;
	constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
	m_parent_ptr->m_roll -= angle;
	while (m_parent_ptr->m_roll < -pi) { m_parent_ptr->m_roll += pi_t2; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_front(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_front_left_up_XYZ[0];
		m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_front_left_up_XYZ[1];
		m_parent_ptr->m_front_left_up_XYZ[14] += distance * m_parent_ptr->m_front_left_up_XYZ[2];
		m_parent_ptr->m_front_left_up_XYZ[15] += distance * m_parent_ptr->m_front_left_up_XYZ[3];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_back(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_front_left_up_XYZ[0];
		m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_front_left_up_XYZ[1];
		m_parent_ptr->m_front_left_up_XYZ[14] -= distance * m_parent_ptr->m_front_left_up_XYZ[2];
		m_parent_ptr->m_front_left_up_XYZ[15] -= distance * m_parent_ptr->m_front_left_up_XYZ[3];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_front_left_up_XYZ[4];
		m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_front_left_up_XYZ[5];
		m_parent_ptr->m_front_left_up_XYZ[14] += distance * m_parent_ptr->m_front_left_up_XYZ[6];
		m_parent_ptr->m_front_left_up_XYZ[15] += distance * m_parent_ptr->m_front_left_up_XYZ[7];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_front_left_up_XYZ[4];
		m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_front_left_up_XYZ[5];
		m_parent_ptr->m_front_left_up_XYZ[14] -= distance * m_parent_ptr->m_front_left_up_XYZ[6];
		m_parent_ptr->m_front_left_up_XYZ[15] -= distance * m_parent_ptr->m_front_left_up_XYZ[7];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_up(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_front_left_up_XYZ[8];
		m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_front_left_up_XYZ[9];
		m_parent_ptr->m_front_left_up_XYZ[14] += distance * m_parent_ptr->m_front_left_up_XYZ[10];
		m_parent_ptr->m_front_left_up_XYZ[15] += distance * m_parent_ptr->m_front_left_up_XYZ[11];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_down(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_front_left_up_XYZ[8];
		m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_front_left_up_XYZ[9];
		m_parent_ptr->m_front_left_up_XYZ[14] -= distance * m_parent_ptr->m_front_left_up_XYZ[10];
		m_parent_ptr->m_front_left_up_XYZ[15] -= distance * m_parent_ptr->m_front_left_up_XYZ[11];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_front_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_cos_yaw;
		m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_sin_yaw;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_back_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_cos_yaw;
		m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_sin_yaw;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_left_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] -= distance * m_parent_ptr->m_sin_yaw;
		m_parent_ptr->m_front_left_up_XYZ[13] += distance * m_parent_ptr->m_cos_yaw;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_right_h(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += distance * m_parent_ptr->m_sin_yaw;
		m_parent_ptr->m_front_left_up_XYZ[13] -= distance * m_parent_ptr->m_cos_yaw;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_X(GLfloat distance, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_front_left_up_XYZ[12] += distance; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_Y(GLfloat distance, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_front_left_up_XYZ[13] += distance; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_Z(GLfloat distance, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_front_left_up_XYZ[14] += distance; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += distance_X;
		m_parent_ptr->m_front_left_up_XYZ[13] += distance_Y;
		m_parent_ptr->m_front_left_up_XYZ[14] += distance_Z;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::move_XYZ(const GLfloat* const distance_XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] += *distance_XYZ_ptr;
		m_parent_ptr->m_front_left_up_XYZ[13] += *(distance_XYZ_ptr + 1);
		m_parent_ptr->m_front_left_up_XYZ[14] += *(distance_XYZ_ptr + 2);
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_up(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
		m_parent_ptr->m_pitch += angle;
		while (m_parent_ptr->m_pitch > pi_d2) { m_parent_ptr->m_pitch = pi_d2; }
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_down(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
		m_parent_ptr->m_pitch -= angle;
		while (m_parent_ptr->m_pitch < -pi_d2) { m_parent_ptr->m_pitch = -pi_d2; }
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_left(GLfloat angle, bool condition) noexcept
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

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::turn_right(GLfloat angle, bool condition) noexcept
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

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::roll_left(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_parent_ptr->m_roll += angle;
		while (m_parent_ptr->m_roll > pi) { m_parent_ptr->m_roll -= pi_t2; }
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::roll_right(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		constexpr GLfloat pi = 3.14159265358979f;
		constexpr GLfloat pi_t2 = 2.0f * 3.14159265358979f;
		m_parent_ptr->m_roll -= angle;
		while (m_parent_ptr->m_roll < -pi) { m_parent_ptr->m_roll += pi_t2; }
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_X(GLfloat X, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_front_left_up_XYZ[12] = X; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_front_left_up_XYZ[13] = Y; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_Z(GLfloat Z, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_front_left_up_XYZ[14] = Z; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] = X;
		m_parent_ptr->m_front_left_up_XYZ[13] = Y;
		m_parent_ptr->m_front_left_up_XYZ[14] = Z;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_XYZ(const GLfloat* const XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] = *XYZ_ptr;
		m_parent_ptr->m_front_left_up_XYZ[13] = *(XYZ_ptr + 1);
		m_parent_ptr->m_front_left_up_XYZ[14] = *(XYZ_ptr + 2);
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_yaw(GLfloat yaw, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_yaw = yaw; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_pitch(GLfloat pitch, bool condition) noexcept
{
	if (condition) { m_parent_ptr->m_pitch = pitch; }

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_angles_yp(GLfloat yaw, GLfloat pitch, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_yaw = yaw;
		m_parent_ptr->m_pitch = pitch;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::set_angles_ypr(GLfloat yaw, GLfloat pitch, GLfloat roll, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_yaw = yaw;
		m_parent_ptr->m_pitch = pitch;
		m_parent_ptr->m_roll = roll;
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] = X - distance * m_parent_ptr->m_front_left_up_XYZ[0];
		m_parent_ptr->m_front_left_up_XYZ[13] = Y - distance * m_parent_ptr->m_front_left_up_XYZ[1];
		m_parent_ptr->m_front_left_up_XYZ[14] = Z - distance * m_parent_ptr->m_front_left_up_XYZ[2];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::follow(const GLfloat* const XYZ_ptr, GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_parent_ptr->m_front_left_up_XYZ[12] = *XYZ_ptr - distance * m_parent_ptr->m_front_left_up_XYZ[0];
		m_parent_ptr->m_front_left_up_XYZ[13] = *(XYZ_ptr + 1) - distance * m_parent_ptr->m_front_left_up_XYZ[1];
		m_parent_ptr->m_front_left_up_XYZ[14] = *(XYZ_ptr + 2) - distance * m_parent_ptr->m_front_left_up_XYZ[2];
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::look_at(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept
{
	if (condition)
	{
		GLfloat dX = X - m_parent_ptr->m_front_left_up_XYZ[12];
		GLfloat dY = Y - m_parent_ptr->m_front_left_up_XYZ[13];
		GLfloat dZ = Z - m_parent_ptr->m_front_left_up_XYZ[14];
		m_parent_ptr->m_yaw = std::atan2(dY, dX);
		m_parent_ptr->m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));
	}

	return *this;
}

kiwi::_camera_3d_proxy& kiwi::_camera_3d_proxy::look_at(const GLfloat* const XYZ_ptr, bool condition) noexcept
{
	if (condition)
	{
		GLfloat dX = *XYZ_ptr - m_parent_ptr->m_front_left_up_XYZ[12];
		GLfloat dY = *(XYZ_ptr + 1) - m_parent_ptr->m_front_left_up_XYZ[13];
		GLfloat dZ = *(XYZ_ptr + 2) - m_parent_ptr->m_front_left_up_XYZ[14];
		m_parent_ptr->m_yaw = std::atan2(dY, dX);
		m_parent_ptr->m_pitch = std::atan(dZ / std::sqrt(dX * dX + dY * dY));
	}

	return *this;
}