#include <iostream>
#include "RPN.h"
#include "fraction.h"

int main() {
	std::cout << "Enter 'i' for int, 'd' for double or 'f' for fractions: ";
	char command;
	std::cin >> command;
	switch(command) {
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
			rpn.start();
			break;
		}
	}
}