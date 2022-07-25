// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef ITERATORTRAITS_H
#define ITERATORTRAITS_H

namespace ft
{

/**
* 
*   std::iterator_traits is the type trait class that provides uniform interface 
*       to the properties of LegacyIterator types. This makes it possible to implement 
*       algorithms only in terms of iterators.
*
*   The template can be specialized for user-defined iterators so that the information 
*       about the iterator can be retrieved even if the type does not provide the usual 
*       typedefs.
*
*/

/*
*   @param Iterator    The iterator type to retrieve properties for.
*/
template < class Iterator >
struct iterator_traits
{
    typedef typename Iterator::value_type          value_type;
    typedef typename Iterator::difference_type     difference_type;
    typedef typename Iterator::iterator_category   iterator_category;
    typedef typename Iterator::pointer             pointer;
    typedef typename Iterator::reference           reference;
};

/**
* 
*   This type trait may be specialized for user-provided types that may be used as iterators. 
*       The standard library provides partial specializations for pointer types T*, which makes 
*       it possible to use all iterator-based algorithms with raw pointers.
*
*/

/*
*   @param T    Specialization member types.
*/
template < class T >
struct iterator_traits< T* >
{
    typedef T                               value_type;
    typedef ptrdiff_t                       difference_type;
    typedef random_access_iterator_tag      iterator_category;
    typedef T*                              pointer;
    typedef T&                              reference;
};

/*
*   @param T    Specialization member types.
*/
template< class T >
struct iterator_traits< const T* >
{    
    typedef T                               value_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef random_access_iterator_tag      iterator_category;
    typedef const T*                        pointer;
    typedef const T&                        reference;
};

} // ft

#endif
