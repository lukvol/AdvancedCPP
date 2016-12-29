#ifndef RANGE_CHECKING_ITERATOR_H
#define RANGE_CHECKING_ITERATOR_H

#include <stdexcept>

template<typename Iter>
class range_checking_iterator {
private:
	//http://softwareengineering.stackexchange.com/a/291804
	typedef typename std::iterator_traits<Iter>::value_type ResultType;
	Iter begin;
	Iter end;
	Iter current;
public:
	range_checking_iterator(Iter b, Iter e) :  begin(b), end(e) {
		current = begin;
	}

	range_checking_iterator operator++() {
		if (end - current <= 1) {
			throw std::out_of_range("You tried to leave the allowed range!");
		}
		++current;
		return *this;
	}

	range_checking_iterator operator--() {
		if (current == begin) {
			throw std::out_of_range("You tried to leave the allowed range!");
		}
		--current;
		return *this;
	}

	ResultType& operator*() {
		return *current;
	}
};

#endif