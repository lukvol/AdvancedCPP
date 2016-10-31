#include "fraction.h"

int main(){
	fraction f1;
	fraction f2;
	char s;
	std::cout << "Enter first fraction (2 numbers)" << std::endl;
	std::cin >> f1;
	std::cout << f1 << std::endl;
	std::cout << "Enter operator (+,-,*,/)" << std::endl;
	std::cin >> s;
	std::cout << "Enter second fraction (2 numbers)" << std::endl;
	std::cin >> f2;
	std::cout << f2 << std::endl;

	if (s == '+'){
		std::cout << f1 << s << f2 << "=" << f1+f2 << std::endl;
	} else if (s == '-'){
		std::cout << f1 << s << f2 << "=" << f1-f2 << std::endl;
	} else if (s == '*'){
		std::cout << f1 << s << f2 << "=" << f1*f2 << std::endl;
	} else if (s == '/'){
		std::cout << f1 << s << f2 << "=" << f1/f2 << std::endl;
	} else {
		std::cout << "Not a valid operation" << std::endl;
	}
}


