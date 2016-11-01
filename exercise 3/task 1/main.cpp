#include <iostream>
#include <string>
#include "pset.h"
#include "pvector.h"

int main() {
	pvector<int> pv("int_input.txt");
	pset<int> ps("int_input.txt");
	
	std::cout << "Input to check the different functionality between a set and a vector" << std::endl;
	std::cout << "The input file contains the values: 1,2,3,3,2,1 and is read by a vector as well as a set." << std::endl;
	std::cout << "pvector: " << std::endl;
	pv.print_vector();
	std::cout << "pset: " << std::endl;
	ps.print_set();

	std::cout << "Input to check if the persistence_traits works with strings which contains a space" << std::endl;
	pvector<std::string> pv2("string_input_pv.txt");
	pset<std::string> ps2("string_input_ps.txt");
	std::cout << std::endl;
	std::cout << "The input file containts the sentence: \"Hello! We try our pvector implementation\"" << std::endl;
	std::cout << "pvector: " << std::endl;
	pv2.print_vector();
	std::cout << "pset: " << std::endl;
	ps2.print_set();
	std::cout << std::endl;
	std::cout << "Writing \"Test passed! into the vector.\"" << std::endl;
	pv2.push_back("Test passed!");
	std::cout << std::endl;
	std::cout << "Writing \"Test passed! into the set.\"" << std::endl;
	ps2.insert("Test passed!");
}