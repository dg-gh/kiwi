#include "rendering/kiwi_sets.hpp"


// XYZA_set

kiwi::XYZA_set& kiwi::XYZA_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);

	m_storage.allocate(number_of_instances * (4 * sizeof(GLfloat)));
	GLfloat arr[4] = { GL0, GL0, GL0, GL0 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_XYZA_proxy kiwi::XYZA_set::operator[](std::size_t number) noexcept
{
	kiwi::_XYZA_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::XYZA_set& kiwi::XYZA_set::to_binding(GLuint binding) noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
const kiwi::XYZA_set& kiwi::XYZA_set::to_binding(GLuint binding) const noexcept
{
	m_storage.to_binding(binding);
	return *this;
}
std::size_t kiwi::XYZA_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::XYZA_loader kiwi::XYZA_set::get_loader(void* ptr) noexcept
{
	kiwi::XYZA_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::XYZA_loader kiwi::XYZA_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::XYZA_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::XYZA_loader kiwi::XYZA_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::XYZA_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_XY(GLfloat X, GLfloat Y) noexcept
{
	GLfloat arr[2] = { X, Y };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XY_ptr), m_number * (4 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XYZ_ptr), m_number * (4 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_XYZA(GLfloat X, GLfloat Y, GLfloat Z, GLfloat angle) noexcept
{
	GLfloat arr[4] = { X, Y, Z, angle };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_XYZA(const GLfloat* const _KIWI_RESTRICT XYZA_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(XYZA_ptr), m_number * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_XYZA_proxy& kiwi::_XYZA_proxy::set_angle(GLfloat angle) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<void*>(&angle), m_number * (4 * sizeof(GLfloat)) + 3 * sizeof(GLfloat), sizeof(GLfloat));
	return *this;
}

kiwi::XYZA_loader::XYZA_loader() noexcept {}
kiwi::XYZA_loader::XYZA_loader(kiwi::XYZA_loader&& rhs) noexcept
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
kiwi::XYZA_loader& kiwi::XYZA_loader::operator=(kiwi::XYZA_loader&& rhs) noexcept
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
kiwi::XYZA_loader::~XYZA_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (4 * sizeof(GLfloat)), m_count * (4 * sizeof(GLfloat)));
	}
}

kiwi::_XYZA_loader_proxy kiwi::XYZA_loader::operator[](std::size_t number) noexcept
{
	kiwi::_XYZA_loader_proxy proxy;
	proxy.m_buffer_ptr = m_data_ptr + (number - m_first) * 4;
	return proxy;
}
void kiwi::XYZA_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

// RGBA_set

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
kiwi::_RGBA_proxy kiwi::RGBA_set::operator[](std::size_t number) noexcept
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

kiwi::RGBA_loader kiwi::RGBA_set::get_loader(void* ptr) noexcept
{
	kiwi::RGBA_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::RGBA_loader kiwi::RGBA_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::RGBA_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::RGBA_loader kiwi::RGBA_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::RGBA_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

kiwi::_RGBA_proxy& kiwi::_RGBA_proxy::set_RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept
{
	GLfloat arr[4] = { R, G, B, A };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}
kiwi::_RGBA_proxy& kiwi::_RGBA_proxy::set_RGBA(const GLfloat* const _KIWI_RESTRICT RGBA_ptr) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<const void* const>(RGBA_ptr), m_number * (4 * sizeof(GLfloat)), 4 * sizeof(GLfloat));
	return *this;
}

kiwi::RGBA_loader::RGBA_loader() noexcept {}
kiwi::RGBA_loader::RGBA_loader(kiwi::RGBA_loader&& rhs) noexcept
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
kiwi::RGBA_loader& kiwi::RGBA_loader::operator=(kiwi::RGBA_loader&& rhs) noexcept
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
kiwi::RGBA_loader::~RGBA_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * (4 * sizeof(GLfloat)), m_count * (4 * sizeof(GLfloat)));
	}
}

kiwi::_RGBA_loader_proxy kiwi::RGBA_loader::operator[](std::size_t number) noexcept
{
	kiwi::_RGBA_loader_proxy proxy;
	proxy.m_buffer_ptr = m_data_ptr + (number - m_first) * 4;
	return proxy;
}
void kiwi::RGBA_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

// UV_set

