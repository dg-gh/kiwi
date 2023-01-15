#ifndef _KIWI_MODEL_2D_HPP
#define _KIWI_MODEL_2D_HPP

#include "header_utils/kiwi_glcall.hpp"
#include "header_utils/kiwi_restrict.hpp"
#include <cmath>


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

		inline const GLfloat* data() noexcept;

		kiwi::model_2d& set_base_model(kiwi::model_2d* base_model_ptr) noexcept;
		kiwi::model_2d* get_base_model() const noexcept;
		kiwi::model_2d& set_free() noexcept;

		inline const GLfloat* front_dir_data() noexcept;
		inline const GLfloat* left_dir_data() noexcept;

		inline const GLfloat* front_dir_data_free() noexcept;
		inline const GLfloat* left_dir_data_free() noexcept;

		inline GLfloat get_X() const noexcept;
		inline GLfloat get_Y() const noexcept;
		inline const GLfloat* XY_data() noexcept;
		inline GLfloat get_angle() const noexcept;

		inline GLfloat get_X_free() noexcept;
		inline GLfloat get_Y_free() noexcept;
		inline const GLfloat* XY_data_free() noexcept;
		inline GLfloat get_angle_free() noexcept;

		inline kiwi::model_2d& set_X(GLfloat X, bool condition = true) noexcept;
		inline kiwi::model_2d& set_Y(GLfloat Y, bool condition = true) noexcept;
		inline kiwi::model_2d& set_XY(GLfloat X, GLfloat Y, bool condition = true) noexcept;
		inline kiwi::model_2d& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr, bool condition = true) noexcept;
		inline kiwi::model_2d& set_angle(GLfloat angle, bool condition = true) noexcept;

		inline kiwi::model_2d& move_X(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_2d& move_Y(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_2d& move_XY(GLfloat dX, GLfloat dY, bool condition = true) noexcept;
		inline kiwi::model_2d& move_XY(const GLfloat* const _KIWI_RESTRICT dXdY_ptr, bool condition = true) noexcept;

		inline kiwi::model_2d& turn_left(GLfloat angle, bool condition = true) noexcept;
		inline kiwi::model_2d& turn_right(GLfloat angle, bool condition = true) noexcept;

		inline kiwi::model_2d& move_front(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_2d& move_back(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_2d& move_left(GLfloat distance, bool condition = true) noexcept;
		inline kiwi::model_2d& move_right(GLfloat distance, bool condition = true) noexcept;

		inline kiwi::model_2d& eval() noexcept;

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


// INLINE IMPLEMENTATION

inline const GLfloat* kiwi::model_2d::data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

inline const GLfloat* kiwi::model_2d::front_dir_data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_rel);
}

inline const GLfloat* kiwi::model_2d::left_dir_data() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_rel) + 3;
}

inline const GLfloat* kiwi::model_2d::front_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free);
}

inline const GLfloat* kiwi::model_2d::left_dir_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 3;
}


inline GLfloat kiwi::model_2d::get_X() const noexcept
{
	return m_matrix_rel[6];
}

inline GLfloat kiwi::model_2d::get_Y() const noexcept
{
	return m_matrix_rel[7];
}

inline const GLfloat* kiwi::model_2d::XY_data() noexcept
{
	return static_cast<GLfloat*>(m_matrix_rel) + 6;
}

inline GLfloat kiwi::model_2d::get_angle() const noexcept
{
	return m_yaw;
}

inline GLfloat kiwi::model_2d::get_X_free() noexcept
{
	eval();
	return m_matrix_free[6];
}

inline GLfloat kiwi::model_2d::get_Y_free() noexcept
{
	eval();
	return m_matrix_free[7];
}

inline const GLfloat* kiwi::model_2d::XY_data_free() noexcept
{
	eval();
	return static_cast<GLfloat*>(m_matrix_free) + 6;
}

inline GLfloat kiwi::model_2d::get_angle_free() noexcept
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

inline kiwi::model_2d& kiwi::model_2d::set_X(GLfloat X, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] = X;
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::set_Y(GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[7] = Y;
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::set_XY(GLfloat X, GLfloat Y, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] = X;
		m_matrix_rel[7] = Y;
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] = *XY_ptr;
		m_matrix_rel[7] = *(XY_ptr + 1);
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::set_angle(GLfloat angle, bool condition) noexcept
{
	if (condition)
	{
		m_yaw = angle;
		m_angle_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_X(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += distance;
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_Y(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[7] += distance;
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_XY(GLfloat dX, GLfloat dY, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += dX;
		m_matrix_rel[7] += dY;
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_XY(const GLfloat* const _KIWI_RESTRICT dXdY_ptr, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += *dXdY_ptr;
		m_matrix_rel[7] += *(dXdY_ptr + 1);
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::turn_left(GLfloat angle, bool condition) noexcept
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

inline kiwi::model_2d& kiwi::model_2d::turn_right(GLfloat angle, bool condition) noexcept
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

inline kiwi::model_2d& kiwi::model_2d::move_front(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += distance * m_matrix_rel[0];
		m_matrix_rel[7] += distance * m_matrix_rel[1];
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_back(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] -= distance * m_matrix_rel[0];
		m_matrix_rel[7] -= distance * m_matrix_rel[1];
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_left(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] -= distance * m_matrix_rel[1];
		m_matrix_rel[7] += distance * m_matrix_rel[0];
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::move_right(GLfloat distance, bool condition) noexcept
{
	if (condition)
	{
		m_matrix_rel[6] += distance * m_matrix_rel[1];
		m_matrix_rel[7] -= distance * m_matrix_rel[0];
		m_XY_modified = true;
	}
	return *this;
}

inline kiwi::model_2d& kiwi::model_2d::eval() noexcept
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

#endif // _KIWI_MODEL_2D_HPP