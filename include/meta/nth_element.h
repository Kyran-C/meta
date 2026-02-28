#pragma once
#include <cstddef>

#include "drop.h"

namespace lunar::meta
{

namespace impl
{

// fast tracking for single element indexing

template <typename T0,
		  typename... Ts>
struct get_0
{
    using type = T0;
};

template <typename T0, typename T1,
          typename... Ts>
struct get_1
{
    using type = T1;
};

template <typename T0, typename T1, typename T2,
          typename... Ts>
struct get_2
{
    using type = T2;
};

template <typename T0, typename T1, typename T2,  typename T3,
          typename... Ts>
struct get_3
{
    using type = T3;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,
          typename... Ts>
struct get_4
{
    using type = T4;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,
          typename... Ts>
struct get_5
{
    using type = T5;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,
          typename... Ts>
struct get_6
{
    using type = T6;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename... Ts>
struct get_7
{
    using type = T7;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, 
          typename... Ts>
struct get_8
{
    using type = T8;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9,
          typename... Ts>
struct get_9
{
    using type = T9;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9, typename T10,
          typename... Ts>
struct get_10
{
    using type = T10;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9, typename T10, typename T11,
          typename... Ts>
struct get_11 
{
    using type = T11;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9, typename T10, typename T11, typename T12,
          typename... Ts>
struct get_12 
{
    using type = T12;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9, typename T10, typename T11, typename T12, typename T13,
          typename... Ts>
struct get_13 
{
    using type = T13;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14,
          typename... Ts>
struct get_14 
{
    using type = T14;
};

template <typename T0, typename T1, typename T2,  typename T3,  typename T4,  typename T5,  typename T6,  typename T7, 
          typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
          typename... Ts>
struct get_15 
{
    using type = T15;
};

} // namespace impl

template< typename... Ts >
struct nth_element 
{
    template< size_t N >
    static constexpr auto impl()
    {
		using namespace impl;
        if constexpr( N >= 16u )
        {
			using tail_elements = drop_front_t< 16u, Ts... >;
			constexpr size_t remainder = N - 16u;
            return typename nth_element< tail_elements >
				 ::template type< remainder >{};
        }
        else if constexpr( N == 15u )
        {
            return typename get_15< Ts... >::type{};
        }
        else if constexpr( N == 14u )
        {
            return typename get_14< Ts... >::type{};
        }
        else if constexpr( N == 13u )
        {
            return typename get_13< Ts... >::type{};
        }
        else if constexpr( N == 12u )
        {
            return typename get_12< Ts... >::type{};
        }
        else if constexpr( N == 11u )
        {
            return typename get_11< Ts... >::type{};
        }
        else if constexpr( N == 10u )
        {
            return typename get_10< Ts... >::type{};
        }
        else if constexpr( N == 9u )
        {
            return typename get_9< Ts... >::type{};
        }
        else if constexpr( N == 8u )
        {
            return typename get_8< Ts... >::type{};
        }
        else if constexpr( N == 7u )
        {
            return typename get_7< Ts... >::type{};
        }
        else if constexpr( N == 6u )
        {
            return typename get_6< Ts... >::type{};
        }
        else if constexpr( N == 5u )
        {
            return typename get_5< Ts... >::type{};
        }
        else if constexpr( N == 4u )
        {
            return typename get_4< Ts... >::type{};
        }
        else if constexpr( N == 3u )
        {
            return typename get_3< Ts... >::type{};
        }
        else if constexpr( N == 2u )
        {
            return typename get_2< Ts... >::type{};
        }
        else if constexpr( N == 1u )
        {
            return typename get_1< Ts... >::type{};
        }
        else
        {
            return typename get_0< Ts... >::type{};
        }
    }

    template< size_t Nth >
    using type = decltype( impl< Nth >() );
};

template< typename First, typename... Rest >
struct nth_element< list< First, Rest... > >
{
    template< size_t Nth >
    using type = typename nth_element< First, Rest... >::template type< Nth >;

};

template< size_t N, typename... Ts >
using nth_element_t = typename nth_element< Ts... >::template type< N >;

} // namespace lunar::meta
