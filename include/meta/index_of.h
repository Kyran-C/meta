#pragma once

#include <type_traits>

#include "list.h"
#include "assertion_fail.h"

namespace lunar::meta
{

namespace impl
{

template< typename >
struct index_if;

template< typename T0, typename T1, typename T2, typename T3
		, typename T4, typename T5, typename T6, typename T7
		, typename... Rest >
struct index_if< list< T0, T1, T2, T3, T4, T5, T6, T7, Rest... > >
{
	template< typename F >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( F::template value< T0 > )
		{
			return 0;
		}
		else if constexpr( F::template value< T1 > )
		{
			return 1;
		}
		else if constexpr( F::template value< T2 > )
		{
			return 2;
		}
		else if constexpr( F::template value< T3 > )
		{
			return 3;
		}
		else if constexpr( F::template value< T4 > )
		{
			return 4;
		}
		else if constexpr( F::template value< T5 > )
		{
			return 5;
		}
		else if constexpr( F::template value< T6 > )
		{
			return 6;
		}
		else if constexpr( F::template value< T7 > )
		{
			return 7;
		}
		else
		{
			return 8 + index_if< list< Rest... > >::template value< F >;
		}
	}

	template< typename F >
	static constexpr
	size_t value = impl< F >();
};

template< typename T0, typename T1, typename T2, typename T3
		, typename... Rest >
struct index_if< list< T0, T1, T2, T3, Rest... > >
{
	template< typename F >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( F::template value< T0 > )
		{
			return 0;
		}
		else if constexpr( F::template value< T1 > )
		{
			return 1;
		}
		else if constexpr( F::template value< T2 > )
		{
			return 2;
		}
		else if constexpr( F::template value< T3 > )
		{
			return 3;;
		}
		else
		{
			return 4 + index_if< list< Rest... > >::template value< F >;
		}
	}

	template< typename F >
	static constexpr
	size_t value = impl< F >();
};

template< typename T0, typename T1
		, typename... Rest >
struct index_if< list< T0, T1, Rest... > >
{
	template< typename F >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( F::template value< T0 > )
		{
			return 0;
		}
		else if constexpr( F::template value< T1 > )
		{
			return 1;
		}
		else
		{
			return 2 + index_if< list< Rest... > >::template value< F >;
		}
	}

	template< typename F >
	static constexpr
	size_t value = impl< F >();
};

template< typename T0
		, typename... Rest >
struct index_if< list< T0, Rest... > >
{
	template< typename F >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( F::template value< T0 > )
		{
			return 0;
		}
		else
		{
			return 1 + index_if< list< Rest... > >::template value< F >;
		}
	}

	template< typename F >
	static constexpr
	size_t value = impl< F >();
};

template<>
struct index_if< list<> >
{
	template< typename F >
	static constexpr
	auto impl()
	{
		assertion_fail< F, "Type was not found in type list." >;
	}

	template< typename F >
	static constexpr
	size_t value = impl< F >();
};

} // namespace impl



template< typename >
struct index_if{};

template< typename... Args >
struct index_if< list< Args... > >
{
	template< typename F >
	static constexpr
	size_t value = impl::index_if< list< Args... > >::template value< F >;
};







namespace impl
{
template< typename >
struct index_of;

template< typename T0, typename T1, typename T2, typename T3
		, typename T4, typename T5, typename T6, typename T7
		, typename... Rest >
struct index_of< list< T0, T1, T2, T3, T4, T5, T6, T7, Rest... > >
{
	template< typename T >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( std::is_same_v< T, T0 > )
		{
			return 0;
		}
		else if constexpr( std::is_same_v< T, T1 > )
		{
			return 1;
		}
		else if constexpr( std::is_same_v< T, T2 > )
		{
			return 2;
		}
		else if constexpr( std::is_same_v< T, T3 > )
		{
			return 3;
		}
		else if constexpr( std::is_same_v< T, T4 > )
		{
			return 4;
		}
		else if constexpr( std::is_same_v< T, T5 > )
		{
			return 5;
		}
		else if constexpr( std::is_same_v< T, T6 > )
		{
			return 6;
		}
		else if constexpr( std::is_same_v< T, T7 > )
		{
			return 7;
		}
		else
		{
			return 8 + index_of< list< Rest... > >::template value< T >;
		}
	}

	template< typename T >
	static constexpr
	size_t value = impl< T >();
};

template< typename T0, typename T1, typename T2, typename T3
		, typename... Rest >
struct index_of< list< T0, T1, T2, T3, Rest... > >
{
	template< typename T >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( std::is_same_v< T, T0 > )
		{
			return 0;
		}
		else if constexpr( std::is_same_v< T, T1 > )
		{
			return 1;
		}
		else if constexpr( std::is_same_v< T, T2 > )
		{
			return 2;
		}
		else if constexpr( std::is_same_v< T, T3 > )
		{
			return 3;
		}
		else
		{
			return 4 + index_of< list< Rest... > >::template value< T >;
		}
	}

	template< typename T >
	static constexpr
	size_t value = impl< T >();
};

template< typename T0, typename T1
		, typename... Rest >
struct index_of< list< T0, T1, Rest... > >
{
	template< typename T >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( std::is_same_v< T, T0 > )
		{
			return 0;
		}
		else if constexpr( std::is_same_v< T, T1 > )
		{
			return 1;
		}
		else
		{
			return 2 + index_of< list< Rest... > >::template value< T >;
		}
	}

	template< typename T >
	static constexpr
	size_t value = impl< T >();
};

template< typename T0
		, typename... Rest >
struct index_of< list< T0, Rest... > >
{
	template< typename T >
	static constexpr
	auto impl()
	{
		using std::is_same_v;

		if constexpr( std::is_same_v< T, T0 > )
		{
			return 0;
		}
		else
		{
			return 1 + index_of< list< Rest... > >::template value< T >;
		}
	}

	template< typename T >
	static constexpr
	size_t value = impl< T >();
};

template<>
struct index_of< list<> >
{
	template< typename T >
	static constexpr
	auto impl()
	{
		assertion_fail< T, "Type was not found in type list." >;
	}

	template< typename T >
	static constexpr
	size_t value = impl< T >();
};

}

template< typename >
struct index_of;

template< typename... Args >
struct index_of< list< Args... > >
{
	template< typename T >
	static constexpr
	size_t value = impl::index_of< list< Args... > >::template value< T >;
};


// can do index_if with several options for predicate:
// constexpr lambda
// type based metafunction
// concepts




} // namespace lunar::meta
