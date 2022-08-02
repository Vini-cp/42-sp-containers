// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef PAIR_H
#define PAIR_H

namespace ft
{

    /* 
    *  
    *   Constructs a pair object.
    *   
    *   This involves individually constructing its two component objects, 
    *   with an initialization that depends on the constructor form invoked.
    *
    * 
    */


/*
*   @param T1     First type.
*   @param T2     Second type.
*/

template< class T1, class T2 >
struct pair
{
public:
    T1 first;
    T2 second;

public:

    /*
    *   Default constructor
    *       Constructs a pair object with its elements value-initialized.
    * 
    */
    pair() : first(), second() {};

    /*
    *   initialization constructor
    *       Member first is constructed with prFirst and member second with prSecond.
    * 
    *   @param prFirst      An object of the type of first, 
    *       or some other type implicitly convertible to it.
    *   @param prSecond     An object of the type of second,
    *       or some other type implicitly convertible to it.
    */
    pair( const T1& prFirst, const T2& prSecond ) : 
        first( prFirst ),
        second( prSecond )
    {
    };

    /*
    *   Copy / move constructor (and implicit conversion)
    *       The object is initialized with the contents of the prPair object.
    *       The corresponding member of prPair is passed to the constructor of each of its members.
    * 
    *   @param prPair  Another pair object.
    *       This may be an object of the same type as the object being constructed
    *       or of a pair type whose elements' types are implicitly convertible to 
    *       those in the pair being constructed.
    */
    template< class U1, class U2 >
    pair( const pair<U1, U2>& prPair ) : 
        first( prPair.first ),
        second( prPair.second )
    {
    };

    /*
    *   Assignment constructor (and implicit conversion)
    *       The object is initialized with the contents of the prPair object.
    *       The corresponding member of prPair is passed to the constructor of each of its members.
    * 
    *   @param prPair  Another pair object.
    *       This may be an object of the same type as the object being constructed
    *       or of a pair type whose elements' types are implicitly convertible to 
    *       those in the pair being constructed.
    */
    pair& operator=( const pair& prPair )
    {
        if (this == &prPair) return *this;

        first = prPair.first;
        second = prPair.second;

        return *this;
    }

}; // pair

/*
*   Creates a pair object, deducing the target type from the types of arguments.
* 
*   @param T1  First type.
*   @param T2  Second type.
*/
template< class T1, class T2 >
ft::pair< T1, T2 > make_pair( T1 pFirst, T2 pSecond )
{
    return ft::pair< T1, T2 >( pFirst, pSecond );
}

/*
*   Tests if both elements of prPair1 and prPair2 are equal, that is, compares
*       prPair1.first with prPair2.first and prPair1.second with prPair2.second.
* 
*   @param prPair1, prPair2     pairs to compare.
*/
template< class T1, class T2 >
bool operator==( const ft::pair< T1, T2 >& prPair1, const ft::pair< T1, T2 >& prPair2 )
{
    return prPair1.first == prPair2.first && prPair1.second == prPair2.second;
}

/*
*   Tests if both elements of prPair1 and prPair2 are equal, that is, compares
*       prPair1.first with prPair2.first and prPair1.second with prPair2.second.
* 
*   @param prPair1, prPair2     pairs to compare.
*/
template< class T1, class T2 >
bool operator!=( const ft::pair< T1, T2 >& prPair1, const ft::pair< T1, T2 >& prPair2 )
{
    return !( prPair1 == prPair2 );
}

/*
*   Compares lhs and rhs lexicographically by operator<, that is, compares
*       the first elements and only if they are equivalent, compares the second elements.
* 
*   @param prPair1, prPair2     pairs to compare.
*/
template< class T1, class T2 >
bool operator<( const ft::pair< T1, T2 >& prPair1, const ft::pair< T1, T2 >& prPair2 )
{
    return prPair1.first < prPair2.first || ( !( prPair2.first < prPair1.first ) && prPair1.second < prPair2.second );
}

/*
*   Compares lhs and rhs lexicographically by operator<, that is, compares
*       the first elements and only if they are equivalent, compares the second elements.
* 
*   @param prPair1, prPair2     pairs to compare.
*/
template< class T1, class T2 >
bool operator<=( const ft::pair< T1, T2 >& prPair1, const ft::pair< T1, T2 >& prPair2 )
{
    return !( prPair2 < prPair1 );
}

/*
*   Compares lhs and rhs lexicographically by operator<, that is, compares
*       the first elements and only if they are equivalent, compares the second elements.
* 
*   @param prPair1, prPair2     pairs to compare.
*/
template< class T1, class T2 >
bool operator>( const ft::pair< T1, T2 >& prPair1, const ft::pair< T1, T2 >& prPair2 )
{
return prPair2 < prPair1;
}

/*
*   Compares lhs and rhs lexicographically by operator<, that is, compares
*       the first elements and only if they are equivalent, compares the second elements.
* 
*   @param prPair1, prPair2     pairs to compare.
*/
template< class T1, class T2 >
bool operator>=( const ft::pair< T1, T2 >& prPair1, const ft::pair< T1, T2 >& prPair2 )
{
    return !( prPair1 < prPair2 );
}

} // ft

#endif