kiwi::UV_set& kiwi::UV_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);

	m_storage.allocate(number_of_instances * (2 * sizeof(GLfloat)));
	GLfloat arr[2] = { GL0, GL0 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_UV_proxy kiwi::UV_set::operator[](std::size_t number) noexcept
{
	kiwi::_UV_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::UV_set& kiwi::UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture_ptr->to_binding(texture_binding);
	return *this;
}
const kiwi::UV_set& kiwi::UV_set::to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept
{
	m_storage.to_binding(storage_binding);
	m_atlas_texture_ptr->to_binding(texture_binding);
	return *this;
}
std::size_t kiwi::UV_set::instance_count() const noexcept
{
	return m_instance_count;
}
kiwi::UV_set& kiwi::UV_set::set_atlas(const kiwi::texture_2d* const atlas_texture_ptr,
	std::function<void(const int, GLfloat* ptr)> atlas_function, const kiwi::UV& UV_size) noexcept
{
	m_atlas_texture_ptr = atlas_texture_ptr;
	m_atlas_coordinate_function = std::move(atlas_function);
	m_UV_size[0] = UV_size[0];
	m_UV_size[1] = UV_size[1];
	return *this;
}

kiwi::_UV_proxy& kiwi::_UV_proxy::set_UV(GLfloat U, GLfloat V) noexcept
{
	GLfloat arr[2] = { U, V };
	m_set_ptr->m_storage.substitute(static_cast<void*>(arr), m_number * (2 * sizeof(GLfloat)), 2 * sizeof(GLfloat));
	return *this;
}
kiwi::_UV_proxy& kiwi::_UV_proxy::set_UV(const GLfloat* const _KIWI_RESTRICT UV_ptr) noexcept
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


// id_set

kiwi::id_set& kiwi::id_set::allocate(std::size_t number_of_instances) noexcept
{
	constexpr GLfloat GL0 = static_cast<GLfloat>(0);

	m_storage.allocate(number_of_instances * sizeof(GLfloat));
	GLfloat arr[2] = { GL0, GL0 };
	for (std::size_t n = 0; n < number_of_instances; n++)
	{
		m_storage.substitute(arr, n * sizeof(GLfloat), sizeof(GLfloat));
	}
	m_instance_count = number_of_instances;
	return *this;
}
kiwi::_id_proxy kiwi::id_set::operator[](std::size_t number) noexcept
{
	kiwi::_id_proxy proxy;
	proxy.m_set_ptr = this;
	proxy.m_number = number;
	return proxy;
}
kiwi::id_set& kiwi::id_set::to_binding(GLuint storage_binding, GLuint texture_binding) noexcept
{
	m_storage.to_binding(storage_binding);
	m_texture_array_ptr->to_binding(texture_binding);
	return *this;
}
const kiwi::id_set& kiwi::id_set::to_binding(GLuint storage_binding, GLuint texture_binding) const noexcept
{
	m_storage.to_binding(storage_binding);
	m_texture_array_ptr->to_binding(texture_binding);
	return *this;
}
std::size_t kiwi::id_set::instance_count() const noexcept
{
	return m_instance_count;
}

kiwi::id_set& kiwi::id_set::set_atlas(const kiwi::texture_array_buffer* const atlas_texture_ptr) noexcept
{
	m_texture_array_ptr = atlas_texture_ptr;
	return *this;
}

kiwi::id_loader kiwi::id_set::get_loader(void* ptr) noexcept
{
	kiwi::id_loader loader;
	loader.m_data_ptr = static_cast<GLint*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_instance_count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::id_loader kiwi::id_set::get_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::id_loader loader;
	loader.m_data_ptr = static_cast<GLint*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::id_loader kiwi::id_set::get_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::id_loader loader;
	loader.m_data_ptr = static_cast<GLint*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

void kiwi::_id_proxy::operator=(GLint id) noexcept
{
	m_set_ptr->m_storage.substitute(static_cast<void*>(&id), m_number * sizeof(GLint), sizeof(GLint));
}

kiwi::id_loader::id_loader() noexcept {}
kiwi::id_loader::id_loader(kiwi::id_loader&& rhs) noexcept
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
kiwi::id_loader& kiwi::id_loader::operator=(kiwi::id_loader&& rhs) noexcept
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
kiwi::id_loader::~id_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_storage.substitute(static_cast<void*>(m_data_ptr), m_first * sizeof(GLint), m_count * sizeof(GLint));
	}
}

void kiwi::id_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}


// mat3x3f_set

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
		m_skylight_count = number_of_skylights;
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
		m_pointlight_count = number_of_pointlights;
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
		m_spotlight_count = number_of_spotlights;
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

