#include <iterator>

template<bool B, typename T = void>
using EnableIf = typename std::enable_if<B,T>::type;

template <typename Iter>
using DifferenceTypeOf = typename std::iterator_traits<Iter>::difference_type;

template <typename Iter>
using IteratorCategoryOf = typename std::iterator_traits<Iter>::iterator_category;

using SubtractableIterator = std::bidirectional_iterator_tag;

template<typename Iter>
EnableIf<std::is_same<IteratorCategoryOf<Iter>, SubtractableIterator>::value, 
		 DifferenceTypeOf<Iter>> my_distance(Iter first, Iter last) { return last-first; }

template<typename Iter> 
EnableIf<!std::is_same<IteratorCategoryOf<Iter>, SubtractableIterator>::value, 
		 DifferenceTypeOf<Iter>> my_distance(Iter first, Iter last) { 
	typename std::iterator_traits<Iter>::difference_type n = 0;
	while (first != last) {
		++first;
		++n;
	}
	return n;
}



