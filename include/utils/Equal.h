// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef EQUAL_H
#define EQUAL_H

namespace ft
{

    /* 
    *  
    *   Returns true if the range [first1, last1) is equal to the range
    *       [first2, first2 + (last1 - first1)), and false otherwise.
    * 
    */


/*
*   @param InputIt1     First range of the elements to compare.
*   @param InputIt2     Second range of the elements to compare.
*/

template< class InputIt1, class InputIt2 >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
{
    for ( ; first1 != last1; ++first1, ++first2 )
    {
        if ( !( *first1 == *first2 ) )
        {
            return false;
        }
    }

    return true;
}

//------------------------------------------------------------------------------

/*
*   @param InputIt1         First range of the elements to compare.
*   @param InputIt2         Second range of the elements to compare.
*   @param BynaryPredicate 	Binary predicate which returns ​true if
*       the elements should be treated as equal. The signature of the
*       predicate function should be equivalent to the following:
*
*       bool pred( const Type1& a, const Type2& b );
*/

template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, 
            InputIt2 first2, BinaryPredicate p )
{
    for ( ; first1 != last1; ++first1, ++first2 )
    {
        if ( !p( *first1, *first2 ) )
        {
            return false;
        }
    }

    return true;
}

} // ft

#endif
