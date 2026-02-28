#pragma once

#include "list.h"

namespace lunar::meta
{

template< template< typename... > typename F, typename... Args >
struct map
{
	static constexpr
	auto impl()
	{
		return list< typename F< Args >::type... >{};
	}

	using type = decltype( impl() );
};

template< template< typename... > typename F, typename... Args >
struct map< F, list< Args... > >
{
	using type = typename map< F, Args... >::type;
};

template< template< typename... > typename F, typename... Args >
using map_t = typename map< F, Args... >::type;

} // namespace lunar::meta
