#pragma once
#include "string.h"

namespace lunar::meta
{

template< typename, meta::String message >
constexpr
bool assertion_fail = false;

} // namespace lunar::meta
