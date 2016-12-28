#include <iostream>
#include "RPN.h"
#include "fraction.h"
#include "FileLocker.h"

int main(int argc, char* argv[]) {
	if (argc > 1) {
		try {
			std::string filename = std::string(argv[1]);
			FileLocker fl = FileLocker(filename);

			std::cout << "Enter 'i' for int, 'd' for double or 'f' for fractions: ";
			std::string input;
			getline(std::cin, input);
			switch(input.at(0)) {
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
					std::cout << "To enter a fraction, write 'n counter/denominator' (e.g. n 1/7 for 1/7): " << std::endl;
					rpn.start();
					break;
				}
			}
		} catch (LockedException &le) {
			std::cout << "The file you want to access is locked!" << std::endl;
		}
		
	} else {
		std::cout << "Filename not submitted!" << std::endl;
	}
}