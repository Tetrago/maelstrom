#ifndef MAELSTROM_META_HPP
#define MAELSTROM_META_HPP

#include <cstddef>
#include <type_traits>

namespace ml
{
	namespace meta
	{
		//////////////
		//// if_t ////
		//////////////

		template <bool B, typename T = void>
		using if_t = typename std::enable_if<B, T>::type;

		/////////////
		//// ind ////
		/////////////

		using ind_t = std::size_t;

		template <ind_t... Is>
		struct ind
		{
			static ind_t size() noexcept { return sizeof...(Is); }
		};

		namespace detail
		{
			template <ind_t C, ind_t... Is>
			struct make_ind_impl : public make_ind_impl<C - 1, C - 1, Is...>
			{};

			template <ind_t... Is>
			struct make_ind_impl<0, Is...>
			{
				using type = ind<Is...>;
			};
		} // namespace detail

		template <ind_t C>
		using make_ind = typename detail::make_ind_impl<C>::type;
	} // namespace meta
} // namespace ml

#endif
