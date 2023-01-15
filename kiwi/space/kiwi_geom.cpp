#include "space/kiwi_geom.hpp"
#include "header_utils/kiwi_simd.hpp"


kiwi::_load_frame_proxy kiwi::load_geom(kiwi::vertex_buffer& vertex_buffer) noexcept
{
	kiwi::_load_frame_proxy proxy;
	proxy.m_buffer_ptr = &vertex_buffer;
	return proxy;
}

void kiwi::make_N_from_lines_2d(kiwi::orient orientation, GLfloat* const  _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t2 = vertex_dim * 2;
	GLfloat orient_coeff = static_cast<GLfloat>(orientation) - static_cast<GLfloat>(1);

	for (std::size_t j = 1; j < vertex_count; j += 2)
	{
		*p = *(q + 1) - *(q + vertex_dim + 1);
		*(p + 1) = *(q + vertex_dim) - *q;

		GLfloat factor = orient_coeff / std::sqrt((*p) * (*p) + (*(p + 1)) * (*(p + 1)));

		*p *= factor;
		*(p + 1) *= factor;

		std::memcpy(p + 2, p, 2 * sizeof(GLfloat));

		p += 4; q += vertex_dim_t2;
	}
}

void kiwi::make_TB_from_triangles_2d(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = TB_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;

	GLfloat uv_vec[4];

	for (std::size_t j = 2; j < vertex_count; j += 3)
	{
		uv_vec[0] = *(r + 2) - *r;
		uv_vec[1] = *(r + 3) - *(r + 1);
		uv_vec[2] = *(r + 4) - *(r + 2);
		uv_vec[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (uv_vec[0] * uv_vec[3] - uv_vec[1] * uv_vec[2]);

		GLfloat a0 = uv_vec[3] * factor;
		GLfloat b0 = -uv_vec[1] * factor;
		GLfloat a1 = -uv_vec[2] * factor;
		GLfloat b1 = uv_vec[0] * factor;

		uv_vec[0] = *(q + vertex_dim) - *q;
		uv_vec[1] = *(q + vertex_dim + 1) - *(q + 1);

		uv_vec[2] = *(q + vertex_dim_t2) - *(q + vertex_dim);
		uv_vec[3] = *(q + vertex_dim_t2 + 1) - *(q + vertex_dim + 1);

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

		p += 12; q += vertex_dim_t3; r += 6;
	}
}

void kiwi::make_TB_from_quads_2d(GLfloat* const _KIWI_RESTRICT TB_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
	GLfloat* p = TB_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;

	GLfloat uv_vec[4];

	for (std::size_t j = 3; j < vertex_count; j += 4)
	{
		uv_vec[0] = *(r + 2) - *r;
		uv_vec[1] = *(r + 3) - *(r + 1);
		uv_vec[2] = *(r + 4) - *(r + 2);
		uv_vec[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (uv_vec[0] * uv_vec[3] - uv_vec[1] * uv_vec[2]);
		GLfloat a0 = uv_vec[3] * factor;
		GLfloat b0 = -uv_vec[1] * factor;
		GLfloat a1 = -uv_vec[2] * factor;
		GLfloat b1 = uv_vec[0] * factor;

		uv_vec[0] = *(q + vertex_dim) - *q;
		uv_vec[1] = *(q + vertex_dim + 1) - *(q + 1);

		uv_vec[2] = *(q + vertex_dim_t2) - *(q + vertex_dim);
		uv_vec[3] = *(q + vertex_dim_t2 + 1) - *(q + vertex_dim + 1);

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

		p += 16; q += vertex_dim_t4; r += 8;
	}
}

void kiwi::make_N_from_triangles_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#ifdef _KIWI_AVX2_FMA
	float* p = N_ptr;
	const float* q = vertex_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	float orient_coeff = static_cast<float>(orientation) - 1.0f;
	
	union { __m128 v; float arr[4]; } varr;

	for (std::size_t j = 5; j < vertex_count; j += 3)
	{
		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		__m128 v = _mm_sub_ps(_mm_loadu_ps(q + vertex_dim_t2), w);
		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		_mm_storeu_ps(p + 3, w);
		_mm_storeu_ps(p + 6, w);

		p += 9; q += vertex_dim_t3;
	}
	if (vertex_count >= 3)
	{
		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		q += vertex_dim_t2;
		__m128 v = _mm_sub_ps(_mm_setr_ps(*q, *(q + 1), *(q + 2), 0.0f), w);
		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		_mm_storeu_ps(p + 3, w);
		std::memcpy(p + 6, p, 3 * sizeof(float));
	}
#else
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	GLfloat orient_coeff = static_cast<GLfloat>(orientation) - static_cast<GLfloat>(1);

	GLfloat u3[3];
	GLfloat v3[3];

	for (std::size_t j = 2; j < vertex_count; j += 3)
	{
		u3[0] = *(q + vertex_dim) - *q;
		u3[1] = *(q + vertex_dim + 1) - *(q + 1);
		u3[2] = *(q + vertex_dim + 2) - *(q + 2);

		v3[0] = *(q + vertex_dim_t2) - *(q + vertex_dim);
		v3[1] = *(q + vertex_dim_t2 + 1) - *(q + vertex_dim + 1);
		v3[2] = *(q + vertex_dim_t2 + 2) - *(q + vertex_dim + 2);

		*p = u3[1] * v3[2] - u3[2] * v3[1];
		*(p + 1) = u3[2] * v3[0] - u3[0] * v3[2];
		*(p + 2) = u3[0] * v3[1] - u3[1] * v3[0];

		GLfloat factor = orient_coeff / std::sqrt((*p) * (*p)
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

void kiwi::make_N_from_quads_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT N_ptr, const GLfloat* const vertex_ptr, std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#ifdef _KIWI_AVX2_FMA
	float* p = N_ptr;
	const float* q = vertex_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	float orient_coeff = static_cast<float>(orientation) - 1.0f;

	union { __m128 v; float arr[4]; } varr;

	for (std::size_t j = 7; j < vertex_count; j += 4)
	{
		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		__m128 v = _mm_sub_ps(_mm_loadu_ps(q + vertex_dim_t2), w);
		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		_mm_storeu_ps(p + 3, w);
		_mm_storeu_ps(p + 6, w);
		_mm_storeu_ps(p + 9, w);

		p += 12; q += vertex_dim_t4;
	}
	if (vertex_count >= 4)
	{
		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		q += vertex_dim_t2;
		__m128 v = _mm_sub_ps(_mm_setr_ps(*q, *(q + 1), *(q + 2), 0.0f), w);
		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		_mm_storeu_ps(p + 3, w);
		_mm_storeu_ps(p + 6, w);
		std::memcpy(p + 9, p, 3 * sizeof(GLfloat));
	}
#else
	GLfloat* p = N_ptr;
	const GLfloat* q = vertex_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	GLfloat orient_coeff = static_cast<GLfloat>(orientation) - static_cast<GLfloat>(1);

	GLfloat u3[3];
	GLfloat v3[3];

	for (std::size_t j = 3; j < vertex_count; j += 4)
	{
		u3[0] = *(q + vertex_dim) - *q;
		u3[1] = *(q + vertex_dim + 1) - *(q + 1);
		u3[2] = *(q + vertex_dim + 2) - *(q + 2);

		v3[0] = *(q + vertex_dim_t2) - *(q + vertex_dim);
		v3[1] = *(q + vertex_dim_t2 + 1) - *(q + vertex_dim + 1);
		v3[2] = *(q + vertex_dim_t2 + 2) - *(q + vertex_dim + 2);

		*p = u3[1] * v3[2] - u3[2] * v3[1];
		*(p + 1) = u3[2] * v3[0] - u3[0] * v3[2];
		*(p + 2) = u3[0] * v3[1] - u3[1] * v3[0];

		GLfloat factor = orient_coeff / std::sqrt((*p) * (*p)
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

void kiwi::make_TBN_from_triangles_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#ifdef _KIWI_AVX2_FMA
	float* p = TBN_ptr;
	const float* q = vertex_ptr;
	const float* r = uv_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	float orient_coeff = static_cast<float>(orientation) - 1.0f;

	union { __m128 v; float arr[4]; } varr;

	for (std::size_t j = 5; j < vertex_count; j += 3)
	{
		varr.v = _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r));
		varr.v = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / (varr.arr[0] * varr.arr[3] - varr.arr[1] * varr.arr[2])));

		__m128 a0 = _mm_set1_ps(varr.arr[3]);
		__m128 b0 = _mm_set1_ps(-varr.arr[1]);
		__m128 a1 = _mm_set1_ps(-varr.arr[2]);
		__m128 b1 = _mm_set1_ps(varr.arr[0]);

		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		__m128 v = _mm_sub_ps(_mm_loadu_ps(q + vertex_dim_t2), w);

		varr.v = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		varr.v = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 3, w);

		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 6, w);

		__m256 cp = _mm256_loadu_ps(p);
		float cplast = *(p + 8);
		_mm256_storeu_ps(p + 9, cp);
		*(p + 17) = cplast;
		_mm256_storeu_ps(p + 18, cp);
		*(p + 26) = cplast;

		p += 27; q += vertex_dim_t3; r += 6;
	}
	if (vertex_count >= 3)
	{
		varr.v = _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r));
		varr.v = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / (varr.arr[0] * varr.arr[3] - varr.arr[1] * varr.arr[2])));

		__m128 a0 = _mm_set1_ps(varr.arr[3]);
		__m128 b0 = _mm_set1_ps(-varr.arr[1]);
		__m128 a1 = _mm_set1_ps(-varr.arr[2]);
		__m128 b1 = _mm_set1_ps(varr.arr[0]);

		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		q += vertex_dim_t2;
		__m128 v = _mm_sub_ps(_mm_setr_ps(*q, *(q + 1), *(q + 2), 0.0f), w);

		varr.v = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		varr.v = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 3, w);

		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 6, w);

		__m256 cp = _mm256_loadu_ps(p);
		float cplast = *(p + 8);
		_mm256_storeu_ps(p + 9, cp);
		*(p + 17) = cplast;
		_mm256_storeu_ps(p + 18, cp);
		*(p + 26) = cplast;
	}
