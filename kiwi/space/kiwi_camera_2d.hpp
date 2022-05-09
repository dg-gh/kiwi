#ifndef KIWI_CAMERA_2D_HPP
#define KIWI_CAMERA_2D_HPP

#include "kiwi_model_2d.hpp"


namespace kiwi
{
	class _camera_2d_proxy;

	class camera_2d
	{

	public:

		camera_2d() = default;
		camera_2d(const kiwi::camera_2d&) = default;
		kiwi::camera_2d& operator=(const kiwi::camera_2d&) = default;
		camera_2d(kiwi::camera_2d&&) = default;
		kiwi::camera_2d& operator=(kiwi::camera_2d&&) = default;
		~camera_2d() = default;

		kiwi::camera_2d& set_new_projection_matrix(GLfloat screen_ratio) noexcept;

		const GLfloat* data() const noexcept;

		const GLfloat* data(const GLfloat* const model_matrix_ptr) noexcept;
		const GLfloat* data(kiwi::model_2d& model) noexcept;

		const GLfloat* XY_data() const noexcept;
		const GLfloat* right_dir_data() const noexcept;
		const GLfloat* up_dir_data() const noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat get_angle() const noexcept;
		GLfloat get_scale() const noexcept;

		kiwi::_camera_2d_proxy set_X(GLfloat X) noexcept;
		kiwi::_camera_2d_proxy set_Y(GLfloat Y) noexcept;
		kiwi::_camera_2d_proxy set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_camera_2d_proxy set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::_camera_2d_proxy set_angle(GLfloat angle) noexcept;
		kiwi::_camera_2d_proxy set_scale(GLfloat scale) noexcept;

		kiwi::_camera_2d_proxy turn_left(GLfloat angle) noexcept;
		kiwi::_camera_2d_proxy turn_right(GLfloat angle) noexcept;
		kiwi::_camera_2d_proxy move_left(GLfloat distance) noexcept;
		kiwi::_camera_2d_proxy move_right(GLfloat distance) noexcept;
		
		kiwi::_camera_2d_proxy move_up(GLfloat distance) noexcept;
		kiwi::_camera_2d_proxy move_down(GLfloat distance) noexcept;

		kiwi::_camera_2d_proxy set_X(GLfloat X, bool condition) noexcept;
		kiwi::_camera_2d_proxy set_Y(GLfloat Y, bool condition) noexcept;
		kiwi::_camera_2d_proxy set_XY(GLfloat X, GLfloat Y, bool condition) noexcept;
		kiwi::_camera_2d_proxy set_XY(const GLfloat* const XY_ptr, bool condition) noexcept;
		kiwi::_camera_2d_proxy set_angle(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_2d_proxy set_scale(GLfloat scale, bool condition) noexcept;

		kiwi::_camera_2d_proxy turn_left(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_2d_proxy turn_right(GLfloat angle, bool condition) noexcept;

		kiwi::_camera_2d_proxy move_up(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_2d_proxy move_down(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_2d_proxy move_right(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_2d_proxy move_left(GLfloat distance, bool condition) noexcept;

		bool in_view(const GLfloat* const object_XY_ptr) noexcept;
		bool in_view(GLfloat object_X, GLfloat object_Y) noexcept;
		bool in_view(const GLfloat* const object_XY_ptr, GLfloat object_radius) noexcept;
		bool in_view(GLfloat object_X, GLfloat object_Y, GLfloat object_radius) noexcept;

		kiwi::camera_2d& pick_XY(GLfloat X_screen, GLfloat Y_screen, GLfloat* XY_picked) noexcept;
		const kiwi::camera_2d& pick_XY(GLfloat X_screen, GLfloat Y_screen, GLfloat* XY_picked) const noexcept;

		void eval() noexcept;

	private:

		friend class _camera_2d_proxy;
		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		GLfloat m_mvp_matrix[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_vp_matrix[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_right_up_XY[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};

		GLfloat m_yaw = GL0;
		GLfloat m_scale = GL1;

		GLfloat m_X_factor = GL1;
		GLfloat m_Y_factor = GL1;

		void m33xm33(GLfloat* _KIWI_RESTRICT pfC, const GLfloat* pfA, const GLfloat* pfB) const noexcept;
	};

	class _camera_2d_proxy
	{

	public:

		_camera_2d_proxy() noexcept = default;
		_camera_2d_proxy(const kiwi::_camera_2d_proxy&) noexcept = default;
		kiwi::_camera_2d_proxy& operator=(const kiwi::_camera_2d_proxy&) noexcept = default;
		_camera_2d_proxy(kiwi::_camera_2d_proxy&&) noexcept = default;
		kiwi::_camera_2d_proxy& operator=(kiwi::_camera_2d_proxy&&) noexcept = default;
		~_camera_2d_proxy();

		kiwi::_camera_2d_proxy& set_X(GLfloat X) noexcept;
		kiwi::_camera_2d_proxy& set_Y(GLfloat Y) noexcept;
		kiwi::_camera_2d_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_camera_2d_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::_camera_2d_proxy& set_angle(GLfloat angle) noexcept;
		kiwi::_camera_2d_proxy& set_scale(GLfloat scale) noexcept;

		kiwi::_camera_2d_proxy& turn_left(GLfloat angle) noexcept;
		kiwi::_camera_2d_proxy& turn_right(GLfloat angle) noexcept;

		kiwi::_camera_2d_proxy& move_left(GLfloat distance) noexcept;
		kiwi::_camera_2d_proxy& move_right(GLfloat distance) noexcept;
		kiwi::_camera_2d_proxy& move_up(GLfloat distance) noexcept;
		kiwi::_camera_2d_proxy& move_down(GLfloat distance) noexcept;

		kiwi::_camera_2d_proxy& set_X(GLfloat X, bool condition) noexcept;
		kiwi::_camera_2d_proxy& set_Y(GLfloat Y, bool condition) noexcept;
		kiwi::_camera_2d_proxy& set_XY(GLfloat X, GLfloat Y, bool condition) noexcept;
		kiwi::_camera_2d_proxy& set_XY(const GLfloat* const XY_ptr, bool condition) noexcept;
		kiwi::_camera_2d_proxy& set_angle(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_2d_proxy& set_scale(GLfloat scale, bool condition) noexcept;

		kiwi::_camera_2d_proxy& turn_left(GLfloat angle, bool condition) noexcept;
		kiwi::_camera_2d_proxy& turn_right(GLfloat angle, bool condition) noexcept;

		kiwi::_camera_2d_proxy& move_left(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_2d_proxy& move_right(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_2d_proxy& move_up(GLfloat distance, bool condition) noexcept;
		kiwi::_camera_2d_proxy& move_down(GLfloat distance, bool condition) noexcept;

	private:

		friend class camera_2d;

		kiwi::camera_2d* m_parent_ptr;
	};
}

#endif // KIWI_CAMERA_2D_HPP