#include <string>
#include <iostream>
#include "RPN.h"

/**
 * Prints all the elements from the stack.
 */
void RPN::show_stack() {
	for (std::size_t i = 0; i < stack.size(); i++) {
		std::cout << i + 1 << ": " << stack[i] << std::endl;
	}
}

/**
 * Removes the last element from the stack if the stack is not empty.
 * @throw std::out_of_range The stack is empty
 * @return Removed element
 */
int RPN::pop_number() {
	if (stack.size() > 0) {
		int last = stack.back();
		stack.pop_back();
		return last;
	} else {
		throw std::out_of_range("The stack is empty!");
	}
}

/**
 * Adds a number to the stack
 * @param number Number to add
 */
void RPN::add_number(int number) {
	stack.push_back(number);
}

/**
 * Executes an operation on two elements of the stack.
 * @pre   operation is a valid operation
 * @param operation The operation which should be performed on two operands
 * @throw std::invalid_argument  The operand is '/' and the denominator is 0, therefore, the user tries to divide by 0
 */
void RPN::execute_operation(char operation) {
	if (stack.size() < 2) {
		std::cout << "You need at least two elements on the stack to perform an operation" << std::endl;
	} else {
		int result;
		//we don't need to check if the operation is valid, since
		//this method is only called if a valid operation was entered
		switch (operation) {
			case '*': {
				result = pop_number() * pop_number();
				break;
			}
			case '/': {
				if (stack.at(stack.size() - 1) == 0) {
					throw std::invalid_argument("You can't divide by 0!");
					break;
				} else {
					int denom = pop_number();
					int nom = pop_number();
					result = nom / denom;
					break;
				}
			}
			case '+': {
				result = pop_number() + pop_number();
				break;
			}
			case '-': {
				int second = pop_number();
				int first = pop_number();
				result = first - second;
				break;
			}
		}
		add_number(result);
	}
}

/**
 * Parses the input the user enters. The input can either be a command (i.e., 'q' to quit, 'd' to delete a number), 
 * an operation (i.e., '/', '+', '-' or '*') or an operand (integer). After the function parsed the command, it delegates
 * the further proceeding to the corresponding method. 
 * @param input String which contains the input
 */
void RPN::parse_input(char command, std::istringstream &fst) {
	switch (command) {
		case '+': case '-': case '*': case'/': {
			//if the rpn fails to execute the operation (namely, if the user wants to
			//divide through 0), we restart the rpn operator but with the stack content
			//remaining.
			try {
				execute_operation(command);
			} catch (std::exception& ex) {
				std::cerr << ex.what() << std::endl;
				start();
			}
			fst >> command;
			break;
		}
		case 'd': {
			if (stack.size() > 0) {
				pop_number();
			}
			fst >> command;
			break;
		}
		case 'q': {
			should_finish = true;
			break;
		}
		case 'n': {
			int operand;
			fst >> operand;
			stack.push_back(operand);
			break;
		}
		default: {
			std::cout << "Your input was not valid!" << std::endl;
			fst >> command;
		}
	}
}

/**
 * Starts the calculator.
 */
void RPN::start() {
	while (!should_finish) {
		std::cout << "Command: ";
		//we use a string stream to process all the values entered
		//in one line
		std::string input;
		getline(std::cin, input);
		std::istringstream fst(input);
		char command;
		while (!fst.eof() && !should_finish) {
			fst >> command;
			parse_input(command, fst);
		}
		
		show_stack();
	}
}