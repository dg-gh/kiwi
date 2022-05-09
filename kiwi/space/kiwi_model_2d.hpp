#ifndef KIWI_MODEL_2D_HPP
#define KIWI_MODEL_2D_HPP

#include "kiwi_includes.hpp"


namespace kiwi
{
	class model_2d
	{

	public:

		model_2d() = default;
		model_2d(const kiwi::model_2d&) = default;
		kiwi::model_2d& operator=(const kiwi::model_2d&) = default;
		model_2d(kiwi::model_2d&&) = default;
		kiwi::model_2d& operator=(kiwi::model_2d&&) = default;
		~model_2d() = default;

		GLfloat* data() noexcept;

		kiwi::model_2d& set_base_model(kiwi::model_2d* base_model_ptr) noexcept;
		kiwi::model_2d* get_base_model() const noexcept;
		kiwi::model_2d& set_free() noexcept;

		GLfloat* front_dir_data() noexcept;
		GLfloat* left_dir_data() noexcept;

		GLfloat* front_dir_data_free() noexcept;
		GLfloat* left_dir_data_free() noexcept;

		GLfloat get_X() const noexcept;
		GLfloat get_Y() const noexcept;
		GLfloat* XY_data() noexcept;
		GLfloat get_angle() const noexcept;

		GLfloat get_X_free() noexcept;
		GLfloat get_Y_free() noexcept;
		GLfloat* XY_data_free() noexcept;
		GLfloat get_angle_free() noexcept;

		kiwi::model_2d& set_X(GLfloat X) noexcept;
		kiwi::model_2d& set_Y(GLfloat Y) noexcept;
		kiwi::model_2d& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::model_2d& set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::model_2d& set_angle(GLfloat angle) noexcept;

		kiwi::model_2d& turn_left(GLfloat angle) noexcept;
		kiwi::model_2d& turn_right(GLfloat angle) noexcept;

		kiwi::model_2d& move_front(GLfloat distance) noexcept;
		kiwi::model_2d& move_back(GLfloat distance) noexcept;
		kiwi::model_2d& move_left(GLfloat distance) noexcept;
		kiwi::model_2d& move_right(GLfloat distance) noexcept;

		kiwi::model_2d& set_X(GLfloat X, bool condition) noexcept;
		kiwi::model_2d& set_Y(GLfloat Y, bool condition) noexcept;
		kiwi::model_2d& set_XY(GLfloat X, GLfloat Y, bool condition) noexcept;
		kiwi::model_2d& set_XY(const GLfloat* const XY_ptr, bool condition) noexcept;
		kiwi::model_2d& set_angle(GLfloat angle, bool condition) noexcept;

		kiwi::model_2d& turn_left(GLfloat angle, bool condition) noexcept;
		kiwi::model_2d& turn_right(GLfloat angle, bool condition) noexcept;

		kiwi::model_2d& move_front(GLfloat distance, bool condition) noexcept;
		kiwi::model_2d& move_back(GLfloat distance, bool condition) noexcept;
		kiwi::model_2d& move_left(GLfloat distance, bool condition) noexcept;
		kiwi::model_2d& move_right(GLfloat distance, bool condition) noexcept;

		kiwi::model_2d& eval() noexcept;

	private:

		static constexpr GLfloat GL0 = static_cast<GLfloat>(0);
		static constexpr GLfloat GL1 = static_cast<GLfloat>(1);

		GLfloat m_matrix_free[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};
		GLfloat m_matrix_rel[9] = {
			GL1, GL0, GL0,
			GL0, GL1, GL0,
			GL0, GL0, GL1
		};

		GLfloat m_yaw = GL0;

		kiwi::model_2d* m_parent_model_ptr = nullptr;
		unsigned int m_state_counter = 0;
		unsigned int m_parent_model_state_counter = 0;

		bool m_XY_modified = false;
		bool m_angle_modified = false;

		void m33xm33(GLfloat* _KIWI_RESTRICT pC, const GLfloat* pA, const GLfloat* pB) noexcept;
	};
}

#endif // KIWI_MODEL_2D_HPP