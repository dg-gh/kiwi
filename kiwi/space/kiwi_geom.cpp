#include "space/kiwi_geom.hpp"

#if defined(__AVX2__) && defined(__FMA__)
#include <immintrin.h>
#endif


kiwi::_load_frame_proxy kiwi::load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept
{
	kiwi::_load_frame_proxy proxy;
	proxy.m_buffer_ptr = &vertex_buffer;
	return proxy;
}

void kiwi::_load_frame_proxy::N_from_2d_lines_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 2);
	kiwi::make_N_from_2d_lines_ccw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 2);
}

void kiwi::_load_frame_proxy::N_from_2d_lines_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 2);
	kiwi::make_N_from_2d_lines_cw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 2);
}

void kiwi::_load_frame_proxy::TB_from_2d_triangles(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 4);
	kiwi::make_TB_from_2d_triangles(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 4);
}

void kiwi::_load_frame_proxy::TB_from_2d_quads(const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 4);
	kiwi::make_TB_from_2d_quads(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 4);
}

void kiwi::_load_frame_proxy::N_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 3);
	kiwi::make_N_from_3d_triangles_ccw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

void kiwi::_load_frame_proxy::N_from_3d_triangles_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 3);
	kiwi::make_N_from_3d_triangles_cw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

void kiwi::_load_frame_proxy::N_from_3d_quads_ccw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 3);
	kiwi::make_N_from_3d_quads_ccw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

void kiwi::_load_frame_proxy::N_from_3d_quads_cw(const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 3);
	kiwi::make_N_from_3d_quads_cw(temp.data(), vertex_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 3);
}

void kiwi::_load_frame_proxy::TBN_from_3d_triangles_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_triangles_ccw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

void kiwi::_load_frame_proxy::TBN_from_3d_triangles_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_triangles_cw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

void kiwi::_load_frame_proxy::TBN_from_3d_quads_ccw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_quads_ccw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}

void kiwi::_load_frame_proxy::TBN_from_3d_quads_cw(const GLfloat* const vertex_ptr, const GLfloat* uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim)
{
	std::vector<GLfloat> temp(vertex_count * 9);
	kiwi::make_TBN_from_3d_quads_cw(temp.data(), vertex_ptr, uv_ptr, vertex_count, vertex_dim);
	m_buffer_ptr->load(temp.data(), vertex_count, 9);
}


void kiwi::make_N_from_2d_lines_ccw(GLfloat* const  _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t2 = vertex_dim + vertex_dim;

	for (std::size_t j = 0; j + 1 < vertex_count; j += 2)
	{
		*p = *(q + 1) - *(q + vertex_dim + 1);
		*(p + 1) = *(q + vertex_dim) - *q;
		GLfloat factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
		*p *= factor;
		*(p + 1) *= factor;

		std::memcpy(p + 2, p, 2 * sizeof(GLfloat));

		p += 4; q += vertex_dim_t2;
	}
}

void kiwi::make_N_from_2d_lines_cw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t2 = vertex_dim + vertex_dim;

	for (std::size_t j = 0; j + 1 < vertex_count; j += 2)
	{
		*p = *(q + vertex_dim + 1) - *(q + 1);
		*(p + 1) = *q - *(q + vertex_dim);
		GLfloat factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
		*p *= factor;
		*(p + 1) *= factor;

		std::memcpy(p + 2, p, 2 * sizeof(GLfloat));

		p += 4; q += vertex_dim_t2;
	}
}

void kiwi::make_TB_from_2d_triangles(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = TB_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	GLfloat uv_vec[4];

	GLfloat a0;
	GLfloat b0;
	GLfloat a1;
	GLfloat b1;

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		uv_vec[0] = *(r + 2) - *r;
		uv_vec[1] = *(r + 3) - *(r + 1);
		uv_vec[2] = *(r + 4) - *(r + 2);
		uv_vec[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (uv_vec[0] * uv_vec[3] - uv_vec[1] * uv_vec[2]);

		a0 = uv_vec[3] * factor;
		b0 = -uv_vec[1] * factor;
		a1 = -uv_vec[2] * factor;
		b1 = uv_vec[0] * factor;

		uv_vec[0] = *(q + 2) - *q;
		uv_vec[1] = *(q + 3) - *(q + 1);

		uv_vec[2] = *(q + 4) - *(q + 2);
		uv_vec[3] = *(q + 5) - *(q + 3);

		*p = a0 * uv_vec[0] + b0 * uv_vec[2];
		*(p + 1) = a0 * uv_vec[1] + b0 * uv_vec[3];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
		*p *= factor;
		*(p + 1) *= factor;

		*(p + 2) = a1 * uv_vec[0] + b1 * uv_vec[2];
		*(p + 3) = a1 * uv_vec[1] + b1 * uv_vec[3];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 2)) * (*(p + 2)) + (*(p + 3)) * (*(p + 3)));
		*(p + 2) *= factor;
		*(p + 3) *= factor;

		std::memcpy(p + 4, p, 4 * sizeof(GLfloat));
		std::memcpy(p + 8, p, 4 * sizeof(GLfloat));

		p += 6; q += vertex_dim_t3; r += 6;
	}
}

