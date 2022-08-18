#ifndef KIWI_SETS_HPP
#define KIWI_SETS_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_texture.hpp"
#include "buffers/kiwi_buffer_storage.hpp"
#include "header_utils/kiwi_restrict.hpp"


// XYZA_RGBA

namespace kiwi
{
	class _XYZA_RGBA_proxy;
	class XYZA_RGBA_loader;
	class _XYZA_RGBA_loader_proxy;

	class XYZA_RGBA_set
	{

	public:

		friend class _XYZA_RGBA_proxy;
		friend class XYZA_RGBA_loader;

		kiwi::XYZA_RGBA_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZA_RGBA_proxy select(std::size_t number) noexcept;
		kiwi::XYZA_RGBA_set& to_binding(GLuint binding) noexcept;
		const kiwi::XYZA_RGBA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

		inline kiwi::XYZA_RGBA_loader get_loader(void* ptr) noexcept;
		inline kiwi::XYZA_RGBA_loader get_loader(void* ptr, std::size_t count) noexcept;
		inline kiwi::XYZA_RGBA_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XYZA_RGBA_proxy
	{

	public:

		friend class XYZA_RGBA_set;

		kiwi::_XYZA_RGBA_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat angle) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_angle(GLfloat angle) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		kiwi::_XYZA_RGBA_proxy& set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept;

	private:

		kiwi::XYZA_RGBA_set* m_set_ptr;
		std::size_t m_number;
	};

	class XYZA_RGBA_loader
	{

	private:

		inline XYZA_RGBA_loader() noexcept;

	public:

		XYZA_RGBA_loader(const kiwi::XYZA_RGBA_loader& rhs) = delete;
		kiwi::XYZA_RGBA_loader& operator=(const kiwi::XYZA_RGBA_loader& rhs) = delete;
		inline XYZA_RGBA_loader(kiwi::XYZA_RGBA_loader&& rhs) noexcept;
		inline kiwi::XYZA_RGBA_loader& operator=(kiwi::XYZA_RGBA_loader&& rhs) noexcept;
		inline ~XYZA_RGBA_loader();

		inline kiwi::_XYZA_RGBA_loader_proxy select(std::size_t number) noexcept;
		inline void cancel() noexcept;

	private:

		friend class XYZA_RGBA_set;

		char* m_data_ptr;
		kiwi::XYZA_RGBA_set* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _XYZA_RGBA_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;

	public:

		friend class XYZA_RGBA_loader;

