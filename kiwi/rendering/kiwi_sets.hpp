#ifndef _KIWI_SETS_HPP
#define _KIWI_SETS_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_texture_2d.hpp"
#include "buffers/kiwi_buffer_texture_2d_array.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "header_utils/kiwi_restrict.hpp"


// XYZA

namespace kiwi
{
	class _XYZA_proxy;
	class XYZA_loader;
	class _XYZA_loader_proxy;

	class XYZA_set
	{

	public:

		friend class _XYZA_proxy;
		friend class XYZA_loader;

		kiwi::XYZA_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZA_proxy operator[](std::size_t number) noexcept;
		kiwi::XYZA_set& to_binding(GLuint binding) noexcept;
		const kiwi::XYZA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::XYZA_loader get_loader(void* ptr) noexcept;
		kiwi::XYZA_loader get_loader(void* ptr, std::size_t count) noexcept;
		kiwi::XYZA_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XYZA_proxy
	{

	private:

		kiwi::XYZA_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class XYZA_set;

		kiwi::_XYZA_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XYZA_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;
		kiwi::_XYZA_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZA_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		kiwi::_XYZA_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat angle) noexcept;
		kiwi::_XYZA_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		kiwi::_XYZA_proxy& set_angle(GLfloat angle) noexcept;
	};

	class XYZA_loader
	{

	private:

		XYZA_loader() noexcept;

	public:

		XYZA_loader(const kiwi::XYZA_loader& rhs) = delete;
		kiwi::XYZA_loader& operator=(const kiwi::XYZA_loader& rhs) = delete;
		XYZA_loader(kiwi::XYZA_loader&& rhs) noexcept;
		kiwi::XYZA_loader& operator=(kiwi::XYZA_loader&& rhs) noexcept;
		~XYZA_loader();

		kiwi::_XYZA_loader_proxy operator[](std::size_t number) noexcept;
		void cancel() noexcept;

	private:

		friend class XYZA_set;

		GLfloat* m_data_ptr;
		kiwi::XYZA_set* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _XYZA_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;

	public:

		friend class XYZA_loader;

