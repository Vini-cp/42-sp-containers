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

} // pair

} // FT

#endif