		inline kiwi::_XYZA_RGBA_loader_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_angle(GLfloat angle) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_RGBA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		inline kiwi::_XYZA_RGBA_loader_proxy& set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept;
	};
}


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
		kiwi::_XYZA_proxy select(std::size_t number) noexcept;
		kiwi::XYZA_set& to_binding(GLuint binding) noexcept;
		const kiwi::XYZA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

		inline kiwi::XYZA_loader get_loader(void* ptr) noexcept;
		inline kiwi::XYZA_loader get_loader(void* ptr, std::size_t count) noexcept;
		inline kiwi::XYZA_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

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

		inline XYZA_loader() noexcept;

	public:

		XYZA_loader(const kiwi::XYZA_loader& rhs) = delete;
		kiwi::XYZA_loader& operator=(const kiwi::XYZA_loader& rhs) = delete;
		inline XYZA_loader(kiwi::XYZA_loader&& rhs) noexcept;
		inline kiwi::XYZA_loader& operator=(kiwi::XYZA_loader&& rhs) noexcept;
		inline ~XYZA_loader();

		inline kiwi::_XYZA_loader_proxy select(std::size_t number) noexcept;
		inline void cancel() noexcept;

	private:

		friend class XYZA_set;

		char* m_data_ptr;
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
		inline kiwi::_XYZA_loader_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		inline kiwi::_XYZA_loader_proxy& set_angle(GLfloat angle) noexcept;
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
		kiwi::_RGBA_proxy select(std::size_t number) noexcept;
		kiwi::RGBA_set& to_binding(GLuint binding) noexcept;
		const kiwi::RGBA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

		inline kiwi::RGBA_loader get_loader(void* ptr) noexcept;
		inline kiwi::RGBA_loader get_loader(void* ptr, std::size_t count) noexcept;
		inline kiwi::RGBA_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

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

		inline RGBA_loader() noexcept;

	public:

		RGBA_loader(const kiwi::RGBA_loader& rhs) = delete;
		kiwi::RGBA_loader& operator=(const kiwi::RGBA_loader& rhs) = delete;
		inline RGBA_loader(kiwi::RGBA_loader&& rhs) noexcept;
		inline kiwi::RGBA_loader& operator=(kiwi::RGBA_loader&& rhs) noexcept;
		inline ~RGBA_loader();

		inline kiwi::_RGBA_loader_proxy select(std::size_t number) noexcept;
		inline void cancel() noexcept;

	private:

		friend class RGBA_set;

		char* m_data_ptr;
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
		kiwi::_UV_proxy select(std::size_t number) noexcept;
		kiwi::UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::UV_set& set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
			std::function<void(const int, GLfloat* ptr)> atlas_function, const kiwi::UV& UV_size) noexcept;

		inline kiwi::UV_loader get_loader(void* ptr) noexcept;
		inline kiwi::UV_loader get_loader(void* ptr, std::size_t count) noexcept;
		inline kiwi::UV_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

		inline GLfloat get_U_size() const noexcept;
		inline GLfloat get_V_size() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_buffer* m_atlas_texture = nullptr;
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

		inline kiwi::_UV_loader_proxy select(std::size_t number) noexcept;
		inline void cancel() noexcept;

	private:

		friend class UV_set;

		char* m_data_ptr;
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
		inline kiwi::_UV_loader_proxy& set_tile(int tile) noexcept;
	};
}

namespace kiwi
{
	class _XYZA_UV_proxy;
	class XYZA_UV_loader;
	class _XYZA_UV_loader_proxy;
	class XYZA_UV_set
	{

	public:

		friend class _XYZA_UV_proxy;
		friend class XYZA_UV_loader;

		kiwi::XYZA_UV_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZA_UV_proxy select(std::size_t number) noexcept;
		kiwi::XYZA_UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::XYZA_UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::XYZA_UV_set& set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
			std::function<void(const int, GLfloat* ptr)> atlas_function, const kiwi::UV& UV_size) noexcept;

		inline kiwi::XYZA_UV_loader get_loader(void* ptr) noexcept;
		inline kiwi::XYZA_UV_loader get_loader(void* ptr, std::size_t count) noexcept;
		inline kiwi::XYZA_UV_loader get_loader(void* ptr, std::size_t first, std::size_t count) noexcept;

		inline GLfloat get_U_size() const noexcept;
		inline GLfloat get_V_size() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_buffer* m_atlas_texture = nullptr;
		std::function<void(const int, GLfloat*)> m_atlas_coordinate_function;
		GLfloat m_UV_size[2] = { static_cast<GLfloat>(0) };
	};

	class _XYZA_UV_proxy
	{

	private:

		kiwi::XYZA_UV_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class XYZA_UV_set;

		kiwi::_XYZA_UV_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XYZA_UV_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;
		kiwi::_XYZA_UV_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZA_UV_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		kiwi::_XYZA_UV_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A) noexcept;
		kiwi::_XYZA_UV_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		kiwi::_XYZA_UV_proxy& set_angle(GLfloat angle) noexcept;
		kiwi::_XYZA_UV_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		kiwi::_XYZA_UV_proxy& set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept;
		kiwi::_XYZA_UV_proxy& set_tile(int tile) noexcept;
	};

	class XYZA_UV_loader
	{

	private:

		inline XYZA_UV_loader() noexcept;

	public:

		XYZA_UV_loader(const kiwi::XYZA_UV_loader& rhs) = delete;
		kiwi::XYZA_UV_loader& operator=(const kiwi::XYZA_UV_loader& rhs) = delete;
		inline XYZA_UV_loader(kiwi::XYZA_UV_loader&& rhs) noexcept;
		inline kiwi::XYZA_UV_loader& operator=(kiwi::XYZA_UV_loader&& rhs) noexcept;
		inline ~XYZA_UV_loader();

		inline kiwi::_XYZA_UV_loader_proxy select(std::size_t number) noexcept;
		inline void cancel() noexcept;

	private:

		friend class XYZA_UV_set;

		char* m_data_ptr;
		kiwi::XYZA_UV_set* m_set_ptr;
		std::size_t m_first;
		std::size_t m_count;
	};

	class _XYZA_UV_loader_proxy
	{

	private:

		GLfloat* m_buffer_ptr;
		std::function<void(const int, GLfloat*)>* m_altas_coordinate_function_ptr;

	public:

		friend class XYZA_UV_loader;

		inline kiwi::_XYZA_UV_loader_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat A) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_angle(GLfloat angle) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept;
		inline kiwi::_XYZA_UV_loader_proxy& set_tile(int tile) noexcept;
	};
}


