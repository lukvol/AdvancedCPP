#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <list>
#include <iostream>
#include "dumb_pointer.h"

template<typename Object>
class smart_pointer {
private:
	//We use a pointer for the reference counter such that multiple smart pointers can
	//share the same one. Therefore, we need to allocate it on the heap.
	int *ref_counter = new int(0);
	Object *raw_object;

	/**
	 * @brief      Adopts the reference counter from another smart pointer
	 * 			   by decreasing its own reference counter and then copy and increasing
	 * 			   the reference counter of the target smart pointer.
	 * @param[in]  sp    The smart pointer from which we want to adopt the reference counter
	 */
	void adopt_reference_counter(const smart_pointer<Object> &sp) {
		(*ref_counter)--;
		ref_counter = sp.ref_counter;
		(*ref_counter)++;
	}
public:
	/**
	 * @brief      Constructor. We need to call the constructor for
	 *             the parent class (dumb_pointer) explicitely. Stores the Object and increases
	 *             the reference counter by one.
	 * @param[in]  obj   The object referenced to by the smart pointer.
	 */
	smart_pointer(Object *obj) {
		raw_object = obj;
		(*ref_counter)++;
	}

	/**
	 * @brief      Copy constructor. Adopts the reference counter from the object
	 *			   Since we call the default copy constructor of dumb_pointer, the 
	 *			   raw_object is automatically initialized.
	 * @param      sp    The smart pointer to copy from
	 */
	smart_pointer<Object>(smart_pointer<Object> &sp) {
		adopt_reference_counter(sp);
	}

	/**
	 * @brief      Deconstructor. Decreases the reference counter. If it reaches 0, the
	 * 			   reference counter is deleted as well.
	 */
	~smart_pointer<Object>() {
		(*ref_counter)--;
		if (*ref_counter == 0) {
			std::cout << "Deleting object: " << *raw_object << std::endl;
			delete ref_counter;
			delete raw_object;
		}
	}

	smart_pointer<Object> &operator= (const smart_pointer<Object> &sp) {
		raw_object = sp.raw_object;
		adopt_reference_counter(sp);
		return *this;
	}

	int counter() { return *ref_counter; };
	Object& operator* () { return *raw_object; }
	Object* operator-> () { return raw_object; }

	void print() { std::cout << *ref_counter << ": " << *raw_object << std::endl; }
};

#endif