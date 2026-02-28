#pragma once

#include "list.h"
#include "concat.h"

namespace lunar::meta
{

/// Prepends the given arguments to the start of the type list.
template< List_Type List_T, typename... Args >
struct prepend
{
	using type = concat_t< list< Args... >, List_T  >;
};

/// Prepends the given arguments to the start of the type list.
template< List_Type List_T, typename... Args >
using prepend_t = typename prepend< List_T, Args... >::type;

} // namespace lunar::meta
