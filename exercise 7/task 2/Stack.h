#ifndef STACK_H
#define STACK_H

class Stack {
	
public:
	int buf[256], sp;
	Stack() { sp = 256; }
	virtual void push(int i) { buf[--sp] = i; }
	virtual int pop() { return buf[sp++]; }
	virtual int empty() { return sp == 256; }
};

#endif