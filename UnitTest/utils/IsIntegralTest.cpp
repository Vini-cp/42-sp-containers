// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../../include/utils/IsIntegral.h"

#include <assert.h>
#include <iostream>
#include <iomanip>
 
class A {};

enum B { a };
 
template <class T>
T f(T i)
{
    return i;
}
 
#define SHOW(...) std::cout << std::setw(39) << #__VA_ARGS__ << " == " << __VA_ARGS__ << '\n'
 
void IsIntegralTests()
{
    std::cout << std::endl << "----------------- IsIntegral Test ----------------" << std::endl << std::endl;
    
    std::cout << std::boolalpha;
    SHOW( ft::is_integral< A >::value );
    SHOW( ft::is_integral< float >::value );
    SHOW( ft::is_integral< B >::value );
    SHOW( ft::is_integral< signed char >::value );
    SHOW( ft::is_integral< int >::value );
    SHOW( ft::is_integral< bool >::value );

    std::cout << std::endl << "--------------------------------------------------" << std::endl;
}
