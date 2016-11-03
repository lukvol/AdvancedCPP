#include <iostream>

#include "fraction.h"


int main() {
	fraction f1(1,2);
	fraction f2(2,3);
	fraction f3(2,4);

	std::cout << f1 << " + " << f2 << " = " << f1+f2 << std::endl;
	std::cout << f1 << " + " << "3" << " = " << f1+3 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1-f2 << std::endl;
	std::cout << f1 << " - " << "3" << " = " << f1-3 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1*f2 << std::endl;
	std::cout << f1 << " * " << "3" << " = " << f1*3 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1/f2 << std::endl;
	std::cout << f1 << " / " << "3" << " = " << f1/3 << std::endl;
	std::cout << f1 << " < " << f2 << " = " << (f1<f2) << std::endl;
	std::cout << f1 << " > " << f2 << " = " << (f1>f2) << std::endl;
	std::cout << f1 << " == " << "(2/4)" << " = " << (f1==f3) << std::endl;
	std::cout << f1 << " == " << f2 << " = " << (f1==f2) << std::endl;
	std::cout << f1 << " != " << f2 << " = " << (f1!=f2) << std::endl;
	std::cout << f1 << " != " << "(2/4)" << " = " << (f1!=f3) << std::endl;
	std::cout << f2 << " - " << f2 << " = " << (f2 - f2) << std::endl;

	std::cout << "Creating fractio with 0 as denominator: " << std::endl;
	try {
   		fraction f4(1,0);
	} catch (const std::exception& e) { // reference to the base of a polymorphic object
     	std::cout << e.what(); // information from length_error printed
	}
}
