#ifndef KIWI_SETS_HPP
#define KIWI_SETS_HPP

#include "context/kiwi_context.hpp"
#include "buffers/kiwi_buffer_texture.hpp"
#include "buffers/kiwi_buffer_storage.hpp"



namespace kiwi
{
	class _XY_RGBA_proxy;

	class XY_RGBA_set
	{

	public:

		friend class _XY_RGBA_proxy;

		kiwi::XY_RGBA_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XY_RGBA_proxy select(std::size_t number) noexcept;
		kiwi::XY_RGBA_set& to_binding(GLuint binding) noexcept;
		const kiwi::XY_RGBA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XY_RGBA_proxy
	{

	private:

		kiwi::XY_RGBA_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class XY_RGBA_set;

		kiwi::_XY_RGBA_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XY_RGBA_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::_XY_RGBA_proxy& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		kiwi::_XY_RGBA_proxy& set_RGBA(const GLfloat* const RGBA_ptr) noexcept;
	};
}


namespace kiwi
{
	class _XYZ_RGBA_proxy;

	class XYZ_RGBA_set
	{

	public:

		friend class _XYZ_RGBA_proxy;

		kiwi::XYZ_RGBA_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZ_RGBA_proxy select(std::size_t number) noexcept;
		kiwi::XYZ_RGBA_set& to_binding(GLuint binding) noexcept;
		const kiwi::XYZ_RGBA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XYZ_RGBA_proxy
	{

	public:

		friend class XYZ_RGBA_set;

		kiwi::_XYZ_RGBA_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZ_RGBA_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
		kiwi::_XYZ_RGBA_proxy& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		kiwi::_XYZ_RGBA_proxy& set_RGBA(const GLfloat* const RGBA_ptr) noexcept;

	private:

		kiwi::XYZ_RGBA_set* m_set_ptr;
		std::size_t m_number;
	};
}


namespace kiwi
{
	class _XY_proxy;

	class XY_set
	{

	public:

		friend class _XY_proxy;

		kiwi::XY_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XY_proxy select(std::size_t number) noexcept;
		kiwi::XY_set& to_binding(GLuint binding) noexcept;
		const kiwi::XY_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XY_proxy
	{

	public:

		friend class XY_set;

		kiwi::_XY_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XY_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;

	private:

		kiwi::XY_set* m_set_ptr;
		std::size_t m_number;
	};
}


namespace kiwi
{
	class _XYZ_proxy;

	class XYZ_set
	{

	public:

		friend class _XYZ_proxy;

		kiwi::XYZ_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZ_proxy select(std::size_t number) noexcept;
		kiwi::XYZ_set& to_binding(GLuint binding) noexcept;
		const kiwi::XYZ_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _XYZ_proxy
	{

	private:

		kiwi::XYZ_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class XYZ_set;

		kiwi::_XYZ_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZ_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
	};
}


namespace kiwi
{
	class _RGBA_proxy;

	class RGBA_set
	{

	public:

		friend class _RGBA_proxy;

		kiwi::RGBA_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_RGBA_proxy select(std::size_t number) noexcept;
		kiwi::RGBA_set& to_binding(GLuint binding) noexcept;
		const kiwi::RGBA_set& to_binding(GLuint binding) const noexcept;
		std::size_t instance_count() const noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
	};

	class _RGBA_proxy
	{

	public:

		friend class RGBA_set;

		kiwi::_RGBA_proxy& set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A = static_cast<GLfloat>(1)) noexcept;
		kiwi::_RGBA_proxy& set_RGBA(const GLfloat* const RGBA_ptr) noexcept;

	private:

		kiwi::RGBA_set* m_set_ptr;
		std::size_t m_number;
	};
}


namespace kiwi
{
	class _XY_UV_proxy;

	class XY_UV_set
	{

	public:

		friend class _XY_UV_proxy;

		kiwi::XY_UV_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XY_UV_proxy select(std::size_t number) noexcept;
		kiwi::XY_UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::XY_UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::XY_UV_set& set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
			std::function<void(const int, GLfloat* ptr)> atlas_function) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_buffer* m_atlas_texture = nullptr;
		std::function<void(const int, GLfloat*)> m_atlas_coordinate_function;
	};

	class _XY_UV_proxy
	{

	private:

		kiwi::XY_UV_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class XY_UV_set;

		kiwi::_XY_UV_proxy& set_XY(GLfloat X, GLfloat Y) noexcept;
		kiwi::_XY_UV_proxy& set_XY(const GLfloat* const XY_ptr) noexcept;
		kiwi::_XY_UV_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		kiwi::_XY_UV_proxy& set_UV(const GLfloat* const UV_ptr) noexcept;
		kiwi::_XY_UV_proxy& set_tile(int tile) noexcept;
	};
}


namespace kiwi
{
	class _XYZ_UV_proxy;

	class XYZ_UV_set
	{

	public:

		friend class _XYZ_UV_proxy;

		kiwi::XYZ_UV_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_XYZ_UV_proxy select(std::size_t number) noexcept;
		kiwi::XYZ_UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::XYZ_UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::XYZ_UV_set& set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
			std::function<void(const int, GLfloat* ptr)> atlas_function) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_buffer* m_atlas_texture = nullptr;
		std::function<void(const int, GLfloat*)> m_atlas_coordinate_function;
	};

	class _XYZ_UV_proxy
	{

	public:

		friend class XYZ_UV_set;

		kiwi::_XYZ_UV_proxy& set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		kiwi::_XYZ_UV_proxy& set_XYZ(const GLfloat* const XYZ_ptr) noexcept;
		kiwi::_XYZ_UV_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		kiwi::_XYZ_UV_proxy& set_UV(const GLfloat* const UV_ptr) noexcept;
		kiwi::_XYZ_UV_proxy& set_tile(int tile) noexcept;

	private:

		kiwi::XYZ_UV_set* m_set_ptr;
		std::size_t m_number;
	};
}


namespace kiwi
{
	class _UV_proxy;

	class UV_set
	{

	public:

		friend class _UV_proxy;

		kiwi::UV_set& allocate(std::size_t number_of_instances) noexcept;
		kiwi::_UV_proxy select(std::size_t number) noexcept;
		kiwi::UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) noexcept;
		const kiwi::UV_set& to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept;
		std::size_t instance_count() const noexcept;

		kiwi::UV_set& set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
			std::function<void(const int, GLfloat* ptr)> atlas_function) noexcept;

	private:

		kiwi::storage_buffer m_storage;
		std::size_t m_instance_count;
		const kiwi::texture_buffer* m_atlas_texture = nullptr;
		std::function<void(const int, GLfloat*)> m_atlas_coordinate_function;
	};

	class _UV_proxy
	{

	private:

		kiwi::UV_set* m_set_ptr;
		std::size_t m_number;

	public:

		friend class UV_set;

		kiwi::_UV_proxy& set_UV(GLfloat U, GLfloat V) noexcept;
		kiwi::_UV_proxy& set_UV(const GLfloat* const UV_ptr) noexcept;
		kiwi::_UV_proxy& set_tile(int tile) noexcept;
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


#endif // KIWI_SETS_HPP