namespace kiwi
{
	class _XY_id_proxy;

	class XY_id_set
	{

	public:

		friend class _XY_id_proxy;

		kiwi::XY_id_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XY_id_proxy select(std::size_t number) noexcept;
		kiwi::XY_id_set& to_binding(GLuint binding) noexcept;
		const kiwi::XY_id_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XY_id_proxy
	{

	private:

		kiwi::XY_id_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class XY_id_set;

		kiwi::_XY_id_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XY_id_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::_XY_id_proxy& set_id(GLushort id) noexcept;
	};
}


namespace kiwi
{
	class _XYZ_id_proxy;

	class XYZ_id_set
	{

	public:

		friend class _XYZ_id_proxy;

		kiwi::XYZ_id_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZ_id_proxy select(std::size_t number) noexcept;
		kiwi::XYZ_id_set& to_binding(GLuint binding) noexcept;
		const kiwi::XYZ_id_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XYZ_id_proxy
	{

	public:

		friend class XYZ_id_set;

		kiwi::_XYZ_id_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZ_id_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
		kiwi::_XYZ_id_proxy& set_id(GLushort id) noexcept;

	private:

		kiwi::XYZ_id_set* m_set_ptr;
		std::size_t m_number;
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
	class _pointlight_proxy;
	class _spotlight_proxy;

	class lightset
	{

	public:

		friend class _skylight_proxy;
		friend class _pointlight_proxy;
		friend class _spotlight_proxy;

		kiwi::lightset& allocate(std::size_t number_of_skylights, std::size_t number_of_pointlights, std::size_t number_of_spotlights) noexcept;

		kiwi::_skylight_proxy select_skylight(std::size_t number) noexcept;
		kiwi::_pointlight_proxy select_pointlight(std::size_t number) noexcept;
		kiwi::_spotlight_proxy select_spotlight(std::size_t number) noexcept;

		kiwi::lightset& to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) noexcept;
		const kiwi::lightset& to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) const noexcept;

		kiwi::lightset& set_ambient_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;

		const GLfloat* ambient_RGB_data() const noexcept;

	private:

		kiwi::storage_buffer m_skylights;
		kiwi::storage_buffer m_pointlights;
		kiwi::storage_buffer m_spotlights;
		GLfloat m_ambient_RGB[3] = { static_cast<GLfloat>(0) };
	};

	class _skylight_proxy
	{

	public:

		friend class lightset;

		kiwi::_skylight_proxy& set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_skylight_proxy& set_dir(const GLfloat* const XYZ_ptr) noexcept;

		kiwi::_skylight_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		kiwi::_skylight_proxy& set_RGB(const GLfloat* const RGB_ptr) noexcept;
		kiwi::_skylight_proxy& set_diff(GLfloat diff) noexcept;
		kiwi::_skylight_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		kiwi::_skylight_proxy& set_RGB_diff(const GLfloat* const RGB_diff_ptr) noexcept;

