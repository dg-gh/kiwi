#include "buffers/kiwi_buffer_pixel.hpp"

GLuint kiwi::pixel_buffer::get_id() noexcept
{
	return m_buffer_index;
}

kiwi::pixel_buffer_type kiwi::pixel_buffer::get_pixel_buffer_type() const noexcept
{
	return m_pixel_buffer_type;
}

void kiwi::pixel_buffer::set_pixel_mapping(kiwi::pixel_mapping mapping, GLint* mapping_mag_ptr, GLint* mapping_min_ptr) noexcept
{
	switch (mapping)
	{
	case kiwi::pixel_mapping::nearest: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST; break;
	case kiwi::pixel_mapping::linear: *mapping_mag_ptr = GL_LINEAR; *mapping_min_ptr = GL_LINEAR; break;
	case kiwi::pixel_mapping::nearest_mipmap_nearest: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST_MIPMAP_NEAREST; break;
	case kiwi::pixel_mapping::linear_mipmap_nearest: *mapping_mag_ptr = GL_LINEAR; *mapping_min_ptr = GL_LINEAR_MIPMAP_NEAREST; break;
	case kiwi::pixel_mapping::nearest_mipmap_linear: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST_MIPMAP_LINEAR; break;
	case kiwi::pixel_mapping::linear_mipmap_linear: *mapping_mag_ptr = GL_LINEAR; *mapping_min_ptr = GL_LINEAR_MIPMAP_LINEAR; break;

	default: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST; break;
	}
}

void kiwi::pixel_buffer::set_pixel_mapping(kiwi::pixel_mapping mapping, GLint* mapping_mag_ptr, GLint* mapping_min_ptr, bool* mipmap_ptr) noexcept
{
	switch (mapping)
	{
	case kiwi::pixel_mapping::nearest: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST; *mipmap_ptr = false; break;
	case kiwi::pixel_mapping::linear: *mapping_mag_ptr = GL_LINEAR; *mapping_min_ptr = GL_LINEAR; *mipmap_ptr = false; break;
	case kiwi::pixel_mapping::nearest_mipmap_nearest: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST_MIPMAP_NEAREST; *mipmap_ptr = true; break;
	case kiwi::pixel_mapping::linear_mipmap_nearest: *mapping_mag_ptr = GL_LINEAR; *mapping_min_ptr = GL_LINEAR_MIPMAP_NEAREST; *mipmap_ptr = true; break;
	case kiwi::pixel_mapping::nearest_mipmap_linear: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST_MIPMAP_LINEAR; *mipmap_ptr = true; break;
	case kiwi::pixel_mapping::linear_mipmap_linear: *mapping_mag_ptr = GL_LINEAR; *mapping_min_ptr = GL_LINEAR_MIPMAP_LINEAR; *mipmap_ptr = true; break;

	default: *mapping_mag_ptr = GL_NEAREST; *mapping_min_ptr = GL_NEAREST; *mipmap_ptr = false; break;
	}
}

void kiwi::pixel_buffer::set_pixel_wrapping(kiwi::pixel_wrapping wrapping, GLint* wrapping_ptr) noexcept
{
	switch (wrapping)
	{
	case kiwi::pixel_wrapping::repeat: *wrapping_ptr = GL_REPEAT; break;
	case kiwi::pixel_wrapping::repeat_mirrored: *wrapping_ptr = GL_MIRRORED_REPEAT; break;
	case kiwi::pixel_wrapping::clamp: *wrapping_ptr = GL_CLAMP_TO_EDGE; break;
	case kiwi::pixel_wrapping::pad: *wrapping_ptr = GL_CLAMP_TO_BORDER; break;

	default: *wrapping_ptr = GL_CLAMP_TO_BORDER; break;
	}
}