void kiwi::make_TB_from_2d_quads(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = TB_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	GLfloat uv_vec[4];

	GLfloat a0;
	GLfloat b0;
	GLfloat a1;
	GLfloat b1;

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		uv_vec[0] = *(r + 2) - *r;
		uv_vec[1] = *(r + 3) - *(r + 1);
		uv_vec[2] = *(r + 4) - *(r + 2);
		uv_vec[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (uv_vec[0] * uv_vec[3] - uv_vec[1] * uv_vec[2]);

		a0 = uv_vec[3] * factor;
		b0 = -uv_vec[1] * factor;
		a1 = -uv_vec[2] * factor;
		b1 = uv_vec[0] * factor;

		uv_vec[0] = *(q + 2) - *q;
		uv_vec[1] = *(q + 3) - *(q + 1);

		uv_vec[2] = *(q + 4) - *(q + 2);
		uv_vec[3] = *(q + 5) - *(q + 3);

		*p = a0 * uv_vec[0] + b0 * uv_vec[2];
		*(p + 1) = a0 * uv_vec[1] + b0 * uv_vec[3];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
		*p *= factor;
		*(p + 1) *= factor;

		*(p + 2) = a1 * uv_vec[0] + b1 * uv_vec[2];
		*(p + 3) = a1 * uv_vec[1] + b1 * uv_vec[3];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 2)) * (*(p + 2)) + (*(p + 3)) * (*(p + 3)));
		*(p + 2) *= factor;
		*(p + 3) *= factor;

		std::memcpy(p + 4, p, 4 * sizeof(GLfloat));
		std::memcpy(p + 8, p, 4 * sizeof(GLfloat));
		std::memcpy(p + 12, p, 4 * sizeof(GLfloat));

		p += 8; q += vertex_dim_t4; r += 8;
	}
}

void kiwi::make_N_from_3d_triangles_ccw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = N_ptr;
	const float* q = vertex_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	__m128 u;
	__m128 v;
	__m128 w;

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(w, _mm_loadu_ps(q));
		v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
		w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		std::memcpy(p + 3, p, 3 * sizeof(float));
		std::memcpy(p + 6, p, 3 * sizeof(float));

		p += 9; q += vertex_dim_t3;
	}
#else
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	GLfloat u3[3];
	GLfloat v3[3];

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		u3[0] = *(q + 3) - *q;
		u3[1] = *(q + 4) - *(q + 1);
		u3[2] = *(q + 5) - *(q + 2);
		v3[0] = *(q + 6) - *(q + 3);
		v3[1] = *(q + 7) - *(q + 4);
		v3[2] = *(q + 8) - *(q + 5);
		*p = u3[1] * v3[2] - u3[2] * v3[1];
		*(p + 1) = u3[2] * v3[0] - u3[0] * v3[2];
		*(p + 2) = u3[0] * v3[1] - u3[1] * v3[0];
		GLfloat factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		std::memcpy(p + 3, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 6, p, 3 * sizeof(GLfloat));

		p += 9; q += vertex_dim_t3;
	}
#endif // SIMD
}

void kiwi::make_N_from_3d_triangles_cw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = N_ptr;
	const float* q = vertex_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	__m128 u;
	__m128 v;
	__m128 w;

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
		v = _mm_sub_ps(w, _mm_loadu_ps(q));
		w = _mm_fnmadd_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2))));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		std::memcpy(p + 3, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 6, p, 3 * sizeof(GLfloat));

		p += 9; q += vertex_dim_t3;
	}
