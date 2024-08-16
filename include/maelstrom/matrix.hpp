#ifndef MAELSTROM_MATRIX_HPP
#define MAELSTROM_MATRIX_HPP

#include "base.hpp"

namespace ml
{
	//////////////////
	//// Internal ////
	//////////////////

	namespace internal
	{
		template <dim_t R, dim_t C, typename T>
		union Matrix
		{
			T m[R][C];
			T data[R * C];
		};
	} // namespace internal

	////////////////
	//// Matrix ////
	////////////////

	template <dim_t R, dim_t C, typename T>
	struct Matrix
	{
		using value_type = T;

		enum
		{
			rows    = R,
			columns = C
		};

		internal::Matrix<R, C, T>* operator->() noexcept { return &container; }

		const internal::Matrix<R, C, T>* operator->() const noexcept
		{
			return &container;
		}

		const T* data() const noexcept { return &container.data[0]; }

		internal::Matrix<R, C, T> container;
	};

	///////////////////
	//// Operators ////
	///////////////////
} // namespace ml

#endif
