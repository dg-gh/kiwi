#ifndef KIWI_MODEL_3D_HPP
#define KIWI_MODEL_3D_HPP

#include "kiwi_includes.hpp"


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

		GLfloat* data() noexcept;

		kiwi::model_3d& set_base_model(kiwi::model_3d* base_model_ptr) noexcept;
		kiwi::model_3d* get_base_model() const noexcept;
		kiwi::model_3d& set_free() noexcept;

		GLfloat* front_dir_data() noexcept;
		GLfloat* left_dir_data() noexcept;
		GLfloat* up_dir_data() noexcept;

		GLfloat* front_dir_data_free() noexcept;
		GLfloat* left_dir_data_free() noexcept;
		GLfloat* up_dir_data_free() noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat get_Z() const noexcept;
		const GLfloat* XYZ_data() noexcept;
		GLfloat get_yaw() const noexcept;
		GLfloat get_pitch() const noexcept;
		GLfloat get_roll() const noexcept;

		GLfloat get_X_free() noexcept;
		GLfloat get_Y_free() noexcept;
		GLfloat get_Z_free() noexcept;
		const GLfloat* XYZ_data_free() noexcept;
		GLfloat get_yaw_free() noexcept;
		GLfloat get_pitch_free() noexcept;
		GLfloat get_roll_free() noexcept;

		kiwi::model_3d& set_X(GLfloat X) noexcept;
		kiwi::model_3d& set_Y(GLfloat Y) noexcept;
		kiwi::model_3d& set_Z(GLfloat Z) noexcept;
		kiwi::model_3d& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::model_3d& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
		kiwi::model_3d& set_yaw(GLfloat yaw) noexcept;
		kiwi::model_3d& set_pitch(GLfloat pitch) noexcept;
		kiwi::model_3d& set_roll(GLfloat roll) noexcept;
		kiwi::model_3d& set_angles(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept;

		kiwi::model_3d& move_front(GLfloat distance) noexcept;
		kiwi::model_3d& move_back(GLfloat distance) noexcept;
		kiwi::model_3d& move_left(GLfloat distance) noexcept;
		kiwi::model_3d& move_right(GLfloat distance) noexcept;
		kiwi::model_3d& move_up(GLfloat distance) noexcept;
		kiwi::model_3d& move_down(GLfloat distance) noexcept;

		kiwi::model_3d& move_front_h(GLfloat distance) noexcept;
		kiwi::model_3d& move_back_h(GLfloat distance) noexcept;
		kiwi::model_3d& move_left_h(GLfloat distance) noexcept;
		kiwi::model_3d& move_right_h(GLfloat distance) noexcept;
		kiwi::model_3d& move_up_h(GLfloat distance) noexcept;
		kiwi::model_3d& move_down_h(GLfloat distance) noexcept;

		kiwi::model_3d& turn_left(GLfloat angle) noexcept;
		kiwi::model_3d& turn_right(GLfloat angle) noexcept;
		kiwi::model_3d& turn_up(GLfloat angle) noexcept;
		kiwi::model_3d& turn_down(GLfloat angle) noexcept;
		kiwi::model_3d& tilt_left(GLfloat angle) noexcept;
		kiwi::model_3d& tilt_right(GLfloat angle) noexcept;

		kiwi::model_3d& set_X(GLfloat X, bool condition) noexcept;
		kiwi::model_3d& set_Y(GLfloat Y, bool condition) noexcept;
		kiwi::model_3d& set_Z(GLfloat Z, bool condition) noexcept;
		kiwi::model_3d& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z, bool condition) noexcept;
		kiwi::model_3d& set_XYZ(const GLfloat* const XYZ_ptr, bool condition) noexcept;
		kiwi::model_3d& set_yaw(GLfloat yaw, bool condition) noexcept;
		kiwi::model_3d& set_pitch(GLfloat pitch, bool condition) noexcept;
		kiwi::model_3d& set_roll(GLfloat roll, bool condition) noexcept;
		kiwi::model_3d& set_angles(GLfloat yaw, GLfloat pitch, GLfloat roll, bool condition) noexcept;

		kiwi::model_3d& move_front(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_back(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_left(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_right(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_up(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_down(GLfloat distance, bool condition) noexcept;

		kiwi::model_3d& move_front_h(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_back_h(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_left_h(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_right_h(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_up_h(GLfloat distance, bool condition) noexcept;
		kiwi::model_3d& move_down_h(GLfloat distance, bool condition) noexcept;

		kiwi::model_3d& turn_left(GLfloat angle, bool condition) noexcept;
		kiwi::model_3d& turn_right(GLfloat angle, bool condition) noexcept;
		kiwi::model_3d& turn_up(GLfloat angle, bool condition) noexcept;
		kiwi::model_3d& turn_down(GLfloat angle, bool condition) noexcept;
		kiwi::model_3d& tilt_left(GLfloat angle, bool condition) noexcept;
		kiwi::model_3d& tilt_right(GLfloat angle, bool condition) noexcept;

		kiwi::model_3d& eval() noexcept;

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

		void m44xm44(GLfloat* const _KIWI_RESTRICT pC, const GLfloat* const pfA, const GLfloat* const pfB) const noexcept;
		void m44xv4(GLfloat* const _KIWI_RESTRICT pfC, const GLfloat* const pfA, const GLfloat* pfB) const noexcept;
	};
}

#endif // KIWI_MODEL_3D_HPP