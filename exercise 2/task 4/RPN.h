#ifndef RPN_H
#define RPN_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "mymin.h"

template<typename T>
class RPN {
private:
	std::vector<T> stack;
	bool should_finish = false;
	T pop_element();
	void add_element(T element);
	void execute_operation(char operation);
	void parse_input(char input, std::istringstream &fst);
	void show_stack();
public:
	void start();
};

/**
 * Prints all the elements from the stack.
 */
template<typename T>
void RPN<T>::show_stack() {
	for (std::size_t i = 0; i < stack.size(); i++) {
		std::cout << i + 1 << ": " << stack[i] << std::endl;
	}
}

/**
 * Removes the last element from the stack if the stack is not empty.
 * @throw std::out_of_range The stack is empty
 * @return Removed element
 */
template<typename T>
T RPN<T>::pop_element() {
	if (stack.size() > 0) {
		T last = stack.back();
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
template<typename T>
void RPN<T>::add_element(T element) {
	stack.push_back(element);
}

/**
 * Executes an operation on two elements of the stack.
 * @pre   operation is a valid operation
 * @param operation The operation which should be performed on two operands
 * @throw std::invalid_argument  The operand is '/' and the denominator is 0, therefore, the user tries to divide by 0
 */
template<typename T>
void RPN<T>::execute_operation(char operation) {
	if (stack.size() < 2) {
		std::cout << "You need at least two elements on the stack to perform an operation" << std::endl;
	} else {
		T result;
		//we don't need to check if the operation is valid, since
		//this method is only called if a valid operation was entered
		switch (operation) {
			case '*': {
				result = pop_element() * pop_element();
				break;
			}
			case '/': {
				if (stack.at(stack.size() - 2) == 0) {
					throw std::invalid_argument("You can't divide by 0!");
					break;
				} else {
					T divisor = pop_element();
					T divident = pop_element();
					result = divident / divisor;
					break;
				}
			}
			case '+': {
				result = pop_element() + pop_element();
				break;
			}
			case '-': {
				T second = pop_element();
				T first = pop_element();
				result = first - second;
				break;
			}
		}
		add_element(result);
	}
}

/**
 * Parses the input the user enters. The input can either be a command (i.e., 'q' to quit, 'd' to delete a number), 
 * an operation (i.e., '/', '+', '-' or '*') or an operand (integer). After the function parsed the command, it delegates
 * the further proceeding to the corresponding method. 
 * @param input String which contains the input
 */
template<typename T>
void RPN<T>::parse_input(char command, std::istringstream &fst) {
	switch (command) {
		case '+': case '-': case '*': case'/': {
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
				pop_element();
			}
			fst >> command;
			break;
		}
		case 'q': {
			should_finish = true;
			break;
		}
		case 'n': {
			T operand;
			fst >> operand;
			stack.push_back(operand);
			break;
		}
		case 'm': {
			int size = stack.size();
			if (size < 2) {
				std::cout << "You need at least two elements to perform this operation!" << std::endl;
			} else {
				T first = stack[size - 1];
				T second = stack[size - 2];
				std::cout << "Minimum: " << mymin(first, second) << std::endl;
			}
			fst >> command;
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
template<typename T>
void RPN<T>::start() {
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

#endif