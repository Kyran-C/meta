#pragma once

namespace lunar::meta
{

template< auto val >
struct fold_init
{
	static constexpr auto _val{ val };
};

template< template< typename, typename > typename F, typename T >
struct fold_state
{
	/* template< typename T > */
	/* struct fold_accumulator */
	/* { */
	/* }; */

	using type = T;

	struct fold_operation
	{
		template< typename Arg1_T, typename Arg2_T >
		static constexpr
		auto operate()
		  -> auto
		{
			return fold_state< F, typename F< Arg1_T, Arg2_T >::type >{};
		};

		template< typename Arg1_T, typename Arg2_T >
		using type = decltype( operate< Arg1_T, Arg2_T >() );
	};

};

template< typename T >
struct fold_wrap
{
	using type = T;
};

/* template< template< typename, typename > typename F, typename A > */
/* using fold_accum = typename fold_state< F, A >::type; */

template< template< typename, typename > typename F, typename A, typename B >
auto operator <<( fold_state< F, A > a, fold_wrap< B >&& b )
{
	using Accum_T = typename decltype( a )::type;
	using Operation_T = typename fold_state< F, A >::fold_operation;
	using Result_T = typename Operation_T::template type< Accum_T, B >;
	return Result_T{};
}

template< template< typename, typename > typename F, typename init, typename... args >
struct fold
{
	static constexpr
	auto impl()
	  -> auto
	{
		using fold_init = fold_state< F, init >;
		return( fold_init{} << ... << fold_wrap< args >{} );
	}

	using type = typename decltype( impl() )::type;
};

template< template< typename, typename > typename F, typename init, typename... args >
struct fold< F, init, list< args... > >
{
	using type = typename fold< F, init, args... >::type;
};

template< template< typename, typename > typename F, typename init, typename... args >
using fold_t = typename fold< F, init, args... >::type;

} // namespace lunar::meta
