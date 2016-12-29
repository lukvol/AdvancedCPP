#include <iostream>
/**
 * https://isocpp.org/wiki/faq/multiple-inheritance#mi-vi-ctor-order
 * 
 * Constructor order:
 * First, the virtual base class constructors are executed. Afterwards, the construction order is from
 * base to derivec classes. The reason for this is that class A which inherits from class B may want to 
 * access data from class B in its constructor. Therefore, class B needs to be constructed before class A such
 * that class B is set up when the constructor of class A is called.
 * 
 * Deconstructor order:
 * The deconstructor order is the exact opposite of the constructor order. 
 * Therefore, if A inherits from B, A is deconstructed before B is deconstructed.
 */

class C {
public:
	C() {
		std::cout << "Constructing C" << std::endl;
	}

	~C() {
		std::cout << "Deconstructing C" << std::endl;
	}
};

class D {
public:
	D() {
		std::cout << "Constructing D" << std::endl;
	}

	~D() {
		std::cout << "Deconstructing D" << std::endl;
	}
};

class B: public D, public C {
public:
	B() {
		std::cout << "Constructing B" << std::endl;
	}

	~B() {
		std::cout << "Deconstructing B" << std::endl;
	}
};

class A: public B {
public:
	A() {
		std::cout << "Constructing A" << std::endl;
	}

	~A() {
		std::cout << "Deconstructing A" << std::endl;
	}
};

/**
 * The constructor order is: D -> C -> B -> A (because D is before C in the definition of B)
 * The deconstructor order is: A -> B -> C -> D (the exact opposite)
 */
int main() {
	A a = A();
	return 0;
}