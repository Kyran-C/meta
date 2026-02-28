#pragma once

#include "take.h"

namespace lunar::meta
{

template< size_t N, typename... Ts >
struct drop_last
{
    using type = typename take_front< sizeof...( Ts ) - N, Ts... >::type;
};


template< size_t N, typename... Ts >
struct drop_last< N, list< Ts... > >
{
    using type = typename drop_last< N, Ts... >::type;
};

template< size_t N, typename... Ts >
using drop_last_t = typename drop_last< N, Ts... >::type;

} // namespace lunar::meta

