#include <iostream>
#include <iterator>
#include <map>
#include <set>

// we chose to use the input and output iterators for realising the merge function
// since every container must have at least an input and an output operator, otherwise
// the container would be useless since one could not either read an element from
// the container or write an element to the container.
// 
// Since we chose to use the iterators, we need almost no information about the container
// to be able to merge one container into another one. We only need to check if the container
// is a map, since the map iterator is different than the other ones (contains first and second)
// 
// Now, the way our merge function work is that the user has to submit the output operator
// from the container which should be the destination container and the whole container from
// which he want the elements merged into the destination. We need the whole container to check
// whether it is a map or not. Afterwards, it simply copies all elements from the container
// to the output iterator.
template<typename output_iterator, typename container>
void merge_containers(output_iterator dest, const container &con) {
	auto fst = con.begin();
	auto lst = con.end();
	while (fst != lst) {
		*dest++ = *fst++;
	}
}

template<typename T, typename Q>
void merge_containers(std::map<T,Q> &dest, const std::map<T,Q> &con) {
	auto fst = con.begin();
	auto lst = con.end();
	auto inserter = std::inserter(dest, std::next(dest.begin()));
	while (fst != lst) {
		*inserter++ = *fst++;
	}
}

template<typename output_iterator, typename T, typename Q>
void merge_containers(output_iterator dest, const std::map<T,Q> &con) {
	auto fst = con.begin();
	auto lst = con.end();
	while (fst != lst) {
		*dest++ = fst->second;
		fst++;
	}
}
