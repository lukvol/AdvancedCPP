#include <iostream>
#include "RPN.h"
#include "fraction.h"

int main(int argc, char* argv[]) {
	if (argc > 1) {
		std::cout << "Enter 'i' for int, 'd' for double or 'f' for fractions: ";
		char command;
		std::cin >> command;
		switch(command) {
			case 'i': {
				RPN<int> rpn = RPN<int>(std::string(argv[1]));
				rpn.start();
				break;
			}
			case 'd': {
				RPN<double> rpn = RPN<double>(std::string(argv[1]));
				rpn.start();
				break;
			}
			case 'f': {
				RPN<fraction> rpn = RPN<fraction>(std::string(argv[1]));
				rpn.start();
				break;
			}
		}
	} else {
		std::cout << "Filename not submitted!" << std::endl;
	}
}