#else
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	GLfloat u3[3];
	GLfloat v3[3];

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		u3[0] = *(q + 3) - *q;
		u3[1] = *(q + 4) - *(q + 1);
		u3[2] = *(q + 5) - *(q + 2);
		v3[0] = *(q + 6) - *(q + 3);
		v3[1] = *(q + 7) - *(q + 4);
		v3[2] = *(q + 8) - *(q + 5);
		*p = u3[2] * v3[1] - u3[1] * v3[2];
		*(p + 1) = u3[0] * v3[2] - u3[2] * v3[0];
		*(p + 2) = u3[1] * v3[0] - u3[0] * v3[1];
		GLfloat factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		std::memcpy(p + 3, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 6, p, 3 * sizeof(GLfloat));

		p += 9; q += vertex_dim_t3;
	}
#endif // SIMD
}

void kiwi::make_N_from_3d_quads_ccw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = N_ptr;
	const float* q = vertex_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	__m128 u;
	__m128 v;
	__m128 w;

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(w, _mm_loadu_ps(q));
		v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
		w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		std::memcpy(p + 3, p, 3 * sizeof(float));
		std::memcpy(p + 6, p, 3 * sizeof(float));
		std::memcpy(p + 9, p, 3 * sizeof(float));

		p += 12; q += vertex_dim_t4;
	}
#else
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	GLfloat u3[3];
	GLfloat v3[3];

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		u3[0] = *(q + 3) - *q;
		u3[1] = *(q + 4) - *(q + 1);
		u3[2] = *(q + 5) - *(q + 2);
		v3[0] = *(q + 6) - *(q + 3);
		v3[1] = *(q + 7) - *(q + 4);
		v3[2] = *(q + 8) - *(q + 5);
		*p = u3[1] * v3[2] - u3[2] * v3[1];
		*(p + 1) = u3[2] * v3[0] - u3[0] * v3[2];
		*(p + 2) = u3[0] * v3[1] - u3[1] * v3[0];
		GLfloat factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		std::memcpy(p + 3, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 6, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 9, p, 3 * sizeof(GLfloat));

		p += 12; q += vertex_dim_t4;
	}
#endif // SIMD
}

void kiwi::make_N_from_3d_quads_cw(GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = N_ptr;
	const float* q = vertex_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	__m128 u;
	__m128 v;
	__m128 w;

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
		v = _mm_sub_ps(w, _mm_loadu_ps(q));
		w = _mm_fnmadd_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2))));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		std::memcpy(p + 3, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 6, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 9, p, 3 * sizeof(GLfloat));

		p += 12; q += vertex_dim_t4;
	}
#else
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	GLfloat u3[3];
	GLfloat v3[3];

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		u3[0] = *(q + 3) - *q;
		u3[1] = *(q + 4) - *(q + 1);
		u3[2] = *(q + 5) - *(q + 2);
		v3[0] = *(q + 6) - *(q + 3);
		v3[1] = *(q + 7) - *(q + 4);
		v3[2] = *(q + 8) - *(q + 5);
		*p = u3[2] * v3[1] - u3[1] * v3[2];
		*(p + 1) = u3[0] * v3[2] - u3[2] * v3[0];
		*(p + 2) = u3[1] * v3[0] - u3[0] * v3[1];
		GLfloat factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		std::memcpy(p + 3, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 6, p, 3 * sizeof(GLfloat));
		std::memcpy(p + 9, p, 3 * sizeof(GLfloat));

		p += 12; q += vertex_dim_t4;
	}
#endif // SIMD
}

void kiwi::make_TBN_from_3d_triangles_ccw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = TBN_ptr;
	const float* q = vertex_ptr;
	const float* r = uv_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	float ut[4];

	__m128 u;
	__m128 v;
	__m128 w;
	__m128 a0;
	__m128 b0;
	__m128 a1;
	__m128 b1;

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		_mm_storeu_ps(static_cast<float*>(ut), _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r)));

		float factor = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = _mm_set1_ps(ut[3] * factor);
		b0 = _mm_set1_ps(-ut[1] * factor);
		a1 = _mm_set1_ps(-ut[2] * factor);
		b1 = _mm_set1_ps(ut[0] * factor);

		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(w, _mm_loadu_ps(q));
		v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);

		w = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		w = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		_mm_storeu_ps(p + 3, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 3))));
		_mm_storeu_ps(p + 3, w);

		w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		_mm_storeu_ps(p + 6, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 6))));
		_mm_storeu_ps(p + 6, w);

		std::memcpy(p + 9, p, 9 * sizeof(float));
		std::memcpy(p + 18, p, 9 * sizeof(float));

		p += 27; q += vertex_dim_t3; r += 6;
	}
