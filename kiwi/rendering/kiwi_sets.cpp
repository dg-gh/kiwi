#include "rendering/kiwi_sets.hpp"


kiwi::XY_RGBA_set& kiwi::XY_RGBA_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (8 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL1 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (8 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XY_RGBA_proxy kiwi::XY_RGBA_set::select(std::size_t number) noexcept
{
	kiwi::_XY_RGBA_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XY_RGBA_set& kiwi::XY_RGBA_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XY_RGBA_set& kiwi::XY_RGBA_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XY_RGBA_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_XY_RGBA_proxy& kiwi::_XY_RGBA_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[2] = { X, Y };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_RGBA_proxy& kiwi::_XY_RGBA_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XY_ptr), m_number * (8 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_RGBA_proxy& kiwi::_XY_RGBA_proxy::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	GLfloat arr[4] = { R, G, B, A };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_RGBA_proxy& kiwi::_XY_RGBA_proxy::set_RGBA(const GLfloat* const RGBA_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(RGBA_ptr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 4 * sizeof(GLfloat));
	return *this;
}


kiwi::XYZ_RGBA_set& kiwi::XYZ_RGBA_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (8 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL1 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (8 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XYZ_RGBA_proxy kiwi::XYZ_RGBA_set::select(std::size_t number) noexcept
{
	kiwi::_XYZ_RGBA_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XYZ_RGBA_set& kiwi::XYZ_RGBA_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XYZ_RGBA_set& kiwi::XYZ_RGBA_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XYZ_RGBA_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_XYZ_RGBA_proxy& kiwi::_XYZ_RGBA_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_RGBA_proxy& kiwi::_XYZ_RGBA_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_RGBA_proxy& kiwi::_XYZ_RGBA_proxy::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	GLfloat arr[4] = { R, G, B, A };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_RGBA_proxy& kiwi::_XYZ_RGBA_proxy::set_RGBA(const GLfloat* const RGBA_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(RGBA_ptr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 4 * sizeof(GLfloat));
	return *this;
}


kiwi::XY_set& kiwi::XY_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (2 * sizeof(GLfloat)));
	GLfloat arr[2] = { GL0, GL0 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(static_cast<void*>(arr), n * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XY_proxy kiwi::XY_set::select(std::size_t number) noexcept
{
	kiwi::_XY_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XY_set& kiwi::XY_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XY_set& kiwi::XY_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XY_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_XY_proxy& kiwi::_XY_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[2] = { X, Y };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_proxy& kiwi::_XY_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XY_ptr), m_number * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}


kiwi::XYZ_set& kiwi::XYZ_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (4 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL1 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XYZ_proxy kiwi::XYZ_set::select(std::size_t number) noexcept
{
	kiwi::_XYZ_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XYZ_set& kiwi::XYZ_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XYZ_set& kiwi::XYZ_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XYZ_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_XYZ_proxy& kiwi::_XYZ_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_proxy& kiwi::_XYZ_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}


kiwi::RGBA_set& kiwi::RGBA_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (4 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL1 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_RGBA_proxy kiwi::RGBA_set::select(std::size_t number) noexcept
{
	kiwi::_RGBA_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::RGBA_set& kiwi::RGBA_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::RGBA_set& kiwi::RGBA_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::RGBA_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_RGBA_proxy& kiwi::_RGBA_proxy::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	GLfloat arr[4] = { R, G, B, A };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_RGBA_proxy& kiwi::_RGBA_proxy::set_RGBA(const GLfloat* const RGBA_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(RGBA_ptr), m_number * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}


kiwi::XY_UV_set& kiwi::XY_UV_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (8 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL1 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (8 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XY_UV_proxy kiwi::XY_UV_set::select(std::size_t number) noexcept
{
	kiwi::_XY_UV_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XY_UV_set& kiwi::XY_UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture->to_binding(texture_binding);
	return *this;
}
const kiwi::XY_UV_set& kiwi::XY_UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture->to_binding(texture_binding);
	return *this;
}
std::size_t kiwi::XY_UV_set::instance_count() const noexcept
{
	return m_instance_count;
}
kiwi::XY_UV_set& kiwi::XY_UV_set::set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
	std::function<void(const int, GLfloat* ptr)> atlas_function) noexcept
{
	m_atlas_texture = atlas_texture_ptr;
	m_atlas_coordinate_function = std::move(atlas_function);
	return *this;
}

kiwi::_XY_UV_proxy& kiwi::_XY_UV_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[2] = { X, Y };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_UV_proxy& kiwi::_XY_UV_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XY_ptr), m_number * (8 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_UV_proxy& kiwi::_XY_UV_proxy::set_UV(GLfloat U, GLfloat V) noexcept
{
	GLfloat arr[2] = { U, V };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_UV_proxy& kiwi::_XY_UV_proxy::set_UV(const GLfloat* const UV_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(UV_ptr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_UV_proxy& kiwi::_XY_UV_proxy::set_tile(int tile) noexcept
{
	GLfloat arr[2];
	m_set_ptr->m_atlas_coordinate_function(tile, static_cast<GLfloat*>(arr));
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(arr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	return *this;
}


kiwi::XYZ_UV_set& kiwi::XYZ_UV_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (8 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL1 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (8 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XYZ_UV_proxy kiwi::XYZ_UV_set::select(std::size_t number) noexcept
{
	kiwi::_XYZ_UV_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XYZ_UV_set& kiwi::XYZ_UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture->to_binding(texture_binding);
	return *this;
}
const kiwi::XYZ_UV_set& kiwi::XYZ_UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture->to_binding(texture_binding);
	return *this;
}
std::size_t kiwi::XYZ_UV_set::instance_count() const noexcept
{
	return m_instance_count;
}
kiwi::XYZ_UV_set& kiwi::XYZ_UV_set::set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
	std::function<void(const int, GLfloat* ptr)> atlas_function) noexcept
{
	m_atlas_texture = atlas_texture_ptr;
	m_atlas_coordinate_function = std::move(atlas_function);
	return *this;
}

kiwi::_XYZ_UV_proxy& kiwi::_XYZ_UV_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_UV_proxy& kiwi::_XYZ_UV_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_UV_proxy& kiwi::_XYZ_UV_proxy::set_UV(GLfloat U, GLfloat V) noexcept
{
	GLfloat arr[2] = { U, V };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_UV_proxy& kiwi::_XYZ_UV_proxy::set_UV(const GLfloat* const UV_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(UV_ptr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_UV_proxy& kiwi::_XYZ_UV_proxy::set_tile(int tile) noexcept
{
	GLfloat arr[2];
	m_set_ptr->m_atlas_coordinate_function(tile, static_cast<GLfloat*>(arr));
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(arr), m_number * (8 * sizeof(GLfloat)) + 4 * sizeof(GLfloat), 2 * sizeof(GLfloat));
	return *this;
}


kiwi::UV_set& kiwi::UV_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (2 * sizeof(GLfloat)));
	GLfloat arr[2] = { GL0, GL0 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_UV_proxy kiwi::UV_set::select(std::size_t number) noexcept
{
	kiwi::_UV_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::UV_set& kiwi::UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture->to_binding(texture_binding);
	return *this;
}
const kiwi::UV_set& kiwi::UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture->to_binding(texture_binding);
	return *this;
}
std::size_t kiwi::UV_set::instance_count() const noexcept
{
	return m_instance_count;
}
kiwi::UV_set& kiwi::UV_set::set_atlas(const kiwi::texture_buffer* const atlas_texture_ptr,
	std::function<void(const int, GLfloat* ptr)> atlas_function) noexcept
{
	m_atlas_texture = atlas_texture_ptr;
	m_atlas_coordinate_function = std::move(atlas_function);
	return *this;
}

kiwi::_UV_proxy& kiwi::_UV_proxy::set_UV(GLfloat U, GLfloat V) noexcept
{
	GLfloat arr[2] = { U, V };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_UV_proxy& kiwi::_UV_proxy::set_UV(const GLfloat* const UV_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(UV_ptr), m_number * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_UV_proxy& kiwi::_UV_proxy::set_tile(int tile) noexcept
{
	GLfloat arr[2];
	m_set_ptr->m_atlas_coordinate_function(tile, static_cast<GLfloat*>(arr));
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(arr), m_number * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}


kiwi::XY_id_set& kiwi::XY_id_set::allocate(std::size_t number_of_instances) noexcept
{
	m_storage.allocate(number_of_instances * (4 * sizeof(GLfloat)));
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XY_id_proxy kiwi::XY_id_set::select(std::size_t number) noexcept
{
	kiwi::_XY_id_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XY_id_set& kiwi::XY_id_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XY_id_set& kiwi::XY_id_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XY_id_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_XY_id_proxy& kiwi::_XY_id_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[2] = { X, Y };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_id_proxy& kiwi::_XY_id_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XY_ptr), m_number * (4 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XY_id_proxy& kiwi::_XY_id_proxy::set_id(GLushort id) noexcept
{
	GLuint _id = static_cast<GLuint>(id);
	m_set_ptr->m_storage.substitute(static_cast<void*>(&_id), m_number * (4 * sizeof(GLfloat)) + 3 * sizeof(GLfloat), sizeof(GLuint));
	return *this;
}


kiwi::XYZ_id_set& kiwi::XYZ_id_set::allocate(std::size_t number_of_instances) noexcept
{
	m_storage.allocate(number_of_instances * (4 * sizeof(GLfloat)));
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XYZ_id_proxy kiwi::XYZ_id_set::select(std::size_t number) noexcept
{
	kiwi::_XYZ_id_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XYZ_id_set& kiwi::XYZ_id_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XYZ_id_set& kiwi::XYZ_id_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XYZ_id_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_XYZ_id_proxy& kiwi::_XYZ_id_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_id_proxy& kiwi::_XYZ_id_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZ_id_proxy& kiwi::_XYZ_id_proxy::set_id(GLushort id) noexcept
{
	GLuint _id = static_cast<GLuint>(id);
	m_set_ptr->m_storage.substitute(static_cast<void*>(&_id), m_number * (4 * sizeof(GLfloat)) + 3 * sizeof(GLfloat), sizeof(GLuint));
	return *this;
}


kiwi::mat3x3f_set& kiwi::mat3x3f_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (12 * sizeof(GLfloat)));
	GLfloat arr[12] = {
		GL1, GL0, GL0, GL0,
		GL0, GL1, GL0, GL0,
		GL0, GL0, GL1, GL0,
	};
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (12 * sizeof(GLfloat)), 12 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_mat3x3f_proxy kiwi::mat3x3f_set::select(std::size_t number) noexcept
{
	kiwi::_mat3x3f_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::mat3x3f_set& kiwi::mat3x3f_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::mat3x3f_set& kiwi::mat3x3f_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::mat3x3f_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_mat3x3f_proxy& kiwi::_mat3x3f_proxy::set_matrix(const GLfloat* const matrix_ptr) noexcept
{
	GLfloat arr[12];

	arr[0] = *matrix_ptr;
	arr[1] = *(matrix_ptr + 1);
	arr[2] = *(matrix_ptr + 2);
	arr[3] = static_cast<GLfloat>(0);

	arr[4] = *(matrix_ptr + 3);
	arr[5] = *(matrix_ptr + 4);
	arr[6] = *(matrix_ptr + 5);
	arr[7] = static_cast<GLfloat>(0);

	arr[8] = *(matrix_ptr + 6);
	arr[9] = *(matrix_ptr + 7);
	arr[10] = *(matrix_ptr + 8);
	arr[11] = static_cast<GLfloat>(0);

	m_set_ptr->m_storage.substitute(static_cast<const void* const>(arr), m_number * (12 * sizeof(GLfloat)), 12 * sizeof(GLfloat));
	return *this;
}

kiwi::mat4x4f_set& kiwi::mat4x4f_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_storage.allocate(number_of_instances * (16 * sizeof(GLfloat)));
	GLfloat arr[16] = {
		GL1, GL0, GL0, GL0,
		GL0, GL1, GL0, GL0,
		GL0, GL0, GL1, GL0,
		GL0, GL0, GL0, GL1
	};
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (16 * sizeof(GLfloat)), 16 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_mat4x4f_proxy kiwi::mat4x4f_set::select(std::size_t number) noexcept
{
	kiwi::_mat4x4f_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::mat4x4f_set& kiwi::mat4x4f_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::mat4x4f_set& kiwi::mat4x4f_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::mat4x4f_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::_mat4x4f_proxy& kiwi::_mat4x4f_proxy::set_matrix(const GLfloat* const matrix_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(matrix_ptr), m_number * (16 * sizeof(GLfloat)), 16 * sizeof(GLfloat));
	return *this;
}


kiwi::lightset& kiwi::lightset::allocate(std::size_t number_of_skylights, std::size_t number_of_pointlights, std::size_t number_of_spotlights) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);
	constexpr GLfloat GL1 = static_cast<GLfloat>(1);

	m_skylights.allocate(number_of_skylights * 8 * sizeof(GLfloat)); // 4xfl : dir // 4xfl : RGBD
	{
		GLfloat arr[8] = {
			GL1, GL0, GL0, GL1,
			GL0, GL0, GL0, GL1
		};
		for (std::size_t n = 0; n < number_of_skylights; n++)
		{
			m_skylights.substitute(static_cast<void*>(arr), n * (8 * sizeof(GLfloat)), 8 * sizeof(GLfloat));
		}
	}
	m_pointlights.allocate(number_of_pointlights * 12 * sizeof(GLfloat)); // 4xfl : XYZ // 4xfl : RGBD // 4xfl : att
	{
		GLfloat arr[12] = {
			GL0, GL0, GL0, GL1,
			GL0, GL0, GL0, GL1,
			GL0, GL0, GL0, GL0
		};
		for (std::size_t n = 0; n < number_of_pointlights; n++)
		{
			m_pointlights.substitute(static_cast<void*>(arr), n * (12 * sizeof(GLfloat)), 12 * sizeof(GLfloat));
		}
	}
	m_spotlights.allocate(number_of_spotlights * 16 * sizeof(GLfloat)); // 4xfl : XYZ // 4xfl : dir // 4xfl : RGBD // 4xfl : att
	{
		GLfloat arr[16] = {
			GL0, GL0, GL0, GL1,
			GL1, GL0, GL0, GL1,
			GL0, GL0, GL0, GL1,
			GL0, GL0, GL0, GL0
		};
		for (std::size_t n = 0; n < number_of_spotlights; n++)
		{
			m_spotlights.substitute(static_cast<void*>(arr), n * (16 * sizeof(GLfloat)), 16 * sizeof(GLfloat));
		}
	}
	return *this;
}

kiwi::_skylight_proxy kiwi::lightset::select_skylight(std::size_t number) noexcept
{
	kiwi::_skylight_proxy proxy;
	proxy.m_lightset_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::_pointlight_proxy kiwi::lightset::select_pointlight(std::size_t number) noexcept
{
	kiwi::_pointlight_proxy proxy;
	proxy.m_lightset_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::_spotlight_proxy kiwi::lightset::select_spotlight(std::size_t number) noexcept
{
	kiwi::_spotlight_proxy proxy;
	proxy.m_lightset_ptr = this;
	proxy.m_number = number;
	return proxy;
}

kiwi::lightset& kiwi::lightset::to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) noexcept
{
	m_skylights.to_binding(skylights_binding);
	m_pointlights.to_binding(pointlights_binding);
	m_spotlights.to_binding(spotlights_binding);

	return *this;
}
const kiwi::lightset& kiwi::lightset::to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) const noexcept
{
	m_skylights.to_binding(skylights_binding);
	m_pointlights.to_binding(pointlights_binding);
	m_spotlights.to_binding(spotlights_binding);

	return *this;
}

kiwi::lightset& kiwi::lightset::set_ambient_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	m_ambient_RGB[0] = R;
	m_ambient_RGB[1] = G;
	m_ambient_RGB[2] = B;
	return *this;
}

const GLfloat* kiwi::lightset::ambient_RGB_data() const noexcept
{
	return static_cast<const GLfloat*>(m_ambient_RGB);
}

kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(X * X + Y * Y + Z * Z);
	GLfloat arr[3] = { temp * X, temp * Y, temp * Z };
	m_lightset_ptr->m_skylights.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_dir(const GLfloat* const XYZ_ptr) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(*XYZ_ptr * *XYZ_ptr + *(XYZ_ptr + 1) * *(XYZ_ptr + 1) + *(XYZ_ptr + 2) * *(XYZ_ptr + 2));
	GLfloat arr[3] = { temp * *XYZ_ptr, temp * *(XYZ_ptr + 1), temp * *(XYZ_ptr + 2) };
	m_lightset_ptr->m_skylights.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}

kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	GLfloat arr[3] = { R, G, B };
	m_lightset_ptr->m_skylights.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_RGB(const GLfloat* const RGB_ptr) noexcept
{
	m_lightset_ptr->m_skylights.substitute(static_cast<const void* const>(RGB_ptr), m_number * (8 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_diff(GLfloat diff) noexcept
{
	m_lightset_ptr->m_skylights.substitute(static_cast<void*>(&diff), m_number * (8 * sizeof(GLfloat)) + (7 * sizeof(GLfloat)), sizeof(GLfloat));
	return *this;
}
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept
{
	GLfloat arr[4] = { R, G, B, diff };
	m_lightset_ptr->m_skylights.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_RGB_diff(const GLfloat* const RGB_diff_ptr) noexcept
{
	m_lightset_ptr->m_skylights.substitute(static_cast<const void* const>(RGB_diff_ptr), m_number * (8 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}

kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_lightset_ptr->m_pointlights.substitute(static_cast<void*>(arr), m_number * (12 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_lightset_ptr->m_pointlights.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (12 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}

kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[3] = { X, Y };
	m_lightset_ptr->m_pointlights.substitute(static_cast<void*>(arr), m_number * (12 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_lightset_ptr->m_pointlights.substitute(static_cast<const void* const>(XY_ptr), m_number * (12 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}

kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	GLfloat arr[3] = { R, G, B };
	m_lightset_ptr->m_pointlights.substitute(static_cast<void*>(arr), m_number * (12 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_RGB(const GLfloat* const RGB_ptr) noexcept
{
	m_lightset_ptr->m_pointlights.substitute(static_cast<const void* const>(RGB_ptr), m_number * (12 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_diff(GLfloat diff) noexcept
{
	m_lightset_ptr->m_pointlights.substitute(static_cast<void*>(&diff), m_number * (12 * sizeof(GLfloat)) + (7 * sizeof(GLfloat)), sizeof(GLfloat));
	return *this;
}
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept
{
	GLfloat arr[4] = { R, G, B, diff };
	m_lightset_ptr->m_pointlights.substitute(static_cast<void*>(arr), m_number * (12 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_RGB_diff(const GLfloat* const RGB_diff_ptr) noexcept
{
	m_lightset_ptr->m_pointlights.substitute(static_cast<const void* const>(RGB_diff_ptr), m_number * (12 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}

kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_attenuation(GLfloat quadratic, GLfloat constant) noexcept
{
	GLfloat arr[2] = { quadratic, constant };
	m_lightset_ptr->m_pointlights.substitute(static_cast<void*>(arr), m_number * (12 * sizeof(GLfloat)) + (8 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}

kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XYZ(const GLfloat* const XYZ_ptr) noexcept
{
	m_lightset_ptr->m_spotlights.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (16 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}

kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[3] = { X, Y };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XY(const GLfloat* const XY_ptr) noexcept
{
	m_lightset_ptr->m_spotlights.substitute(static_cast<const void* const>(XY_ptr), m_number * (16 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}

kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(X * X + Y * Y + Z * Z);
	GLfloat arr[3] = { temp * X, temp * Y, temp * Z };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_dir(const GLfloat* const XYZ_ptr) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(*XYZ_ptr * *XYZ_ptr + *(XYZ_ptr + 1) * *(XYZ_ptr + 1) + *(XYZ_ptr + 2) * *(XYZ_ptr + 2));
	GLfloat arr[3] = { temp * *XYZ_ptr, temp * *(XYZ_ptr + 1), temp * *(XYZ_ptr + 2) };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)) + (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}

kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_RGB(GLfloat R, GLfloat G, GLfloat B) noexcept
{
	GLfloat arr[3] = { R, G, B };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)) + (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_RGB(const GLfloat* const RGB_ptr) noexcept
{
	m_lightset_ptr->m_spotlights.substitute(static_cast<const void* const>(RGB_ptr), m_number * (16 * sizeof(GLfloat)) + (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_diff(GLfloat diff) noexcept
{
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(&diff), m_number * (16 * sizeof(GLfloat)) + (11 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_RGB_diff(GLfloat R, GLfloat G, GLfloat B, GLfloat diff) noexcept
{
	GLfloat arr[4] = { R, G, B, diff };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)) + (8 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_RGB_diff(const GLfloat* const RGB_diff_ptr) noexcept
{
	m_lightset_ptr->m_spotlights.substitute(static_cast<const void* const>(RGB_diff_ptr), m_number * (16 * sizeof(GLfloat)) + (8 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}

kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_attenuation(GLfloat quadratic, GLfloat constant, GLfloat edge_min, GLfloat edge_max) noexcept
{
	GLfloat arr[4] = { quadratic, constant, edge_min, edge_max };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)) + (12 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}


kiwi::light_selection& kiwi::light_selection::allocate(std::size_t number_of_skylights, std::size_t number_of_pointlights, std::size_t number_of_spotlights) noexcept
{
	m_skylight_id.allocate(number_of_skylights * sizeof(GLint));
	m_pointlight_id.allocate(number_of_pointlights * sizeof(GLint));
	m_spotlight_id.allocate(number_of_spotlights * sizeof(GLint));

	return *this;
}

const GLuint* kiwi::light_selection::number_of_lights_data() const noexcept
{
	return static_cast<const GLuint*>(number_of_lights);
}

kiwi::light_selection& kiwi::light_selection::select_skylights(GLint* skylight_id_ptr, std::size_t number_of_skylights) noexcept
{
	number_of_lights[0] = static_cast<GLuint>(number_of_skylights);
	m_skylight_id.substitute(static_cast<const void* const>(skylight_id_ptr), 0, number_of_skylights * sizeof(GLfloat));
	return *this;
}
kiwi::light_selection& kiwi::light_selection::select_pointlights(GLint* skylight_id_ptr, std::size_t number_of_pointlights) noexcept
{
	number_of_lights[1] = static_cast<GLuint>(number_of_pointlights);
	m_pointlight_id.substitute(static_cast<const void* const>(skylight_id_ptr), 0, number_of_pointlights * sizeof(GLfloat));
	return *this;
}
kiwi::light_selection& kiwi::light_selection::select_splotlights(GLint* skylight_id_ptr, std::size_t number_of_spotlights) noexcept
{
	number_of_lights[2] = static_cast<GLuint>(number_of_spotlights);
	m_pointlight_id.substitute(static_cast<const void* const>(skylight_id_ptr), 0, number_of_spotlights * sizeof(GLfloat));
	return *this;
}

kiwi::light_selection& kiwi::light_selection::to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) noexcept
{
	m_skylight_id.to_binding(skylights_binding);
	m_pointlight_id.to_binding(pointlights_binding);
	m_spotlight_id.to_binding(spotlights_binding);

	return *this;
}
const kiwi::light_selection& kiwi::light_selection::to_binding(GLuint skylights_binding, GLuint pointlights_binding, GLuint spotlights_binding) const noexcept
{
	m_skylight_id.to_binding(skylights_binding);
	m_pointlight_id.to_binding(pointlights_binding);
	m_spotlight_id.to_binding(spotlights_binding);

	return *this;
}