#ifndef KIWI_CAMERA_3D_HPP
#define KIWI_CAMERA_3D_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_frame.hpp"
#include "space/kiwi_model_3d.hpp"


namespace kiwi
{
	class _camera_3d_proxy;

	class camera_3d
	{

	public:

		camera_3d() = default;
		camera_3d(const kiwi::camera_3d&) = default;
		kiwi::camera_3d& operator=(const kiwi::camera_3d&) = default;
		camera_3d(kiwi::camera_3d&&) = default;
		kiwi::camera_3d& operator=(kiwi::camera_3d&&) = default;
		~camera_3d() = default;

		kiwi::camera_3d& new_projection_matrix(GLfloat screen_ratio, GLfloat fov, GLfloat z_near, GLfloat z_far) noexcept;
		kiwi::camera_3d& new_projection_matrix_ortho(GLfloat screen_ratio, const kiwi::XY& scale, GLfloat z_near, GLfloat z_far) noexcept;

		const GLfloat* data(const GLfloat* const model_matrix_ptr) noexcept;
		const GLfloat* skybox_data(const GLfloat* const model_matrix_ptr) noexcept;
		const GLfloat* data(kiwi::model_3d& model) noexcept;
		const GLfloat* skybox_data(kiwi::model_3d& model) noexcept;

		const GLfloat* XYZ_data() const noexcept;
		const GLfloat* front_dir_data() const noexcept;
		const GLfloat* left_dir_data() const noexcept;
		const GLfloat* up_dir_data() const noexcept;
		const GLfloat* front_left_up_XYZ_data() const noexcept;
		const GLfloat* data() const noexcept;
		const GLfloat* skybox_data() const noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat get_Z() const noexcept;
		GLfloat get_yaw() const noexcept;
		GLfloat get_pitch() const noexcept;
		GLfloat get_roll() const noexcept;