	private:

		kiwi::lightset* m_lightset_ptr;
		std::size_t m_number;
	};

	class _pointlight_proxy
	{

	public:

		friend class lightset;

		kiwi::_pointlight_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_pointlight_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;

		kiwi::_pointlight_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_pointlight_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;

		kiwi::_pointlight_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		kiwi::_pointlight_proxy& set_RGB(const GLfloat* const RGB_ptr) noexcept;
		kiwi::_pointlight_proxy& set_diff(GLfloat diff) noexcept;
		kiwi::_pointlight_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		kiwi::_pointlight_proxy& set_RGB_diff(const GLfloat* const RGB_diff_ptr) noexcept;

		kiwi::_pointlight_proxy& set_attenuation(GLfloat quadratic, GLfloat constant) noexcept;

	private:

		kiwi::lightset* m_lightset_ptr;
		std::size_t m_number;
	};

	class _spotlight_proxy
	{

	public:

		friend class lightset;

		kiwi::_spotlight_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_spotlight_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;

		kiwi::_spotlight_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_spotlight_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;

		kiwi::_spotlight_proxy& set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_spotlight_proxy& set_dir(const GLfloat* const XYZ_ptr) noexcept;

		kiwi::_spotlight_proxy& set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept;
		kiwi::_spotlight_proxy& set_RGB(const GLfloat* const RGB_ptr) noexcept;
		kiwi::_spotlight_proxy& set_diff(GLfloat diff) noexcept;
		kiwi::_spotlight_proxy& set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept;
		kiwi::_spotlight_proxy& set_RGB_diff(const GLfloat* const RGB_diff_ptr) noexcept;

		kiwi::_spotlight_proxy& set_attenuation(GLfloat quadratic, GLfloat constant, GLfloat edge_min, GLfloat edge_max) noexcept;

	private:

		kiwi::lightset* m_lightset_ptr;
		std::size_t m_number;
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

// XYZA_RGBA_set

inline kiwi::XYZA_RGBA_loader kiwi::XYZA_RGBA_set::get_loader(void* ptr) noexcept
{
	kiwi::XYZA_RGBA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::XYZA_RGBA_loader kiwi::XYZA_RGBA_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::XYZA_RGBA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::XYZA_RGBA_loader kiwi::XYZA_RGBA_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::XYZA_RGBA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

inline kiwi::XYZA_RGBA_loader::XYZA_RGBA_loader() noexcept {}
inline kiwi::XYZA_RGBA_loader::XYZA_RGBA_loader(kiwi::XYZA_RGBA_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	m_data_ptr = nullptr;
	m_set_ptr = nullptr;
	m_first = 0;
	m_count = 0;
}
inline kiwi::XYZA_RGBA_loader& kiwi::XYZA_RGBA_loader::operator=(kiwi::XYZA_RGBA_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	m_data_ptr = nullptr;
	m_set_ptr = nullptr;
	m_first = 0;
	m_count = 0;
}
inline kiwi::XYZA_RGBA_loader::~XYZA_RGBA_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (8 * sizeof(GLfloat)), m_count * (8 * sizeof(GLfloat)));
	}
}

inline kiwi::_XYZA_RGBA_loader_proxy kiwi::XYZA_RGBA_loader::select(std::size_t number) noexcept
{
	kiwi::_XYZA_RGBA_loader_proxy proxy;
	proxy.m_buffer_ptr = reinterpret_cast<GLfloat*>(m_data_ptr) + (number - m_first) * 8;
	return proxy;
}
inline void kiwi::XYZA_RGBA_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
{
	*m_buffer_ptr = *XY_ptr;
	*(m_buffer_ptr + 1) = *(XY_ptr + 1);
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	*m_buffer_ptr = *XYZ_ptr;
	*(m_buffer_ptr + 1) = *(XYZ_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZ_ptr + 2);
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat angle) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	*(m_buffer_ptr + 3) = angle;
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept
{
	*m_buffer_ptr = *XYZA_ptr;
	*(m_buffer_ptr + 1) = *(XYZA_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZA_ptr + 2);
	*(m_buffer_ptr + 3) = *(XYZA_ptr + 3);
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_angle(GLfloat angle) noexcept
{
	*(m_buffer_ptr + 3) = angle;
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	*(m_buffer_ptr + 4) = R;
	*(m_buffer_ptr + 5) = G;
	*(m_buffer_ptr + 6) = B;
	*(m_buffer_ptr + 7) = A;
	return *this;
}
inline kiwi::_XYZA_RGBA_loader_proxy& kiwi::_XYZA_RGBA_loader_proxy::set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept
{
	*(m_buffer_ptr + 4) = *RGBA_ptr;
	*(m_buffer_ptr + 5) = *(RGBA_ptr + 1);
	*(m_buffer_ptr + 6) = *(RGBA_ptr + 2);
	*(m_buffer_ptr + 7) = *(RGBA_ptr + 3);
	return *this;
}


// XYZA_set

inline kiwi::XYZA_loader kiwi::XYZA_set::get_loader(void* ptr) noexcept
{
	kiwi::XYZA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::XYZA_loader kiwi::XYZA_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::XYZA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::XYZA_loader kiwi::XYZA_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::XYZA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

inline kiwi::XYZA_loader::XYZA_loader() noexcept {}
inline kiwi::XYZA_loader::XYZA_loader(kiwi::XYZA_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	m_data_ptr = nullptr;
	m_set_ptr = nullptr;
	m_first = 0;
	m_count = 0;
}
inline kiwi::XYZA_loader& kiwi::XYZA_loader::operator=(kiwi::XYZA_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	m_data_ptr = nullptr;
	m_set_ptr = nullptr;
	m_first = 0;
	m_count = 0;
}
inline kiwi::XYZA_loader::~XYZA_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (4 * sizeof(GLfloat)), m_count * (4 * sizeof(GLfloat)));
	}
}

