#include <iostream>
#include <string>
#include "pvector.h"

int main() {
	pvector<int> p1("pv_int.txt");
	pvector<double> p2("pv_double.txt");
	pvector<char> p3("pv_char.txt");
	pvector<std::string> p4("pv_string.txt");

	std::cout << "pvector with ints" << std::endl;
	std::cout << "Values read from file pv_int.txt: " << std::endl;
	p1.print_vector();
	std::cout << "Push value '41' to pvector" << std::endl;
	p1.push_back(41);

	std::cout << std::endl;

	std::cout << "pvector with doubles" << std::endl;
	std::cout << "Values read from file pv_double.txt: " << std::endl;
	p2.print_vector();
	std::cout << "Push value '41.14' to pvector" << std::endl;
	p2.push_back(41.14);

	std::cout << std::endl;

	std::cout << "pvector with chars" << std::endl;
	std::cout << "Values read from file pv_char.txt: " << std::endl;
	p3.print_vector();
	std::cout << "Push value '0' to pvector" << std::endl;
	p3.push_back('0');

	std::cout << std::endl;

	std::cout << "pvector with strings" << std::endl;
	std::cout << "Values read from file pv_string.txt: " << std::endl;
	p4.print_vector();
	std::cout << "Push value 'The End' to pvector" << std::endl;
	p4.push_back("The End");
}