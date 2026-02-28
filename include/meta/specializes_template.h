#pragma once

#include <type_traits>

namespace lunar::meta
{
	
template< typename T, template< typename... > typename Template >
struct is_specialization_of : std::false_type
{};

template< typename... Args, template< typename... > typename Template >
struct is_specialization_of< Template< Args... >, Template > : std::true_type
{};

template< typename T, template< typename... > typename Template >
inline constexpr
bool is_specialization_of_v = is_specialization_of< T, Template >::value;

template< typename T, template< typename... > typename Template >
concept specialization_of_template = requires
{
	is_specialization_of_v< T, Template >;
};

} // namespace lunar::meta
