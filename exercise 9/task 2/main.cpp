#include "indentation_buffer.h"
#include <iostream>

int main() {
	indentation_buffer buff(std::cout, 4);
	/*std::cout << "int main() {    std::cout << \"Hello { World! }\" << std::endl;" << std::endl;
	std::cout << "return 0; } hallo" << std::endl;*/


	std::cout << "int main() " << std::endl;
	std::cout << "{" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "    Hello { World! } << std::endl;" << std::endl;
	std::cout << "    return 0;" << std::endl;
	std::cout << std::endl;
	std::cout << "}" << std::endl;

	return 0;
}