#else
	GLfloat* p = TBN_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	GLfloat a0;
	GLfloat b0;
	GLfloat a1;
	GLfloat b1;
	GLfloat ut[4];
	GLfloat vt[3];

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		ut[0] = *(r + 2) - *r;
		ut[1] = *(r + 3) - *(r + 1);
		ut[2] = *(r + 4) - *(r + 2);
		ut[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = ut[3] * factor;
		b0 = -ut[1] * factor;
		a1 = -ut[2] * factor;
		b1 = ut[0] * factor;

		ut[0] = *(q + 3) - *q;
		ut[1] = *(q + 4) - *(q + 1);
		ut[2] = *(q + 5) - *(q + 2);

		vt[0] = *(q + 6) - *(q + 3);
		vt[1] = *(q + 7) - *(q + 4);
		vt[2] = *(q + 8) - *(q + 5);

		*p = a0 * ut[0] + b0 * vt[0];
		*(p + 1) = a0 * ut[1] + b0 * vt[1];
		*(p + 2) = a0 * ut[2] + b0 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		*(p + 3) = a1 * ut[0] + b1 * vt[0];
		*(p + 4) = a1 * ut[1] + b1 * vt[1];
		*(p + 5) = a1 * ut[2] + b1 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 3)) * (*(p + 3))
			+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));
		*(p + 3) *= factor;
		*(p + 4) *= factor;
		*(p + 5) *= factor;

		*(p + 6) = (*(ut + 1)) * (*(vt + 2)) - (*(ut + 2)) * (*(vt + 1));
		*(p + 7) = (*(ut + 2)) * (*(vt + 0)) - (*ut) * (*(vt + 2));
		*(p + 8) = (*ut) * (*(vt + 1)) - (*(ut + 1)) * (*(vt + 0));

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 6)) * (*(p + 6))
			+ (*(p + 7)) * (*(p + 7)) + (*(p + 8)) * (*(p + 8)));
		*(p + 6) *= factor;
		*(p + 7) *= factor;
		*(p + 8) *= factor;

		std::memcpy(p + 9, p, 9 * sizeof(GLfloat));
		std::memcpy(p + 18, p, 9 * sizeof(GLfloat));

		p += 27; q += vertex_dim_t3; r += 6;
	}
#endif // SIMD
}

void kiwi::make_TBN_from_3d_triangles_cw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = TBN_ptr;
	const float* q = vertex_ptr;
	const float* r = uv_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	float ut[4];

	__m128 u;
	__m128 v;
	__m128 w;
	__m128 a0;
	__m128 b0;
	__m128 a1;
	__m128 b1;

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		_mm_storeu_ps(static_cast<float*>(ut), _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r)));

		float factor = static_cast<GLfloat>(1) / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = _mm_set1_ps(ut[3] * factor);
		b0 = _mm_set1_ps(-ut[1] * factor);
		a1 = _mm_set1_ps(-ut[2] * factor);
		b1 = _mm_set1_ps(ut[0] * factor);

		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(w, _mm_loadu_ps(q));
		v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);

		w = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		w = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		_mm_storeu_ps(p + 3, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 3))));
		_mm_storeu_ps(p + 3, w);

		w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1))));
		_mm_storeu_ps(p + 6, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 6))));
		_mm_storeu_ps(p + 6, w);

		std::memcpy(p + 9, p, 9 * sizeof(float));
		std::memcpy(p + 18, p, 9 * sizeof(float));

		p += 27; q += vertex_dim_t3; r += 6;
	}
