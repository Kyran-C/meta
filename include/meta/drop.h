#pragma once

#include "list.h"
#include "extract_arguments.h"

namespace lunar::meta
{

namespace impl
{

// fast tracking
//
template< typename, typename, typename, typename, typename, typename, typename, typename,
		  typename, typename, typename, typename, typename, typename, typename, typename,
		  typename... Ts >
struct drop_sixteen
{
	using type = list< Ts... >;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = Target_Container< Ts... >;
};

template< typename, typename, typename, typename, typename, typename, typename, typename, 
		  typename... Ts >
struct drop_eight
{
	using type = list< Ts... >;
	
	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = Target_Container< Ts... >;
};

template< typename, typename, typename, typename, 
		  typename... Ts >
struct drop_four
{
	using type = list< Ts... >;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = Target_Container< Ts... >;
};

template< typename, typename, 
		  typename... Ts >
struct drop_two
{
	using type = list< Ts... >;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = Target_Container< Ts... >;
};

template< typename, 
		  typename... Ts >
struct drop_one
{
	using type = list< Ts... >;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = Target_Container< Ts... >;
};

template< typename... Ts >
struct drop_none
{
	using type = list< Ts... >;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = Target_Container< Ts... >;
};

}


/// Drop the first N elements from the given list and return the remainder.
///
template< size_t, typename List_T >
struct drop_front;

template< size_t N, typename... Ts >
struct drop_front< N, list< Ts... > >
{
	static constexpr
	auto impl()
	{
		using namespace impl;

		if constexpr( N >= 16u )
			return drop_front< N - 16, typename drop_sixteen< Ts... >::type >::impl();
		else if constexpr( N >= 8u )
			return drop_front< N - 8,  typename drop_eight< Ts... >::type >::impl();
		else if constexpr( N >= 4u )
			return drop_front< N - 4,  typename drop_four< Ts... >::type >::impl();
		else if constexpr( N >= 2u )
			return drop_front< N - 2,  typename drop_two< Ts... >::type >::impl();
		else if constexpr( N == 1u )
			return drop_front< 0u,	 typename drop_one< Ts... >::type >::impl();
		else
			return drop_none< Ts... >{};
	}

	using type = typename decltype( impl() )::type;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = typename extract_arguments< type >
						   ::template into< Target_Container >;
};

template< size_t N, typename List >
using drop_front_t = typename drop_front< N, List >::type;



/// Drop the first N elements from the given pack and return the remainder.
///
template< size_t N, typename... Ts >
struct drop_front_pack
{
	using type = drop_front_t< N, list< Ts... > >;

	template< template< typename... >
			  typename Target_Container
			>
	using and_deposit_into = typename extract_arguments< type >
						   ::template into< Target_Container >;
};

template< size_t N, typename... Ts >
using drop_front_pack_t = typename drop_front_pack< N, Ts... >::type;


} // namespace lunar::meta
