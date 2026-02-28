#include <type_traits>

#include "gtest/gtest.h"

#include "meta/list.h"

using namespace lunar::meta;

TEST( list, size_returns_element_count )
{
	using List = list< float, bool, int, char >;
	ASSERT_EQ( List::size, 4u );
}

TEST( list, contains_checks_for_matching_element )
{
	using List = list< float, bool, int, char >;

	ASSERT_TRUE( List::contains< float >() );
	ASSERT_TRUE( List::contains< bool >() );
	ASSERT_TRUE( List::contains< int >() );
	ASSERT_TRUE( List::contains< char >() );

	ASSERT_FALSE( List::contains< char* >() );
}

TEST( list, empty_list_has_zero_size )
{
	ASSERT_EQ( list<>::size, 0u );
}

TEST( list, empty_list_contains_no_elements )
{
	ASSERT_FALSE( list<>::contains< float >() );
	ASSERT_FALSE( list<>::contains< int >() );
	ASSERT_FALSE( list<>::contains< bool >() );
}


TEST( list, head_returns_first_element )
{
	using List = list< float, bool, int >;
	ASSERT_TRUE( ( std::is_same_v< List::head, float > ) );
}

TEST( list, tail_returns_remaining_elements )
{
	using List = list< float, bool, int >;
	ASSERT_TRUE( ( std::is_same_v< List::tail, list< bool, int > > ) );
}

