#pragma once

namespace lunar::meta
{

template< auto F >
struct Lambda
{
	template< typename... Args >
	struct Eval
	{
		static constexpr
		auto value = F.template operator()< Args... >();

		using type = decltype( F.template operator()< Args... >() );
	};
};

} // namespace lunar::meta