		inline kiwi::_XYZA_loader_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYA(GLfloat X, GLfloat Y, GLfloat A) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYA(const GLfloat* const _KIWI_RESTRICT XYA_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_angle(GLfloat angle) noexcept;

		inline kiwi::_XYZA_loader_proxy& move_X(GLfloat distance) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_Y(GLfloat distance) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_Z(GLfloat distance) noexcept;

		inline kiwi::_XYZA_loader_proxy& move_XY(GLfloat distance_X, GLfloat distance_Y) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_XY(const GLfloat* const _KIWI_RESTRICT distance_XY_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_XYZ(const GLfloat* const _KIWI_RESTRICT distance_XYZ_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_XYZA(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, GLfloat angle) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_XYZA(const GLfloat* const _KIWI_RESTRICT distance_XYZA_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& move_angle(GLfloat angle) noexcept;

		inline GLfloat& X(GLfloat angle) noexcept;
		inline GLfloat& Y(GLfloat angle) noexcept;
		inline GLfloat& Z(GLfloat angle) noexcept;
		inline GLfloat& angle(GLfloat angle) noexcept;
	};
}


// RGBA

namespace kiwi
{
	class _RGBA_proxy;
	class RGBA_loader;
	class _RGBA_loader_proxy;

	class RGBA_set
	{

	public:

		friend class _RGBA_proxy;
		friend class RGBA_loader;

		kiwi::RGBA_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_RGBA_proxy operator[](std::size_t number) noexcept;
		kiwi::RGBA_set& to_binding(GLuint binding) noexcept;
		const kiwi::RGBA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::RGBA_loader get_loader(void* ptr) noexcept;
		kiwi::RGBA_loader get_loader(void* ptr, std::size_t count) noexcept;
		kiwi::RGBA_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _RGBA_proxy
	{

	public:

		friend class RGBA_set;

		kiwi::_RGBA_proxy& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		kiwi::_RGBA_proxy& set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept;

	private:

		kiwi::RGBA_set* m_set_ptr;
		std::size_t m_number;
	};

	class RGBA_loader
	{

	private:

		RGBA_loader() noexcept;

	public:

		RGBA_loader(const kiwi::RGBA_loader& rhs) = delete;
		kiwi::RGBA_loader& operator=(const kiwi::RGBA_loader& rhs) = delete;
		RGBA_loader(kiwi::RGBA_loader&& rhs) noexcept;
		kiwi::RGBA_loader& operator=(kiwi::RGBA_loader&& rhs) noexcept;
		~RGBA_loader();

		kiwi::_RGBA_loader_proxy operator[](std::size_t number) noexcept;
		void cancel() noexcept;

	private:

		friend class RGBA_set;

		GLfloat* m_data_ptr;
		kiwi::RGBA_set* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _RGBA_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;

	public:

		friend class RGBA_loader;
		inline kiwi::_RGBA_loader_proxy& set_RGBA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		inline kiwi::_RGBA_loader_proxy& set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept;

		inline GLfloat& R() noexcept;
		inline GLfloat& G() noexcept;
		inline GLfloat& B() noexcept;
		inline GLfloat& A() noexcept;
	};
}


// UV

namespace kiwi
{
	class _UV_proxy;
	class UV_loader;
	class _UV_loader_proxy;

	class UV_set
	{

	public:

		friend class _UV_proxy;
		friend class UV_loader;

		kiwi::UV_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_UV_proxy operator[](std::size_t number) noexcept;
		kiwi::UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::UV_set& set_atlas(const kiwi::texture_2d* const atlas_texture_ptr,
			std::function<void(const int, GLfloat* ptr)> atlas_function, const kiwi::UV& UV_size) noexcept;

		inline kiwi::UV_loader get_loader(void* ptr) noexcept;
		inline kiwi::UV_loader get_loader(void* ptr, std::size_t count) noexcept;
		inline kiwi::UV_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

		inline GLfloat get_U_size() const noexcept;
		inline GLfloat get_V_size() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_2d* m_atlas_texture_ptr = nullptr;
		std::function<void(const int, GLfloat*)> m_atlas_coordinate_function;
		GLfloat m_UV_size[2] = { static_cast<GLfloat>(0) };
	};

	class _UV_proxy
	{

	private:

		kiwi::UV_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class UV_set;

		kiwi::_UV_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		kiwi::_UV_proxy& set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept;
		kiwi::_UV_proxy& set_tile(int tile) noexcept;
	};

	class UV_loader
	{

	private:

		inline UV_loader() noexcept;

	public:

		UV_loader(const kiwi::UV_loader& rhs) = delete;
		kiwi::UV_loader& operator=(const kiwi::UV_loader& rhs) = delete;
		inline UV_loader(kiwi::UV_loader&& rhs) noexcept;
		inline kiwi::UV_loader& operator=(kiwi::UV_loader&& rhs) noexcept;
		inline ~UV_loader();

		inline kiwi::_UV_loader_proxy operator[](std::size_t number) noexcept;
		inline void cancel() noexcept;

	private:

		friend class UV_set;

		GLfloat* m_data_ptr;
		kiwi::UV_set* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _UV_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;
		std::function<void(const int, GLfloat*)>* m_altas_coordinate_function_ptr;

	public:

		friend class UV_loader;

		inline kiwi::_UV_loader_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		inline kiwi::_UV_loader_proxy& set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept;
		inline kiwi::_UV_loader_proxy& operator=(int tile) noexcept;

		inline GLfloat& U() noexcept;
		inline GLfloat& V() noexcept;
	};
}

// id

namespace kiwi
{
	class _id_proxy;
	class id_loader;
	class _id_loader_proxy;

	class id_set
	{

	public:

		friend class _id_proxy;
		friend class id_loader;

		kiwi::id_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_id_proxy operator[](std::size_t number) noexcept;
		kiwi::id_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::id_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::id_set& set_atlas(const kiwi::texture_2d_array* const atlas_texture_ptr) noexcept;

		kiwi::id_loader get_loader(void* ptr) noexcept;
		kiwi::id_loader get_loader(void* ptr, std::size_t count) noexcept;
		kiwi::id_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_2d_array* m_texture_array_ptr = nullptr;
	};

	class _id_proxy
	{

	private:

		kiwi::id_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class id_set;

		void operator=(GLint id) noexcept;
	};

	class id_loader
	{

	private:

		id_loader() noexcept;

	public:

		id_loader(const kiwi::id_loader& rhs) = delete;
		kiwi::id_loader& operator=(const kiwi::id_loader& rhs) = delete;
		id_loader(kiwi::id_loader&& rhs) noexcept;
		kiwi::id_loader& operator=(kiwi::id_loader&& rhs) noexcept;
		~id_loader();

		inline GLint& operator[](std::size_t number) noexcept;
		void cancel() noexcept;

	private:

		friend class id_set;

		GLint* m_data_ptr;
		kiwi::id_set* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};
}


namespace kiwi
{
	class _mat3x3f_proxy;

	class mat3x3f_set
	{

	public:

		friend class _mat3x3f_proxy;

		kiwi::mat3x3f_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_mat3x3f_proxy select(std::size_t number) noexcept;
		kiwi::mat3x3f_set& to_binding(GLuint binding) noexcept;
		const kiwi::mat3x3f_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _mat3x3f_proxy
	{

	private:

		kiwi::mat3x3f_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class mat3x3f_set;

		kiwi::_mat3x3f_proxy& set_matrix(const GLfloat* const matrix_ptr) noexcept;
	};
}

namespace kiwi
{
	class _mat4x4f_proxy;

	class mat4x4f_set
	{

	public:

		friend class _mat4x4f_proxy;

		kiwi::mat4x4f_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_mat4x4f_proxy select(std::size_t number) noexcept;
		kiwi::mat4x4f_set& to_binding(GLuint binding) noexcept;
		const kiwi::mat4x4f_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _mat4x4f_proxy
	{

	private:

		kiwi::mat4x4f_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class mat4x4f_set;

		kiwi::_mat4x4f_proxy& set_matrix(const GLfloat* const matrix_ptr) noexcept;
	};
}

namespace kiwi
{
	class _skylight_proxy;
	class skylight_loader;
	class _skylight_loader_proxy;

	class _pointlight_proxy;
	class pointlight_loader;
	class _pointlight_loader_proxy;

	class _spotlight_proxy;
	class spotlight_loader;
	class _spotlight_loader_proxy;

	class lightset
	{

	public:

		friend class _skylight_proxy;
		friend class skylight_loader;

		friend class _pointlight_proxy;
		friend class pointlight_loader;

		friend class _spotlight_proxy;
		friend class spotlight_loader;

		kiwi::lightset& allocate(std::size_t number_of_skylights, std::size_t number_of_pointlights, std::size_t number_of_spotlights) noexcept;

		kiwi::_skylight_proxy select_skylight(std::size_t number) noexcept;
		kiwi::_pointlight_proxy select_pointlight(std::size_t number) noexcept;
		kiwi::_spotlight_proxy select_spotlight(std::size_t number) noexcept;

		kiwi::lightset& to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) noexcept;
		const kiwi::lightset& to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) const noexcept;

		kiwi::lightset& set_ambient_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		const GLfloat* ambient_RGB_data() const noexcept;

		kiwi::skylight_loader get_skylight_loader(void* ptr) noexcept;
		kiwi::skylight_loader get_skylight_loader(void* ptr, std::size_t count) noexcept;
		kiwi::skylight_loader get_skylight_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

		kiwi::pointlight_loader get_pointlight_loader(void* ptr) noexcept;
		kiwi::pointlight_loader get_pointlight_loader(void* ptr, std::size_t count) noexcept;
		kiwi::pointlight_loader get_pointlight_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

		kiwi::spotlight_loader get_spotlight_loader(void* ptr) noexcept;
		kiwi::spotlight_loader get_spotlight_loader(void* ptr, std::size_t count) noexcept;
		kiwi::spotlight_loader get_spotlight_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

	private:

		kiwi::storage_buffer m_skylights;
		kiwi::storage_buffer m_pointlights;
		kiwi::storage_buffer m_spotlights;
		GLfloat m_ambient_RGB[3] = { static_cast<GLfloat>(0) };
		std::size_t m_skylight_count;
		std::size_t m_pointlight_count;
		std::size_t m_spotlight_count;
	};

	class _skylight_proxy
	{

	public:

		friend class lightset;

		kiwi::_skylight_proxy& set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_skylight_proxy& set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		kiwi::_skylight_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		kiwi::_skylight_proxy& set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept;
		kiwi::_skylight_proxy& set_diff(GLfloat diff) noexcept;
		kiwi::_skylight_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		kiwi::_skylight_proxy& set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept;

	private:

		kiwi::lightset* m_lightset_ptr;
		std::size_t m_number;
	};

	class skylight_loader
	{

	private:

		skylight_loader() noexcept;

	public:

		skylight_loader(const kiwi::pointlight_loader& rhs) = delete;
		kiwi::skylight_loader& operator=(const kiwi::skylight_loader& rhs) = delete;
		skylight_loader(kiwi::skylight_loader&& rhs) noexcept;
		kiwi::skylight_loader& operator=(kiwi::skylight_loader&& rhs) noexcept;
		~skylight_loader();

		kiwi::_skylight_loader_proxy operator[](std::size_t number) noexcept;
		void cancel() noexcept;

	private:

		friend class lightset;

		GLfloat* m_data_ptr;
		kiwi::lightset* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _skylight_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;

	public:

		friend class skylight_loader;

		inline kiwi::_skylight_loader_proxy& set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_skylight_loader_proxy& set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		inline kiwi::_skylight_loader_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		inline kiwi::_skylight_loader_proxy& set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept;
		inline kiwi::_skylight_loader_proxy& set_diff(GLfloat diff) noexcept;
		inline kiwi::_skylight_loader_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		inline kiwi::_skylight_loader_proxy& set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept;

		inline GLfloat& dir_X() noexcept;
		inline GLfloat& dir_Y() noexcept;
		inline GLfloat& dir_Z() noexcept;

		inline GLfloat& R() noexcept;
		inline GLfloat& G() noexcept;
		inline GLfloat& B() noexcept;
		inline GLfloat& diff() noexcept;
	};

	class _pointlight_proxy
	{

	public:

		friend class lightset;

		kiwi::_pointlight_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_pointlight_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		kiwi::_pointlight_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_pointlight_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;

		kiwi::_pointlight_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		kiwi::_pointlight_proxy& set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept;
		kiwi::_pointlight_proxy& set_diff(GLfloat diff) noexcept;
		kiwi::_pointlight_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		kiwi::_pointlight_proxy& set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept;

		kiwi::_pointlight_proxy& set_attenuation(GLfloat quadratic, GLfloat constant) noexcept;

	private:

		kiwi::lightset* m_lightset_ptr;
		std::size_t m_number;
	};

	class pointlight_loader
	{

	private:

		pointlight_loader() noexcept;

	public:

		pointlight_loader(const kiwi::pointlight_loader& rhs) = delete;
		kiwi::pointlight_loader& operator=(const kiwi::pointlight_loader& rhs) = delete;
		pointlight_loader(kiwi::pointlight_loader&& rhs) noexcept;
		kiwi::pointlight_loader& operator=(kiwi::pointlight_loader&& rhs) noexcept;
		~pointlight_loader();

		kiwi::_pointlight_loader_proxy operator[](std::size_t number) noexcept;
		void cancel() noexcept;

	private:

		friend class lightset;

		GLfloat* m_data_ptr;
		kiwi::lightset* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _pointlight_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;

	public:

		friend class pointlight_loader;

		inline kiwi::_pointlight_loader_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_pointlight_loader_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		inline kiwi::_pointlight_loader_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		inline kiwi::_pointlight_loader_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;

		inline kiwi::_pointlight_loader_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		inline kiwi::_pointlight_loader_proxy& set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept;
		inline kiwi::_pointlight_loader_proxy& set_diff(GLfloat diff) noexcept;
		inline kiwi::_pointlight_loader_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		inline kiwi::_pointlight_loader_proxy& set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept;

		inline kiwi::_pointlight_loader_proxy& set_attenuation(GLfloat quadratic, GLfloat constant) noexcept;

		inline GLfloat& X() noexcept;
		inline GLfloat& Y() noexcept;
		inline GLfloat& Z() noexcept;

		inline GLfloat& R() noexcept;
		inline GLfloat& G() noexcept;
		inline GLfloat& B() noexcept;
		inline GLfloat& diff() noexcept;

		inline GLfloat& attenuation_quadratic() noexcept;
		inline GLfloat& attenuation_constant() noexcept;
	};

	class _spotlight_proxy
	{

	public:

		friend class lightset;

		kiwi::_spotlight_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_spotlight_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		kiwi::_spotlight_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_spotlight_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;

		kiwi::_spotlight_proxy& set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_spotlight_proxy& set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		kiwi::_spotlight_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		kiwi::_spotlight_proxy& set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept;
		kiwi::_spotlight_proxy& set_diff(GLfloat diff) noexcept;
		kiwi::_spotlight_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		kiwi::_spotlight_proxy& set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept;

		kiwi::_spotlight_proxy& set_attenuation(GLfloat quadratic, GLfloat constant, GLfloat edge_min, GLfloat edge_max) noexcept;

	private:

		kiwi::lightset* m_lightset_ptr;
		std::size_t m_number;
	};

	class spotlight_loader
	{

	private:

		spotlight_loader() noexcept;

	public:

		spotlight_loader(const kiwi::spotlight_loader& rhs) = delete;
		kiwi::spotlight_loader& operator=(const kiwi::spotlight_loader& rhs) = delete;
		spotlight_loader(kiwi::spotlight_loader&& rhs) noexcept;
		kiwi::spotlight_loader& operator=(kiwi::spotlight_loader&& rhs) noexcept;
		~spotlight_loader();

		kiwi::_spotlight_loader_proxy operator[](std::size_t number) noexcept;
		void cancel() noexcept;

	private:

		friend class lightset;

		GLfloat* m_data_ptr;
		kiwi::lightset* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _spotlight_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;

	public:

		friend class spotlight_loader;

		inline kiwi::_spotlight_loader_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		inline kiwi::_spotlight_loader_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;

		inline kiwi::_spotlight_loader_proxy& set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;

		inline kiwi::_spotlight_loader_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_diff(GLfloat diff) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		inline kiwi::_spotlight_loader_proxy& set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept;

		inline kiwi::_spotlight_loader_proxy& set_attenuation(GLfloat quadratic, GLfloat constant, GLfloat edge_min, GLfloat edge_max) noexcept;

		inline GLfloat& X() noexcept;
		inline GLfloat& Y() noexcept;
		inline GLfloat& Z() noexcept;

		inline GLfloat& dir_X() noexcept;
		inline GLfloat& dir_Y() noexcept;
		inline GLfloat& dir_Z() noexcept;

		inline GLfloat& R() noexcept;
		inline GLfloat& G() noexcept;
		inline GLfloat& B() noexcept;
		inline GLfloat& diff() noexcept;

		inline GLfloat& attenuation_quadratic() noexcept;
		inline GLfloat& attenuation_constant() noexcept;
		inline GLfloat& edge_min() noexcept;
		inline GLfloat& edge_max() noexcept;
	};
}


namespace kiwi
{
	class light_selection
	{

	public:

		kiwi::light_selection& allocate(std::size_t number_of_skylights, std::size_t number_of_pointlights, std::size_t number_of_spotlights) noexcept;

		const GLuint* number_of_lights_data() const noexcept;

		kiwi::light_selection& select_skylights(GLint* skylight_id_ptr, std::size_t number_of_skylights) noexcept;
		kiwi::light_selection& select_pointlights(GLint* skylight_id_ptr, std::size_t number_of_pointlights) noexcept;
		kiwi::light_selection& select_splotlights(GLint* skylight_id_ptr, std::size_t number_of_spotlights) noexcept;

		kiwi::light_selection& to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) noexcept;
		const kiwi::light_selection& to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) const noexcept;

	private:

		kiwi::storage_buffer m_skylight_id;
		kiwi::storage_buffer m_pointlight_id;
		kiwi::storage_buffer m_spotlight_id;
		GLuint number_of_lights[3] = { 0, 0, 0 };
	};
}


// INLINE IMPLEMENTATION

// XYZA_set
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
{
	*m_buffer_ptr = *XY_ptr;
	*(m_buffer_ptr + 1) = *(XY_ptr + 1);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XYA(GLfloat X, GLfloat Y, GLfloat A) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 3) = A;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XYA(const GLfloat* const _KIWI_RESTRICT XYA_ptr) noexcept
{
	*m_buffer_ptr = *XYA_ptr;
	*(m_buffer_ptr + 1) = *(XYA_ptr + 1);
	*(m_buffer_ptr + 3) = *(XYA_ptr + 2);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	*m_buffer_ptr = *XYZ_ptr;
	*(m_buffer_ptr + 1) = *(XYZ_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZ_ptr + 2);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat angle) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	*(m_buffer_ptr + 3) = angle;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept
{
	*m_buffer_ptr = *XYZA_ptr;
	*(m_buffer_ptr + 1) = *(XYZA_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZA_ptr + 2);
	*(m_buffer_ptr + 3) = *(XYZA_ptr + 3);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::set_angle(GLfloat angle) noexcept
{
	*(m_buffer_ptr + 3) = angle;
	return *this;
}

inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_X(GLfloat distance) noexcept
{
	*m_buffer_ptr += distance;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_Y(GLfloat distance) noexcept
{
	*(m_buffer_ptr + 1) += distance;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_Z(GLfloat distance) noexcept
{
	*(m_buffer_ptr + 2) += distance;
	return *this;
}

inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_XY(GLfloat distance_X, GLfloat distance_Y) noexcept
{
	*m_buffer_ptr += distance_X;
	*(m_buffer_ptr + 1) += distance_Y;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_XY(const GLfloat* const _KIWI_RESTRICT distance_XY_ptr) noexcept
{
	*m_buffer_ptr += *distance_XY_ptr;
	*(m_buffer_ptr + 1) += *(distance_XY_ptr + 1);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_XYZ(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z) noexcept
{
	*m_buffer_ptr += distance_X;
	*(m_buffer_ptr + 1) += distance_Y;
	*(m_buffer_ptr + 2) += distance_Z;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_XYZ(const GLfloat* const _KIWI_RESTRICT distance_XYZ_ptr) noexcept
{
	*m_buffer_ptr += *distance_XYZ_ptr;
	*(m_buffer_ptr + 1) += *(distance_XYZ_ptr + 1);
	*(m_buffer_ptr + 2) += *(distance_XYZ_ptr + 2);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_XYZA(GLfloat distance_X, GLfloat distance_Y, GLfloat distance_Z, GLfloat angle) noexcept
{
	*m_buffer_ptr += distance_X;
	*(m_buffer_ptr + 1) += distance_Y;
	*(m_buffer_ptr + 2) += distance_Z;
	*(m_buffer_ptr + 3) += angle;
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_XYZA(const GLfloat* const _KIWI_RESTRICT distance_XYZA_ptr) noexcept
{
	*m_buffer_ptr += *distance_XYZA_ptr;
	*(m_buffer_ptr + 1) += *(distance_XYZA_ptr + 1);
	*(m_buffer_ptr + 2) += *(distance_XYZA_ptr + 2);
	*(m_buffer_ptr + 3) += *(distance_XYZA_ptr + 3);
	return *this;
}
inline kiwi::_XYZA_loader_proxy& kiwi::_XYZA_loader_proxy::move_angle(GLfloat angle) noexcept
{
	*(m_buffer_ptr + 3) += angle;
	return *this;
}

inline GLfloat& kiwi::_XYZA_loader_proxy::X(GLfloat angle) noexcept
{
	return *m_buffer_ptr;
}
inline GLfloat& kiwi::_XYZA_loader_proxy::Y(GLfloat angle) noexcept
{
	return *(m_buffer_ptr + 1);
}
inline GLfloat& kiwi::_XYZA_loader_proxy::Z(GLfloat angle) noexcept
{
	return *(m_buffer_ptr + 2);
}
inline GLfloat& kiwi::_XYZA_loader_proxy::angle(GLfloat angle) noexcept
{
	return *(m_buffer_ptr + 3);
}


// RGBA_set
inline kiwi::_RGBA_loader_proxy& kiwi::_RGBA_loader_proxy::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	*m_buffer_ptr = R;
	*(m_buffer_ptr + 1) = G;
	*(m_buffer_ptr + 2) = B;
	*(m_buffer_ptr + 3) = A;
	return *this;
}
inline kiwi::_RGBA_loader_proxy& kiwi::_RGBA_loader_proxy::set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept
{
	*m_buffer_ptr = *RGBA_ptr;
	*(m_buffer_ptr + 1) = *(RGBA_ptr + 1);
	*(m_buffer_ptr + 2) = *(RGBA_ptr + 2);
	*(m_buffer_ptr + 3) = *(RGBA_ptr + 3);
	return *this;
}

inline GLfloat& kiwi::_RGBA_loader_proxy::R() noexcept
{
	return *m_buffer_ptr;
}
inline GLfloat& kiwi::_RGBA_loader_proxy::G() noexcept
{
	return *(m_buffer_ptr + 1);
}
inline GLfloat& kiwi::_RGBA_loader_proxy::B() noexcept
{
	return *(m_buffer_ptr + 2);
}
inline GLfloat& kiwi::_RGBA_loader_proxy::A() noexcept
{
	return *(m_buffer_ptr + 3);
}


// UV_set

inline kiwi::UV_loader kiwi::UV_set::get_loader(void* ptr) noexcept
{
	kiwi::UV_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::UV_loader kiwi::UV_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::UV_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::UV_loader kiwi::UV_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::UV_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

GLfloat kiwi::UV_set::get_U_size() const noexcept
{
	return m_UV_size[0];
}
GLfloat kiwi::UV_set::get_V_size() const noexcept
{
	return m_UV_size[1];
}

inline kiwi::UV_loader::UV_loader() noexcept {}
inline kiwi::UV_loader::UV_loader(kiwi::UV_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	rhs.m_data_ptr = nullptr;
	rhs.m_set_ptr = nullptr;
	rhs.m_first = 0;
	rhs.m_count = 0;
}
inline kiwi::UV_loader& kiwi::UV_loader::operator=(kiwi::UV_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	rhs.m_data_ptr = nullptr;
	rhs.m_set_ptr = nullptr;
	rhs.m_first = 0;
	rhs.m_count = 0;

	return *this;
}
inline kiwi::UV_loader::~UV_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (2 * sizeof(GLfloat)), m_count * (2 * sizeof(GLfloat)));
	}
}

inline kiwi::_UV_loader_proxy kiwi::UV_loader::operator[](std::size_t number) noexcept
{
	kiwi::_UV_loader_proxy proxy;
	proxy.m_buffer_ptr = m_data_ptr + (number - m_first) * 2;
	proxy.m_altas_coordinate_function_ptr = &(m_set_ptr->m_atlas_coordinate_function);
	return proxy;
}
inline void kiwi::UV_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

inline kiwi::_UV_loader_proxy& kiwi::_UV_loader_proxy::set_UV(GLfloat U, GLfloat V) noexcept
{
	*m_buffer_ptr = U;
	*(m_buffer_ptr + 1) = V;
	return *this;
}
inline kiwi::_UV_loader_proxy& kiwi::_UV_loader_proxy::set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept
{
	*m_buffer_ptr = *UV_ptr;
	*(m_buffer_ptr + 1) = *(UV_ptr + 1);
	return *this;
}
inline kiwi::_UV_loader_proxy& kiwi::_UV_loader_proxy::operator=(int tile) noexcept
{
	(*m_altas_coordinate_function_ptr)(tile, m_buffer_ptr);
	return *this;
}

inline GLfloat& kiwi::_UV_loader_proxy::U() noexcept
{
	return *m_buffer_ptr;
}
inline GLfloat& kiwi::_UV_loader_proxy::V() noexcept
{
	return *(m_buffer_ptr + 1);
}

inline GLint& kiwi::id_loader::operator[](std::size_t number) noexcept
{
	return *(m_data_ptr + (number - m_first));
}


inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(X * X + Y * Y + Z * Z);
	*m_buffer_ptr = temp * X;
	*(m_buffer_ptr + 1) = temp * Y;
	*(m_buffer_ptr + 2) = temp * Z;
	return *this;
}
inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	GLfloat _X = *XYZ_ptr;
	GLfloat _Y = *(XYZ_ptr + 1);
	GLfloat _Z = *(XYZ_ptr + 2);
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(_X * _X + _Y * _Y + _Z * _Z);
	*m_buffer_ptr = temp * _X;
	*(m_buffer_ptr + 1) = temp * _Y;
	*(m_buffer_ptr + 2) = temp * _Z;
	return *this;
}

inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	*(m_buffer_ptr + 4) = R;
	*(m_buffer_ptr + 5) = G;
	*(m_buffer_ptr + 6) = B;
	return *this;
}
inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept
{
	*(m_buffer_ptr + 4) = *RGB_ptr;
	*(m_buffer_ptr + 5) = *(RGB_ptr + 1);
	*(m_buffer_ptr + 6) = *(RGB_ptr + 2);
	return *this;
}
inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_diff(GLfloat diff) noexcept
{
	*(m_buffer_ptr + 7) = diff;
	return *this;
}
inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept
{
	*(m_buffer_ptr + 4) = R;
	*(m_buffer_ptr + 5) = G;
	*(m_buffer_ptr + 6) = B;
	*(m_buffer_ptr + 7) = diff;
	return *this;
}
inline kiwi::_skylight_loader_proxy& kiwi::_skylight_loader_proxy::set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept
{
	*(m_buffer_ptr + 4) = *RGB_diff_ptr;
	*(m_buffer_ptr + 5) = *(RGB_diff_ptr + 1);
	*(m_buffer_ptr + 6) = *(RGB_diff_ptr + 2);
	*(m_buffer_ptr + 7) = *(RGB_diff_ptr + 3);
	return *this;
}

inline GLfloat& kiwi::_skylight_loader_proxy::dir_X() noexcept
{
	return *m_buffer_ptr;
}
inline GLfloat& kiwi::_skylight_loader_proxy::dir_Y() noexcept
{
	return *(m_buffer_ptr + 1);
}
inline GLfloat& kiwi::_skylight_loader_proxy::dir_Z() noexcept
{
	return *(m_buffer_ptr + 2);
}

inline GLfloat& kiwi::_skylight_loader_proxy::R() noexcept
{
	return *(m_buffer_ptr + 4);
}
inline GLfloat& kiwi::_skylight_loader_proxy::G() noexcept
{
	return *(m_buffer_ptr + 5);
}
inline GLfloat& kiwi::_skylight_loader_proxy::B() noexcept
{
	return *(m_buffer_ptr + 6);
}
inline GLfloat& kiwi::_skylight_loader_proxy::diff() noexcept
{
	return *(m_buffer_ptr + 7);
}

inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	return *this;
}
inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	*m_buffer_ptr = *XYZ_ptr;
	*(m_buffer_ptr + 1) = *(XYZ_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZ_ptr + 2);
	return *this;
}

inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	return *this;
}
inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
{
	*m_buffer_ptr = *XY_ptr;
	*(m_buffer_ptr + 1) = *(XY_ptr + 1);
	return *this;
}

inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	*(m_buffer_ptr + 4) = R;
	*(m_buffer_ptr + 5) = G;
	*(m_buffer_ptr + 6) = B;
	return *this;
}
inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept
{
	*(m_buffer_ptr + 4) = *RGB_ptr;
	*(m_buffer_ptr + 5) = *(RGB_ptr + 1);
	*(m_buffer_ptr + 6) = *(RGB_ptr + 2);
	return *this;
}
inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_diff(GLfloat diff) noexcept
{
	*(m_buffer_ptr + 7) = diff;
	return *this;
}
inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept
{
	*(m_buffer_ptr + 4) = R;
	*(m_buffer_ptr + 5) = G;
	*(m_buffer_ptr + 6) = B;
	*(m_buffer_ptr + 7) = diff;
	return *this;
}
inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept
{
	*(m_buffer_ptr + 4) = *RGB_diff_ptr;
	*(m_buffer_ptr + 5) = *(RGB_diff_ptr + 1);
	*(m_buffer_ptr + 6) = *(RGB_diff_ptr + 2);
	*(m_buffer_ptr + 7) = *(RGB_diff_ptr + 3);
	return *this;
}

inline kiwi::_pointlight_loader_proxy& kiwi::_pointlight_loader_proxy::set_attenuation(GLfloat quadratic, GLfloat constant) noexcept
{
	*(m_buffer_ptr + 8) = quadratic;
	*(m_buffer_ptr + 9) = constant;
	return *this;
}

inline GLfloat& kiwi::_pointlight_loader_proxy::X() noexcept
{
	return *m_buffer_ptr;
}
inline GLfloat& kiwi::_pointlight_loader_proxy::Y() noexcept
{
	return *(m_buffer_ptr + 1);
}
inline GLfloat& kiwi::_pointlight_loader_proxy::Z() noexcept
{
	return *(m_buffer_ptr + 2);
}

inline GLfloat& kiwi::_pointlight_loader_proxy::R() noexcept
{
	return *(m_buffer_ptr + 4);
}
inline GLfloat& kiwi::_pointlight_loader_proxy::G() noexcept
{
	return *(m_buffer_ptr + 5);
}
inline GLfloat& kiwi::_pointlight_loader_proxy::B() noexcept
{
	return *(m_buffer_ptr + 6);
}
inline GLfloat& kiwi::_pointlight_loader_proxy::diff() noexcept
{
	return *(m_buffer_ptr + 7);
}

inline GLfloat& kiwi::_pointlight_loader_proxy::attenuation_quadratic() noexcept
{
	return *(m_buffer_ptr + 8);
}
inline GLfloat& kiwi::_pointlight_loader_proxy::attenuation_constant() noexcept
{
	return *(m_buffer_ptr + 9);
}


inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	*m_buffer_ptr = *XYZ_ptr;
	*(m_buffer_ptr + 1) = *(XYZ_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZ_ptr + 2);
	return *this;
}

inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
{
	*m_buffer_ptr = *XY_ptr;
	*(m_buffer_ptr + 1) = *(XY_ptr + 1);
	return *this;
}

inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(X * X + Y * Y + Z * Z);
	*(m_buffer_ptr + 4) = temp * X;
	*(m_buffer_ptr + 5) = temp * Y;
	*(m_buffer_ptr + 6) = temp * Z;
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	GLfloat _X = *XYZ_ptr;
	GLfloat _Y = *(XYZ_ptr + 1);
	GLfloat _Z = *(XYZ_ptr + 2);
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(_X * _X + _Y * _Y + _Z * _Z);
	*(m_buffer_ptr + 4) = temp * _X;
	*(m_buffer_ptr + 5) = temp * _Y;
	*(m_buffer_ptr + 6) = temp * _Z;
	return *this;
}

inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	*(m_buffer_ptr + 8) = R;
	*(m_buffer_ptr + 9) = G;
	*(m_buffer_ptr + 10) = B;
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept
{
	*(m_buffer_ptr + 8) = *RGB_ptr;
	*(m_buffer_ptr + 9) = *(RGB_ptr + 1);
	*(m_buffer_ptr + 10) = *(RGB_ptr + 2);
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_diff(GLfloat diff) noexcept
{
	*(m_buffer_ptr + 11) = diff;
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept
{
	*(m_buffer_ptr + 8) = R;
	*(m_buffer_ptr + 9) = G;
	*(m_buffer_ptr + 10) = B;
	*(m_buffer_ptr + 11) = diff;
	return *this;
}
inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept
{
	*(m_buffer_ptr + 8) = *RGB_diff_ptr;
	*(m_buffer_ptr + 9) = *(RGB_diff_ptr + 1);
	*(m_buffer_ptr + 10) = *(RGB_diff_ptr + 2);
	*(m_buffer_ptr + 11) = *(RGB_diff_ptr + 3);
	return *this;
}

inline kiwi::_spotlight_loader_proxy& kiwi::_spotlight_loader_proxy::set_attenuation(GLfloat quadratic, GLfloat constant, GLfloat edge_min, GLfloat edge_max) noexcept
{
	*(m_buffer_ptr + 12) = quadratic;
	*(m_buffer_ptr + 13) = constant;
	*(m_buffer_ptr + 14) = edge_min;
	*(m_buffer_ptr + 15) = edge_max;
	return *this;
}

inline GLfloat& kiwi::_spotlight_loader_proxy::X() noexcept
{
	return *m_buffer_ptr;
}
inline GLfloat& kiwi::_spotlight_loader_proxy::Y() noexcept
{
	return *(m_buffer_ptr + 1);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::Z() noexcept
{
	return *(m_buffer_ptr + 2);
}

inline GLfloat& kiwi::_spotlight_loader_proxy::dir_X() noexcept
{
	return *(m_buffer_ptr + 4);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::dir_Y() noexcept
{
	return *(m_buffer_ptr + 5);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::dir_Z() noexcept
{
	return *(m_buffer_ptr + 6);
}

inline GLfloat& kiwi::_spotlight_loader_proxy::R() noexcept
{
	return *(m_buffer_ptr + 8);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::G() noexcept
{
	return *(m_buffer_ptr + 9);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::B() noexcept
{
	return *(m_buffer_ptr + 10);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::diff() noexcept
{
	return *(m_buffer_ptr + 11);
}

inline GLfloat& kiwi::_spotlight_loader_proxy::attenuation_quadratic() noexcept
{
	return *(m_buffer_ptr + 12);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::attenuation_constant() noexcept
{
	return *(m_buffer_ptr + 13);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::edge_min() noexcept
{
	return *(m_buffer_ptr + 14);
}
inline GLfloat& kiwi::_spotlight_loader_proxy::edge_max() noexcept
{
	return *(m_buffer_ptr + 15);
}

#endif // _KIWI_SETS_HPP