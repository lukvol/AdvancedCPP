#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include "merge.h"

int main() {
	std::map<int, int> m1, m2;
	m1[1] = 123;
	m1[2] = 312;
	m1[3] = 341;
	m2[1] = 312;
	m2[2] = 1;
	m2[3] = 312;
	m2[4] = 1111;

	std::cout << "Merging map 2 into map 1: " << std::endl;
	std::cout << "Content of m1: " << std::endl;
	for (auto &el : m1) {
		std::cout << "key: " << el.first << " value: " << el.second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of m2: " << std::endl;
	for (auto &el : m2) {
		std::cout << "key: " << el.first << " value: " << el.second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of m1 after merging: " << std::endl;
	merge_containers(m1, m2);
	for (auto &el : m1) {
		std::cout << "key: " << el.first << " value: " << el.second << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<std::string> v1, v2;
	v1.push_back("Hello");
	v1.push_back("World");
	v2.push_back("This is a");
	v2.push_back("Test!");

	std::cout << "Merging vector 2 into vector 1: " << std::endl;
	std::cout << "Content of v1: " << std::endl;
	for (auto &el : v1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v2: " << std::endl;
	for (auto &el : v2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v1 after merging: " << std::endl;
	merge_containers(std::back_inserter(v1), v2);
	for (auto &el : v1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::list<int> l1, l2;
	l1.push_back(13);
	l1.push_back(11);
	l2.push_back(-5);

	std::cout << "Merging list 2 into list 1: " << std::endl;
	std::cout << "Content of l1: " << std::endl;
	for (auto &el : l1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of l2: " << std::endl;
	for (auto &el : l2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of l1 after merging: " << std::endl;
	merge_containers(std::back_inserter(l1), l2);
	for (auto &el : l1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::set<int> s1, s2;
	s1.insert(42);
	s1.insert(1);
	s2.insert(42);
	s2.insert(312);

	std::cout << "Merging set 2 into set 1: " << std::endl;
	std::cout << "Content of s1: " << std::endl;
	for (auto &el : s1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of s2: " << std::endl;
	for (auto &el : s2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of s1 after merging: " << std::endl;
	merge_containers(std::inserter(s1, std::next(s1.begin())), s2);
	for (auto &el : s1) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int> v3;
	v3.push_back(31);
	v3.push_back(123);

	std::cout << "Merging set 2 into vector 3: " << std::endl;
	std::cout << "Content of s2: " << std::endl;
	for (auto &el : s2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3: " << std::endl;
	for (auto &el : v3) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3 after merging: " << std::endl;
	merge_containers(std::back_inserter(v3), s2);
	for (auto &el : v3) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging vector 3 into set 2: " << std::endl;
	std::cout << "Content of s2: " << std::endl;
	for (auto &el : s2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3: " << std::endl;
	for (auto &el : v3) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of s2 after merging: " << std::endl;
	merge_containers(std::inserter(s2, std::next(s2.begin())), v3);
	for (auto &el : s2) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging list 2 into set 2: " << std::endl;
	std::cout << "Content of s2: " << std::endl;
	for (auto &el : s2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of l2: " << std::endl;
	for (auto &el : l2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of s2 after merging: " << std::endl;
	merge_containers(std::inserter(s2, std::next(s2.begin())), l2);
	for (auto &el : s2) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging set 1 into list 1: " << std::endl;
	std::cout << "Content of s1: " << std::endl;
	for (auto &el : s1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of l1: " << std::endl;
	for (auto &el : l1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of l1 after merging: " << std::endl;
	merge_containers(std::back_inserter(l1), s1);
	for (auto &el : l1) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging map 1 into set 1: " << std::endl;
	std::cout << "Content of s1: " << std::endl;
	for (auto &el : s1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of m1: " << std::endl;
	for (auto &el : m1) {
		std::cout << "key: " << el.first << " value: " << el.second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of s1 after merging: " << std::endl;
	merge_containers(std::inserter(s1, std::next(s1.begin())), m1);
	for (auto &el : s1) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging vector 3 into list 1: " << std::endl;
	std::cout << "Content of l1: " << std::endl;
	for (auto &el : l1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3: " << std::endl;
	for (auto &el : v3) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of l1 after merging: " << std::endl;
	merge_containers(std::back_inserter(l1), v3);
	for (auto &el : l1) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging list 2 into vector 3: " << std::endl;
	std::cout << "Content of l2: " << std::endl;
	for (auto &el : l2) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3: " << std::endl;
	for (auto &el : v3) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3 after merging: " << std::endl;
	merge_containers(std::back_inserter(v3), l2);
	for (auto &el : v3) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging map 1 into list 1: " << std::endl;
	std::cout << "Content of l1: " << std::endl;
	for (auto &el : l1) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of m1: " << std::endl;
	for (auto &el : m1) {
		std::cout << "key: " << el.first << " value: " << el.second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of s1 after merging: " << std::endl;
	merge_containers(std::back_inserter(l1), m1);
	for (auto &el : l1) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Merging map 2 into vector 3: " << std::endl;
	std::cout << "Content of v3: " << std::endl;
	for (auto &el : v3) {
		std::cout << el << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of m2: " << std::endl;
	for (auto &el : m2) {
		std::cout << "key: " << el.first << " value: " << el.second << " | ";
	}
	std::cout << std::endl;
	std::cout << "Content of v3 after merging: " << std::endl;
	merge_containers(std::back_inserter(v3), m2);
	for (auto &el : v3) {
		std::cout << el << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
}