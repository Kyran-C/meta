#pragma once

namespace lunar::meta
{

template< template< typename, typename... > typename F >
struct apply
{
	template< typename T >
	struct impl
	{
		using type = F< T >;
	};

	template< typename T >
	using type = typename impl< T >::type;
};

} // namespace lunar::meta
