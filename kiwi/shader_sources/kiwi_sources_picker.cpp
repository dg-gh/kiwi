#include "shader_sources/kiwi_sources_picker.hpp"



const char* const kiwi::source::picker_2d::vertex_shader() noexcept
{
	return

		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XY;				\n"
		"	uniform mat3 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		vec3 in_XYh = u_mvp_M * vec3(vec2(in_XY), 1.0);	\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],		\n"
		"			in_XY[2], 1.0);								\n"
		"	}													\n"
		;
}
const char* const kiwi::source::picker_2d::fragment_shader() noexcept
{
	return
		
		"	#version 430 core									\n"
		"	layout (binding = 0) out uint entity_id;			\n"
		"	uniform uint u_entity_id;							\n"

		"	void main()											\n"
		"	{													\n"
		"		entity_id = u_entity_id;						\n"
		"	}													\n"
		;
}

const char* const kiwi::source::picker_XY_id_2d::vertex_shader() noexcept
{
	return

		"	#version 430 core														\n"
		"	layout (location = 0) in vec2 in_XY;									\n"
		"	struct t_XY_id { vec3 XY; uint id; };									\n"
		"	layout (std430, binding = 0) buffer s_XY_id { t_XY_id XY_id[]; };		\n"
		"	flat out uint _entity_id;												\n"
		"	uniform mat3 u_mvp_M;													\n"

		"	void main()																\n"
		"	{																		\n"
		"		vec3 in_XYh = u_mvp_M * vec3(in_XY									\n"
		"			+ vec2(XY_id[gl_InstanceID].XY), 1.0);							\n"

		"		gl_Position = vec4(in_XYh[0], in_XYh[1],							\n"
		"			XY_id[gl_InstanceID].XY[2], 1.0);								\n"

		"		_entity_id = XY_id[gl_InstanceID].id;								\n"
		"	}																		\n"
		;
}
const char* const kiwi::source::picker_XY_id_2d::fragment_shader() noexcept
{
	return

		"	#version 430 core														\n"
		"	flat in uint _entity_id;												\n"
		"	layout (binding = 0) out uint entity_id;								\n"

		"	void main()																\n"
		"	{																		\n"
		"		entity_id = _entity_id;												\n"
		"	}																		\n"
		;
}

const char* const kiwi::source::picker_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core									\n"
		"	layout (location = 0) in vec3 in_XYZ;				\n"
		"	uniform mat4 u_mvp_M;								\n"

		"	void main()											\n"
		"	{													\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ, 1.0);		\n"
		"	}													\n"
		;
}
const char* const kiwi::source::picker_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core									\n"
		"	layout (binding = 0) out uint entity_id;			\n"
		"	uniform uint u_entity_id;							\n"

		"	void main()											\n"
		"	{													\n"
		"		entity_id = u_entity_id;						\n"
		"	}													\n"
		;
}

const char* const kiwi::source::picker_XYZ_id_3d::vertex_shader() noexcept
{
	return

		"	#version 430 core														\n"
		"	layout (location = 0) in vec3 in_XYZ;									\n"
		"	struct t_XYZ_id { vec3 XYZ; uint id; };									\n"
		"	layout (std430, binding = 0) buffer s_XYZ_id { t_XYZ_id XYZ_id[]; };	\n"
		"	flat out uint _entity_id;												\n"
		"	uniform mat4 u_mvp_M;													\n"

		"	void main()																\n"
		"	{																		\n"
		"		gl_Position = u_mvp_M * vec4(in_XYZ									\n"
		"			+ XYZ_id[gl_InstanceID].XYZ, 1.0);								\n"

		"		_entity_id = XYZ_id[gl_InstanceID].id;								\n"
		"	}																		\n"
		;
}
const char* const kiwi::source::picker_XYZ_id_3d::fragment_shader() noexcept
{
	return

		"	#version 430 core														\n"
		"	flat in uint _entity_id;												\n"
		"	layout (binding = 0) out uint entity_id;								\n"

		"	void main()																\n"
		"	{																		\n"
		"		entity_id = _entity_id;												\n"
		"	}																		\n"
		;
}