#else
	GLfloat* p = TBN_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	GLfloat a0;
	GLfloat b0;
	GLfloat a1;
	GLfloat b1;
	GLfloat ut[4];
	GLfloat vt[3];

	for (std::size_t j = 0; j + 2 < vertex_count; j += 3)
	{
		ut[0] = *(r + 2) - *r;
		ut[1] = *(r + 3) - *(r + 1);
		ut[2] = *(r + 4) - *(r + 2);
		ut[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = ut[3] * factor;
		b0 = -ut[1] * factor;
		a1 = -ut[2] * factor;
		b1 = ut[0] * factor;

		ut[0] = *(q + 3) - *(q);
		ut[1] = *(q + 4) - *(q + 1);
		ut[2] = *(q + 5) - *(q + 2);

		vt[0] = *(q + 6) - *(q + 3);
		vt[1] = *(q + 7) - *(q + 4);
		vt[2] = *(q + 8) - *(q + 5);

		*p = a0 * ut[0] + b0 * vt[0];
		*(p + 1) = a0 * ut[1] + b0 * vt[1];
		*(p + 2) = a0 * ut[2] + b0 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		*(p + 3) = a1 * ut[0] + b1 * vt[0];
		*(p + 4) = a1 * ut[1] + b1 * vt[1];
		*(p + 5) = a1 * ut[2] + b1 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 3)) * (*(p + 3))
			+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));
		*(p + 3) *= factor;
		*(p + 4) *= factor;
		*(p + 5) *= factor;

		*(p + 6) = (*(ut + 2)) * (*(vt + 1)) - (*(ut + 1)) * (*(vt + 2));
		*(p + 7) = (*ut) * (*(vt + 2)) - (*(ut + 2)) * (*(vt + 0));
		*(p + 8) = (*(ut + 1)) * (*(vt + 0)) - (*ut) * (*(vt + 1));

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 6)) * (*(p + 6))
			+ (*(p + 7)) * (*(p + 7)) + (*(p + 8)) * (*(p + 8)));
		*(p + 6) *= factor;
		*(p + 7) *= factor;
		*(p + 8) *= factor;

		std::memcpy(p + 9, p, 9 * sizeof(GLfloat));
		std::memcpy(p + 18, p, 9 * sizeof(GLfloat));

		p += 27; q += vertex_dim_t3; r += 6;
	}
#endif // SIMD
}

void kiwi::make_TBN_from_3d_quads_cw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = TBN_ptr;
	const float* q = vertex_ptr;
	const float* r = uv_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	float ut[4];

	__m128 u;
	__m128 v;
	__m128 w;
	__m128 a0;
	__m128 b0;
	__m128 a1;
	__m128 b1;

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		_mm_storeu_ps(static_cast<float*>(ut), _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r)));

		float factor = static_cast<GLfloat>(1) / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = _mm_set1_ps(ut[3] * factor);
		b0 = _mm_set1_ps(-ut[1] * factor);
		a1 = _mm_set1_ps(-ut[2] * factor);
		b1 = _mm_set1_ps(ut[0] * factor);

		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(w, _mm_loadu_ps(q));
		v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);

		w = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		w = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		_mm_storeu_ps(p + 3, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 3))));
		_mm_storeu_ps(p + 3, w);

		w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1))));
		_mm_storeu_ps(p + 6, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 6))));
		_mm_storeu_ps(p + 6, w);

		std::memcpy(p + 9, p, 9 * sizeof(float));
		std::memcpy(p + 18, p, 9 * sizeof(float));
		std::memcpy(p + 27, p, 9 * sizeof(float));

		p += 36; q += vertex_dim_t4; r += 8;
	}
#else
	GLfloat* p = TBN_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	GLfloat a0;
	GLfloat b0;
	GLfloat a1;
	GLfloat b1;
	GLfloat ut[4];
	GLfloat vt[3];

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		ut[0] = *(r + 2) - *r;
		ut[1] = *(r + 3) - *(r + 1);
		ut[2] = *(r + 4) - *(r + 2);
		ut[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = ut[3] * factor;
		b0 = -ut[1] * factor;
		a1 = -ut[2] * factor;
		b1 = ut[0] * factor;

		ut[0] = *(q + 3) - *(q);
		ut[1] = *(q + 4) - *(q + 1);
		ut[2] = *(q + 5) - *(q + 2);

		vt[0] = *(q + 6) - *(q + 3);
		vt[1] = *(q + 7) - *(q + 4);
		vt[2] = *(q + 8) - *(q + 5);

		*p = a0 * ut[0] + b0 * vt[0];
		*(p + 1) = a0 * ut[1] + b0 * vt[1];
		*(p + 2) = a0 * ut[2] + b0 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		*(p + 3) = a1 * ut[0] + b1 * vt[0];
		*(p + 4) = a1 * ut[1] + b1 * vt[1];
		*(p + 5) = a1 * ut[2] + b1 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 3)) * (*(p + 3))
			+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));
		*(p + 3) *= factor;
		*(p + 4) *= factor;
		*(p + 5) *= factor;

		*(p + 6) = (*(ut + 2)) * (*(vt + 1)) - (*(ut + 1)) * (*(vt + 2));
		*(p + 7) = (*ut) * (*(vt + 2)) - (*(ut + 2)) * (*(vt + 0));
		*(p + 8) = (*(ut + 1)) * (*(vt + 0)) - (*ut) * (*(vt + 1));

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 6)) * (*(p + 6))
			+ (*(p + 7)) * (*(p + 7)) + (*(p + 8)) * (*(p + 8)));
		*(p + 6) *= factor;
		*(p + 7) *= factor;
		*(p + 8) *= factor;

		std::memcpy(p + 9, p, 9 * sizeof(GLfloat));
		std::memcpy(p + 18, p, 9 * sizeof(GLfloat));
		std::memcpy(p + 27, p, 9 * sizeof(GLfloat));

		p += 36; q += vertex_dim_t4; r += 8;
	}