inline kiwi::_XYZA_loader_proxy kiwi::XYZA_loader::select(std::size_t number) noexcept
{
	kiwi::_XYZA_loader_proxy proxy;
	proxy.m_buffer_ptr = reinterpret_cast<GLfloat*>(m_data_ptr) + (number - m_first) * 4;
	return proxy;
}
inline void kiwi::XYZA_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

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


// RGBA_set

inline kiwi::RGBA_loader kiwi::RGBA_set::get_loader(void* ptr) noexcept
{
	kiwi::RGBA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::RGBA_loader kiwi::RGBA_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::RGBA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::RGBA_loader kiwi::RGBA_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::RGBA_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

inline kiwi::RGBA_loader::RGBA_loader() noexcept {}
inline kiwi::RGBA_loader::RGBA_loader(kiwi::RGBA_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	m_data_ptr = nullptr;
	m_set_ptr = nullptr;
	m_first = 0;
	m_count = 0;
}
inline kiwi::RGBA_loader& kiwi::RGBA_loader::operator=(kiwi::RGBA_loader&& rhs) noexcept
{
	m_data_ptr = rhs.m_data_ptr;
	m_set_ptr = rhs.m_set_ptr;
	m_first = rhs.m_first;
	m_count = rhs.m_count;

	m_data_ptr = nullptr;
	m_set_ptr = nullptr;
	m_first = 0;
	m_count = 0;
}
inline kiwi::RGBA_loader::~RGBA_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (4 * sizeof(GLfloat)), m_count * (4 * sizeof(GLfloat)));
	}
}

inline kiwi::_RGBA_loader_proxy kiwi::RGBA_loader::select(std::size_t number) noexcept
{
	kiwi::_RGBA_loader_proxy proxy;
	proxy.m_buffer_ptr = reinterpret_cast<GLfloat*>(m_data_ptr) + (number - m_first) * 4;
	return proxy;
}
inline void kiwi::RGBA_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

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

// UV_set

