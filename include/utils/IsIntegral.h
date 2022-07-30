// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef IS_INTEGRAL_H
#define IS_INTEGRAL_H

#include "RemoveCV.h"

namespace ft
{

/**
* 
*   Checks whether T is an integral type. Provides the member 
*       constant value which is equal to true, if T is the type
*       bool, char, char16_t, char32_t, wchar_t, short, int, long,
*       long long, or any implementation-defined extended integer types, 
*       including any signed, unsigned, and cv-qualified variants.
*       Otherwise, value is equal to false.
*
*/

template< typename T, T v >
struct integral_constant
{
    static const T value = v;
    typedef T value_type;
    typedef integral_constant< T, v > type;
    operator value_type() const { return value; }
};

typedef integral_constant< bool, true > true_type;
typedef integral_constant< bool, false > false_type;

/*
*   @param T     A type to check.
*/
template< typename T >
struct is_integral : public false_type {};

template<>
struct is_integral< bool > : public true_type {};
    
template<>
struct is_integral< char > : public true_type {};

template<>
struct is_integral< unsigned char > : public true_type {};

template<>
struct is_integral< signed char > : public true_type {};

template<>
struct is_integral< short > : public true_type {};

template<>
struct is_integral< unsigned short > : public true_type {};

template<>
struct is_integral< int > : public true_type {};

template<>
struct is_integral< unsigned int > : public true_type {};

template<>
struct is_integral< long > : public true_type {};

template<>
struct is_integral< unsigned long > : public true_type {};

template<>
struct is_integral< long long > : public true_type {};

template<>
struct is_integral< unsigned long long > : public true_type {};

} // ft

#endif
