#ifndef MAELSTROM_VEC_HPP
#define MAELSTROM_VEC_HPP

#include "vector.hpp"

namespace ml
{
	using vec2f = Vector<2, float>;
	using vec3f = Vector<3, float>;
	using vec4f = Vector<4, float>;

	using vec2d = Vector<2, double>;
	using vec3d = Vector<3, double>;
	using vec4d = Vector<4, double>;

	using vec2l = Vector<2, long double>;
	using vec3l = Vector<3, long double>;
	using vec4l = Vector<4, long double>;

	using vec2 = vec2f;
	using vec3 = vec3f;
	using vec4 = vec4f;
} // namespace ml

#endif
