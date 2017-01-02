#include <iterator>

template<bool B, typename T = void>
using EnableIf = typename std::enable_if<B,T>::type;

using SubtractableIterator = std::bidirectional_iterator_tag;

template<typename It>
typename std::iterator_traits<It>::difference_type my_distance(It first, It last, typename std::enable_if<std::is_same<typename std::iterator_traits<It>::iterator_category,
           SubtractableIterator>::value>::type* = 0) { return last-first; }

template<typename It> 
typename std::iterator_traits<It>::difference_type my_distance(It first, It last, typename std::enable_if<!std::is_same<typename std::iterator_traits<It>::iterator_category,
           SubtractableIterator>::value>::type* = 0) { 
	typename std::iterator_traits<It>::difference_type n = 0;
	while (first != last) {
		++first;
		++n;
	}
	return n;
}