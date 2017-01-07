#include <iostream>

#include "Stack.h"
#include "Unlimited_Stack.h"


void fill(Stack s) {
	std::cout << s.pop() << std::endl;
	s.push(2);
}

void fill2(Stack &s) {
	s.push(1);
	s.push(2);
}

void fill3(Stack *s) {
	s->push(1);
	s->push(232);
}

/**
 * To ensure that there do not occur any binding errors, we declared the functions the subclass overrides as
 * virtual. To ensure that no slicing occurs, we adopted the datastructure from the superclass. However, the 
 * datastructure (i.e, the buff array and the pointer) have to be declared protected for this to work. The
 * unlimited stack version then uses the array for the most current 256 objects and stores the other objects which
 * do not fit into the array in a register from which they can be loaded as needed.
 */
int main() {
	Stack s;
	Unlimited_Stack us;

	std::cout << "Add 3 elements (2, 4, 12): " << std::endl;
	us.push(2);
	us.push(4);
	us.push(12);
	std::cout << "Size: " << us.size() << std::endl;

	std::cout << "Pop element, add 2 (method declared for superclass; by value): " << std::endl;
	fill(us);
	std::cout << "Size: " << us.size() << std::endl;

	std::cout << "Add 1234 * 2 elements (1, 2) by reference: " << std::endl;
	for (int i = 0; i < 1234; i++) {
		fill2(us);
	}
	std::cout << "Size: " << us.size() << std::endl;

	std::cout << "Add 2 elements (1, 232) by reference: " << std::endl;
	fill3(&us);
	std::cout << "Size: " << us.size() << std::endl;
	std::cout << "Pop: " << us.pop() << std::endl;
	std::cout << "size: " << us.size() << std::endl;
	return 0;
}