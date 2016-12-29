#ifndef UNLIMITED_STACK_H
#define UNLIMITED_STACK_H

#include <deque>
#include "Stack.h"

class Unlimited_Stack: public Stack {
	std::deque<int> buf;
public:
	virtual void push(int i) { 
		buf.emplace_back(i);
	}
	virtual int pop() { 
		int last = buf.back();
		buf.pop_back();
		return last;
	}
	virtual int empty() { return buf.empty(); }
	int elements() { return buf.size(); }
};

#endif