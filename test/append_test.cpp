#include "gtest/gtest.h"

#include "meta/list.h"
#include "meta/append.h"

using namespace lunar::meta;

TEST( append, appending_zero_elements_leaves_list_unchanged )
{
	using List = list< int, bool >;
	using Result = append_t< List >;
	ASSERT_TRUE( ( std::is_same_v< Result, List > ) );
}

TEST( append, single_element )
{
	using List = list< int, bool >;
	using Result = append_t< List, float >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< int, bool, float > > ) );
}

TEST( append, multiple_elements )
{
	using List = list< int, bool >;
	using Result = append_t< List, float, char >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< int, bool, float, char > > ) );
}

TEST( append, single_element_to_empty_list )
{
	using List = list<>;
	using Result = append_t< List, float >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< float > > ) );
}

TEST( append, multiple_elements_to_empty_list )
{
	using List = list<>;
	using Result = append_t< List, float, char >;
	ASSERT_TRUE( ( std::is_same_v< Result, list< float, char > > ) );
}
