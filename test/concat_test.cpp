#include "gtest/gtest.h"

#include "meta/string.h"
#include "meta/concat.h"

using namespace lunar::meta;

TEST( concat, two_empty_lists_produces_empty_list )
{
	using List_1 = list<>;
	using List_2 = list<>;
	using Result = concat_t< List_1, List_2 >;

	ASSERT_TRUE( ( std::is_same_v< Result, list<> > ) );
}

TEST( concat, empty_rhs_produces_lhs )
{
	using List_1 = list< int, bool >;
	using List_2 = list<>;
	using Result = concat_t< List_1, List_2 >;

	ASSERT_TRUE( ( std::is_same_v< Result, List_1 > ) );
}

TEST( concat, empty_lhs_produces_rhs )
{
	using List_1 = list<>;
	using List_2 = list< int, bool >;
	using Result = concat_t< List_1, List_2 >;

	ASSERT_TRUE( ( std::is_same_v< Result, List_2 > ) );
}

TEST( concat, two_lists )
{
	using List_1 = list< int, bool >;
	using List_2 = list< float, char >;
	using Result = concat_t< List_1, List_2 >;

	ASSERT_TRUE( ( std::is_same_v< Result, list< int, bool, float, char > > ) );
}

TEST( concat, three_lists )
{
	using List_1 = list< int >;
	using List_2 = list< bool >;
	using List_3 = list< float, char >;
	using Result = concat_t< List_1, List_2, List_3 >;

	ASSERT_TRUE( ( std::is_same_v< Result, list< int, bool, float, char > > ) );
}

TEST( concat, four_lists )
{
	using List_1 = list< int >;
	using List_2 = list< bool >;
	using List_3 = list< float >;
	using List_4 = list< char >;
	using Result = concat_t< List_1, List_2, List_3, List_4 >;

	ASSERT_TRUE( ( std::is_same_v< Result, list< int, bool, float, char > > ) );
}