#else
	GLfloat* p = TBN_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t3 = 3 * vertex_dim;
	GLfloat orient_coeff = static_cast<GLfloat>(orientation) - static_cast<GLfloat>(1);

	GLfloat u4[4];
	GLfloat v3[3];

	for (std::size_t j = 2; j < vertex_count; j += 3)
	{
		u4[0] = *(r + 2) - *r;
		u4[1] = *(r + 3) - *(r + 1);
		u4[2] = *(r + 4) - *(r + 2);
		u4[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (u4[0] * u4[3] - u4[1] * u4[2]);

		GLfloat a0 = u4[3] * factor;
		GLfloat b0 = -u4[1] * factor;
		GLfloat a1 = -u4[2] * factor;
		GLfloat b1 = u4[0] * factor;

		u4[0] = *(q + vertex_dim) - *q;
		u4[1] = *(q + vertex_dim + 1) - *(q + 1);
		u4[2] = *(q + vertex_dim + 2) - *(q + 2);

		v3[0] = *(q + vertex_dim_t2) - *(q + vertex_dim);
		v3[1] = *(q + vertex_dim_t2 + 1) - *(q + vertex_dim + 1);
		v3[2] = *(q + vertex_dim_t2 + 2) - *(q + vertex_dim + 2);

		*p = a0 * u4[0] + b0 * v3[0];
		*(p + 1) = a0 * u4[1] + b0 * v3[1];
		*(p + 2) = a0 * u4[2] + b0 * v3[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));

		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		*(p + 3) = a1 * u4[0] + b1 * v3[0];
		*(p + 4) = a1 * u4[1] + b1 * v3[1];
		*(p + 5) = a1 * u4[2] + b1 * v3[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 3)) * (*(p + 3))
			+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));

		*(p + 3) *= factor;
		*(p + 4) *= factor;
		*(p + 5) *= factor;

		*(p + 6) = u4[1] * v3[2] - u4[2] * v3[1];
		*(p + 7) = u4[2] * v3[0] - u4[0] * v3[2];
		*(p + 8) = u4[0] * v3[1] - u4[1] * v3[0];

		factor = orient_coeff / std::sqrt((*(p + 6)) * (*(p + 6))
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

void kiwi::make_TBN_from_quads_3d(kiwi::orient orientation, GLfloat* const _KIWI_RESTRICT TBN_ptr, const GLfloat* const vertex_ptr, const GLfloat* const uv_ptr,
	std::size_t vertex_count, std::size_t vertex_dim) noexcept
{
#ifdef _KIWI_AVX2_FMA
	float* p = TBN_ptr;
	const float* q = vertex_ptr;
	const float* r = uv_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	float orient_coeff = static_cast<float>(orientation) - 1.0f;

	union { __m128 v; float arr[4]; } varr;

	for (std::size_t j = 7; j < vertex_count; j += 4)
	{
		varr.v = _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r));
		varr.v = _mm_mul_ps(varr.v, _mm_set1_ps(static_cast<GLfloat>(1) / (varr.arr[0] * varr.arr[3] - varr.arr[1] * varr.arr[2])));

		__m128 a0 = _mm_set1_ps(varr.arr[3]);
		__m128 b0 = _mm_set1_ps(-varr.arr[1]);
		__m128 a1 = _mm_set1_ps(-varr.arr[2]);
		__m128 b1 = _mm_set1_ps(varr.arr[0]);

		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		__m128 v = _mm_sub_ps(_mm_loadu_ps(q + vertex_dim_t2), w);

		varr.v = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		varr.v = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 3, w);

		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 6, w);

		__m256 cp = _mm256_loadu_ps(p);
		float cplast = *(p + 8);
		_mm256_storeu_ps(p + 9, cp);
		*(p + 17) = cplast;
		_mm256_storeu_ps(p + 18, cp);
		*(p + 26) = cplast;
		_mm256_storeu_ps(p + 27, cp);
		*(p + 35) = cplast;

		p += 36; q += vertex_dim_t4; r += 8;
	}
	if (vertex_count >= 4)
	{
		varr.v = _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r));
		varr.v = _mm_mul_ps(varr.v, _mm_set1_ps(static_cast<GLfloat>(1) / (varr.arr[0] * varr.arr[3] - varr.arr[1] * varr.arr[2])));

		__m128 a0 = _mm_set1_ps(varr.arr[3]);
		__m128 b0 = _mm_set1_ps(-varr.arr[1]);
		__m128 a1 = _mm_set1_ps(-varr.arr[2]);
		__m128 b1 = _mm_set1_ps(varr.arr[0]);

		__m128 w = _mm_loadu_ps(q + vertex_dim);
		__m128 u = _mm_sub_ps(w, _mm_loadu_ps(q));
		q += vertex_dim_t2;
		__m128 v = _mm_sub_ps(_mm_setr_ps(*q, *(q + 1), *(q + 2), 0.0f), w);

		varr.v = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p, w);

		varr.v = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(1.0f / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 3, w);

		varr.v = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
			_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
			_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
		w = _mm_mul_ps(varr.v, _mm_set1_ps(orient_coeff / std::sqrt(varr.arr[0] * varr.arr[0] + varr.arr[1] * varr.arr[1] + varr.arr[2] * varr.arr[2])));
		_mm_storeu_ps(p + 6, w);

		__m256 cp = _mm256_loadu_ps(p);
		float cplast = *(p + 8);
		_mm256_storeu_ps(p + 9, cp);
		*(p + 17) = cplast;
		_mm256_storeu_ps(p + 18, cp);
		*(p + 26) = cplast;
		_mm256_storeu_ps(p + 27, cp);
		*(p + 35) = cplast;
	}
