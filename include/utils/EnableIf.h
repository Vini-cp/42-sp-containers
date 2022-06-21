// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef ENABLE_IF_H
#define ENABLE_IF_H

namespace ft
{

    /* 
    *  
    *   If B is true, ft::enable_if has a public member typedef type, equal to T;
    *       otherwise, there is no member typedef.
    *
    *   This metafunction is a convenient way to leverage SFINAE
    *       ( Substitution Failure Is Not An Error )
    *       prior to C++20's concepts, in particular for conditionally removing
    *       functions from the candidate set based on type traits, allowing separate
    *       function overloads or specializations based on those different type traits.
    * 
    */

/*
*   @param Cond   A compile-time constant of type bool.
*   @param T      A type.
*/
template< bool Cond, class T = void >
struct enable_if {};

template< class T >
struct enable_if< true, T > { typedef T type; };

}

#endif
