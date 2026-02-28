#pragma once

#include <algorithm>

namespace lunar::meta
{
	
template< size_t N >
struct String
{
	constexpr
	String( const char (&str)[ N ] )
	{
		std::copy_n( str, N, value );
	}

	char value[ N ];
};

}
