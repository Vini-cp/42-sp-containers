// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../../include/utils/Pair.h"

#include <assert.h>
#include <iostream>

static void ConstructorTest();
static void OperatorEqualTest();
static void MakePairTest();
static void OperatorCompareTest();

template < class T, class U >
std::ostream& operator<<( std::ostream& os, const ft::pair< T, U >& prPair )
{
    return os << "( " << prPair.first << ", " << prPair.second << " )";
}

void PairTests()
{
    std::cout << std::endl << "-------------------- Pair Test -------------------" << std::endl << std::endl;
    ConstructorTest();
    OperatorEqualTest();
    MakePairTest();
    OperatorCompareTest();
    std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;
}

static void ConstructorTest()
{
    std::cout << "------------------- Constructor ------------------" << std::endl;

    ft::pair< int, float > p1;
    std::cout << "(1) Value-initialized: " << p1 << std::endl;
 
    ft::pair< int, double > p2( 42, 3.1415 );
    std::cout << "(2) Initialized with two values: " << p2 << std::endl;
 
    ft::pair< char, int > p3( p2 );
    std::cout << "(3) Implicitly converted: " << p3 << std::endl;

    std::pair< int, float > std_p1;
    std::pair< int, double > std_p2( 42, 3.1415 );
    std::pair< char, int > std_p3( std_p2 );

    assert( p1.first == std_p1.first );
    assert( p1.second == std_p1.second );
    assert( p2.first == std_p2.first );
    assert( p2.second == std_p2.second );
    assert( p3.first == std_p3.first );
    assert( p3.second == std_p3.second );

    std::cout << "--------------------------------------------------" << std::endl;
}

static void OperatorEqualTest()
{
    std::cout << "-------------------- Operator= -------------------" << std::endl;

    ft::pair< int, double > p1( 33, 442.75 ), p2( 18, 9873.5 );
    std::cout << "(1) Initialized with two values: " << p1 << std::endl;
    std::cout << "(2) Initialized with two values: " << p2 << std::endl;
 
    p2 = p1;
    std::cout << "(3) Operator= (p2 = p1), p2: " << p2 << std::endl;
 
    std::pair< int, double > std_p1( 33, 442.75 ), std_p2( 18, 9873.5 );
    std_p2 = std_p1;

    assert( p1.first == std_p1.first );
    assert( p1.second == std_p1.second );
    assert( p1.first == p2.first );
    assert( p1.second == p2.second );
    assert( p2.first == std_p2.first );
    assert( p2.second == std_p2.second );

    std::cout << "--------------------------------------------------" << std::endl;
}

static void MakePairTest()
{
    std::cout << "-------------------- Make Pair -------------------" << std::endl;

    int n = 1;
    int a[ 5 ] = { 1, 2, 3, 4, 5 };
 
    // build a pair from two ints
    ft::pair< int, int > p1 = ft::make_pair( n, a[ 1 ] );
    std::cout << "(1) The value of p1 is " << p1 << std::endl;

    std::pair< int, int > std_p1 = std::make_pair( n, a[ 1 ] );

    assert( p1.first == std_p1.first );
    assert( p1.second == std_p1.second );

    std::cout << "--------------------------------------------------" << std::endl;
}

static void OperatorCompareTest()
{
    std::cout << "------------------- Operator== -------------------" << std::endl;

    ft::pair< int, double > p1( 33, 442.75 );
    ft::pair< int, double > p2( 33, 442.75 );
    ft::pair< int, double > p3( 30, 0.4877 );
    ft::pair< int, double > p4( 47, 12 );
    std::cout << "(1) Initialized with two values: " << p1 << std::endl;
    std::cout << "(2) Initialized with two values: " << p2 << std::endl;
    std::cout << "(3) Initialized with two values: " << p3 << std::endl;
 
    std::cout << std::boolalpha;
    std::cout << "(4) p1 == p2 ?: " << ( p1 == p2 ) << std::endl;
    std::cout << "(5) p1 == p3 ?: " << ( p1 == p3 ) << std::endl;
 
    assert( p1 == p2 );
    assert( p1 != p3 );
    assert( p1 >= p3 );
    assert( p1 > p3 );
    assert( p1 <= p4 );
    assert( p1 < p4 );

    std::cout << "--------------------------------------------------" << std::endl;
}
