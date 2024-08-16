#ifndef MAELSTROM_VECTOR_HPP
#define MAELSTROM_VECTOR_HPP

#include "base.hpp"
#include "math.hpp"
#include "meta.hpp"
#include "utility.hpp"

namespace ml
{
	//////////////////
	//// Internal ////
	//////////////////

	namespace internal
	{
		template <dim_t C, typename T>
		union Vector
		{
			T data[C];
		};

		template <typename T>
		union Vector<2, T>
		{
			struct
			{
				T x, y;
			};

			T data[2];
		};

		template <typename T>
		union Vector<3, T>
		{
			struct
			{
				T x, y, z;
			};

			struct
			{
				T r, g, b;
			};

			T data[3];
		};

		template <typename T>
		union Vector<4, T>
		{
			struct
			{
				T x, y, z, w;
			};

			struct
			{
				T r, g, b, a;
			};

			T data[4];
		};
	} // namespace internal

	////////////////
	//// Vector ////
	////////////////

	template <dim_t C, typename T>
	struct Vector
	{
		using value_type = T;

		enum
		{
			length = C
		};

		T& operator[](std::size_t i) noexcept { return container.data[i]; }

		const T& operator[](std::size_t i) const noexcept
		{
			return container.data[i];
		}

		Vector& operator+=(const Vector& other) noexcept;
		Vector& operator-=(const Vector& other) noexcept;
		Vector& operator*=(T value) noexcept;

		internal::Vector<C, T>* operator->() noexcept { return &container; }

		const internal::Vector<C, T>* operator->() const noexcept
		{
			return &container;
		}

		T mag() const noexcept;

		const T* data() const noexcept { return &container.data[0]; }

		internal::Vector<C, T> container;
	};

	///////////////////
	//// Operators ////
	///////////////////

	namespace detail
	{
		template <dim_t C, typename T, meta::ind_t... Is>
		Vector<C, T> add(const Vector<C, T>& lhs,
		                 const Vector<C, T>& rhs,
		                 meta::ind<Is...>)
		{
			return {(lhs[Is] + rhs[Is])...};
		}

		template <dim_t C, typename T, meta::ind_t... Is>
		Vector<C, T> sub(const Vector<C, T>& lhs,
		                 const Vector<C, T>& rhs,
		                 meta::ind<Is...>)
		{
			return {(lhs[Is] - rhs[Is])...};
		}

		template <dim_t C, typename T, meta::ind_t... Is>
		Vector<C, T> mul(const Vector<C, T>& lhs, T rhs, meta::ind<Is...>)
		{
			return {(lhs[Is] * rhs)...};
		}
	} // namespace detail

	template <dim_t C, typename T>
	Vector<C, T> operator+(const Vector<C, T>& lhs,
	                       const Vector<C, T>& rhs) noexcept
	{
		return detail::add(lhs, rhs, meta::make_ind<C>{});
	}

	template <dim_t C, typename T>
	Vector<C, T> operator-(const Vector<C, T>& lhs,
	                       const Vector<C, T>& rhs) noexcept
	{
		return detail::sub(lhs, rhs, meta::make_ind<C>{});
	}

	template <dim_t C, typename T>
	Vector<C, T> operator*(const Vector<C, T>& lhs, T rhs) noexcept
	{
		return detail::mul(lhs, rhs, meta::make_ind<C>{});
	}

	template <dim_t C, typename T>
	Vector<C, T> operator*(T lhs, const Vector<C, T>& rhs) noexcept
	{
		return rhs * lhs;
	}

	///////////////////
	//// Magnitude ////
	///////////////////

	namespace detail
	{
		template <dim_t C, typename T, meta::ind_t... Is>
		T mag_impl(const Vector<C, T>& v, meta::ind<Is...>)
		{
			return sqrt(sum({(v[Is] * v[Is])...}));
		}
	} // namespace detail

	template <dim_t C, typename T>
	T mag(const Vector<C, T>& v)
	{
		return detail::mag_impl(v, meta::make_ind<C>{});
	}

	/////////////
	//// Sum ////
	/////////////

	namespace detail
	{
		template <dim_t C, typename T, meta::ind_t... Is>
		T sum_impl(const Vector<C, T>& v, meta::ind<Is...>)
		{
			return sum({v[Is]...});
		}
	} // namespace detail

	template <dim_t C, typename T>
	T sum(const Vector<C, T>& v)
	{
		return detail::sum_impl(v, meta::make_ind<C>{});
	}

	//////////////////
	//// Products ////
	//////////////////

	namespace detail
	{
		template <dim_t C, typename T, meta::ind_t... Is>
		T dot_impl(const Vector<C, T>& a,
		           const Vector<C, T>& b,
		           meta::ind<Is...>)
		{
			return sum({(a[Is] * b[Is])...});
		}
	} // namespace detail

	template <dim_t C, typename T>
	T dot(const Vector<C, T>& a, const Vector<C, T>& b)
	{
		return detail::dot_impl(a, b, meta::make_ind<C>{});
	}

	template <typename T>
	T cross(const Vector<3, T>& a, const Vector<3, T>& b)
	{
		return {(a->y * b->z - a->z * b->y),
		        (a->z * b->x - a->x * b->z),
		        (a->x * b->y - a->y * b->x)};
	}

	/////////////////
	//// Methods ////
	/////////////////

	template <dim_t C, typename T>
	Vector<C, T>& Vector<C, T>::operator+=(const Vector<C, T>& other) noexcept
	{
		*this = *this + other;
	}

	template <dim_t C, typename T>
	Vector<C, T>& Vector<C, T>::operator-=(const Vector<C, T>& other) noexcept
	{
		*this = *this - other;
	}

	template <dim_t C, typename T>
	Vector<C, T>& Vector<C, T>::operator*=(T value) noexcept
	{
		*this = *this * value;
	}

	template <dim_t C, typename T>
	T Vector<C, T>::mag() const noexcept
	{
		return mag(*this);
	}
} // namespace ml

#endif
