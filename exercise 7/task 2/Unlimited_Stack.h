#ifndef UNLIMITED_STACK_H
#define UNLIMITED_STACK_H

#include <deque>
#include <array>
#include "Stack.h"

class Unlimited_Stack: public Stack {
private:
	int index;
	std::deque<std::array<int, 256>> reg;
public:
	Unlimited_Stack() {
		sp = 256;
		index = 0;
	}

	virtual void push(int i) { 
		if (sp == 0) {
			std::array<int, 256> temp;
			std::copy(std::begin(buf), std::end(buf), std::begin(temp));
			reg.emplace_back(temp);

			index++;
			sp = 256;
		}

		buf[--sp] = i;
	}

	virtual int pop() {
		if (index > 0 && sp == 256) {
			reg.pop_back();
			std::copy(reg.back().begin(), reg.back().end(), buf);
			index--;
		}
		return buf[sp++];
	}

	virtual int empty() { return index == 0 && sp == 256; }
	int size() { return (256 - sp) + index * 256; }
};

#endif
