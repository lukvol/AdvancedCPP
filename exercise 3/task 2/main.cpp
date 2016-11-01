#include <iostream>
#include "spell_checker.h"

int main(int argc, char const *argv[]) {
	if (argc > 2) {
		spell_checker test(argv[1], argv[2]);
	} else {
		std::cout << "Please submit a dictionary and a text file" << std::endl;
	}
	return 0;
}