#include <iostream>
#include <vector>
#include "range_checking_iterator.h"

int main() {
	std::cout << "Creating vector with values [13,1]" << std::endl;
	std::vector<int> v;
	v.push_back(13);
	v.push_back(1);

	std::cout << "Initialize range checking iterator with this vector (current -> 13)" << std::endl;
	range_checking_iterator<std::vector<int>::iterator> rci(v.begin(), v.end());

	std::cout << "Decrease the iterator: std::out_of_range expected" << std::endl;
	try {
		--rci;
	} catch (std::logic_error &ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "Increasing the iterator" << std::endl;
	++rci;
	std::cout << "Current element: " << *rci << std::endl;

	std::cout << "Increasing the iterator: std::out_of_range expected" << std::endl;
	try {
		++rci;
	} catch (std::logic_error &ex) {
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}