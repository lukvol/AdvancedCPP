#ifndef RPN_H
#define RPN_H

#include <vector>
#include <sstream>

class RPN {
private:
	std::vector<int> stack;
	bool should_finish = false;
	int pop_number();
	void add_number(int number);
	void execute_operation(char operation);
	void parse_input(char input, std::istringstream &fst);
	void show_stack();
public:
	void start();
};

#endif