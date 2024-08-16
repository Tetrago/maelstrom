#ifndef MAELSTROM_UTILITY_HPP
#define MAELSTROM_UTILITY_HPP

#include <initializer_list>

namespace ml
{
	template <typename T>
	T sum(std::initializer_list<T> list)
	{
		T acc = 0;
		for (T elem : list) acc += elem;
		return acc;
	}
} // namespace ml

#endif
