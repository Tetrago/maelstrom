#ifndef MAELSTROM_MATH_HPP
#define MAELSTROM_MATH_HPP

#include <cmath>

namespace ml
{
	///////////////////
	//// Constants ////
	///////////////////

	template <typename T>
	struct Constants
	{
		static constexpr T PI = 3.141592653589793238462643383279502884e+00;
	};

	////////////////
	//// Angles ////
	////////////////

	template <typename T>
	T rad(T deg)
	{
		return deg * Constants<T>::PI / 180.0;
	}

	template <typename T>
	T deg(T rad)
	{
		return rad * 180.0 / Constants<T>::PI;
	}

	/////////////////////
	//// Square Root ////
	/////////////////////

	template <typename T>
	T sqrt(T value)
	{
		return std::sqrt(value);
	}

	template <>
	inline long double sqrt<long double>(long double value)
	{
#if __GNUC__
		return sqrtl(value);
#else
		return std::sqrtl(value);
#endif
	}

	template <>
	inline float sqrt<float>(float value)
	{
#if __GNUC__
		return sqrtf(value);
#else
		return std::sqrtf(value);
#endif
	}

	//////////////
	//// Sine ////
	//////////////

	template <typename T>
	T sin(T value)
	{
		return std::sin(value);
	}

	template <>
	inline long double sin<long double>(long double value)
	{
#if __GNUC__
		return sinl(value);
#else
		return std::sinl(value);
#endif
	}

	template <>
	inline float sin<float>(float value)
	{
#if __GNUC__
		return sinf(value);
#else
		return std::sinf(value);
#endif
	}

	////////////////
	//// Cosine ////
	////////////////

	template <typename T>
	T cos(T value)
	{
		return std::cos(value);
	}

	template <>
	inline long double cos<long double>(long double value)
	{
#if __GNUC__
		return cosl(value);
#else
		return std::cosl(value);
#endif
	}

	template <>
	inline float cos<float>(float value)
	{
#if __GNUC__
		return cosf(value);
#else
		return std::cosf(value);
#endif
	}

	/////////////////
	//// Tangent ////
	/////////////////

	template <typename T>
	T tan(T value)
	{
		return std::tan(value);
	}

	template <>
	inline long double tan<long double>(long double value)
	{
#if __GNUC__
		return tanl(value);
#else
		return std::tanl(value);
#endif
	}

	template <>
	inline float tan<float>(float value)
	{
#if __GNUC__
		return tanf(value);
#else
		return std::tanf(value);
#endif
	}
} // namespace ml

#endif
