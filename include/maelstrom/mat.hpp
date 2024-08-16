#ifndef MAELSTROM_MAT_HPP
#define MAELSTROM_MAT_HPP

#include "matrix.hpp"

namespace ml
{
	using mat3f = Matrix<3, 3, float>;
	using mat4f = Matrix<4, 4, float>;

	using mat3d = Matrix<3, 3, double>;
	using mat4d = Matrix<4, 4, double>;

	using mat3l = Matrix<3, 3, long double>;
	using mat4l = Matrix<4, 4, long double>;

	using mat3 = mat3f;
	using mat4 = mat4f;
} // namespace ml

#endif
