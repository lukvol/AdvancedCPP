#include <iostream>
#include "RPN.h"
#include "fraction.h"

int main() {
	std::cout << "Enter 'i' for int, 'd' for double or 'f' for fractions: ";
	std::string input;
	getline(std::cin, input);
	switch(input.at(0)) {
		case 'i': {
			RPN<int> rpn;
			rpn.start();
			break;
		}
		case 'd': {
			RPN<double> rpn;
			rpn.start();
			break;
		}
		case 'f': {
			RPN<fraction> rpn;
			std::cout << "To enter a fraction, write 'n counter denominator' (e.g. n 1 7 for 1/7): " << std::endl;
			rpn.start();
			break;
		}
	}
}