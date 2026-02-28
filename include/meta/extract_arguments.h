#pragma once

namespace lunar::meta
{

template< typename >
struct extract_arguments
{};

/// Extract the template arguments from one type and forward them to another template.
template< template< typename... >
		  typename Source
		, typename... Source_Args
		>
struct extract_arguments< Source< Source_Args... > >
{

	/// Inserts the source arguments into the given template.
    template< template< typename... >
			  typename Target
			>
    using into = Target< Source_Args... >;


	/// Inserts the source arguments into the given template at the head,
	/// with the supplied trailing args inserted after.
    template< template< typename... >
			  typename Target
			, typename... Trailing_Args
			>
    using into_head = Target<  Source_Args..., Trailing_Args... >;


	/// Inserts the source arguments into the given template at the tail,
	/// after the supplied leading args.
    template< template< typename... >
			  typename Target
			, typename... Leading_Args
			>
    using into_tail = Target< Leading_Args..., Source_Args... >;
};

template< typename Source,
		  template< typename... >
		  typename Target
		>
using extract_arguments_into_t = typename extract_arguments< Source >::
								 template into< Target >;

} // namespace lunar::meta
