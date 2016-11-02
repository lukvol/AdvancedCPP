#include <functional>
#include <iostream>
#include <set>
#include <vector>
#include "somefunction.h"

class mod_three: public std::unary_function<const std::vector<int>, std::vector<int>> {
	public:
	std::vector<int> operator()(const std::vector<int> &input) {
		std::vector<int> filtered;
		for (const auto &el : input) {
		 	if (el % 3 == 0) {
		 		filtered.push_back(el);
		 	}
		}
		return filtered;
	}
};

class mod_two: public std::unary_function<const std::vector<int>, std::vector<int>> {
	public:
	std::vector<int> operator()(const std::vector<int> &input) {
		std::vector<int> filtered;
		for (const auto &el : input) {
		 	if (el % 2 == 0) {
		 		filtered.push_back(el);
		 	}
		}
		return filtered;
	}
};

class combine_values: public std::binary_function<const std::vector<int>, std::vector<int>, std::set<int>> {
	public:
	std::set<int> operator()(const std::vector<int> &a, const std::vector<int> &b) {
		std::set<int> result;
		for (const auto &el : a) {
			result.insert(el);
		}
		for (const auto &el : b) {
			result.insert(el);
		}
		return result;
	}
};

int main() {
	mod_two mod_two_object;
	mod_three mod_three_object;
	combine_values combine_values_object;
	somefunction_t<combine_values, mod_three, mod_two> filter_vector(combine_values_object, mod_three_object, mod_two_object);

	std::vector<int> input;
	for (int i = 0; i < 20; i++) {
		input.push_back(i);
	}

	std::cout << "Input: " << std::endl;
	for (const auto &el : input) {
		std::cout << el << std::endl;
	}

	std::set<int> result = filter_vector(input);
	std::cout << "Result: " << std::endl;
	for (const auto &el : result) {
		std::cout << el << std::endl;
	}
}