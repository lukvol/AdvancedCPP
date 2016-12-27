#include <iostream>
#include <string>
#include "dumb_pointer.h"
#include "smart_pointer.h"

struct Object {
public:
	int value;
	Object(int val) : value(val) {}
	int method1() { return value * 10;}
	int method2() { return value + 10;}
	int method3() { return value - 10;}
	friend std::ostream &operator<< (std::ostream &output, const Object &a) {
		output << a.value;
		return output; 
	}
};


int main() {
	//Testing dumb pointer
	std::cout << "Dumb pointer:" << std::endl;
	std::cout << "Initialize a new dumb pointer which stores integers with 12" << std::endl;
	dumb_pointer<int> p1(12);
	std::cout << "Showing value of dumb pointer by using the * operator: " << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << "Increasing the stored integer ((*p1)++): " << std::endl;
	(*p1)++;
	std::cout << *p1 << std::endl;

	std::cout << "Initialize a new dumb pointer which stores strings with \"Hello World\"." << std::endl;
	dumb_pointer<std::string> p2("Hello World");
	std::cout << "Showing value of dumb pointer by using the * operator: " << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << "Using the -> operator to access the first element of the string (p2->at(0)):" << std::endl;
	std::cout << p2->at(0) << std::endl;
	std::cout << std::endl;


	//Testing smart pointer
	std::cout << "Smart pointer:" << std::endl;
	std::cout << "Creating two Objects o1 = new Object(1) and o2 = new Object(2)" << std::endl;

	Object *o1 = new Object(1);
	Object *o2 = new Object(2);

	std::cout << "Creating smart pointer p which references o1: " << std::endl;
	smart_pointer<Object> p(o1);
	std::cout << "Ref counter (p for o1): " << p.counter() << std::endl;

	std::cout << "Creating smart pointer q by copying p (q(p)): " << std::endl;
	smart_pointer<Object> q(p);
	std::cout << "Ref counter (p for o1): " << p.counter() << std::endl;
	std::cout << "Ref counter (q for o1): " << q.counter() << std::endl;

	std::cout << "Creating smart pointer r which references o2: " << std::endl;
	smart_pointer<Object> r(o2);
	std::cout << "Ref counter (r for o2): " << r.counter() << std::endl;

	std::cout << "Assign r to q (q=r): " << std::endl;
	q = r;
	std::cout << "Ref counter (p for o1): " << p.counter() << std::endl;
	std::cout << "Ref counter (q for o2): " << q.counter() << std::endl;
	std::cout << "Ref counter (r for o2): " << r.counter() << std::endl;

	p.print();
	q.print();
	r.print();

	std::cout << "Display 1st and 2nd object (* operator): " << std::endl;
	std::cout << *p << ", " << *r << std::endl;

	std::cout << "Call methods on object (-> operator): " << std::endl;
	std::cout << p->method1() << ", " << q->method2() << ", " << r->method3() << std::endl;
	return 0;
}