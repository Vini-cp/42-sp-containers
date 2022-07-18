// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef LEXICOGRAPHICAL_COMPARE_H
#define LEXICOGRAPHICAL_COMPARE_H

namespace ft
{

    /* 
    *  
    *   Checks if the first range [first1, last1) is lexicographically
    *       less than the second range [first2, last2).
    * 
    * 
    *   Lexicographical comparison is an operation with the following properties:
    * 
    *    -  Two ranges are compared element by element.
    *    -  The first mismatching element defines which range is
    *           lexicographically less or greater than the other.
    *    -  If one range is a prefix of another, the shorter range
    *           is lexicographically less than the other.
    *    -  If two ranges have equivalent elements and are of the 
    *           same length, then the ranges are lexicographically equal.
    *    -  An empty range is lexicographically less than any non-empty range.
    *    -  Two empty ranges are lexicographically equal.
    * 
    */


/*
*   Elements are compared using operator ' < '.
* 
*   @param InputIt1     First range of the elements to examine.
*   @param InputIt2     Second range of the elements to examine.
*/

template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2 )
{
    for ( ; ( first1 != last1 ) && ( first2 != last2 ); ++first1, (void) ++first2 )
    {
        if ( *first1 < *first2 ) return true;
        if ( *first2 < *first1 ) return false;
    }

    return ( first1 == last1 ) && ( first2 != last2 );
}

//------------------------------------------------------------------------------

/*
*   Elements are compared using the given binary comparison function comp.
* 
*   @param InputIt1     First range of the elements to examine.
*   @param InputIt2     Second range of the elements to examine.
*   @param Compare      Comparison function object 
*       (i.e. an object that satisfies the requirements of Compare) 
*       which returns ​true if the first argument is less than the second.
*       The signature of the comparison function should be equivalent to the following:
*
*       bool cmp( const Type1& a, const Type2& b );
*/

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2,
                              Compare comp )
{
    for ( ; ( first1 != last1 ) && ( first2 != last2 ); ++first1, (void) ++first2 )
    {
        if ( comp( *first1, *first2 ) ) return true;
        if ( comp( *first2, *first1 ) ) return false;
    }

    return ( first1 == last1 ) && ( first2 != last2 );
}

} // ft

#endif