kiwi::skylight_loader kiwi::lightset::get_skylight_loader(void* ptr) noexcept
{
	kiwi::skylight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_skylight_count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::skylight_loader kiwi::lightset::get_skylight_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::skylight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::skylight_loader kiwi::lightset::get_skylight_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::skylight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

kiwi::pointlight_loader kiwi::lightset::get_pointlight_loader(void* ptr) noexcept
{
	kiwi::pointlight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_pointlight_count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::pointlight_loader kiwi::lightset::get_pointlight_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::pointlight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::pointlight_loader kiwi::lightset::get_pointlight_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::pointlight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

kiwi::spotlight_loader kiwi::lightset::get_spotlight_loader(void* ptr) noexcept
{
	kiwi::spotlight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = m_spotlight_count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::spotlight_loader kiwi::lightset::get_spotlight_loader(void* ptr, std::size_t count) noexcept
{
	kiwi::spotlight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = 0;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}
kiwi::spotlight_loader kiwi::lightset::get_spotlight_loader(void* ptr, std::size_t first, std::size_t count) noexcept
{
	kiwi::spotlight_loader loader;
	loader.m_data_ptr = static_cast<GLfloat*>(ptr);
	loader.m_first = first;
	loader.m_count = count;
	loader.m_set_ptr = this;
	return loader;
}

kiwi::skylight_loader::skylight_loader() noexcept {}
kiwi::skylight_loader::skylight_loader(kiwi::skylight_loader&& rhs) noexcept
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
kiwi::skylight_loader& kiwi::skylight_loader::operator=(kiwi::skylight_loader&& rhs) noexcept
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
kiwi::skylight_loader::~skylight_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_skylights.substitute(static_cast<void*>(m_data_ptr), m_first * (8 * sizeof(GLfloat)), m_count * (8 * sizeof(GLfloat)));
	}
}

kiwi::_skylight_loader_proxy kiwi::skylight_loader::operator[](std::size_t number) noexcept
{
	kiwi::_skylight_loader_proxy proxy;
	proxy.m_buffer_ptr = m_data_ptr + (number - m_first) * 8;
	return proxy;
}
void kiwi::skylight_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_dir(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat temp = static_cast<GLfloat>(1) / std::sqrt(X * X + Y * Y + Z * Z);
	GLfloat arr[3] = { temp * X, temp * Y, temp * Z };
	m_lightset_ptr->m_skylights.substitute(static_cast<void*>(arr), m_number * (8 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
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
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept
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
kiwi::_skylight_proxy& kiwi::_skylight_proxy::set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept
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
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
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
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
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
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept
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
kiwi::_pointlight_proxy& kiwi::_pointlight_proxy::set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept
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

kiwi::pointlight_loader::pointlight_loader() noexcept {}
kiwi::pointlight_loader::pointlight_loader(kiwi::pointlight_loader&& rhs) noexcept
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
kiwi::pointlight_loader& kiwi::pointlight_loader::operator=(kiwi::pointlight_loader&& rhs) noexcept
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
kiwi::pointlight_loader::~pointlight_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_pointlights.substitute(static_cast<void*>(m_data_ptr), m_first * (12 * sizeof(GLfloat)), m_count * (12 * sizeof(GLfloat)));
	}
}

kiwi::_pointlight_loader_proxy kiwi::pointlight_loader::operator[](std::size_t number) noexcept
{
	kiwi::_pointlight_loader_proxy proxy;
	proxy.m_buffer_ptr = m_data_ptr + (number - m_first) * 12;
	return proxy;
}
void kiwi::pointlight_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
}

kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept
{
	GLfloat arr[3] = { X, Y, Z };
	m_lightset_ptr->m_spotlights.substitute(static_cast<void*>(arr), m_number * (16 * sizeof(GLfloat)), 3 * sizeof(GLfloat));
	return *this;
}
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XYZ(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
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
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_XY(const GLfloat* const _KIWI_RESTRICT XY_ptr) noexcept
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
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_dir(const GLfloat* const _KIWI_RESTRICT XYZ_ptr) noexcept
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
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_RGB(const GLfloat* const _KIWI_RESTRICT RGB_ptr) noexcept
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
kiwi::_spotlight_proxy& kiwi::_spotlight_proxy::set_RGB_diff(const GLfloat* const _KIWI_RESTRICT RGB_diff_ptr) noexcept
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

kiwi::spotlight_loader::spotlight_loader() noexcept {}
kiwi::spotlight_loader::spotlight_loader(kiwi::spotlight_loader&& rhs) noexcept
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
kiwi::spotlight_loader& kiwi::spotlight_loader::operator=(kiwi::spotlight_loader&& rhs) noexcept
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
kiwi::spotlight_loader::~spotlight_loader()
{
	if (m_data_ptr != nullptr)
	{
		m_set_ptr->m_spotlights.substitute(static_cast<void*>(m_data_ptr), m_first * (16 * sizeof(GLfloat)), m_count * (16 * sizeof(GLfloat)));
	}
}

kiwi::_spotlight_loader_proxy kiwi::spotlight_loader::operator[](std::size_t number) noexcept
{
	kiwi::_spotlight_loader_proxy proxy;
	proxy.m_buffer_ptr = m_data_ptr + (number - m_first) * 16;
	return proxy;
}
void kiwi::spotlight_loader::cancel() noexcept
{
	m_data_ptr = nullptr;
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