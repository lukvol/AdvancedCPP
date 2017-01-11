#include <iostream>
#include <vector>
#include <forward_list>

#include "iterator_distance.h"

int main() {
	std::vector<int> v;
	v.push_back(1);

	std::forward_list<int> fl;
	fl.push_front(1);
	fl.push_front(2);

	std::cout << my_distance<std::vector<int>::iterator>(v.begin(), v.end()) << std::endl;
	std::cout << my_distance<std::forward_list<int>::iterator>(fl.begin(), fl.end()) << std::endl;
	return 0;
}