		kiwi::_camera_3d_proxy set_X(GLfloat X) noexcept;
		kiwi::_camera_3d_proxy set_Y(GLfloat Y) noexcept;
		kiwi::_camera_3d_proxy set_Z(GLfloat Z) noexcept;
		kiwi::_camera_3d_proxy set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_camera_3d_proxy set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
		kiwi::_camera_3d_proxy set_yaw(GLfloat yaw) noexcept;
		kiwi::_camera_3d_proxy set_pitch(GLfloat pitch) noexcept;
		kiwi::_camera_3d_proxy set_roll(GLfloat roll) noexcept;
		kiwi::_camera_3d_proxy set_angles_yp(GLfloat yaw, GLfloat pitch) noexcept;
		kiwi::_camera_3d_proxy set_angles_ypr(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept;
		kiwi::_camera_3d_proxy follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy follow(const GLfloat* const XYZ_ptr, GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy look_at(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_camera_3d_proxy look_at(const GLfloat* const XYZ_ptr) noexcept;

		kiwi::_camera_3d_proxy move_front(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_back(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_left(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_right(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_up(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_down(GLfloat distance) noexcept;

		kiwi::_camera_3d_proxy move_front_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_back_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_left_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_right_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_X(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_Y(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_Z(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z) noexcept;
		kiwi::_camera_3d_proxy move_XYZ(const GLfloat* const distance_XYZ_ptr) noexcept;

		kiwi::_camera_3d_proxy turn_up(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy turn_down(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy turn_left(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy turn_right(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy roll_left(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy roll_right(GLfloat angle) noexcept;

		kiwi::_camera_3d_proxy set_X(GLfloat X, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_Y(GLfloat Y, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_Z(GLfloat Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_XYZ(const GLfloat* const XYZ_ptr, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_yaw(GLfloat yaw, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_pitch(GLfloat pitch, bool condition) noexcept;
		kiwi::_camera_3d_proxy set_angles_yp(GLfloat yaw, GLfloat pitch, bool condition) noexcept;
		kiwi::_camera_3d_proxy follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy follow(const GLfloat* const XYZ_ptr, GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy look_at(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy look_at(const GLfloat* const XYZ_ptr, bool condition) noexcept;

		kiwi::_camera_3d_proxy move_front(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_back(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_left(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_right(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_up(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_down(GLfloat distance, bool condition) noexcept;

		kiwi::_camera_3d_proxy move_front_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_back_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_left_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_right_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_X(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_Y(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_Z(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy move_XYZ(const GLfloat* const distance_XYZ_ptr, bool condition) noexcept;

		kiwi::_camera_3d_proxy turn_up(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy turn_down(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy turn_left(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy turn_right(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy roll_left(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy roll_right(GLfloat angle, bool condition) noexcept;

		bool in_view(const GLfloat* const object_XYZ_ptr) const noexcept;
		bool in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z) const noexcept;
		bool in_view(const GLfloat* const object_XYZ_ptr, GLfloat object_radius) const noexcept;
		bool in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_Z, GLfloat object_radius) const noexcept;

		GLfloat pick_view_depth(GLfloat X_screen, GLfloat Y_screen) const;
		GLfloat pick_view_depth(GLfloat X_screen, GLfloat Y_screen, const kiwi::frame_spec& frame) const;
		kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked);
		kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked, const kiwi::frame_spec& frame);
		const kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked) const;
		const kiwi::camera_3d& pick_view_XYZ(GLfloat X_screen, GLfloat Y_screen, GLfloat* XYZ_picked, const kiwi::frame_spec& frame) const;

		void eval() noexcept;

	private:

		friend class _camera_3d_proxy;
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


		GLfloat m_front_left_up_XYZ[16] = {
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

		bool m_perspective;

		void m44xm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
		void m44xv4(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
		void m33hxm44(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
	};

	class _camera_3d_proxy
	{

	public:

		_camera_3d_proxy() = default;
		_camera_3d_proxy(const kiwi::_camera_3d_proxy&) = default;
		kiwi::_camera_3d_proxy& operator=(const kiwi::_camera_3d_proxy&) = default;
		_camera_3d_proxy(kiwi::_camera_3d_proxy&&) = default;
		kiwi::_camera_3d_proxy& operator=(kiwi::_camera_3d_proxy&&) = default;
		~_camera_3d_proxy();

		kiwi::_camera_3d_proxy& set_X(GLfloat X) noexcept;
		kiwi::_camera_3d_proxy& set_Y(GLfloat Y) noexcept;
		kiwi::_camera_3d_proxy& set_Z(GLfloat Z) noexcept;
		kiwi::_camera_3d_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_camera_3d_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
		kiwi::_camera_3d_proxy& set_yaw(GLfloat yaw) noexcept;
		kiwi::_camera_3d_proxy& set_pitch(GLfloat pitch) noexcept;
		kiwi::_camera_3d_proxy& set_roll(GLfloat pitch) noexcept;
		kiwi::_camera_3d_proxy& set_angles_yp(GLfloat yaw, GLfloat pitch) noexcept;
		kiwi::_camera_3d_proxy& set_angles_ypr(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept;
		kiwi::_camera_3d_proxy& follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& follow(const GLfloat* const XYZ_ptr, GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& look_at(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_camera_3d_proxy& look_at(const GLfloat* const XYZ_ptr) noexcept;

		kiwi::_camera_3d_proxy& move_front(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_back(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_left(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_right(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_up(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_down(GLfloat distance) noexcept;

		kiwi::_camera_3d_proxy& move_front_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_back_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_left_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_right_h(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_X(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_Y(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_Z(GLfloat distance) noexcept;
		kiwi::_camera_3d_proxy& move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z) noexcept;
		kiwi::_camera_3d_proxy& move_XYZ(const GLfloat* const distance_XYZ_ptr) noexcept;

		kiwi::_camera_3d_proxy& turn_up(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy& turn_down(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy& turn_left(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy& turn_right(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy& roll_left(GLfloat angle) noexcept;
		kiwi::_camera_3d_proxy& roll_right(GLfloat angle) noexcept;

		kiwi::_camera_3d_proxy& set_X(GLfloat X, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_Y(GLfloat Y, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_Z(GLfloat Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_XYZ(const GLfloat* const XYZ_ptr, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_yaw(GLfloat yaw, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_pitch(GLfloat pitch, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_angles_yp(GLfloat yaw, GLfloat pitch, bool condition) noexcept;
		kiwi::_camera_3d_proxy& set_angles_ypr(GLfloat yaw, GLfloat pitch, GLfloat roll, bool condition) noexcept;
		kiwi::_camera_3d_proxy& follow(GLfloat X, GLfloat Y, GLfloat Z, GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& follow(const GLfloat* const XYZ_ptr, GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& look_at(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy& look_at(const GLfloat* const XYZ_ptr, bool condition) noexcept;

		kiwi::_camera_3d_proxy& move_front(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_back(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_left(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_right(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_up(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_down(GLfloat distance, bool condition) noexcept;

		kiwi::_camera_3d_proxy& move_front_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_back_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_left_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_right_h(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_X(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_Y(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_Z(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, bool condition) noexcept;
		kiwi::_camera_3d_proxy& move_XYZ(const GLfloat* const distance_XYZ_ptr, bool condition) noexcept;

		kiwi::_camera_3d_proxy& turn_up(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy& turn_down(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy& turn_left(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy& turn_right(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy& roll_left(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_3d_proxy& roll_right(GLfloat angle, bool condition) noexcept;

	private:

		friend class camera_3d;

		kiwi::camera_3d* m_parent_ptr;
	};
}

#endif // KIWI_CAMERA_3D_HPP