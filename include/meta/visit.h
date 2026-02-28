#pragma once

#include <utility>

#include "list.h"

namespace lunar::meta
{
	

template< typename... Args >
struct visit_each
{
	template< typename F >
	static constexpr
	auto with( F&& f )
	{
		auto call = [&]< typename T >()
		{
			f.template operator()< T >();
			return false;
		};

		( void )
		( ( call.template operator()< Args >() || ... ) );
	}
};

template< typename... Args >
struct visit_each< list< Args... > > : visit_each< Args... >
{
};


template< typename... Args >
struct visit_nth
{
	template< typename F >
	static constexpr
	auto with( std::size_t nth, F&& f )
	{
		auto test_and_call = [&]< std::size_t N, typename T >()
		{
			if( N == nth )
			{
				f.template operator()< N, T >();
				return true;
			}
			else
			{
				return false;
			}
		};

		( void )
		[&]< std::size_t... N >( std::index_sequence< N... > )
		{
			( void )
			( test_and_call.template operator()< N, Args >() || ... );
		}
		( std::make_index_sequence< sizeof...( Args ) >() );
	}
};

template< typename... Args >
struct visit_nth< list< Args... > > : visit_nth< Args... >
{
};

template< typename... Args >
struct visit_each_indexed
{
	template< typename F >
	static constexpr
	auto with( F&& f )
	{
		auto call = [&]< std::size_t N, typename T >()
		{
			f.template operator()< N, T >();
			return false;
		};

		( void )
		[&]< std::size_t... N >( std::index_sequence< N... > )
		{
			( void )
			( call.template operator()< N, Args >() || ... );
		}
		( std::make_index_sequence< sizeof...( Args ) >() );
	}
};

template< typename... Args >
struct visit_each_indexed< list< Args... > > : visit_each_indexed< Args... >
{
};

}
