// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../../include/utils/LexicographicalCompare.h"

#include <assert.h>
#include <iostream>
#include <vector>

static void LexicographicalCompareTest();
static void LexicographicalCompareWithCompTest();

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& prVector )
{
    os << "{ ";

    for ( typename std::vector< T >::const_iterator it = prVector.begin(); it != prVector.end(); ++it )
    {
        os << *it << " ";
    }

    os << "}";
    
    return os;
}

bool CompareFunction( int a, int b )
{
    return a > b;
}

void LexicographicalCompareTests()
{
    std::cout << std::endl << "---------- Lexicographical Compare Test ----------" << std::endl << std::endl;

    LexicographicalCompareTest();
    LexicographicalCompareWithCompTest();

    std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;
}

static void LexicographicalCompareTest()
{
    std::cout << "---------- Lexicographical Compare Test ----------" << std::endl;

    std::vector< int > v1 ( 3, 5 );
    std::vector< int > v2 ( 3, 5 );
    std::vector< int > v3 ( 3, 7 );
    std::vector< int > v4 ( 3, 9 );
    std::vector< int > v5 ( 4, 5 );

    std::cout << "(1) v1: " << v1 << std::endl;
    std::cout << "(2) v2: " << v2 << std::endl;
    std::cout << "(3) v3: " << v3 << std::endl;
    std::cout << "(4) v4: " << v4 << std::endl;
    std::cout << "(5) v5: " << v5 << std::endl;

    std::cout << std::boolalpha;
    std::cout << "(6) LexiCompare v1, v2: " 
              << ft::lexicographical_compare( v1.begin(), v1.end(), v2.begin(), v2.end() ) << std::endl;
    std::cout << "(7) LexiCompare v1, v3: " 
              << ft::lexicographical_compare( v1.begin(), v1.end(), v3.begin(), v3.end() ) << std::endl;
    std::cout << "(8) LexiCompare v1, v6: " 
              << ft::lexicographical_compare( v1.begin(), v1.end(), v5.begin(), v5.end() ) << std::endl;

    assert( ft::lexicographical_compare( v1.begin(), v1.end(), v2.begin(), v2.end() ) ==
            std::lexicographical_compare( v1.begin(), v1.end(), v2.begin(), v2.end() ) );
    assert( ft::lexicographical_compare( v1.begin(), v1.end(), v3.begin(), v3.end() ) ==
            std::lexicographical_compare( v1.begin(), v1.end(), v3.begin(), v3.end() ) );
    assert( ft::lexicographical_compare( v2.begin(), v2.end(), v4.begin(), v4.end() ) ==
            std::lexicographical_compare( v2.begin(), v2.end(), v4.begin(), v4.end() ) );
        
 
    std::cout << "--------------------------------------------------" << std::endl;
}

static void LexicographicalCompareWithCompTest()
{
    std::cout << "--- Lexicographical Compare With Function Test ---" << std::endl;

    std::vector< int > v1 ( 3, 5 );
    std::vector< int > v2 ( 3, 5 );
    std::vector< int > v3 ( 3, 7 );
    std::vector< int > v4 ( 3, 9 );
    std::vector< int > v5 ( 4, 5 );

    std::cout << "(1) v1: " << v1 << std::endl;
    std::cout << "(2) v2: " << v2 << std::endl;
    std::cout << "(3) v3: " << v3 << std::endl;
    std::cout << "(4) v4: " << v4 << std::endl;
    std::cout << "(5) v5: " << v5 << std::endl;

    std::cout << std::boolalpha;
    std::cout << "(6) LexiCompare v1, v2: " 
              << ft::lexicographical_compare( v1.begin(), v1.end(), v2.begin(), v2.end(), CompareFunction ) << std::endl;
    std::cout << "(7) LexiCompare v1, v3: " 
              << ft::lexicographical_compare( v1.begin(), v1.end(), v3.begin(), v3.end(), CompareFunction ) << std::endl;
    std::cout << "(8) LexiCompare v1, v6: " 
              << ft::lexicographical_compare( v1.begin(), v1.end(), v5.begin(), v5.end(), CompareFunction ) << std::endl;

    assert( ft::lexicographical_compare( v1.begin(), v1.end(), v2.begin(), v2.end(), CompareFunction ) ==
            std::lexicographical_compare( v1.begin(), v1.end(), v2.begin(), v2.end(), CompareFunction ) );
    assert( ft::lexicographical_compare( v1.begin(), v1.end(), v3.begin(), v3.end(), CompareFunction ) ==
            std::lexicographical_compare( v1.begin(), v1.end(), v3.begin(), v3.end(), CompareFunction ) );
    assert( ft::lexicographical_compare( v2.begin(), v2.end(), v4.begin(), v4.end(), CompareFunction ) ==
            std::lexicographical_compare( v2.begin(), v2.end(), v4.begin(), v4.end(), CompareFunction ) );
        
 
    std::cout << "--------------------------------------------------" << std::endl;
}
