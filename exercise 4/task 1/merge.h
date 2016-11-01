#include <iostream>
#include <iterator>
#include <map>
#include <set>

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