#else
	GLfloat* p = TBN_ptr;
	const GLfloat* q = vertex_ptr;
	const GLfloat* r = uv_ptr;
	std::size_t vertex_dim_t2 = 2 * vertex_dim;
	std::size_t vertex_dim_t4 = 4 * vertex_dim;
	GLfloat orient_coeff = static_cast<GLfloat>(orientation) - static_cast<GLfloat>(1);

	GLfloat u4[4];
	GLfloat v3[3];

	for (std::size_t j = 3; j < vertex_count; j += 4)
	{
		u4[0] = *(r + 2) - *r;
		u4[1] = *(r + 3) - *(r + 1);
		u4[2] = *(r + 4) - *(r + 2);
		u4[3] = *(r + 5) - *(r + 3);

		GLfloat factor = static_cast<GLfloat>(1) / (u4[0] * u4[3] - u4[1] * u4[2]);

		GLfloat a0 = u4[3] * factor;
		GLfloat b0 = -u4[1] * factor;
		GLfloat a1 = -u4[2] * factor;
		GLfloat b1 = u4[0] * factor;

		u4[0] = *(q + vertex_dim) - *q;
		u4[1] = *(q + vertex_dim + 1) - *(q + 1);
		u4[2] = *(q + vertex_dim + 2) - *(q + 2);

		v3[0] = *(q + vertex_dim_t2) - *(q + vertex_dim);
		v3[1] = *(q + vertex_dim_t2 + 1) - *(q + vertex_dim + 1);
		v3[2] = *(q + vertex_dim_t2 + 2) - *(q + vertex_dim + 2);

		*p = a0 * u4[0] + b0 * v3[0];
		*(p + 1) = a0 * u4[1] + b0 * v3[1];
		*(p + 2) = a0 * u4[2] + b0 * v3[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*p) * (*p)
			+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));

		*p *= factor;
		*(p + 1) *= factor;
		*(p + 2) *= factor;

		*(p + 3) = a1 * u4[0] + b1 * v3[0];
		*(p + 4) = a1 * u4[1] + b1 * v3[1];
		*(p + 5) = a1 * u4[2] + b1 * v3[2];

		factor = static_cast<GLfloat>(1) / std::sqrt((*(p + 3)) * (*(p + 3))
			+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));

		*(p + 3) *= factor;
		*(p + 4) *= factor;
		*(p + 5) *= factor;

		*(p + 6) = u4[1] * v3[2] - u4[2] * v3[1];
		*(p + 7) = u4[2] * v3[0] - u4[0] * v3[2];
		*(p + 8) = u4[0] * v3[1] - u4[1] * v3[0];

		factor = orient_coeff / std::sqrt((*(p + 6)) * (*(p + 6))
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