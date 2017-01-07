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
	s->push(2);
}

/**
 * For the unlimited stack, we used the deque sequential container since it has no size limits and allows
 * fast insertion and deletion at the front and at the back. Therefore, it is ideal for an unlimted stack.
 * The binding problem is solved by declaring any function as virtual, therefore, the unlimited stack uses
 * dynamic binding. However, the slicing problem can only be solved by using a reference/pointer to access 
 * the stack in a method. The reason is that we cannot keep the attributes of the subclass consistent, because
 * the main data structure in the superclass has a hardcoded size limitation.
 */
int main() {
	Stack s;
	Unlimited_Stack us;

	us.push(2);
	us.push(4);
	us.push(12);

	fill(us);

	for (int i = 0; i < 1234; i++) {
		fill2(us);
	}
	
	std::cout << "Size: " << us.size() << std::endl;

	return 0;
}