#ifndef STACK_H
#define STACK_H

class Stack {
protected:
	int buf[256], sp;
public:
	Stack() { sp = 256; }
	virtual void push(int i) { buf[--sp] = i; }
	virtual int pop() { return buf[sp++]; }
	virtual int empty() { return sp == 256; }
};

#endif