void kiwi::pixel_buffer::set_pixel_format(kiwi::pixel_format format, std::size_t pixel_dimension, GLint* internal_format_ptr) noexcept
{
	switch (pixel_dimension)
	{
	case 1:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_R8; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_R16; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_R16F; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_R32F; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_R8UI; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_R16UI; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_R32UI; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_R8I; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_R16I; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_R32I; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_R8; break;
		}
		break;
	}

	case 2:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RG8; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RG16; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RG16F; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RG32F; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RG8UI; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RG16UI; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RG32UI; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RG8I; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RG16I; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RG32I; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_RG8; break;
		}
		break;
	}

	case 3:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RGB8; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RGB16; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RGB16F; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RGB32F; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RGB8UI; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RGB16UI; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RGB32UI; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RGB8I; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RGB16I; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RGB32I; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_RGB8; break;
		}
		break;
	}

	case 4:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RGBA8; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RGBA16; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RGBA16F; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RGBA32F; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RGBA8UI; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RGBA16UI; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RGBA32UI; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RGBA8I; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RGBA16I; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RGBA32I; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_RGBA8; break;
		}
		break;
	}

	default:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_R8; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_R16; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_R16F; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_R32F; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_R8UI; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_R16UI; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_R32UI; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_R8I; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_R16I; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_R32I; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_R8; break;
		}
		break;
	}

	}
}

void kiwi::pixel_buffer::set_pixel_format(kiwi::pixel_format format, std::size_t pixel_dimension,
	GLint* internal_format_ptr, GLenum* color_format_ptr) noexcept
{
	switch (pixel_dimension)
	{
	case 1:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_R16; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_R16F; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_R32F; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_R8UI; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_R16UI; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_R32UI; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_R8I; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_R16I; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_R32I; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; break;
		}
		break;
	}

	case 2:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RG8; *color_format_ptr = GL_RG; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RG16; *color_format_ptr = GL_RG; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RG16F; *color_format_ptr = GL_RG; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RG32F; *color_format_ptr = GL_RG; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RG8UI; *color_format_ptr = GL_RG_INTEGER; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RG16UI; *color_format_ptr = GL_RG_INTEGER; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RG32UI; *color_format_ptr = GL_RG_INTEGER; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RG8I; *color_format_ptr = GL_RG_INTEGER; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RG16I; *color_format_ptr = GL_RG_INTEGER; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RG32I; *color_format_ptr = GL_RG_INTEGER; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_RG8; *color_format_ptr = GL_RG; break;
		}
		break;
	}

	case 3:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RGB8; *color_format_ptr = GL_RGB; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RGB16; *color_format_ptr = GL_RGB; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RGB16F; *color_format_ptr = GL_RGB; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RGB32F; *color_format_ptr = GL_RGB; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RGB8UI; *color_format_ptr = GL_RGB_INTEGER; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RGB16UI; *color_format_ptr = GL_RGB_INTEGER; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RGB32UI; *color_format_ptr = GL_RGB_INTEGER; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RGB8I; *color_format_ptr = GL_RGB_INTEGER; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RGB16I; *color_format_ptr = GL_RGB_INTEGER; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RGB32I; *color_format_ptr = GL_RGB_INTEGER; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_RGB8; *color_format_ptr = GL_RGB; break;
		}
		break;
	}

	case 4:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RGBA8; *color_format_ptr = GL_RGBA; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RGBA16; *color_format_ptr = GL_RGBA; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RGBA16F; *color_format_ptr = GL_RGBA; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RGBA32F; *color_format_ptr = GL_RGBA; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RGBA8UI; *color_format_ptr = GL_RGBA_INTEGER; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RGBA16UI; *color_format_ptr = GL_RGBA_INTEGER;  break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RGBA32UI; *color_format_ptr = GL_RGBA_INTEGER; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RGBA8I; *color_format_ptr = GL_RGBA_INTEGER; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RGBA16I; *color_format_ptr = GL_RGBA_INTEGER; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RGBA32I; *color_format_ptr = GL_RGBA_INTEGER; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_RGBA8; *color_format_ptr = GL_RGBA; break;
		}
		break;
	}

	default:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_R16; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_R16F; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_R32F; *color_format_ptr = GL_RED; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_R8UI; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_R16UI; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_R32UI; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_R8I; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_R16I; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_R32I; *color_format_ptr = GL_RED_INTEGER; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; break;

		default: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; break;
		}
		break;
	}

	}
}

