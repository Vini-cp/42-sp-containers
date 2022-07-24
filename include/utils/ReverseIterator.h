// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include "IteratorTraits.h"

namespace ft
{

    /* 
    *  
    *   reverse_iterator is an iterator adaptor that reverses the direction of a given iterator.
    *       In other words, when provided with a bidirectional iterator, reverse_iterator produces
    *       a new iterator that moves from the end to the beginning of the sequence defined by the 
    *       underlying bidirectional iterator.
    *
    *   For a reverse iterator r constructed from an iterator i, the relationship &*r == &*(i-1) is 
    *       always true (as long as r is dereferenceable); thus a reverse iterator constructed from 
    *       a one-past-the-end iterator dereferences to the last element in a sequence.
    * 
    */


/*
*   @param Iterator   A iterator type.
*/
template < class Iterator >
class reverse_iterator : public ft::iterator_traits< Iterator >
{

public:

    typedef Iterator iterator_type;
    typedef typename ft::iterator_traits< Iterator >::iterator_category iterator_category;
    typedef typename ft::iterator_traits< Iterator >::value_type value_type;
    typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
    typedef typename ft::iterator_traits< Iterator >::pointer pointer;
    typedef typename ft::iterator_traits< Iterator >::reference reference;

    /*
    *   Default constructor.
    *       The underlying iterator is value-initialized.
    *
    *   @param (None)
    *
    */
    reverse_iterator() : mCurrent() {}

    /*
    *   Initalization constructor
    *       The underlying iterator is initialized with pIterator.
    * 
    *   @param pIterator    Iterator to adapt.
    *
    */
    explicit reverse_iterator( Iterator pIterator ) : mCurrent( pIterator ) {}

    /*
    *   Copy / type-cast constructor
    *       Constructs a reverse iterator from some other reverse iterator.
    *       The constructed object keeps the same sense of iteration as prIterator.
    * 
    *   @param pIterator    An iterator of a reverse_iterator type, whose sense of iteration is preserved.
    *
    */
    template < typename U >
    reverse_iterator( const reverse_iterator< U >& prIterator ) : mCurrent( prIterator.mCurrent ) {}


    /*
    *   Returns the underlying base iterator.
    *
    *   @param (None)
    *
    */
    Iterator base() const { return mCurrent; }

    /*
    *   Returns a reference to the element previous to current.
    *
    *   @param (None)
    *
    */
    reference operator*() const
    {
        Iterator tmp = current;
        return *--tmp;
    }

    /*
    *   Returns a pointer to the element previous to current.
    *
    *   @param (None)
    *
    */
    pointer operator->() const { return &( operator*() ); }

    /*
    *   Pre-increments by one respectively and returns a reference to iterator.
    *
    *   @param (None)
    *
    */
    reverse_iterator& operator++()
    {
        --mCurrent;
        return *this;
    }

    /*
    *   Returns a reference to iterator and post-increments by one respectively.
    *
    *   @param (None)
    *
    */
    reverse_iterator operator++(int)
    {
        reverse_iterator tmp = *this;
        --( *this );

        return tmp;
    }

    /*
    *   Pre-decrements by one respectively and returns a reference to iterator.
    *
    *   @param (None)
    *
    */
    reverse_iterator& operator--()
    {
        ++mCurrent;
        return *this;
    }

    /*
    *   Returns a reference to iterator and post-decrements by one respectively.
    *
    *   @param (None)
    *
    */
    reverse_iterator operator--(int)
    {
        reverse_iterator tmp = *this;
        ++( *this );

        return tmp;
    }

    /*
    *   Returns an iterator which is advanced by -n positions.
    *
    *   @param n    position relative to current location.
    *
    */
    reverse_iterator operator+( difference_type n ) const { return reverse_iterator( base() - n ); }

    /*
    *   Advances the iterator by -n positions and returns it.
    *
    *   @param n    position relative to current location.
    *
    */
    reverse_iterator& operator+=( difference_type n )
    {
        mCurrent = reverse_iterator( base() - n );
        return *this;   
    }

    /*
    *   Returns an iterator which is advanced by n positions.
    *
    *   @param n    position relative to current location.
    *
    */
    reverse_iterator operator-( difference_type n ) const { return reverse_iterator( base() + n ); }

    /*
    *   Advances the iterator by n positions and returns it.
    *
    *   @param n    position relative to current location.
    *
    */
    reverse_iterator& operator-=( difference_type n )
    {
        mCurrent = reverse_iterator( base() + n );
        return *this;   
    }

    /*
    *   Returns a reference to the element at specified relative location.
    *
    *   @param n    position relative to current location.
    *
    */
    reference operator[]( difference_type n ) const { return base()[ -n - 1 ]; }


protected:
    /*
    *   The underlying iterator of which base() returns a copy.
    *
    */
    Iterator mCurrent;

}; // reverse_iterator

/*
*   Compares the underlying iterators.
*
*   @param prIterator1, prIterator2     iterator adaptors to compare
*
*/
template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator< Iterator1 >& prIterator1, const ft::reverse_iterator< Iterator2 >& prIterator2 )
{
    return prIterator1 == prIterator2;
}

/*
*   Compares the underlying iterators.
*
*   @param prIterator1, prIterator2     iterator adaptors to compare
*
*/
template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator< Iterator1 >& prIterator1, const ft::reverse_iterator< Iterator2 >& prIterator2 )
{
    return prIterator1 != prIterator2;
}

/*
*   Compares the underlying iterators.
*
*   @param prIterator1, prIterator2     iterator adaptors to compare
*
*/
template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator< Iterator1 >& prIterator1, const ft::reverse_iterator< Iterator2 >& prIterator2 )
{
    return prIterator1 < prIterator2;
}

/*
*   Compares the underlying iterators.
*
*   @param prIterator1, prIterator2     iterator adaptors to compare
*
*/
template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator< Iterator1 >& prIterator1, const ft::reverse_iterator< Iterator2 >& prIterator2 )
{
    return prIterator1 <= prIterator2;
}

/*
*   Compares the underlying iterators.
*
*   @param prIterator1, prIterator2     iterator adaptors to compare
*
*/
template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator< Iterator1 >& prIterator1, const ft::reverse_iterator< Iterator2 >& prIterator2 )
{
    return prIterator1 > prIterator2;
}

/*
*   Compares the underlying iterators.
*
*   @param prIterator1, prIterator2     iterator adaptors to compare
*
*/
template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator< Iterator1 >& prIterator1, const ft::reverse_iterator< Iterator2 >& prIterator2 )
{
    return prIterator1 >= prIterator2;
}

/*
*   Returns the iterator it incremented by n.
*
*   @param n            the number of positions to increment the iterator
*   @param prIterator   the iterator adaptor to increment
*
*/
template< class Iter >
reverse_iterator< Iter > operator+( typename reverse_iterator< Iter >::difference_type n, const reverse_iterator< Iter >& prIterator )
{
    return reverse_iterator< Iter >( prIterator.base() - n );
}

/*
*   Returns the distance between two iterator adaptors.
*
*   @param prIterator1, prIterator2     iterator adaptors to compute the difference of.
*
*/
template< class Iterator >
typename reverse_iterator< Iterator >::difference_type operator-( const reverse_iterator< Iterator >& prIterator1,
                                                                  const reverse_iterator< Iterator >& prIterator2 )
{
    return prIterator2.base() - prIterator1.base();
}

} // ft

#endif
