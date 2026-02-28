#pragma once

#include <cstddef>
#include <type_traits>

#include "extract_arguments.h"
#include "specializes_template.h"

namespace lunar::meta
{

template< typename... >
struct list;

template< typename First, typename... Rest >
struct list< First, Rest... >
{
	using head = First;
	using tail = list< Rest... >;

	static constexpr
	size_t size{ 1u + sizeof...( Rest ) };

	template< template< typename... >
			  typename Target
			>
	using forward_args = Target< First, Rest... >;

	template< typename T >
	static constexpr
	auto contains()
	  -> bool
	{
		return( std::is_same_v< T, First >
			 || ...
			 || list< Rest >::template contains< T >()
			  );
	}
};

template<>
struct list<>
{
	static constexpr
	size_t size = 0u;

	template< template< typename... >
			  typename Target
			>
	using forward_args = Target<>;

	template< typename T >
	static constexpr
	auto contains()
	  -> bool
	{
		return false;
	}
};

template< typename T, typename List >
concept Matching_Any = requires
{
	List::template contains< T >();
};

template< typename List >
concept List_Type = specialization_of_template< List, list >;


} // namespace lunar::meta
