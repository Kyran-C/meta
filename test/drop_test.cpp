#include <type_traits>

#include "gtest/gtest.h"

#include "meta/list.h"
#include "meta/drop.h"

using namespace lunar::meta;

TEST( drop, zero_elements_leaves_list_unchanged )
{
	using List = list< int, bool, float >;
	using Result = drop_front_t< 0, List >;

	ASSERT_TRUE( ( std::is_same_v< Result, List > ) );
}

TEST( drop, one_element )
{
	using List = list< int, bool, float >;
	using Result = drop_front_t< 1, List >;

	ASSERT_TRUE( ( std::is_same_v< Result, list< bool, float > > ) );
}

TEST( drop, dropping_entire_list_returns_empty_list )
{
	using List = list< int, bool, float >;
	using Result = drop_front_t< 3, List >;

	ASSERT_TRUE( ( std::is_same_v< Result, list<> > ) );
}

TEST( drop, drop_pack )
{
	using Result = drop_front_pack_t< 1, int, bool, float >;

	ASSERT_TRUE( ( std::is_same_v< Result, list< bool, float > > ) );
}
