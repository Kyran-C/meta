#include "gtest/gtest.h"

#include "meta/string.h"
#include "meta/assertion_fail.h"

using namespace lunar::meta;

TEST( assertion_fail, type_dependent_failure )
{
	auto test =
	[]
	< typename Arg_T >
	( Arg_T&& arg )
	{
		if constexpr( std::is_same_v< Arg_T, int > )
			static_assert( assertion_fail< Arg_T, "Bad type!" > );

		return true;
	};

	ASSERT_TRUE( ( test( 3.14 ) ) );

	// This would trigger the static assertion fail
	// ASSERT_FALSE( ( test( 3 ) ) );
}

