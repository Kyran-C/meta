#include "gtest/gtest.h"

#include "meta/list.h"
#include "meta/prepend.h"

using namespace lunar::meta;

TEST( prepend, prepending_zero_elements_leaves_list_unchanged )
{
	using List = list< int, bool >;
	using Result = prepend_t< List >;
	ASSERT_TRUE( ( std::is_same_v< Result, List > ) );
}

TEST( prepend, single_element )
{
	using List = list< int, bool >;
	using Result = prepend_t< List, float >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< float, int, bool > > ) );
}

TEST( prepend, multiple_elements )
{
	using List = list< int, bool >;
	using Result = prepend_t< List, float, char >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< float, char, int, bool > > ) );
}

TEST( prepend, single_element_to_empty_list )
{
	using List = list<>;
	using Result = prepend_t< List, float >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< float > > ) );
}

TEST( prepend, multiple_elements_to_empty_list )
{
	using List = list<>;
	using Result = prepend_t< List, float, char >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< float, char > > ) );
}
