#pragma once

#include "list.h"
#include "concat.h"

namespace lunar::meta
{

/// Appends the given arguments to the end of the type list.
template< List_Type List_T, typename... Args >
struct append
{
	using type = concat_t< List_T, list< Args... > >;
};

/// Appends the given arguments to the end of the type list.
template< List_Type List_T, typename... Args >
using append_t = typename append< List_T, Args... >::type;

} // namespace lunar::meta
