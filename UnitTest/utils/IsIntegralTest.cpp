// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../../include/utils/IsIntegral.h"

#include <assert.h>
#include <iostream>
#include <iomanip>
#include <type_traits>
 
class A {};

enum B { a };
 
template <class T>
T f(T i)
{
    return i;
}
 
#define SHOW(...) std::cout << std::setw(39) << #__VA_ARGS__ << " == " << __VA_ARGS__ << '\n'
 
int main()
{
    assert( ft::is_integral< A >::value == std::is_integral< A >::value );
    assert( ft::is_integral< float >::value == std::is_integral< float >::value );
    assert( ft::is_integral< B >::value == std::is_integral< B >::value );
    assert( ft::is_integral< signed char >::value == std::is_integral< signed char >::value );
    assert( ft::is_integral< int >::value == std::is_integral< int >::value );
    assert( ft::is_integral< bool >::value == std::is_integral< bool >::value );

    std::cout << std::boolalpha;
    SHOW( ft::is_integral< A >::value );
    SHOW( ft::is_integral< float >::value );
    SHOW( ft::is_integral< B >::value );
    SHOW( ft::is_integral< signed char >::value );
    SHOW( ft::is_integral< int >::value );
    SHOW( ft::is_integral< bool >::value );
}
