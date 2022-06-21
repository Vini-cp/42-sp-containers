// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef MAKE_PAIR_H
#define MAKE_PAIR_H

#include "Pair.h"

namespace ft
{

    /* 
    *  
    *   Creates a ft::pair object, deducing the target type from the types of arguments.
    * 
    */

/*
*   @param T1     First type.
*   @param T2     Second type.
*/

template< class T1, class T2 >
ft::pair< T1, T2 > make_pair( T1 pFirst, T2 pSecond )
{
    return ft::pair< T1, T2 >( pFirst, pSecond );
}

} // FT

#endif