void kiwi::pixel_buffer::set_pixel_format(kiwi::pixel_format format, std::size_t pixel_dimension,
	GLint* internal_format_ptr, GLenum* color_format_ptr, GLenum* type_ptr) noexcept
{
	switch (pixel_dimension)
	{
	case 1:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_R16; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_R16F; *color_format_ptr = GL_RED; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_R32F; *color_format_ptr = GL_RED; *type_ptr = GL_FLOAT; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_R8UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_R16UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_R32UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_R8I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_R16I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_R32I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;

		default: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_BYTE; break;
		}
		break;
	}

	case 2:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RG8; *color_format_ptr = GL_RG; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RG16; *color_format_ptr = GL_RG; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RG16F; *color_format_ptr = GL_RG; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RG32F; *color_format_ptr = GL_RG; *type_ptr = GL_FLOAT; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RG8UI; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RG16UI; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RG32UI; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RG8I; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RG16I; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RG32I; *color_format_ptr = GL_RG_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;

		default: *internal_format_ptr = GL_RG8; *color_format_ptr = GL_RG; *type_ptr = GL_UNSIGNED_BYTE; break;
		}
		break;
	}

	case 3:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RGB8; *color_format_ptr = GL_RGB; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RGB16; *color_format_ptr = GL_RGB; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RGB16F; *color_format_ptr = GL_RGB; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RGB32F; *color_format_ptr = GL_RGB; *type_ptr = GL_FLOAT; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RGB8UI; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RGB16UI; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RGB32UI; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RGB8I; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RGB16I; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RGB32I; *color_format_ptr = GL_RGB_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;

		default: *internal_format_ptr = GL_RGB8; *color_format_ptr = GL_RGB; *type_ptr = GL_UNSIGNED_BYTE; break;
		}
		break;
	}

	case 4:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_RGBA8; *color_format_ptr = GL_RGBA; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_RGBA16; *color_format_ptr = GL_RGBA; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_RGBA16F; *color_format_ptr = GL_RGBA; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_RGBA32F; *color_format_ptr = GL_RGBA; *type_ptr = GL_FLOAT; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_RGBA8UI; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_RGBA16UI; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_RGBA32UI; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_RGBA8I; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_RGBA16I; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_RGBA32I; *color_format_ptr = GL_RGBA_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;

		default: *internal_format_ptr = GL_RGBA8; *color_format_ptr = GL_RGBA; *type_ptr = GL_UNSIGNED_BYTE; break;
		}
		break;
	}

	default:
	{
		switch (format)
		{
		case kiwi::pixel_format::u8: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16: *internal_format_ptr = GL_R16; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::f16: *internal_format_ptr = GL_R16F; *color_format_ptr = GL_RED; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::f32: *internal_format_ptr = GL_R32F; *color_format_ptr = GL_RED; *type_ptr = GL_FLOAT; break;
		case kiwi::pixel_format::u8u: *internal_format_ptr = GL_R8UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_BYTE; break;
		case kiwi::pixel_format::u16u: *internal_format_ptr = GL_R16UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_SHORT; break;
		case kiwi::pixel_format::u32u: *internal_format_ptr = GL_R32UI; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_UNSIGNED_INT; break;
		case kiwi::pixel_format::i8u: *internal_format_ptr = GL_R8I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_BYTE; break;
		case kiwi::pixel_format::i16u: *internal_format_ptr = GL_R16I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_SHORT; break;
		case kiwi::pixel_format::i32u: *internal_format_ptr = GL_R32I; *color_format_ptr = GL_RED_INTEGER; *type_ptr = GL_INT; break;
		case kiwi::pixel_format::dep16: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_HALF_FLOAT; break;
		case kiwi::pixel_format::dep32: *internal_format_ptr = GL_DEPTH_COMPONENT; *color_format_ptr = GL_DEPTH_COMPONENT; *type_ptr = GL_FLOAT; break;

		default: *internal_format_ptr = GL_R8; *color_format_ptr = GL_RED; *type_ptr = GL_UNSIGNED_BYTE; break;
		}
		break;
	}

	}
}