inline kiwi::UV_loader kiwi::UV_set::get_loader(void* ptr) noexcept
{
	kiwi::UV_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::UV_loader kiwi::UV_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::UV_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::UV_loader kiwi::UV_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::UV_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
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

inline kiwi::_UV_loader_proxy kiwi::UV_loader::select(std::size_t number) noexcept
{
	kiwi::_UV_loader_proxy proxy;
	proxy.m_buffer_ptr = reinterpret_cast<GLfloat*>(m_data_ptr) + (number - m_first) * 2;
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
inline kiwi::_UV_loader_proxy& kiwi::_UV_loader_proxy::set_tile(int tile) noexcept
{
	(*m_altas_coordinate_function_ptr)(tile, m_buffer_ptr);
	return *this;
}


// XYZA_UV

inline kiwi::XYZA_UV_loader kiwi::XYZA_UV_set::get_loader(void* ptr) noexcept
{
	kiwi::XYZA_UV_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::XYZA_UV_loader kiwi::XYZA_UV_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::XYZA_UV_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
inline kiwi::XYZA_UV_loader kiwi::XYZA_UV_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::XYZA_UV_loader loader;
	loader.m_data_ptr = static_cast<char*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

inline GLfloat kiwi::XYZA_UV_set::get_U_size() const noexcept
{
	return m_UV_size[0];
}
inline GLfloat kiwi::XYZA_UV_set::get_V_size() const noexcept
{
	return m_UV_size[1];
}

inline kiwi::XYZA_UV_loader::XYZA_UV_loader() noexcept {}
inline kiwi::XYZA_UV_loader::XYZA_UV_loader(kiwi::XYZA_UV_loader&& rhs) noexcept
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
inline kiwi::XYZA_UV_loader& kiwi::XYZA_UV_loader::operator=(kiwi::XYZA_UV_loader&& rhs) noexcept
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
inline kiwi::XYZA_UV_loader::~XYZA_UV_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (8 * sizeof(GLfloat)), m_count * (8 * sizeof(GLfloat)));
	}
}

inline kiwi::_XYZA_UV_loader_proxy kiwi::XYZA_UV_loader::select(std::size_t number) noexcept
{
	kiwi::_XYZA_UV_loader_proxy proxy;
	proxy.m_buffer_ptr = reinterpret_cast<GLfloat*>(m_data_ptr) + (number - m_first) * 8;
	proxy.m_altas_coordinate_function_ptr = &(m_set_ptr->m_atlas_coordinate_function);
	return proxy;
}
inline void kiwi::XYZA_UV_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
{
	*m_buffer_ptr = *XY_ptr;
	*(m_buffer_ptr + 1) = *(XY_ptr + 1);
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	*m_buffer_ptr = *XYZ_ptr;
	*(m_buffer_ptr + 1) = *(XYZ_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZ_ptr + 2);
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat angle) noexcept
{
	*m_buffer_ptr = X;
	*(m_buffer_ptr + 1) = Y;
	*(m_buffer_ptr + 2) = Z;
	*(m_buffer_ptr + 3) = angle;
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept
{
	*m_buffer_ptr = *XYZA_ptr;
	*(m_buffer_ptr + 1) = *(XYZA_ptr + 1);
	*(m_buffer_ptr + 2) = *(XYZA_ptr + 2);
	*(m_buffer_ptr + 3) = *(XYZA_ptr + 3);
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_angle(GLfloat angle) noexcept
{
	*(m_buffer_ptr + 3) = angle;
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_UV(GLfloat U, GLfloat V) noexcept
{
	*(m_buffer_ptr + 4) = U;
	*(m_buffer_ptr + 5) = V;
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept
{
	*(m_buffer_ptr + 4) = *UV_ptr;
	*(m_buffer_ptr + 5) = *(UV_ptr + 1);
	return *this;
}
inline kiwi::_XYZA_UV_loader_proxy& kiwi::_XYZA_UV_loader_proxy::set_tile(int tile) noexcept
{
	(*m_altas_coordinate_function_ptr)(tile, m_buffer_ptr + 4);
	return *this;
}


#endif // KIWI_SETS_HPP