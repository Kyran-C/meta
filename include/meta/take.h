#pragma once

#include "drop.h"
#include "extract_elements.h"
#include "concat.h"

namespace lunar::meta
{

namespace impl
{

template< typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
		  typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
		  typename... Ts >
struct take_sixteen
{
	using type = list< T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15 >;
};

template< typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
		  typename... Ts >
struct take_eight
{
	using type = list< T0, T1, T2, T3, T4, T5, T6, T7 >;
	
	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2, T3, T4, T5, T6, T7 >;
};

template< typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
		  typename... Ts >
struct take_seven
{
	using type = list< T0, T1, T2, T3, T4, T5, T6 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2, T3, T4, T5, T6 >;
};

template< typename T0, typename T1, typename T2, typename T3, typename T4, typename T5,
		  typename... Ts >
struct take_six
{
	using type = list< T0, T1, T2, T3, T4, T5 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2, T3, T4, T5 >;
};

template< typename T0, typename T1, typename T2, typename T3, typename T4,
		  typename... Ts >
struct take_five
{
	using type = list< T0, T1, T2, T3, T4 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2, T3, T4 >;
};

template< typename T0, typename T1, typename T2, typename T3,
		  typename... Ts >
struct take_four
{
	using type = list< T0, T1, T2, T3 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2, T3 >;
};

template< typename T0, typename T1, typename T2,
		  typename... Ts >
struct take_three
{
	using type = list< T0, T1, T2 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1, T2 >;
};

template< typename T0, typename T1,
		  typename... Ts >
struct take_two
{
	using type = list< T0, T1 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T0, T1 >;
};

template< typename T1, 
		  typename... Ts >
struct take_one
{
	using type = list< T1 >;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container< T1 >;
};

template< typename... Ts >
struct take_none
{
	using type = list<>;

	template< template< typename... > typename New_Container >
	using and_deposit_into = New_Container<>;
};

} // namespace impl

// Take front 
// <N, list> -> list
//
template< size_t, typename >
struct take_front_list;

template< size_t N, typename... Ts >
struct take_front_list< N, list< Ts... > >
{
	static constexpr auto impl()
	{
		using namespace impl;
		if constexpr( N >= 16u )
		{
			using first_sixteen = typename take_sixteen< Ts... >::type;

			constexpr size_t remainder = N - 16u;
			using tail = drop_front_t< 16u, Ts... >;
			using rest = typename take_front_list< remainder, tail >::type;

			return concat_t< first_sixteen, rest >{};
		}
		else if constexpr( N > 8u )
		{
			using first_eight = typename take_eight< Ts... >::type;

			constexpr size_t remainder = N - 8u;
			using tail = drop_front_t< 8u, Ts... >;
			using rest = typename take_front_list< remainder, tail >::type;

			return concat_t< first_eight, rest >{};
		}
		else if constexpr( N == 8u )
		{
			return typename take_eight< Ts... >::type{};
		}
		else if constexpr( N == 7u )
		{
			return typename take_seven< Ts... >::type{};
		}
		else if constexpr( N == 6u )
		{
			return typename take_six< Ts... >::type{};
		}
		else if constexpr( N == 5u )
		{
			return typename take_five< Ts... >::type{};
		}
		else if constexpr( N == 4u )
		{
			return typename take_four< Ts... >::type{};
		}
		else if constexpr( N == 3u )
		{
			return typename take_three< Ts... >::type{};
		}
		else if constexpr( N == 2u )
		{
			return typename take_two< Ts... >::type{};
		}
		else if constexpr( N == 1u )
		{
			return typename take_one< Ts... >::type{};
		}
		else
		{
			return typename take_none<>::type{};
		}
	}

	using type = decltype( impl() );

	template< template< typename... > typename New_Container >
	using and_deposit_into = typename extract_elements< type >
						   ::template into< New_Container >::type;
};

template< size_t N, typename... Ts >
using take_front_list_t = typename take_front_list< N, Ts... >::type;

// Take front
// <N, Args...> -> list
//
template< size_t N, typename... Ts >
struct take_front
{
	using impl = take_front_list< N, list< Ts... > >;
	using type = typename impl::type;

	template< template< typename... > typename New_Container >
	using and_deposit_into = typename take_front_list< N, list< Ts... > >
						   ::template and_deposit_into< New_Container >;
};

template< size_t N, typename... Ts >
using take_front_t = typename take_front< N, Ts... >::type;


} // namespace lunar::meta
