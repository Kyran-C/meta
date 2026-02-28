#pragma once

#include "list.h"

namespace lunar::meta
{

template< typename... Ts >
struct concat
{
	using type = list< Ts... >;
};

template< typename... Ts >
struct concat< list< Ts... > >
{
    using type = list< Ts... >;
};

template< typename... Ts, typename... Us >
struct concat< list< Ts... >, list< Us... > >
{
    using type = list< Ts..., Us... >;
};

template< typename... Ts, typename... Us, typename... Vs, typename... Rest >
struct concat< list< Ts... >, list< Us... >, list< Vs... >, Rest... >
{
	using type = typename concat< typename concat< list< Ts... >, list< Us... > >::type
								, typename concat< list< Vs... >,     Rest...   >::type
								>::type;
};

template< typename T, typename... Us >
using concat_t = typename concat< T, Us... >::type;


} // namespace lunar::meta