#endif // SIMD
}

void kiwi::make_TBN_from_3d_quads_ccw(GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#if defined(__AVX2__) && defined(__FMA__)
	float* p = TBN_ptr;
	const float* q = vertex_ptr;
	const float* r = uv_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	float ut[4];

	__m128 u;
	__m128 v;
	__m128 w;
	__m128 a0;
	__m128 b0;
	__m128 a1;
	__m128 b1;

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		_mm_storeu_ps(static_cast<float*>(ut), _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r)));

		float factor = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = _mm_set1_ps(ut[3] * factor);
		b0 = _mm_set1_ps(-ut[1] * factor);
		a1 = _mm_set1_ps(-ut[2] * factor);
		b1 = _mm_set1_ps(ut[0] * factor);

		w = _mm_loadu_ps(q + 3);
		u = _mm_sub_ps(w, _mm_loadu_ps(q));
		v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);

		w = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*p)));
		_mm_storeu_ps(p, w);

		w = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		_mm_storeu_ps(p + 3, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 3))));
		_mm_storeu_ps(p + 3, w);

		w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		_mm_storeu_ps(p + 6, _mm_dp_ps(w, w, 0x7f));
		w = _mm_mul_ps(w, _mm_set1_ps(1.0f / std::sqrt(*(p + 6))));
		_mm_storeu_ps(p + 6, w);

		std::memcpy(p + 9, p, 9 * sizeof(float));
		std::memcpy(p + 18, p, 9 * sizeof(float));
		std::memcpy(p + 27, p, 9 * sizeof(float));

		p += 36; q += vertex_dim_t4; r += 8;
	}
#else
	GLfloat* p = TBN_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	GLfloat a0;
	GLfloat b0;
	GLfloat a1;
	GLfloat b1;
	GLfloat ut[4];
	GLfloat vt[3];

	for (std::size_t j = 0; j + 3 < vertex_count; j += 4)
	{
		ut[0] = *(r + 2) - *r;
		ut[1] = *(r + 3) - *(r + 1);
		ut[2] = *(r + 4) - *(r + 2);
		ut[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (ut[0] * ut[3] - ut[1] * ut[2]);

		a0 = ut[3] * factor;
		b0 = -ut[1] * factor;
		a1 = -ut[2] * factor;
		b1 = ut[0] * factor;

		ut[0] = *(q + 3) - *q;
		ut[1] = *(q + 4) - *(q + 1);
		ut[2] = *(q + 5) - *(q + 2);

		vt[0] = *(q + 6) - *(q + 3);
		vt[1] = *(q + 7) - *(q + 4);
		vt[2] = *(q + 8) - *(q + 5);

		*p = a0 * ut[0] + b0 * vt[0];
		*(p + 1) = a0 * ut[1] + b0 * vt[1];
		*(p + 2) = a0 * ut[2] + b0 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		*(p + 3) = a1 * ut[0] + b1 * vt[0];
		*(p + 4) = a1 * ut[1] + b1 * vt[1];
		*(p + 5) = a1 * ut[2] + b1 * vt[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 3)) * (*(p + 3))
			+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));
		*(p + 3) *= factor;
		*(p + 4) *= factor;
		*(p + 5) *= factor;

		*(p + 6) = (*(ut + 1)) * (*(vt + 2)) - (*(ut + 2)) * (*(vt + 1));
		*(p + 7) = (*(ut + 2)) * (*(vt + 0)) - (*ut) * (*(vt + 2));
		*(p + 8) = (*ut) * (*(vt + 1)) - (*(ut + 1)) * (*(vt + 0));

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 6)) * (*(p + 6))
			+ (*(p + 7)) * (*(p + 7)) + (*(p + 8)) * (*(p + 8)));
		*(p + 6) *= factor;
		*(p + 7) *= factor;
		*(p + 8) *= factor;

		std::memcpy(p + 9, p, 9 * sizeof(GLfloat));
		std::memcpy(p + 18, p, 9 * sizeof(GLfloat));
		std::memcpy(p + 27, p, 9 * sizeof(GLfloat));

		p += 36; q += vertex_dim_t4; r += 8;
	}
#endif // SIMD
}