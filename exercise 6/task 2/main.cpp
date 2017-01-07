#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * std::mem_fun binds member functions of a class to a function object.
 * This can be useful, if one needs to pass a member function as a function
 * parameter.
 * As an example, this program creates a copy of every non-empty string from a vector 
 * by using the member function string::length
 */

int main() {
	std::vector<std::string*> sentences;
	sentences.push_back(new std::string());
	sentences.push_back(new std::string("Hello world"));
	sentences.push_back(new std::string(""));

	std::cout << "Version with empty strings:" << std::endl;
	for (auto &sentence : sentences) {  
		std::cout << *sentence << std::endl;
	}

	std::vector<std::string*> cleaned;
    std::copy_if(sentences.begin(), sentences.end(), std::back_inserter(cleaned), std::mem_fun(&std::string::length));

    std::cout << "Cleaned version:" << std::endl;
	for (auto &sentence : cleaned) {  
		std::cout << *sentence << std::endl;
	}

	return 0;
}