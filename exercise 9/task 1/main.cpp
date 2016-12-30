#include <iostream>
#include "Form.h"

int main() {
	Form gen4(4);

	Form sci8 = gen4;
	sci8.scientific().precision(8);

	std::cout << sci8(12.12) << " " << 12.12 << " " << sci8 << 12.12 << " " << 12.12 << std::endl;
	return 0;
}